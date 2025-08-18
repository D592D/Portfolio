# Corner Grocer — Grocery Frequency Tracker

## Overview / Problem solved
This C++ program reads a plain-text list of grocery items (`CS210_Project_Three_Input_File.txt`), normalizes names, counts how often each item appears, and presents results interactively (lookup, list, histogram). It also writes a backup `frequency.dat`. The tool solves the manual problem of counting occurrences in a list and gives a quick way to inspect item frequency.

## Files
- `main.cpp` — program source (contains `GroceryTracker` class and menu)
- `CS210_Project_Three_Input_File.txt` — input (one item per line)
- `frequency.dat` — generated backup file (item frequency pairs)
- `README.md` — this file

## Build & Run (Windows PowerShell)
1. Compile:
```cmd
g++ main.cpp -o groceryTracker.exe
```
2. Run:
```cmd
.\groceryTracker.exe
```

On Linux/macOS use:
```bash
g++ main.cpp -o groceryTracker
./groceryTracker
```

## What I did particularly well
- Encapsulated functionality in a single-responsibility class (`GroceryTracker`).
- Implemented file-open error checks and input validation to avoid crashes on bad input.
- Wrote an automatic backup (`frequency.dat`) so results persist.
- Provided basic normalization (case folding and simple plural handling) to improve matching.

## Where the code could be enhanced
- Use `std::unordered_map` for faster average-case lookups (better performance on large datasets).
- Improve normalization: trim whitespace, remove punctuation, handle irregular plurals, and use locale-aware case conversion (improves accuracy).
- Add command-line options to specify input/output file paths (removes hard-coded filenames).
- Add unit tests and CI for correctness and regression prevention (improves maintainability).
- Validate/sanitize file paths and limit write locations when integrating untrusted input (security).

Impact of improvements:
- Efficiency: `unordered_map` reduces lookup/insertion time.
- Accuracy: better normalization reduces false negatives.
- Security/usability: path validation and CLI options reduce risk and increase flexibility.
- Reliability: automated tests catch regressions early.

## Most challenging parts and how they were overcome
- Reliable normalization (handling case, trailing characters, blank/whitespace lines) was the trickiest.
- Approach: used `std::getline` to preserve spacing, `std::tolower` for case folding, and iterative testing with sample inputs in VS Code.
- Resources: C++ reference documentation, the VS Code terminal, and small test files.

## Tools / resources used
- Visual Studio Code (editor + integrated terminal)
- g++ (MinGW-w64) for compilation
- C++ standard library documentation and small ad-hoc test files

## Transferable skills
- File I/O and error handling in C++
- Using associative containers for aggregation/counting
- Input validation and text normalization techniques
- Designing small, testable classes with clear responsibilities

## Maintainability, readability, adaptability
- Single-class design with descriptive method names (`loadData`, `writeBackupFile`, `printHistogram`) keeps responsibilities clear.
- Comments and straightforward control flow improve readability.
- Separation of I/O and processing logic makes it easy to swap data structures or add features (e.g., CLI args, tests) without extensive refactoring.

## Next steps (optional)
- Add unit tests for normalization and counting functions.
- Accept command-line input/output paths.
- Scale histogram output for large counts (e.g., scaled bars or CSV export).
