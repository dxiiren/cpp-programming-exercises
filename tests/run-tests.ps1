# tests\run-tests.ps1 — golden-output test harness.
#
# For every golden in tests\expected\, compiles src\<name>.cpp, runs the exe
# (stdin from sample-inputs\<name>.txt when it exists, else < NUL), and compares
# stdout against the golden with CRLF/LF normalized. A non-zero process exit code
# is a FAIL even when stdout matches — a program that prints the right text and
# then crashes is not passing. One line per program, summary at the end, exit 1 on
# any failure. The goldens pin the programs' real behavior, quirks included.
#
# Run it via `just test` (or directly: powershell -NoProfile -File tests\run-tests.ps1).
# stdout/stdin are redirected inside cmd on purpose — the PowerShell pipe injects
# a UTF-8 BOM into the first stdin line (see README Troubleshooting).
#
# The 57 programs are compiled and run CONCURRENTLY. Nothing is shared between
# them: no linking, one main() per file, and each writes only out\<name>.exe and
# out\<name>.actual.txt — names unique per program, so two workers never touch
# the same path. No program opens a socket or a fixed file. That independence is
# what makes this safe; if you ever add a program that binds a port or writes a
# fixed filename, it has to be excluded from the parallel set.
#
# Two things the parallel block must NOT rely on:
#   * the current directory — a runspace does not reliably inherit the caller's
#     location, so every path handed to g++ or cmd here is absolute;
#   * output ordering — workers finish out of order, so results are collected as
#     objects and printed sorted by name afterwards. The printed output is byte
#     for byte what the serial version produced.
[CmdletBinding()]
param(
    # Compiling is CPU-bound, so this tracks core count rather than program
    # count. Override to 1 to get the old serial behaviour back when debugging.
    [int]$ThrottleLimit = [Environment]::ProcessorCount
)

$repo = Split-Path -Parent $PSScriptRoot
$gppbin = Join-Path $env:LOCALAPPDATA 'Programs\w64devkit\bin'
$gpp = Join-Path $gppbin 'g++.exe'
if (-not (Test-Path $gpp)) {
    Write-Host "g++ not found at $gpp  -> Run setup.ps1 first:  pwsh ./setup.ps1" -ForegroundColor Red
    exit 1
}
# g++ spawns its assembler (`as`) via PATH — same prepend the justfile build recipes use.
$env:Path = "$gppbin;$env:Path"

Set-Location $repo
if (-not (Test-Path out)) { New-Item -ItemType Directory out | Out-Null }

$goldens = @(Get-ChildItem (Join-Path $PSScriptRoot 'expected') -Filter *.txt | Sort-Object Name)
if ($goldens.Count -eq 0) {
    Write-Host 'No goldens found in tests\expected\ — nothing to test.' -ForegroundColor Red
    exit 1
}

$results = $goldens | ForEach-Object -ThrottleLimit $ThrottleLimit -Parallel {
    $repo = $using:repo
    $gpp = $using:gpp
    # $env: is process-wide, so the prepend above already applies here — but a
    # runspace may start before that assignment is visible, and g++ dies with
    # `cannot execute 'as'` when it is not. Cheap to make certain.
    $env:Path = "$($using:gppbin);$env:Path"

    $g = $_
    $name = $g.BaseName
    $srcPath = Join-Path $repo "src\$name.cpp"
    $exePath = Join-Path $repo "out\$name.exe"
    $actualPath = "out\$name.actual.txt"
    $actualFull = Join-Path $repo $actualPath
    $inputPath = Join-Path $repo "sample-inputs\$name.txt"

    if (-not (Test-Path $srcPath)) {
        return [pscustomobject]@{ Name = $name; Ok = $false; Line = "[FAIL] $name — golden exists but src\$name.cpp does not" }
    }

    & $gpp -o $exePath $srcPath
    if ($LASTEXITCODE -ne 0) {
        return [pscustomobject]@{ Name = $name; Ok = $false; Line = "[FAIL] $name — compile error" }
    }

    # Absolute paths, and the redirection still happens inside cmd rather than
    # through a PowerShell pipe — the pipe injects a UTF-8 BOM into the first
    # stdin line (see README Troubleshooting). cmd strips the outermost pair of
    # quotes, which is why the whole command is wrapped in its own pair.
    if (Test-Path $inputPath) {
        cmd /c "`"$exePath`" < `"$inputPath`" > `"$actualFull`""
    } else {
        cmd /c "`"$exePath`" < NUL > `"$actualFull`""
    }
    $code = $LASTEXITCODE

    # A non-zero exit is a FAIL even when stdout matches: a program that prints the right
    # text and then crashes (undefined behavior, a trap, an unhandled exception) is not
    # passing. Every program here ends in `return 0`, so any other code is a real failure.
    # Same guard both java harnesses carry.
    if ($code -ne 0) {
        return [pscustomobject]@{ Name = $name; Ok = $false; Line = "[FAIL] $name — exit code $code (stdout not compared)" }
    }

    $expected = ([IO.File]::ReadAllText($g.FullName)) -replace "`r`n", "`n"
    $actual = ([IO.File]::ReadAllText($actualFull)) -replace "`r`n", "`n"
    if ($expected -eq $actual) {
        return [pscustomobject]@{ Name = $name; Ok = $true; Line = "[PASS] $name" }
    }

    $expLines = $expected -split "`n"
    $actLines = $actual -split "`n"
    $max = [Math]::Max($expLines.Count, $actLines.Count)
    $firstDiff = 0
    for ($i = 0; $i -lt $max; $i++) {
        $e = if ($i -lt $expLines.Count) { $expLines[$i] } else { $null }
        $a = if ($i -lt $actLines.Count) { $actLines[$i] } else { $null }
        if ($e -cne $a) { $firstDiff = $i + 1; break }
    }
    [pscustomobject]@{ Name = $name; Ok = $false; Line = "[FAIL] $name — first difference at line $firstDiff (see $actualPath vs tests\expected\$name.txt)" }
}

# Sorted, so the report reads identically to the serial harness no matter what
# order the workers happened to finish in.
$pass = 0
$fail = 0
foreach ($r in ($results | Sort-Object Name)) {
    if ($r.Ok) {
        Write-Host $r.Line -ForegroundColor Green
        $pass++
    } else {
        Write-Host $r.Line -ForegroundColor Red
        $fail++
    }
}

Write-Host ''
$total = $goldens.Count
if ($fail -eq 0) {
    Write-Host "test summary: $pass/$total PASS, 0 FAIL" -ForegroundColor Green
    exit 0
} else {
    Write-Host "test summary: $pass/$total PASS, $fail FAIL" -ForegroundColor Red
    exit 1
}
