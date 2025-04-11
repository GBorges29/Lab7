#pragma once

#include <stdbool.h>

#define VECTOR3D_OK 0
#define VECTOR3D_NULL 1

struct vector3d;
typedef struct vector3d* PtVector3d;

/**
 * @brief Creates a new vector
 * 
 * @param x [in] x component
 * @param y [in] y component
 * @param z [in] z component
 * @return PtVector3d pointer to allocated data structure
 * @return NULL if no memory available
 */
PtVector3d  vector3dCreate(double x, double y, double z);

/**
 * @brief Prints a vector in the form "<x, y, z>". 
 * Each component is presented with two decimal places.
 * 
 * @param vec [in] PtVector3d pointer
 * @param lineBreakAfter [in] if a line break should be put afterwards
 */
void vector3dPrint(PtVector3d vec, bool lineBreakAfter);

/**
 * @brief Frees the underlying data structure
 * 
 * @param pVec [in] address of PtVector3d pointer
 * @return VECTOR3_OK if successful
 * @return VECTOR3_NULL if *pVec is NULL
 */
int vector3dDestroy(PtVector3d *pVec);

/**
 * @brief Retrieves the X component of a vector
 * 
 * @param vec [in] PtVector3d pointer
 * @param x [out] address of variable to hold the returned value
 * @return VECTOR3_OK if successful and value in *x
 * @return VECTOR3_NULL if vec is NULL and x unmodified
 */
int vector3dX(PtVector3d vec, double *x);

/**
 * @brief Retrieves the Y component of a vector
 * 
 * @param vec [in] PtVector3d pointer
 * @param y [out] address of variable to hold the returned value
 * @return VECTOR3_OK if successful and value in *y
 * @return VECTOR3_NULL if vec is NULL and y unmodified
 */
int vector3dY(PtVector3d vec, double *y);

/**
 * @brief Retrieves the Z component of a vector
 * 
 * @param vec [in] PtVector3d pointer
 * @param z [out] address of variable to hold the returned value
 * @return VECTOR3_OK if successful and value in *z
 * @return VECTOR3_NULL if vec is NULL and *z unmodified
 */
int vector3dZ(PtVector3d vec, double *z);

/**
 * @brief Returns the multiplication of a vector by a scalar
 * 
 * The result is a number with their components multipled by 'scalar'
 * 
 * @param vec [in] PtVector3d pointer
 * @param scalar [in] the scalar to multiply
 * @return PtVector3d pointer for the resulting (allocated) number
 * @return NULL if vec is NULL
 */
PtVector3d vector3dMultiplyByScalar(PtVector3d vec, double scalar);

/**
 * @brief Computes the sum between two vectors
 * 
 * @param vec1 [in] PtVector3d pointer
 * @param vec2 [in] PtVector3d pointer
 * @return PtVector3d pointer for the resulting (allocated) number
 * @return NULL if vec1 is NULL or vec2 is NULL
 */
PtVector3d vector3dAdd(PtVector3d vec1, PtVector3d vec2);

/**
 * @brief Computes the magnitude (or length) of a vector.
 * 
 * ||vec|| = sqrt(x^2 + y^2 + z^2)
 * 
 * @param vec [in] PtVector3d pointer
 * @param magnitude [out] address of variable to hold the value
 * @return VECTOR3_OK if successful and value in *magnitude
 * @return VECTOR3_NULL if vec is NULL and *magnitude unmodified
 */
int vector3dMagnitude(PtVector3d vec, double *magnitude);

/**
 * @brief Normalizes a vector.
 * 
 * norm(vec) = vec / ||vec||
 * 
 * If ||vec|| == 0, then the result is <0, 0, 0>
 * 
 * @param vec [in] PtVector3d pointer
 * @return PtVector3d pointer to resulting (allocated) number
 * @return NULL if vec is NULL
 */
PtVector3d vector3dNormalize(PtVector3d vec);
