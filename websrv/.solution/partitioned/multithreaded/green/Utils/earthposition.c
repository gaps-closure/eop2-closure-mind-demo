#include "earthposition.h"
#include "WGS84.h"
#include "Constants.h"
#include <math.h>


/*!
 * Compute the trigonmetric quantities of latitude and longitude
 * \param lla is the latitude, longitude, altitude array in rad, rad, meters.
 * \param trig receives the sin and cosine of latitude and longitude.
 * \return a const pointer to trig.
 */


/*!
 * Convert a LLA position to Earth centered Earth fixed.
 * \param lla is the latitude, longitude, altitude array in rad, rad, meters.
 * \param ecef receives the X, Y, Z ECEF coordinates in meters.
 */


/*!
 * Convert a LLA position to Earth centered Earth fixed, and return the lla trig values.
 * \param lla is the latitude, longitude, altitude array in rad, rad, meters.
 * \param ecef receives the X, Y, Z ECEF coordinates in meters.
 * \param trig receives the lla trigonmetric values.
 */


/*!
 * Convert a LLA position represented by trigonometric values to Earth
 * centered Earth fixed.
 * \param alt is the altitude of the LLA position with respect to the
 *        WGS-84 ellipsoid in meters.
 * \param ecef is a 3 element array that receives the X, Y, Z ECEF
 *        coordinates in meters.
 * \param trig points to the lla trigonometric values.
 */


/*!
 * Convert the ECEF (earth centered, earth fixed) position to geodetic
 * (latitude, longitude, altitude) position.  This conversion is not exact
 * and provides centimeter accuracy for heights below 1000km.  See
 * Browning, B. 1976. Transformation from spatial to geographical
 * coordinates. Survey Review XXIII: page 323-327.
 * \param ecef is the X, Y, Z ECEF position in meters.
 * \param lla receives the LLA position in radians, radians, meters.
 */


/*!
 * Convert the ECEF (earth centered, earth fixed) position to geodetic
 * (latitude, longitude, altitude) position, and latitude and longitude
 * trigonometric values.  This conversion is not exact
 * and provides centimeter accuracy for heights below 1000km.  See
 * Browning, B. 1976. Transformation from spatial to geographical
 * coordinates. Survey Review XXIII: page 323-327.
 * \param ecef is the X, Y, Z ECEF position in meters.
 * \param lla receives the LLA position in radians, radians, meters.
 * \param trig receives the latitude and longitude trig values.*/


/*!
 * Convert an array of geodetic coordinates (latitude, longitude, altitude)
 * to spherical geocentric coordinates (latitude', longitude, radius).
 * Geodetic coordinates are the familiar latitude, longitude, and altitude
 * in which the locally level plane (tangent to the ellipsoid) has North,
 * East, -Down axes parallel to Latitude, Longitude, Altitude axes.  Because
 * WGS84 is an ellipsoid (not a sphere) the origin of the geodetic
 * coordinate system is not at the center of the earth, and moves along the
 * equatorial plane as latitude changes.  In contrast the geocentric 
 * coordinates have their origin at the center of the Earth.
 * 
 * \param geodetic is 3 element array of geodetic coordinates in latitude(rad),
 *        longitude(rad), altitude(m) with respect to the WGS-84 ellipsoid.
 * \param spherical is a 3 element array that receives the equivalent spherical
 *        coordinates in latitude'(rad), longitude(rad), radius(m).  spherical
 *        can refer to the same array as geodetic.
 */


/*!
 * Perform Earth position tests, converting between LLA and ECEF representations
 * \return TRUE if the tests pass
 */
