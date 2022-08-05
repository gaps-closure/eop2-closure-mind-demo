#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H

/*!
 * \file
 * This module contains routine for doing linear algebra in C. There are six types of data here:
 * - Vectors whose length are 3 elements (a simple array). "vector3"
 * - Vectors whose length is arbitrary. "Vector_t"
 * - Matrices whose row and column dimensions are arbitrary. "Matrix_t"
 * - And single precision versions of the above.
 * To avoid unnecessary dynamic memory allocation special macros are used to
 * declare and initialize the Vector_t and Matrix_t types.
 */

#include "Types.h"

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

//! Enumeration for a three dimensional vector
enum
{
    VECTOR3X,
    VECTOR3Y,
    VECTOR3Z,
    NVECTOR3
};

//! Set all elements of a vector3 to a specific value

//! Copy one vector to another
const double* vector3Copy(const double source[NVECTOR3], double dest[NVECTOR3]);

//! Multiply and accumulate two vectors as result = a + b*scale.

//! Sum two three dimensional vectors together.
const double* vector3Sum(const double a[NVECTOR3], const double b[NVECTOR3], double result[NVECTOR3]);

//! Subtract one three dimensional vector from another.
const double* vector3Difference(const double left[NVECTOR3], const double right[NVECTOR3], double result[NVECTOR3]);

//! Multiply two vectors together element-wise

//! Compute the dot product of two three dimensional vectors
double vector3Dot(const double a[NVECTOR3], const double b[NVECTOR3]);

//! Compute the angle between two three dimensional vectors
double vector3AngleBetween(const double a[NVECTOR3], const double b[NVECTOR3]);

//! Cross one three dimensional vector against another.

//! Compute the square of the length of a three dimensional vector
double vector3LengthSquared(const double vector[NVECTOR3]);

//! Compute the length of a three dimensional vector
double vector3Length(const double vector[NVECTOR3]);

//! Change the length of a vector. This is faster than making a unit vector and then scaling.
const double* vector3ChangeLength(const double vector[NVECTOR3], double result[NVECTOR3], double newlength);

//! Scale a three dimensional vector
const double* vector3Scale(const double vector[NVECTOR3], double result[NVECTOR3], double scale);

//! Scale a three dimensional vector to unit length.
const double* vector3Unit(const double vector[NVECTOR3], double result[NVECTOR3]);

//! Convert a double-precision vector to single precision
const float *vector3Convert(const double vector[NVECTOR3], float result[NVECTOR3]);

//! Compute the absolute value of all three elements in a vector

//! Get the largest element in a vector
#define vector3Max(vector)  MAX(vector[VECTOR3X], MAX(vector[VECTOR3Y], vector[VECTOR3Z]))

//! Get the smallest element in a vector
#define vector3Min(vector)  MIN(vector[VECTOR3X], MIN(vector[VECTOR3Y], vector[VECTOR3Z]))


//! The vector structure
typedef struct
{
    uint32_t num;   //!< number of elements of the vector
    double* data;   //!< pointer to the vector data

}Vector_t;


/*! Macro to allocate a vector statically. The vector elements are not initialized.
 * \param V is the name used to refer to the vector.
 * \param num is the number of elements.
 */
#define staticAllocateVector(V, num) static double V##data[(num)]; static Vector_t V = {(num), V##data}

/*! Macro to allocate a vector on the stack. The vector elements are not initialized.
 * \param V is the name used to refer to the vector.
 * \param num is the number of elements.
 */
#define stackAllocateVector(V, num) double V##data[(num)]; Vector_t V = {(num), V##data}

/*! Macro to allocate a vector as part of a structure. The vector MUST be setup with structInitVector()
 * \param V is the name used to refer to the vector.
 * \param num is the number of elements.
 */
#define structAllocateVector(V, num) double V##data[(num)]; Vector_t V

/*! Macro to setup a vector that was previously named in a struct using structAllocateVector()
 * \param V is the name used to refer to the vector.
 * \param num is the number of elements.
 */
