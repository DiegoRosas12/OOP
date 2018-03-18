#ifndef _IMAGE_H_
#define _IMAGE_H_

<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "lodepng.h"
#include "color.h"
=======
#include <string>
>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac


class Image {
    public:
<<<<<<< HEAD

        // formatos de imagen soportados
        enum class Format { PPM, PNG };

=======
>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac
        // constructor por defecto. Inicializa los atributos.
        Image();

        // constructor que crea una imagen nueva.
        Image( int width, int height );

        // constructor que carga una imagen de un archivo.
<<<<<<< HEAD
        Image( const std::string filename );
=======
        Image( std::string filename );
>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac

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
<<<<<<< HEAD
        bool load( const std::string filename );

        // mpetodo para guardar la información de la imagen contenida en el
        // objeto en un archivo PPM
        bool save( const std::string filename, Format type ) const;
=======
        bool load( char* filename );

        // mpetodo para guardar la información de la imagen contenida en el
        // objeto en un archivo PPM
        bool save( char* filename );
>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac

        // Obtiene el píxel en la posición (x,y)
        // NOTA: En las imágenes, el píxel (0,0) es el que se encuentra en la
        // esquina superior izquierda. Es decir, el eje y está invertido con
        // respecto al plano cartesiano.
<<<<<<< HEAD
        Color getpixel( int x, int y ) const;

        // Cambia el color del píxel en (x,y) por el proporcionado mediante px.
        bool setpixel( int x, int y, const Color px );
        bool setpixel( int x, int y, const Color& px );

        // Regresa el ancho de la imagen en píxeles.
        int width() const;

        // Regresa el alto de la imagen en píxeles.
        int height() const;
        
        Image& operator=(const Image& im);
        Color& operator()(int x, int y);
        bool operator==(const Image& im);
        bool operator!=(const Image& im);
        double& at(int x, int y);
=======
        Pixel get( int x, int y );

        // Cambia el color del píxel en (x,y) por el proporcionado mediante px.
        bool set( int x, int y, Pixel& px );

        // Regresa el ancho de la imagen en píxeles.
        int width();

        // Regresa el alto de la imagen en píxeles.
        int height();
>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac

    private:
        int    m_width;
        int    m_height;
<<<<<<< HEAD
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
=======
        Pixel* m_data;

        // Dado que m_data es un vector, hay que convertir las coordenadas (x,y)
        // en un índice para este vector. Este método hace eso.
        int index( int x, int y );
>>>>>>> d5ab66d44dea98324977e8ead81eed8a20df1aac
};

# endif

