#include "regular.h"
#include "cmath"

Regular::Regular(){
    m_center.x = 0;
    m_center.y = 0;

    m_radius = 0;

    m_sides = 0;
}
Regular::Regular( Point center, double radius, int sides, Color fill ) : Regular() {
    if (radius < 0.0) return;

    // define el bounding box
    m_bbox = Bbox(Point(center.x - radius, center.y - radius), Point(center.x + radius, center.y + radius));
    m_center = center;
    m_radius = radius;
    m_sides = sides;

    double gradsFrac = 2*3.1416 / double(sides);
    double countGrads = 0.0;
    Point p;

    // Crea un vector que contiene los vertices de la figura
    for (int i=0; i<sides; i++){
        // x =  radio * cos ( a (radianes ) + h
        // y = radio * sen ( a (radianes) )+ k
        p.x = radius * cos(countGrads) + center.x;
        p.y = radius * sin(countGrads) + center.y;
        m_points.push_back(p);
        countGrads += gradsFrac;
    }
    // Usa los puntos para crear un vector con los los aristas de la figura
    for(int j=0; j<sides-1; j++){
        // Line l(m_points[j], m_points[j+1]);
        // Falta unir el punto del inicio con el del final        
        m_lines.push_back(Line(m_points[j], m_points[j+1]));
    }
    
}
bool Regular::inside(Point pt){
    Point pt1(0,0);
    Point pt2 = pt;
    Point intersec;
    Line l(pt1, pt2); 
    int count=0;
    // int bwidth = ceil(m_bbox.bottomright().x - m_bbox.topleft().x);
    // int bheight = ceil(m_bbox.topleft().y - m_bbox.bottomright().y);
    // pt1 = m_bbox.topleft();

    if (!m_bbox.test(pt))
        return false;
    for (int i=0;i<m_sides;i++){
        if (m_lines[i].intersection(intersec, l)) count ++;
    }
    if (count % 2){
        return false;
    }else{
        return true;
    }
}
Color Regular::test(Point pt){
     if (inside(pt))
    {
        return m_fill;
    }
    // return Color(); // CLEAR
    return Color::Name::CLEAR;
}