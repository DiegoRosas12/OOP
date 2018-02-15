#include <iostream>
using namespace std;

// dice cuantos tokens hay en una cadena
int ntokens(char* str) {
    int i = 0;     // indice para str
    int count = 0; // contador de palabras

    while ( 1 ) {
        // consume todos los espacios
        while ( str[i] == ' ' ) i ++;

        // si halla el fin de linea, finaliza el conteo
        if ( str[i] == '\n' || str[i] == 0 ) break;

        // si no es espacio ni fin de línea, encontró un token, contarlo
        count ++;

        // consume el token (hasta hallar un espacio o fin de línea)
        while ( str[i] != ' ' && str[i] != '\n' && \
                str[i] != 0 ) i ++;
    }

    // regresa el número de tokens en la cadena
    return count;
}

// regresa el token n en out
// out = cadena donde se guardará el token
// in  = cadena donde se buscará el token
// n   = número de token deseado [1,n]
bool token(char* out, const char* in, const int n) {
    int i = 0;     // indice para str
    int j = 0;     // indice para out
    int count = 0; // contador de palabras

    while ( 1 ) {
        // consume todos los espacios
        while ( in[i] == ' ' ) i ++;

        // verifica si se ha encontrado el fin de línea, en cuyo caso la función
        // falla, porque no ha encontrado el token
        if ( in[i] == '\n' || in[i] == 0 ) return false;

        // si no es fin de línea ni es espacio, se halló un token, contarlo
        count ++;

        // consumir los caracteres del token hasta encontrar un espacio o el
        // fin de linea
        while ( in[i] != ' ' && in[i] != '\n' && \
                in[i] != 0 )
        {
            // si el token actual es el deseado, guardarlo en cout
            if ( count == n ) {
                out[j] = in[i];
                j ++;
            }

            // siguiente caracter
            i ++;
        }

        // si el token recién consumido era el token deseado
        if ( count == n ) {
            out[j] = 0; // agrega el caracter nulo para finalizar la cadena
            break;      // rompe el while infinito
        }
    }

    // si todo sale bien, la función regresa true
    return true;
}

int main( int argc, char** argv ) {

    // verifica el número de argumentos
    if ( argc != 2 ) {
        cout << "usage: ./tokens <string>" << endl;
        return 1;
    }

    // alias
    char* input = argv[1];

    char out[200];
    int i = 1;
    while ( token(out, input, i) ) {
        cout << i << ": \"" << out << "\"" << endl;
        i ++;
    }

    return 0;
}

