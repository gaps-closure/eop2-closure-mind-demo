#ifndef QUATERNION_H
#define QUATERNION_H

/*!
 * \file
 * Quaternion is a 4 element vector that represents the rotation from the
 * body to a reference frame. The choice of reference frame is arbitrary but is
 * typically NED or ECEF.  Note that the roll, pitch, and yaw functions are
 * defined based on the reference frame.  They typically only make sense if the
 * reference frame is NED.
 */

#include "dcm.h"

//! Enumeration for a quaternion attitude vector
enum
{
    Q0,
    Q1,
    Q2,
    Q3,
    NQUATERNION
};

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

//! Convert a quaternion to a DCM
void quaternionToDCM(const float quat[NQUATERNION], DCM_t* dcm);

//! Convert a DCM to quaternion
void dcmToQuaternion(const DCM_t* dcm, float quat[NQUATERNION]);

//! Initialize the quaternion to 0 roll, 0 pitch, 0 yaw

//! Fill out the quaternion from an Euler roll angle
void setQuaternionBasedOnRoll(float quat[NQUATERNION], float roll);

//! Fill out the quaternion from an Euler pitch angle
void setQuaternionBasedOnPitch(float quat[NQUATERNION], float pitch);

//! Fill out the quaternion from an Euler yaw angle
void setQuaternionBasedOnYaw(float quat[NQUATERNION], float yaw);

//! Fill out the quaternion from Euler angles
void setQuaternionBasedOnEuler(float quat[NQUATERNION], float yaw, float pitch, float roll);

//! Compute the Euler yaw angle of a quaternion.
float quaternionYaw(const float quat[NQUATERNION]);

//! Compute the Euler pitch rotation of a quaternion.
float quaternionPitch(const float quat[NQUATERNION]);

//! Compute the cosine of the Euler pitch angle of a quaternion
float quaternionCosPitch(const float quat[NQUATERNION]);

//! Compute the sin of the Euler pitch angle of a quaternion
float quaternionSinPitch(const float quat[NQUATERNION]);

//! Compute the Euler roll rotation.
float quaternionRoll(const float quat[NQUATERNION]);

//! Compute the cosine of the Euler roll angle of a quaternion
float quaternionCosRoll(const float quat[NQUATERNION]);

//! Compute the sin of the Euler roll angle of a quaternion
float quaternionSinRoll(const float quat[NQUATERNION]);

//! Use a quaternion to rotate a vector.
void quaternionApplyRotation(const float quat[NQUATERNION], const float input[], float output[]);

//! Use a quaternion to rotate a vector, in the reverse direction.
void quaternionApplyReverseRotation(const float quat[NQUATERNION], const float input[], float output[]);

//! Compute the length of a quaternion which should be 1.0
float quaternionLength(const float quat[NQUATERNION]);

//! Multiply two quaternions together

//! Multiply two quaternions together such that r = p^-1*q

//! Multiply two quaternions together such that r = p*q^-1

//! Convert a quaternion to a rotation vector

//! Convert a rotation vector to a quaternion
float* rotVecToQuaternion( const float rotVec[NVECTOR3], float quat[NQUATERNION] );

//! Test quaternion operations
BOOL testQuaternion(void);

//////////////////////////////////////////////////
// Functions for double precision quaternion below

//! Convert a quaternion to a DCM

//! Convert a quaternion to a DCM (float)
void quaterniondToDCMf(const double quat[NQUATERNION], DCM_t* dcm);

//! Convert a DCM to quaternion

//! Convert a DCM (float) to quaternion
void dcmfToQuaterniond(const DCM_t* dcm, double quat[NQUATERNION]);

//! Initialize the quaternion to 0 roll, 0 pitch, 0 yaw

//! Fill out the quaternion from an Euler roll angle

//! Fill out the quaternion from an Euler pitch angle

//! Fill out the quaternion from an Euler yaw angle

//! Fill out the quaternion from Euler angles

//! Compute the Euler yaw angle of a quaternion.

//! Compute the Euler pitch rotation of a quaternion.

//! Compute the cosine of the Euler pitch angle of a quaternion

//! Compute the sin of the Euler pitch angle of a quaternion

//! Compute the Euler roll rotation.

//! Compute the cosine of the Euler roll angle of a quaternion

//! Compute the sin of the Euler roll angle of a quaternion

//! Use a quaternion to rotate a vector.

//! Use a quaternion to rotate a vector, in the reverse direction.

//! Compute the length of a quaternion which should be 1.0

//! Multiply two quaternions together

//! Multiply two quaternions together such that r = p^-1*q

//! Multiply two quaternions together such that r = p*q^-1

//! Convert a quaternion to a rotation vector

//! Convert a rotation vector to a quaternion
double* rotVecToQuaterniond( const double rotVec[NVECTOR3], double quat[NQUATERNION] );

//! Test quaternion operations

// C++ compilers: don't mangle us
#ifdef __cplusplus
}
#endif

#endif // QUATERNION_H
