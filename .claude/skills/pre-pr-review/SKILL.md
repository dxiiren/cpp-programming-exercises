---
name: pre-pr-review
description: Use when the developer says 'pre-pr review', 'review my branch', 'audit my work', or 'self review' — self-reviews the current branch's diff against a plain-C++ exercise-collection checklist (compiles, cin input contract, per-program independence, docs/catalog sync) before opening a PR, then saves a report to .claude/workspace/reports/pr/.
model: opus
---

# Pre-PR Review (Self-Audit)

Self-review your feature-branch diff **before** opening a PR. This is a collection of 57
standalone plain-C++ console exercises (one `main()` per file in `src\`, no build system
beyond g++, no tests) — the goal is to catch compile breakage, input-contract drift, and
catalog rot early, not to restyle preserved uni coursework.

## Trigger

- `"pre-pr review"` / `"self review"`
- `"review my branch"` / `"review my work"` / `"review my code"`
- `"audit my work"` / `"audit my branch"`

## Do NOT flag

- The programs' existing decorative output (the `~~~~` boxes, `RM` prefixes, "Press Enter
  to continue" banners) — that IS the coursework; only flag output changes the branch
  itself broke.
- Pre-existing patterns the developer copied from a sibling exercise — not this branch's
  problem.
- Style-only rewrites of untouched code (the 2019-era indentation, `using namespace std`,
  implicit-int `main()`, Malay comments) unless the branch touches those lines anyway.
- The 8 known baseline `-Wall -Wextra` warnings in untouched files (see `/lint-check`).

## Step 1 — Branch & base

```bash
git branch --show-current
```

If on `main`: **STOP** — "You're on `main`; switch to your feature branch first."

```bash
git fetch origin main
git diff origin/main...HEAD --name-only
```

If no files changed: **STOP** — "No changes vs `main`."

Scope the review to reviewable source: `src/*.cpp`, `sample-inputs/*.txt`, `justfile`,
`setup.ps1`. **Exclude** `.claude/` and generated artifacts (`out/`). If only excluded
files changed: **STOP** — "No reviewable source changed."

Report: "Branch `{name}` changed {N} source files. Running review."

## Step 2 — Fetch the diff

```bash
git diff origin/main...HEAD -- 'src/*.cpp' 'sample-inputs/*.txt' justfile setup.ps1
```

For context-dependent checks (cin read order, loop conditions), read the **full file**,
not just the hunk — each program is small enough to read whole.

## Step 3 — Run the checklist

Verify each finding against the actual code before reporting it.

| #   | Check                        | Label      | What to look for                                                                                                                                                                  |
| --- | ---------------------------- | ---------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1   | **Compiles clean**           | issue      | `just build-all` exits 0 with `57/57 PASS` (58+ if the branch adds a program). Run it — one broken file fails the whole collection gate.                                            |
| 2   | **Runs end-to-end**          | issue      | For each changed program that has a `sample-inputs\<name>.txt`, `just run <name>` exits 0 with its closing output. A hang is a FAIL (a failed `cin >>` fail-states the stream and any y/n stop loop never ends). |
| 3   | **Input contract**           | issue      | Any added/reordered `cin >>` / `getline` MUST be mirrored in that program's `sample-inputs\<name>.txt` (exact order, one terminating answer). Watch the `cin >> x; cin.get(); getline(name)` newline dance — dropping the `cin.get()` makes `name` read empty. |
| 4   | **Parsing robustness**       | suggestion | `cin >> n` on non-numeric input fail-states the stream — several programs then loop forever. Does new input handling clear/re-prompt, or at least not make this worse? Flag regressions, don't demand a rewrite. |
| 5   | **Program independence**     | issue      | Every `src\*.cpp` stays a standalone translation unit with its own `main()` — no cross-file includes, no shared headers, no linking two exercises together. New files follow the kebab-case `<topic>.cpp` / `exN-qM-<topic>.cpp` naming. |
| 6   | **Loop/sentinel semantics**  | issue      | The looping programs use `while (toupper(answer) != 'Y')` on "Do you want to stop ? (y/n)" — `y` STOPS. Inverting the prompt or the test without the other breaks the committed input files. |
| 7   | **Catalog sync**             | issue      | A renamed/added/removed program MUST be reflected in the README catalog table and `.docs/05-reference/program-catalog.md` — the catalog is the collection's index; rot here is a blocking finding. |
| 8   | **No debug leftovers**       | issue      | `cout << "here"`-style debugging, commented-out dead blocks, `TODO` without follow-up. |
| 9   | **Naming & structure**       | suggestion | New code follows C++ conventions (initialize at declaration, `int main()`, pass by const ref where sensible) even though old code predates them.                                   |
| 10  | **Docs sync**                | suggestion | Behavior changes reflected in `README.md` / `.docs/` (especially the sample-input coverage list and troubleshooting).                                                              |

## Step 4 — Build & run gate

If any `src/*.cpp` file or `sample-inputs/*.txt` changed:

```bash
just build-all
just run <changed-program-with-sample-input>
```

Both must exit 0 with no crash or hang. Paste the `build-all summary:` line and the last
few run-output lines as evidence. A failure is an **issue** (blocking).

## Step 5 — Finding labels & caps

- **issue** (blocking) — fix before opening the PR.
- **suggestion** (non-blocking) — recommended.
- **nitpick** (non-blocking) — minor/optional.

Every finding must carry: the label, the `file:line`, and **WHY** it matters (not just what).
Issues: uncapped. Suggestions + nitpicks: cap at 15 total; note "{X} more non-blocking
findings omitted" if over.

## Step 6 — Present

```
## Pre-PR Review: {branch}
Branch: {branch} -> main   |   Files: {N}
Build/run gate: {pass/fail — build-all summary line + run exit codes}

### Issues (fix before PR)
1. [path:line] Finding — why it matters

### Suggestions
2. [path:line] Finding

### Nitpicks
3. [path:line] Finding

---
{Total} findings: {issues} issues, {suggestions} suggestions, {nitpicks} nitpicks
```

Zero findings → "No issues found — branch looks clean. Ready to open the PR."

## Step 7 — Save the report

Path: `.claude/workspace/reports/pr/{branch}-{YYYY-MM-DD}.md` (replace `/` in the branch name
with `-`; overwrite on a same-day re-run). Frontmatter then the same body as the terminal
output:

```yaml
---
branch: { branch }
base: main
date: { YYYY-MM-DD }
files_changed: { N }
issues: { count }
suggestions: { count }
nitpicks: { count }
---
```

Confirm: "Report saved to `{path}`".

## Tone

Self-improvement, not a verdict from a lead. "Consider extracting…", not "You must fix…".
Never directive, never judgmental.
