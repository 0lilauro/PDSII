#ifndef PI
#define PI 3.14

#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H



#include <cmath> 

struct Circunferencia {
    double xc;
    double xy;
    double raio;

    // Construtor
    Circunferencia(double, double, double);
    
    double calcularArea();
    bool possuiIntersecao(Circunferencia*);
    
};

#endif
#endif