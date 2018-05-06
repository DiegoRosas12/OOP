#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "lodepng.h"
#include "color.h"


class Image {
    public:

        // formatos de imagen soportados
        enum class Format { PPM, PNG };

        // constructor por defecto. Inicializa los atributos.
        Image();

        // constructor que crea una imagen nueva.
        Image( int width, int height );

        // constructor que carga una imagen de un archivo.
        Image( const std::string filename );

        // constructor copia, que crea una imagen nueva a partir de otra.
        Image( const Image& cp );

        // destructor
        ~Image();

        // método para liberar la memoria dinámica del objeto y restablecer los
        // valores de los atributos a cero.
        bool clear();

        // método para crear una imagen nueva a partir de sus dimensiones.
        bool set( int width, int height );

        // método para copiar otro objeto tipo Image.
        bool copy( const Image& cp );

        // método para cargar una imagen desde un archivo PPM.
        bool load( const std::string filename );

        // mpetodo para guardar la información de la imagen contenida en el
        // objeto en un archivo PPM
        bool save( const std::string filename, Format type ) const;

        // regresa una *referencia* al píxel indicado
        // Al ser una referencia, se puede leer o escribir el valor del pixel
        // NOTA: En las imágenes, el píxel (0,0) es el que se encuentra en la
        // esquina superior izquierda. Es decir, el eje y está invertido con
        // respecto al plano cartesiano.
        Color& at( int x, int y );

        // Regresa el ancho de la imagen en píxeles.
        int width() const;

        // Regresa el alto de la imagen en píxeles.
        int height() const;

        Image& operator=( const Image& im );
        Color& operator()( int x, int y );
        bool operator==( const Image& im );
        bool operator!=( const Image& im );

    private:
        int    m_width;
        int    m_height;
        Color* m_data;

        // Dado que m_data es un vector, hay que convertir las coordenadas (x,y)
        // en un índice para este vector. Este método hace eso.
        int index( int x, int y ) const;

        // carga el contenido de una imagen PPM (P3) particularmente
        bool load_ppm( const std::string filename );

        // guarda el contenido del objeto en una imagen PPM (P3)
        bool save_ppm( const std::string filename ) const;

        bool load_png( const std::string filename );

        bool save_png( const std::string filename ) const;
};

# endif

