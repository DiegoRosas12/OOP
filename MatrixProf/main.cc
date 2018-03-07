#include <iostream>
#include "matrix.h"

using namespace std;

void test1() {
    double data[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Matrix A;
    A.set(3, 3, data);
    A.print();
}

int main( int argc, char** argv ) {

    if ( argc != 2 ) {
        return 1;
    }

    char* filename = argv[1];

    Matrix A;
    A.load(filename);
    A.print();

    return 0;
}

