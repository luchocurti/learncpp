# README.md

**Chapter 5 - Constants and Strings**

+ 5.01 - Constant variables (named constants)
+ 5.02 - Literals
+ 5.03 - Numeral systems (decimal, binary, hexadecimal, and octal)
+ 5.04 - The as-if rule and compile-time optimization
+ 5.05 - Constant expressions
+ 5.06 - Constexpr variables
+ 5.07 - Introduction to std::string
+ 5.08 - Introduction to std::string_view
+ 5.09 - std::string_view (part 2)
+ 5.10 - Chapter 5 summary and quiz

---

# File tree

```
project-template/
├── include/
│   └── add.hpp
├── src/
│   ├── main.cpp
│   └── add.cpp
├── tests/
│   └── test_main.cpp
├── .gitignore
├── Makefile
└── README.md
```

---

# Prerequisites (Debian / Ubuntu)

```sh
sudo apt update
sudo apt install build-essential make cmake gdb valgrind clang git -y
```

---

# Toolchain

## Build modes --- debug vs release

The Makefile supports two build modes: **debug** (the default) and
**release**.

-   **debug** (default)
    -   Flags: `-std=c++20 -Wall -Wextra -Wpedantic -DDEBUG -g -O0`
    -   Includes debug symbols (`-g`) and disables optimizations (`-O0`)
        to make stepping through the code with a debugger easy.
    -   Recommended for development, testing, sanitizers and readable
        backtraces.
-   **release**
    -   Flags: `-std=c++20 -Wall -Wextra -Wpedantic -pedantic-errors -Weffc++ -Wsign-conversion -O3 -DNDEBUG`
    -   Enables optimizations (`-O3`) and defines `NDEBUG` (which
        disables `assert()`).
    -   Produces a faster binary but without debug symbols.

### How to choose a mode

Shortcuts:

``` sh
# Default (debug)
make  # same as: make debug

# Release (optimized)
make release
```

Or set the MODE variable explicitly:

``` sh
make MODE=debug
make MODE=release
```

You can also change the compiler or tweak flags on the command line:

``` sh
# Use clang++ for a single invocation
CXX=clang++ make release

# Override optimization flags directly
CXXFLAGS="-O2 -march=native -DNDEBUG" make MODE=release
```

Notes:
- `make release` runs `clean` first, then builds in release mode.
- Other targets (like `test`) respect the selected mode: `make MODE=release test`
- Prefer debug mode when using sanitizers or debuggers.

------------------------------------------------------------------------

## Compile with debug symbols and warnings

```sh
# Default build (debug symbols, -O0)
make
```

This produces the executable `bin/app`.

## Run

```sh
# Run with no arguments
./bin/app
# Prints: Hello, world!
```

## Run automated tests

```sh
make test
```

This builds and runs `bin/test_main` (exits with a non-zero status if tests fail).

## Build & run with sanitizers (AddressSanitizer + UndefinedBehavior)

```sh
make clean
make sanitize
# ./bin/app will be run automatically by the `sanitize` target
```

To build with sanitizers but not run automatically:

```sh
CXXFLAGS='-std=c++20 -Wall -Wextra -Wpedantic -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer' make all
./bin/app
```

Notes:
- The `sanitize` target appends sanitizer flags to `CXXFLAGS`.
- Sanitizers are most useful in debug mode.

## Debug with gdb

```sh
gdb ./bin/app
# Inside gdb: break main; run; step; next; print <variable>; bt
```

## Memory check with valgrind

```sh
valgrind --leak-check=full ./bin/app
```

(valgrind works best with debug builds.)

## Use clang++ instead of g++

```sh
# Temporary for a single make invocation
CXX=clang++ make clean all
```

## Clean

```sh
make clean
```
