// Universidad de Guanajuato
// Diego Eduardo Rosas Gonzalez

#ifndef _LINEMY_H_
#define _LINEMY_H_

#include "point.h"

class LineMy{
    public:

    LineMy();
    LineMy(Point a1, Point b1);
    bool set(Point A1, Point B1);
    bool inter(Point& pt, LineMy L1, LineMy L2);
    Point intersec;

    private:
    Point a1;
    Point b1;
    double m;
    double b;
    double x; // valor en caso de que la línea sea paralela
    bool isVertical();
    bool isParallel(LineMy L1, LineMy L2);
    void clear();
};

#endif