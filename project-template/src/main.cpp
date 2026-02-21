#include "add.hpp"
#include <iostream>
#include <string>

// main.cpp
// Minimal command-line program demonstrating:
//  - basic argument parsing
//  - conversion from string to integer
//  - calling a small library function (add)
//  - clear exit codes for different failure modes
//
// Usage:
//   ./bin/app <int a> <int b>
//
// Exit codes:
//   0 - success
//   1 - incorrect usage (wrong number of arguments)
//   2 - invalid integer conversion

int main(int argc, char **argv) {
  if (argc == 3) {
    try {
      // Convert the two command-line arguments to integers.
      // std::stoi throws std::invalid_argument or std::out_of_range if
      // conversion fails; we catch std::exception and return a non-zero,
      // documented exit code.
      int a = std::stoi(argv[1]);
      int b = std::stoi(argv[2]);
      std::cout << "add(" << a << ", " << b << ") = " << add(a, b) << std::endl;
      return 0;
    } catch (const std::exception &e) {
      std::cerr << "Invalid integer arguments: " << e.what() << std::endl;
      return 2;
    }
  }
  // If the user did not provide the required arguments, print a short usage
  // message. This makes the program easy to use in manual testing from the
  // terminal and from automated scripts.
  std::cout << "Usage: " << argv[0] << " <int a> <int b>" << std::endl;
  return 1;
}
