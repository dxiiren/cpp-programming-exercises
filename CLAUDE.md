# CLAUDE.md — cpp-programming-exercises

> Human-facing developer docs live in [`.docs/`](./.docs/README.md) — start at
> [`.docs/tldr.md`](./.docs/tldr.md). Keep them in sync when changing behavior they document.

## Project: C++ Programming Exercises

A collection of 57 standalone C++ console programs from CSC126 (Fundamentals of Algorithm
and Computer Problem Solving, UiTM) — selection, loop, function, and array drills such as
BMI calculators, electric bills, payroll, Fibonacci, date arithmetic, and sales
commissions. Each `src\*.cpp` is its own program with its own `main()`; there is no shared
code and no linking between files. Preserved coursework (2019-era), published 2026.

- **Repo:** GitHub — `github.com/dxiiren/cpp-programming-exercises`
- **Runs locally only** — no CI/CD, no deployment target, no server. `just run <name>`
  compiles one program and runs it (canned stdin from `sample-inputs\` when available).

### Tech Stack Quick Reference

| Layer | Technology | Key details |
| --- | --- | --- |
| Language | C++ (g++ 16.1.0 via w64devkit) | 57 independent translation units, no build system, no dependencies |
| Entry points | one `main()` per `src\*.cpp` | Most read stdin via `cin`/`getline`; 8 take no input (patterns/demos) |
| Naming | kebab-case | free-standing drills `<topic>.cpp`; lab exercises `exN-qM-<topic>.cpp` |
| Fixtures | `sample-inputs\<name>.txt` | 50 committed (one per stdin program); the other 7 programs read no stdin and are fed `< NUL`. Every program has a golden in `tests\expected\` |
| Task runner | `just` | parameterized recipes wrap the pinned-path `g++` (see `justfile`) |

### Project Structure

```
cpp-programming-exercises/
  src/                     # 57 standalone programs — one main() per .cpp
  sample-inputs/           # canned stdin consumed by `just run <name>` (10 programs)
  tests/                   # golden-output harness — run-tests.ps1 + expected/ (57 goldens);
                           # `just test` must stay 57/57 PASS. The harness also fails a
                           # program on a NON-ZERO EXIT CODE even when stdout matches.
  out/                     # `just build`/`build-all` output — git-ignored
  .docs/                   # numbered documentation set
  .claude/                 # skills, hooks, settings
  justfile, setup.ps1
```

## Git Commits

- **Conventional Commits** (`feat:`, `fix:`, `chore:`, `docs:` ...).
- **NEVER** add `Co-Authored-By` lines or "Generated with Claude Code" / session-link footers to
  **any** outward artifact — commit messages, PR descriptions, or issue comments.
- Commit author email for this repo is `mohdakmal875@gmail.com` (set repo-locally).
- Only stage and commit files relevant to the change. **Never auto-commit** after a fix — the
  developer says "commit" first.

## Local Development

- One-time machine setup: `pwsh ./setup.ps1` (idempotent — installs Git, Node (for the Claude
  CLI), w64devkit (g++), uv/Python, just, the Claude Code CLI). Then `just list`,
  `just build-all`, `just run <name>`.
- All day-2 commands are `just` recipes — run `just` to list them. Never invent an alternative
  command for something a recipe already covers.
- These are run-to-completion CLIs — there is no server and no `just start`/`just stop`.
- The `run` recipe uses `cmd /c "out\<name>.exe < sample-inputs\<name>.txt"` on purpose: the
  Windows PowerShell pipe (`Get-Content |`) injects a UTF-8 BOM into the first stdin line.
  Don't "simplify" it back to a pipe.
- g++ lives at a **pinned path** (`%LOCALAPPDATA%\Programs\w64devkit\bin`) and spawns its
  assembler (`as`) via PATH — the `build`/`build-all` recipes prepend that bin dir for their
  own process. Calling `g++.exe` by absolute path alone dies with `cannot execute 'as'`.
- A `sample-inputs\<name>.txt` must exactly match that program's cin read order. A failed
  `cin >>` fail-states the stream and any y/n stop loop **hangs forever** — no exception, no
  crash. Programs without a sample file run interactively under `just run`.
- Preserve coursework quirks in untouched files: the 8 known `-Wall -Wextra` baseline
  warnings, implicit-int `main()`, Malay comments, and the remaining quirks in the
  catalog's known-quirks table (e.g. `ex4-q10c-next-10-weeks` advances 4 weeks). The
  documented logic bugs (swapped BMI arguments, uninitialized accumulators, duplicated
  `'E'` zone test, "next day" label, `gdjgjgw` debug print) were **fixed** in a 2026
  maintenance pass — see the fixed-bugs table in
  `.docs/05-reference/program-catalog.md`. Fix further quirks only when a change is
  explicitly asked for.

## Project Skills

Development skills live in `.claude/skills/` — check `.claude/skills/README.md` for the catalog
and **follow the relevant skill before writing code**. Notables: `/commit`, `/create-pr`,
`/pre-pr-review`, `/lint-check`, `/claude-transfer`, `/llm-transfer`, `/define-goal`,
`/setup-mcp`, `/test-all-mcp`, `/audit-skills`.

## MCP Servers

Wired via the committed-stub + git-ignored-secret pattern: `.mcp.json.stub` (committed,
placeholders) → `.mcp.json` (git-ignored, real — seeded by `setup.ps1`). Turnkey: `context7`
(library docs — call `resolve-library-id` then `query-docs` instead of recalling APIs),
`playwright` (drive a real browser). Per-dev: `github` (fill the PAT in `.mcp.json`).
Health check: `/test-all-mcp`. Fall back to native tools silently if a server is unavailable.

## Memory

Lightweight, single-developer, file-based project memory at `.claude/memory/`:

- **`MEMORY.md`** is the index (one line per memory: `- [Title](file.md) — hook`), loaded each
  session.
- Each memory is **one fact in its own `*.md` file** with frontmatter (`name`, `description`,
  `metadata.type` = `reference` | `feedback` | `project`). Read the fact file on demand when its
  index hook is relevant.
- After writing a fact file, add its one-line pointer to `MEMORY.md`. Update rather than
  duplicate; delete a memory that turns out wrong. Don't store what the repo already records.
