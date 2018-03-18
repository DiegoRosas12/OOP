#include "matrix.h"

// constructor por defecto
Matrix::Matrix() {
   m_rows = 0;
   m_cols = 0;
   m_size = 0;
   m_data = nullptr;
}

// Constructor 1: Crea una matriz nueva con todos sus elementos igual a value.
Matrix::Matrix( int rows, int cols, double value ) : Matrix() {
    set(rows, cols, value);
}


// Constructor 2: Crea una matriz nueva cuyos elementos copia del vector data.
Matrix::Matrix( int rows, int cols, const double* data) : Matrix() {
    set(rows, cols, data);
}

// Constructor 3: Crea una matriz nueva a partir de los datos del archivo
// especificado por filename. El formato de archivo es el siguiente:
// no. de renglones
// no. de columnas
// datos consecutivos (rows*cols)
//
// Ejemplo:
// 3
// 3
// 1 2 3
// 4 5 6
// 7 8 9
//
Matrix::Matrix( const char* filename ) : Matrix() {
    load(filename);
}


// constructor copia
Matrix::Matrix( const Matrix& cp ) : Matrix() {
    copy(cp);
}


// destructor
Matrix::~Matrix() {
    clear();
}


// Si hay memoria reservada, la libera. Deja al objeto Matrix en un estado
// válido. Si borra la memoria, modifica los atributos a sus valores iniciales.
// La función regresa true si eliminó la memoria, o false si no hizo nada.
bool Matrix::clear() {

    if ( m_data != nullptr ) {
        delete [] m_data;

        m_rows = 0;
        m_cols = 0;
        m_data = nullptr;
        return true;
    }

    return false;
}


// Reescribe los atributos de un objeto tipo Matrix.
// Se le puede dar un tamaño nuevo, especificado por rows y cols. Además, se
// puede inicializar con un valor 'value' para todos los elementos de la matriz.
// Por default, value = 0.0.
bool Matrix::set( int rows, int cols, double value ) {

    // revisa que la nueva matriz tenga dimensiones válidas. Si no, se queda
    // como estaba.
    if ( rows < 1 || cols < 1 ) return false;

    // ya que set() puede ser llamado en cualquier momento, hay que borrar
    // cualquier memoria que esté reservada. Usamos clear() porque no queremos
    // repetir código por todas partes. Si clear() libera memoria, hay que
    // reutilizar el método.
    clear();

    // configura la nueva matriz.
    m_rows = rows;
    m_cols = cols;
    m_size = rows*cols;
    m_data = new double[m_size];

    // inicializa los valores de la matriz con value.
    for ( int i=0; i<m_size; i++ ) m_data[i] = value;

    return true;
}


// reescribe los atributos de un objeto tipo Matrix
// Se le puede dar un tamaño nuevo, especificado por rows y cols. Los valores de
// los elementos de la matriz son copiados del vector data. El usuario es
// responsable de proporcionar un vector válido.
bool Matrix::set( int rows, int cols, const double* data ) {

    if ( rows < 1 || cols < 1 ) return false;

    clear();

    m_rows = rows;
    m_cols = cols;
    m_size = rows*cols;
    m_data = new double[m_size];

    // inicializa los valores con los datos del vector data.
    for ( int i=0; i<m_size; i++ ) m_data[i] = data[i];

    return true;
}


// El método copy() copia la matriz proporcionada como cp en el objeto actual.
// La función no necesita regresar nada porque no hay casos de fallo.
void Matrix::copy( const Matrix& cp ) {

    // también hay que llamar a clear(), porque puede haber memoria reservada.
    clear();

    // se copian los atributos
    m_rows = cp.m_rows;
    m_cols = cp.m_cols;
    m_size = cp.m_size;

    // puede que cp sea la matriz nula, así que hay que verificar esto antes de
    // intentar reservar memoria
    if ( cp.m_size > 0 ) {

        // reserva memoria para los nuevos datos (copia)
        m_data = new double[m_size];

        // copia los valores de cp en el objeto actual.
        for ( int i=0; i<m_size; i++ ) m_data[i] = cp.m_data[i];
    }
}


// Otra forma de llamar a copy() es sin usar ningún parámetro. En este caso, el
// método copy() regresa una copia "dura" (osea, con su propia memoria) del objeto
// actual.
Matrix Matrix::copy() const {
    // crea un nuevo objeto de tipo Matrix
    Matrix C;

    // Copia el objeto actual en C.
    // Nótese que aquí se usa el otro método copy para crear la copia del objeto
    // actual (*this es un objeto Matrix).
    C.copy(*this);

    // regresa la copia en C.
    return C;
}


