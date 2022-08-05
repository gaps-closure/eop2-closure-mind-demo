#include "floatspecial.h"
#include <math.h>


/*!
 * Determine if a 32-bit field represents a valid 32-bit IEEE-754 floating
 * point number. If the field is infinity, NaN, or de-normalized then it is
 * not valid. This determination is made without using any floating point
 * instructions.
 * \param value is the field to evaluate
 * \return 0 if field is infinity, NaN, or de-normalized, else 1
 */


/*!
 * Determine if a 64-bit field represents a valid 64-bit IEEE-754 floating
 * point number. If the field is infinity, NaN, or de-normalized then it is
 * not valid. This determination is made without using any floating point
 * instructions.
 * \param value is the field to evaluate
 * \return 0 if field is infinity, NaN, or de-normalized, else 1
 */


/*!
 * \deprecated
 * Convert a 32-bit floating point value (IEEE-754 binary32) to 24-bit floating
 * point representation with 15 bits significand. Underflow will be returned as
 * zero and overflow as the maximum possible value.
 * \param value is the 32-bit floating point data to convert.
 * \return The 24-bit floating point as a simple 32-bit integer with the most
 *         significant byte clear.
 */


/*!
 * Convert a 32-bit floating point value (IEEE-754 binary32) to 24-bit floating
 * point representation with a variable number of bits for the significand.
 * Underflow will be returned as zero and overflow as the maximum possible value.
 * \param value is the 32-bit floating point data to convert.
 * \param sigbits is the number of bits to use for the significand.
 * \return The float24 as a simple 24-bit integer (most significant byte clear).
 */


/*!
 * \deprecated
 * Convert a 24 bit floating point representation with 15 bits significand to
 * binary32.
 * \param value is the 24-bit representation to convert.
 * \return the binary32 version as a float.
 */


/*!
 * Convert a 24-bit floating point representation with variable number of
 * significand bits to binary32
 * \param value is the float16 representation to convert.
 * \param sigbits is the number of bits to use for the significand of the 24-bit float.
 * \return the binary32 version as a float.
 */


/*!
 * \deprecated
 * Convert a 32-bit floating point value (IEEE-754 binary32) to 16-bit floating
 * point representation with 9 bits significand. Underflow will be returned as
 * zero and overflow as the maximum possible value.
 * \param value is the 32-bit floating point data to convert.
 * \return The binary16 as a simple 16-bit integer.
 */


/*!
 * \deprecated
 * Convert a 16 bit floating point representation with 9 bits significand to
 * binary32.
 * \param value is the binary16 representation to convert.
 * \return the binary32 version as a float.
 */


/*!
 * Convert a 32-bit floating point value (IEEE-754 binary32) to 16-bit floating
 * point representation with a variable number of bits for the significand.
 * Underflow will be returned as zero and overflow as the maximum possible value.
 * \param value is the 32-bit floating point data to convert.
 * \param sigbits is the number of bits to use for the significand.
 * \return The float16 as a simple 16-bit integer.
 */


/*!
 * Convert a 16-bit floating point representation with variable number of
 * significand bits to binary32
 * \param value is the float16 representation to convert.
 * \param sigbits is the number of bits to use for the significand of the 16-bit float.
 * \return the binary32 version as a float.
 */


/*!
 * Use this routine (and a debugger) to verify the special float functionality
 * return 1 if test passed
 */
