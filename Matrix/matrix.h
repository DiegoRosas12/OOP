#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix {
    private:
    int m_m; //filas
    int m_n; // columnas
    int **matrix;
    bool creado = true;
    

    public:
    // Constructores
    Matrix();
    Matrix(char* filename);
    Matrix(int m, int n, int vector[]);
    // Destructor
    ~Matrix();

    // Metodos
    char* m_filename;
    void set(int m, int n, int vector[]);
    bool load(char* filename);
    bool save(char* filename);
    void add(int n);
    void add(Matrix b);
    void sub(int n);
    void sub(Matrix b);
    void mult(Matrix b);
    void dot(Matrix b, int n2);
    int** valor();
    int getM();
    int getN();
    bool clear();

};

#endif