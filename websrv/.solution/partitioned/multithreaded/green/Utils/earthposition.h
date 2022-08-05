#ifndef EARTHPOSITION_H
#define EARTHPOSITION_H

#include "Types.h"

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

enum
{
    ECEFX,
    ECEFY,
    ECEFZ,
    NECEF
};

enum
{
    LAT,
    LON,
    ALT,
    NLLA
};

enum
{
    NORTH,
    EAST,
    DOWN,
    NNED
};


/*! A structure to represent the trigonmetric values of the latitude and longitude */
typedef struct
{
    double sinLat;
    double sinLon;
    double cosLat;
    double cosLon;

}llaTrig_t;

//! Compute the trigonmetric quantities of latitude and longitude

//! Convert a LLA position to Earth centered Earth fixed.

//! Convert a LLA position to Earth centered Earth fixed, and return the lla trig values

//! Convert a LLA position represented by trigonometric values to ECEF

//! Convert the ECEF position to LLA

//! Convert the ECEF position to LLA, with LLA trig

//! Convert an array of geodetic coordinates to spherical geocentric coordinates.

//! Perform Earth position tests

// C++ compilers: don't mangle us
#ifdef __cplusplus
}
#endif

#endif // EARTHPOSITION_H
