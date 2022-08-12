#include "linearalgebra.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifndef MIN
# define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif

#ifndef MAX
# define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif

/*!
 * Set all elements of a vector3 to a specific value
 * \param vector is the vector3 to change
 * \param value is the value to use for all elements of vector
 * \return a pointer to vector
 */


/*!
 * Copy one vector to another
 * \param source is the source vector
 * \param dest receives a copy of the source vector
 * \return a const pointer to dest.
 */
const double* vector3Copy(const double source[NVECTOR3], double dest[NVECTOR3])
{
    int i;

    for(i = 0; i < NVECTOR3; i++)
        dest[i] = source[i];

    return dest;

}// vector3Copy


/*!
 * Multiply and accumulate two vectors as result = a + b*scale.
 * \param a is the first argument vector of the sum
 * \param b is the second argument vector of the sum
 * \param scale is the scalar to multiply by the b vector
 * \param result receives the summed vector
 * \return a const pointer to result.
 */


/*!
 * Sum two three dimensional vectors together. a, b, and result can point to
 * the same vector in order to do in-place addition.
 * \param a is the first argument vector of the sum
 * \param b is the second argument vector of the sum
 * \param result receives the summed vector
 * \return a const pointer to result.
 */
const double* vector3Sum(const double a[NVECTOR3], const double b[NVECTOR3], double result[NVECTOR3])
{
    int i;

    for(i = 0; i < NVECTOR3; i++)
        result[i] = a[i] + b[i];

    return result;

}// vector3Sum


/*!
 * Subtract one three dimensional vector from another. lef, right, and result
 * can point to the same vector in order to do in-place subtraction
 * \param left is the left argument of the vector difference
 * \param right is the right argument of the vector difference
 * \param result receives the difference vector
 * \return a const pointer to result.
 */
const double* vector3Difference(const double left[NVECTOR3], const double right[NVECTOR3], double result[NVECTOR3])
{
    int i;

    for(i = 0; i < NVECTOR3; i++)
        result[i] = left[i] - right[i];

    return result;

}// vector3Difference

/*!
 * Multipy one three dimensional vector with another, element-wise.
 * left, right, and result can point to the same vector in order to do
 * in-place multiplication
 * \param left is the left argument of the vector multiplication
 * \param right is the right argument of the vector multiplication
 * \param result receives the product vector
 * \return a const pointer to result.
 */


/*!
 * Take the dot product of two three dimensional vectors. a and b can be the
 * same vector in order to compute the square of the vector length
 * \param a is the first argument vector of the dot product
 * \param b is the second argument vector of the dot product
 * \return the dot product result
 */
double vector3Dot(const double a[NVECTOR3], const double b[NVECTOR3])
{
    int i;
    double result = 0.0;
    for(i = 0; i < NVECTOR3; i++)
        result += a[i]*b[i];

    return result;

}// vector3Dot


/*!
 * Compute the angle between two three dimensional vectors
 * \param a is the first argument vector
 * \param b is the second argument vector
 * \return the angle between a and b from 0 to pi radians. 0 is returned if either vector is zero length.
 */
double vector3AngleBetween(const double a[NVECTOR3], const double b[NVECTOR3])
{
	double dot = vector3Dot(a, b);

	double magnitude = vector3LengthSquared(a)*vector3LengthSquared(b);

	if(magnitude > 0)
	{
		magnitude = sqrt(magnitude);
		return acos(dot/magnitude);
	}
	else
		return 0;
}


/*!
 * Cross one three dimensional vector against another. result cannot point to
 * either left or right, but must have its own memory
 * \param left is the left argument of the vector cross product
 * \param right is the right argument of the vector cross product
 * \param result receives the cross product
 * \return a const pointer to result.
 */


/*!
 * Compute the square of the length of a three dimensional vector
 * \param vector is the vector whose length squared is computed
 * \return the square of the lenght of vector.
 */
double vector3LengthSquared(const double vector[NVECTOR3])
{
    return vector3Dot(vector, vector);
}


/*!
 * Compute the length of a three dimensional vector
 * \param vector is the vector whose length is computed
 * \return the length of vector.
 */
double vector3Length(const double vector[NVECTOR3])
{
    return sqrt(vector3LengthSquared(vector));
}


/*!
 * Change the length of a vector. This is faster than making a unit vector and then scaling.
 * \param vector is the vector whose length is changed
 * \param result receives the new vector. fesult can be the same as vector.
 * \param newlength is the desired length of result. Note that newlength should
 *        not be negative, as the sign will be lost in this operation.
 * \return a const pointer to result.
 */
const double* vector3ChangeLength(const double vector[NVECTOR3], double result[NVECTOR3], double newlength)
{
	double oldlength = vector3Length(vector);

	if(oldlength > 0)
	{
		return vector3Scale(vector, result, newlength/oldlength);
	}
	else
	{
		// Divide by zero protection here.
		result[0] = newlength;
		result[1] = 0;
		result[2] = 0;
		return result;
	}

}// vector3ChangeLength


/*!
 * Scale a three dimensional vector
 * \param vector is the vector to be scaled
 * \param result receives the scaled vector. Result can be the same as vector.
 * \param scale is the scalar to multply against vector.
 * \return a const pointer to result.
 */
const double* vector3Scale(const double vector[NVECTOR3], double result[NVECTOR3], double scale)
{
    int i;
    for(i = 0; i < NVECTOR3; i++)
        result[i] = vector[i]*scale;

    return result;

}// vector3Scale


/*!
 * Convert a double-precision vector to single precision
 * \param vector is the vector to be converted
 * \param result receives the converted vector
 * \return a const pointer to result.
 */
const float *vector3Convert(const double vector[NVECTOR3], float result[NVECTOR3])
{
    result[VECTOR3X] = (float)vector[VECTOR3X];
    result[VECTOR3Y] = (float)vector[VECTOR3Y];
    result[VECTOR3Z] = (float)vector[VECTOR3Z];

    return result;

}// vector3Convert


/*!
 * Convert a single-precision vector to double precision
 * \param vector is the vector to be converted
 * \param result receives the converted vector
 * \return a const pointer to result.
 */
const double *vector3Convertf(const float vector[NVECTOR3], double result[NVECTOR3])
{
    result[VECTOR3X] = vector[VECTOR3X];
    result[VECTOR3Y] = vector[VECTOR3Y];
    result[VECTOR3Z] = vector[VECTOR3Z];

    return result;

}// vector3Convertf


