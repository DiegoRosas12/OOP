// Universidad de Guanajuato
// Diego Eduardo Rosas Gonzalez

#include <iostream>
#include "destructor.h"
using namespace std;

int main(int argc, char** argv) {
    // verifica el número de argumentos
    char* str;
    char* sep;
    if ( argc == 2) {
        str = argv[1];
    }else if (argc == 3){
        str = argv[2];
        sep = argv[1];
    }else{
        cout << "usage: ./tokens <sep> <string>" << endl;
        return 1;
    }
    Token tok(str,sep);
    char** p;
    
    char out[200];
    //int i = 1;
    int i=1,k=0;
    char c;
    cout << "separador = \"" << tok.getSep() << "\"" << endl;
    cout << "Numero de tokens: " << tok.num() << endl;
    
    for(i=1;i<tok.num();i++) {
    while(tok.get(i,k) != 0)
    c = tok.get(i,k);
    cout << c;
    cout << endl;
    k++;
    }
    return 0;
}
