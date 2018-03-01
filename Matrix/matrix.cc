#include "matrix.h"

 // Constructores
Matrix::Matrix(){
    m_m = 0;
    m_n = 0;
    matrix = nullptr;
    
}
Matrix::Matrix(char[30]){

}
Matrix::Matrix(int m, int n, int vector[]){
    m_m = m;
    m_n = n;
    matrix = new int*[m];
    for(int i=0; i<n; i++){
        matrix[i] = new int[n];
    }
    set(m,n,vector); 

}
Matrix::~Matrix(){
    for(int i=0;i<m_m;i++){
            delete [] matrix[i];
    }
    delete [] matrix;
    matrix = nullptr;
    m_m = 0;
    m_n = 0;
}
// Metodos
void Matrix::set(int m, int n, int vector[]){
    int k = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            matrix[i][j] = vector[k];
            k++;
    }
    }
}
void Matrix::load(char[30]){

}
void Matrix::save(char[30]){

}
void Matrix::add(int n){

}
void Matrix::add(int** m){

}
void Matrix::sub(int n){

}
void Matrix::sub(int** m){

}
void Matrix::mult(int** m){

}
void Matrix::dot(int** m){

}
int** Matrix::valor(){
    return matrix;
}