/*!
 * Scale a three dimensional vector to unit length. If vector is (0, 0, 0)
 * then (1, 0, 0) is returned.
 * \param vector is the vector to be scaled to unit lenght
 * \param result receives the unit vector. Result can be the same as vector.
 * \return a const pointer to result.
 */
const double* vector3Unit(const double vector[NVECTOR3], double result[NVECTOR3])
{
    double length = vector3Length(vector);
    if(length > 0.0)
        return vector3Scale(vector, result, 1.0/length);
    else
    {
        result[VECTOR3X] = 1.0;
        result[VECTOR3Y] = 0.0;
        result[VECTOR3Z] = 0.0;
        return result;
    }

}// vector3Unit


/*!
 * Get a specific element of a vector
 * \param V is the vector
 * \param index is the index of the element to return
 * \return the element of V at index
 */


/*!
 * Set a specific element of a vector
 * \param V is the vector
 * \param index is the index of the element to return
 * \param value is the value to assign to element index of V
 * \return V is returned
 */


/*!
 * Add a scalar to a specific element of the vector
 * \param V is the vector
 * \param index is the index of the element to return
 * \param value is added to elements of V
 * \return V is returned
 */


/*!
 * Set the value of all elements of a vector
 * \param V is the vector
 * \param value is assigned to all elements of V
 * \return V is returned
 */


/*!
 * Allocate a vector, initializing its memory. The memory will be allocated
 * in a single step so all of the vector's memory can be released by calling
 * free(vector). The vector will initially be zero.
 * \param num is the number of elements of the vector.
 * \return a pointer to the newly allocated matrix, or
 *         NULL if the allocation failed.
 */


/*!
 * Change the size of a dynamically allocated vector. This can only be used
 * with vectors that were created using vectorAllocate().
 * \param v is the vector whose size will be changed.
 * \param num is the new size of the vector.
 * \param initial is the value given to the new elements of vector if it's size is being increased.
 * \return The new pointer to the vector, or null if the reallocation failed.
 */


/*!
 * Change the size of a vector. The caller must make certain that v-data points
 * to adequate memory space. For stack, global, or struct allocated vectors
 * this must be guaranteed at compile time by allocating a large enough vector.
 * For dynamically allowed vectors (vectorAllocate()) this can be done with
 * vectorChangeAllocateSize().
 * \param v is the vector whose size will be changed.
 * \param num is the new size of the vector.
 * \param initial is the value given to the new elements of vector if it's size is being increased.
 */


/*!
 * Set the value of all elements of a vector to zero
 * \param V is the vector
 * \return V is returned
 */


/*!
 * Copy elements of a vector. The copy proceeds up to the smallest
 * dimension of A or B. The dimension of B is not changed.
 * \param A is the source vector.
 * \param B is the destination vector.
 * \return B is returned.
 */



/*!
 * Multiply and accumulate two vectors as result = a + b*scale; up to the
 * smallest dimension of a, b, and result.
 * \param a is the first vector in the accumulation.
 * \param b is the scaled vector in the accumulation.
 * \param scale is multiplied against every element of b.
 * \param result receives a + b*scale.
 * \return result is returned.
 */


/*!
 * Sum two vectors together; up to the smallest dimension of a, b, and result.
 * \param a is the first vector in the sum.
 * \param b is the second vector in the sum.
 * \param result receives the sum.
 * \return result is returned.
 */


/*!
 * Subtract one vector from another; up to the smallest dimension of left,
 * right, and result.
 * \param left is the left vector in the difference.
 * \param right is subtracted from left.
 * \param result receives the left - right.
 * \return result is returned.
 */


/*!
 * Multiply two vectors together element-wise; up to the smallest dimension of
 * a, b, and result.
 * \param a is the first vector in the multiply.
 * \param b is the second vector in the multiply.
 * \param result receives a*b element-by-element.
 * \return result is returned.
 */


/*!
 * Compute the dot product of two vectors; up to the smallest dimension of
 * a and b.
 * \param a is the first vector in the dot product.
 * \param b is the second vector in the dot product.
 * \return the dot product of a and b.
 */


/*!
 * Compute the square of the length of a vector.
 * \param v is the vector.
 * \return the square of the length of v.
 */


/*!
 * Compute the length of a vector.
 * \param v is the vector.
 * \return the length of v.
 */


/*!
 * Change the length of a vector. This is faster than making a unit vector and
 * then scaling. Proceed up to the smallest dimension of v and result.
 * \param v is the vector whose length is changed.
 * \param result receives the new vector.
 * \param newlength is the desired length of the new vector.
 * \return result is returned.
 */


/*!
 * Scale a vector; proceeding up to the smallest dimension of v and result
 * \param v is the vector to scale.
 * \param result receives the scaled vector.
 * \param scale is multiplied against every element of v.
 * \return result is returned.
 */


/*!
 * Scale a vector to unit length; proceeding up to the smallest dimension of
 * v and result.
 * \param v is the vector to scale.
 * \param result receives the unit vector.
 * \return result is returned.
 */


/*!
 * Return the absolute value of all elements in a vector
 * \param v is the vector to take absolute value of
 * \param result receives the absolute value of v
 * \return result is returned.
 */


/*!
 * Get the largest element in a vector
 * \param v is the vector
 * \return the largest element of v
 */


/*!
 * Get the smallest element in a vector
 * \param v is the vector
 * \return the smallest element of v
 */


/*!
 * Get a specific element of a matrix
 * \param M is the matrix pointer
 * \param row is the row index
 * \param col is the column index
 * \return the value at <row, col>
 */
#define get(M, row, col) ((M)->data[(row)*(M)->numCols + (col)])

/*!
 * Set a specific element of a matrix
 * \param M is the matrix pointer
 * \param row is the row index
 * \param col is the column index
 * \value is the new value to place at <row, col>
 */
#define set(M, row, col, value) (get(M, row, col) = (value))

//! Invert a 2x2 matrix

//! Invert a 3x3 matrix


/*!
 * Get a specific element of a matrix
 * \param M is the matrix pointer
 * \param row is the row index
 * \param col is the column index
 * \return the value at <row, col>
 */


/*!
 * Set a specific element of a matrix
 * \param M is the matrix pointer
 * \param row is the row index
 * \param col is the column index
 * \param value is the new value to place at <row, col>
 */


/*!
 * Add a scalar to a specific element of the matrix
 * \param M is the matrix pointer
 * \param row is the row index
 * \param col is the column index
 * \param value added to the element at <row, col>
 */


