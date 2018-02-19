#include "token.h"

void Token::setStr(char* str){
    cadena = str;
}
void Token::setSep(char* str){
    separador = str;
}

int Token::ntokens(char* str, char sep=' ') {
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
    n = count;
    return n;
}

char Token::seeStr(){
    char cad = cadena[1];
    return cad;
}

// volver a poner el default char* separador = (char*)= " "
bool Token::token(char* out, const int n, char sep=' ') {
    int i = 0;     // indice para str
    int j = 0;     // indice para out
    int count = 0; // contador de palabras

    while ( 1 ) {
        while ( cadena[i] == sep ) i ++;
        if ( cadena[i] == '\n' || cadena[i] == 0 ) return false;
        while ( cadena[i] == ' ' ) i++; // consume espacios al inicio
        if ( cadena[i] != sep && cadena[i] != '\n' && cadena[i] != 0 ) count ++;
        while ( cadena[i] != sep && cadena[i] != '\n' && \
                cadena[i] != 0 )
        {
            if ( count == n ) {
                out[j] = cadena[i];
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
