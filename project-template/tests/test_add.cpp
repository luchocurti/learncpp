#include "add.hpp"
#include <cstdlib>
#include <iostream>

// test_add.cpp
// Tiny, dependency-free test executable. Tests are intentionally simple to run
// from the terminal without installing an external unit-test framework.
//
// Conventions used here:
//  - A failing test prints an explanatory message to stderr and exits the
//  process with a non-zero status code (1).
//  - A passing test prints a short "OK" message. If all tests pass, the program
//  exits with status 0.

static void expect(int got, int want, const char *desc) {
  if (got != want) {
    std::cerr << "FAIL: " << desc << " got=" << got << " want=" << want
              << std::endl;
    std::exit(1);
  } else {
    std::cout << "OK: " << desc << std::endl;
  }
}

int main() {
  // Add test cases covering normal, boundary, and negative inputs.
  expect(add(1, 2), 3, "add(1,2)");
  expect(add(-1, 1), 0, "add(-1,1)");
  expect(add(1000, 234), 1234, "add(1000,234)");
  std::cout << "All tests passed" << std::endl;
  return 0;
}
