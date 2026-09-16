/**
 * add.hpp
 *  Small utility function declaration for demonstration purposes.
 *  Provides a clear, well-documented interface.
 *
 * Function: add
 *
 * Parameters:
 *  - a: first integer operand
 *  - b: second integer operand
 *
 * Returns:
 *  - The sum of a and b.
 *
 * Notes:
 *  - This uses built-in `int` arithmetic; callers should be aware of potential
 * overflow for very large values.
 */

#ifndef ADD_HPP
#define ADD_HPP

namespace BasicMath {
int add(int a, int b);
} // namespace BasicMath

#endif // ADD_HPP
