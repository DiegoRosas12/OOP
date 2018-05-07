#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "point.h"
#include "color.h"
#include "bbox.h"

class Shape {
    public:
        Shape();
        virtual ~Shape();

        void set_fill(Color fill);

        Color get_fill() const;

        Bbox get_bbox() const;

        // Color& fill();

        // Bbox& bbox();

        // Método virtual puro
        virtual bool inside( Point& pt ) = 0; // makes abstract class

        Color test( Point pt );

        Color test( Point& pt );

    protected:
        Color m_fill;
        Bbox  m_bbox;
};

#endif

