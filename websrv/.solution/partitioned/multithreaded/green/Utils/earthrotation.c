#include "earthrotation.h"
#include "Constants.h"
#include <math.h>


/*!
 * Convert a vector in North, East, Down to Earth Centered Earth Fixed.
 * \param ned is the NED vector to convert
 * \param ecef receives the equivalent ECEF vector
 * \param lla is the position in latitude and longitude in radians.
 */


/*!
 * Convert a vector in Earth Centered Earth Fixed to North, East, Down.
 * \param ecef is the ECEF vector to convert
 * \param ned receives the equivalent NED vector
 * \param lla is the position in latitude and longitude in radians.
 */


/*!
 * Convert a vector in North, East, Down to Earth Centered Earth Fixed. The
 * conversion is done using precomputed trig values for latitude and longitude.
 * \param ned is the NED vector to convert
 * \param ecef receives the equivalent ECEF vector. ecef can be the same memory
 *        as ned for rotation in place.
 * \param trig are the precomputed trig values that depend on latitude and longitude
 */


/*!
 * Convert a vector in Earth Centered Earth Fixed to North, East, Down. The
 * conversion is done using precomputed trig values for latitude and longitude.
 * \param ecef is the ECEF vector to convert
 * \param ned receives the equivalent NED vector. ned can be the same memory
 *        as ecef for rotation in place.
 * \param trig are the precomputed trig values that depend on latitude and longitude
 */


/*!
 * Fill out a dcm that rotates from NED to ECEF
 * \param dcm is filled out with the rotation
 * \param trig are the LLA trig values that go into the rotation
 */
void nedToECEFdcmd(DCMd_t* dcm, const llaTrig_t* trig)
{
    double* dcmdata = dcm->data;

    dcmdata[0] = (-trig->sinLat*trig->cosLon); dcmdata[1] = (-trig->sinLon); dcmdata[2] = (-trig->cosLat*trig->cosLon);
    dcmdata[3] = (-trig->sinLat*trig->sinLon); dcmdata[4] = ( trig->cosLon); dcmdata[5] = (-trig->cosLat*trig->sinLon);
    dcmdata[6] = ( trig->cosLat);              dcmdata[7] =  0.0;            dcmdata[8] = (-trig->sinLat);

}// nedToECEFdcmd


/*!
 * Fill out a dcm that rotates from ECEF to NED
 * \param dcm is filled out with the rotation
 * \param trig are the LLA trig values that go into the rotation
 */
void ecefToNEDdcmd(DCMd_t* dcm, const llaTrig_t* trig)
{
    double* dcmdata = dcm->data;

    // Notice the indices are transposed compared to above
    dcmdata[0] = (-trig->sinLat*trig->cosLon); dcmdata[3] = (-trig->sinLon); dcmdata[6] = (-trig->cosLat*trig->cosLon);
    dcmdata[1] = (-trig->sinLat*trig->sinLon); dcmdata[4] = ( trig->cosLon); dcmdata[7] = (-trig->cosLat*trig->sinLon);
    dcmdata[2] = ( trig->cosLat);              dcmdata[5] =  0.0;            dcmdata[8] = (-trig->sinLat);

}// ecefToNEDdcmd


/*!
 * Compute the gravity vector in the ECEF frame given the strength of gravity
 * in the NED frame. Gravity in NED has one component, DOWN, which is positive.
 * \param gravityDown is the strenght of gravity in m/s/s.
 * \param gravityEcef receives the gravity vector in ECEF.
 * \param trig are the LLA trig values that go into the rotation.
 */
void gravityToECEFd(double gravityDown, double gravityEcef[NECEF], const llaTrig_t* trig)
{
    // This is the NED to ECEF rotation assuming NORTH and EAST are zero.
    gravityEcef[ECEFX] = (-gravityDown*trig->cosLat*trig->cosLon);
    gravityEcef[ECEFY] = (-gravityDown*trig->cosLat*trig->sinLon);
    gravityEcef[ECEFZ] = (-gravityDown*trig->sinLat);

}// gravityToECEFd


/*!
 * Convert a vector in North, East, Down to Earth Centered Earth Fixed.
 * \param ned is the NED vector to convert
 * \param ecef receives the equivalent ECEF vector
 * \param lla is the position in latitude and longitude in radians.
 */


/*!
 * Convert a vector in Earth Centered Earth Fixed to North, East, Down.
 * \param ecef is the ECEF vector to convert
 * \param ned receives the equivalent NED vector
 * \param lla is the position in latitude and longitude in radians.
 */


/*!
 * Convert a vector in North, East, Down to Earth Centered Earth Fixed. The
 * conversion is done using precomputed trig values for latitude and longitude.
 * \param ned is the NED vector to convert
 * \param ecef receives the equivalent ECEF vector. ecef can be the same memory
 *        as ned for rotation in place.
 * \param trig are the precomputed trig values that depend on latitude and longitude
 */


/*!
 * Convert a vector in Earth Centered Earth Fixed to North, East, Down. The
 * conversion is done using precomputed trig values for latitude and longitude.
 * \param ecef is the ECEF vector to convert
 * \param ned receives the equivalent NED vector. ned can be the same memory
 *        as ecef for rotation in place.
 * \param trig are the precomputed trig values that depend on latitude and longitude
 */


/*!
 * Fill out a dcm that rotates from NED to ECEF
 * \param dcm is filled out with the rotation
 * \param trig are the LLA trig values that go into the rotation
 */


/*!
 * Fill out a dcm that rotates from ECEF to NED
 * \param dcm is filled out with the rotation
 * \param trig are the LLA trig values that go into the rotation
 */


/*!
 * Compute the gravity vector in the ECEF frame given the strength of gravity
 * in the NED frame. Gravity in NED has one component, DOWN, which is positive.
 * \param gravityDown is the strenght of gravity in m/s/s.
 * \param gravityEcef receives the gravity vector in ECEF.
 * \param trig are the LLA trig values that go into the rotation.
 */
void gravityToECEF(float gravityDown, float gravityEcef[NECEF], const llaTrig_t* trig)
{
    // This is the NED to ECEF rotation assuming NORTH and EAST are zero.
    gravityEcef[ECEFX] = (float)(-gravityDown*trig->cosLat*trig->cosLon);
    gravityEcef[ECEFY] = (float)(-gravityDown*trig->cosLat*trig->sinLon);
    gravityEcef[ECEFZ] = (float)(-gravityDown*trig->sinLat);

}// gravityToECEF


/*!
 * Perform Earth rotation tests, converting between NED and ECEF representations
 * \return TRUE if the tests pass
 */
