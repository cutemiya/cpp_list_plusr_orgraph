#include "structure.h"

int main() {
    Top fTop = addTop(1);
    Top sTop = addTop(4);
    Top tTop = addTop(6);


    addArc(&fTop, &sTop);
    addArc(&fTop, &tTop);
    addArc(&tTop, &sTop);

    printMatrix();

    deleteArc(&fTop, &sTop);

    printMatrix();

    deleteTop(&sTop);

    printMatrix();



    return 0;
}
