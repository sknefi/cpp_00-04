# 42 C++ Modules 00-04

Documenting what I learnt while solving the first five chapters (cpp00 -> cpp04) of the 42 C++ curriculum. Each folder is self-contained with its own Makefile so I can revisit or demo any exercise quickly.

## Toolchain & Conventions
- Compiler: `c++`/`clang++` with `-Wall -Wextra -Werror -std=c++98`.
- Every Makefile exposes the classical `all`, `clean`, `fclean`, and `re` targets so I can rebuild fast.
- When a function takes no arguments I still spell out `void` whenever the subject requests it, even though C++ does not require it.
- Stick to the STL pieces allowed by each module and treat warnings as failures to stay within the 42 norm.

## Build & Run Quickstart
1. `make -C cpp0X/ex0Y` inside the exercise I want to try.
2. Run the generated binary (its name matches the exercise, e.g. `megaphone`, `phonebook`, `zombie`, `ClapTrap`, ...).
3. Clean artifacts with `make clean` or `make fclean` in the same folder when needed.

```bash
make -C cpp03/ex02
./cpp03/ex02/FragTrap
```

## Repository Map

| Path | Exercises | Focus |
| --- | --- | --- |
| `cpp00` | ex00-ex02 | CLI handling, tiny classes, Makefiles. |
| `cpp01` | ex00-ex06 | Memory allocation, references vs pointers, file streams, switch replacements. |
| `cpp02` | ex00-ex03 | Fixed-point arithmetic and operator overloading. |
| `cpp03` | ex00-ex03 | Inheritance chains and the diamond problem with ClapTraps. |
| `cpp04` | ex00-ex03 | Polymorphism, abstract classes, interface driven design. |
| `test.cpp` | - | Scratch pad for small experiments before copying ideas into the modules. |

## Chapter Notes

### CPP00 — Kickoff: Streams, Classes & Static Members
- `ex00/megaphone` made me comfortable with iterating CLI arguments, normalizing characters with `<cctype>`, and handling empty input edge cases.
- `ex01/phonebook` reinforced splitting classes into headers/sources, keeping a fixed-size storage, formatting tables with `std::setw`, and sanitizing user input.
- `ex02/account` forced me to use `static` attributes/functions to track shared state (total deposits, withdrawals, timestamps) across all instances.
- Learned to keep Makefiles minimal yet reusable and to adopt the canonical form (default ctor, copy ctor, assignment, destructor) from the very beginning.

### CPP01 — Memory, References & Simple File IO
- `ex00`/`ex01` (Zombie and ZombieHorde) contrasted stack allocation against `new`/`delete` while practicing destructors and cleanup loops.
- `ex02` (HI THIS IS BRAIN) was my quick test bed for comparing pointers to references and observing aliasing in practice.
- `ex03` (Weapon/HumanA/HumanB) showed why references require initialization and how pointers let me swap the weapon at runtime.
- `ex04` (Sed-is-for-losers) focused on `std::ifstream`/`std::ofstream`, error handling, and simple find/replace loops.
- `ex05` and `ex06` (Harl) replaced `switch` statements with arrays of member-function pointers plus filtering logic to shout only what is needed.
- Overall this chapter solidified constructor/destroyer ordering, ownership rules, and basic resource management.

### CPP02 — Orthodox Canonical Form & Fixed-Point Math
- Implemented a `Fixed` class with a constant number of fractional bits, which drilled in the orthodox canonical form and the importance of const-correctness.
- Added conversion constructors plus `toFloat`/`toInt` helpers to translate between primitive types and my fixed representation.
- Overloaded comparison, arithmetic, and increment operators so the class behaves like a built-in type while respecting overflow limits.
- `ex03/bsp` introduced the barycentric technique to test whether a `Point` lives inside a triangle, highlighting immutability and pass-by-const-reference patterns.

### CPP03 — Inheritance Chains & the Diamond Trap
- `ex00` built the base `ClapTrap` with hit points, energy points, and attack damage plus guard rails against over-spending resources.
- `ex01` and `ex02` derived `ScavTrap` and `FragTrap`, teaching me to call parent constructors, override behaviors, and extend the public API with guard/high-five modes.
- `ex03` (DiamondTrap) combined both derived classes, so I had to understand multiple inheritance, explicitly resolve name clashes, and reuse ClapTrap's protected members responsibly.
- Learned to log actions consistently and reason about object lifetime through the inheritance hierarchy.

### CPP04 — Polymorphism, Abstract Classes & Interfaces
- `ex00` contrasted proper polymorphism (`Animal` with virtual methods) with the intentionally broken `WrongAnimal` hierarchy to show why virtual destructors matter.
- `ex01` introduced the `Brain` class which required deep copies in copy constructors/assignment to avoid sharing internal ideas arrays between cats and dogs.
- `ex02` (AAnimal) enforced abstraction with pure virtual functions; any concrete animal now must implement `makeSound`, and instantiating the base becomes illegal.
- `ex03` (`MateriaSource`, `AMateria`, `ICharacter`) was my first interface-driven design: cloning Materia, equipping/unequipping inventory slots, and guaranteeing cleanup through well-defined ownership.
- Came away with a better intuition for upcasting/downcasting, resource duplication, and when to expose virtual hooks.

## Next Up
- Continue toward `cpp05`+ (exceptions and nested classes) while keeping these notes in sync.
- Revisit each module with extra unit tests to validate edge cases (overflow in `Fixed`, Materia inventory bounds, etc.).

---

Designed with ☕️ by fkarika