/*! Allocate a matrix, initializing its memory. The memory will be allocated
 * in a single step so all of the matrix's memory can be released by calling
 * free(matrix). The matrix will initially be zero.
 * \param rows is the number of rows of the matrix.
 * \param cols is the number of columns of the matrix.
 * \return a pointer to the newly allocated matrix, or
 *         NULL if the allocation failed.
 */


/*!
 * Change the size of a dynamically allocated matrix. This applies only to
 * matrix allocated via matrixAllocate().
 * \param M is the matrix whose size will be changed.
 * \param rows is the new number of rows.
 * \param cols is the new number of columns.
 * \param initial is the value given to the new elements of matrix if the number
 *        of rows or columns are being increased.
 * \return The reallocated matrix or null if the reallocation failed
 */


/*!
 * Change the size of a matrix. The caller must make certain that M-data points
 * to adequate memory space. For stack, global, or struct allocated vectors
 * this must be guaranteed at compile time by allocating a large enough matrix.
 * For dynamically allowed vectors (matrixAllocate()) this can be done with
 * matrixChangeAllocateSize().
 * \param M is the matrix whose size will be changed.
 * \param rows is the new number of rows.
 * \param cols is the new number of columns.
 * \param initial is the value given to the new elements of matrix if the number
 *        of rows or columns are being increased.
 */


/*! Set all elements of a matrix to zero
 * \param M has all its elements set to Zero
 */


/*! Set this matrix to be identity
 * \param M is set to identity */


/*! Copy a matrix
 * \param A is the source matrix
 * \param B receives the copy of A. B must already be the correct size
 * \return TRUE if B is the correct size, else FALSE and no copy is performed
 */


/*! Set an entire row of a matrix
 * \param M is the matrix whose row is set.
 * \param row is the index of the row to set.
 * \param value is the value to place in each element of the row.
 */


/*! Set an entire column of a matrix
 * \param M is the matrix whose column is set.
 * \param col is the index of the column to set.
 * \param value is the value to place in each element of the column.
 */


/*! Multiply two matrices together
 * \param A is the left side matrix with dimensions m by n.
 * \param B is the right side matrix with dimensions n by s.
 * \param C receives the result. C must must dimension m by s.
 * \return TRUE if the matrix dimensions are compatible and the multiply is
 *         performed, else FALSE.
 */


/*! Multiply the transpose of the left matrix against the right matrix
 * \param A is the left side matrix with dimensions n by m, whose transpose is used in the multiply
 * \param B is the right side matrix with dimensions n by s.
 * \param C receives the result. C must must dimension m by s.
 * \return TRUE if the matrix dimensions are compatible and the multiply is
 *         performed, else FALSE.
 */


/*! Multiply the left matrix against the transpose of the right matrix
 * \param A is the left side matrix with dimensions m by n
 * \param B is the right side matrix with dimensions s by n, whose transpose is used in the multiply.
 * \param C receives the result. C must must dimension m by s.
 * \return TRUE if the matrix dimensions are compatible and the multiply is
 *         performed, else FALSE.
 */


/*!
 * Multiply a vector against a matrix C = A x B
 * \param A is the left side matrix with dimensions m by n.
 * \param B is the right side vector with dimensions n or greater. Elements
 *        past n will not be used.
 * \param C is the vector result. C must have dimension m or greater. Elements
 *        past m will not be touched.
 * \return TRUE if the matrix and vector dimensions are compatible
 *         and the multiply is performed, else FALSE.
 */


/*!
 * Multiply a vector against the transpose of a matrix C = A' x B
 * \param A is the left side matrix with dimensions m by n, which will be
 *        accessed in transpose.
 * \param B is the right side vector with dimensions m or greater. Elements
 *        past m will not be used.
 * \param C is the vector result. C must have dimension n or greater. Elements
 *        past n will not be touched.
 * \return TRUE if the matrix and vector dimensions are compatible
 *         and the multiply is performed, else FALSE.
 */


/*! Add two matrices together. The dimensions of A, B, and C must be the same.
 *  Note that addition in place can be done if C points to the same matrix as A or B
 * \param A is a matrix to add
 * \param B is a matrix to add
 * \param C receives the result
 * \return TRUE if the matrix dimensions are equal and the addition is performed.
 */


/*! Add two matrices together, placing the result back into the
 *  first matrix. The dimensions of A and B must be the same
 * \param A is a matrix to add, which also receives the result
 * \param B is a matrix to add
 * \return TRUE if the matrix dimensions are equal and the addition is performed.
 */


/*! Scale a matrix, multiplying every element by a scalar value
 * \param A is the matrix to scale
 * \param scalar is the value to multiply by every element
 */


/*! Add two matrices together and multiply each element by 0.5. This might be
 *  faster than using separate Add() and Scale() functions since the compiler
 *  can utilize a multiply-accumulate instruction. The dimensions of A, B, and
 *  C must be the same. Note that average in place can be done if C points to
 *  the same matrix as A or B
 * \param A is a matrix to average
 * \param B is a matrix to average
 * \param C receives the result
 * \return TRUE if the matrix dimensions are equal and the averaging is performed.
 */


/*! Add identity to a matrix
 * \param A has identity added to it
 */


/*!
 * Subtract identity from a matrix
 * \param A has identity subtracted from it
 */


/*! Subtract a matrix from the identity matrix
 * \param A is updated to identity minus A
 */


/*!
 * Compute the dot product of two rows of a matrix
 * \param A is the matrix whose rows are dotted
 * \param rowA is the index of the first row
 * \param rowB is the index of the second row
 * \return the dot product of rowA dotted with rowB
 */


/*! Compute the transpose of a matrix. The B matrix can be the same as the A
 *  matrix if the matrix is square. In that case this function will use an
 *  optimized in place transpose.
 * \param A is the matix whose transpose should be taken.
 * \param B receives the transpose of A.
 * \return TRUE if the matrix dimensions are compatible, else FALSE
 */


/*! Calculate the inverse of a square matrix A, for dimensions 1x1, 2x2, or
 *  3x3. The A and B matrices must have the same dimensions. A and B can point
 *  to the same matrix.
 * \param A is the matrix to take an inverse of.
 * \param B receives the inverse of A.
 * \return TRUE if the matrix dimensions are compatible and A is non-singular.
 */