#define structInitVector(V, num) V.data = V##data; V.num = (num)

//! Get a specific element of a vector

//! Set a specific element of a vector

//! Add a scalar to a specific element of the vector

//! Set the contents of a vector

//! Allocate a vector, initializing its memory

//! Change the size of a dynamically allocated vector

//! Change the size of a vector

//! Set all elements of a vector to zero

//! Copy a vector

//! Multiply and accumulate two vectors as result = a + b*scale.

//! Sum two three dimensional vectors together.

//! Subtract one three dimensional vector from another.

//! Multiply two vectors together element-wise

//! Compute the dot product of two three dimensional vectors

//! Compute the square of the length of a three dimensional vector

//! Compute the length of a three dimensional vector

//! Change the length of a vector. This is faster than making a unit vector and then scaling.

//! Scale a three dimensional vector

//! Scale a three dimensional vector to unit length.

//! Compute the absolute value of all three elements in a vector

//! Get the largest element in a vector

//! Get the smallest element in a vector

//! The matrix structure which holds data in row major format
typedef struct
{
    uint32_t numRows;   //!< number of rows of the matrix
    uint32_t numCols;   //!< number of columns of the matrix
    double* data;       //!< pointer to the matrix data in row major format

}Matrix_t;


/*! Macro to allocate a matrix statically. The matrix elements are not initialized.
 * \param M is the name used to refer to the matrix.
 * \param rows is the number of rows.
 * \param cols is the number of columns.
 */
#define staticAllocateMatrix(M, rows, cols) static double M##data[(rows)*(cols)]; static Matrix_t M = {(rows), (cols), M##data}

/*! Macro to allocate a matrix on the stack. The matrix elements are not initialized.
 * \param M is the name used to refer to the matrix.
 * \param rows is the number of rows.
 * \param cols is the number of columns.
 */
#define stackAllocateMatrix(M, rows, cols) double M##data[(rows)*(cols)]; Matrix_t M = {(rows), (cols), M##data}

/*! Macro to allocate a matrix as part of a structure. The matrix MUST be setup with structInitMatrix()
 * \param M is the name used to refer to the DCM.
 * \param rows is the number of rows.
 * \param cols is the number of columns.
 */
#define structAllocateMatrix(M, rows, cols) double M##data[(rows)*(cols)]; Matrix_t M

/*! Macro to setup a DCM that was previously named in a struct using structAllocateDCM()
 * \param M is the name used to refer to the DCM.
 * \param rows is the number of rows.
 * \param cols is the number of columns.
 */
#define structInitMatrix(M, rows, cols) M.data = M##data; M.numRows = (rows); M.numCols = (cols)

//! Get a specific element of a matrix

//! Set a specific element of a matrix

//! Add a scalar to a specific element of the matrix

//! Set an entire row of a matrix

//! Set an entire column of a matrix

//! Allocate a matrix, initializing its memory

//! Change the size of a matrix

//! Change the size of a matrix

//! Set all elements of a matrix to zero

//! Set this matrix to be identity

//! Copy a matrix

//! Multiply two matrices together

//! Multiply the transpose of the left matrix against the right matrix

//! Multiply the left matrix against the transpose of the right matrix

//! Multiply a vector against a matrix

//! Multiply a vector against the transpose of a matrix

//! Add two matrices together

//! Add two matrices together, placing the result back into the first matrix.

//! Scale a matrix

//! Add two matrices together and multiply each element by 0.5.

//! Add identity to a matrix

//! Subtract identity from a matrix

//! Subtract a matrix from the identity matrix

//! Compute the dot product of two rows of a matrix

//! Compute the transpose of a matrix

//! Calculate the inverse of a square matrix A, for dimensions 1x2, 2x2, 3x3

//! Test a matrix for its error to identity

//! Test a matrix for its error to null

//! Evaluate the derivative of quadratic equation at x

//! Evaluate a quadratic equation with 3 coefficients at x

