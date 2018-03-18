#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <fstream>
<<<<<<< HEAD
#include <cmath>
=======
>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac

class Matrix {
    public:
        Matrix();
<<<<<<< HEAD
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

=======
        Matrix( int rows, int cols, double* data);
        Matrix( char* filename );
        Matrix( const Matrix& copy );
        ~Matrix();

        bool clear();
        bool set( int rows, int cols, double* data );
        bool load( char* filename );
        bool save( char* filename );

        //void add();
        int getrows();
        int getcols();

        void print();

        bool Matrix::add(const Matrix& B);

    private:
        int rows;
        int cols;
        int size;
        double* data;
};

>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac
#endif

