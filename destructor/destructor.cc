#include "destructor.h"

Token::Token() {
    *separador = 0;
    n = 0;
    cadena = (char*)" ";
}
Token::Token(char* string, char* sep){
    setCadena(string);
    setSep(sep);
}

void Token::setCadena(char* str){
    cadena = str;
}
void Token::setSep(char* str){
    separador = str;
}

int Token::getN(){
    return n;
}

char Token::getSep(){
    return separador[0];
}

int Token::ntokens() {
    int i = 0;     // indice para str
    int count = 0; // contador de palabras

    while ( 1 ) {
        // consume todos los separadores
        while ( cadena[i] == *separador ) i ++;

        // si halla el fin de linea, finaliza el conteo
        if ( cadena[i] == '\n' || cadena[i] == 0 ) break;

        while ( cadena[i] == ' ' ) i++; // consume espacios al inicio

        // si no es espacio ni fin de línea, encontró un token, contarlo
        if ( cadena[i] != *separador && cadena[i] != '\n' && cadena[i] != 0 ) count ++;

        // consume el token (hasta hallar un espacio o fin de línea)
        while ( cadena[i] != *separador && cadena[i] != '\n' && \
                cadena[i] != 0 ) i ++;

        while ( cadena[i] == ' ' ) i++; // consume espacios al final

    }

    // regresa el número de tokens en la cadena
    n = count; // Guarda el resultado en n de la clase token
    return n;
}

// volver a poner el default char* separador = (char*)= " "
bool Token::token(char* out, const int n) {
    int i = 0;     // indice para str
    int j = 0;     // indice para out
    int count = 0; // contador de palabras

    while ( 1 ) {
        while ( cadena[i] == *separador ) i ++;
        if ( cadena[i] == '\n' || cadena[i] == 0 ) return false;
        while ( cadena[i] == ' ' ) i++; // consume espacios al inicio
        if ( cadena[i] != *separador && cadena[i] != '\n' && cadena[i] != 0 ) count ++;
        while ( cadena[i] != *separador && cadena[i] != '\n' && \
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
