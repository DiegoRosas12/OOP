#ifndef _DESTRUCTOR_H
#define _DESTRUCTOR_H

class Token {
    public:

        Token(); // constructor por defecto

        Token(char* string, char sep=' ');

        // Mutación (mutators)
        void set(char* string, char sep=' ');

        // Acceso (accessors)
        int ntokens();
        char sep();
        bool token(char* out, int n);

    private:
        char m_sep;
        int  m_ntokens;
        char m_buffer[256];

        int token_count();
};

#endif
