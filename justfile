# C++ Programming Exercises justfile — development recipes

set shell := ["powershell.exe", "-NoProfile", "-Command"]

# w64devkit extracted by setup.ps1 into the user's LOCALAPPDATA\Programs\w64devkit.
# Absolute path keeps recipes working even in PowerShell sessions opened before
# setup.ps1 updated the User PATH environment variable.
gppbin := env_var('LOCALAPPDATA') + '\Programs\w64devkit\bin'
gpp := gppbin + '\g++.exe'

# List available recipes
default:
    @just --list

# ─── Guards ───────────────────────────────────────────────

# g++ — installed by setup.ps1 (w64devkit) to a pinned path; needed by build/run.
[private]
_require-gpp:
    @if (-not (Test-Path '{{gpp}}')) { Write-Error "g++ not found at {{gpp}}`n  -> Run setup.ps1 first:  pwsh ./setup.ps1"; exit 1 }

# ─── Build & run ─────────────────────────────────────────

# List every program in the collection (one name per line — these are the `name` args).
list:
    @Get-ChildItem src -Filter *.cpp | Sort-Object Name | ForEach-Object { $_.BaseName }

# g++ spawns its assembler (`as`) via PATH, so the compile line prepends the w64devkit
# bin dir for its own process -- calling g++.exe by absolute path alone dies with
# "cannot execute 'as'" on a machine where the dir was never added to PATH.
# Compile ONE program into out\<name>.exe, e.g. `just build movie-ticket`.
build name: _require-gpp
    @if (-not (Test-Path 'src\{{name}}.cpp')) { Write-Error "src\{{name}}.cpp not found -- run 'just list' for valid names"; exit 1 }
    if (-not (Test-Path out)) { New-Item -ItemType Directory out | Out-Null }
    $env:Path = '{{gppbin}};' + $env:Path; & '{{gpp}}' -o 'out\{{name}}.exe' 'src\{{name}}.cpp'

# Compile EVERY program in src\ — stops at the first compile error, then prints a PASS/FAIL summary.
build-all: _require-gpp
    if (-not (Test-Path out)) { New-Item -ItemType Directory out | Out-Null }
    $env:Path = '{{gppbin}};' + $env:Path; $pass = 0; $files = @(Get-ChildItem src -Filter *.cpp | Sort-Object Name); foreach ($f in $files) { & '{{gpp}}' -o ('out\' + $f.BaseName + '.exe') $f.FullName; if ($LASTEXITCODE -ne 0) { Write-Host "[FAIL] $($f.Name)" -ForegroundColor Red; Write-Host "build-all: stopped at first error -- $pass/$($files.Count) passed before it." -ForegroundColor Red; exit 1 }; $pass++; Write-Host "[PASS] $($f.Name)" -ForegroundColor Green }; Write-Host ""; Write-Host "build-all summary: $pass/$($files.Count) PASS, 0 FAIL" -ForegroundColor Green

# PowerShell's `Get-Content |` pipe prepends a UTF-8 BOM to the first stdin line (crashes
# apps whose first read is numeric); cmd redirection passes the file bytes through untouched.
# Compile then run ONE program — stdin from sample-inputs\<name>.txt when it exists, else interactive.
run name: (build name)
    @if (Test-Path 'sample-inputs\{{name}}.txt') { cmd /c "out\{{name}}.exe < sample-inputs\{{name}}.txt" } else { Write-Host "[INFO] No sample-inputs\{{name}}.txt -- running interactively, type the prompts yourself." -ForegroundColor Cyan; & '.\out\{{name}}.exe' }

# Compile then run ONE program with YOUR OWN typed input (always interactive).
run-interactive name: (build name)
    & '.\out\{{name}}.exe'

# The harness (tests\run-tests.ps1) rebuilds each covered program, feeds its committed
# sample input (or nothing for the no-input demos), and diffs stdout against the goldens
# in tests\expected\ — CRLF-normalized, one PASS/FAIL line per program, exit 1 on any fail.
# Run the golden-output test suite over every program with a committed expected output.
test:
    & 'tests\run-tests.ps1'; exit $LASTEXITCODE

# Remove build output.
clean:
    if (Test-Path out) { Remove-Item -Recurse -Force out }

# ─── Tools ───────────────────────────────────────────────

# Launch Claude Code with all permissions — Sonnet (latest)
claudex:
    claude --dangerously-skip-permissions --model sonnet

# Launch Claude Code with all permissions — Opus (latest)
claudeo:
    claude --dangerously-skip-permissions --model opus

# Launch Claude Code with all permissions — Haiku (latest)
claudeh:
    claude --dangerously-skip-permissions --model haiku
