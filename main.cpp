#include "structure.h"
using namespace std;

int main() {
    list l;

    l.addTop(3);
    l.addTop(123);
    l.addTop(8);
    l.addArc(123, l[2]);
    l.addArc(123, l[0]);

    l.printArcs();

    l.print();
    return 0;
}
