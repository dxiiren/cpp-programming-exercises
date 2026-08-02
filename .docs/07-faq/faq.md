# FAQ

> **TL;DR** It's preserved university coursework: bugs and style stay unless a change is
> the explicit goal; the toolchain is a portable g++ at a pinned path; four programs run
> unattended, the rest are interactive.

## Why do some programs have obvious bugs?

Because they're the historical record of a first-year programming course. The known ones
(swapped BMI arguments, uninitialized accumulators, misleading names) are cataloged in
[`../05-reference/program-catalog.md`](../05-reference/program-catalog.md). Fixing them is
fine as a deliberate change with its own branch/PR — never as a drive-by.

## Why is `src/` flat instead of foldered by topic?

The original archive was one flat folder; the topic grouping lives in the catalog tables.
Flat also keeps the justfile recipes trivial (`src\<name>.cpp` → `out\<name>.exe`).

## Why kebab-case names that differ from the originals?

The originals had spaces, `%`, `+`, and `,` in filenames — hostile to command-line use.
Every rename is recorded in
[`../01-overview/project-overview.md`](../01-overview/project-overview.md).

## Where is `assesment3try.cpp`? The archive had 58 C++ files.

It was excluded because it had already been published as a standalone repo. That
standalone copy was retired; this collection's `assessment3-employee-payroll.cpp` (the
earlier draft of the same assignment) is the canonical version.

## Why w64devkit instead of MSYS2 / Visual Studio?

A portable zip extracted to `%LOCALAPPDATA%\Programs\w64devkit` — no installer
interactivity, no system-wide PATH pollution, and setup.ps1 can verify it by path. The
exercises need nothing beyond a stock g++.

## Why does `just run <name>` only work unattended for four programs?

Sample inputs are hand-built to match each program's exact cin read order, and only the
representative four have them. Add a `sample-inputs\<name>.txt` (exact read order, final
`y` for y/n loops) and `just run <name>` picks it up automatically.

## Can I add a build system (CMake) or tests?

Not inside this repo's mission — it's an archive, and per-file `g++` IS the build. If you
want to experiment, propose it first (see the house rules in
[`../03-development/workflow.md`](../03-development/workflow.md)).

## Why C++ this old-fashioned (`system`-free but pre-C++11 style)?

The course taught 2019-era Dev-C++ conventions. g++ 16 still compiles all of it (8
benign warnings under `-Wall -Wextra`), which is the point: preserve, don't modernize.

## Related docs

| Doc | Why |
| --- | --- |
| [`../01-overview/project-overview.md`](../01-overview/project-overview.md) | Provenance + mapping |
| [`../06-troubleshooting/common-issues.md`](../06-troubleshooting/common-issues.md) | Symptom-driven fixes |
| [`../03-development/workflow.md`](../03-development/workflow.md) | House rules |
