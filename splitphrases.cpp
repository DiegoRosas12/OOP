#include <iostream>
#include <string>

using namespace std;
int main() {
    int i=0;
    string s, s2;
    size_t inicio, fin;
    cout << "Introduce la cadena: ";
    getline(cin,s);
    cout << s << endl;

    do{
    inicio = s.find(' ',i);
    i = inicio;
    s2 = s.substr (inicio+1,fin);
    cout << inicio <<endl;
    
    cout << s2 << endl;
    }while(inicio != npos);

}