//! Solve a quadratic regression to determine the coefficients c, b, and a.

//! Set all elements of a vector3 to a specific value

//! Copy one vector to another

//! Multiply and accumulate two vectors as result = a + b*scale.

//! Sum two three dimensional vectors together.
const float* vector3Sumf(const float a[NVECTOR3], const float b[NVECTOR3], float result[NVECTOR3]);

//! Subtract one three dimensional vector from another.

//! Multiply two vectors together element-wise

//! Compute the dot product of two three dimensional vectors
float vector3Dotf(const float a[NVECTOR3], const float b[NVECTOR3]);

//! Compute the angle between two three dimensional vectors
float vector3AngleBetweenf(const float a[NVECTOR3], const float b[NVECTOR3]);

//! Cross one three dimensional vector against another.

//! Compute the square of the length of a three dimensional vector
float vector3LengthSquaredf(const float vector[NVECTOR3]);

//! Compute the length of a three dimensional vector
float vector3Lengthf(const float vector[NVECTOR3]);

//! Change the length of a vector. This is faster than making a unit vector and then scaling.
const float* vector3ChangeLengthf(const float vector[NVECTOR3], float result[NVECTOR3], float newlength);

//! Scale a three dimensional vector
const float* vector3Scalef(const float vector[NVECTOR3], float result[NVECTOR3], float scale);

//! Scale a three dimensional vector to unit length.
const float* vector3Unitf(const float vector[NVECTOR3], float result[NVECTOR3]);

//! Convert a double-precision vector to single precision
const double *vector3Convertf(const float vector[NVECTOR3], double result[NVECTOR3]);

//! Compute the absolute value of all three elements in a vector

//! Get the largest element in a vector
#define vector3Maxf(vector) MAX(vector[VECTOR3X], MAX(vector[VECTOR3Y], vector[VECTOR3Z]))

//! Get the smallest element in a vector
#define vector3Minf(vector) MIN(vector[VECTOR3X], MIN(vector[VECTOR3Y], vector[VECTOR3Z]))


//! The vector structure
typedef struct
{
    uint32_t num;   //!< number of elements of the vector
    float* data;   //!< pointer to the vector data

}Vectorf_t;


/*! Macro to allocate a vector statically. The vector elements are not initialized.
 * \param V is the name used to refer to the vector.
 * \param num is the number of elements.
 */
#define staticAllocateVectorf(V, num) static float V##data[(num)]; static Vectorf_t V = {(num), V##data}

/*! Macro to allocate a vector on the stack. The vector elements are not initialized.
 * \param V is the name used to refer to the vector.
 * \param num is the number of elements.
 */
#define stackAllocateVectorf(V, num) float V##data[(num)]; Vectorf_t V = {(num), V##data}

/*! Macro to allocate a vector as part of a structure. The vector MUST be setup with structInitVector()
 * \param V is the name used to refer to the vector.
 * \param num is the number of elements.
 */
#define structAllocateVectorf(V, num) float V##data[(num)]; Vectorf_t V

//! Get a specific element of a vector

//! Set a specific element of a vector

//! Add a scalar to a specific element of the vector

//! Set the contents of a vector

//! Allocate a vector, initializing its memory

//! Set all elements of a vector to zero

//! Copy a vector

//! Multiply and accumulate two vectors as result = a + b*scale.

//! Sum two three dimensional vectors together.

//! Subtract one three dimensional vector from another.

//! Multiply two vectors together element-wise

//! Compute the dot product of two three dimensional vectors

//! Compute the square of the length of a three dimensional vector

//! Compute the length of a three dimensional vector

//! Change the length of a vector. This is faster than making a unit vector and then scaling.

//! Scale a three dimensional vector

//! Scale a three dimensional vector to unit length.

//! Compute the absolute value of all three elements in a vector

//! Get the largest element in a vector

//! Get the smallest element in a vector

//! Change the size of a dynamically allocated vector

//! Change the size of a vector


