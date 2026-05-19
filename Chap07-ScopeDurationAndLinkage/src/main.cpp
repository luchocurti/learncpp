/**
 *  main.cpp
 *  - Calling a small library function (add).
 *  - Test static local variables.
 *
 * Usage:
 *  ./bin/app
 *
 * Status codes:
 *  0 - EXIT_SUCCESS
 *  1 - EXIT_FAILURE
 */

/* Preprocessor Directives */
#include "add.hpp"     // BasicMath::add()
#include <bitset>      // std::bitset
#include <cstdint>     // fixed-width integer types
#include <cstdlib>     // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream>    // std::cout, std::cin, std::cerr
#include <string>      // std::string, std::getline
#include <string_view> // C++17 std::string_view

/* Templates */

/* Functions */
int generateID() {
  static int s_itemID{0};
  return s_itemID++; // makes copy of s_itemID, increments the real s_itemID,
                     // then returns the value in the copy
}

/* Main Function */
int main() {
#ifdef DEBUG
  std::cerr << "Debug: Starting main()\n";
#endif

  std::cout << "The sum of 3 and 4 is: " << BasicMath::add(3, 4) << "\n\n";

  std::cout << "Generating unique IDs:\n";
  for (int i = 0; i < 5; ++i) {
    std::cout << " - ID " << i + 1 << " = " << generateID() << "\n";
  }

  return EXIT_SUCCESS;
}
