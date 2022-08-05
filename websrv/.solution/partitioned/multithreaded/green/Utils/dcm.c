#include "dcm.h"
#include "Constants.h"
#include <math.h>

#include <string.h>

/*!
 * Get a specific element of a DCM
 * \param M is the DCM pointer
 * \param row is the row index
 * \param col is the column index
 * \return the value at <row, col>
 */
#define get(M, row, col) (M->data[(row)*3 + (col)])

/*!
 * Set a specific element of a DCM
 * \param M is the DCM pointer
 * \param row is the row index
 * \param col is the column index
 * \value is the new value to place at <row, col>
 */
#define set(M, row, col, value) (get(M, row, col) = (value))


/*!
 * Get a specific element of a dcm
 * \param M is the dcm pointer
 * \param row is the row index
 * \param col is the column index
 * \return the value at <row, col>
 */


/*! Get a specific element of a dcm, when all you have is the raw data
 * \param data is the dcm data pointer
 * \param row is the row index
 * \param col is the column index
 * \return the value at <row, col>
 */
float dcmGetFromRawData(const float* data, uint32_t row, uint32_t col)
{
	return data[row*3 + col];
}


/*!
 * Copy a direction cosine matrix. This function is faster than matrixCopyf()
 * since it uses a-priori knowledge about the size of the matrix.
 * \param A is the source DCM
 * \param B receives the copy of A. Only the DCM elements are copied since the
 *        size variables are assumed to be already correct.
 */
void dcmCopy(const DCM_t* A, DCM_t* B)
{
	memcpy(B->data, A->data, sizeof(float[9]));

}// dcmCopy


/*!
 * Set a direction cosine matrix to identity. This function is faster than
 * matrixIdentityf() since it uses a-priori knowledge about the size of
 * the matrix.
 * \param A is set to identity
 */


/*!
 * Add identity to a direction cosine matrix. This function is faster than
 * matrixAddIdentityf() since it uses a-priori knowledge about the size of
 * the matrix.
 * \param A has identity added to it
 */
void dcmAddIdentity(DCM_t* A)
{
	get(A, 0, 0) += 1;
	get(A, 1, 1) += 1;
	get(A, 2, 2) += 1;

}// dcmAddIdentity


/*!
 * Add two DCMs together, placing the result back into the first DCM. This is
 * faster than called matrixAddEqualsf() since it uses a-priori knowledge about
 * the size of the matrix.
 * \param A is a DCM to add, which also receives the result
 * \param B is a DCM to add
 */
void dcmAddEquals(DCM_t* A, const DCM_t* B)
{
	A->data[0] += B->data[0];
	A->data[1] += B->data[1];
	A->data[2] += B->data[2];
	A->data[3] += B->data[3];
	A->data[4] += B->data[4];
	A->data[5] += B->data[5];
	A->data[6] += B->data[6];
	A->data[7] += B->data[7];
	A->data[8] += B->data[8];
}


/*!
 * Scale all the terms of a direction cosine matrix. This function is faster
 * than matrixScalef() since it uses a-priori knowledge about the size of
 * the matrix.
 * \param A has all its terms scaled
 * \param scaler is the value to multiply by all the terms of A
 */
void dcmScale(DCM_t* A, float scaler)
{
	A->data[0] *= scaler;
	A->data[1] *= scaler;
	A->data[2] *= scaler;
	A->data[3] *= scaler;
	A->data[4] *= scaler;
	A->data[5] *= scaler;
	A->data[6] *= scaler;
	A->data[7] *= scaler;
	A->data[8] *= scaler;

}// dcmScale


/*!
 * Set a specific element of a dcm
 * \param M is the dcm pointer
 * \param row is the row index
 * \param col is the column index
 * \param value is the new value to place at <row, col>
 */


/*! Allocate a DCM, initializing its memory. The memory will be allocated
 * in a single step so all of the DCM's memory can be released by calling
 * free(DCM). The DCM will be set to identity.
 * \return a pointer to the newly allocated DCM, or
 *         NULL if the allocation failed.
 */
DCM_t* dcmAllocate(void)
{
    DCM_t* dcm = matrixAllocatef(3, 3);
    if(dcm != NULL)
    {
        // Make identity
        set(dcm, 0, 0, 1.0f);
        set(dcm, 1, 1, 1.0f);
        set(dcm, 2, 2, 1.0f);
    }

    return dcm;

}// dcmAllocate


/*!
 * Fill out the direction cosine matrix from an Euler roll angle
 * This DCM represents the local to global transform.
 * \param dcm is filled out according to the angle
 * \param roll is the Euler roll angle in radians
 */


/*!
 * Fill out the direction cosine matrix from an Euler pitch angle
 * This DCM represents the local to global transform.
 * \param dcm is filled out according to the angle
 * \param pitch is the Euler pitch angle in radians
 */


/*!
 * Fill out the direction cosine matrix from an Euler yaw angle
 * This DCM represents the local to global transform.
 * \param dcm is filled out according to the angle
 * \param yaw is the Euler yaw angle in radians
 */


/*!
 * Fill out the direction cosine matrix from an Euler, yaw, then pitch, then roll rotation.
 * This DCM represents the local to global transform.
 * \param dcm is filled out according to the angle.
 * \param yaw is the Euler yaw angle in radians
 * \param pitch is the Euler pitch angle in radians
 * \param roll is the Euler roll angle in radians
 */