/*! Calculate the inverse of a 2x2 matrix A. The A and B matrix must be 2x2
 *  matrices. A and B can point to the same matrix.
 * \param A is the 2x2 matrix to take an inverse of.
 * \param B receives the inverse of A.
 * \return TRUE if A is non-singular and the inverse is computed.
 */


/*! Calculate the inverse of a 3x3 matrix A. The A and B matrix must be 3x3
 *  matrices. A and B can point to the same matrix.
 * \param A is the 3x3 matrix to take an inverse of.
 * \param B receives the inverse of A.
 * \return TRUE if A is non-singular and the inverse is computed.
 */


/*!
 * Test for identity by returning the sum of the absolute differences between
 * a Matrix and an identity matrix of the same dimensions.
 * \param M points to the matrix to test
 * \return the total error between M and identity
 */


/*!
 * Test for zero matrix by returning the sum of the absolute differences between
 * a Matrix and a null matrix of the same dimensions.
 * \param M points to the matrix to test
 * \return the total error between M and null
 */


/*!
 * Evaluate the derivative of quadratic equation at x
 * \param cba is the c, b, and a coeficients in the equation y = ax^2 + bx + c.
 * \param x is the location to evaluate
 * \return the value of dy/dx at x.
 */


/*!
 * Evaluate a quadratic equation with 3 coefficients at x
 * \param cba is the c, b, and a coeficients in the equation y = ax^2 + bx + c.
 * \param x is the location to evaluate
 * \return the value of y at x.
 */


/*!
 * Solve a quadratic regression to determine the coefficients c, b, and a in
 * the equation y = ax^2 + bx + c.
 * \param x is the vector of xs, which must be at least three elements long
 * \param y is the vector of ys, which must be the same length as x
 * \param num is the number of elements in x and y
 * \param cba receives the three coefficients, c = cba[0], b = cba[1], a = cba[2]
 * \return true if a solution was found, else false
 */


/*!
 * Set all elements of a vector3 to a specific value
 * \param vector is the vector3 to change
 * \param value is the value to use for all elements of vector
 * \return a pointer to vector
 */


/*!
 * Copy one vector to another
 * \param source is the source vector
 * \param dest receives a copy of the source vector
 * \return a const pointer to dest.
 */


/*!
 * Multiply and accumulate two vectors as result = a + b*scale.
 * \param a is the first argument vector of the sum
 * \param b is the second argument vector of the sum
 * \param scale is the scalar to multiply by the b vector
 * \param result receives the summed vector
 * \return a const pointer to result.
 */


/*!
 * Sum two three dimensional vectors together. a, b, and result can point to
 * the same vector in order to do in-place addition.
 * \param a is the first argument vector of the sum
 * \param b is the second argument vector of the sum
 * \param result receives the summed vector
 * \return a const pointer to result.
 */
const float* vector3Sumf(const float a[NVECTOR3], const float b[NVECTOR3], float result[NVECTOR3])
{
    int i;

    for(i = 0; i < NVECTOR3; i++)
        result[i] = a[i] + b[i];

    return result;

}// vector3Sum


/*!
 * Subtract one three dimensional vector from another. lef, right, and result
 * can point to the same vector in order to do in-place subtraction
 * \param left is the left argument of the vector difference
 * \param right is the right argument of the vector difference
 * \param result receives the difference vector
 * \return a const pointer to result.
 */

/*!
 * Multipy one three dimensional vector with another, element-wise.
 * left, right, and result can point to the same vector in order to do
 * in-place multiplication
 * \param left is the left argument of the vector multiplication
 * \param right is the right argument of the vector multiplication
 * \param result receives the product vector
 * \return a const pointer to result.
 */


/*!
 * Take the dot product of two three dimensional vectors. a and b can be the
 * same vector in order to compute the square of the vector length
 * \param a is the first argument vector of the dot product
 * \param b is the second argument vector of the dot produc
 * \return the dot product result
 */
float vector3Dotf(const float a[NVECTOR3], const float b[NVECTOR3])
{
    int i;
    float result = 0.0f;
    for(i = 0; i < NVECTOR3; i++)
        result += a[i]*b[i];

    return result;

}// vector3Dotf


/*!
 * Compute the angle between two three dimensional vectors
 * \param a is the first argument vector
 * \param b is the second argument vector
 * \return the angle between a and b from 0 to pi radians. 0 is returned if either vector is zero length.
 */
float vector3AngleBetweenf(const float a[NVECTOR3], const float b[NVECTOR3])
{
	float dot = vector3Dotf(a, b);

	float magnitude = vector3LengthSquaredf(a)*vector3LengthSquaredf(b);

	if(magnitude > 0)
	{
		magnitude = sqrtf(magnitude);
		return acosf(dot/magnitude);
	}
	else
		return 0;
}


/*!
 * Cross one three dimensional vector against another. result cannot point to
 * either left or right, but must have its own memory
 * \param left is the left argument of the vector cross product
 * \param right is the right argument of the vector cross product
 * \param result receives the cross product
 * \return a const pointer to result.
 */


/*!
 * Compute the square of the length of a three dimensional vector
 * \param vector is the vector whose length squared is computed
 * \return the square of the lenght of vector.
 */
float vector3LengthSquaredf(const float vector[NVECTOR3])
{
    return vector3Dotf(vector, vector);
}


/*!
 * Compute the length of a three dimensional vector
 * \param vector is the vector whose length is computed
 * \return the length of vector.
 */
float vector3Lengthf(const float vector[NVECTOR3])
{
    return sqrtf(vector3LengthSquaredf(vector));
}


/*!
 * Change the length of a vector. This is faster than making a unit vector and then scaling.
 * \param vector is the vector whose length is changed
 * \param result receives the new vector. fesult can be the same as vector.
 * \param newlength is the desired length of result. Note that newlength should
 *        not be negative, as the sign will be lost in this operation.
 * \return a const pointer to result.
 */
const float* vector3ChangeLengthf(const float vector[NVECTOR3], float result[NVECTOR3], float newlength)
{
	float oldlength = vector3Lengthf(vector);

	if(oldlength > 0)
	{
		return vector3Scalef(vector, result, newlength/oldlength);
	}
	else
	{
		// Divide by zero protection here.
		result[0] = newlength;
		result[1] = 0;
		result[2] = 0;
		return result;
	}

}// vector3ChangeLengthf


/*!
 * Scale a three dimensional vector
 * \param vector is the vector to be scaled
 * \param result receives the scaled vector. Result can be the same as vector.
 * \param scale is the scalar to multply against vector.
 * \return a const pointer to result.
 */
