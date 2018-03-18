#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

class Vector {
    public:
    Vector();
    Vector(int nelem);
    Vector(const Vector& copy);
    ~Vector();
    double& at(int index);
    double& operator[] (int index);
    Vector& operator=(const Vector &copy);
    Vector& operator+ (double i);
    Vector& operator+ (Vector i);
    void set(int rows, int cols);
    Vector& operator- (Vector v);
    Vector& operator- (double i);

    Vector& operator* (Vector v);
    Vector& operator* (double i);
    void print();

    private:
    int m_nelem;
    double* m_data;
    int m_rows;
    int m_cols;
};
#endif