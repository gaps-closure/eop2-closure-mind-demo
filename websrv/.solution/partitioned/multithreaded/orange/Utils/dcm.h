#ifndef DCM_H
#define DCM_H

/*!
 * \file
 * DCM is a direction cosine 3x3 matrix that represents the rotation from the
 * body to a reference frame. The choice of reference frame is arbitrary but is
 * typically NED or ECEF.  Note that the roll, pitch, and yaw functions are
 * defined based on the reference frame.  They typically only make sense if the
 * reference frame is NED.
 */

#include "linearalgebra.h"

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

//! DCM is a 3x3 matrix of floats
typedef Matrixf_t DCM_t;

//! DCMd is a 3x3 matrix of doubles
typedef Matrix_t DCMd_t;

//! indices for row major access of a 3x3 DCM
enum
{
    T11,
    T12,
    T13,
    T21,
    T22,
    T23,
    T31,
    T32,
    T33,
    TNUM
};

/*!
 * Macro to allocate a DCM statically. The DCM elements are not initialized.
 * \param M is the name used to refer to the DCM.
 */
#define staticAllocateDCM(M) staticAllocateMatrixf(M, 3, 3)

/*!
 * Macro to allocate a DCM on the stack. The DCM elements are not initialized.
 * \param M is the name used to refer to the DCM.
 */
#define stackAllocateDCM(M) stackAllocateMatrixf(M, 3, 3)

/*!
 * Macro to allocate a DCM as part of a structure. The DCM MUST be setup with structInitDCM()
 * \param M is the name used to refer to the DCM.
 */
#define structAllocateDCM(M)  float M##data[9]; Matrixf_t M

/*!
 * Macro to setup a DCM that was previously named in a struct using structAllocateDCM()
 * \param M is the name used to refer to the DCM.
 */
#define structInitDCM(M) M.data = M##data; M.numRows = M.numCols = 3

//! Allocate a DCM, initializing its memory.

//! Get a specific element of a dcm
float dcmGet(const DCM_t* M, uint32_t row, uint32_t col);

//! Get a specific element of a dcm, when all you have is the raw data

//! Copy a direction cosine matrix.

//! Set a DCM to identity
void dcmSetIdentity(DCM_t* A);

//! Add identity to a DCM

//! Add two DCMs together, placing the result back into the first matrix.

//! Scale a DCM

//! Set a specific element of a dcm
void dcmSet(DCM_t* M, uint32_t row, uint32_t col, float value);

//! Fill out the direction cosine matrix from an Euler roll angle
void setDCMBasedOnRoll(DCM_t* dcm, float roll);

//! Fill out the direction cosine matrix from an Euler pitch angle
void setDCMBasedOnPitch(DCM_t* dcm, float pitch);

//! Fill out the direction cosine matrix from an Euler yaw angle
void setDCMBasedOnYaw(DCM_t* dcm, float yaw);

//! Fill out the direction cosine matrix from Euler angles
void setDCMBasedOnEuler(DCM_t* dcm, float yaw, float pitch, float roll);

//! Fill out the direction cosine matrix from a Pan then a Tilt rotation
void setDCMBasedOnPanTilt(DCM_t* dcm, float pan, float tilt);

//! Compute the Euler yaw angle of a dcm.
float dcmYaw(const DCM_t* dcm);

//! Compute the Euler pitch rotation of a dcm.
float dcmPitch(const DCM_t* dcm);

//! Compute the cosine of the Euler pitch angle of a DCM
float dcmCosPitch(const DCM_t* dcm);

//! Compute the sin of the Euler pitch angle of a DCM
float dcmSinPitch(const DCM_t* dcm);

//! Compute the Euler roll rotation.
float dcmRoll(const DCM_t* dcm);

//! Compute the cosine of the Euler roll angle of a DCM
float dcmCosRoll(const DCM_t* dcm);

//! Compute the sin of the Euler roll angle of a DCM
float dcmSinRoll(const DCM_t* dcm);

//! Use a DCM to rotate a vector.
void dcmApplyRotation(const DCM_t* rotation, const float input[], float output[]);

//! Use a DCM to rotate a vector, in the reverse direction.
void dcmApplyReverseRotation(const DCM_t* rotation, const float input[], float output[]);