const float* vector3Scalef(const float vector[NVECTOR3], float result[NVECTOR3], float scale)
{
    int i;
    for(i = 0; i < NVECTOR3; i++)
        result[i] = vector[i]*scale;

    return result;

}// vector3Scale



/*!
 * Scale a three dimensional vector to unit length. If vector is (0, 0, 0)
 * then (1, 0, 0) is returned.
 * \param vector is the vector to be scaled to unit lenght
 * \param result receives the unit vector. Result can be the same as vector.
 * \return a const pointer to result.
 */
const float* vector3Unitf(const float vector[NVECTOR3], float result[NVECTOR3])
{
    float length = vector3Lengthf(vector);
    if(length > 0.0f)
        return vector3Scalef(vector, result, 1.0f/length);
    else
    {
        result[VECTOR3X] = 1.0f;
        result[VECTOR3Y] = 0.0f;
        result[VECTOR3Z] = 0.0f;
        return result;
    }

}// vector3Unit


/*!
 * Compute the absolute value of all three elements in a vector
 * \param vector is the vector to be scaled to unit lenght
 * \param result receives the unit vector. Result can be the same as vector.
 * \return a const pointer to result.
 */


/*!
 * Compute the absolute value of all three elements in a vector
 * \param vector is the vector to be scaled to unit lenght
 * \param result receives the unit vector. Result can be the same as vector.
 * \return a const pointer to result.
 */


/*!
 * Get a specific element of a vector
 * \param V is the vector
 * \param index is the index of the element to return
 * \return the element of V at index
 */


/*!
 * Set a specific element of a vector
 * \param V is the vector
 * \param index is the index of the element to return
 * \param value is the value to assign to element index of V
 * \return V is returned
 */


/*!
 * Add a scalar to a specific element of the vector
 * \param V is the vector
 * \param index is the index of the element to return
 * \param value is added to elements of V
 * \return V is returned
 */


/*!
 * Set the value of all elements of a vector
 * \param V is the vector
 * \param value is assigned to all elements of V
 * \return V is returned
 */


/*!
 * Allocate a vector, initializing its memory. The memory will be allocated
 * in a single step so all of the vector's memory can be released by calling
 * free(vector). The vector will initially be zero.
 * \param num is the number of elements of the vector.
 * \return a pointer to the newly allocated matrix, or
 *         NULL if the allocation failed.
 */


/*!
 * Change the size of a dynamically allocated vector. This can only be used
 * with vectors that were created using vectorAllocate().
 * \param v is the vector whose size will be changed.
 * \param num is the new size of the vector.
 * \param initial is the value given to the new elements of vector if it's size is being increased.
 * \return The new pointer to the vector, or null if the reallocation failed.
 */


/*!
 * Change the size of a vector. The caller must make certain that v-data points
 * to adequate memory space. For stack, global, or struct allocated vectors
 * this must be guaranteed at compile time by allocating a large enough vector.
 * For dynamically allowed vectors (vectorAllocate()) this can be done with
 * vectorChangeAllocateSize().
 * \param v is the vector whose size will be changed.
 * \param num is the new size of the vector.
 * \param initial is the value given to the new elements of vector if it's size is being increased.
 */


/*!
 * Set the value of all elements of a vector to zero
 * \param V is the vector
 * \return V is returned
 */


/*!
 * Copy elements of a vector. The copy proceeds up to the smallest
 * dimension of A or B. The dimension of B is not changed.
 * \param A is the source vector.
 * \param B is the destination vector.
 * \return B is returned.
 */


/*!
 * Multiply and accumulate two vectors as result = a + b*scale; up to the
 * smallest dimension of a, b, and result.
 * \param a is the first vector in the accumulation.
 * \param b is the scaled vector in the accumulation.
 * \param scale is multiplied against every element of b.
 * \param result receives a + b*scale.
 * \return result is returned.
 */


/*!
 * Sum two vectors together; up to the smallest dimension of a, b, and result.
 * \param a is the first vector in the sum.
 * \param b is the second vector in the sum.
 * \param result receives the sum.
 * \return result is returned.
 */


/*!
 * Subtract one vector from another; up to the smallest dimension of left,
 * right, and result.
 * \param left is the left vector in the difference.
 * \param right is subtracted from left.
 * \param result receives the left - right.
 * \return result is returned.
 */


/*!
 * Multiply two vectors together element-wise; up to the smallest dimension of
 * a, b, and result.
 * \param a is the first vector in the multiply.
 * \param b is the second vector in the multiply.
 * \param result receives a*b element-by-element.
 * \return result is returned.
 */


/*!
 * Compute the dot product of two vectors; up to the smallest dimension of
 * a and b.
 * \param a is the first vector in the dot product.
 * \param b is the second vector in the dot product.
 * \return the dot product of a and b.
 */


/*!
 * Compute the square of the length of a vector.
 * \param v is the vector.
 * \return the square of the length of v.
 */


/*!
 * Compute the length of a vector.
 * \param v is the vector.
 * \return the length of v.
 */


/*!
 * Change the length of a vector. This is faster than making a unit vector and
 * then scaling. Proceed up to the smallest dimension of v and result.
 * \param v is the vector whose length is changed.
 * \param result receives the new vector.
 * \param newlength is the desired length of the new vector.
 * \return result is returned.
 */


/*!
 * Scale a vector; proceeding up to the smallest dimension of v and result
 * \param v is the vector to scale.
 * \param result receives the scaled vector.
 * \param scale is multiplied against every element of v.
 * \return result is returned.
 */


/*!
 * Scale a vector to unit length; proceeding up to the smallest dimension of
 * v and result.
 * \param v is the vector to scale.
 * \param result receives the unit vector.
 * \return result is returned.
 */


/*!
 * Return the absolute value of all elements in a vector
 * \param v is the vector to take absolute value of
 * \param result receives the absolute value of v
 * \return result is returned.
 */


/*!
 * Get the largest element in a vector
 * \param v is the vector
 * \return the largest element of v
 */


/*!
 * Get the smallest element in a vector
 * \param v is the vector
 * \return the smallest element of v
 */


//! Invert a 2x2 matrix
static BOOL matrixInverse2x2f(const Matrixf_t* A, Matrixf_t* B);

//! Invert a 3x3 matrix
static BOOL matrixInverse3x3f(const Matrixf_t* A, Matrixf_t* B);


/*!
 * Get a specific element of a matrix
 * \param M is the matrix pointer
 * \param row is the row index
 * \param col is the column index
 * \return the value at <row, col>
 */
