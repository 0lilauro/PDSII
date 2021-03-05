/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include <algorithm>  
#include "polygon.h"
#include <typeinfo>

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

// Eu alterei
bool operator > (const Point &lhs, const Point &rhs) {
    return (lhs.x >= rhs.x && lhs.y >= rhs.y) ? true : false;
}

// Eu alterei
bool operator < (const Point &lhs, const Point &rhs) {
    return rhs < lhs;
}

// Eu alterei
bool operator == (const Polygon &lhs, const Polygon &rhs) {
    bool response = false;

    std::vector<Point> lpoints = std::vector<Point>(lhs);
    std::vector<Point> rpoints = std::vector<Point>(rhs);
    unsigned left_size = lpoints.size();
    unsigned equality = 0;
    if (left_size == rpoints.size() && left_size > 0) {
        for (unsigned i = 0; i < (left_size); i++) {
            for (unsigned j = 0; j < (left_size); j++) {
                if(lpoints[i].contains(rpoints[j])) {
                    equality+=1;
                    break;
                }
            }
        }
        if(equality == left_size) {
            response = true;
        }
    }
    return response;
}


bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

// Eu alterei
bool RightRectangle::contains(const Point& p) const {
    bool response = true;

    int min_x  = this->limits[0].x;
    int max_x  = this->limits[0].x;
    int min_y  = this->limits[0].y;
    int max_y  = this->limits[0].y;

    for(Point eachPoint : this->limits) {
        min_x = std::min(min_x, eachPoint.x);
        max_x = std::max(max_x, eachPoint.x);
        min_y = std::min(min_y, eachPoint.y);
        max_y = std::max(max_y, eachPoint.y);
    } 
    if (max_x < p.x || min_x > p.x || max_y < p.y || min_y > p.y) {
        response = false;
    }
    return response;
}

// Eu alterei
Point::Point(int xx, int yy): x(xx), y(yy) {
    this->limits.push_back(*this);
}
// Eu alterei
RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
    //  colocar um iff para verificar se é um ponto 
    Point p1(x0, y0);
    Point p2(x1, y1);
    Point p3(x1, y0);
    Point p4(x0, y1);
    if(p1.contains(p2) && p1.contains(p3) && p1.contains(p4)) {
            this->limits.push_back(p1);
    } else {
        this->limits.push_back(p1);
        this->limits.push_back(p2);
        this->limits.push_back(p3);
        this->limits.push_back(p4);
    }    
}