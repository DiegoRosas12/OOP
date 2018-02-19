#ifndef _CLASETOKEN_H
#define _CLASETOKEN_H

class Token {
    private:
    char *cadena;
    char *separador;
    int n=0;

    public:
    char seeStr();
    void setStr(char* str);
    void setSep(char* str);
    int ntokens(char* str, char sep);    
    bool token(char* out, const char* in, const int n, char separador);
};

#endif