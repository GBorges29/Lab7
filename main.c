#include <stdio.h>
#include <stdlib.h>
#include "vector3d.h"

int main() {
    PtVector3d v1 = vector3dCreate(2, 1, -4);
    if (v1 == NULL) {
        printf("No memory available.\n");
        return EXIT_FAILURE;
    }

    // Teste da normalização
    PtVector3d v1_normalized = vector3dNormalize(v1);
    printf("Resultado da normalização de <2, 1, -4>:\n");
    printComponentsOf(v1_normalized);

    // Verifique a magnitude do vetor normalizado
    double mag;
    if (vector3dMagnitude(v1_normalized, &mag) == VECTOR3D_OK) {
        printf("Magnitude do vetor normalizado: %.2f\n", mag); // Espera-se 1.00
    } else {
        printf("Erro a calcular a magnitude.\n");
    }

    // Libertar memória
    vector3dDestroy(&v1);
    vector3dDestroy(&v1_normalized);

    return EXIT_SUCCESS;
}



void printComponentsOf(PtVector3d vec) {
    double x, y, z;

    if (vector3dX(vec, &x) != VECTOR3D_OK ||
        vector3dY(vec, &y) != VECTOR3D_OK ||
        vector3dZ(vec, &z) != VECTOR3D_OK) {
        printf("Vector NULL. Não é possível apresentar as componentes.\n");
        return;
    }

    printf("x = %.2f | y = %.2f | z = %.2f\n", x, y, z);
}