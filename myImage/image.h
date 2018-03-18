#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <string>
#include <fstream>
#include <string>
#include "pixel.h"


class Image {
    public:
        // constructor por defecto. Inicializa los atributos.
        Image();

        // constructor que crea una imagen nueva.
        Image( int width, int height );

        // constructor que carga una imagen de un archivo.
        Image( char* filename );

        // constructor copia, que crea una imagen nueva a partir de otra.
        Image( const Image& copy );

        // destructor
        ~Image();

        // método para liberar la memoria dinámica del objeto y restablecer los
        // valores de los atributos a cero.
        bool clear();

        // método para crear una imagen nueva a partir de sus dimensiones.
        bool set( int width, int height );

        // método para cargar una imagen desde un archivo PPM.
        bool load( char* filename );

        // mpetodo para guardar la información de la imagen contenida en el
        // objeto en un archivo PPM
        bool save( char* filename );

        // Obtiene el píxel en la posición (x,y)
        // NOTA: En las imágenes, el píxel (0,0) es el que se encuentra en la
        // esquina superior izquierda. Es decir, el eje y está invertido con
        // respecto al plano cartesiano.
        Pixel get( int x, int y );

        // Cambia el color del píxel en (x,y) por el proporcionado mediante px.
        bool set( int x, int y, Pixel& px );

        // Regresa el ancho de la imagen en píxeles.
        int width();

        // Regresa el alto de la imagen en píxeles.
        int height();

    private:
        int    m_width;
        int    m_height;
        int    m_maxValue;
        int    m_size;
        std::string  m_type;
        Pixel* m_data;

        // Dado que m_data es un vector, hay que convertir las coordenadas (x,y)
        // en un índice para este vector. Este método hace eso.
        int index( int x, int y );
};

# endif

