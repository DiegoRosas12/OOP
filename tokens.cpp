#include <iostream>
using namespace std;
// dice cuantos tokens hay en una cadena
int ntokens(char* str){
    int i=0; // Índice para str
    int count = 0; // Contador de palabras
    //consume todos los espacios
    while(1) {
        while(str[i] == ' ') i++;
        if(str[i] == '\n' || str[i] == 0) break;
        count++;
        //El backslash indica que la condición continua abajo 
        while(str[i] != ' ' && str[i] != '\n' &&  \
        str[i] != 0) i++;
        i++;
    }
    return count;
}
// regresa el token n en out
bool token(char* out, char* in, int n){ //char* out = char out[]
    int i=0; // Indice para str
    int j=0; // Indice para out
    int count = 0; // Contador de palabras
    //consume todos los espacios
    while(1) {
        while(in[i] == ' ') i++;
        if(in[i] == '\n' || in[i] == 0) false;
        count++;
        //El backslash indica que la condición continua abajo 
        while(in[i] != ' ' && in[i] != '\n' &&  \
        in[i] != 0) {
            if (count==n){
            out[j] = in[i];
            j++;
        }
        i++;
    }
    if(count == n){
        out[j] = 0; // agrega el caracter nulo
        break;
    }
    return true;
}
}

int main() {
    //char cadena[] = "Cadena de texto puro\n";
    char buffer[200];
    cout << "Ingrese la cadena de caracteres" << endl;
    cin.getline(buffer,200);

    int n = ntokens(buffer);
    cout << n <<endl;
    int k;
    cout << "que token quiere?: ";
    cin >> k;
    cout << "eligio" << k << endl;

    char out[200];
    /*if(!token(out, buffer, k)) {
        cout << "El token" << k << " no existe" << endl;
        return 1;
    }
    */
    //cout << "token: \"" << out << "\"" << endl;
    for(int i=0; i<n; i++){
        token(out, buffer, i+1);
        cout << i+1 << ": " << out << endl;
    }
    return 0;
}