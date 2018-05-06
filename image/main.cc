#include <iostream>
#include "image.h"
#include "color.h"
#include "point.h"
#include "circle.h"
#include "box.h"
#include "regular.h"

using namespace std;

int main()
{
    Image im(800, 600);
    Color pixel;
    Point pt;

    Circle circ(Point(400.0,300.0), 175.0, Color::Name::CYAN);
    Box bob(Point(100, 100), Point(400, 400), Color::Name::PURPLE);
    Regular penta(Point(400,300), 100, 5,  Color::Name::OLIVE );
    for (int j = 0; j < 600; j++)
    {
        for (int i = 0; i < 800; i++)
        {
            pt = Point(double(i), double(j));
            pixel = penta.test(pt);
            //im.at(i, j) = pixel;
            im(i, j) = pixel;
        }
    }

    im.save("circle.png", Image::Format::PNG);

    return 0;
}
