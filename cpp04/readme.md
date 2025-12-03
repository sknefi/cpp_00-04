# CPP04 — Polymorphism, Abstract Bases, Interfaces

Complete theory recap for dynamic dispatch, abstraction, and interface-driven design with Materia.

## Polymorphism & virtual dispatch
- Mark behavior `virtual` in the base so calls through base pointers/references pick the derived override at runtime.
- Always give polymorphic classes a `virtual` destructor; deleting through a base pointer without it is UB and can leak.
- `WrongAnimal` intentionally lacks `virtual` to show the failure case (base method called instead of derived).

## Abstract classes & pure virtual functions
- A pure virtual function (`virtual void f() const = 0;`) makes the class abstract: cannot instantiate, but can hold shared data and non-pure methods.
- Derived classes must implement all pure virtual functions or remain abstract.
- `AAnimal` provides `getType` plus a pure virtual `makeSound`, forcing concrete animals to supply behavior.

## Rule of Three and deep copies
- Classes owning dynamic memory (e.g., `Brain*` in Cat/Dog, Materia pointers in Character) must implement copy ctor, copy assignment, and destructor.
- Copy operations should allocate new resources and duplicate contents to avoid shared ownership bugs.
- Destructor must release owned memory to prevent leaks when deleting via base pointers.

```cpp
class Dog : public AAnimal {
public:
    Dog() : _brain(new Brain()) { _type = "Dog"; }
    Dog(Dog const& other) : AAnimal(other), _brain(new Brain(*other._brain)) {}
    Dog& operator=(Dog const& other) {
        if (this != &other) { _type = other._type; *_brain = *other._brain; }
        return *this;
    }
    virtual ~Dog() { delete _brain; }
    virtual void makeSound() const { std::cout << "Woof!" << std::endl; }
private:
    Brain* _brain;
};
```

## Interface-style classes
- `ICharacter` and `IMateriaSource` are pure-virtual-only with virtual destructors, mirroring interfaces from other languages.
- They define required behaviors (equip/unequip/use, learn/create) without owning data; concrete classes implement storage and rules.

## Prototype/clone pattern (Materia)
- `AMateria` exposes `clone()` which returns a new instance of the same dynamic type.
- `MateriaSource` stores learned prototypes, and `createMateria(type)` scans them, cloning the first matching type so callers own a fresh object.
- This avoids `if/else` type factories and keeps creation open for new Materia types.

## Ownership during equip/unequip
- Equipping transfers ownership into the character’s slot array; if full, decide whether to drop or delete.
- Unequipping should not delete immediately—store on a “floor” to avoid dangling pointers while still preventing leaks.
- `use(idx, target)` must validate indices and `NULL` slots before calling the Materia’s `use`.

## Upcasting and downcasting
- Upcast derived objects to base references to use a common interface (`AAnimal& a = dog;`).
- Avoid downcasting unless necessary; design virtual interfaces to make downcasts rare.

## Re-run quickly
Each exercise builds `a.out`:
```bash
make -C ex00 && ./ex00/a.out
make -C ex02 && ./ex02/a.out
make -C ex03 && ./ex03/a.out
```
