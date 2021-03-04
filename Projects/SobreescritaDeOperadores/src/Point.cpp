#include <iostream>
#include "Point.h"

std::ostream & operator << (std::ostream &out, const Point &p) {
    return out << "(" <<  p.getX() << ", " << p.getY() << ")";
}

std::istream & operator >> (std::istream &in,  Point &p) {
    in >> p.x >> p.y;
    return in;
}

Point Point::operator + (const Point &p) {
    Point newPoint( this->x + p.getX(), this->y + p.getY());
    return newPoint;
}

Point& Point::operator += (const Point &p) {
    this->x += p.getX();
    this->y += p.getY();
    return *this;
}