//! Use a raw dcm to rotate a vector.
void rawdcmApplyRotation(const float dcmdata[], const float input[], float output[]);

//! Use a raw dcm to rotate a vector, in the reverse direction.
void rawdcmApplyReverseRotation(const float dcmdata[], const float input[], float output[]);

//! Multiply two DCMs together.
void dcmMultiply(const DCM_t* A, const DCM_t* B, DCM_t* C);

//! Multiply two raw DCMs together.
void rawdcmMultiply(const float Adata[9], const float Bdata[9], float Cdata[9]);

//! Multiply the transpose of a DCM against another DCM.

//! Multiply a DCM against another the transpose of another DCM.

//! Transpose a DCM in place

//! Add two DCMs together and multiply each element by 0.5.

//! Convert a 3 element column vector to a skew symmetric DCM

//! Convert 3 elements to a skew symmetric DCM

//! Convert a 3 element column vector to a skew symmetric DCM with 1s on the diagonal

//! Convert 3 elements to a skew symmetric DCM with 1s on the diagonal

//! Convert a 3 elements to a skew symmetric DCM with 1s on the diagonal, allowing the yaw term to be large

//! Test the linear algebra code
BOOL testLinearAlgebra(void);

////////////////////////////////////////////////
// Functions for DCMd_t (double precision) below

/*!
 * Macro to allocate a DCM statically. The DCM elements are not initialized.
 * \param M is the name used to refer to the DCM.
 */
#define staticAllocateDCMd(M) staticAllocateMatrix(M, 3, 3)

/*!
 * Macro to allocate a DCM on the stack. The DCM elements are not initialized.
 * \param M is the name used to refer to the DCM.
 */
#define stackAllocateDCMd(M) stackAllocateMatrix(M, 3, 3)

/*!
 * Macro to allocate a DCM as part of a structure. The DCM MUST be setup with structInitDCM()
 * \param M is the name used to refer to the DCM.
 */
#define structAllocateDCMd(M)  double M##data[9]; Matrix_t M

/*!
 * Macro to setup a DCM that was previously named in a struct using structAllocateDCM()
 * \param M is the name used to refer to the DCM.
 */
#define structInitDCMd(M) M.data = M##data; M.numRows = M.numCols = 3

//! Allocate a DCM, initializing its memory.

//! Get a specific element of a dcm

//! Get a specific element of a dcm, when all you have is the raw data

//! Copy a direction cosine matrix.

//! Set a DCM to identity

//! Add identity to a DCM

//! Add two DCMs together, placing the result back into the first matrix.

//! Scale a DCM

//! Set a specific element of a dcm

//! Fill out the direction cosine matrix from an Euler roll angle

//! Fill out the direction cosine matrix from an Euler pitch angle

//! Fill out the direction cosine matrix from an Euler yaw angle

//! Fill out the direction cosine matrix from Euler angles

//! Fill out the direction cosine matrix from a Pan then a Tilt rotation

//! Compute the Euler yaw angle of a dcm.

//! Compute the Euler pitch rotation of a dcm.

//! Compute the cosine of the Euler pitch angle of a DCM

//! Compute the sin of the Euler pitch angle of a DCM

//! Compute the Euler roll rotation.

//! Compute the cosine of the Euler roll angle of a DCM

//! Compute the sin of the Euler roll angle of a DCM

//! Use a DCM to rotate a vector.

//! Use a DCM to rotate a vector, in the reverse direction.

//! Use a raw dcm to rotate a vector.

//! Use a raw dcm to rotate a vector, in the reverse direction.

//! Multiply two DCMs together.

//! Multiply two raw DCMs together.

//! Multiply the transpose of a DCM against another DCM.

//! Multiply a DCM against another the transpose of another DCM.

//! Transpose a DCM in place

//! Add two DCMs together and multiply each element by 0.5.

//! Convert a 3 element column vector to a skew symmetric DCM

//! Convert 3 elements to a skew symmetric DCM

//! Convert a 3 element column vector to a skew symmetric DCM with 1s on the diagonal

//! Convert 3 elements to a skew symmetric DCM with 1s on the diagonal

//! Convert a 3 elements to a skew symmetric DCM with 1s on the diagonal, allowing the yaw term to be large

// C++ compilers: don't mangle us
#ifdef __cplusplus
}
#endif

#endif // DCM_H
