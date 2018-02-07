//Universidad de Guanajuato
//Diego Eduardo Rosas Gonzalez
//Programacion Orientada a Objetos

#include <iostream>       // std::cout
#include <string>         // std::string
#include <vector>

using namespace std;

void split(string s, vector<string> &v){ //hay manera de hacer el valor return de la funcion igual al vector pero encontre esta manera de hacerlo por referencia.
  string palabra;
  int i=0;
  size_t inicio=0, fin;//Contadores de inicio de la palabra y final de la palabra
  while (inicio!=string::npos) {//si la funcion find no encuentra el espacio entonces devuelve npos y ahi acaba el ciclo
    while(s[inicio] == ' '){ //mientras haya espacios el contador inicio avanza
      inicio++;
    }
    fin = s.find(' ',inicio);//busca el primer espacio a partir de la posicion de inicio.
    palabra = s.substr(inicio,(fin-inicio));// El 1er argumento de substr es donde inicia la nueva cadena(inicio)
    //el segundo argumento es su longitud. Como fin marca donde acaba la nueva palabra entronces la longitud de esa palabra es fin-inicio.
    inicio = fin;//hace que los dos contadores partan del mismo nuevo punto
    v.push_back(palabra);//agrega la palabra al vector y automaticamente reserva memoria y la pone en su lugar consecutivo.
    i++;
  }
}

int main () {
  vector<string> v;
  string s;
  int i;
  cout << "Introduce la cadena: ";
  getline(cin,s);
  split(s,v);
 for(i=0;i<v.size();i++){
    cout << v[i] << endl;
  }
  return 0;
}