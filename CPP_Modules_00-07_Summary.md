# 42 School — C++ Modules (CPP00 → CPP07)

A progression map of the C++ piscine/cursus modules, from "C with classes" up to
generic programming with templates. Each module builds directly on the
canonical-form and memory-management habits from the one before it.

---

## CPP00 — Namespaces, Classes, Member Functions, Basic OOP

**Goal:** Transition from C to C++. Learn classes, encapsulation, `std::string`,
`std::cout`/`std::cin`, and the general shape of a C++ file (`.hpp`/`.cpp` split).

**Key concepts**
- `class` vs `struct`, access specifiers (`private`/`public`)
- Member functions, member initialization
- `static` members/methods
- `const` correctness
- No raw C arrays of structs — use classes instead

**Exercises**
| Ex | Name | Focus |
|----|------|-------|
| 00 | Megaphone | argv handling, string manipulation (uppercase output) |
| 01 | PhoneBook | `Contact` class + `PhoneBook` class, static array of 8 contacts, add/search by index, private members with public interface |

---

## CPP01 — Memory Allocation, References, Pointers to Members

**Goal:** Understand stack vs heap allocation, and the difference between
pointers and references.

**Key concepts**
- `new` / `delete`, `new[]` / `delete[]`
- Pointers vs references (a reference **must** be initialized, can't be reseated, no null reference)
- File I/O (`ifstream`/`ofstream`)
- Function pointers
- `switch` statements

**Exercises**
| Ex | Name | Focus |
|----|------|-------|
| 00 | Braaaiiiins | Heap (`newZombie`) vs stack (`randomZombie`) object creation |
| 01 | Moar brainz | Array of heap objects (`zombieHorde`), `new[]` |
| 02 | HI THIS IS BRAIN | Pointer vs reference to a string, print via both |
| 03 | Unnecessary violence | `HumanA` (holds a reference to `Weapon`) vs `HumanB` (holds a pointer) |
| 04 | Sed is for losers | Read a file, replace all occurrences of a string, write to new file |
| 05 | Harl 2.0 | Array of member function pointers to simulate a `switch` |
| 06 | Harl filter | Extend 05 — filter by complaint severity level (DEBUG/INFO/WARNING/ERROR) |

---

## CPP02 — Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Form

**Goal:** Learn the **Orthodox Canonical Form** (OCF) — the standard shape
every "value type" class should follow — and operator overloading.

**Orthodox Canonical Form = must implement:**
1. Default constructor
2. Copy constructor
3. Copy assignment operator (`operator=`)
4. Destructor

**Key concepts**
- Fixed-point number representation (int storing a value shifted by N fractional bits)
- Overloading arithmetic (`+ - * /`), comparison (`< > == !=`), increment/decrement (`++x` vs `x++`), stream insertion (`<<`)
- `explicit` constructors avoiding accidental implicit conversions

**Exercises**
| Ex | Name | Focus |
|----|------|-------|
| 00 | My Money Is No Object | `Fixed` class basics + OCF |
| 01 | Towards a more useful fixed-point class | Constructors from `int`/`float`, `toInt()`/`toFloat()`, `<<` overload |
| 02 | Now it's version 2 | Full operator overloading: comparisons, arithmetic, `++`/`--` (prefix & postfix), static `min`/`max` |
| 03 | BSP | Point-in-triangle test using `Fixed`, applying the whole class practically |

---

## CPP03 — Inheritance

**Goal:** Basic single and multiple inheritance, constructor/destructor call
order, and a first brush with the diamond problem.

**Key concepts**
- `class Derived : public Base`
- Constructor call order: Base → Derived; Destructor: Derived → Base
- Function overriding (still **non-virtual** at this stage — that's CPP04)
- Multiple inheritance and ambiguity

**Exercises**
| Ex | Name | Focus |
|----|------|-------|
| 00 | Aaaaa! | `ClapTrap` base class |
| 01 | Serena, my love | `ScavTrap : public ClapTrap` |
| 02 | Repetitive work | `FragTrap : public ClapTrap` |
| 03 | Now it's weird | `NinjaTrap : public ScavTrap, public FragTrap` — diamond inheritance, name ambiguity |

---

## CPP04 — Subtype Polymorphism, Abstract Classes, Interfaces

**Goal:** True runtime polymorphism via `virtual`, abstract base classes, and
interfaces — plus deep vs shallow copy.

**Key concepts**
- `virtual` functions → dynamic dispatch (vtable)
- Virtual destructors (mandatory once you `delete` via a base pointer)
- Pure virtual functions (`= 0`) → abstract classes (can't instantiate)
- Interfaces (all pure virtual, no data)
- Deep copy when a class owns a pointer member

**Exercises**
| Ex | Name | Focus |
|----|------|-------|
| 00 | Polymorphism | `Animal`/`Dog`/`Cat` with `virtual makeSound()`; contrast with a non-virtual `WrongAnimal` |
| 01 | I don't want to set the world on fire | Add a `Brain*` member — deep copy in copy constructor/assignment |
| 02 | Abstract class | `Animal` becomes abstract (`makeSound() = 0`) |
| 03 | Interface & recap | `ICharacter` interface, `AMateria` abstract class, `MateriaSource`, `clone()` pattern, full recap of the module |

---

## CPP05 — Repetition and Exceptions

**Goal:** Exception handling — throwing, catching, custom exception classes,
and RAII-adjacent error safety.

**Key concepts**
- `try` / `catch` / `throw`
- Custom exceptions inheriting `std::exception`, overriding `what()`
- Exception hierarchies and `catch` order (most-derived first)
- Nested/abstract class design combined with exceptions

**Exercises**
| Ex | Name | Focus |
|----|------|-------|
| 00 | Everybody Poops | `Bureaucrat` class with a grade (1–150), throws `GradeTooHighException` / `GradeTooLowException` |
| 01 | Form up, maggots! | `Form` class — a `Bureaucrat` can `sign()` a form if their grade qualifies |
| 02 | No, I need form! | `AForm` abstract base, concrete forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`), `execute()`, `Intern` factory-style class that builds a form by name |

---

## CPP06 — C++ Casts

**Goal:** Understand and correctly choose between the four C++-style casts,
replacing C-style casts entirely.

**Key concepts**
- `static_cast` — well-defined conversions known at compile time
- `dynamic_cast` — safe downcasting across polymorphic types (needs `virtual`), returns `nullptr`/throws on failure
- `reinterpret_cast` — reinterpret raw bit patterns (pointer ↔ integer)
- `const_cast` — add/remove `const` (rarely legitimate)

**Exercises**
| Ex | Name | Focus |
|----|------|-------|
| 00 | Convert I/O | `ScalarConverter` — convert a literal string to `char`/`int`/`float`/`double`, handling pseudo-literals (`nan`, `inf`, `-inf`) and overflow |
| 01 | Serialization | Convert a pointer to `uintptr_t` and back using `reinterpret_cast` |
| 02 | Identify real type | Use `dynamic_cast` to identify the real derived type of a `Base*`/`Base&` at runtime |

---

## CPP07 — Templates ← *(you are here)*

**Goal:** Generic programming — write code once that works across types,
without duplicating logic or relying on inheritance/virtual dispatch.

**Key concepts**
- Function templates: `template <typename T> T foo(T a, T b)`
- Type deduction from arguments
- Template functions taking function pointers, e.g. `void (*)(T&)`
- Class templates: `template <typename T> class Array { ... }`
- Combining templates with the canonical form + exception safety (from CPP02/CPP05)

**Exercises**
| Ex | Name | Focus |
|----|------|-------|
| 00 | Introduction to templates | Generic `swap`, `min`, `max` functions |
| 01 | Iter | Generic `iter()` — apply a function to every element of an array, templated over element type *(this is the file you posted)* |
| 02 | Array | `Array<T>` class template — dynamic array, bounds-checked access (throws on out-of-range), full OCF with deep copy |

---

## The through-line

Notice how each module is really reinforcing the same few pillars, adding one
new tool each time:

1. **CPP00–01**: memory & basic structure (stack/heap, pointers/references)
2. **CPP02**: the Orthodox Canonical Form — the backbone of *every* class you'll write from here on
3. **CPP03–04**: inheritance → real polymorphism (virtual)
4. **CPP05**: making your classes fail safely (exceptions)
5. **CPP06**: casting correctly between related/unrelated types
6. **CPP07**: templates — genericizing everything you've learned so it's not tied to one type at all

By CPP07, you're expected to combine *all* of the above: your `Array<T>`
in ex02, for instance, should still respect the canonical form from CPP02 and
throw exceptions properly like CPP05 taught you — just now generically, for
any `T`.

What typically comes next (CPP08–09) pushes further into the STL
(containers, iterators, algorithms) and a final capstone exercise using
Reverse Polish Notation, but that's beyond where you are now.
