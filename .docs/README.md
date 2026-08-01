# cpp-programming-exercises — documentation

Documentation for the CSC126 C++ exercise collection: 57 standalone console programs,
one toolchain, one task runner.

> **New here? Start with [`tldr.md`](tldr.md)** — every document summarised in 30 seconds
> each.

## Who is this for?

| Reader | Start here |
| --- | --- |
| New developer setting up the machine | [`02-setup/getting-started.md`](02-setup/getting-started.md) |
| Anyone asking "what are these 57 programs?" | [`05-reference/program-catalog.md`](05-reference/program-catalog.md) |
| Contributor changing a program | [`03-development/workflow.md`](03-development/workflow.md) |
| Someone whose build/run just failed | [`06-troubleshooting/common-issues.md`](06-troubleshooting/common-issues.md) |
| Historian / provenance check | [`01-overview/project-overview.md`](01-overview/project-overview.md) |

## Recommended reading order

1. [`tldr.md`](tldr.md)
2. [`01-overview/project-overview.md`](01-overview/project-overview.md)
3. [`02-setup/getting-started.md`](02-setup/getting-started.md)
4. [`05-reference/commands.md`](05-reference/commands.md)
5. [`05-reference/program-catalog.md`](05-reference/program-catalog.md)
6. [`03-development/workflow.md`](03-development/workflow.md)
7. The rest as needed.

## 01-overview

| Document | What it covers |
| --- | --- |
| [`project-overview.md`](01-overview/project-overview.md) | What the collection is, import provenance, exclusions, and the full original-filename mapping |

## 02-setup

| Document | What it covers |
| --- | --- |
| [`getting-started.md`](02-setup/getting-started.md) | setup.ps1, first build-all, first run, sanity checklist |

## 03-development

| Document | What it covers |
| --- | --- |
| [`workflow.md`](03-development/workflow.md) | Branch → edit → verify → review → commit loop, input contract, house rules |

## 04-deployment

| Document | What it covers |
| --- | --- |
| [`deployment.md`](04-deployment/deployment.md) | Honest answer: no CI/CD, no releases — local compile-run only |

## 05-reference

| Document | What it covers |
| --- | --- |
| [`commands.md`](05-reference/commands.md) | Every just recipe + why the recipes are shaped that way |
| [`program-catalog.md`](05-reference/program-catalog.md) | All 57 programs, input behavior, known coursework quirks |
| [`project-layout.md`](05-reference/project-layout.md) | Annotated file tree and naming conventions |

## 06-troubleshooting

| Document | What it covers |
| --- | --- |
| [`common-issues.md`](06-troubleshooting/common-issues.md) | Real symptoms: missing g++, `cannot execute 'as'`, stdin hangs, BOM garbage, the warning baseline |

## 07-faq

| Document | What it covers |
| --- | --- |
| [`faq.md`](07-faq/faq.md) | Why-questions: preserved bugs, flat layout, renames, the excluded file, toolchain choice |
