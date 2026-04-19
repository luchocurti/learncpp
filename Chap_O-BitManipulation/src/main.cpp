/**
 *  main.cpp
 *  - Calling a small library function (add).
 *  - Playing with Bit Manipulation.
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
#include <bitset>      // std::bitset
#include <cstdint>     // fixed-width integer types
#include <cstdlib>     // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream>    // std::cout, std::cin, std::cerr
#include <string>      // std::string, std::getline
#include <string_view> // C++17 std::string_view

/* Templates */

/* Functions */

/* Main Function */
int main() {
#ifdef DEBUG
  std::cerr << "Debug: Starting main()\n";
#endif

  std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n\n";

  [[maybe_unused]] constexpr int isHungry{0};
  [[maybe_unused]] constexpr int isSad{1};
  [[maybe_unused]] constexpr int isMad{2};
  [[maybe_unused]] constexpr int isHappy{3};
  [[maybe_unused]] constexpr int isLaughing{4};
  [[maybe_unused]] constexpr int isAsleep{5};
  [[maybe_unused]] constexpr int isDead{6};
  [[maybe_unused]] constexpr int isCrying{7};

  std::bitset<8> bits{0b0000'0101}; // Start with bit pattern 0000 0101
  bits.set(isHappy);      // set bit position 3 to 1 (now we have 0000 1101)
  bits.flip(isLaughing);  // flip bit 4 (now we have 0001 1101)
  bits.reset(isLaughing); // set bit 4 back to 0 (now we have 0000 1101)

  std::cout << "All the bits: " << bits << '\n';
  std::cout << "I am happy: " << bits.test(isHappy) << '\n';
  std::cout << "I am laughing: " << bits.test(isLaughing) << '\n';

  std::cout << bits.size() << " bits are in the bitset\n";
  std::cout << bits.count() << " bits are set to true\n";

  std::cout << std::boolalpha;
  std::cout << "All bits are true: " << bits.all() << '\n';
  std::cout << "Some bits are true: " << bits.any() << '\n';
  std::cout << "No bits are true: " << bits.none() << '\n';

  std::bitset<4> x{0b1100};

  std::cout << x << '\n';
  std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
  std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000

  // [[maybe_unused]] constexpr std::uint8_t mask0{0b0000'0001};
  // [[maybe_unused]] constexpr std::uint8_t mask1{0b0000'0010};
  // [[maybe_unused]] constexpr std::uint8_t mask2{0b0000'0100};
  // [[maybe_unused]] constexpr std::uint8_t mask3{0b0000'1000};
  // [[maybe_unused]] constexpr std::uint8_t mask4{0b0001'0000};
  // [[maybe_unused]] constexpr std::uint8_t mask5{0b0010'0000};
  // [[maybe_unused]] constexpr std::uint8_t mask6{0b0100'0000};
  // [[maybe_unused]] constexpr std::uint8_t mask7{0b1000'0000};

  [[maybe_unused]] constexpr std::uint8_t mask0{0x01}; // hex for 0000 0001
  [[maybe_unused]] constexpr std::uint8_t mask1{0x02}; // hex for 0000 0010
  [[maybe_unused]] constexpr std::uint8_t mask2{0x04}; // hex for 0000 0100
  [[maybe_unused]] constexpr std::uint8_t mask3{0x08}; // hex for 0000 1000
  [[maybe_unused]] constexpr std::uint8_t mask4{0x10}; // hex for 0001 0000
  [[maybe_unused]] constexpr std::uint8_t mask5{0x20}; // hex for 0010 0000
  [[maybe_unused]] constexpr std::uint8_t mask6{0x40}; // hex for 0100 0000
  [[maybe_unused]] constexpr std::uint8_t mask7{0x80}; // hex for 1000 0000

  std::uint8_t flags{0b0000'0101};

  /* Testing a bit */
  std::cout << "bit 0 is "
            << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
  std::cout << "bit 1 is "
            << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

  /* Setting a bit */
  flags |= mask1; // set bit 1
  // flags |= (mask4 | mask5); // set bits 4 and 5 at the same time
  std::cout << "bit 1 is "
            << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

  /* Resetting a bit */
  flags &= ~mask2; // turn off bit 2
  // flags &= ~(mask4 | mask5); // reset bits 4 and 5 at the same time
  std::cout << "bit 2 is "
            << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");

  /* Flipping a bit */
  flags ^= mask2; // flip bit 2
  // flags ^= (mask4 | mask5); // flip bits 4 and 5 at the same time
  std::cout << "bit 2 is "
            << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");

  return EXIT_SUCCESS;
}
