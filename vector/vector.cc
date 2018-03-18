#include "vector.h"
Vector::Vector(){
    m_nelem = 0;
    m_data = nullptr;
}
Vector::Vector(int nelem){
    if(nelem < 1) return;
    m_nelem = nelem;
    m_data = new double[nelem];

    // inicializar el vector con ceros
    for (int i=0; i<nelem; i++) m_data[i] = 0.0;
}
Vector::~Vector(){
    if (m_data != nullptr){
        delete [] m_data;
    }
}

Vector &Vector::operator=(const Vector &copy){
    if(m_data != nullptr){
        delete m_data;
        m_data = nullptr;
    }

    m_nelem = copy.m_nelem;

    if (copy.m_nelem > 0){
        m_data = new double[m_nelem];
        for (int i=0;i< m_nelem;i++)
            m_data[i] = copy.m_data[i];
    }
    return *this;
}

Vector::Vector(const Vector& copy): Vector(){
    if (copy.m_data != nullptr) {
        m_nelem = copy.m_nelem;
        m_data = new double[m_nelem];
        for (int i=0;i< m_nelem; i++) m_data[i] = copy.m_data[i];
    }
}
double& Vector::at(int index){
    return m_data[index];
}
double& Vector::operator[] (int index){
    return m_data[index];
}
Vector& Vector::operator+ (Vector v){
    for (int j=0; j<m_nelem; j++){
       m_data[j] += v.m_data[j];
    }
    return *this;
}
Vector& Vector::operator+ (double i){
    for (int j=0; j<m_nelem; j++){
       m_data[j] += i;
    }
    return *this;

}
Vector& Vector::operator- (Vector v){
    for (int j=0; j<m_nelem; j++){
       m_data[j] += v.m_data[j];
    }
    return *this;

}
Vector& Vector::operator- (double i){
    for (int j=0; j<m_nelem; j++){
       m_data[j] += i;
    }
    return *this;
    
}
Vector& Vector::operator* (double i){
    for (int j=0; j<m_nelem; j++){
       m_data[j] += i;
    }
    return *this;
    
}
Vector& Vector::operator* (Vector v){
    for (int j=0; j<m_nelem; j++){
       m_data[j] *= v.m_data[j];
    }
    return *this;
    
}
void Vector::print(){
    for(int i=0; i<m_rows;i++){
       for(int j=0; j<m_cols; j++){
       std::cout << m_data[j] << " ";
       }
    std::cout << std::endl;
    }
}
void Vector::set(int rows, int cols){
    m_rows = rows;
    m_cols = cols;
} 