#ifndef _CIRCLE_H
#define _CIRCLE_H

class Circle {
    public:

    Circle();
    Circle(double x, double y);
    Circle(double x, double y, double radius);
    Circle(const Circle& copy);
    ~Circle();

    bool set(double posx, double posy, double radius);
    bool draw();

    private:

    double m_posx;
    double m_posy;
    double m_radius;

};

#endif