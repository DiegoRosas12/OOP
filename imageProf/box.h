#ifndef _BOX_H_
#define _BOX_H_

#include "color.h"
#include "point.h"
#include "shape.h"

class Box : public Shape {
    public:
        Box();

        Box( Point topleft, Point bottomright,
             Color fill=Color::Name::BLACK );

        virtual bool inside( Point& pt );

    //protected:
};

#endif

