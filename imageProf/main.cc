#include <iostream>
#include "image.h"
#include "color.h"
#include "point.h"
#include "circle.h"
#include "box.h"
#include "poly.h"
#include "regular.h"
#include "group.h"

using namespace std;

int main() {
    Image im(800,600);
    Color pixel;
    Point pt;



    Circle obj(Point(400.0,300.0), 175.0, Color::Name::GREEN);
    //Box obj( Point(100,100), Point(400, 400), Color::Name::PURPLE );
    Regular pol(Point(400.0,300.0), 175, 6,Color::Name::RED);


    for ( int j=0; j<600; j++ ) {
        for ( int i=0; i<800; i++ ) {
            //pt = Point(double(i),double(j));
            //pixel = obj.test(pt);
            pixel = pol.test(Point(double(i),double(j)));
            im(i,j) = pixel;
        }
    }

    im.save("image.png", Image::Format::PNG);

    return 0;
}

