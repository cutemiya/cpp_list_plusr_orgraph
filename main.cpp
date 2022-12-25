#include "structure.h"
using namespace std;

int main() {

    Top top = addTop(1);
    Top top2 = addTop(4);
    Top top4 = addTop(6);


    addArc(&top2, &top4);
    deleteArc(&top2, &top4);
    deleteTop(&top2);

    printMatrix();



    return 0;
}
