#include "structure.h"
using namespace std;

int main() {
    list l;

    l.addTop(1);
    l.addTop(2);
    l.addTop(3);
    l.addArc(2, l[2]);
    l.addArc(2, l[0]);

    l.printArcs();

    l.print();
    return 0;
}
