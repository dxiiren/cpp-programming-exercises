# Getting started

> **TL;DR** Run `pwsh ./setup.ps1` once, reopen PowerShell, then `just build-all` to
> compile all 57 programs and `just run movie-ticket` to see one run. Everything is
> installed by the script; the only true prerequisites are stock Windows PowerShell and
> winget.

## 1. One-time machine setup

```powershell
pwsh ./setup.ps1
```

Idempotent — safe to re-run any time; installed tools are skipped with `[OK]`. It installs:

| Tool | Why |
| --- | --- |
| Git | version control |
| Node.js LTS | only to install the Claude Code CLI |
| Claude Code CLI | AI-assisted development (optional to use) |
| uv + Python | `.claude` tooling (statusline, skill scripts) |
| w64devkit (g++ 16.x) | the C++ toolchain, extracted to `%LOCALAPPDATA%\Programs\w64devkit` |
| just | task runner for every day-2 command |
| GitHub CLI | `gh` for PRs (`gh auth login` once) |

It also seeds a git-ignored `.mcp.json` from the committed `.mcp.json.stub` — fill the
`REPLACE_WITH_*` GitHub PAT placeholder by hand if you want the GitHub MCP.

**Close and reopen PowerShell afterwards** so PATH updates land.

## 2. First build and run

```powershell
just list               # all 57 program names
just build-all          # compile everything -> out\*.exe (expect "57/57 PASS, 0 FAIL")
just run movie-ticket   # compile + run with the committed sample input
```

`just run <name>` feeds `sample-inputs\<name>.txt` as stdin when it exists
(`assessment3-employee-payroll`, `movie-ticket`, `electric-bill`, `fibonacci-series`);
any other program runs interactively — type at its prompts.

## 3. Sanity checklist

| Check | Expect |
| --- | --- |
| `just build-all` | exit 0, `build-all summary: 57/57 PASS, 0 FAIL` |
| `just run fibonacci-series` | `Fibonacci Series: 1 1 2 3 5 8 13 21 34 55` |
| re-run `pwsh ./setup.ps1` | every step `[OK]`, no installs |

## Related docs

| Doc | Why |
| --- | --- |
| [`../03-development/workflow.md`](../03-development/workflow.md) | The day-2 loop after setup works |
| [`../05-reference/commands.md`](../05-reference/commands.md) | Every just recipe |
| [`../06-troubleshooting/common-issues.md`](../06-troubleshooting/common-issues.md) | If a step fails |
