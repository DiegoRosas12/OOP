#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    Vector v1(10);

    v1.set(2,5);
    for (int i=0; i<10; i++) v1[i] = double(i+1); //vec[i] = vec.add(i)
    Vector v2 = v1;
    v2.set(2,5);

    cout << "A" << endl;
    v1.print();

    cout << "B" << endl;
    v2.print();
    
    cout << "suma" << endl;
    v1 + v2;    
    v1.print();
    cout << endl;
    
    cout << "suma +5" << endl;
    v1 + 5;    
    v1.print();
    cout << endl;
    
    cout << "resta"<< endl;
    v1 - v2;
    v1.print();
    cout << endl;
    
    cout << "resta -1"<< endl;
    v1 - 1;
    v1.print();
    cout << endl;
    
    cout << "multiplicación" << endl;
    v1 * v2;
    v1.print();
    cout << endl;
    
    cout << "multiplicación x2" << endl;
    v1 * 2;
    v1.print();
    cout << endl;
    
    return 0;
}