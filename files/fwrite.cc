#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout;

    fout.open("prueba.txt");

    if ( !fout.is_open() ) {
        cout << "Fallo al abrir el archivo." << endl;
        return 1;
    }

    for ( int i=0; i<10; i++ ) {
       fout << "línea " << i+1 << endl;
    }

    fout.close();

    return 0;
}

