# tests\run-tests.ps1 — golden-output test harness.
#
# For every golden in tests\expected\, compiles src\<name>.cpp, runs the exe
# (stdin from sample-inputs\<name>.txt when it exists, else < NUL), and compares
# stdout against the golden with CRLF/LF normalized. One line per program,
# summary at the end, exit 1 on any failure. Zero changes to program source —
# the goldens pin the programs' behavior as-is.
#
# Run it via `just test` (or directly: powershell -NoProfile -File tests\run-tests.ps1).
# stdout/stdin are redirected inside cmd on purpose — the PowerShell pipe injects
# a UTF-8 BOM into the first stdin line (see README Troubleshooting).

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

$pass = 0
$fail = 0
foreach ($g in $goldens) {
    $name = $g.BaseName
    if (-not (Test-Path "src\$name.cpp")) {
        Write-Host "[FAIL] $name — golden exists but src\$name.cpp does not" -ForegroundColor Red
        $fail++
        continue
    }

    & $gpp -o "out\$name.exe" "src\$name.cpp"
    if ($LASTEXITCODE -ne 0) {
        Write-Host "[FAIL] $name — compile error" -ForegroundColor Red
        $fail++
        continue
    }

    $actualPath = "out\$name.actual.txt"
    if (Test-Path "sample-inputs\$name.txt") {
        cmd /c "out\$name.exe < sample-inputs\$name.txt > $actualPath"
    } else {
        cmd /c "out\$name.exe < NUL > $actualPath"
    }

    $expected = ([IO.File]::ReadAllText($g.FullName)) -replace "`r`n", "`n"
    $actual = ([IO.File]::ReadAllText((Join-Path $repo $actualPath))) -replace "`r`n", "`n"
    if ($expected -eq $actual) {
        Write-Host "[PASS] $name" -ForegroundColor Green
        $pass++
    } else {
        $expLines = $expected -split "`n"
        $actLines = $actual -split "`n"
        $max = [Math]::Max($expLines.Count, $actLines.Count)
        $firstDiff = 0
        for ($i = 0; $i -lt $max; $i++) {
            $e = if ($i -lt $expLines.Count) { $expLines[$i] } else { $null }
            $a = if ($i -lt $actLines.Count) { $actLines[$i] } else { $null }
            if ($e -cne $a) { $firstDiff = $i + 1; break }
        }
        Write-Host "[FAIL] $name — first difference at line $firstDiff (see $actualPath vs tests\expected\$name.txt)" -ForegroundColor Red
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
