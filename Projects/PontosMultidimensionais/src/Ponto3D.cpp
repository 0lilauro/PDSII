#include "Ponto3D.hpp"
#include "Ponto2D.hpp"
#include <iostream>
#include <math.h>

void Ponto3D::setZ(double z) {
    this->_z = z;
}

std::string Ponto3D::to_string() const {
    std::string tmp_string = "(" + std::to_string(this->_x) + ",";
    tmp_string += std::to_string(this->_y) +",";
    tmp_string += std::to_string(this->_z) + ")";
    return tmp_string;
}


double Ponto3D::distancia(Ponto* p) const {
    Ponto3D* p2 = dynamic_cast<Ponto3D*>(p);
    double dist = pow(this->getX() - p2->getX(), 2);
    dist += pow(this->getY() - p2->getY(),2);
    dist += pow(this->getZ() - p2->getZ(),2);
    return sqrt(dist);
}