/*!
 * Fill out the direction cosine matrix from a Pan then a Tilt rotation
 * \param dcm is filled out according to the angle.
 * \param pan is the pan angle in radians
 * \param tilt is the tilt angle in radians
 */


/*!
 * Compute the Euler yaw angle of a dcm.
 * \param dcm is the body to reference rotation matrix.
 * \return the Euler yaw angle in radians, from -PI to PI.
 */


/*!
 * Compute the Euler pitch rotation of a dcm.
 * \param dcm is the body to reference rotation matrix.
 * \return the Euler pitch angle in radians, from -PI/2 to PI/2.
 */


/*!
 * Compute the cosine of the Euler pitch angle of a DCM
 * \param dcm is the body to reference rotation matrix.
 * \return the cosine of the Euler pitch angle.
 */


/*!
 * Compute the sin of the Euler pitch angle of a DCM
 * \param dcm is the body to reference rotation matrix.
 * \return the sin of the Euler pitch angle.
 */


/*!
 * Compute the Euler roll rotation.
 * \param dcm is the body to reference rotation matrix.
 * \return the Euler roll angle in radians, from -PI to PI.
 */


/*!
 * Compute the cosine of the Euler roll angle of a DCM
 * \param dcm is the body to reference rotation matrix.
 * \return the cosine of the Euler roll angle.
 */


/*!
 * Compute the sin of the Euler roll angle of a DCM
 * \param dcm is the body to reference rotation matrix.
 * \return the sin of the Euler roll angle.
 */


/*!
 * Use a DCM to rotate a vector. The input and output vector can be the same vector
 * \param rotation is the DCM rotation matrix
 * \param input is the 3 element vector to be rotated.
 * \param output is the 3 element vector that receives the rotated result.
 */


/*!
 * Use a DCM to rotate a vector, in the reverse direction. The input and output
 * vector can be the same vector. This is equivalent to multiplying the input
 * by the transpose of the rotation matrix.
 * \param rotation is the DCM rotation matrix
 * \param input is the 3 element vector to be rotated.
 * \param output is the 3 element vector that receives the rotated result.
 */


/*!
 * Use a raw dcm to rotate a vector. The input and output vector can be the same vector
 * \param rotation is the DCM rotation matrix
 * \param input is the 3 element vector to be rotated.
 * \param output is the 3 element vector that receives the rotated result.
 */


/*!
 * Use a raw dcm to rotate a vector, in the reverse direction. The input and output
 * vector can be the same vector. This is equivalent to multiplying the input
 * by the transpose of the rotation matrix.
 * \param rotation is the DCM rotation matrix
 * \param input is the 3 element vector to be rotated.
 * \param output is the 3 element vector that receives the rotated result.
 */


/*!
 * Multiply two DCMs together. This is numerically equivalent to matrixMultiplyf(),
 * but faster because no dimension checking is done, no looping is done, and no
 * index computation is done.
 * \param A is the left side DCM.
 * \param B is the right side DCM.
 * \param C receives the result.
 */


/*!
 * Multiply two raw DCMs together. This is numerically equivalent to matrixMultiplyf(),
 * but faster because no dimension checking is done, no looping is done, and no
 * index computation is done.
 * \param Adata is the left side raw DCM.
 * \param Bdata is the right side raw DCM.
 * \param Cdata receives the result.
 */



/*!
 * Multiply the transpose of a DCM against another DCM. This is numerically
 * equivalent to matrixMultiplyTransAf(), but faster because no dimension
 * checking is done, no looping is done, and no index computation is done.
 * \param A is the left side DCM, whose transpose is used.
 * \param B is the right side DCM.
 * \param C receives the result.
 */
void dcmMultiplyTransA(const DCM_t* A, const DCM_t* B, DCM_t* C)
{
    const float* Adata = A->data;
    const float* Bdata = B->data;
    float* Cdata = C->data;

    // First row of C and A
    Cdata[0] = Adata[0]*Bdata[0] + Adata[3]*Bdata[3] + Adata[6]*Bdata[6];
    Cdata[1] = Adata[0]*Bdata[1] + Adata[3]*Bdata[4] + Adata[6]*Bdata[7];
    Cdata[2] = Adata[0]*Bdata[2] + Adata[3]*Bdata[5] + Adata[6]*Bdata[8];

    // Second row of C and A
    Cdata[3] = Adata[1]*Bdata[0] + Adata[4]*Bdata[3] + Adata[7]*Bdata[6];
    Cdata[4] = Adata[1]*Bdata[1] + Adata[4]*Bdata[4] + Adata[7]*Bdata[7];
    Cdata[5] = Adata[1]*Bdata[2] + Adata[4]*Bdata[5] + Adata[7]*Bdata[8];

    // Third row of C and A
    Cdata[6] = Adata[2]*Bdata[0] + Adata[5]*Bdata[3] + Adata[8]*Bdata[6];
    Cdata[7] = Adata[2]*Bdata[1] + Adata[5]*Bdata[4] + Adata[8]*Bdata[7];
    Cdata[8] = Adata[2]*Bdata[2] + Adata[5]*Bdata[5] + Adata[8]*Bdata[8];

}// dcmMultiplyTransA


