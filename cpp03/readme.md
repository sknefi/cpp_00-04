# CPP03 — Inheritance, Overriding, Diamond Problem

Detailed notes on stacking behavior through inheritance and resolving shared bases.

## Inheritance fundamentals
- Base class (`ClapTrap`) holds common data: name, hit points, energy, attack damage.
- Derived classes reuse and extend behavior instead of copying code; constructors call base constructors in init lists.
- Use `protected` for members that derived classes must adjust, but keep public API small.

## Overriding vs hiding
- Mark functions `virtual` in the base so derived overrides are chosen at runtime.
- If signatures differ (missing `const`, different params), the function is hidden instead of overridden—calls on base references will not hit the derived version.
- Override `attack` in derived traps to customize messages/stats while keeping base resource checks if desired.

## Virtual destructors
- When a class is intended for polymorphic use, the destructor must be `virtual`; otherwise deleting via a base pointer leaks derived resources or is UB.

## Resource and action guards
- Clamp actions when `_hp == 0` or `_energy == 0`; refuse to attack/repair if dead or exhausted.
- Centralize these checks in the base to keep derived classes consistent.

## Virtual inheritance and the diamond
- `ScavTrap` and `FragTrap` both virtually inherit `ClapTrap` to ensure a single shared base inside `DiamondTrap`.
- The most-derived class (`DiamondTrap`) initializes the virtual base explicitly: `ClapTrap(name + "_clap_name")`.
- Resolves duplicated members (one set of hp/energy/ad) and avoids ambiguous base paths.

```cpp
class ScavTrap : virtual public ClapTrap { /* ... */ };
class FragTrap : virtual public ClapTrap { /* ... */ };

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap(std::string const& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
        _hp = FragTrap::_hp;      // from FragTrap defaults
        _energy = ScavTrap::_energy;
        _ad = FragTrap::_ad;
    }
    void attack(std::string const& target) { ScavTrap::attack(target); } // pick one path
    void whoAmI() {
        std::cout << "DiamondTrap: " << _name
                  << " | ClapTrap: " << ClapTrap::_name << std::endl;
    }
private:
    std::string _name;
};
```

## Constructor/destructor order
- Virtual bases construct first, then non-virtual bases, then members; destruction reverses the order.
- Logging from constructors/destructors in exercises makes this order visible.

## Re-run quickly
Each Makefile emits `a.out` in its folder:
```bash
make -C ex00 && ./ex00/a.out
make -C ex02 && ./ex02/a.out
make -C ex03 && ./ex03/a.out
```
