#include "destructor.h"

// Constructor
Token::Token(char* str, char* sep){
    //str = (char*)' ';
    set(str, sep);
    array = new char*[n];
    for(int i=0;i<n;i++)
        array[i] = new char[30];

    
}
void Token::set(char* str, char* sep){
    clear(array);
    int i=0;
    while(str[i] != 0){
    cadena[i] = *str;
    i++;
    }
    separador = sep;
    n = getN();
}
void Token::clear(char **myarray){
    int i=0;
    separador = (char*)' ';
    cadena[i] = 0;
    n = 0;

}
Token::~Token(){
    clear(array);
    for(int i=0;i<n;i++){
    delete [] array[i];
    }
    delete array;
}
char Token::getSep(){
    return separador[0];
}
int Token::num() {
    return n;
}
int Token::getN() {
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
bool Token::getTok(char *out, const int n) {
    int i = 0;     // indice para str
    int j = 0;     // indice para out
    int count = 0; // contador de palabras
    int k = 0;     // indice para arreglo dinamico

    while ( 1 ) {
        while ( cadena[i] == *separador ) i ++;
        if ( cadena[i] == '\n' || cadena[i] == 0 ) return false;
        while ( cadena[i] == ' ' ) i++; // consume espacios al inicio
        if ( cadena[i] != *separador && cadena[i] != '\n' && cadena[i] != 0 ) count ++;
        while ( cadena[i] != *separador && cadena[i] != '\n' && \
                cadena[i] != 0 )
        {
            if ( count == n ) {
                array[n-1][j] = cadena[i];
                j ++;
            }

            i ++;
        }
        if ( count == n ) {
            j --;
            while ( array[n-1][j] == ' ') j--; // consume espacios al final
            array[n-1][j+1] = 0;
            k++;
            break;
        }
        k++;
    }
    return true;
}
char Token::get(int x, int y){
    int i=0;
    //while(array[a-1][i] != 0){
    return array[x][y];
    //i++;
   // }
}
