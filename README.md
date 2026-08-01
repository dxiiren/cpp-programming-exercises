# C++ Programming Exercises

A collection of 57 standalone C++ console programs written for CSC126 (Fundamentals of
Algorithm and Computer Problem Solving) at UiTM. Each `.cpp` file in `src/` is a complete
program with its own `main()` — selection drills (BMI, bills, discounts), loop drills
(series, counters, sentinels), function drills (date arithmetic, delivery charges), and
array drills (rainfall, grades, sales) — preserved as coursework, compiled with a modern
g++ toolchain.

> **New developer? Start with [`.docs/tldr.md`](.docs/tldr.md)** — every doc summarised on one
> page. The full guide lives in [`.docs/`](.docs/README.md).

## Prerequisites

| Tool | Version | Installed by |
| --- | --- | --- |
| PowerShell + winget | Windows 10/11 stock | — (the only true prerequisites) |
| g++ (w64devkit) | GCC 16.x, pinned path | `setup.ps1` |
| Node.js | LTS (only for the Claude CLI) | `setup.ps1` |
| uv + Python | latest (only for `.claude` tooling) | `setup.ps1` |
| just | any recent | `setup.ps1` |
| Claude Code CLI | latest | `setup.ps1` (optional, for AI-assisted dev) |

## Quick start

```powershell
# 1. One-time machine setup (idempotent — safe to re-run)
pwsh ./setup.ps1

# 2. Close and reopen PowerShell so PATH updates land
# 3. See what's in the collection, compile everything, run one program
just list
just build-all
just run movie-ticket
```

Every program runs in the terminal and finishes on its own — there is no server.
`just run <name>` compiles `src\<name>.cpp` into `out\<name>.exe` and, when a
`sample-inputs\<name>.txt` exists, feeds it as stdin; otherwise the program runs
interactively and you type at its prompts. Use `just run-interactive <name>` to force
your own input.

## Commands

Run `just` with no arguments to list every recipe. The ones you'll use daily:

