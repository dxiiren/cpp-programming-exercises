# TL;DR — every doc in 30 seconds

## [01-overview/project-overview.md](01-overview/project-overview.md)

57 standalone C++ console programs from UiTM's CSC126 course, copied out of the archived
coursework folder, renamed to kebab-case in a flat `src/`, and preserved as written.
`assesment3try.cpp` was excluded (its standalone copy was retired; this collection's
`assessment3-employee-payroll.cpp` is the canonical version). No personal data needed stripping. The doc carries the
full original-name → new-name mapping table.

## [02-setup/getting-started.md](02-setup/getting-started.md)

`pwsh ./setup.ps1` once (installs Git, Node, Claude CLI, uv/Python, w64devkit g++, just,
gh — idempotent), reopen PowerShell, then `just list`, `just build-all` (expect
`57/57 PASS`), `just run movie-ticket`. Sanity checklist included.

## [03-development/workflow.md](03-development/workflow.md)

Branch, edit one standalone program, `just build <name>` + `just run <name>`, keep
`sample-inputs\<name>.txt` in sync with any cin change, `just build-all` + `just test`
(11/11 golden diffs) as the gates, then `/pre-pr-review`, `/commit`, `/create-pr`. House
rules: preserve coursework quirks, no build-system creep, never commit `out\`.

## [04-deployment/deployment.md](04-deployment/deployment.md)

There is no deployment: no CI/CD, no releases, no server. The repo runs locally;
"shipping" is a push to `main`. A locally built `out\<name>.exe` is statically linked if
you ever must hand one over.

## [05-reference/commands.md](05-reference/commands.md)

The just recipes: `list`, `build <name>`, `build-all` (stops at first error, prints
PASS/FAIL summary), `run <name>` (canned stdin when a sample exists, else interactive),
`run-interactive <name>`, `test` (golden-output suite over 11 covered programs), `clean`,
plus the claude launchers. Explains the pinned g++ path, the PATH-prepend for `as`, and
the BOM-avoiding cmd redirect.

## [05-reference/program-catalog.md](05-reference/program-catalog.md)

The full inventory grouped Basics / Selection / Loops / Exercise sets / Assessments, with
each program's input behavior (none / stdin / committed sample) and a table of known
coursework quirks that are preserved on purpose.

## [05-reference/project-layout.md](05-reference/project-layout.md)

Annotated tree: flat `src/` (one `main()` per file), `sample-inputs/` named after their
programs, `tests/` (golden harness + expected outputs), git-ignored `out/`, `.docs/`,
`.claude/`, `justfile`, `setup.ps1`. Naming conventions for drills vs lab exercises.

## [06-troubleshooting/common-issues.md](06-troubleshooting/common-issues.md)

Real symptoms with fixes: g++ missing → setup.ps1; `cannot execute 'as'` → PATH-prepend;
silent "hang" → the program is reading stdin interactively; infinite prompt loop → sample
input drifted from the cin read order; garbage first value → PowerShell pipe BOM; the
8-warning `-Wall -Wextra` baseline; wrong-looking results that are original coursework
bugs.

## [07-faq/faq.md](07-faq/faq.md)

Why bugs stay (it's an archive), why `src/` is flat, why files were renamed, where
`assesment3try.cpp` went, why w64devkit, why only four programs run unattended, and why
there's no CMake or tests.
