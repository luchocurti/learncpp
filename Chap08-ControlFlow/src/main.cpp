/**
 *  main.cpp
 *  - Calling a small library function (add).
 *  - Introduction to random number generation.
 *
 * Usage:
 *  ./bin/app
 *
 * Status codes:
 *  0 - EXIT_SUCCESS
 *  1 - EXIT_FAILURE
 */

/* Preprocessor Directives */
#include "add.hpp"  // BasicMath::add()
#include "random.h" // Random::mt, Random::get(), Random::generate()
#include <array>    // std::array
#include <bitset>   // std::bitset
#include <chrono>   // for std::chrono
#include <cstddef>  // for std::size_t
#include <cstdint>  // fixed-width integer types
#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE, std::exit()
#include <iostream> // std::cout, std::cin, std::cerr
#include <random> // std::mt19937, std::uniform_int_distribution, std::random_device
#include <string>      // std::string, std::getline
#include <string_view> // C++17 std::string_view

/* Templates */

/* Functions */
void cleanup() {
  // Code here to do any kind of cleanup required
  std::cout << "cleanup!\n";
}

/* Main Function */
int main() {
#ifdef DEBUG
  std::cerr << "Debug: Starting main()\n";
#endif

  // print value std::chrono::steady_clock::now().time_since_epoch().count()
  std::cout << "std::chrono::steady_clock::now().time_since_epoch().count(): "
            << std::chrono::steady_clock::now().time_since_epoch().count()
            << '\n';

  // Register cleanup() to be called automatically when std::exit() is called
  std::atexit(cleanup); // Note: We use cleanup rather than cleanup() since
                        // we're not making a function call to cleanup()

  std::cout << "The sum of 1 and 2 is: " << BasicMath::add(1, 2) << "\n\n";

  // Instantiate a 32-bit Mersenne Twister random number generator
  std::mt19937 mt{};

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count) {
    std::cout << mt() << '\t'; // Generate a random number

    // If we've printed 5 numbers, start a new row
    if (count % 5 == 0)
      std::cout << '\n';
  }

  // Random number generator that generates uniform numbers between 1 and 6
  std::uniform_int_distribution die6{1, 6};
  std::array<unsigned int, 7> distribution{};

  // Print a bunch of random numbers
  std::cout << '\n';
  for (int count{1}; count <= 40; ++count) {
    int value = die6(mt);       // Generate a roll of the die here
    std::cout << value << '\t'; // Print the value of the die roll
    ++distribution[static_cast<size_t>(
        value)]; // Increment the count for this value

    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
      std::cout << '\n';
  }
  std::cout << '\n';
  std::cout << "Distribution of die rolls:\n";
  for (size_t i{1}; i < distribution.size(); ++i) {
    std::cout << i << ": " << distribution[i] << '\n';
  }

  // Seed our Mersenne Twister using steady_clock
  std::mt19937 mt_clock{static_cast<std::mt19937::result_type>(
      std::chrono::steady_clock::now().time_since_epoch().count())};

  // Random number generator that generates uniform numbers between 1 and 6
  std::uniform_int_distribution die6_clock{1, 6};
  std::array<unsigned int, 7> distribution_clock{};

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count) {
    int value = die6_clock(mt_clock); // Generate a roll of the die here
    std::cout << value << '\t';       // Print the value of the die roll
    ++distribution_clock[static_cast<size_t>(
        value)]; // Increment the count for this value

    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
      std::cout << '\n';
  }
  std::cout << '\n';
  std::cout << "Distribution of die rolls:\n";
  for (size_t i{1}; i < distribution_clock.size(); ++i) {
    std::cout << i << ": " << distribution_clock[i] << '\n';
  }

  // Seed the Mersenne Twister with one random number generated from a temporary
  // instance of std::random_device
  std::mt19937 mt_dev{std::random_device{}()};

  // Random number generator that generates uniform numbers between 1 and 6
  std::uniform_int_distribution die6_dev{1, 6};

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count) {
    std::cout << die6_dev(mt_dev) << '\t'; // Generate a roll of the die here

    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
      std::cout << '\n';
  }

  // Print std::random_device{}() value
  std::cout << "std::random_device{}(): " << std::random_device{}() << '\n';

  // Call Random::get() to generate random integral values
  // If the two arguments have the same type, the returned value will have that
  // same type.
  std::cout << Random::get(1, 6) << '\n'; // Returns int between 1 and 6
  std::cout << Random::get(1u, 6u)
            << '\n'; // Returns unsigned int between 1 and 6

  // In cases where we have two arguments with different types and/or if we want
  // the return type to be different than the argument types. We must specify
  // the return type using a template type argument (between the angled
  // brackets)
  std::cout << Random::get<std::size_t>(1, 6u)
            << '\n'; // Returns std::size_t between 1 and 6

  // If we have our own distribution, we can access Random::mt directly.
  // Random number generator that generates uniform numbers between 1 and 6
  std::uniform_int_distribution die6_lib{1, 6};
  for (int count{1}; count <= 10; ++count) {
    std::cout << die6_lib(Random::mt)
              << '\t'; // Generate a roll of the die here
  }

  std::cout << '\n';

  // Best practice: Only use a halt if there is no safe or reasonable way to
  // return normally from the main function.
  std::exit(EXIT_SUCCESS); // Terminate and return status code to the OS

  // The following statements never execute
  std::cout << "The sum of 3 and 4 is: " << BasicMath::add(3, 4) << "\n\n";

  return EXIT_SUCCESS;
}
