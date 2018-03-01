#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( int argc, char** argv ) {
    ifstream fin;

    if ( argc != 2 ) {
        cout << "usage: files <vector_file>" << endl;
        return 1;
    }

    // alias para el nombre de archivo
    char* filename = argv[1];

    // abre el archivo
    fin.open(filename);

    // verifica que el archivo esté abierto
    if ( !fin.is_open() ) {
        cout << "No se pudo abrir " << filename << "." << endl;
        return 2;
    }

    double buffer[10];
    for ( int i=0; i<10; i++ ) {

        // si el archivo tuviera menos de 10 elementos, falla
        if ( fin.eof() ) {
            cout << "archivo incorrecto" << endl;
            return 3;
        }

        // captura elemento a elemento
        fin >> buffer[i];
    }

    fin.close();

    // imprime el vector
    cout << "v = [";
    for ( int i=0; i<9; i++ ) {
        cout << buffer[i] << ", ";
    }
    cout << buffer[9] << "]" << endl;

    return 0;
}

