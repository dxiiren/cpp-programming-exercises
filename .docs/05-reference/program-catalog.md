# Program catalog

> **TL;DR** The full inventory: every program, what it does, what it reads, and the known
> coursework quirks preserved on purpose. Names are the `just run <name>` arguments.

Input column: **none** = prints and exits, no stdin · **stdin** = interactive prompts
(run via `just run-interactive <name>` or type at `just run <name>`) · **sample** =
committed `sample-inputs\<name>.txt`, so `just run <name>` is unattended.

## Basics — I/O, arithmetic, operators

| Program | What it does | Input |
| --- | --- | --- |
| `add-2-numbers` | Read two integers and print their sum | stdin |
| `area-of-triangle` | Base and height to triangle area (`0.5*b*h`) | stdin |
| `average-of-3-people` | Average the ages of three people | stdin |
| `boolean` | Bool expression on hardcoded marks; prints the 0/1 result | none |
| `divide-2-numbers` | Division with a divide-by-zero guard | stdin |
| `increment-operators` | `++`/`--`/`+=`/`sqrt` walkthrough on one variable | none |
| `larger-number` | Print the larger of two numbers | stdin |
| `output-design-assignment` | Read and echo a student's name, ID, and age | stdin |
| `test` | Array rewrite: odd values become 99, odd indexes +8; prints the result row | none |

## Selection — if/else chains

| Program | What it does | Input |
| --- | --- | --- |
| `bmi-function` | BMI via a value-returning function, then a health status | stdin |
| `comma-draft` | Insert a thousands comma into a number over 1000 (draft attempt) | stdin |
| `comma-percent` | Thousands-comma formatting via `%`; validates 1000–50000 | stdin |
| `discount-price` | Price + discount rate to price after discount | stdin |
| `electric-bill` | Tiered bill: 0.10/unit ≤100, 0.30 ≤600, 0.50 ≤1100, 0.70 above | sample |
| `even-and-odd-number` | Parity check; an odd number gets incremented into a "new number" | stdin |
| `even-and-odd-v2` | Clean odd/even verdict for one integer | stdin |
| `final-exam-v2` | Weighted score (exam 70% of /100, project 20% of /80, test 10% of /60) + PASS/FAIL at 50 | stdin |
| `final-score-of-student` | Same weighting idea (project /50), no verdict | stdin |
| `format-time` | 24-hour `HHMM` integer to 12-hour am/pm display | stdin |
| `high-tech-company` | Capital + IT-headcount rules decide "high-tech company" | stdin |
| `land-area-tax` | Tiered land tax by acreage (10/20/35/50 per acre) | stdin |
| `loan-application` | Eligibility (loan vs yearly income and tenure) + monthly payment | stdin |
| `movie-ticket` | Ticket total: seniors -40%, children -50%, kids free | sample |
| `shoe-discount` | Shoe type A/B/C discount pricing, quantity-dependent for B/C | stdin |

## Loops — for/while/sentinel

| Program | What it does | Input |
| --- | --- | --- |
| `avg-mark-student-and-class` | Per-student test average + 40/60-weighted score, then the class average | stdin |
| `blood-pressure-and-sugar` | 5 patients' BP/sugar to hypertension, diabetes, and combined counts | stdin |
| `count-even-and-odd-data` | Read 10 numbers; count evens and odds | stdin |
| `electrical-salesman` | Item-sales loop (A–D, tiered commission %) to total commission + best seller | stdin |
| `fibonacci-series` | First n Fibonacci terms | sample |
| `following-series` | Prints 2i/3i fractions for n terms plus their sum | stdin |
| `modify-salesman` | Nested loops: per-salesman commissions, grand total, average | stdin |
| `pair-number-repeat` | Sum pairs until both numbers match; largest sum + count over 500 | stdin |
| `salesman` | 5 salesmen: salary + 3% of sales; highest/lowest/total | stdin |
| `salesman-v2` | y/n-looped salesman income with loan deduction + average | stdin |
| `sentinel-even-odd` | Sentinel-0 loop counting evens/odds plus min and max | stdin |
| `sum-of-odd-numbers` | Lists odd numbers 101–199 and sums the series | none |

## Exercise sets (Ex3–Ex8) — patterns, functions, arrays

