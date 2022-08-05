#include "GpsDataReceive.h"
#include "OrionPublicPacket.h"
#include "earthposition.h"
#include "earthrotation.h"
#include <math.h>

/*!
 * Fill out null-encoded ECEF position and velocity members of the GpsData_t
 * after it was received via ORION_PKT_GPS_DATA packet, by converting from the
 * LLA and NED data members. Some other null-encoded data members are also
 * set by this function.
 * \param gpsdata_t points to the GpsData_t whose ECEF position and velocity data are updated.
 */


/*!
 * Fill out null-encoded ECEF position and velocity uncertainty members of the GpsData_t
 * after it was received via ORION_PKT_GPS_DATA packet, by converting from the
 * LLA and NED data members.
 * \param gpsdata_t points to the GpsData_t whose ECEF uncertainty data are updated.
 */

