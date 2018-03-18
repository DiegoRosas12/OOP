#include "color.h"


Color::Color() {
    r = 0;
    g = 0;
    b = 0;
    a = 0;
}

Color::Color( int gray, int alpha ) {
    r = gray;
    g = gray;
    b = gray;
    a = alpha;
}

Color::Color( int red, int green, int blue, int alpha ) {
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

Color( VGA name ) {

    a = 255;
    switch( name ) {
        case BLACK:
            r = 0;
            g = 0;
            b = 0;
            break;
        case GRAY:
            r = 128;
            g = 128;
            b = 128;
            break;
        case SILVER:
            r = 192;
            g = 192;
            b = 192;
            break;
        case WHITE:
            r = 255;
            g = 255;
            b = 255;
            break;
        case MAROON:
            r = 128;
            g = 0;
            b = 0;
            break;
        case RED:
            r = 255;
            g = 0;
            b = 0;
            break;
        case OLIVE:
            r = 128;
            g = 128;
            b = 0;
            break;
        case YELLOW:
            r = 255;
            g = 255;
            b = 0;
            break;
        case GREEN:
            r = 0;
            g = 128;
            b = 0;
            break;
        case LIME:
            r = 0;
            g = 255;
            b = 0;
            break;
        case TEAL:
            r = 0;
            g = 128;
            b = 128;
            break;
        case AQUA:
        case CYAN:
            r = 0;
            g = 255;
            b = 255;
            break;
        case NAVY:
            r = 0;
            g = 0;
            b = 128;
            break;
        case BLUE:
            r = 0;
            g = 0;
            b = 255;
            break;
        case PURPLE:
            r = 128;
            g = 0;
            b = 128;
            break;
        case FUCHSIA:
        case MAGENTA:
            r = 255;
            g = 0;
            b = 255;
            break;
        case CLEAR:
        default:
            r = 0;
            g = 0;
            b = 0;
            a = 0;
    }
}

void Color::print() {
    std::cout << "RGBA";
    std::cout << "(" << int(r) << "," << int(g) << "," << int(b);
    std::cout << "," << int(a) << ")" << std::endl;
}

