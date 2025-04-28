#include "vector3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* TODO: -- define data structure here -- */ 

typedef struct vector3d {
    double x;
    double y;
    double z;
} Vector3d;



PtVector3d  vector3dCreate(double x, double y, double z) {
    PtVector3d newVector = (PtVector3d)malloc(sizeof(Vector3d));
    if (newVector == NULL) return NULL;

    newVector->x = x;
    newVector->y = y;
    newVector->z = z;

    return newVector;
}

void vector3dPrint(PtVector3d vec, bool lineBreakAfter) {
    if (vec == NULL) {
        printf("Vector NULL");
    } else {
        printf("<%.2f, %.2f, %.2f>", vec->x, vec->y, vec->z);
    }
    
    if (lineBreakAfter) printf("\n");
}

int vector3dX(PtVector3d vec, double *x) {
    if (vec == NULL) return VECTOR3D_NULL; // Se o vetor for NULL, devolve erro
    *x = vec->x; // Senão, guarda o valor de x
    return VECTOR3D_OK;
}

int vector3dY(PtVector3d vec, double *y) {
    if (vec == NULL) return VECTOR3D_NULL;
    *y = vec->y;
    return VECTOR3D_OK;
}

int vector3dZ(PtVector3d vec, double *z) {
    if (vec == NULL) return VECTOR3D_NULL;
    *z = vec->z;
    return VECTOR3D_OK;
}

int vector3dDestroy(PtVector3d *pVec) {
    
    if (pVec == NULL || *pVec == NULL) return VECTOR3D_NULL;

    free(*pVec);   // Liberta a memória alocada
    *pVec = NULL;  // Evita dangling pointer (ponteiro solto)

    return VECTOR3D_OK;
}

PtVector3d vector3dMultiplyByScalar(PtVector3d vec, double scalar) {
    if (vec == NULL) return NULL;

    PtVector3d result = vector3dCreate(vec->x * scalar, vec->y * scalar, vec->z * scalar);
    return result;
}


PtVector3d vector3dAdd(PtVector3d vec1, PtVector3d vec2) {
    if (vec1 == NULL || vec2 == NULL) return NULL;

    PtVector3d result = vector3dCreate(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z);
    return result;
}


int vector3dMagnitude(PtVector3d vec, double *magnitude) {
    if (vec == NULL) return VECTOR3D_NULL;

    *magnitude = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
    return VECTOR3D_OK;
}

PtVector3d vector3dNormalize(PtVector3d vec) {
    if (vec == NULL) return NULL;

    double magnitude;
    if (vector3dMagnitude(vec, &magnitude) != VECTOR3D_OK || magnitude == 0) {
        // Se a magnitude for 0, o vetor não pode ser normalizado. Retorna um vetor nulo.
        return vector3dCreate(0, 0, 0);
    }

    // Normaliza as componentes do vetor
    return vector3dCreate(vec->x / magnitude, vec->y / magnitude, vec->z / magnitude);
}