// Universidad de Guanajuato
// Diego Eduardo Rosas Gonzalez

#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream fin;

    int i=0;
    int m = 3;
    int n = 3;
    int size = m*n;
    int numeros[9] = {5,5,2,4,5,6,8,1,9};


    if (argc == 2) {
    char * filename = argv[1];
    fin.open(filename);
    if ( !fin.is_open() ) {
        cout << "No se abrio archivo " << filename << "." << endl;
        return 2;
    }
    Matrix A(m,n,numeros);
    
    }
    for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(A.valor()+i)+j);
        }
    cout<<endl;
    }
    fin.close();
    return 0;
}