// Carga los datos del archivo filename en el objeto Matrix actual.
// El archivo es un archivo de texto con un formato sencillo. Consiste en una
// secuencia de números en base decimal separados por algún caracter de espacio
// (puede ser un espacio, un tabulador, un salto de línea etc.).
// El primer número del archivo es un entero que especifica el número de
// renglones de la matriz. El segundo número es también un entero, que
// especifica el número de columnas de la matrix. Los siguientes números pueden
// ser flotantes o enteros, y especifican los elementos de la matriz. El número
// total de estos elementos debe ser igual al alto por el ancho de la matriz
// (rows*cols).
bool Matrix::load( const char* filename ) {
    std::ifstream fs;

    fs.open(filename);
    if ( !fs.is_open() ) return false;

    int rows, cols;

    fs >> rows;
    fs >> cols;

    if ( fs.eof() ) return false;
    if ( cols < 1 || rows < 1 ) return false;

    clear();

    m_rows = rows;
    m_cols = cols;
    m_size = cols * rows;
    m_data = new double[m_size];

    for ( int i=0; i<m_size; i++ ) {
        fs >> m_data[i];
    }

    fs.close();

    return true;
}


// Este método guarda los datos del objeto Matrix en un archivo de texto con el
// formato requerido por load().
bool Matrix::save( const char* filename ) const {
    std::ofstream fs;

    fs.open(filename);
    if ( !fs.is_open() ) return false;

    fs << m_rows << std::endl;
    fs << m_cols << std::endl;
    for ( int i=0; i<m_rows; i++ ) {
        fs << m_data[m_cols*i+0];
        for ( int j=1; j<m_cols; j++ ) {
            fs << " " << m_data[m_cols*i+j];
        }
        fs << std::endl;
    }

    fs.close();

    return true;
}


// rergesa el número de renglones de la matriz
int Matrix::rows() const {
    return m_rows;
}


// regresa el número de columnas de la matriz
int Matrix::cols() const {
    return m_cols;
}


// Imprime la matriz en la salida estándar
// Este método está obsoleto, es mejor usar el operador operator<< ya que
// print() solo puede imprimir en la salida estándar, pero operator<< puede
// imprimir en cualquier stream de datos.
void Matrix::print() const {
   std::cout << "(" << m_rows << " x " << m_cols << ") =" << std::endl;
   for ( int i=0; i<m_rows; i++ ) {
       std::cout << " ";
       for ( int j=0; j<m_cols; j++ ) {
           std::cout << m_data[m_cols*i+j] << " ";
       }
       std::cout << std::endl;
   }
   std::cout << std::endl;
}

// Método at() regresa una referencia al elemento row,col de la matriz. Al ser
// una referencia, se puede usar para lectura y escritura.
double& Matrix::at( int row, int col ) {
    return m_data[m_cols*row+col];
}

// suma la matriz B con la matriz del objeto actual (*this)
bool Matrix::add( const Matrix& B ) {
   if ( m_rows != B.m_rows || m_cols != B.m_cols ) return false;

   for ( int i=0; i<m_size; i++ ) m_data[i] += B.m_data[i];
   return true;
}


// suma una constante c a la matriz del objeto actual (*this)
bool Matrix::add( double c ) {

   for ( int i=0; i<m_size; i++ ) m_data[i] += c;
   return true;
}


// resta la matriz B de la matriz del objeto actual (*this)
bool Matrix::sub( const Matrix& B ) {
   if ( m_rows != B.m_rows || m_cols != B.m_cols ) return false;

   for ( int i=0; i<m_size; i++ ) m_data[i] -= B.m_data[i];
   return true;
}


// resta una constante c a la matriz del objeto actual (*this)
bool Matrix::sub( double c ) {

   for ( int i=0; i<m_size; i++ ) m_data[i] -= c;
   return true;
}


// multiplica elemento a elemento la matriz B con la matriz del objeto actual
// (*this)
bool Matrix::mult( const Matrix& B ) {
   if ( m_rows != B.m_rows || m_cols != B.m_cols ) return false;

   for ( int i=0; i<m_size; i++ ) m_data[i] *= B.m_data[i];
   return true;
}


// multiplica una constante c con la matriz del objeto actual (*this)
bool Matrix::mult( double c ) {

   for ( int i=0; i<m_size; i++ ) m_data[i] *= c;
   return true;
}


// realiza el producto matricial entre la matriz actual y la matriz B, en ese
// orden.
bool Matrix::dot( const Matrix& B ) {

   if ( m_cols != B.m_rows ) return false;
   //  C(n x k) = A(n x m) B(m x k)

   int c_rows = m_rows;
   int c_cols = B.m_cols;
   int c_size = c_rows * c_cols;
   int m = m_cols; // m == A.m_cols == B.m_rows

   double* c_data = new double[c_size];

   for ( int j=0; j<c_rows; j++ ) {

       for ( int i=0; i<c_cols; i++ ) {

           c_data[c_cols*j+i] = 0.0;
           for ( int k=0; k<m; k++ ) {
               c_data[c_cols*j+i] += m_data[m_cols*j+k] * B.m_data[B.m_cols*k+i];
           }
       }
   }

   // swap
   clear();
   m_rows = c_rows;
   m_cols = c_cols;
   m_size = c_rows*c_cols;
   m_data = c_data;

   return true;
}


// Operador de asignación, permite asignar nuevos valores a matrices ya creadas.
// La memoria se maneja de forma interna con copy() para evitar el problema de
// la memoria compartida.
Matrix& Matrix::operator=( const Matrix& B ) {

    // copy() copia B en el objeto actual.
    copy(B);

    // se regresa una referencia al objeto actual.
    return *this;
}

