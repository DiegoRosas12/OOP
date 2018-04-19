#include <iostream>
#include "image.h"
#include "color.h"
#include "point.h"
#include "circle.h"

using namespace std;

int main( int argc, char** argv ) {
    
    Image im(800,600);
    Color pixel;
    Point pt;

    Circle circ(Point(400.0,300.0), 175.0, Color::VGA::CYAN);
    
    for (int j=0; j<600; j++){
        for (int i=0; i<800; i++){
            pt = Point(double(i), double(j));
            pixel = circ.test(pt);

            im.at(i,j) = pixel;
        }
    }
    
    /*
    Image im(800,600);
    double d;

    double cx = 400;
    double cy = 300;
    double r = 150;

    for(int y=0; y<im.height(); y++){
        for (int x=0; x<im.width(); x++){
        d = (x-cx)*(x-cx) + (y-cy)*(y-cy);
        if (d <= r*r) {
            im.at(x,y) = Color::VGA::RED;
        } 
        else {
            im.at(x,y) = Color::VGA::WHITE;
        }
        }
    }
    */
    im.save("circle.png", Image::Format::PNG);
    return 0;
}