/*!
 * Multiply a DCM against the transpose of another DCM. This is numerically
 * equivalent to matrixMultiplyTransBf(), but faster because no dimension
 * checking is done, no looping is done, and no index computation is done.
 * \param A is the left side DCM.
 * \param B is the right side DCM, whose transpose is used.
 * \param C receives the result.
 */
void dcmMultiplyTransB(const DCM_t* A, const DCM_t* B, DCM_t* C)
{
    const float* Adata = A->data;
    const float* Bdata = B->data;
    float* Cdata = C->data;

    // First row of C and A
    Cdata[0] = Adata[0]*Bdata[0] + Adata[1]*Bdata[1] + Adata[2]*Bdata[2];
    Cdata[1] = Adata[0]*Bdata[3] + Adata[1]*Bdata[4] + Adata[2]*Bdata[5];
    Cdata[2] = Adata[0]*Bdata[6] + Adata[1]*Bdata[7] + Adata[2]*Bdata[8];

    // Second row of C and A
    Cdata[3] = Adata[3]*Bdata[0] + Adata[4]*Bdata[1] + Adata[5]*Bdata[2];
    Cdata[4] = Adata[3]*Bdata[3] + Adata[4]*Bdata[4] + Adata[5]*Bdata[5];
    Cdata[5] = Adata[3]*Bdata[6] + Adata[4]*Bdata[7] + Adata[5]*Bdata[8];

    // Third row of C and A
    Cdata[6] = Adata[6]*Bdata[0] + Adata[7]*Bdata[1] + Adata[8]*Bdata[2];
    Cdata[7] = Adata[6]*Bdata[3] + Adata[7]*Bdata[4] + Adata[8]*Bdata[5];
    Cdata[8] = Adata[6]*Bdata[6] + Adata[7]*Bdata[7] + Adata[8]*Bdata[8];

}// dcmMultiplyTransB


/*!
 * Transpose a DCM in place
 * \param A is the DCM to transpose
 */
void dcmTransposeInPlace(DCM_t* A)
{
	float* Adata = A->data;
	float temp;

	// (0, 1) swaps with (1, 0)
	temp = Adata[1];
	Adata[1] = Adata[3];
	Adata[3] = temp;

	// (0, 2) swaps with (2, 0)
	temp = Adata[2];
	Adata[2] = Adata[6];
	Adata[6] = temp;

	// (1, 2) swaps with (2, 1)
	temp = Adata[5];
	Adata[5] = Adata[7];
	Adata[7] = temp;

}// dcmTransposeInPlace


/*!
 *  Add two DCMs together and multiply each element by 0.5. This might be
 *  faster than using separate Add() and Scale() functions since the compiler
 *  can utilize a multiply-accumulate instruction. This is faster than
 *  matrixAveragef() since the matrix size is known a-priori. Note that
 *  average in place can be done if C points to the same matrix as A or B.
 * \param A is a matrix to average
 * \param B is a matrix to average
 * \param C receives the result
 */
void dcmAverage(const DCM_t* A, const DCM_t* B, DCM_t* C)
{
	set(C, 0, 0, 0.5f*(get(A, 0, 0) + get(B, 0, 0)));
	set(C, 0, 1, 0.5f*(get(A, 0, 1) + get(B, 0, 1)));
	set(C, 0, 2, 0.5f*(get(A, 0, 2) + get(B, 0, 2)));

	set(C, 1, 0, 0.5f*(get(A, 1, 0) + get(B, 1, 0)));
	set(C, 1, 1, 0.5f*(get(A, 1, 1) + get(B, 1, 1)));
	set(C, 1, 2, 0.5f*(get(A, 1, 2) + get(B, 1, 2)));

	set(C, 2, 0, 0.5f*(get(A, 2, 0) + get(B, 2, 0)));
	set(C, 2, 1, 0.5f*(get(A, 2, 1) + get(B, 2, 1)));
	set(C, 2, 2, 0.5f*(get(A, 2, 2) + get(B, 2, 2)));

}// dcmAverage


/*!
 * Convert a 3 element column vector to a skew symmetric DCM
 * \param dcm receives the 3x3 skew symmetric matrix
 * \param vector is the X, Y, Z column vector
 */
void vectorSkewSymmetric(DCM_t* dcm, const float vector[])
{
    skewSymmetric(dcm, vector[0], vector[1], vector[2]);

}// vectorSkewSymmetric


/*!
 * Convert 3 elements to a skew symmetric DCM
 * \param dcm receives the 3x3 skew symmetric vector
 * \param x is the first element of the column vector
 * \param y is the second element of the column vector
 * \param z is the third element of the column vector
 */
void skewSymmetric(DCM_t* dcm, float x, float y, float z)
{
    set(dcm, 0, 0, 0.0f);set(dcm, 0, 1, -z);   set(dcm, 0, 2,  y);
    set(dcm, 1, 0,  z);  set(dcm, 1, 1, 0.0f); set(dcm, 1, 2, -x);
    set(dcm, 2, 0, -y);  set(dcm, 2, 1,  x);   set(dcm, 2, 2, 0.0f);

}// skewSymmetric


/*!
 * Convert a 3 element column vector to a skew symmetric DCM with 1s on the diagonal
 * \param dcm receives the DCM
 * \param vector is the X, Y, Z column vector
 */
void vectorAttitudeIncrement(DCM_t* dcm, const float vector[])
{
	attitudeIncrement(dcm, vector[0], vector[1], vector[2]);

}// vectorAttitudeIncrement


