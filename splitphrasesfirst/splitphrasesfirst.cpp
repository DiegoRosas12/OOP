// string::find_first_of
#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t
#include <vector>

using namespace std;

void split(string s, vector v){
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

int main () {
  vector<string> v;
  string s;
  cout << "Introduce la cadena: ";
  getline(cin,s);
/*
  size_t inicio = s.find_first_of(' ');
  while (inicio!=string::npos) {
    while(s[inicio+1] == ' '){
        inicio++;
    }
    s[inicio]='\n';
    inicio=s.find_first_of(' ',inicio+1);
  }
*/
  split(s);
  //cout << s << '\n';

  return 0;
}