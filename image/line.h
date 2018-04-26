#ifndef _LINE_H_
#define _LINE_H_
#include "point.h"

class Line {
    public:

    Line();
    Line(Point a1, Point b1);
    bool set(Point A1, Point B1);
    bool inter(Line L1, Line L2);

    private:
    Point a1;
    Point b1;
    Point intersec;
    double m;
    double b;
    double x; // valor en caso de que la línea sea paralela
    bool isVertical();
    bool isParallel(Line L1, Line L2);
    void clear();
};

#endif