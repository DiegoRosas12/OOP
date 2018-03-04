#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <fstream>

class Matrix {
    public:
        Matrix();
        Matrix(int rows, int cols, double*data);
        Matrix(char* filename);
        ~Matrix();

        bool clear();
        bool set(int rows, int cols, double* data);
        bool load(char* filename);
        bool save(cahr* filename);
    private:
        int rows;
        int cols;
        double* data;
}
#endif