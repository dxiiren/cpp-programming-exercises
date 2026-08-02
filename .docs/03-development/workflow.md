# Development workflow

> **TL;DR** Branch off `main`, edit one program under `src/`, `just build <name>` +
> `just run <name>` to verify, keep its `sample-inputs` file in sync with any cin change,
> then `/commit` and `/create-pr`. Never restyle untouched coursework.

## The loop

1. **Branch** — `git checkout -b fix/<topic>` (never commit straight to `main` for real work).
2. **Edit** — each `src\*.cpp` is standalone; a change to one program can't break another.
   New programs follow the kebab-case naming (`<topic>.cpp` or `exN-qM-<topic>.cpp`) and
   must be added to the README catalog + `.docs/05-reference/program-catalog.md`.
3. **Verify** —
   ```powershell
   just build <name>       # compile just your program
   just run <name>         # run it (sample input or interactive)
   just build-all          # the collection gate: 57/57 PASS expected
   just test               # the output gate: 11/11 PASS expected (golden diffs)
   ```
4. **Input contract** — if you add/reorder a `cin >>`/`getline`, mirror it in that
   program's `sample-inputs\<name>.txt` (exact read order; a y/n loop needs its final
   `y`). A drifted file makes the run hang forever, not crash. If the program has a
   golden in `tests\expected\` and its intended output changed, regenerate the golden
   from a verified run (the failing run's stdout is at `out\<name>.actual.txt`).
5. **Review** — `/pre-pr-review` for the checklist; `/lint-check` for the warning +
   build-all gates.
6. **Commit / PR** — `/commit` (Conventional Commits, scopes: `src`, `input`, `tooling`,
   `docs`, `skills`), then `/create-pr`. No attribution footers, ever.

## House rules

- **Preserve coursework** — untouched files keep their quirks (implicit-int `main()`,
  Malay comments, the 8 baseline warnings, known logic bugs documented in the catalog).
  Fix a quirk only when that fix is the point of the branch.
- **No build system creep** — no CMake/Make/vcpkg; the collection stays plain per-file
  `g++`. Propose tooling changes to the developer instead of adding them.
- **out\ is disposable** — never commit compiled exes; `just clean` resets it.
- **Don't "fix" the justfile's cmd redirect or PATH-prepend** — both are deliberate
  (see [`../06-troubleshooting/common-issues.md`](../06-troubleshooting/common-issues.md)).

## Related docs

| Doc | Why |
| --- | --- |
| [`../05-reference/commands.md`](../05-reference/commands.md) | Recipe reference |
| [`../05-reference/program-catalog.md`](../05-reference/program-catalog.md) | Program inventory + input behavior |
| [`../04-deployment/deployment.md`](../04-deployment/deployment.md) | Why there is no deploy step |