float matrixGetf(const Matrixf_t* M, uint32_t row, uint32_t col)
{
    return get(M, row, col);
}


/*!
 * Set a specific element of a matrix
 * \param M is the matrix pointer
 * \param row is the row index
 * \param col is the column index
 * \param value is the new value to place at <row, col>
 */
void matrixSetf(Matrixf_t* M, uint32_t row, uint32_t col, float value)
{
    get(M, row, col) = value;
}


/*!
 * Add a scalar to a specific element of the matrix
 * \param M is the matrix pointer
 * \param row is the row index
 * \param col is the column index
 * \param value added to the element at <row, col>
 */


/*! Allocate a matrix, initializing its memory. The memory will be allocated
 * in a single step so all of the matrix's memory can be released by calling
 * free(matrix). The matrix will initially be zero.
 * \param rows is the number of rows of the matrix.
 * \param cols is the number of columns of the matrix.
 * \return a pointer to the newly allocated matrix, or
 *         NULL if the allocation failed.
 */


/*!
 * Change the size of a dynamically allocated matrix. This applies only to
 * matrix allocated via matrixAllocatef().
 * \param M is the matrix whose size will be changed.
 * \param rows is the new number of rows.
 * \param cols is the new number of columns.
 * \param initial is the value given to the new elements of matrix if the number
 *        of rows or columns are being increased.
 * \return The reallocated matrix or null if the reallocation failed
 */


/*!
 * Change the size of a matrix. The caller must make certain that M-data points
 * to adequate memory space. For stack, global, or struct allocated vectors
 * this must be guaranteed at compile time by allocating a large enough matrix.
 * For dynamically allowed vectors (matrixAllocatef()) this can be done with
 * matrixChangeAllocateSizef().
 * \param M is the matrix whose size will be changed.
 * \param rows is the new number of rows.
 * \param cols is the new number of columns.
 * \param initial is the value given to the new elements of matrix if the number
 *        of rows or columns are being increased.
 */


/*! Set all elements of a matrix to zero
 * \param M has all its elements set to Zero
 */


/*! Set this matrix to be identity
 * \param M is set to identity */
void matrixSetIdentityf(Matrixf_t* M)
{
    uint32_t row, col;
    for(row = 0; row < M->numRows; row++)
    {
        for(col = 0; col < M->numCols; col++)
        {
            if(row == col)
                set(M, row, col, 1.0f);
            else
                set(M, row, col, 0.0f);
        }
    }

}// matrixSetIdentityf


/*! Copy a matrix
 * \param A is the source matrix
 * \param B receives the copy of A. B must already be the correct size
 * \return TRUE if B is the correct size, else FALSE and no copy is performed
 */


/*! Set an entire row of a matrix
 * \param M is the matrix whose row is set.
 * \param row is the index of the row to set.
 * \param value is the value to place in each element of the row.
 */


/*! Set an entire column of a matrix
 * \param M is the matrix whose column is set.
 * \param col is the index of the column to set.
 * \param value is the value to place in each element of the column.
 */


/*! Multiply two matrices together
 * \param A is the left side matrix with dimensions m by n.
 * \param B is the right side matrix with dimensions n by s.
 * \param C receives the result. C must must dimension m by s.
 * \return TRUE if the matrix dimensions are compatible and the multiply is
 *         performed, else FALSE.
 */
BOOL matrixMultiplyf(const Matrixf_t* A, const Matrixf_t* B, Matrixf_t* C)
{
    uint32_t row, col, i;

    // When multiplying matrices A x B = C we must satisfy the following dimensions:
    // A = m by n    // m rows by n columns
    // B = n by o    // rows of B must be equal to columns of A
    // C = m by o    // rows of C must be equal to rows of A and columns of C must be equal to columns of B

    if((A->numCols != B->numRows) || (A->numRows != C->numRows) || (B->numCols != C->numCols))
        return FALSE;

    /// TODO: there is some potential for optimization here reqarding computing of data indices
    for(row = 0; row < A->numRows; row++ )
    {
        for(col = 0; col < B->numCols; col++)
        {
            // Initialize the summation
            float result = 0.0f;

            for(i = 0; i < A->numCols; i++)
            {
                // continue summation
                result += get(A, row, i)*get(B, i, col);

            }// for the inner dimension

            set(C, row, col, result);

        }// for all columns of the result matrix

    }// for all rows of the result matrix

    return TRUE;

}// matrixMultiplyf


/*! Multiply the transpose of the left matrix against the right matrix
 * \param A is the left side matrix with dimensions n by m, whose transpose is used in the multiply
 * \param B is the right side matrix with dimensions n by s.
 * \param C receives the result. C must must dimension m by s.
 * \return TRUE if the matrix dimensions are compatible and the multiply is
 *         performed, else FALSE.
 */
BOOL matrixMultiplyTransAf(const Matrixf_t* A, const Matrixf_t* B, Matrixf_t* C)
{
    uint32_t row, col, i;

    // We are going to be using A in transpose. We don't actually take
    // the tranpose, we just access the data according to those rules.
    uint32_t rowsLeft = A->numCols;
    uint32_t colsLeft = A->numRows;

    if((colsLeft != B->numRows) || (rowsLeft != C->numRows) || (B->numCols != C->numCols))
        return FALSE;

    /// TODO: there is some potential for optimization here reqarding computating of data indices
    for(row = 0; row < rowsLeft; row++ )
    {
        for(col = 0; col < B->numCols; col++)
        {
            // Initialize the summation
            float result = 0.0f;

            for(i = 0; i < colsLeft; i++)
            {
                // continue summation, notice how we access A's data in
                // transpose by reverseing the row and column indices
                result += get(A, i, row)*get(B, i, col);

            }// for the inner dimension

            set(C, row, col, result);

        }// for all columns of the result matrix

    }// for all rows of the result matrix

    return TRUE;

}// matrixMultiplyTransAf


/*! Multiply the left matrix against the transpose of the right matrix
 * \param A is the left side matrix with dimensions m by n
 * \param B is the right side matrix with dimensions s by n, whose transpose is used in the multiply.
 * \param C receives the result. C must must dimension m by s.
 * \return TRUE if the matrix dimensions are compatible and the multiply is
 *         performed, else FALSE.
 */
