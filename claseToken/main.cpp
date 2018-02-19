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
    tok.setStr(argv[2]);
    tok.setSep(argv[1]);

    char* input = argv[2];
    
    char* sepstr = argv[1];    
    char sep = sepstr[0];

    char out[200];
    int i = 1;
    
    cout << "Numero de tokens: " << tok.ntokens(input,sep) << endl;
    while ( tok.token(out, input, i, sep) ) {
        cout << i << ": \"" << out << "\"" << endl;
        i ++;
    }
    
    return 0;
}