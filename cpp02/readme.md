# CPP02 — Fixed-Point Numbers & Operator Overloading

Comprehensive notes on building a value type that behaves like a primitive: fixed-point math, conversions, overloading, and geometric testing.

## Fixed-point representation
- Store a scaled integer: `raw = roundf(real * 2^fractional_bits)`. Here `fractional_bits = 8`.
- Conversions:
  - `toFloat`: `raw / (1 << fractional_bits)`.
  - `toInt`: `raw >> fractional_bits`.
- Keep the fractional bit count `static const` and initialize it in the source file.

## Canonical form and const-correctness
- Provide default ctor, copy ctor, copy assignment, and destructor even if they only log—future changes will be safer.
- Mark conversion helpers `const` because they do not mutate the object; allow use on temporaries and const references.
- Avoid exposing mutable raw bits; if you must, expose them through accessors.

## Operator overloading rules
- Comparisons (`==`, `!=`, `<`, `>`, `<=`, `>=`) can compare `_rawBits` directly because scaling is uniform.
- Arithmetic (`+ - * /`) can either operate in float space for simplicity or in raw space with careful scaling; guard division by zero.
- Prefix vs postfix:
  - Prefix increments the object then returns a reference to it.
  - Postfix stores a copy, increments the object, then returns the old copy.
- `operator<<` should be a non-member (often friend) to allow `std::cout << fixed`.

```cpp
Fixed::Fixed(float f) : _rawBits(static_cast<int>(roundf(f * (1 << _fracBits)))) {}

Fixed Fixed::operator/(Fixed const& rhs) const {
    if (rhs.getRawBits() == 0) throw std::runtime_error("Division by zero");
    return Fixed(toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++() { ++_rawBits; return *this; }   // prefix
Fixed  Fixed::operator++(int) { Fixed tmp(*this); ++_rawBits; return tmp; } // postfix
```

## Immutability and value semantics
- `Point` uses `const Fixed` members so coordinates cannot change after construction, preventing accidental movement.
- Pass objects as `const T&` to avoid copies when reading; return by value when you intend to create new objects.

## Barycentric point-in-triangle test (bsp)
- Compute denominator once; if zero, triangle is degenerate.
- Barycentric weights:

```cpp
Fixed denom = (b.getY() - c.getY()) * (a.getX() - c.getX()) +
              (c.getX() - b.getX()) * (a.getY() - c.getY());
Fixed alpha = ((b.getY() - c.getY()) * (p.getX() - c.getX()) +
               (c.getX() - b.getX()) * (p.getY() - c.getY())) / denom;
Fixed beta  = ((c.getY() - a.getY()) * (p.getX() - c.getX()) +
               (a.getX() - c.getX()) * (p.getY() - c.getY())) / denom;
Fixed gamma = Fixed(1) - alpha - beta;
bool inside = (alpha > 0) && (beta > 0) && (gamma > 0);
```
- Using strict `>` excludes points on the edges; switch to `>=` to include them.

## Naming and stream helpers
- Keep a single `operator<<` overload to print `toFloat()` results, enabling natural logging and debugging.
- Ensure overloaded operators preserve intuitive meaning to avoid surprises for users of the class.

## Re-run quickly
Makefiles output `a.out` in each exercise folder:
```bash
make -C ex00 && ./ex00/a.out
make -C ex02 && ./ex02/a.out
make -C ex03 && ./ex03/a.out
```
