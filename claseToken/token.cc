#include "token.h"

void Token::setStr(char* str){
    cadena = str;
}
void Token::setSep(char* str){
    cadena = str;
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
bool Token::token(char* out, const char* in, const int n, char separador =' ') {
    int i = 0;     // indice para str
    int j = 0;     // indice para out
    int l = 0;     // contador independiente para el numero de letras de la palabra
    int count = 0; // contador de palabras
    
    while ( 1 ) {
        // consume todos los espacios
        while ( (in[i] == ' ')||in[i]==separador) i ++;
        // verifica si se ha encontrado el fin de línea, en cuyo caso la función
        // falla, porque no ha encontrado el token
        if ( in[i] == '\n' || in[i] == 0 ) return false;
        // si no es fin de línea ni es espacio, se halló un token, contarlo
        count ++;
        // consumir los caracteres del token hasta encontrar un espacio o el
        // fin de linea
        while ( (in[i] != separador) && in[i] != '\n' && in[i] != 0 )
        {
            // si el token actual es el deseado, guardarlo en cout
            if ( count == n ) {
                out[j] = in[i];
                j ++;
            }
            // siguiente caracter
            i ++; 
        }
        l = 0;
        while(out[l] != 0 && out[l] != '\n'){
            l++; // total de letras en la cadena
        }
        while(out[l] == ' '|| out[l] == 0){
            l--; // resta si hay espacio o es el final de línea
        }
       // inserta el caracter nulo al final de la palabra
       // tambien inserta el caracter nulo en l+2 porque en la ultima palabra no hacia el recorte
        out[l+1] = 0;
        out[l+2] = 0;
        // si el token recién consumido era el token deseado
        if ( count == n ) {
            out[j] = 0; // agrega el caracter nulo para finalizar la cadena
            break;      // rompe el while infinito
        }
    }
    // si todo sale bien, la función regresa true
    return true;
}
