#include <iostream>
#include "image.h"
#include "color.h"
#include "point.h"
#include "circle.h"
#include "box.h"
#include "poly.h"
#include "regular.h"

using namespace std;

int main() {
    Image im(800,600);
    Color pixel;
    Point pt;



    Circle obj(Point(400.0,300.0), 175.0, Color::Name::GREEN);
    //Box obj( Point(100,100), Point(400, 400), Color::Name::PURPLE );

    //double delta = 0.00000001;
    //vector<Point> vert;
    //vert.push_back(Point(340+delta, 420+delta)); // 1
    //vert.push_back(Point(490+delta, 390+delta)); // 2
    //vert.push_back(Point(490+delta, 270+delta)); // 3
    //vert.push_back(Point(370+delta, 120+delta)); // 4
    //vert.push_back(Point(280+delta, 270+delta)); // 5
    //Poly obj( vert, Color::Name::RED );

    //Regular obj(Point(400.0, 300.0), 100.0, 7, Color::Name::BLUE );

    for ( int j=0; j<600; j++ ) {
        for ( int i=0; i<800; i++ ) {
            //pt = Point(double(i),double(j));
            //pixel = obj.test(pt);
            pixel = obj.test(Point(double(i),double(j)));
            im(i,j) = pixel;
        }
    }

    im.save("image.png", Image::Format::PNG);

    return 0;
}

