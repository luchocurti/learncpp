/**
 *  main.cpp
 *  - Calling a small library function (add).
 *  - Calculator: Run a mathematical operation over two numbers.
 *
 * Usage:
 *  ./bin/app
 *
 * Status codes:
 *  0 - EXIT_SUCCESS
 *  1 - EXIT_FAILURE
 */

/* Preprocessor Directives */
#include "add.hpp"  // add
#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream> // std::cout, std::cin, std::cerr

/* Functions */
int getUserInput() {
  int input{};

  std::cout << "Enter an integer: ";
  std::cin >> input;

  return input;
}

/* Main Function */
int main() {
  std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

  // Get first number from user
  int value1{getUserInput()};
  std::cout << "debug code: value1 = " << value1 << '\n';

  // Get mathematical operation from user
  // getMathematicalOperation();

  // Get second number from user
  int value2{getUserInput()};
  std::cout << "debug code: value2 = " << value2 << '\n';

  // Calculate result
  // calculateResult();

  // Print result
  // printResult();

  return EXIT_SUCCESS;
}
