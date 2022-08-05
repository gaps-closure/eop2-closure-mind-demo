#include "mathutilities.h"

//! Number of days between Jan 6 1980 and Jan 1 2012
#define JAN12012 11683

//! Day number at start of each month for a common year, day and month are zero based

//! Day number at start of each month for a leap year, day and month are zero based


//! Determine if a year is a leap year in the Gregorian calendar.


/*!
 * Add two angles together accounting for circular wrap
 * \param first is the first angle in radians in the range -PI to PI
 * \param second is the second angle in radians in the range -PI to PI
 * \return the correctly wrapped sum of first and second, in the range -PI to PI
 */


/*!
 * Subtract one angle from another accounting for circular wrap
 * \param left is the first angle in radians in the range -PI to PI
 * \param serightcond is the second angle in radians in the range -PI to PI
 * \return the correctly wrapped difference of left minus right, in the range -PI to PI
 */


/*!
 * Adjust an angle for circular wrap. The input angle will only be adjusted by
 * one circle (2PI). Arbitrary angles should be adjusted using fmod(angle, 2PI)
 * \param angle is the angle to adjust in radians, in the range of -3PI to 3PI.
 * \return an equivalent angle in the range of -PI to PI.
 */


/*!
 * Adjust an angle for circular wrap with the wrap point at -270/+90. The input
 * angle will only be adjusted by one circle (2PI).
 * \param angle is the angle to adjust in radians, in the range of -3.5PI to 2.5PI.
 * \return an equivalent angle in the range of -1.5PI to 0.5PI.
 */
double wrapAngle90(double angle)
{
    if(angle > PId/2)
        angle -= 2*PId;
    else if(angle <= -3*PId/2)
        angle += 2*PId;

    return angle;
}


/*!
 * A simple first order low pass filter where state is stored by the caller.
 * \param prev is the previous output of the filter
 * \param sig is the new signal
 * \param tau is the filter time constant
 * \param sampleTime is the iteration period of the filter, in the same units as tau
 * \return the new filtered value, which the caller must store
 */
double firstOrderFilter(double prev, double sig, double tau, double sampleTime)
{
    return prev + sampleTime * (sig - prev) / (tau + sampleTime);

}// firstOrderFilter


/*!
 * Add two angles together accounting for circular wrap
 * \param first is the first angle in radians in the range -PI to PI
 * \param second is the second angle in radians in the range -PI to PI
 * \return the correctly wrapped sum of first and second, in the range -PI to PI
 */


/*!
 * Subtract one angle from another accounting for circular wrap
 * \param left is the first angle in radians in the range -PI to PI
 * \param serightcond is the second angle in radians in the range -PI to PI
 * \return the correctly wrapped difference of left minus right, in the range -PI to PI
 */


/*!
 * Adjust an angle for circular wrap. The input angle will only be adjusted by
 * one circle (2PI). Arbitrary angles should be adjusted using fmod(angle, 2PI)
 * \param angle is the angle to adjust in radians, in the range of -3PI to 3PI.
 * \return an equivalent angle in the range of -PI to PI.
 */


/*!
 * Adjust an angle for circular wrap with the wrap point at -270/+90. The input
 * angle will only be adjusted by one circle (2PI).
 * \param angle is the angle to adjust in radians, in the range of -3.5PI to 2.5PI.
 * \return an equivalent angle in the range of -1.5PI to 0.5PI.
 */


/*!
 * Adjust an angle for circular wrap with the wrap point at 0/360. The input
 * angle will only be adjusted by one circle (2PI).
 * \param angle is the angle to adjust in radians, in the range of -2PI to 2PI.
 * \return an equivalent angle in the range of 0 to 2PI.
 */
float wrapAngle360f(float angle)
{
    if(angle < 0)
        angle += 2*PIf;

    return angle;
}


/*!
 * Compute a fast approximation to the sine of an angle
 * \param angle is the angle to compute the sine of, in radians
 * \return the approximate sine of angle
 */


/*!
 * Compute a fast approximation to the cosine of an angle
 * \param angle is the angle to compute the cosine of, in radians
 * \return the approximate cosine of angle
 */


/*! 
 * Fast inverse square root approximation
 * \param x is the number to take the inverse square root of
 * \return x ^ -0.5
 */
