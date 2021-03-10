#include <iostream>
#include <string>
#include "Encomenda.hpp"
#include <assert.h>
#include <typeinfo> 


Correio::Encomenda::Encomenda(double peso, double custoPorKg, Usuario::Cliente *remet, Usuario::Cliente *desti) {
    this->setPeso(peso);
    this->setCustoPorKg(custoPorKg);
    this->setRemetente(remet);
    this->setDestinatario(desti);
}

void Correio::Encomenda::setPeso(double parameter) {
    assert(parameter > 0.0 && "parametro Peso não pode ser menor ou igual a 0");
    this->peso = parameter;
}

void Correio::Encomenda::setCustoPorKg(double parameter) {
    assert(parameter > 0.0 && "parametro Peso não pode ser menor ou igual a 0");
    this->custoPorKg = parameter;
}

void Correio::Encomenda::setRemetente(Usuario::Cliente* parameter) {
    assert(parameter != nullptr && "O parametro de remetente precisa ser uma referência da classe Cliente");
    this->remetente = parameter; 
}

void Correio::Encomenda::setDestinatario(Usuario::Cliente* parameter) {
    assert(parameter != nullptr && "O parametro de destinatario precisa ser uma referência da classe Cliente");
    this->destinatario = parameter; 
}

double Correio::Encomenda::calcularCustoTotal() {
    return this->peso*this->custoPorKg;
}

void Correio::Encomenda::print() {
    std::cout << "[Remetente]" << endl;
    this->remetente->print();
    std::cout << "[Destinatário]" << endl;
    this->destinatario->print();
}