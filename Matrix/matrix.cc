#include "matrix.h"
#include <fstream>
using namespace std;
 // Constructores
Matrix::Matrix(){
    m_m = 0;
    m_n = 0;
    matrix = nullptr;
}

Matrix::Matrix(char* filename){
    load(filename);
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
bool Matrix::load(char* filename){
    if(creado){
    ifstream fin;
    fin.open(filename);
    if ( !fin.is_open() ) {
        return false;
    }
    fin >> m_m;
    fin >> m_n;
    creado = true;
    matrix = new int*[m_m];
    for(int i=0; i<m_n; i++){
        matrix[i] = new int[m_n];
    }

    for ( int i=0; i<m_n; i++ ) {
        for(int j=0;j<m_m;j++){
        // captura elemento a elemento
        fin >> matrix[i][j];
        }
    }
    fin.close();
    return true;
    /////////////////////////////////////
    }
    return true;
    /*else{
        ifstream fin2;
    fin2.open(filename);
    if ( !fin2.is_open() ) {
        return false;
    }
    creado = true;
    fin2 >> m_m;
    fin2 >> m_n;
    matrixb = new int*[m_m];
    for(int i=0; i<m_n; i++){
        matrixb[i] = new int[m_n];
    }

    for ( int i=0; i<m_n; i++ ) {
        for(int j=0;j<m_m;j++){
        // captura elemento a elemento
        fin2 >> matrixb[i][j];
        }
    }
    fin2.close();
    return true;
    }
    */
}
bool Matrix::save(char* filename){
    ofstream fout;
    fout.open(filename);
    if ( !fout.is_open() ) {
        return false;
    }
    for ( int i=0; i<m_n; i++ ) {
        for(int j=0;j<m_m;j++){
        fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
    return true;
}

void Matrix::add(int n){
    for(int i=0; i<m_n;i++){
        for(int j=0; j<m_m;j++){
            matrix[i][j] = matrix[i][j] + n;
        }        
    }
}
void Matrix::add(Matrix b){
    for(int i=0; i<m_n;i++){
        for(int j=0; j<m_m;j++){
            matrix[i][j] = matrix[i][j] + *(*(b.valor()+i)+j);
        }        
    }

}
void Matrix::sub(int n){
    for(int i=0; i<m_n;i++){
        for(int j=0; j<m_m;j++){
            matrix[i][j] = matrix[i][j] - n;
        }        
    }

}
void Matrix::sub(Matrix b){
    for(int i=0; i<m_n;i++){
        for(int j=0; j<m_m;j++){
            matrix[i][j] = matrix[i][j] - *(*(b.valor()+i)+j);
        }        
    }

}
void Matrix::mult(Matrix b){
    for(int i=0; i<m_n;i++){
        for(int j=0; j<m_m;j++){
            matrix[i][j] = (matrix[i][j]) * (*(*(b.valor()+i)+j));
        }        
    }

}
void Matrix::dot(Matrix b, int n2){
    for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_n; j++)
                for (int k = 0; k < m_m; k++)
                    matrix[i][j] += matrix[i][k] * (*(*(b.valor()+i)+j));

}
int** Matrix::valor(){
    return matrix;
}
int Matrix::getM(){
    return m_m;
}
int Matrix::getN(){
    return m_n;
}