| Program | What it does | Input |
| --- | --- | --- |
| `ex3-q6a-pattern` | `?` hourglass from nested count-down/count-up loops | none |
| `ex3-q6b-pattern` | `=` rails around `+ +` rows | none |
| `ex3-q6c-pattern` | `*` growing triangle + solid block | none |
| `ex3-q9-student-activity-points` | Per-student activity points; qualified (>100) count, highest, lowest | stdin |
| `ex4-q4-even-odd-function` | Parity via a reference-parameter function | stdin |
| `ex4-q6-delivery-package` | Delivery charge = mass rate + zone fee + 5% (two helper functions) | stdin |
| `ex4-q7-total-delivery` | 20 parcels through the same charging; highest/lowest/total | stdin |
| `ex4-q9-bmi-reference` | BMI via a reference out-parameter | stdin |
| `ex4-q10-next-day` | Next calendar day with month-length/December handling | stdin |
| `ex4-q10b-next-week` | Date one week ahead incl. leap-year February | stdin |
| `ex4-q10c-next-10-weeks` | Next day, then 4 `nextWeek` hops | stdin |
| `ex5-q2a-quiz-marks-array` | 4 quiz marks in an array: total, average, above-average marks | stdin |
| `ex5-q3-rainfall` | 12 months of rainfall: total, wettest/driest month, above-average months | stdin |
| `ex5-q4-array-merge-compare` | Two 5-element arrays: element sums (array c) and element-wise max (array d) | stdin |
| `ex5-q5-grade-counter` | Grade tally (A/B/C/D bands) with y/n stop loop + most popular grade | stdin |
| `ex5-q5-grade-counter-v2` | Grade tally for exactly 10 marks (for-loop variant) | stdin |
| `ex5-q6-car-sales` | Units sold across 5 car types at fixed prices: per-type totals, overall, most popular | stdin |
| `ex8-q4-date-formatter` | Numeric d/m/y to "1 January 2020"; loops until day/month 0 | stdin |
| `previous-day` | Previous calendar day incl. leap-year February | stdin |
| `untitled2-grade-counter` | Grade tally variant with a leftover debug print | stdin |

## Assessments

| Program | What it does | Input |
| --- | --- | --- |
| `assessment3-employee-payroll` | Weekly payroll: tiered gross (RM8 ≤40h, RM12 41–50h, RM16 >50h), 8%+11%+RM10 deduction, net pay; closing head-count / highest-paid / underpaid summary | sample |

**Excluded:** `assesment3try.cpp` — the final iteration of this assessment — was published
as a standalone repo instead. That standalone copy was retired; this collection's
`assessment3-employee-payroll.cpp` is the canonical version — the earlier draft (it
compares `gross` rather than monthly salary for the highest/underpaid summary).

## Known coursework quirks (preserved, do not "fix" casually)

| Program | Quirk |
| --- | --- |
| `ex4-q9-bmi-reference` | Calls `BMI(height, weight, bmi)` but the parameters are declared `(weight, height, ...)` — arguments swapped, so the BMI is inverted; also labels low BMI "unhealthy" and high BMI "underweight" |
| `ex4-q10c-next-10-weeks` | Name says 10 weeks; the loop advances 4 |
| `previous-day` | Computes the previous day but prints "The next day is" |
| `sum-of-odd-numbers` | Adds `n` after incrementing, so the printed list and the sum are off by one step |
| `ex5-q6-car-sales` | `overall` accumulator never initialized — the overall total can print garbage |
| `ex4-q7-total-delivery` | `sumall` accumulator never initialized — same risk |
| `ex4-q6-delivery-package` / `ex4-q7-total-delivery` | Zone `'E'` tested twice; `'W'` unreachable (falls to 0) |
| `untitled2-grade-counter` | `cout<<"gdjgjgw"` debug leftover before the popular-grade block |
| 8 files | One `-Wall -Wextra` warning each — the accepted baseline, see [`../06-troubleshooting/common-issues.md`](../06-troubleshooting/common-issues.md) |

## Related docs

| Doc | Why |
| --- | --- |
| [`../01-overview/project-overview.md`](../01-overview/project-overview.md) | Original filename mapping + provenance |
| [`commands.md`](commands.md) | How to build/run any row above |
| [`../06-troubleshooting/common-issues.md`](../06-troubleshooting/common-issues.md) | Hangs, warnings, PATH issues |
