# README.md

C++ project template.

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
sudo apt install build-essential make gdb valgrind cmake clang -y
```

---

# Toolchain

## Compile with debug symbols and warnings

```sh
# Default build (debug symbols, -O0)
make
```

This produces `bin/app`.

## Run

```sh
# Run with two integers
./bin/app 2 3
# Prints: add(2, 3) = 5
```

## Run Automate tests

```sh
make test
```

This builds and runs `bin/test_add` (it exits non-zero on failure).

## Build & run with sanitizers (AddressSanitizer + UndefinedBehavior)

```sh
make clean
make sanitize
# ./bin/app will be run automatically by the `sanitize` target
```

Or to run a sanitizer build but not run automatically:

```sh
CXXFLAGS='-std=c++20 -Wall -Wextra -Wpedantic -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer' make all
./bin/app 2 3
```

## Debug with gdb

```sh
gdb --args ./bin/app 2 3
# Inside gdb: break main, run, next, print var, backtrace
```

## Memory check with valgrind

```sh
valgrind --leak-check=full ./bin/app 2 3
```

## Use clang++ instead of g++

```sh
# Temporary for a single make invocation
CXX=clang++ make clean all
```

## Clean

```sh
make clean
```
