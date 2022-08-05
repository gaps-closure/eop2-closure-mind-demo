#include "WGS84.h"

/*!
 * Return the gravity at the surface of the ellipsoid, as a function of the
 * latitude.  This is the WGS84 ellipsoidal gravity formula, also known as
 * the Somigliana model.
 * \param latitude is the geodetic latitude.
 * \return the gravity in meters per second per second.
 */


/*!
 * Return the gravity at the surface of the ellipsoid, as a function of the
 * latitude.  This is the WGS84 ellipsoidal gravity formula, also known as
 * the Somigliana model.
 * \param sinlat is the sin of the geodetic latitude.
 * \return the gravity in meters per second per second.
 */


/*!
 * Compute the East-West radius of curvature at a specific latitude
 * \param latitude is the geodetic latitude in radians, positive North.
 * \return the East-West radius of curvature in meters.
 */
double radiusOfEWCurv(double latitude)
{
    return radiusOfEWCurvFromSinLat(sin(latitude));

}// radiusOfEastWestCurvature


/*!
 * Compute the East-West radius of curvature from the sin() of the latitude
 * \param sinLat is the sin of the geodetic latitude.
 * \return the East-West radius of curvature in meters.
 */
double radiusOfEWCurvFromSinLat(double sinLat)
{
    return datum_semiMajorAxis / sqrt(1.0 - datum_eSquared * sinLat * sinLat);

}// radiusOfEastWestCurvature
