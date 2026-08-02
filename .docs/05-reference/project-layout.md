# Project layout

> **TL;DR** All 57 programs sit flat in `src/` (kebab-case, one `main()` each), canned
> stdin lives in `sample-inputs/`, builds land in git-ignored `out/`, and the tooling is
> `justfile` + `setup.ps1` at the root.

```
cpp-programming-exercises/
  src/                          # 57 standalone .cpp programs — the whole collection
    <topic>.cpp                 #   free-standing drills (movie-ticket.cpp, loan-application.cpp, ...)
    exN-qM-<topic>.cpp          #   lab exercises keeping their exercise/question number
    assessment3-employee-payroll.cpp   # graded assessment draft — canonical version (the standalone repo copy was retired)
  sample-inputs/                # canned stdin for `just run <name>` — 10 files, named after their program
  tests/                        # golden-output harness (`just test`)
    run-tests.ps1               #   builds + runs every program with a golden, diffs stdout
                                #   (parallel; -ThrottleLimit 1 for a serial run)
    expected/                   #   57 committed goldens, named after their program
  out/                          # compiled <name>.exe files — git-ignored, `just clean` deletes
  .docs/                        # this documentation set (01-overview ... 07-faq + tldr)
  .claude/                      # Claude Code kit
    skills/                     #   project skills (see skills/README.md catalog)
    hooks/statusline.py         #   statusline script
    memory/MEMORY.md            #   project memory index
    settings.json               #   committed settings (statusline, permissions, MCP enable list)
  justfile                      # day-2 recipes (list/build/build-all/run/clean)
  setup.ps1                     # idempotent machine bootstrap
  CLAUDE.md                     # AI-agent operating rules for this repo
  README.md                     # human front door + full program catalog
  .mcp.json.stub                # committed MCP config template (.mcp.json itself is git-ignored)
  .gitignore                    # out/, .mcp.json, settings.local.json, workspace/
```

Conventions:

- Flat `src/` on purpose — the originals were one flat folder; grouping lives in the
  catalog tables, not the filesystem.
- One program = one file = one `main()`. Nothing links against anything else.
- A program's sample input (when it has one) shares its exact name:
  `sample-inputs\<name>.txt` for `src\<name>.cpp`.

## Related docs

| Doc | Why |
| --- | --- |
| [`../01-overview/project-overview.md`](../01-overview/project-overview.md) | Original archive filename mapping |
| [`program-catalog.md`](program-catalog.md) | Per-program inventory |
| [`commands.md`](commands.md) | The recipes that operate on this layout |
