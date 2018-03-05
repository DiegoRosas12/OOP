#include "pixel.h"


Pixel::Pixel() {
    r = 0;
    g = 0;
    b = 0;
    a = 0;
}

Pixel::Pixel( int gray, int alpha) {
    r = gray;
    g = gray;
    b = gray;
    a = alpha;
}

Pixel::Pixel( int red, int green, int blue, int alpha) {
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

void Pixel::print() {
    std::cout << "RGBA";
    std::cout << "(" << int(r) << "," << int(g) << "," << int(b);
    std::cout << "," << int(a) << ")" << std::endl;
}

