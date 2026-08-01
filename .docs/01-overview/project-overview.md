# Project overview

> **TL;DR** 57 standalone C++ console programs from UiTM's CSC126 course (Fundamentals of
> Algorithm and Computer Problem Solving), imported from the original coursework archive,
> renamed to kebab-case under `src/`, and preserved as written — quirks, Malay comments,
> and all. One `main()` per file; no shared code.

## What this is

The C++ half of the developer's CSC126 coursework: practice drills and graded exercises
covering the course's four pillars — sequential I/O, selection (`if`/`else`), repetition
(`for`/`while`/sentinel loops), functions (value/reference parameters), and 1-D arrays.
Every program is a small run-to-completion CLI that reads from `cin` (49 of 57) or just
prints (8 of 57). The full program-by-program catalog lives in
[`../05-reference/program-catalog.md`](../05-reference/program-catalog.md) and the README.

The code is **preserved coursework**: implicit-int `main()`, uninitialized accumulators,
a swapped-argument BMI bug, and leftover debug prints are kept as historical record. All
57 files compile cleanly with g++ 16.1.0 (8 files carry one `-Wall -Wextra` warning each —
see [`../06-troubleshooting/common-issues.md`](../06-troubleshooting/common-issues.md)).

## Import provenance and exclusions

Imported 2026-08 from the university archive folder
`...\UITM\SEM 5\Preparation\Projek\CSC126(programming algorithm) - C++ ide\C++\`.

- Only `.cpp` sources were copied — the archive's per-program `.exe` builds were left behind.
- Two orphan executables (`EX4 , q2.exe`, `EX4 , Q7.exe`) had no matching source and were
  not imported.
- `assesment3try.cpp` (the final iteration of Assessment 3) is **byte-identical** to the
  source already published as
  [`dxiiren/employee-salary-counter`](https://github.com/dxiiren/employee-salary-counter)
  and was excluded; the earlier draft `Assessment3.cpp` is kept here as
  `assessment3-employee-payroll.cpp`.
- No sanitization was needed: no matric/IC numbers, names, or credentials appear in any file.

## Filename mapping (original archive name → `src/` name)

| Original | `src/` |
| --- | --- |
| `Assessment3.cpp` | `assessment3-employee-payroll.cpp` |
| `Averageof3People.cpp` | `average-of-3-people.cpp` |
| `Avg mark student and class.cpp` | `avg-mark-student-and-class.cpp` |
| `bloodpressure and sugar.cpp` | `blood-pressure-and-sugar.cpp` |
| `Bmi address EX4 Q9.cpp` | `ex4-q9-bmi-reference.cpp` |
| `bmi function.cpp` | `bmi-function.cpp` |
| `boolean.cpp` | `boolean.cpp` |
| `CalculateTheAreaofTriangle.cpp` | `area-of-triangle.cpp` |
| `comma draft.cpp` | `comma-draft.cpp` |
| `comma%.cpp` | `comma-percent.cpp` |
| `Count Even and odd data.cpp` | `count-even-and-odd-data.cpp` |
| `Date Q4 Ex8.cpp` | `ex8-q4-date-formatter.cpp` |
| `delivery package  EX4 Q6.cpp` | `ex4-q6-delivery-package.cpp` |
| `DiscountPrice.cpp` | `discount-price.cpp` |
| `divide 2 number basic.cpp` | `divide-2-numbers.cpp` |
| `electric bill.cpp` | `electric-bill.cpp` |
| `Electrical Salesman.cpp` | `electrical-salesman.cpp` |
| `even and number v2.cpp` | `even-and-odd-v2.cpp` |
| `even and odd fx EX4 Q4.cpp` | `ex4-q4-even-odd-function.cpp` |
| `even and odd number.cpp` | `even-and-odd-number.cpp` |
| `Ex3 Q 9.cpp` | `ex3-q9-student-activity-points.cpp` |
| `Ex3 Q6a.cpp` | `ex3-q6a-pattern.cpp` |
| `EX3 Q6b.cpp` | `ex3-q6b-pattern.cpp` |
| `EX3 Q6c.cpp` | `ex3-q6c-pattern.cpp` |
| `Ex5 Q2a.cpp` | `ex5-q2a-quiz-marks-array.cpp` |
| `Ex5 Q3.cpp` | `ex5-q3-rainfall.cpp` |
| `Ex5 Q4.cpp` | `ex5-q4-array-merge-compare.cpp` |
| `Ex5 Q5.cpp` | `ex5-q5-grade-counter.cpp` |
| `ex5 q6.cpp` | `ex5-q6-car-sales.cpp` |
| `ex5_q5.cpp` | `ex5-q5-grade-counter-v2.cpp` |
| `Example of +++ .cpp` | `increment-operators.cpp` |
| `Fibonaci Series.cpp` | `fibonacci-series.cpp` |
| `FinalExam_V2.cpp` | `final-exam-v2.cpp` |
| `FinalScoreofStudent.cpp` | `final-score-of-student.cpp` |
| `Following Series.cpp` | `following-series.cpp` |
| `format time.cpp` | `format-time.cpp` |
| `High tech company.cpp` | `high-tech-company.cpp` |
| `land area.cpp` | `land-area-tax.cpp` |
| `Larger number.cpp` | `larger-number.cpp` |
| `loan.cpp` | `loan-application.cpp` |
| `modify salesman.cpp` | `modify-salesman.cpp` |
| `movie ticket.cpp` | `movie-ticket.cpp` |
| `Next 10 week EX4 Q10c.cpp` | `ex4-q10c-next-10-weeks.cpp` |
| `Next Day EX4 Q10.cpp` | `ex4-q10-next-day.cpp` |
| `Next Week Ex4 Q10b.cpp` | `ex4-q10b-next-week.cpp` |
| `OutputDesign-assignment.cpp` | `output-design-assignment.cpp` |
| `Pair number repeat.cpp` | `pair-number-repeat.cpp` |
| `Previous Day.cpp` | `previous-day.cpp` |
| `ProgramToAdd2numb.cpp` | `add-2-numbers.cpp` |
| `salesman.cpp` | `salesman.cpp` |
| `salesmanv2.cpp` | `salesman-v2.cpp` |
| `Sentinal even odd.cpp` | `sentinel-even-odd.cpp` |
| `shoe.cpp` | `shoe-discount.cpp` |
| `Sum of odd num.cpp` | `sum-of-odd-numbers.cpp` |
| `test.cpp` | `test.cpp` |
| `total delivery EX4 Q7.cpp` | `ex4-q7-total-delivery.cpp` |
| `Untitled2.cpp` | `untitled2-grade-counter.cpp` |

Renaming rules: kebab-case; lab exercises keep their `exN-qM-` prefix; content-derived
descriptors were appended only where the original name was meaningless (`Untitled2`) or
unwritable (`Example of +++ `, `comma%`).

## Related docs

| Doc | Why |
| --- | --- |
| [`../05-reference/program-catalog.md`](../05-reference/program-catalog.md) | What every program does + input behavior |
| [`../02-setup/getting-started.md`](../02-setup/getting-started.md) | Get the toolchain and run your first program |
| [`../03-development/workflow.md`](../03-development/workflow.md) | Day-2 loop: build, run, review, commit |
