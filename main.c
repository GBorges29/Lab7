#include <stdio.h> 
#include <stdlib.h>
#include "vector3d.h"

int main() {

    PtVector3d v1 = vector3dCreate(2, 1, -4);
    if(v1 == NULL) {
        printf("No memory available. \n");
        return EXIT_FAILURE;
    }

    vector3dPrint(v1, true);
    
    return EXIT_SUCCESS;
}