//! The matrix structure which holds data in row major format
typedef struct
{
    uint32_t numRows;   //!< number of rows of the matrix
    uint32_t numCols;   //!< number of columns of the matrix
    float* data;        //!< pointer to the matrix data in row major format

}Matrixf_t;

/*! Macro to allocate a matrix statically. The matrix elements are not initialized.
 * \param M is the name used to refer to the matrix.
 * \param rows is the number of rows.
 * \param cols is the number of columns.
 */
#define staticAllocateMatrixf(M, rows, cols) static float M##data[(rows)*(cols)]; static Matrixf_t M = {(rows), (cols), M##data}

/*! Macro to allocate a matrix on the stack. The matrix elements are not initialized.
 * \param M is the name used to refer to the matrix.
 * \param rows is the number of rows.
 * \param cols is the number of columns.
 */
#define stackAllocateMatrixf(M, rows, cols) float M##data[(rows)*(cols)]; Matrixf_t M = {(rows), (cols), M##data}

/*! Macro to allocate a matrix as part of a structure. The matrix MUST be setup with structInitMatrix()
 * \param M is the name used to refer to the DCM.
 * \param rows is the number of rows.
 * \param cols is the number of columns.
 */
#define structAllocateMatrixf(M, rows, cols) float M##data[(rows)*(cols)]; Matrixf_t M

//! Get a specific element of a matrix
float matrixGetf(const Matrixf_t* M, uint32_t row, uint32_t col);

//! Set a specific element of a matrix
void matrixSetf(Matrixf_t* M, uint32_t row, uint32_t col, float value);

//! Add a scalar to a specific element of the matrix

//! Set an entire row of a matrix

//! Set an entire column of a matrix

//! Allocate a matrix, initializing its memory

//! Change the size of a matrix

//! Change the size of a matrix

//! Set all elements of a matrix to zero

//! Set this matrix to be identity
void matrixSetIdentityf(Matrixf_t* M);

//! Copy a matrix

//! Multiply two matrices together
BOOL matrixMultiplyf(const Matrixf_t* A, const Matrixf_t* B, Matrixf_t* C);

//! Multiply the transpose of the left matrix against the right matrix
BOOL matrixMultiplyTransAf(const Matrixf_t* A, const Matrixf_t* B, Matrixf_t* C);

//! Multiply the left matrix against the transpose of the right matrix
BOOL matrixMultiplyTransBf(const Matrixf_t* A, const Matrixf_t* B, Matrixf_t* C);

//! Multiply a vector against a matrix

//! Multiply a vector against the transpose of a matrix

//! Add two matrices together

//! Add two matrices together, placing the result back into the first matrix.

//! Scale a matrix

//! Add two matrices together and multiply each element by 0.5.

//! Add identity to a matrix

//! Subtract identity from a matrix

//! Subtract a matrix from the identity matrix

//! Compute the dot product of two rows of a matrix

//! Compute the transpose of a matrix

//! Calculate the inverse of a square matrix A, for dimensions 1x2, 2x2, 3x3
BOOL matrixInversef(const Matrixf_t* A, Matrixf_t* B);

//! Test a matrix for its error to identity
float testForIdentityf(const Matrixf_t* M);

//! Test a matrix for its error to null
float testForZeroMatrixf(const Matrixf_t* M);

//! Compute the transpose of a matrix, copying from Matrixf_t to Matrix_t

//! Compute the transpose of a matrix, copying from Matrix_t to Matrixf_t

//! Copy a matrix, copying from Matrixf_t to Matrix_t

//! Copy a matrix, copying from Matrix_t to Matrixf_t

//! Evaluate the derivative of quadratic equation at x

//! Evaluate a quadratic equation with 3 coefficients at x

//! Solve a quadratic regression to determine the coefficients c, b, and a.
BOOL quadraticRegressionf(const float x[], const float y[], int num, float cba[3]);

// C++ compilers: don't mangle us
#ifdef __cplusplus
}
#endif

#endif // LINEARALGEBRA_H
