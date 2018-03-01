#ifndef _DESTRUCTOR_H
#define _DESTRUCTOR_H

class Token {
    private:
    char cadena[256];
    char *separador=(char*)' ';
    char **array;
    int n=0;
    int getN();
    void clear(char **array);

    public:
    Token(); // constructor por defecto
    ~Token();
    Token(char* str, char* sep=(char*)' ');
    char get(int x, int y);
    // Mutators
    void set(char* str, char* sep=(char*)' ');
    bool getTok(char* out, const int n);
    // Accessors
    char getSep();
    int num();    
    
};

#endif