BOOL matrixMultiplyTransBf(const Matrixf_t* A, const Matrixf_t* B, Matrixf_t* C)
{
    uint32_t row, col, i;

    // We are going to be using B in transpose. We don't actually take
    // the tranpose, we just access the data according to those rules.
    uint32_t rowsRight = B->numCols;
    uint32_t colsRight = B->numRows;

    if((A->numCols != rowsRight) || (A->numRows != C->numRows) || (colsRight != C->numCols))
        return FALSE;

    /// TODO: there is some potential for optimization here reqarding computating of data indices
    for(row = 0; row < A->numRows; row++ )
    {
        for(col = 0; col < colsRight; col++)
        {
            // Initialize the summation
            float result = 0.0f;

            for(i = 0; i < A->numCols; i++)
            {
                // continue summation, notice how we access B's data in
                // transpose by reverseing the row and column indices
                result += get(A, row, i)*get(B, col, i);

            }// for the inner dimension

            set(C, row, col, result);

        }// for all columns of the result matrix

    }// for all rows of the result matrix

    return TRUE;

}// matrixMultiplyTransBf


/*!
 * Multiply a vector against a matrix C = A x B
 * \param A is the left side matrix with dimensions m by n.
 * \param B is the right side vector with dimensions n or greater. Elements
 *        past n will not be used.
 * \param C is the vector result. C must have dimension m or greater. Elements
 *        past m will not be touched.
 * \return TRUE if the matrix and vector dimensions are compatible
 *         and the multiply is performed, else FALSE.
 */


/*!
 * Multiply a vector against the transpose of a matrix C = A' x B
 * \param A is the left side matrix with dimensions m by n, which will be
 *        accessed in transpose.
 * \param B is the right side vector with dimensions m or greater. Elements
 *        past m will not be used.
 * \param C is the vector result. C must have dimension n or greater. Elements
 *        past n will not be touched.
 * \return TRUE if the matrix and vector dimensions are compatible
 *         and the multiply is performed, else FALSE.
 */


/*! Add two matrices together. The dimensions of A, B, and C must be the same.
 *  Note that addition in place can be done if C points to the same matrix as A or B
 * \param A is a matrix to add
 * \param B is a matrix to add
 * \param C receives the result
 * \return TRUE if the matrix dimensions are equal and the addition is performed.
 */


/*! Add two matrices together, placing the result back into the
 *  first matrix. The dimensions of A and B must be the same
 * \param A is a matrix to add, which also receives the result
 * \param B is a matrix to add
 * \return TRUE if the matrix dimensions are equal and the addition is performed.
 */


/*! Scale a matrix, multiplying every element by a scalar value
 * \param A is the matrix to scale
 * \param scalar is the value to multiply by every element
 */


/*! Add two matrices together and multiply each element by 0.5. This might be
 *  faster than using separate Add() and Scale() functions since the compiler
 *  can utilize a multiply-accumulate instruction. The dimensions of A, B, and
 *  C must be the same. Note that average in place can be done if C points to
 *  the same matrix as A or B
 * \param A is a matrix to average
 * \param B is a matrix to average
 * \param C receives the result
 * \return TRUE if the matrix dimensions are equal and the averaging is performed.
 */


/*! Add identity to a matrix
 * \param A has identity added to it
 */


/*!
 * Subtract identity from a matrix
 * \param A has identity subtracted from it
 */


/*! Subtract a matrix from the identity matrix
 * \param A is updated to identity minus A
 */


/*!
 * Compute the dot product of two rows of a matrix
 * \param A is the matrix whose rows are dotted
 * \param rowA is the index of the first row
 * \param rowB is the index of the second row
 * \return the dot product of rowA dotted with rowB
 */


/*! Compute the transpose of a matrix. The B matrix can be the same as the A
 *  matrix if the matrix is square. In that case this function will use an
 *  optimized in place transpose.
 * \param A is the matix whose transpose should be taken.
 * \param B receives the transpose of A.
 * \return TRUE if the matrix dimensions are compatible, else FALSE
 */


/*! Calculate the inverse of a square matrix A, for dimensions 1x1, 2x2, or
 *  3x3. The A and B matrices must have the same dimensions. A and B can point
 *  to the same matrix.
 * \param A is the matrix to take an inverse of.
 * \param B receives the inverse of A.
 * \return TRUE if the matrix dimensions are compatible and A is non-singular.
 */
BOOL matrixInversef(const Matrixf_t* A, Matrixf_t* B)
{
    if((A->numRows != A->numCols) || (B->numRows != B->numCols) || (A->numRows != B->numRows))
        return FALSE;

    switch(A->numRows)
    {
    case 1:
        if(A->data[0] != 0.0f)
        {
            B->data[0] = 1.0f/A->data[0];
            return TRUE;
        }
        else
            return FALSE;

    case 2:
        return matrixInverse2x2f(A, B);

    case 3:
        return matrixInverse3x3f(A, B);

    default:
        return FALSE;

    }// switch on size

}// matrixInversef


/*! Calculate the inverse of a 2x2 matrix A. The A and B matrix must be 2x2
 *  matrices. A and B can point to the same matrix.
 * \param A is the 2x2 matrix to take an inverse of.
 * \param B receives the inverse of A.
 * \return TRUE if A is non-singular and the inverse is computed.
 */
BOOL matrixInverse2x2f(const Matrixf_t* A, Matrixf_t* B)
{
    float a = get(A, 0, 0);
    float b = get(A, 0, 1);
    float c = get(A, 1, 0);
    float d = get(A, 1, 1);

    // Calculate the determinant
    float det = a*d - b*c;

    if(det != 0.0f)
    {
        det = 1.0f/det;
        set(B, 0, 0,  det*d);
        set(B, 0, 1, -det*b);
        set(B, 1, 0, -det*c);
        set(B, 1, 1,  det*a);

        return TRUE;
    }
    else
        return FALSE;

}// matrixInverse2x2f


/*! Calculate the inverse of a 3x3 matrix A. The A and B matrix must be 3x3
 *  matrices. A and B can point to the same matrix.
 * \param A is the 3x3 matrix to take an inverse of.
 * \param B receives the inverse of A.
 * \return TRUE if A is non-singular and the inverse is computed.
 */