// Equivalente a at(), pero no requiere especificar el nombre del método, lo
// cual simplifica su sintaxis. Se usa así:
// Matrix A(3,3);  // matriz con ceros
// A(0,0) = 1;     // creamos una matriz diagonal
// A(1,1) = 1;
// A(2,2) = 1;
//
double& Matrix::operator()( int row, int col ) {
    return m_data[m_cols*row+col];
}


// Operador lógico de igualdad, regresa true si dos matrices A y B son iguales,
// y regresa false si no lo son, por ejemplo:
//
// if ( A == B ) cout << "iguales" << endl;
//
bool Matrix::operator==( const Matrix& B ) {

    // error tolerable al comparar flotantes
    const double delta = 0.000001;

    if ( m_rows != B.m_rows ) return false;
    if ( m_cols != B.m_cols ) return false;
    if ( m_size != B.m_size ) return false;

    for ( int i=0; i<m_size; i++ ) {
        // la siguiente comparación no funciona bien con flotantes, ya que
        // algunos números no se pueden representar y las operaciones con
        // flotantes producen resultados con cierta inexactitud.
        //
        //if ( m_data[i] != B.m_data[i] ) return false;

        if ( std::abs(m_data[i]-B.m_data[i]) > delta ) return false;
    }

    return true;
}


// Operador lógico de desigualdad, regresa true si dos matrices A y B son
// iguales, y regresa false si no lo son, por ejemplo:
//
// if ( A != B ) cout << "iguales" << endl;
//
bool Matrix::operator!=( const Matrix& B ) {
    // podemos llamar al operador como si fuera un método cuyo nombre es
    // 'operator=='
    return !operator==(B);
}


// operador suma, permite realizar la suma de matrices de la forma C = A + B;
// donde C adquiere el valor de la suma de A y B. Las matrices A y B permanecen
// sin modificaciones después de este proceso (como se esperaría).
Matrix Matrix::operator+( const Matrix& B ) {

    // crea una copia del objeto actual, para no modificarlo.
    Matrix A(*this);

    // hace la suma entre A y B, el resultado se guarda en A
    // usa un método ya implementado para reutilizar el código
    A.add(B);

    // regresa el nuevo objeto A
    return A;
}

// operador suma, permite realizar la suma de una matriz y un escalar de la
// forma C = A + k; donde C adquiere el valor de la suma de A y k. La matriz A
// permanece sin modificaciones después de este proceso (como se esperaría).
Matrix Matrix::operator+( const double c ) {

    // crea una copia del objeto actual
    Matrix A(*this);

    // hace la suma entre A y el escalar c
    A.add(c);

    // regresa el nuevo objeto
    return A;
}

// operador resta, permite realizar la resta de matrices de la forma C = A - B;
// donde C adquiere el valor de la resta entre A y B. Las matrices A y B
// permanecen sin modificaciones después de este proceso (como se esperaría).
Matrix Matrix::operator-( const Matrix& B ) {

    // crea una copia del objeto actual
    Matrix A(*this);

    // hace la resta entre A y B
    A.sub(B);

    // regresa el nuevo objeto
    return A;
}

// operador resta, permite realizar la resta de una matriz y un escalar de la
// forma C = A + k; donde C adquiere el valor de la suma de A y k. La matriz A
// permanece sin modificaciones después de este proceso (como se esperaría).
Matrix Matrix::operator-( const double c ) {

    // crea una copia del objeto actual
    Matrix A = copy();

    // hace la resta entre A y el escalar c
    A.sub(c);

    // regresa el nuevo objeto
    return A;
}

// operador multiplicación, permite realizar la multiplicación de matrices de
// la forma C = A * B; donde C adquiere el valor de la multiplicación elemento a
// elemento entre A y B. Las matrices A y B permanecen sin modificaciones
// después de este proceso (como se esperaría).
Matrix Matrix::operator*( const Matrix& B ) {

    // crea una copia del objeto actual
    Matrix A = copy();

    // hace la multiplicación entre A y B
    A.mult(B);

    // regresa el nuevo objeto
    return A;
}

// operador multiplicación, permite realizar la multiplicación de una matriz y
// un escalar de la forma C = A * k; donde C adquiere el valor de la
// multiplicación entre A y k. La matriz A permanece sin modificaciones después
// de este proceso (como se esperaría).
Matrix Matrix::operator*( const double c ) {

    // crea una copia del objeto actual
    Matrix A = copy();

    // hace la multiplicación entre A y el escalar c
    A.mult(c);

    // regresa el nuevo objeto
    return A;
}


// operador de redirección, imprime la matriz M en un stream de datos.
// sobrecarga el operador << para usarlo en streams de datos de salida (ostream)
// funciona igual para cout, cerr o para un archivo
std::ostream& operator<<( std::ostream& os, const Matrix& M ) {
    for ( int i=0; i<M.m_rows; i++ ) {
        os << M.m_data[M.m_cols*i+0];
        for ( int j=1; j<M.m_cols; j++ ) {
            os << " " << M.m_data[M.m_cols*i+j];
        }
        os << std::endl;
    }

    return os;
}

