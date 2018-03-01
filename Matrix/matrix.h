#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix {
    private:
    int m_m; //filas
    int m_n; // columnas
    int **matrix;

    public:
    // Constructores
    Matrix();
    Matrix(char[]);
    Matrix(int m, int n, int vector[]);
    // Destructor
    ~Matrix();

    //void clear();
    // Metodos
    void set(int m, int n, int vector[]);
    void load(char[]);
    void save(char[]);
    void add(int n);
    void add(int** m);
    void sub(int n);
    void sub(int** m);
    void mult(int** m);
    void dot(int** m);
    int** valor();

};

#endif