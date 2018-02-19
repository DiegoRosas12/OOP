// Universidad de Guanajuato
// Diego Eduardo Rosas Gonzalez

#include <iostream>
#include "token.h"
using namespace std;

int main(int argc, char** argv) {
    // verifica el número de argumentos
    if ( argc != 3 ) {
        cout << "usage: ./tokens <sep> <string>" << endl;
        return 1;
    }
    Token tok;
    tok.setCadena(argv[2]);
    tok.setSep(argv[1]);

    char out[200];
    int i = 1;
    
    cout << "Numero de tokens: " << tok.ntokens() << endl;
    while ( tok.token(out, i) ) {
        cout << i << ": \"" << out << "\"" << endl;
        i ++;
    }
    
    return 0;
}