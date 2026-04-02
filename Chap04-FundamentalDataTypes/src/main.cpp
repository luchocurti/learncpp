/**
 *  main.cpp
 *  - Calling a small library function (add).
 *  - Print the size of all basic data types.
 *
 * Usage:
 *  ./bin/app
 *
 * Status codes:
 *  0 - EXIT_SUCCESS
 *  1 - EXIT_FAILURE
 */

/* Preprocessor Directives */
#include "add.hpp" // add()
#include <climits> // CHAR_BIT
#include <cstddef> // std::size_t, std::ptrdiff_t, std::nullptr_t, std::max_align_t
#include <cstdint>  // fixed-width integer types
#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE
#include <iomanip>  // std::setw, std::setprecision
#include <iostream> // std::cout, std::cin, std::cerr
#include <limits>   // std::numeric_limits

/* Templates */
template <typename T> void print_type(const char *name) {
  // columns: type name (left), size (bytes)
  std::cout << std::left << std::setw(46) << name << std::right << std::setw(3)
            << sizeof(T) << " byte";
  if (sizeof(T) > 1) {
    std::cout << "s";
  }
  std::cout << '\n';
}

/* Functions */

/* Main Function */
int main() {
#ifdef DEBUG
  std::cerr << "Debug: Starting main()\n";
#endif

  std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

  std::cout << "\nA byte is " << CHAR_BIT << " bits\n\n";

  // Print bool as 'true' or 'false' rather than '1' or '0'
  // Use std::noboolalpha to turn it back off
  std::cout << std::boolalpha;

  std::cout << std::left; // Left-justify the names column

  std::cout << "Fundamental integer and character types\n";
  print_type<bool>("bool");
  print_type<char>("char");
  print_type<signed char>("signed char");
  print_type<unsigned char>("unsigned char");
  print_type<wchar_t>("wchar_t"); // It should be avoided in almost all cases
#if __cplusplus >= 202002L
  print_type<char8_t>("char8_t");
#endif
#if __cplusplus >= 201103L
  print_type<char16_t>("char16_t");
  print_type<char32_t>("char32_t");
#endif

  print_type<short>("short");
  print_type<unsigned short>("unsigned short");
  print_type<int>("int");
  print_type<unsigned int>("unsigned int");
  print_type<long>("long");
  print_type<unsigned long>("unsigned long");
  print_type<long long>("long long");
  print_type<unsigned long long>("unsigned long long");

  std::cout << "\nFloating point\n";
  print_type<float>("float");
  print_type<double>("double");
  print_type<long double>("long double");

  std::cout << "\nSizes / ptrs / other standard types\n";
  print_type<std::size_t>("std::size_t");
  print_type<std::ptrdiff_t>("std::ptrdiff_t");
  print_type<std::nullptr_t>("std::nullptr_t");
  print_type<std::max_align_t>("std::max_align_t");

  std::cout << "\nPointer types (commonly the same size)\n";
  print_type<void *>("void*");
  print_type<char *>("char*");
  print_type<int *>("int*");
  print_type<double *>("double*");

  std::cout << "\nFunction pointer type\n";
  print_type<void (*)()>("void (*)()");

  std::cout << "\nMember pointer types\n";
  // Require a class
  struct Dummy {
    int member;
    void foo() {}
  };
  print_type<int Dummy::*>("int Dummy::* (ptr to data member)");
  print_type<void (Dummy::*)()>("void (Dummy::*)() (ptr to member function)");

  std::cout << "\nFixed-width integer types\n";
#ifdef INT8_MAX
  print_type<int8_t>("int8_t");
  print_type<uint8_t>("uint8_t");
#endif
#ifdef INT16_MAX
  print_type<int16_t>("int16_t");
  print_type<uint16_t>("uint16_t");
#endif
#ifdef INT32_MAX
  print_type<int32_t>("int32_t");
  print_type<uint32_t>("uint32_t");
#endif
#ifdef INT64_MAX
  print_type<int64_t>("int64_t");
  print_type<uint64_t>("uint64_t");
#endif
#ifdef INTPTR_MAX
  print_type<intptr_t>("intptr_t");
#endif
#ifdef UINTPTR_MAX
  print_type<uintptr_t>("uintptr_t");
#endif

  std::cout << "\nThe \"fast\" integer types with a width of at least n bits\n";
#ifdef INT_FAST8_MAX
  print_type<int_fast8_t>("int_fast8_t");
  print_type<int_fast16_t>("int_fast16_t");
  print_type<int_fast32_t>("int_fast32_t");
  print_type<int_fast64_t>("int_fast64_t");
  print_type<uint_fast8_t>("uint_fast8_t");
  print_type<uint_fast16_t>("uint_fast16_t");
  print_type<uint_fast32_t>("uint_fast32_t");
  print_type<uint_fast64_t>("uint_fast64_t");
#endif

  std::cout << "\nThe \"least\" (smallest) integer types of at least n bits\n";
#ifdef INT_LEAST8_MAX
  print_type<int_least8_t>("int_least8_t");
  print_type<int_least16_t>("int_least16_t");
  print_type<int_least32_t>("int_least32_t");
  print_type<int_least64_t>("int_least64_t");
  print_type<uint_least8_t>("uint_least8_t");
  print_type<uint_least16_t>("uint_least16_t");
  print_type<uint_least32_t>("uint_least32_t");
  print_type<uint_least64_t>("uint_least64_t");
#endif

  std::cout << "\nBest practice: Avoid the fast and least integral types "
               "because they may exhibit different behaviors on architectures "
               "where they resolve to different sizes.\n\n";

  char ch{97}; // 97 is ASCII code for 'a'
  // print value of variable ch as an int
  std::cout << "\'" << ch << "\' has value " << static_cast<int>(ch) << '\n';

  return EXIT_SUCCESS;
}
