#include "Circunferencia.hpp"

inline double round( double val )
{
    if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

Circunferencia::Circunferencia(double x, double y, double raio) {
    this->xc = x;
    this->xy = y;
    this->raio = raio;
}

double Circunferencia::calcularArea() {
    return PI * pow(this->raio, 2);
}

bool Circunferencia::possuiIntersecao(Circunferencia* circun) {
    int euclidDistance = sqrt(pow((this->xc - circun->xc), 2) + pow((this->xc - circun->xc), 2));
    bool answer = true;

    if (euclidDistance > (this->raio + circun->raio)) {
        answer = false;
    }
    return answer;    
}