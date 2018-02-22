#include <iostream>
#include "destructor.h"

using namespace std;

int main( int argc, char** argv ) {
    char out[256];

    if ( argc != 3 ) {
        cout << "usage: tokens <sep> <string>" << endl;
        return 1;
    }

    // alias
    char* string = argv[2];
    char* sep = argv[1];

    // creamos el objeto
    Token tk(string, sep[0]);

    cout << "cadena = \"" << string << "\"" << endl;
    cout << "número de tokens = " << tk.ntokens() << endl;
    for ( int i=1; i<=tk.ntokens(); i++ ) {
        if ( !tk.token(out,i) ) break;
        cout << i << ": \"" << out << "\"" << endl;
    }

    return 0;
}

