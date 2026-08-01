# Commands

> **TL;DR** Everything is a `just` recipe. `just list` names the programs;
> `just build-all` is the collection gate; `just run <name>` compiles and runs one
> program with canned stdin when a sample-input file exists.

Run `just` with no arguments to list recipes with their descriptions.

| Recipe | What it does | Notes |
| --- | --- | --- |
| `just` | List all recipes | |
| `just list` | Print all 57 program names, one per line | These are the valid `<name>` arguments |
| `just build <name>` | Compile `src\<name>.cpp` → `out\<name>.exe` | Errors if the name doesn't exist |
| `just build-all` | Compile every program in `src\` | Stops at the first compile error (exit 1); prints `[PASS]` per file + a final `57/57 PASS` summary |
| `just run <name>` | Build then run one program | stdin from `sample-inputs\<name>.txt` if present, else interactive with an `[INFO]` note |
| `just run-interactive <name>` | Build then run, always reading your typed input | Use to try your own values |
| `just clean` | Delete `out\` | Safe — everything rebuilds |
| `just claudex` / `claudeo` / `claudeh` | Launch Claude Code (Sonnet / Opus / Haiku), all permissions | |

## Implementation notes (why the recipes look odd)

- `gpp` points at `%LOCALAPPDATA%\Programs\w64devkit\bin\g++.exe` — an absolute pinned
  path so recipes work in shells opened before setup.ps1 updated PATH.
- `build`/`build-all` prepend the w64devkit bin dir to `PATH` for their own process:
  g++ finds its assembler `as` via PATH and dies with `cannot execute 'as'` without it.
- `run` uses `cmd /c "... < file"` instead of a PowerShell pipe: the PowerShell pipe
  injects a UTF-8 BOM into the first stdin line, which garbles a numeric first read.
- Sample inputs exist for: `assessment3-employee-payroll`, `movie-ticket`,
  `electric-bill`, `fibonacci-series`.

## Related docs

| Doc | Why |
| --- | --- |
| [`program-catalog.md`](program-catalog.md) | What each `<name>` is |
| [`project-layout.md`](project-layout.md) | Where files live |
| [`../06-troubleshooting/common-issues.md`](../06-troubleshooting/common-issues.md) | When a recipe misbehaves |
