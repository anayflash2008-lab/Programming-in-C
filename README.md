# C Programming

A collection of C programs written while learning the language, organised by
difficulty — from basic syntax through pointers and dynamic memory, plus data
structures and a set of console applications.

## Structure

| Folder | What's in it |
| --- | --- |
| [`Basic/`](Basic/) | Syntax, control flow, patterns, functions and recursion |
| [`Medium/`](Medium/) | Arrays and strings |
| [`Advanced/`](Advanced/) | Pointers and structures |
| [`Expert/`](Expert/) | Dynamic memory and function pointers |
| [`DSA/`](DSA/) | Data structures and algorithms |
| [`projects/`](projects/) | Complete console applications |

The numbered subfolders run `01`–`09` in learning order across the four
difficulty tiers.

### Basic

| Folder | Topics |
| --- | --- |
| [`01-syntax-and-control-flow/`](Basic/01-syntax-and-control-flow/) | Hello world, `if`/`else`, `for`, `while`, `do-while`, `typedef`, type conversion |
| [`02-patterns/`](Basic/02-patterns/) | Star and number pyramids, console animation |
| [`03-functions-and-recursion/`](Basic/03-functions-and-recursion/) | Function basics, return values, recursion, factorial and nCr |

### Medium

| Folder | Topics |
| --- | --- |
| [`04-arrays/`](Medium/04-arrays/) | 1D and 2D arrays, searching, bubble and selection sort, leaders, duplicate removal, vectors |
| [`05-strings/`](Medium/05-strings/) | Length, reversal, palindromes, vowel/character/letter counting, `string.h` functions |

### Advanced

| Folder | Topics |
| --- | --- |
| [`06-pointers/`](Advanced/06-pointers/) | Dereferencing, pointer arithmetic, pointers with arrays and strings, swapping |
| [`07-structures/`](Advanced/07-structures/) | `struct` basics, structures with pointers, record-keeping examples |

### Expert

| Folder | Topics |
| --- | --- |
| [`08-dynamic-memory/`](Expert/08-dynamic-memory/) | `malloc` / `free`, dynamically sized arrays |
| [`09-function-pointers/`](Expert/09-function-pointers/) | Calling a function through a pointer |

### DSA

| Folder | Topics |
| --- | --- |
| [`matrices/`](DSA/matrices/) | Addition, determinant (3x3 and NxN), inverse, sparse and complex matrices |
| [`stack-programming/`](DSA/stack-programming/) | Array-based stack, push / pop / peek |
| [`linked-list/`](DSA/linked-list/) | Singly and doubly linked lists, polynomial representation |
| [`tree/`](DSA/tree/) | Binary tree creation and traversal |

### Projects

| Program | What it does |
| --- | --- |
| [`tic-tac-toe.c`](projects/tic-tac-toe.c) | Two-player Tic Tac Toe on a 3x3 board |
| [`library-management.c`](projects/library-management.c) | Book records with add / search / delete, saved to file |
| [`expense-tracker.c`](projects/expense-tracker.c) | Category-wise expense logging and totals |
| [`calendar-generator.c`](projects/calendar-generator.c) | Prints any month or year, with leap-year handling |
| [`password-strength-checker.c`](projects/password-strength-checker.c) | Charset detection and entropy-based strength estimate |
| [`casino-betting.c`](projects/casino-betting.c) | Betting game tracking wins, losses and balance |
| [`slot-machine.c`](projects/slot-machine.c) | Slot machine with payout table and statistics |

## Building

Each `.c` file is a standalone program and compiles on its own:

```sh
gcc Medium/04-arrays/sorting-algorithms.c -o bin/sorting-algorithms
gcc projects/tic-tac-toe.c -o bin/tic-tac-toe
```

In VS Code, the task in [`.vscode/tasks.json`](.vscode/tasks.json) builds the active
file with <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd> and writes the executable to `bin/`.

Two exceptions:

- [`DSA/matrices/matrix-addition.c`](DSA/matrices/matrix-addition.c) is a helper module
  with no `main`; it is `#include`d by [`determinant-3x3.c`](DSA/matrices/determinant-3x3.c).
- [`Basic/02-patterns/moving-text-animation.c`](Basic/02-patterns/moving-text-animation.c)
  uses `<windows.h>` and is Windows-only.

## Notes

- Compiled binaries go to `bin/` and runtime data files to `data/`; both are gitignored.
- Programs are kept as originally written while learning, so style and error handling vary.
- A few files are still works in progress and do not yet compile — they either have no
  `main` yet or contain known errors.
