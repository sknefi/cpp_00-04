# CPP00 — Foundations: CLI, Streams, Classes

Long-form notes of what I drilled in this module.

## Class layout & canonical form
- Always provide the orthodox canonical form early (default ctor, copy ctor, copy assignment, destructor) even for tiny classes so copying is predictable.
- Split headers (`.hpp`) and sources (`.cpp`), include only what is needed, and keep data private; expose behavior through member functions.
- Constructors and destructors run in deterministic order; use them to log lifecycle during exercises.

## Static data & functions
- `static` members belong to the class, not the instance; declare in-class, define once in a `.cpp`, and access through the class name.
- Great for shared counters (total accounts, deposits, withdrawals) while keeping per-instance state private.
- Pair static getters with const methods to read shared state safely without exposing the underlying variables.

```cpp
class Account {
public:
    Account(int initial) : _amount(initial) { ++_nbAccounts; _totalAmount += initial; }
    Account(Account const& other) { *this = other; ++_nbAccounts; _totalAmount += _amount; }
    Account& operator=(Account const& other) { _amount = other._amount; return *this; }
    ~Account() { --_nbAccounts; _totalAmount -= _amount; }

    void makeDeposit(int amount) { _amount += amount; _totalAmount += amount; }
    static int getNbAccounts() { return _nbAccounts; }
private:
    static int _nbAccounts;
    static int _totalAmount;
    int        _amount;
};
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
```

## CLI parsing and cctype
- Signatures: `int main(int argc, char *argv[])`. Validate `argc` before indexing `argv`.
- Cast `argv[i][j]` to `unsigned char` before `std::toupper`/`std::tolower` to avoid UB with negative `char`.
- Iterate args with nested loops to transform each character; print fallback output when no args are provided.

## Streams & formatting
- Use `<iostream>` for input/output and `<iomanip>` helpers (`std::setw`, `std::setfill`, `std::right`) to align phonebook columns.
- Build table headers and rows consistently to avoid manual padding bugs.
- Prefer `std::stringstream` for converting types to formatted strings when needed.

## Input validation
- Phonebook: keep a fixed-size array of 8 contacts and wrap around when full; never trust user indices—check range before accessing.
- Trim or sanitize empty fields so the stored data is meaningful; guard against empty strings when printing.

## Makefiles & build habits
- Each exercise has its own Makefile with `NAME`, `SRC`, `OBJ`, and targets `all`, `clean`, `fclean`, `re`.
- Compile with `-Wall -Wextra -Werror -std=c++98`; treat warnings as errors.
- Keep include paths explicit and avoid over-linking.

## Re-run quickly
```bash
make -C ex00 && ./ex00/megaphone "Hello world"
make -C ex01 && ./ex01/phonebook
make -C ex02 && ./ex02/account
```
