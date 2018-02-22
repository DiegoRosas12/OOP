#include "token.h"

Token::Token() {
    m_sep = 0;
    m_ntokens = 0;
    m_buffer[0] = 0;
}

Token::Token(char* string, char sep) {
    set(string, sep);
}

void Token::set(char* string, char sep) {
    int i = 0;

    while ( string[i] != 0 ) {
        m_buffer[i] = string[i];
        i ++;
    }

    m_sep = sep;
    m_ntokens = token_count();
}

int Token::ntokens() {
    return m_ntokens;
}

char Token::sep() {
    return m_sep;
}

int Token::token_count() {
    int i = 0;     // indice para str
    int count = 0; // contador de palabras

    while ( 1 ) {
        while ( m_buffer[i] == m_sep ) i ++;
        while ( m_buffer[i] == ' ' ) i++;
        if ( m_buffer[i] == '\n' || m_buffer[i] == 0 ) break;
        if ( m_buffer[i] != m_sep ) count ++;
        while ( m_buffer[i] != m_sep && m_buffer[i] != '\n' && \
                m_buffer[i] != 0 ) i ++;
        while ( m_buffer[i] == ' ' ) i++;
    }

    // regresa el número de tokens en la cadena
    return count;
}

bool Token::token(char* out, int n) {
    int i = 0;     // indice para str
    int j = 0;     // indice para out
    int count = 0; // contador de palabras

    while ( 1 ) {
        while ( m_buffer[i] == m_sep ) i ++;
        while ( m_buffer[i] == ' ' ) i++;
        if ( m_buffer[i] == '\n' || m_buffer[i] == 0 ) return false;
        if ( m_buffer[i] != m_sep ) count ++;
        while ( m_buffer[i] != m_sep && m_buffer[i] != '\n' && \
                m_buffer[i] != 0 )
        {
            if ( count == n ) {
                out[j] = m_buffer[i];
                j ++;
            }

            i ++;
        }
        if ( count == n ) {
            j --;
            while ( out[j] == ' ') j--; // consume espacios al final
            out[j+1] = 0;
            break;
        }
    }

    return true;
}


