---
name: lint-check
description: Use when the developer says 'lint check', 'run lint', 'check lint', 'run the quality suite', or 'lint everything' — runs the quality gates this repo has (g++ -Wall -Wextra warnings across all 57 programs, plus a build-all/run smoke) and reports pass/fail per layer.
model: sonnet
---

# lint-check — Quality suite (g++ -Wall -Wextra · build-all/run smoke)

This repo has no clang-tidy/cppcheck/clang-format — the honest quality layers for a
collection of 57 standalone plain-C++ console exercises are the compiler's own warnings
and a compile-everything smoke test. Run both and report pass/fail per layer.

## Trigger

When the developer says any of: "lint check", "run lint", "check lint",
"run the quality suite", "lint everything".

---

## What to Do

Run each layer and record its result. Run them independently so one failure doesn't
hide the others.

### 1 — Compiler warnings (`g++ -Wall -Wextra`)

g++ lives at a pinned path (never on PATH) and spawns its assembler via PATH, so the
bin dir must be prepended for the invocation — same trick the justfile `build` recipe
uses. Syntax-check every program in `src\`:

```powershell
$gppbin = "$env:LOCALAPPDATA\Programs\w64devkit\bin"
$env:Path = "$gppbin;" + $env:Path
Get-ChildItem src -Filter *.cpp | Sort-Object Name | ForEach-Object {
    & "$gppbin\g++.exe" -Wall -Wextra -fsyntax-only $_.FullName
}
```

Pass = no NEW warnings versus the known baseline. Warnings (unused-variable,
sign-compare, uninitialized, ...) in files a branch touched are findings — list each
with file:line. Fix at the root cause (e.g. initialize the variable), never by
suppressing with a pragma or a cast just to go quiet.

> Expected baseline (g++ 16.1.0): **8 warnings across 8 files** — `comma-percent.cpp`,
> `ex3-q6b-pattern.cpp`, `ex4-q10b-next-week.cpp`, `ex4-q4-even-odd-function.cpp`,
> `ex5-q6-car-sales.cpp`, `modify-salesman.cpp`, `output-design-assignment.cpp`,
> `sentinel-even-odd.cpp` (1 each). These are preserved coursework quirks — do NOT
> "fix" untouched files. The other 49 files are warning-free; any warning in a file
> the branch touched is a regression.

### 2 — Build/run smoke

```powershell
just build-all
just run assessment3-employee-payroll
```

Pass = `build-all` prints `57/57 PASS, 0 FAIL` and exits 0, and the run exits 0 with
the closing summary block (`The total number of employee is ...`). If the branch
changed a program that has a committed `sample-inputs\<name>.txt` (currently
`assessment3-employee-payroll`, `movie-ticket`, `electric-bill`, `fibonacci-series`),
run that one too. A hang means the cin read order and the sample-input file drifted
apart (a failed `cin >>` leaves the stream in a fail state and any `Do you want to
stop ?` loop never sees a `y`) — kill it with Ctrl+C and report FAIL.

---

## Reporting back

Report a per-layer table, then an overall verdict:

```
LAYER      TOOL                        STATUS
warnings   g++ -Wall -Wextra (57 src)  PASS | FAIL (N new warnings vs the 8-warning baseline)
smoke      just build-all + run        PASS | FAIL (exit codes / symptom, e.g. hang or compile error)
OVERALL: PASS | FAIL
```

---

## Notes

- Run from the **repo root** — all sources live in `src\`, one standalone program per file.
- There is no auto-fix layer here — every fix is a source edit; re-run the layer after.
- Programs are independent translation units — never try to link them together; each
  compiles to its own `out\<name>.exe`.
- Don't bolt on clang-tidy/cppcheck uninvited — this is preserved uni coursework;
  propose new tooling to the developer instead of adding it inside a lint run.
