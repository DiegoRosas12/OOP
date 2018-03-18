#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <fstream>
#include <cmath>

class Matrix {
    public:
        Matrix();
        Matrix( int rows, int cols, double value = 0.0 );
        Matrix( int rows, int cols, const double* data);
        Matrix( const char* filename );
        Matrix( const Matrix& cp );
        ~Matrix();

        bool clear();
        bool set( int rows, int cols, double value = 0.0 );
        bool set( int rows, int cols, const double* data );
        void copy( const Matrix& cp );
        Matrix copy() const;
        bool load( const char* filename );
        bool save( const char* filename ) const;
        int rows() const;
        int cols() const;
        void print() const;

        double& at( int row, int col );

        bool add( const Matrix& B );
        bool add( double c );
        bool sub( const Matrix& B );
        bool sub( double c );
        bool mult( const Matrix& B );
        bool mult( double c );
        bool dot( const Matrix& B );

        Matrix& operator=( const Matrix& B );
        double& operator()( int row, int col );
        bool operator==( const Matrix& B );
        bool operator!=( const Matrix& B );

        Matrix operator+( const Matrix& B );
        Matrix operator+( const double c );

        Matrix operator-( const Matrix& B );
        Matrix operator-( const double c );

        Matrix operator*( const Matrix& B );
        Matrix operator*( const double c );

        // Función amiga (friend). Al ser una función amiga, le estamos dando
        // permiso de accesar a los elementos privados de la clase. La función
        // se define fuera de la clase (es una función global) pero la siguiente
        // línea le otorga los permisos anteriormente mencionados.
        friend std::ostream& operator<<( std::ostream& os, const Matrix& M );

    private:
        int m_rows;
        int m_cols;
        int m_size;
        double* m_data;
};

std::ostream& operator<<( std::ostream& os, const Matrix& M );

#endif

