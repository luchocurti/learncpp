# README.md

C++ project template.
Minimal starter for C++ projects (Makefile, unit tests, sanitizers).

Note: These files are set up to work with terminal toolchains.

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
│   └── test_add.cpp
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
    -   Flags: `-std=c++20 -Wall -Wextra -Wpedantic -g -O0`
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
# Run with two integers
./bin/app 2 3
# Prints: add(2, 3) = 5
```

## Run automated tests

```sh
make test
```

This builds and runs `bin/test_add` (exits with a non-zero status if tests fail).

## Build & run with sanitizers (AddressSanitizer + UndefinedBehavior)

```sh
make clean
make sanitize
# ./bin/app will be run automatically by the `sanitize` target
```

To build with sanitizers but not run automatically:

```sh
CXXFLAGS='-std=c++20 -Wall -Wextra -Wpedantic -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer' make all
./bin/app 2 3
```

Notes:
- The `sanitize` target appends sanitizer flags to `CXXFLAGS`.
- Sanitizers are most useful in debug mode.

## Debug with gdb

```sh
gdb --args ./bin/app 2 3
# Inside gdb: break main; run; next; print <variable>; bt
```

## Memory check with valgrind

```sh
valgrind --leak-check=full ./bin/app 2 3
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