/*!
 * Convert a 3 elements to a skew symmetric DCM with 1s on the diagonal. This
 * is typically used to propagate a DCM with a new set of delta angles.
 * \param dcm receives the DCM
 * \param x is the first element of the column vector
 * \param y is the second element of the column vector
 * \param z is the third element of the column vector
 */
void attitudeIncrement(DCM_t* dcm, float x, float y, float z)
{
	set(dcm, 0, 0, 1.0f);set(dcm, 0, 1, -z);  set(dcm, 0, 2,  y);
	set(dcm, 1, 0,  z);  set(dcm, 1, 1, 1.0f);set(dcm, 1, 2, -x);
	set(dcm, 2, 0, -y);  set(dcm, 2, 1,  x);  set(dcm, 2, 2, 1.0f);

}// attitudeIncrement


/*!
 * Convert a 3 elements to a skew symmetric DCM with 1s on the diagonal. This
 * is typically used to propagate a DCM with a new set of delta angles. This
 * function uses the sin and cosine of the z (yaw) term
 * \param dcm receives the DCM
 * \param x is the small rotation in radians about the x axis
 * \param y is the small rotation in radians about the y axis
 * \param z is the rotation in radians about the z axis
 */
void attitudeIncrementBigYaw(DCM_t* dcm, float x, float y, float z)
{
    float sinz = sinf(z);
    float cosz = cosf(z);

    set(dcm, 0, 0, cosz); set(dcm, 0, 1, -sinz); set(dcm, 0, 2,  y);
    set(dcm, 1, 0, sinz); set(dcm, 1, 1,  cosz); set(dcm, 1, 2, -x);
    set(dcm, 2, 0, -y);   set(dcm, 2, 1,  x);    set(dcm, 2, 2, 1.0f);

}// attitudeIncrementBigYaw


/*!
 * Verify correct operation of key matrix and DCM operations.
 * \return TRUE if the test passed.
 */



/*!
 * Get a specific element of a dcm
 * \param M is the dcm pointer
 * \param row is the row index
 * \param col is the column index
 * \return the value at <row, col>
 */
double dcmdGet(const DCMd_t* M, uint32_t row, uint32_t col)
{
    return get(M, row, col);
}


/*! Get a specific element of a dcm, when all you have is the raw data
 * \param data is the dcm data pointer
 * \param row is the row index
 * \param col is the column index
 * \return the value at <row, col>
 */
double dcmdGetFromRawData(const double* data, uint32_t row, uint32_t col)
{
    return data[row*3 + col];
}


/*!
 * Copy a direction cosine matrix. This function is faster than matrixCopyf()
 * since it uses a-priori knowledge about the size of the matrix.
 * \param A is the source DCM
 * \param B receives the copy of A. Only the DCM elements are copied since the
 *        size variables are assumed to be already correct.
 */
void dcmdCopy(const DCMd_t* A, DCMd_t* B)
{
    memcpy(B->data, A->data, sizeof(double[9]));

}


/*!
 * Set a direction cosine matrix to identity. This function is faster than
 * matrixIdentityf() since it uses a-priori knowledge about the size of
 * the matrix.
 * \param A is set to identity
 */
void dcmdSetIdentity(DCMd_t* A)
{
    set(A, 0, 0, 1);
    set(A, 0, 1, 0);
    set(A, 0, 2, 0);

    set(A, 1, 0, 0);
    set(A, 1, 1, 1);
    set(A, 1, 2, 0);

    set(A, 2, 0, 0);
    set(A, 2, 1, 0);
    set(A, 2, 2, 1);

}


/*!
 * Add identity to a direction cosine matrix. This function is faster than
 * matrixAddIdentityf() since it uses a-priori knowledge about the size of
 * the matrix.
 * \param A has identity added to it
 */
void dcmdAddIdentity(DCMd_t* A)
{
    get(A, 0, 0) += 1;
    get(A, 1, 1) += 1;
    get(A, 2, 2) += 1;

}


/*!
 * Add two DCMs together, placing the result back into the first DCM. This is
 * faster than called matrixAddEqualsf() since it uses a-priori knowledge about
 * the size of the matrix.
 * \param A is a DCM to add, which also receives the result
 * \param B is a DCM to add
 */
void dcmdAddEquals(DCMd_t* A, const DCMd_t* B)
{
    A->data[0] += B->data[0];
    A->data[1] += B->data[1];
    A->data[2] += B->data[2];
    A->data[3] += B->data[3];
    A->data[4] += B->data[4];
    A->data[5] += B->data[5];
    A->data[6] += B->data[6];
    A->data[7] += B->data[7];
    A->data[8] += B->data[8];
}


/*!
 * Scale all the terms of a direction cosine matrix. This function is faster
 * than matrixScalef() since it uses a-priori knowledge about the size of
 * the matrix.
 * \param A has all its terms scaled
 * \param scaler is the value to multiply by all the terms of A
 */
void dcmdScale(DCMd_t* A, double scaler)
{
    A->data[0] *= scaler;
    A->data[1] *= scaler;
    A->data[2] *= scaler;
    A->data[3] *= scaler;
    A->data[4] *= scaler;
    A->data[5] *= scaler;
    A->data[6] *= scaler;
    A->data[7] *= scaler;
    A->data[8] *= scaler;
}


