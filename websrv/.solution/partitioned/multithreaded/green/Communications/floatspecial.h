#ifndef FLOATSPECIAL_H
#define FLOATSPECIAL_H

#ifdef __cplusplus
extern "C"{
#endif

/*!
 * \file
 * \brief Special routines for floating point manipulation
 *
 * These routines allow floating point values to be compressed to
 * smaller formats by discarding resolution and dynamic range. This is
 * useful for saving space in data messages for fields that have a lot of
 * dynamic range, but not a lot of required resolution.
 *
 * float16 and float24 are not defined by IEEE-754, but uses the same rules.
 * The most significant bit is a sign bit, the next bits are biased exponent
 * bits, and the remaining bits are used for the significand. float16 and
 * float24 have a variable number of signifcand bits, which can be adjusted
 * as needed to best fit the application.
 *
 * Note that IEEE-754 defines a binary16 format (also called half-precision),
 * which uses a 10-bit significand (therefore 5 bits of exponent). float16
 * with 10 bits significand is the same as IEEE-754 half precision.
 *
 * float16 and float24 cannot be used for arithmetic. Accordingly this module
 * only provides routines to convert between these and binary32 (float). In
 * memory floating point numbers are always IEEE-754 binary32 or IEEE-754
 * binary64. The in-memory representation of a float16 or float24 is actually
 * an integer which can be encoded into a data message like any integer.
 */

#include <stdint.h>

//! Determine if a 32-bit field represents a valid 32-bit IEEE-754 floating point number.

//! Determine if a 64-bit field represents a valid 64-bit IEEE-754 floating point number.

//! Convert a 32-bit floating point value to 24-bit floating point with 15 bit significand (deprecated)

//! Convert a 24-bit floating point representation with 15 bits significand to binary32 (deprecated)

//! Convert a 32-bit floating point value to 24-bit floating point

//! Convert a IEEE-754 binary24 floating point representation to binary32

//! Convert a 32-bit floating point value to 16-bit floating point with 9 bit significand (deprecated)

//! Convert a 16-bit floating point representation with 9 bits significand to binary32 (deprecated)

//! Convert a 32-bit floating point value to 16-bit floating point representation

//! Convert a 16 bit floating point representation to binary32

//! test the special float functionality

#ifdef __cplusplus
}
#endif
#endif // FLOATSPECIAL_H
