#ifndef _CLASETOKEN_H
#define _CLASETOKEN_H

class Token {
    private:
    char *cadena;
    char *separador=(char*)' ';
    int n=0;

    public:
    void setCadena(char* str);
    void setSep(char* str);
    int ntokens();    
    bool token(char* out, const int n);
};

#endif