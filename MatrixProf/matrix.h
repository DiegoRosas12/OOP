#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <fstream>

class Matrix {
    public:
        Matrix();
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

    private:
        int rows;
        int cols;
        int size;
        double* data;
};

#endif

