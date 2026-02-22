/**
 *  main.cpp
 *  - Print the C++ language standard the compiler is currently using
 *
 * Usage:
 *  ./bin/app
 *
 * Exit codes:
 *  0 - success
 *  1 - error
 */

/* Preprocessor Directives */
#include <iostream>

const int numStandards = 7;
/* The C++26 stdCode is a placeholder since the exact code won't be determined
 * until the standard is finalized */
const long stdCode[numStandards] = {199711L, 201103L, 201402L, 201703L,
                                    202002L, 202302L, 202612L};
const char *stdName[numStandards] = {"Pre-C++11", "C++11", "C++14", "C++17",
                                     "C++20",     "C++23", "C++26"};

long getCPPStandard() {
  /* __cplusplus is the intended way to query the language standard code (as
   * defined by the language standards) */
  return __cplusplus;
}

/* Main Function */
int main() {
  long standard = getCPPStandard();

  if (standard == -1) {
    std::cout << "Error: Unable to determine the language standard."
              << std::endl;
    return 1;
  }

  for (int i = 0; i < numStandards; ++i) {
    /* If the reported version is one of the finalized standard codes then we
     * know exactly what version the compiler is running */
    if (standard == stdCode[i]) {
      std::cout << "The compiler is using " << stdName[i]
                << " (language standard code " << standard << "L)" << std::endl;
      break;
    }

    /* If the reported version is between two finalized standard codes, this
     * must be a preview / experimental support for the next upcoming version.
     */
    if (standard < stdCode[i]) {
      std::cout << "The compiler is using a preview/pre-release of "
                << stdName[i] << " (language standard code " << standard << "L)"
                << std::endl;
      break;
    }
  }

  return 0;
}