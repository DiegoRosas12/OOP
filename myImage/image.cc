#include "image.h"

Image::Image(){
    m_width = 0;
    m_height = 0;
    m_size = 0;
    m_type[0] = 0;
    m_type[1] = 0;
    m_data = nullptr;
}

// constructor que crea una imagen nueva.
Image::Image( int width, int height ){
    m_width = width;
    m_height = height;
}

// constructor que carga una imagen de un archivo.
Image::Image( char* filename ){
    load(filename);
}

// constructor copia, que crea una imagen nueva a partir de otra.
Image::Image( const Image& copy ){
    m_width = copy.m_width;
    m_height = copy.m_height;
    m_size = copy.m_size;
    m_data = new Pixel[m_size];
    for ( int i=0; i<m_height; i++ ){
        for(int j=0; j<m_width; j++){
        set( i,j, copy.m_data[index(i,j)] );
        }
    }
}

// destructor
Image::~Image(){
    clear();
}

// método para liberar la memoria dinámica del objeto y restablecer los
// valores de los atributos a cero.
bool Image::clear(){
    if ( m_data != nullptr ) {
        delete [] m_data;

        m_width = 0;
        m_height = 0;
        m_data = nullptr;
        m_type[0] = 0;
        m_type[1] = 1;
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
    m_data = new Pixel[m_size]; // Pixel o double?
    return true;    

}

// método para cargar una imagen desde un archivo PPM.
bool Image::load( char* filename ){
    std::ifstream fs;

    fs.open(filename);
    if ( !fs.is_open() ) return false;

    int width, height, max;
    std::string type;
    if ( fs.eof() ) return false;
    fs >> type;
    if ( fs.eof() ) return false;
    fs >> width;
    if ( fs.eof() ) return false;
    fs >> height;
    if ( fs.eof() ) return false;
    fs >> max;
    if ( width < 1 || height < 1 ) return false;
    
    clear();

    m_type = type;
    m_width = width;
    m_height = height;
    m_size = width*height;
    m_data = new Pixel[m_size];

    fs.close();
    return true;

}

// mpetodo para guardar la información de la imagen contenida en el
// objeto en un archivo PPM
bool Image::save( char* filename ){
    std::ofstream fs;

    fs.open(filename);
    if ( !fs.is_open() ) return false;
    
    fs << m_type[0]; fs << m_type[1] << std::endl;
    fs << m_width << std::endl;
    fs << m_height << std::endl;

    for (int i=0; i<m_height; i++ ) {
        for (int  j=1; j<m_width; j++ ) {
            fs << " " << int(m_data[index(i,j)].r);
            fs << " " << int(m_data[index(i,j)].g);
            fs << " " << int(m_data[index(i,j)].b);
        }
    }
    
    return true;
}

// Obtiene el píxel en la posición (x,y)
// NOTA: En las imágenes, el píxel (0,0) es el que se encuentra en la
// esquina superior izquierda. Es decir, el eje y está invertido con
// respecto al plano cartesiano.
Pixel Image::get( int x, int y ){
    return m_data[index(x,y)];
}

// Cambia el color del píxel en (x,y) por el proporcionado mediante px.
bool Image::set( int x, int y, Pixel& px ){
    m_data[index(x,y)].r = px.r;
    m_data[index(x,y)].g = px.g;
    m_data[index(x,y)].b = px.b;
    return true;
        
}

// Regresa el ancho de la imagen en píxeles.
int Image::width(){
    return m_width;
}

// Regresa el alto de la imagen en píxeles.
int Image::height(){
    return m_height;
}

int Image::index( int x, int y ){
    return m_width*x+y;
}