float fastISqrt(float x)
{
    // Union for reinterpreting x as an int32_t
    union { float f; int32_t i; } u;

    // "What the fuck?" --John Carmack
    u.f = x;
    u.i = 0x5f3759dfL - (u.i >> 1);

    // Single Newton iteration
    return u.f * (1.5f - (0.5f * x * u.f * u.f));

}// fastISqrt


/*! 
 * Fast square root approximation
 * \param x is the number to take the square root of
 * \return x ^ 0.5
 */
float fastSqrt(float x)
{
    // Multiply inverse square root by X to get sqrt(x)
    return x * fastISqrt(x);

}// fastSqrt


/*!
 * A simple first order low pass filter where state is stored by the caller.
 * \param prev is the previous output of the filter
 * \param sig is the new signal
 * \param tau is the filter time constant
 * \param sampleTime is the iteration period of the filter, in the same units as tau
 * \return the new filtered value, which the caller must store
 */
float firstOrderFilterf(float prev, float sig, float tau, float sampleTime)
{
    return prev + sampleTime * (sig - prev) / (tau + sampleTime);

}// firstOrderFilterf


/*!
 * Apply a rate of change limit
 * \param prev is the previous output of the limiter
 * \param value is the new proposed value whose derivative should be limited
 * \param limit is the time-rate-of-change limit for value, i.e. the max time derivative of value.
 * \param sampleTime is the elapsed time since prev was computed.
 * \return The rate-of-change limited value.
 */
float rateOfChangeLimitf(float prev, float value, float limit, float sampleTime)
{
    float delta;

    // the maximum amount of change allowed
    float maxDelta = sampleTime*limit;

    // Which must be positive non-zero to make sense
    if(maxDelta <= 0)
        return value;

    // The actual proposed changed
    delta = value-prev;

    // Return the limited value if needed
    if(delta > maxDelta)
        return prev + maxDelta;
    else if(delta < -maxDelta)
        return prev - maxDelta;
    else
        return value;

}


/*!
 * Use GPS time information to compute the Gregorian calendar date and time with respect to UTC.
 * This only works for dates after Jan 1 2012.
 * \param week is the GPS week number
 * \param itow is the GPS time of week in milliseconds
 * \param leapsecs is the number of leapseconds to subtract from GPS time to get UTC time
 * \param pyear receives the Gregorian year
 * \param pmonth receives the month of the year, from 1 (January) to 12 (December)
 * \param pday receives the day of the month, from 1 to 31
 * \param phour receives the hour of the day from 0 to 23
 * \param pmin receives the minute of the hour from 0 to 59
 * \param psec receives the seconds of the minute from 0 to 59
 */


/*!
 * Use GPS time information to compute the Gregorian calendar date.
 * This only works for dates after Jan 1 2012.
 * \param week is the GPS week number
 * \param itow is the GPS time of week in milliseconds
 * \param pyear receives the Gregorian year
 * \param pmonth receives the month of the year, from 1 (January) to 12 (December)
 * \param pday receives the day of the month, from 1 to 31
 */


/*!
 * Compute hours, minutes, and seconds from time of week.
 * \param itow is the time of week in milliseconds
 * \param hour receives the hour of the day from 0 to 23
 * \param min receives the minute of the hour from 0 to 59
 * \param second receives the seconds of the minute from 0 to 59
 */


/*!
 * Determine if a year is a leap year in the Gregorian calendar.
 * \param year is the year number.
 * \return 0 for a common year (365 days), 1 for a leap year (366 days)
 */


/*!
 * Use Gregorian date information to compute GPS style time information. The
 * output is either in GPS time or UTC time, depending on which time reference
 * is used for the inputs. This function only works for dates after Jan 1 2012
 * \param year is the Gregorian calendar year
 * \param month is the month of the year, from 1 (January) to 12 (December)
 * \param day is the day of the month, from 1 to 31
 * \param hours is the hour of the dya, from 0 to 23
 * \param minutes is the minute of the hour, from 0 to 59
 * \param seconds is the seconds of the minute, from 0 to 60 (60 may occur in a leap second jump)
 * \param milliseconds is the milliseconds of the second
 * \param pweek receives the number of weeks since Jan 6 1980 (aka GPS week number)
 * \param pitow receives the time of week in milliseconds
 */


/*!
 * Test the date conversion logic
 * \return 1 if good, 0 if bad
 */



