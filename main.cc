#include <iostream>
#include "point.h"
using namespace std;

int main () {
    Point pt;
    // inicializamos la clase
    pt.set(0.0, 0.0);
    cout << "(" << pt.getx() << ", " << pt.gety() << ")" << endl;
    return 0;
}