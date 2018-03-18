#include <iostream>
#include "matrix.h"

using namespace std;

void test1() {
    double data[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Matrix A;
    A.set(3, 3, data);
    A.print();
}

<<<<<<< HEAD
int main() {

    {
        Matrix A("A.txt");
        Matrix B("B.txt");

        cout << "A:" << endl;
        A.print();
        cout << "B:" << endl;
        B.print();

        cout << "dot: A . B" << endl;
        Matrix C = A; // constructor copia
        C.dot(B);
        C.print();
    }

    {
        Matrix A("m1.txt");
        Matrix B("m2.txt");

        cout << "A:" << endl;
        A.print();
        cout << "B:" << endl;
        B.print();

        cout << "suma: A + B" << endl;
        {
            Matrix C = A; // constructor copia
            C.add(B);
            C.print();
        }

        cout << "suma: A + 5" << endl;
        {
            Matrix C = A; // constructor copia
            C.add(5.0);
            C.print();
        }

        cout << "resta: A - B" << endl;
        {
            Matrix C = A; // constructor copia
            C.sub(B);
            C.print();
        }

        cout << "resta: A - 2" << endl;
        {
            Matrix C = A; // constructor copia
            C.sub(2.0);
            C.print();
        }

        cout << "mult: A o B" << endl;
        {
            Matrix C = A; // constructor copia
            C.mult(B);
            C.print();
        }

        cout << "mult: 3A" << endl;
        {
            Matrix C = A; // constructor copia
            C.mult(3.0);
            C.print();
        }
    }


    // 14  23   3  27
    // 12 -10  46  -2
=======
int main( int argc, char** argv ) {

    if ( argc != 2 ) {
        return 1;
    }

    char* filename = argv[1];

    Matrix A;
    A.load(filename);
    A.print();
>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac

    return 0;
}

