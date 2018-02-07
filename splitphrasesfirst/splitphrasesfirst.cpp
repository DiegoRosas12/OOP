// string::find_first_of
#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t
#include <vector>

using namespace std;
/*
void split(string s){
    size_t inicio = s.find_first_of(' ');
    while (inicio!=string::npos) {
    while(s[inicio+1] == ' '){
        inicio++;
    }
    s[inicio]='\n';
    inicio = s.find_first_of(' ',inicio+1);
  }
  cout << s << '\n';
}
*/
void splitv(string s, vector<string> &v){
  string palabra;
  int i=0;
  size_t inicio=0, fin;
  while (inicio!=string::npos) {
    while(s[inicio] == ' '){
      inicio++;
    }
    fin = s.find(' ',inicio);
    palabra = s.substr(inicio,(fin-inicio));
    inicio = fin;
    v.push_back(palabra);
    i++;
  }
}

int main () {
  vector<string> v;
  string s;
  int i;
  cout << "Introduce la cadena: ";
  getline(cin,s);
  splitv(s,v);
 for(i=0;i<v.size();i++){
    cout << v[i] << endl;
  }
  //cout << s << '\n';

  return 0;
}