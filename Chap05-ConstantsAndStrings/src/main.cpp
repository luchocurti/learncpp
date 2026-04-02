/**
 *  main.cpp
 *  - Calling a small library function (add).
 *  - Working with Constants and Strings.
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
// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) { std::cout << str << '\n'; }

/* Main Function */
int main() {
#ifdef DEBUG
  std::cerr << "Debug: Starting main()\n";
#endif

  std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n\n";

  std::cout << 5 << " - 5 (no suffix) is type int (by default)\n";
  std::cout << 5L << " - 5L is type long\n";
  std::cout << 5u << " - 5u is type unsigned int\n";

  std::cout << 5.0 << " - 5.0 (no suffix) is type double (by default)\n";
  std::cout << 5.0f << " - 5.0f is type float\n";

  float f{4.1f};
  double d{4.1};
  std::cout << f
            << " - use 'f' suffix so the literal is a float and matches "
               "variable type of float\n";
  std::cout << d
            << " - change variable to type double so it matches the literal "
               "type double\n";

  int dec{12};  // 12 is assumed to be a decimal number
  int hex{0xF}; // 0x before the number means this is hexadecimal
  std::bitset<8> bin{0b1100'0101}; // binary literal for binary 1100 0101
  std::cout << '\n';

  std::cout << "dec in dec = " << dec << '\n'; // decimal (default)
  std::cout << "dec in bin = "
            << std::bitset<8>{static_cast<std::bitset<8>>(dec)} << '\n';
  std::cout << "dec in hex = " << std::uppercase << std::hex << dec << '\n';
  std::cout << std::dec << std::nouppercase << '\n'; // return to decimal

  std::cout << "hex in dec = " << hex << '\n'; // decimal (default)
  std::cout << "hex in bin = "
            << std::bitset<8>{static_cast<std::bitset<8>>(hex)} << '\n';
  std::cout << "hex in hex = " << std::uppercase << std::hex << hex << '\n';
  std::cout << std::dec << std::nouppercase << '\n'; // return to decimal

  std::cout << "bin in dec = " << bin.to_ulong() << '\n'; // decimal (default)
  std::cout << "bin in bin = " << bin << '\n';
  std::cout << "bin in hex = " << std::uppercase << std::hex << bin.to_ulong()
            << '\n';
  std::cout << std::dec << std::nouppercase << '\n'; // return to decimal

  std::cout << "Pick 1 or 2: ";
  int choice{};
  std::cin >> choice;

  std::cout << "Enter full name: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);

  std::cout << "Hello " << name << ", you picked: " << choice << '\n';
  std::cout << '\"' << name << "\" has " << name.length() << " characters\n\n";

  std::string_view s1{"initialize with C-style string literal"};
  printSV(s1);

  std::string s{"initialize with std::string"};
  std::string_view s2{s};
  printSV(s2);

  std::cout << "(initialize with std::string_view)" << '\n';
  std::string_view s3{s2};
  printSV(s3);

  return EXIT_SUCCESS;
}