/*!
 * Set a specific element of a dcm
 * \param M is the dcm pointer
 * \param row is the row index
 * \param col is the column index
 * \param value is the new value to place at <row, col>
 */
void dcmdSet(DCMd_t* M, uint32_t row, uint32_t col, double value)
{
    set(M, row, col, value);
}


/*! Allocate a DCM, initializing its memory. The memory will be allocated
 * in a single step so all of the DCM's memory can be released by calling
 * free(DCM). The DCM will be set to identity.
 * \return a pointer to the newly allocated DCM, or
 *         NULL if the allocation failed.
 */
DCMd_t* dcmdAllocate(void)
{
    DCMd_t* dcm = matrixAllocate(3, 3);
    if(dcm != NULL)
    {
        // Make identity
        set(dcm, 0, 0, 1.0f);
        set(dcm, 1, 1, 1.0f);
        set(dcm, 2, 2, 1.0f);
    }

    return dcm;

}


/*!
 * Fill out the direction cosine matrix from an Euler roll angle
 * This DCM represents the local to global transform.
 * \param dcm is filled out according to the angle
 * \param roll is the Euler roll angle in radians
 */
void setDCMdBasedOnRoll(DCMd_t* dcm, double roll)
{
    double sinRoll = sin(roll);
    double cosRoll = cos(roll);

    dcmdSetIdentity(dcm);
    set(dcm, 1, 1,  cosRoll);
    set(dcm, 2, 2,  cosRoll);
    set(dcm, 1, 2, -sinRoll);
    set(dcm, 2, 1,  sinRoll);

}


/*!
 * Fill out the direction cosine matrix from an Euler pitch angle
 * This DCM represents the local to global transform.
 * \param dcm is filled out according to the angle
 * \param pitch is the Euler pitch angle in radians
 */
void setDCMdBasedOnPitch(DCMd_t* dcm, double pitch)
{
    double sinPitch = sin(pitch);
    double cosPitch = cos(pitch);

    dcmdSetIdentity(dcm);
    set(dcm, 0, 0,  cosPitch);
    set(dcm, 2, 2,  cosPitch);
    set(dcm, 0, 2,  sinPitch);
    set(dcm, 2, 0, -sinPitch);

}


/*!
 * Fill out the direction cosine matrix from an Euler yaw angle
 * This DCM represents the local to global transform.
 * \param dcm is filled out according to the angle
 * \param yaw is the Euler yaw angle in radians
 */
void setDCMdBasedOnYaw(DCMd_t* dcm, double yaw)
{
    double sinYaw = sin(yaw);
    double cosYaw = cos(yaw);

    dcmdSetIdentity(dcm);
    set(dcm, 0, 0,  cosYaw);
    set(dcm, 1, 1,  cosYaw);
    set(dcm, 0, 1, -sinYaw);
    set(dcm, 1, 0,  sinYaw);

}


/*!
 * Fill out the direction cosine matrix from an Euler, yaw, then pitch, then roll rotation.
 * This DCM represents the local to global transform.
 * \param dcm is filled out according to the angle.
 * \param yaw is the Euler yaw angle in radians
 * \param pitch is the Euler pitch angle in radians
 * \param roll is the Euler roll angle in radians
 */
void setDCMdBasedOnEuler(DCMd_t* dcm, double yaw, double pitch, double roll)
{
    double cosRoll = cos(roll);
    double sinRoll = sin(roll);
    double cosPitch = cos(pitch);
    double sinPitch = sin(pitch);
    double cosYaw = cos(yaw);
    double sinYaw = sin(yaw);

    set(dcm, 0, 0, cosPitch*cosYaw);
    set(dcm, 0, 1, sinRoll*sinPitch*cosYaw - cosRoll*sinYaw);
    set(dcm, 0, 2, cosRoll*sinPitch*cosYaw + sinRoll*sinYaw);
    set(dcm, 1, 0, cosPitch*sinYaw);
    set(dcm, 1, 1, sinRoll*sinPitch*sinYaw + cosRoll*cosYaw);
    set(dcm, 1, 2, cosRoll*sinPitch*sinYaw - sinRoll*cosYaw);
    set(dcm, 2, 0, -sinPitch);
    set(dcm, 2, 1, sinRoll*cosPitch);
    set(dcm, 2, 2, cosRoll*cosPitch);

}

/*!
 * Fill out the direction cosine matrix from a Pan then a Tilt rotation
 * \param dcm is filled out according to the angle.
 * \param pan is the pan angle in radians
 * \param tilt is the tilt angle in radians
 */
void setDCMdBasedOnPanTilt(DCMd_t* dcm, double pan, double tilt)
{
    // Pan and Tilt are equivalent to the an Euler yaw and pitch
    double cosPitch = cos(tilt);
    double sinPitch = sin(tilt);
    double cosYaw = cos(pan);
    double sinYaw = sin(pan);

    set(dcm, 0, 0, cosPitch*cosYaw);
    set(dcm, 0, 1, -sinYaw);
    set(dcm, 0, 2, sinPitch*cosYaw);
    set(dcm, 1, 0, cosPitch*sinYaw);
    set(dcm, 1, 1, cosYaw);
    set(dcm, 1, 2, sinPitch*sinYaw);
    set(dcm, 2, 0, -sinPitch);
    set(dcm, 2, 1, 0);
    set(dcm, 2, 2, cosPitch);

}


