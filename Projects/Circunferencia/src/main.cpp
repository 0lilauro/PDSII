#include "Circunferencia.hpp"
#include <iostream> 

using namespace std;

int main() {
    Circunferencia* circ = new Circunferencia(-1, 0, 2);
    // Circunferencia* circ2 = new Circunferencia(1, 0, 4);

    cout << circ->calcularArea();
    
    return 0;
}