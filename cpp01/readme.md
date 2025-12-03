# CPP01 — Memory, References, File IO, Dispatch Tables

Full notes on ownership decisions and basic IO patterns.

## Stack vs heap lifetime
- Stack objects die automatically at scope end; use them by default for simplicity.
- Heap objects created with `new`/`new[]` need matching `delete`/`delete[]` even on early returns; wrap loops to free arrays.
- Logging destructors (as in Zombie exercises) makes lifetime visible and helps catch leaks or double deletes.

## References vs pointers
- References must bind at initialization and cannot be reseated; great for mandatory dependencies (`HumanA` must always have a weapon).
- Pointers can be `NULL`/`0` and reassigned; great for optional state (`HumanB` can fight unarmed or swap weapons).
- When passing objects you do not want to copy, prefer `const T&` to avoid duplication while staying non-null.

```cpp
Weapon club("crude spiked club");
HumanA bob("Bob", club);   // reference: must exist
HumanB jim("Jim");         // pointer: optional
jim.setWeapon(&club);      // can later set to NULL to drop the weapon
```

## Constructors, destructors, and ownership
- Respect construction order: base classes first, then members in declaration order. Destruction happens in reverse.
- Pair every allocation with destruction in the destructor or manage through RAII wrappers when allowed.
- Implement copy constructor and assignment when the class owns heap memory to avoid shallow copies (Rule of Three starts here).

## File streams and text processing
- Use `std::ifstream` and `std::ofstream`; check `.is_open()`/`.good()` before reading/writing.
- For replace, read line by line, search for `s1`, and rebuild the output to `<filename>.replace`. Guard against empty `s1` to avoid infinite loops.

```cpp
size_t pos = 0;
while ((pos = line.find(s1, pos)) != std::string::npos) {
    out << line.substr(0, pos) << s2;
    line.erase(0, pos + s1.size());
    pos = 0; // restart search on the trimmed line
}
```

## Member-function pointer dispatch (Harl)
- Replace `switch`/`if` ladders with arrays of member-function pointers.
- Map strings to function pointers and call through `(this->*ptr)()` to keep code compact and easily extensible.
- Filtering (ex06) just means choosing the starting index and letting the loop fall through higher severities.

```cpp
typedef void (Harl::*Handler)();
static const char *levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
Handler actions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

for (size_t i = 0; i < 4; ++i) {
    if (input == levels[i]) {
        (this->*actions[i])();
        break;
    }
}
```

## Input hygiene
- Always validate user input for indices (phonebook) or empty arguments (replace strings).
- Normalize strings (trim, handle empty) to keep output consistent.

## Re-run quickly
```bash
make -C ex00 && ./ex00/zombie
make -C ex04 && ./ex04/replace file s1 s2
make -C ex06 && ./ex06/harlFilter WARNING
```
