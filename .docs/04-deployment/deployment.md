# Deployment

> **TL;DR** There is none. This is preserved university coursework that compiles and runs
> locally; no CI/CD, no releases, no hosted artifact. "Shipping" is pushing to `main` on
> GitHub.

## What exists

| Concern | Answer |
| --- | --- |
| CI/CD | none — no workflows; verification is local (`just build-all`) |
| Release artifacts | none — `out\` exes are git-ignored and rebuilt on demand |
| Hosting / server | n/a — every program is a run-to-completion console app |
| Distribution | clone the repo, run `pwsh ./setup.ps1`, `just build-all` |

## If you ever need to hand someone a binary

Build it locally (`just build <name>`) and send `out\<name>.exe` — it is statically
linked by w64devkit's GCC and runs on stock Windows. There is no signing and no installer;
prefer sending them the repo instead.

## Related docs

| Doc | Why |
| --- | --- |
| [`../02-setup/getting-started.md`](../02-setup/getting-started.md) | The only "deployment" that exists: a local setup |
| [`../03-development/workflow.md`](../03-development/workflow.md) | How changes reach `main` |
