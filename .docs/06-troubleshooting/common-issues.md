# Common issues

> **TL;DR** Almost every problem here is one of four things: g++ missing (run setup.ps1),
> g++ found but `as` not on PATH (use the recipes, not bare g++), a program waiting on
> stdin (only 4 have sample inputs), or a sample-input file drifted from the cin read
> order (hangs forever — Ctrl+C).

## `just build ...` fails: "g++ not found at ...w64devkit\bin\g++.exe"

w64devkit isn't installed. Run `pwsh ./setup.ps1` — it extracts the toolchain to
`%LOCALAPPDATA%\Programs\w64devkit`. The justfile always calls that pinned absolute path,
so nothing else needs PATH.

## g++ dies with `cannot execute 'as'` when you invoke it by hand

g++ finds its assembler (`as`) via PATH, even when g++ itself is called by absolute path.
Prepend the bin dir for your session first:

```powershell
$env:Path = "$env:LOCALAPPDATA\Programs\w64devkit\bin;" + $env:Path
```

The `build` and `build-all` recipes do exactly this for their own process — another
reason to use the recipes.

## `just run <name>` shows nothing and appears stuck

The program is reading stdin interactively. Only four programs have committed sample
inputs (`assessment3-employee-payroll`, `movie-ticket`, `electric-bill`,
`fibonacci-series`); for the rest, `just run` prints an `[INFO] ... running interactively`
note and waits for you to type. That's expected — answer the prompts, or create a
`sample-inputs\<name>.txt` matching the program's exact read order.

## A program WITH a sample input hangs, re-printing its prompts forever

The input file drifted from the cin read order. A failed `cin >>` (wrong type, missing
line) fail-states the stream — every later read silently fails, so a
"Do you want to stop ?" loop never sees its `y`. Keep the file in the exact read order
with the terminating answer, e.g. for `assessment3-employee-payroll`:
id → name → hours → `n`/`y` answer, repeated, final answer `y`. Ctrl+C kills a hung run.

## All prompts print in one long line during `just run`

Normal. With redirected stdin nothing is echoed between prompts, so they run together.
Read the result lines underneath.

## The first value reads as garbage after "simplifying" the run recipe

The `run` recipe was changed to `Get-Content sample-inputs\... | out\<name>.exe`. The
Windows PowerShell pipe injects a UTF-8 BOM into the first stdin line, which garbles a
numeric first read. Restore the `cmd /c "out\<name>.exe < sample-inputs\<name>.txt"`
redirect.

## `-Wall -Wextra` prints warnings — is the build broken?

No. Plain `just build-all` uses default flags and is clean (57/57). With `-Wall -Wextra`
(what `/lint-check` runs) the accepted baseline is **8 warnings in 8 files** —
`comma-percent`, `ex3-q6b-pattern`, `ex4-q10b-next-week`, `ex4-q4-even-odd-function`,
`ex5-q6-car-sales`, `modify-salesman`, `output-design-assignment`, `sentinel-even-odd` —
preserved coursework (unused variables, a `&` meant as `&&`, a missing return). Only a
NEW warning in a file you touched is a regression.

## A program prints a wrong-looking result but exits fine

Check the [known-quirks table](../05-reference/program-catalog.md#known-coursework-quirks-preserved-do-not-fix-casually)
first — several logic bugs (swapped BMI arguments, uninitialized accumulators, the
"next day" label on `previous-day`) are original coursework behavior, preserved on
purpose.

## Related docs

| Doc | Why |
| --- | --- |
| [`../05-reference/commands.md`](../05-reference/commands.md) | What each recipe actually executes |
| [`../05-reference/program-catalog.md`](../05-reference/program-catalog.md) | Input behavior + quirks per program |
| [`../07-faq/faq.md`](../07-faq/faq.md) | Why-is-it-like-this questions |
