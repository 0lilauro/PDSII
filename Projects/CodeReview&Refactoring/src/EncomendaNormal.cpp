#include <iostream>
#include "Encomenda.hpp"
#include "EncomendaNormal.hpp"


void Correio::EncomendaNormal::print() {
    this->Encomenda::print();
    std::cout << "[Encomenda Normal]" << endl;
    std::cout << "  Peso: " << this->GetPeso() << endl
        << "  Custo por kg: " << this->GetCustoPorKg() << endl
        << "  Custo total: " << this->calcularCustoTotal() << endl;
}