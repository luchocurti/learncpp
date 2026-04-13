/**
 *  main.cpp
 *  - Calling a small library function (add).
 *  - Testing operators.
 *
 * Usage:
 *  ./bin/app
 *
 * Status codes:
 *  0 - EXIT_SUCCESS
 *  1 - EXIT_FAILURE
 */

/* Preprocessor Directives */
#include "add.hpp"     // add()
#include <bitset>      // for std::bitset
#include <cstdint>     // fixed-width integer types
#include <cstdlib>     // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream>    // std::cout, std::cin, std::cerr
#include <string>      // std::string, std::getline
#include <string_view> // C++17

/* Templates */

/* Functions */
std::string_view getQuantityPhrase(int num) {
  if (num < 0)
    return "negative";
  if (num == 0)
    return "no";
  if (num == 1)
    return "a single";
  if (num == 2)
    return "a couple of";
  if (num == 3)
    return "a few";
  return "many";
}

std::string_view getApplesPluralized(int num) {
  return (num == 1) ? "apple" : "apples";
}

/* Main Function */
int main() {
#ifdef DEBUG
  std::cerr << "Debug: Starting main()\n";
#endif

  std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n\n";

  int x{5};
  int y{++x};
  std::cout << "x{5} = " << x << " - y{++x} = " << y << '\n';

  x = 5;
  y = x++;
  std::cout << "x{5} = " << x << " - y{x++} = " << y << '\n';

  constexpr int maryApples{3};
  std::cout << "\nMary has " << getQuantityPhrase(maryApples) << ' '
            << getApplesPluralized(maryApples) << ".\n";

  std::cout << "How many apples do you have? ";
  int numApples{};
  std::cin >> numApples;

  std::cout << "You have " << getQuantityPhrase(numApples) << ' '
            << getApplesPluralized(numApples) << ".\n";

  return EXIT_SUCCESS;
}
