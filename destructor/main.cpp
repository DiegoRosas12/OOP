// Universidad de Guanajuato
// Diego Eduardo Rosas Gonzalez

#include <iostream>
#include "destructor.h"
using namespace std;

int main(int argc, char** argv) {
    // verifica el número de argumentos
    if ( argc != 3 ) {
        cout << "usage: ./tokens <sep> <string>" << endl;
        return 1;
    }
    char* string = argv[2];
    char* sep = argv[1];

    Token tok(string, sep);
    cout << "ntokens = " << tok.getN() <<endl;
    cout << "sep = " << tok.getSep() << endl;
    
    char out[200];
    int i = 1;

    cout << "Numero de tokens: " << tok.ntokens() << endl;
    while ( tok.token(out, i) ) {
        cout << i << ": \"" << out << "\"" << endl;
        i ++;
    }
    
    return 0;
}
