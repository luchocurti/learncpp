/**
 *  main.cpp
 *  - Example program that uses (and demonstrates) all Chapter 1 concepts.
 *  - Single, self-contained program that demonstrates: statements, comments,
 * variables / objects, several initialization forms, input/output with
 * validation, literals, operators, expressions, safe handling of potential
 * uninitialized variables, use of '\n' vs std::endl, and reasonable formatting
 * / whitespace.
 *
 * Usage:
 *  ./bin/app
 *
 * Exit codes:
 *  0 - success
 *  1 - error
 */

/* Preprocessor Directives */
#include <iostream> // std::cout, std::cin, std::cerr

/* Main Function */
int main() {
  // --- 1) Statements, function, and main() ---
  // This program asks for two integers and demonstrates initialization,
  // assignment, expressions, and console I/O with validation.

  // --- 2) Variable definitions + initialization examples ---
  int a{};     // Value-initialized (zero-initialized for int)
  int b = 0;   // Copy-initialization
  int c(3);    // Direct-initialization (same as int c = 3; for built-ins)
  int d{4};    // List (brace) initialization — preferred in modern C++
  int e = {5}; // Copy-list-initialization
  // int uninitialized; // BAD: would be uninitialized (do not read it)

  // Print literal and explanation
  std::cout << "This program adds and subtracts two integers.\n";

  // --- 3) Input with validation (use std::cin carefully) ---
  std::cout << "Enter first integer: ";
  if (!(std::cin >> a)) {
    // Input failed — handle gracefully
    std::cerr << "Invalid input for first integer.\n";
    return 1; // non-zero return signals error to OS
  }

  std::cout << "Enter second integer: ";
  if (!(std::cin >> b)) {
    std::cerr << "Invalid input for second integer.\n";
    return 1;
  }

  // --- 4) Expressions and operators ---
  // Using literals, variables, binary operators; these are expressions.
  int sum = a + b; // Assignment after expression evaluation
  int diff = a - b;
  int prod = a * b;
  double quotient = 0.0; // Initialize to a safe value

  // Safe division check (avoid divide-by-zero)
  if (b != 0) {
    quotient = static_cast<double>(a) / b; // expression + cast
  } else {
    std::cout << "Cannot divide by zero; quotient left as " << quotient << '\n';
  }

  // --- 5) Output results; prefer '\n' (no flush) unless flush required ---
  std::cout << a << " + " << b << " is " << sum << ".\n";
  std::cout << a << " - " << b << " is " << diff << ".\n";
  std::cout << a << " * " << b << " is " << prod << ".\n";
  if (b != 0) {
    std::cout << a << " / " << b << " is " << quotient << ".\n";
  } else {
    std::cout << a << " / " << b << " is not valid.\n";
  }

  // --- 6) Demonstrate assignment vs initialization ---
  int x{}; // Initialization (already done above style)
  x = 42;  // Assignment — gives an already-existing variable a new value
  std::cout << "Example: x was initialized to 0 and then assigned " << x
            << "\n";

  // --- 7) Final statement and return value ---
  // return 0 indicates successful execution;  non-zero indicates error.
  return 0;
}
