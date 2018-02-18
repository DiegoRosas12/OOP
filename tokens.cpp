// Universidad de Guanajuato
// Diego Eduardo Rosas Gonzalez
#include <iostream>
using namespace std;

// regresa el token n en out
// out = cadena donde se guardará el token
// in  = cadena donde se buscará el token
// n   = número de token deseado [1,n]
bool token(char* out, const char* in, const int n, char* separador = (char*)" ") {
    int i = 0;     // indice para str
    int j = 0;     // indice para out
    int l = 0;     // contador independiente para el numero de letras de la palabra
    int count = 0; // contador de palabras
    
    while ( 1 ) {
        // consume todos los espacios
        while ( (in[i] == ' ')||in[i]==*separador) i ++;
        // verifica si se ha encontrado el fin de línea, en cuyo caso la función
        // falla, porque no ha encontrado el token
        if ( in[i] == '\n' || in[i] == 0 ) return false;
        // si no es fin de línea ni es espacio, se halló un token, contarlo
        count ++;
        // consumir los caracteres del token hasta encontrar un espacio o el
        // fin de linea
        while ( (in[i] != *separador) && in[i] != '\n' && in[i] != 0 )
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

int main( int argc, char** argv ) {

    // verifica el número de argumentos
    if (argc !=2 && argc != 3) {
        cout << "usage: ./tokens <string> <separador>" << endl;
        return 1;
    }

    // alias
    char* sep;
    char* input = argv[1];
    char out[200];
    int i = 1;

    if (argc == 2){
        sep = (char*)" ";
    }else{
        sep = argv[2];
    }
    while ( token(out, input, i, sep) ) {
        cout << i << ": \"" << out << "\"" << endl;
        i ++;
    }

    return 0;
}

