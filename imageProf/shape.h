#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "point.h"
#include "color.h"
#include "bbox.h"

class Shape {
    public:
        Shape();
        virtual ~Shape();

        Color& fill();

        Bbox& bbox();

        virtual bool inside( Point& pt ) = 0; // makes abstract class

        Color test( Point pt );

        Color test( Point& pt );

    protected:
        Color m_fill;
        Bbox  m_bbox;
};

#endif