/*!
 * Compute the Euler yaw angle of a dcm.
 * \param dcm is the body to reference rotation matrix.
 * \return the Euler yaw angle in radians, from -PI to PI.
 */
double dcmdYaw(const DCMd_t* dcm)
{
    return atan2(get(dcm, 1, 0), get(dcm, 0, 0));

}


/*!
 * Compute the Euler pitch rotation of a dcm.
 * \param dcm is the body to reference rotation matrix.
 * \return the Euler pitch angle in radians, from -PI/2 to PI/2.
 */
double dcmdPitch(const DCMd_t* dcm)
{
    return asin(dcmdSinPitch(dcm));

}


/*!
 * Compute the cosine of the Euler pitch angle of a DCM
 * \param dcm is the body to reference rotation matrix.
 * \return the cosine of the Euler pitch angle.
 */
double dcmdCosPitch(const DCMd_t* dcm)
{
    double sinp = dcmdSinPitch(dcm);

    // pitch goes from -90 to 90, so cosine of pitch must be positive.
    return sqrt(1.0 - sinp*sinp);

}


/*!
 * Compute the sin of the Euler pitch angle of a DCM
 * \param dcm is the body to reference rotation matrix.
 * \return the sin of the Euler pitch angle.
 */
double dcmdSinPitch(const DCMd_t* dcm)
{
    return SATURATE(-1.0*get(dcm, 2, 0), 1.0);
}


/*!
 * Compute the Euler roll rotation.
 * \param dcm is the body to reference rotation matrix.
 * \return the Euler roll angle in radians, from -PI to PI.
 */
double dcmdRoll(const DCMd_t* dcm)
{
    return atan2(get(dcm, 2, 1), get(dcm, 2, 2));

}


/*!
 * Compute the cosine of the Euler roll angle of a DCM
 * \param dcm is the body to reference rotation matrix.
 * \return the cosine of the Euler roll angle.
 */
double dcmdCosRoll(const DCMd_t* dcm)
{
    return cos(dcmdRoll(dcm));
}


/*!
 * Compute the sin of the Euler roll angle of a DCM
 * \param dcm is the body to reference rotation matrix.
 * \return the sin of the Euler roll angle.
 */
double dcmdSinRoll(const DCMd_t* dcm)
{
    return sin(dcmdRoll(dcm));
}


/*!
 * Use a DCM to rotate a vector. The input and output vector can be the same vector
 * \param rotation is the DCM rotation matrix
 * \param input is the 3 element vector to be rotated.
 * \param output is the 3 element vector that receives the rotated result.
 */
void dcmdApplyRotation(const DCMd_t* rotation, const double input[], double output[])
{
    rawdcmdApplyRotation(rotation->data, input, output);

}// dcmApplyRotation


/*!
 * Use a DCM to rotate a vector, in the reverse direction. The input and output
 * vector can be the same vector. This is equivalent to multiplying the input
 * by the transpose of the rotation matrix.
 * \param rotation is the DCM rotation matrix
 * \param input is the 3 element vector to be rotated.
 * \param output is the 3 element vector that receives the rotated result.
 */
void dcmdApplyReverseRotation(const DCMd_t* rotation, const double input[], double output[])
{
    rawdcmdApplyReverseRotation(rotation->data, input, output);

}


/*!
 * Use a raw dcm to rotate a vector. The input and output vector can be the same vector
 * \param rotation is the DCM rotation matrix
 * \param input is the 3 element vector to be rotated.
 * \param output is the 3 element vector that receives the rotated result.
 */
void rawdcmdApplyRotation(const double dcmdata[], const double input[], double output[])
{
    // Doing it this way makes it possible for input and output to be the same vector
    double zero = dcmdata[0]*input[0] + dcmdata[1]*input[1] + dcmdata[2]*input[2];
    double one  = dcmdata[3]*input[0] + dcmdata[4]*input[1] + dcmdata[5]*input[2];
    double two  = dcmdata[6]*input[0] + dcmdata[7]*input[1] + dcmdata[8]*input[2];
    output[0] = zero;
    output[1] = one;
    output[2] = two;

}


/*!
 * Use a raw dcm to rotate a vector, in the reverse direction. The input and output
 * vector can be the same vector. This is equivalent to multiplying the input
 * by the transpose of the rotation matrix.
 * \param rotation is the DCM rotation matrix
 * \param input is the 3 element vector to be rotated.
 * \param output is the 3 element vector that receives the rotated result.
 */
void rawdcmdApplyReverseRotation(const double dcmdata[], const double input[], double output[])
{
    // Doing it this way makes it possible for input and output to be the same vector
    double zero = dcmdata[0]*input[0] + dcmdata[3]*input[1] + dcmdata[6]*input[2];
    double one  = dcmdata[1]*input[0] + dcmdata[4]*input[1] + dcmdata[7]*input[2];
    double two  = dcmdata[2]*input[0] + dcmdata[5]*input[1] + dcmdata[8]*input[2];
    output[0] = zero;
    output[1] = one;
    output[2] = two;

}


/*!
 * Multiply two DCMs together. This is numerically equivalent to matrixMultiplyf(),
 * but faster because no dimension checking is done, no looping is done, and no
 * index computation is done.
 * \param A is the left side DCM.
 * \param B is the right side DCM.
 * \param C receives the result.
 */
void dcmdMultiply(const DCMd_t* A, const DCMd_t* B, DCMd_t* C)
{
    rawdcmdMultiply(A->data, B->data, C->data);

}


