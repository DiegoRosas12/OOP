#include "image.h"

Image::Image(){
    m_width = 0;
    m_height = 0;
    m_size = 0;
    m_type = 0
    m_data = nullptr;
}

// constructor que crea una imagen nueva.
Image::Image( int width, int height ){
    m_width = width;
    m_height = height;
}

// constructor que carga una imagen de un archivo.
Image::Image( std::string filename ){
    load(filename);
}

// constructor copia, que crea una imagen nueva a partir de otra.
Image::Image( const Image& copy ){
    m_width = copy.m_width;
    m_height = copy.m_height;

    data = new double[size];
    for ( int i=0; i<size; i++ ) data[i] = copy.data[i];
}

// destructor
Image::~Image(){
    clear();
}

// método para liberar la memoria dinámica del objeto y restablecer los
// valores de los atributos a cero.
bool Image::clear(){
    if ( data != nullptr ) {
        delete [] data;

        m_width = 0;
        m_height = 0;
        data = nullptr;
        return true;
    }

    return false;
}

// método para crear una imagen nueva a partir de sus dimensiones.
bool Image::set( int width, int height ){
    if ( width < 1 || height < 1 ) return false;
    
    clear();

    m_width = width;
    m_height = height;
    m_size = width*height;            
    data = new Pixel[m_size]; // Pixel o double?
    return true;    

}

// método para cargar una imagen desde un archivo PPM.
bool Image::load( char* filename ){
    std::ifstream fs;

    fs.open(filename);
    if ( !fs.is_open() ) return false;


    if ( fs.eof() ) return false;
    fs >> m_type;
    if ( fs.eof() ) return false;
    fs >> m_width;
    if ( fs.eof() ) return false;
    fs >> m_height;
    if ( m_width < 1 || m_ < 1 ) return false;
        


}

// mpetodo para guardar la información de la imagen contenida en el
// objeto en un archivo PPM
bool Image::save( char* filename ){

}

// Obtiene el píxel en la posición (x,y)
// NOTA: En las imágenes, el píxel (0,0) es el que se encuentra en la
// esquina superior izquierda. Es decir, el eje y está invertido con
// respecto al plano cartesiano.
Pixel Image::get( int x, int y ){

}

// Cambia el color del píxel en (x,y) por el proporcionado mediante px.
bool Image::set( int x, int y, Pixel& px ){

}

// Regresa el ancho de la imagen en píxeles.
int Image::width(){
    return m_width
}

// Regresa el alto de la imagen en píxeles.
int Image::height(){
    return m_height;
}

int Image::index( int x, int y ){

}