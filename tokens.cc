#include <iostream>
using namespace std;

// dice cuantos tokens hay en una cadena
int ntokens(char* str, char sep=' ') {
    int i = 0;     // indice para str
    int count = 0; // contador de palabras

    while ( 1 ) {
        // consume todos los separadores
        while ( str[i] == sep ) i ++;

        // si halla el fin de linea, finaliza el conteo
        if ( str[i] == '\n' || str[i] == 0 ) break;

        while ( str[i] == ' ' ) i++; // consume espacios al inicio

        // si no es espacio ni fin de línea, encontró un token, contarlo
        if ( str[i] != sep && str[i] != '\n' && str[i] != 0 ) count ++;

        // consume el token (hasta hallar un espacio o fin de línea)
        while ( str[i] != sep && str[i] != '\n' && \
                str[i] != 0 ) i ++;

        while ( str[i] == ' ' ) i++; // consume espacios al final

    }

    // regresa el número de tokens en la cadena
    return count;
}

// regresa el token n en out
// out = cadena donde se guardará el token
// in  = cadena donde se buscará el token
// n   = número de token deseado [1,n]
bool token(char* out, const char* in, const int n, char sep=' ') {
    int i = 0;     // indice para str
    int j = 0;     // indice para out
    int count = 0; // contador de palabras

    while ( 1 ) {
        while ( in[i] == sep ) i ++;
        if ( in[i] == '\n' || in[i] == 0 ) return false;
        while ( in[i] == ' ' ) i++; // consume espacios al inicio
        if ( in[i] != sep && in[i] != '\n' && in[i] != 0 ) count ++;
        while ( in[i] != sep && in[i] != '\n' && \
                in[i] != 0 )
        {
            if ( count == n ) {
                out[j] = in[i];
                j ++;
            }

            i ++;
        }
        if ( count == n ) {
            j --;
            while ( out[j] == ' ') j--; // consume espacios al final
            out[j+1] = 0;
            break;
        }
    }

    return true;
}

int main( int argc, char** argv ) {

    // verifica el número de argumentos
    if ( argc != 3 ) {
        cout << "usage: ./tokens <sep> <string>" << endl;
        return 1;
    }

    // alias
    char* sepstr = argv[1];
    char* input = argv[2];

    char sep = sepstr[0];

    char out[200];
    int i = 1;
    while ( token(out, input, i, sep) ) {
        cout << i << ": \"" << out << "\"" << endl;
        i ++;
    }

    return 0;
}

