#include "GeolocateTelemetry.h"
#include "earthposition.h"
#include "earthrotation.h"
#include "mathutilities.h"
#include "linearalgebra.h"
#include "WGS84.h"

#include <string.h>


/*!
 * Create a GeolocateTelemetry packet
 * \param pPkt receives the formatted packet
 * \param pGeo is the geo locate telemetry to encode
 */


/*!
 * Parse a GeolocateTelemetry packet
 * \param pPkt is the received packet packet
 * \param pGeo receives the parsed data, including locally constructed data
 * \return TRUE if the packet was successfully decoded
 */


/*!
 * Convert a GeolocateTelemetryCore_t struct to GeolocateTelemetry_t
 * \param pCore is a GeolocateTelemetryCore_t message to be converted
 * \param pGeo receives a copy of pCore, as well as some locally constructed data
 */


/*!
 * Given a current image location compute a new location based on a angular
 * deviation in camera frame (i.e. user click) and assuming the altitude of the
 * new location is the same as the image location altitude.
 * \param geo is the geolocate telemetry from the gimbal.
 * \param imagePosLLA is the latitude, longitude, altitude of the current image
 *        location in radians, radians, meters.
 * \param ydev is the angular deviation in radians from the image location in
 *        right camera direction.
 * \param zdev is the angular deviation in radians from the image location in
 *        up camera direction.
 * \param newPosLLA receives the position of the user click
 * \param slantRangeM Slant Range to point in Meters
 */

//! Returns the approximate distance to the horizon based on MSL altitude and latitude.

/*!
 * Assuming the gimbal is over the ocean, compute an image location based on
 * angular deviation in camera frame (i.e. user click).
 *
 * \param geo is the geolocate telemetry from the gimbal.
 * \param deltaYawDeg is the angular deviation in radians from the image location in
 *        right camera direction.
 * \param deltaPitchRad is the angular deviation in radians from the image location in
 *        up camera direction.
 * \param newPosLLA receives the position of the user click. If the click is above the
 *        horizon, a point above the ocean at the distance to horizon will be returned.
 * \param slantRangeM Slant Range to point in Meters
 */

/*! Get the terrain intersection of the current line of sight given gimbal geolocate telemetry data.
 *  \param pGeo[in] A pointer to incoming geolocate telemetry data
 *  \param getElevationHAE[in] Pointer to a terrain model lookup function, which should take a lat/lon
 *                             pair (in radians) and return the height above ellipsoid of that point
 *  \param PosLLA[out] Terrain intersection location in the LLA frame
 *  \param pRange[out] Target range in meters to be sent to the gimbal
 *  \return TRUE if a valid intersection was found, otherwise FALSE. Note that if this function
 *          returns FALSE, the data in PosLLA and pRange will still be overwritten with invalid data.
 */


/*!
 * Get the velocity of the terrain intersection
 * \param buf points to the geolocate buffer
 * \param dt is the desired timer interval in milliseconds
 * \param imageVel receives the velocity of the image in North, East Down, meters
 * \return TRUE if the velocity was computed, else FALSE
 */


/*!
 * Get a buffered geolocate telemetry struct
 * \param buf points to the geolocate buffer
 * \param dt is the desired timer interval in milliseconds
 * \param imageVel receives the velocity of the gimbal in North, East Down, meters
 * \return TRUE if the velocity was computed, else FALSE
 */


/*!
 * Push a new geolocate telemetry into a geolocate buffer
 * \param buf is the geolocate buffer to put new data into
 * \param geo is the new data to load, which will be copied into the buffer
 */


/*!
 * Copy a geolocate structure, which cannot be done with simple assignment due to the DCM pointers
 * \param source is the source structure whose contents are copied.
 * \param dest receives a copy of the data in source.
 */