BOOL matrixInverse3x3f(const Matrixf_t* A, Matrixf_t* B)
{
    // This algorithm taken from:
    // http://www.cg.info.hiroshima-cu.ac.jp/~miyazaki/knowledge/teche23.html

    float a11 = get(A, 0, 0);
    float a12 = get(A, 0, 1);
    float a13 = get(A, 0, 2);

    float a21 = get(A, 1, 0);
    float a22 = get(A, 1, 1);
    float a23 = get(A, 1, 2);

    float a31 = get(A, 2, 0);
    float a32 = get(A, 2, 1);
    float a33 = get(A, 2, 2);

    // Calculate the determinant
    float det = a11*a22*a33 + a21*a32*a13 + a31*a12*a23 - a11*a32*a23 - a31*a22*a13 - a21*a12*a33;

    if(det != 0.0f)
    {
        det = 1.0f/det;

        set(B, 0, 0, det*(a22*a33 - a23*a32));
        set(B, 0, 1, det*(a13*a32 - a12*a33));
        set(B, 0, 2, det*(a12*a23 - a13*a22));

        set(B, 1, 0, det*(a23*a31 - a21*a33));
        set(B, 1, 1, det*(a11*a33 - a13*a31));
        set(B, 1, 2, det*(a13*a21 - a11*a23));

        set(B, 2, 0, det*(a21*a32 - a22*a31));
        set(B, 2, 1, det*(a12*a31 - a11*a32));
        set(B, 2, 2, det*(a11*a22 - a12*a21));

        return TRUE;
    }
    else
        return FALSE;

}// matrixInverse3x3f


/*!
 * Test for identity by returning the sum of the absolute differences between
 * a Matrix and an identity matrix of the same dimensions.
 * \param M points to the matrix to test
 * \return the total error between M and identity
 */
float testForIdentityf(const Matrixf_t* M)
{
    uint32_t row, col;
    float error = 0.0f;

    for(row = 0; row < M->numRows; row++)
    {
        for(col = 0; col < M->numCols; col++)
        {
            if(row == col)
                error += fabsf(1.0f - matrixGetf(M, row, col));
            else
                error += fabsf(0.0f - matrixGetf(M, row, col));
        }
    }

    return error;
}


/*!
 * Test for zero matrix by returning the sum of the absolute differences between
 * a Matrix and a null matrix of the same dimensions.
 * \param M points to the matrix to test
 * \return the total error between M and null
 */
float testForZeroMatrixf(const Matrixf_t* M)
{
    uint32_t row, col;
    float error = 0.0f;

    for(row = 0; row < M->numRows; row++)
    {
        for(col = 0; col < M->numCols; col++)
        {
        	error += fabsf(0.0f - matrixGetf(M, row, col));
        }
    }

    return error;
}


/*!
 * Compute the transpose of a matrix, copying from Matrixf_t to Matrix_t
 * \param A is the Matrixf_t whose transpose should be taken.
 * \param B receives the transpose of A.
 * \return TRUE if the matrix dimensions are compatible, else FALSE
 */


/*!
 * Compute the transpose of a matrix, copying from Matrix_t to Matrixf_t
 * \param A is the Matrix_t whose transpose should be taken.
 * \param B receives the transpose of A.
 * \return TRUE if the matrix dimensions are compatible, else FALSE
 */


/*!
 * Copy a matrix, copying from Matrixf_t to Matrix_t
 * \param A is the Matrixf_t whose copy should be taken.
 * \param B receives the copy of A.
 * \return TRUE if the matrix dimensions are compatible, else FALSE
 */


/*!
 * Copy a matrix, copying from Matrix_t to Matrixf_t
 * \param A is the Matrix_t whose copy should be taken.
 * \param B receives the copy of A.
 * \return TRUE if the matrix dimensions are compatible, else FALSE
 */


/*!
 * Evaluate the derivative of quadratic equation at x
 * \param cba is the c, b, and a coeficients in the equation y = ax^2 + bx + c.
 * \param x is the location to evaluate
 * \return the value of dy/dx at x.
 */


/*!
 * Evaluate a quadratic equation with 3 coefficients at x
 * \param cba is the c, b, and a coeficients in the equation y = ax^2 + bx + c.
 * \param x is the location to evaluate
 * \return the value of y at x.
 */


/*!
 * Solve a quadratic regression to determine the coefficients c, b, and a in
 * the equation y = ax^2 + bx + c.
 * \param x is the vector of xs, which must be at least three elements long
 * \param y is the vector of ys, which must be the same length as x
 * \param num is the number of elements in x and y
 * \param cba receives the three coefficients, c = cba[0], b = cba[1], a = cba[2]
 * \return true if a solution was found, else false
 */
BOOL quadraticRegressionf(const float x[], const float y[], int num, float cba[3])
{
    /// TODO: this can be made faster if done in a less general way

    int i;
    float sumx4 = 0, sumx3 = 0, sumx2 = 0, sumx1 = 0, sumx2y1 = 0, sumx1y1 = 0, sumy1 = 0;

    stackAllocateMatrixf(left, 3, 3);
    stackAllocateMatrixf(invleft, 3, 3);
    stackAllocateMatrixf(right, 3, 1);
    stackAllocateMatrixf(solution, 3, 1);

    if(num < 3)
        return 0;

    for(i = 0; i < num; i++)
    {
        float x1 = x[i];
        float y1 = y[i];
        float x2 = x1*x1;

        sumx1 += x1;
        sumy1 += y1;
        sumx2 += x2;
        sumx3 += x2*x1;
        sumx4 += x2*x2;
        sumx1y1 += x1*y1;
        sumx2y1 += x2*y1;

    }// for all inputs

    // fill out the matrices
    matrixSetf(&left, 0, 0, sumx4);
    matrixSetf(&left, 0, 1, sumx3);
    matrixSetf(&left, 0, 2, sumx2);

    matrixSetf(&left, 1, 0, sumx3);
    matrixSetf(&left, 1, 1, sumx2);
    matrixSetf(&left, 1, 2, sumx1);

    matrixSetf(&left, 2, 0, sumx2);
    matrixSetf(&left, 2, 1, sumx1);
    matrixSetf(&left, 2, 2, (float)num);

    if(!matrixInversef(&left, &invleft))
        return FALSE;

    // The right side column vector
    matrixSetf(&right, 0, 0, sumx2y1);
    matrixSetf(&right, 0, 1, sumx1y1);
    matrixSetf(&right, 0, 2, sumy1);

    // Compute the solution column vector
    matrixMultiplyf(&invleft, &right, &solution);

    // Record the results
    cba[2] = matrixGetf(&solution, 0, 0);
    cba[1] = matrixGetf(&solution, 0, 1);
    cba[0] = matrixGetf(&solution, 0, 2);

    return TRUE;

}// quadraticRegression