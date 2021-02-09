#include "Ponto4D.hpp"
#include "Ponto3D.hpp"
#include <iostream>
#include <math.h>

void Ponto4D::setW(double w) {
    this->_w = w;
}

std::string Ponto4D::to_string() const {
    std::string tmp_string = "(" + std::to_string(this->_x) + ",";
    tmp_string += std::to_string(this->_y) +",";
    tmp_string += std::to_string(this->_z) + ",";
    tmp_string += std::to_string(this->_w) + ")";
    return tmp_string;
}

double Ponto4D::distancia(Ponto* p) const {
    Ponto4D* p2 = dynamic_cast<Ponto4D*>(p);
    double dist = pow(this->getX() - p2->getX(), 2);
    dist += pow(this->getY() - p2->getY(),2);
    dist += pow(this->getZ() - p2->getZ(),2);
    dist += pow(this->getW() - p2->getW(),2);
    return sqrt(dist);
}
