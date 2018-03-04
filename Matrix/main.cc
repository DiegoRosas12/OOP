// Universidad de Guanajuato
// Diego Eduardo Rosas Gonzalez

#include <iostream>
#include <fstream>
#include "matrix.h"


using namespace std;

int main(int argc, char** argv) {

    int i=0;
    int m = 3;
    int n = 3;
    int numeros[9] = {5,5,2,4,5,6,8,1,9};

    if (argc == 2) {
    char* filename = argv[1];
    Matrix A(filename);
    
     for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(A.valor()+i)+j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    
//////////////////////////////////////////////////////
    }else if (argc ==3){
    char* filename = argv[1];
    char* filename2 = argv[2];
    Matrix A(filename);
    cout << "A: " << endl;
     for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(A.valor()+i)+j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    Matrix B(filename2);
    cout << "B: " << endl;
    for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(B.valor()+i)+j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    A.add(B);
    cout << "suma A+B: " << endl;
    for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(A.valor()+i)+j) << " ";
        }
        cout << endl;
    }
    
    A.sub(B);
    cout << "resta A-B: " << endl;
    for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(A.valor()+i)+j) << " ";
        }
        cout << endl;
    }
    
    A.mult(B);
    cout << "multiplica elemento a elemento A*B: " << endl;
    for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(A.valor()+i)+j) << " ";
        }
        cout << endl;
    }
    if (A.getN() == B.getM()){
    A.mult(B);
    cout << "multiplicacion matricial A*B: " << endl;
    for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(A.valor()+i)+j) << " ";
        }
        cout << endl;
    }
    }else{
        cout << "el tamano de las matrices no permite la multiplicacion" << endl;
    }
    /////////////////////////////////////
    A.save((char*)"resultado.txt");
    }else{
        Matrix A(m,n,numeros);
        
        for (i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << *(*(A.valor()+i)+j) << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
