#include <iostream>
#include "Encomenda.hpp"
#include "EncomendaRelampago.hpp"

void Correio::EncomendaRelampago::print() {
    this->Encomenda::print();
    std::cout << "[Encomenda Relâmpago]" << endl;
    std::cout << "  Peso: " << this->GetPeso() << endl
        << "  Custo por kg: " << this->GetCustoPorKg() << endl
        << "  Taxa adicional: " << Correio::EncomendaRelampago::TARIFA_ADICIONAL_FIXA << endl
        << "  Custo total: " << this->calcularCustoTotal() << endl;
}

double Correio::EncomendaRelampago::calcularCustoTotal() {
    return this->Encomenda::calcularCustoTotal() * (1 + Correio::EncomendaRelampago::TARIFA_ADICIONAL_FIXA);
}