#ifndef _PIXEL_H_
#define _PIXEL_H_

#include <iostream>

// Estructura Pixel
// Las estructuras tienen atributos y métodos públicos por default.
// Fuera de eso, son idénticas a las clases, aunque se usan para tipos de datos
// más simples, como Pixel. Nótese que los atributos se pueden accesar
// directamente porque son públicos. Aún así, se cuenta con algunas comodidades
// como los constructores.
//
// Ejemplos de uso:
//
// Pixel px1(0, 128, 0);
// Pixel px2 = px1;
// Pixel px3;
// Pixel px4(35);
// px3 = Pixel(0, 0, 255);
// px1.b = 255;
// px2.r = 255;
// px4.a = 128;
//
struct Pixel {

    // constructor por defecto, inicializa todo en cero
    // el color resultante es completamente transparente
    Pixel();

    // constructor que inicializa el píxel con un tono de gris
    // el canal alpha es opcional, y por default es 255 (completamente opaco)
    Pixel( int gray, int alpha=255);

    // constructor que inicializa el píxel con un color RGB
    // el canal alpha es opcional, y por default es 255 (completamente opaco)
    Pixel( int red, int green, int blue, int alpha=255);

    // imprime el píxel en stdout
    void print();

    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

#endif

