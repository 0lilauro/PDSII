#include "Ponto.hpp"
#include "Ponto2D.hpp"
#include <iostream>
#include <math.h>

Ponto2D::Ponto2D(double x, double y) {
    this->setX(x);
    this->setY(y);
}

void Ponto2D::setY(double y) {
    this->_y = y;
}

void Ponto2D::setX(double x) {
    this->_x = x;
}

std::string Ponto2D::to_string() const {
    std::string tmp_string = "(" + std::to_string(this->_x) + "," +  std::to_string(this->_y) + ")";
    return tmp_string;
}

double Ponto2D::distancia(Ponto* p) const {
    Ponto2D* p2 = dynamic_cast<Ponto2D*>(p);
    double dist = sqrt( pow(this->getX() - p2->getX(),2) + pow(this->getY() - p2->getY(),2));
    return dist;
}

void Ponto2D::converteParaPolar() {
    double r = sqrt(pow(this->_x, 2) + pow(this->_y, 2));
    double theta = atan((this->_y/ this->_x));
    this->_x = r; 
    this->_y = theta;
}