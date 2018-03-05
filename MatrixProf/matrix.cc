#include "matrix.h"

Matrix::Matrix() {
   rows = 0;
   cols = 0;
   data = nullptr;
}

// constructor copia
Matrix::Matrix( const Matrix& copy ) {
    rows = copy.rows;
    cols = copy.cols;
    size = copy.size;

    data = new double[size];
    for ( int i=0; i<size; i++ ) data[i] = copy.data[i];
}

Matrix::Matrix( int rows, int cols, double* data) : Matrix() {
    set(rows, cols, data);
}

Matrix::Matrix( char* filename ) : Matrix() {
    load(filename);
}

Matrix::~Matrix() {
    clear();
}


bool Matrix::clear() {

    if ( data != nullptr ) {
        delete [] data;

        rows = 0;
        cols = 0;
        data = nullptr;
        return true;
    }

    return false;
}

bool Matrix::set( int rows, int cols, double* data ) {

    if ( rows < 1 || cols < 1 ) return false;

    clear();

    (*this).rows = rows;
    (*this).cols = cols;
    (*this).size = rows*cols;
    (*this).data = new double[size];

    for ( int i=0; i<size; i++ ) (*this).data[i] = data[i];
    return true;
}

int Matrix::getrows() {
    return (*this).rows;
}

int Matrix::getcols() {
    return (*this).cols;
}

void Matrix::print() {
   std::cout << "(" << rows << " x " << cols << ") =" << std::endl;
   for ( int i=0; i<rows; i++ ) {
       std::cout << " ";
       for ( int j=0; j<cols; j++ ) {
           std::cout << data[cols*i+j] << " ";
       }
       std::cout << std::endl;
   }
   std::cout << std::endl;
}

bool Matrix::load( char* filename ) {
    std::ifstream fs;

    fs.open(filename);
    if ( !fs.is_open() ) return false;

    int nrows, ncols;

    if ( fs.eof() ) return false;

    fs >> nrows;

    if ( fs.eof() ) return false;

    fs >> ncols;

    if ( ncols < 1 || nrows < 1 ) return false;

    clear();

    rows = nrows;
    cols = ncols;
    size = ncols * nrows;
    data = new double[size];

    for ( int i=0; i<size; i++ ) {
        fs >> data[i];
    }

    fs.close();

    return true;
}

bool Matrix::save( char* filename ) {
    std::ofstream fs;

    fs.open(filename);
    if ( !fs.is_open() ) return false;

    fs << rows << std::endl;
    fs << cols << std::endl;
    for ( int i=0; i<rows; i++ ) {
        fs << data[cols*i+0];
        for ( int j=1; j<cols; j++ ) {
            fs << " " << data[cols*i+j];
        }
        fs << std::endl;
    }

    fs.close();

    return true;
}