/*!
 * Multiply two raw DCMs together. This is numerically equivalent to matrixMultiplyf(),
 * but faster because no dimension checking is done, no looping is done, and no
 * index computation is done.
 * \param Adata is the left side raw DCM.
 * \param Bdata is the right side raw DCM.
 * \param Cdata receives the result.
 */
void rawdcmdMultiply(const double Adata[9], const double Bdata[9], double Cdata[9])
{
    // First row of C and A
    Cdata[0] = Adata[0]*Bdata[0] + Adata[1]*Bdata[3] + Adata[2]*Bdata[6];
    Cdata[1] = Adata[0]*Bdata[1] + Adata[1]*Bdata[4] + Adata[2]*Bdata[7];
    Cdata[2] = Adata[0]*Bdata[2] + Adata[1]*Bdata[5] + Adata[2]*Bdata[8];

    // Second row of C and A
    Cdata[3] = Adata[3]*Bdata[0] + Adata[4]*Bdata[3] + Adata[5]*Bdata[6];
    Cdata[4] = Adata[3]*Bdata[1] + Adata[4]*Bdata[4] + Adata[5]*Bdata[7];
    Cdata[5] = Adata[3]*Bdata[2] + Adata[4]*Bdata[5] + Adata[5]*Bdata[8];

    // Third row of C and A
    Cdata[6] = Adata[6]*Bdata[0] + Adata[7]*Bdata[3] + Adata[8]*Bdata[6];
    Cdata[7] = Adata[6]*Bdata[1] + Adata[7]*Bdata[4] + Adata[8]*Bdata[7];
    Cdata[8] = Adata[6]*Bdata[2] + Adata[7]*Bdata[5] + Adata[8]*Bdata[8];

}



/*!
 * Multiply the transpose of a DCM against another DCM. This is numerically
 * equivalent to matrixMultiplyTransAf(), but faster because no dimension
 * checking is done, no looping is done, and no index computation is done.
 * \param A is the left side DCM, whose transpose is used.
 * \param B is the right side DCM.
 * \param C receives the result.
 */
void dcmdMultiplyTransA(const DCMd_t* A, const DCMd_t* B, DCMd_t* C)
{
    const double* Adata = A->data;
    const double* Bdata = B->data;
    double* Cdata = C->data;

    // First row of C and A
    Cdata[0] = Adata[0]*Bdata[0] + Adata[3]*Bdata[3] + Adata[6]*Bdata[6];
    Cdata[1] = Adata[0]*Bdata[1] + Adata[3]*Bdata[4] + Adata[6]*Bdata[7];
    Cdata[2] = Adata[0]*Bdata[2] + Adata[3]*Bdata[5] + Adata[6]*Bdata[8];

    // Second row of C and A
    Cdata[3] = Adata[1]*Bdata[0] + Adata[4]*Bdata[3] + Adata[7]*Bdata[6];
    Cdata[4] = Adata[1]*Bdata[1] + Adata[4]*Bdata[4] + Adata[7]*Bdata[7];
    Cdata[5] = Adata[1]*Bdata[2] + Adata[4]*Bdata[5] + Adata[7]*Bdata[8];

    // Third row of C and A
    Cdata[6] = Adata[2]*Bdata[0] + Adata[5]*Bdata[3] + Adata[8]*Bdata[6];
    Cdata[7] = Adata[2]*Bdata[1] + Adata[5]*Bdata[4] + Adata[8]*Bdata[7];
    Cdata[8] = Adata[2]*Bdata[2] + Adata[5]*Bdata[5] + Adata[8]*Bdata[8];

}


/*!
 * Multiply a DCM against the transpose of another DCM. This is numerically
 * equivalent to matrixMultiplyTransBf(), but faster because no dimension
 * checking is done, no looping is done, and no index computation is done.
 * \param A is the left side DCM.
 * \param B is the right side DCM, whose transpose is used.
 * \param C receives the result.
 */
void dcmdMultiplyTransB(const DCMd_t* A, const DCMd_t* B, DCMd_t* C)
{
    const double* Adata = A->data;
    const double* Bdata = B->data;
    double* Cdata = C->data;

    // First row of C and A
    Cdata[0] = Adata[0]*Bdata[0] + Adata[1]*Bdata[1] + Adata[2]*Bdata[2];
    Cdata[1] = Adata[0]*Bdata[3] + Adata[1]*Bdata[4] + Adata[2]*Bdata[5];
    Cdata[2] = Adata[0]*Bdata[6] + Adata[1]*Bdata[7] + Adata[2]*Bdata[8];

    // Second row of C and A
    Cdata[3] = Adata[3]*Bdata[0] + Adata[4]*Bdata[1] + Adata[5]*Bdata[2];
    Cdata[4] = Adata[3]*Bdata[3] + Adata[4]*Bdata[4] + Adata[5]*Bdata[5];
    Cdata[5] = Adata[3]*Bdata[6] + Adata[4]*Bdata[7] + Adata[5]*Bdata[8];

    // Third row of C and A
    Cdata[6] = Adata[6]*Bdata[0] + Adata[7]*Bdata[1] + Adata[8]*Bdata[2];
    Cdata[7] = Adata[6]*Bdata[3] + Adata[7]*Bdata[4] + Adata[8]*Bdata[5];
    Cdata[8] = Adata[6]*Bdata[6] + Adata[7]*Bdata[7] + Adata[8]*Bdata[8];

}


