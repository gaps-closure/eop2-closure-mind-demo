#ifndef EARTHROTATION_H
#define EARTHROTATION_H

#include "dcm.h"
#include "earthposition.h"

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

//! Convert an NED vector to ECEF

//! Convert an NED vector to NED

//! Convert an NED vector to ECEF using trig data

//! Convert an ECEF vector to NED using trig data

//! Fill out a dcm that rotates from NED to ECEF
void nedToECEFdcmd(DCMd_t* dcm, const llaTrig_t* trig);

//! Fill out a dcm that rotates from ECEF to NED
void ecefToNEDdcmd(DCMd_t* dcm, const llaTrig_t* trig);

//! Compute the gravity vector in the ECEF frame given the strength of gravity.
void gravityToECEFd(double gravityDown, double gravityEcef[NECEF], const llaTrig_t* trig);

//! Convert an NED vector to ECEF

//! Convert an ECEF vector to NED

//! Convert an NED vector to ECEF using trig data

//! Convert an ECEF vector to NED using trig data

//! Fill out a dcm that rotates from NED to ECEF

//! Fill out a dcm that rotates from ECEF to NED

//! Compute the gravity vector in the ECEF frame given the strength of gravity.
void gravityToECEF(float gravityDown, float gravityEcef[NECEF], const llaTrig_t* trig);

//! Test earth rotations

// C++ compilers: don't mangle us
#ifdef __cplusplus
}
#endif

#endif // EARTHROTATION_H