| Command | What it does |
| --- | --- |
| `just list` | Print every program name (the valid `<name>` arguments) |
| `just build <name>` | Compile `src\<name>.cpp` into `out\<name>.exe` |
| `just build-all` | Compile all 57 programs; stop at the first error; print a PASS/FAIL summary |
| `just run <name>` | Compile, then run — `sample-inputs\<name>.txt` as stdin if present, else interactive |
| `just run-interactive <name>` | Compile, then run reading YOUR typed input |
| `just clean` | Delete the compiled `out\` folder |
| `just claudex` | Launch Claude Code (Sonnet, all permissions) |

## Program catalog

Names are the `just run <name>` arguments (the `.cpp` files in `src\`). Programs marked
"input" read from stdin; the four with a committed sample input run unattended via
`just run`. Original coursework filenames are mapped in
[`.docs/01-overview/project-overview.md`](.docs/01-overview/project-overview.md).

### Basics — I/O, arithmetic, operators

| Program | What it does | Input |
| --- | --- | --- |
| `add-2-numbers` | Read two integers and print their sum | stdin |
| `area-of-triangle` | Base and height to triangle area | stdin |
| `average-of-3-people` | Average the ages of three people | stdin |
| `boolean` | Bool expression demo on hardcoded marks (prints 0/1) | none |
| `divide-2-numbers` | Divide two numbers with a divide-by-zero guard | stdin |
| `increment-operators` | `++`/`--`/compound-assignment walkthrough on one variable | none |
| `larger-number` | Print the larger of two numbers | stdin |
| `output-design-assignment` | Read and echo a student's name, ID, and age | stdin |
| `test` | Array-rewrite drill: odd values become 99, odd indexes +8 | none |

### Selection — if/else chains

| Program | What it does | Input |
| --- | --- | --- |
| `bmi-function` | BMI via a value-returning function, then a health status | stdin |
| `comma-draft` | Insert a thousands comma into a number over 1000 (draft) | stdin |
| `comma-percent` | Thousands-comma formatting via `%`, validates 1000–50000 | stdin |
| `discount-price` | Price and discount rate to price after discount | stdin |
| `electric-bill` | Tiered electricity bill from units used (sample input committed) | stdin |
| `even-and-odd-number` | Parity check; an odd number gets incremented | stdin |
| `even-and-odd-v2` | Clean odd/even verdict for one integer | stdin |
| `final-exam-v2` | Weighted final score (exam/project/test) plus PASS/FAIL | stdin |
| `final-score-of-student` | Weighted final score, no verdict | stdin |
| `format-time` | 24-hour `HHMM` to 12-hour am/pm time | stdin |
| `high-tech-company` | Capital + IT-headcount rules decide "high-tech company" | stdin |
| `land-area-tax` | Tiered land tax by acreage | stdin |
| `loan-application` | Loan eligibility rules plus monthly payment | stdin |
| `movie-ticket` | Ticket total with age-category discounts (sample input committed) | stdin |
| `shoe-discount` | Shoe type A/B/C discount pricing | stdin |

### Loops — for/while/sentinel

| Program | What it does | Input |
| --- | --- | --- |
| `avg-mark-student-and-class` | Per-student average + weighted score, then the class average | stdin |
| `blood-pressure-and-sugar` | 5 patients' readings to hypertension/diabetes/both counts | stdin |
| `count-even-and-odd-data` | Read 10 numbers, count evens and odds | stdin |
| `electrical-salesman` | Item-sales loop (types A–D) to commission and best seller | stdin |
| `fibonacci-series` | First n Fibonacci terms (sample input committed) | stdin |
| `following-series` | Series of 2i/3i fractions plus their sum | stdin |
| `modify-salesman` | Multi-salesman commissions with per-salesman and average totals | stdin |
| `pair-number-repeat` | Sum number pairs until a pair matches; track largest and >500 count | stdin |
| `salesman` | 5 salesmen: salary + 3% commission; highest/lowest/total | stdin |
| `salesman-v2` | Looped salesman income with loan deduction and average | stdin |
| `sentinel-even-odd` | Sentinel-0 loop counting evens/odds plus min and max | stdin |
| `sum-of-odd-numbers` | List odd numbers 101–199 and sum the series | none |

### Exercise sets (Ex3–Ex8) — patterns, functions, arrays

| Program | What it does | Input |
| --- | --- | --- |
| `ex3-q6a-pattern` | `?` hourglass pattern from nested loops | none |
| `ex3-q6b-pattern` | `=`/`+` box pattern | none |
| `ex3-q6c-pattern` | `*` triangle-plus-block pattern | none |
| `ex3-q9-student-activity-points` | Activity points per student; qualified count, highest, lowest | stdin |
| `ex4-q4-even-odd-function` | Parity via a reference-parameter function | stdin |
| `ex4-q6-delivery-package` | Delivery charge from weight and zone (two helper functions) | stdin |
| `ex4-q7-total-delivery` | 20 parcels' charges with highest/lowest/total | stdin |
| `ex4-q9-bmi-reference` | BMI via a reference out-parameter (arguments passed swapped — coursework bug, preserved) | stdin |
| `ex4-q10-next-day` | Next calendar day, month/leap handling | stdin |
| `ex4-q10b-next-week` | Date one week ahead with leap-year February | stdin |
| `ex4-q10c-next-10-weeks` | Next day plus 4 weeks ahead (name says 10; the loop runs 4) | stdin |
| `ex5-q2a-quiz-marks-array` | 4 quiz marks in an array: total, average, above-average list | stdin |
| `ex5-q3-rainfall` | 12 months of rainfall: total, wettest/driest month, above-average months | stdin |
| `ex5-q4-array-merge-compare` | Two 5-element arrays: element sums and element-wise max | stdin |
| `ex5-q5-grade-counter` | Grade tally (A–D) with a y/n stop loop plus most popular grade | stdin |
| `ex5-q5-grade-counter-v2` | Grade tally for exactly 10 marks | stdin |
| `ex5-q6-car-sales` | Car sales per type against fixed prices: totals and most popular | stdin |
| `ex8-q4-date-formatter` | Numeric day/month/year to "1 January 2020", loops until 0 | stdin |
| `previous-day` | Previous calendar day (output label says "next day" — coursework quirk) | stdin |
| `untitled2-grade-counter` | Looped grade counter variant; keeps a leftover debug print | stdin |

### Assessments

| Program | What it does | Input |
| --- | --- | --- |
| `assessment3-employee-payroll` | Tiered weekly payroll: gross, deductions, net; headcount/highest-paid/underpaid summary (sample input committed) | stdin |

**Cross-reference:** the final iteration of Assessment 3, `assesment3try.cpp`, is
byte-identical to the source already published as
[`dxiiren/employee-salary-counter`](https://github.com/dxiiren/employee-salary-counter)
and is therefore excluded from this collection. `assessment3-employee-payroll` here is the
earlier draft of the same assignment.

## Troubleshooting

### `just build` fails with "g++ not found at ...w64devkit\bin\g++.exe"

Run `pwsh ./setup.ps1` — it installs w64devkit to `%LOCALAPPDATA%\Programs\w64devkit`. The
justfile calls g++ by that pinned absolute path, so no PATH edit is needed for building.

### g++ dies with `cannot execute 'as'` when invoked by hand

g++ spawns its assembler via PATH. Prepend the w64devkit bin dir first
(`$env:Path = "$env:LOCALAPPDATA\Programs\w64devkit\bin;" + $env:Path`) — the `build` and
`build-all` recipes already do this for their own process.

### `just run <name>` appears to hang with no output

The program is waiting on stdin. Only `assessment3-employee-payroll`, `movie-ticket`,
`electric-bill`, and `fibonacci-series` have committed sample inputs — every other
stdin-reading program runs interactively (the recipe prints an `[INFO]` note first), so
type at its prompts. If a program with a sample input hangs, the input file drifted from
the cin read order — a failed `cin >>` fail-states the stream and any y/n stop loop never
sees its `y`. Press Ctrl+C to kill it.

### All prompts print in one long line during `just run`

Normal. The programs print prompts expecting a human; with redirected input nothing is
echoed between them, so the prompts run together. The result lines below them are what
matters.

### The first value reads as garbage after "simplifying" the run recipe

You changed `run` to a `Get-Content sample-inputs\... |` pipe. The Windows PowerShell pipe
injects a UTF-8 BOM into the first stdin line. Keep the recipe's
`cmd /c "out\<name>.exe < sample-inputs\<name>.txt"` redirect, which passes the file's
bytes untouched.

More in [`.docs/06-troubleshooting/common-issues.md`](.docs/06-troubleshooting/common-issues.md).

## Project layout

```
cpp-programming-exercises/
  src/                     # 57 standalone programs — one main() per .cpp, kebab-case names
  sample-inputs/           # canned stdin for `just run` (4 programs covered)
  out/                     # compiled exes from `just build`/`build-all` — git-ignored
  .docs/                   # numbered documentation set — start at .docs/tldr.md
  .claude/                 # Claude Code skills, hooks, settings
  justfile                 # day-2 commands (`just` to list)
  setup.ps1                # one-time machine bootstrap
```