/*!
 * Transpose a DCM in place
 * \param A is the DCM to transpose
 */
void dcmdTransposeInPlace(DCMd_t* A)
{
    double* Adata = A->data;
    double temp;

    // (0, 1) swaps with (1, 0)
    temp = Adata[1];
    Adata[1] = Adata[3];
    Adata[3] = temp;

    // (0, 2) swaps with (2, 0)
    temp = Adata[2];
    Adata[2] = Adata[6];
    Adata[6] = temp;

    // (1, 2) swaps with (2, 1)
    temp = Adata[5];
    Adata[5] = Adata[7];
    Adata[7] = temp;

}


/*!
 *  Add two DCMs together and multiply each element by 0.5. This might be
 *  faster than using separate Add() and Scale() functions since the compiler
 *  can utilize a multiply-accumulate instruction. This is faster than
 *  matrixAveragef() since the matrix size is known a-priori. Note that
 *  average in place can be done if C points to the same matrix as A or B.
 * \param A is a matrix to average
 * \param B is a matrix to average
 * \param C receives the result
 */
void dcmdAverage(const DCMd_t* A, const DCMd_t* B, DCMd_t* C)
{
    set(C, 0, 0, 0.5*(get(A, 0, 0) + get(B, 0, 0)));
    set(C, 0, 1, 0.5*(get(A, 0, 1) + get(B, 0, 1)));
    set(C, 0, 2, 0.5*(get(A, 0, 2) + get(B, 0, 2)));

    set(C, 1, 0, 0.5*(get(A, 1, 0) + get(B, 1, 0)));
    set(C, 1, 1, 0.5*(get(A, 1, 1) + get(B, 1, 1)));
    set(C, 1, 2, 0.5*(get(A, 1, 2) + get(B, 1, 2)));

    set(C, 2, 0, 0.5*(get(A, 2, 0) + get(B, 2, 0)));
    set(C, 2, 1, 0.5*(get(A, 2, 1) + get(B, 2, 1)));
    set(C, 2, 2, 0.5*(get(A, 2, 2) + get(B, 2, 2)));

}


/*!
 * Convert a 3 element column vector to a skew symmetric DCM
 * \param dcm receives the 3x3 skew symmetric matrix
 * \param vector is the X, Y, Z column vector
 */
void vectorSkewSymmetricd(DCMd_t* dcm, const double vector[])
{
    skewSymmetricd(dcm, vector[0], vector[1], vector[2]);

}


/*!
 * Convert 3 elements to a skew symmetric DCM
 * \param dcm receives the 3x3 skew symmetric vector
 * \param x is the first element of the column vector
 * \param y is the second element of the column vector
 * \param z is the third element of the column vector
 */
void skewSymmetricd(DCMd_t* dcm, double x, double y, double z)
{
    set(dcm, 0, 0, 0.0); set(dcm, 0, 1, -z);  set(dcm, 0, 2,  y);
    set(dcm, 1, 0,  z);  set(dcm, 1, 1, 0.0); set(dcm, 1, 2, -x);
    set(dcm, 2, 0, -y);  set(dcm, 2, 1,  x);  set(dcm, 2, 2, 0.0);

}


/*!
 * Convert a 3 element column vector to a skew symmetric DCM with 1s on the diagonal
 * \param dcm receives the DCM
 * \param vector is the X, Y, Z column vector
 */
void vectorAttitudeIncrementd(DCMd_t* dcm, const double vector[])
{
    attitudeIncrementd(dcm, vector[0], vector[1], vector[2]);

}


/*!
 * Convert a 3 elements to a skew symmetric DCM with 1s on the diagonal. This
 * is typically used to propagate a DCM with a new set of delta angles.
 * \param dcm receives the DCM
 * \param x is the first element of the column vector
 * \param y is the second element of the column vector
 * \param z is the third element of the column vector
 */
void attitudeIncrementd(DCMd_t* dcm, double x, double y, double z)
{
    set(dcm, 0, 0, 1.0); set(dcm, 0, 1, -z);  set(dcm, 0, 2,  y);
    set(dcm, 1, 0,  z);  set(dcm, 1, 1, 1.0); set(dcm, 1, 2, -x);
    set(dcm, 2, 0, -y);  set(dcm, 2, 1,  x);  set(dcm, 2, 2, 1.0);

}


/*!
 * Convert a 3 elements to a skew symmetric DCM with 1s on the diagonal. This
 * is typically used to propagate a DCM with a new set of delta angles. This
 * function uses the sin and cosine of the z (yaw) term
 * \param dcm receives the DCM
 * \param x is the small rotation in radians about the x axis
 * \param y is the small rotation in radians about the y axis
 * \param z is the rotation in radians about the z axis
 */
void attitudeIncrementBigYawd(DCMd_t* dcm, double x, double y, double z)
{
    double sinz = sin(z);
    double cosz = cos(z);

    set(dcm, 0, 0, cosz); set(dcm, 0, 1, -sinz); set(dcm, 0, 2,  y);
    set(dcm, 1, 0, sinz); set(dcm, 1, 1,  cosz); set(dcm, 1, 2, -x);
    set(dcm, 2, 0, -y);   set(dcm, 2, 1,  x);    set(dcm, 2, 2, 1.0);

}
