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

//Color(VGA name) {
Color::Color(VGA name) {

    a = 255;
    // añadir VGA:: a los colores
    switch(name) {
        case VGA::BLACK:
            r = 0;
            g = 0;
            b = 0;
            break;
        case VGA::GRAY:
            r = 128;
            g = 128;
            b = 128;
            break;
        case VGA::SILVER:
            r = 192;
            g = 192;
            b = 192;
            break;
        case VGA::WHITE:
            r = 255;
            g = 255;
            b = 255;
            break;
        case VGA::MAROON:
            r = 128;
            g = 0;
            b = 0;
            break;
        case VGA::RED:
            r = 255;
            g = 0;
            b = 0;
            break;
        case VGA::OLIVE:
            r = 128;
            g = 128;
            b = 0;
            break;
        case VGA::YELLOW:
            r = 255;
            g = 255;
            b = 0;
            break;
        case VGA::GREEN:
            r = 0;
            g = 128;
            b = 0;
            break;
        case VGA::LIME:
            r = 0;
            g = 255;
            b = 0;
            break;
        case VGA::TEAL:
            r = 0;
            g = 128;
            b = 128;
            break;
        case VGA::AQUA:
        case VGA::CYAN:
            r = 0;
            g = 255;
            b = 255;
            break;
        case VGA::NAVY:
            r = 0;
            g = 0;
            b = 128;
            break;
        case VGA::BLUE:
            r = 0;
            g = 0;
            b = 255;
            break;
        case VGA::PURPLE:
            r = 128;
            g = 0;
            b = 128;
            break;
        case VGA::FUCHSIA:
        case VGA::MAGENTA:
            r = 255;
            g = 0;
            b = 255;
            break;
        case VGA::CLEAR:
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
bool Color::operator==(const Color& c){
    if (r!=c.r) return false;
    if (g!=c.g) return false;
    if (b!=c.b) return false;
    if (a!=c.a) return false;            
    
    return true;
}

bool Color::operator!=(const Color& c){
    return !operator==(c);
}

