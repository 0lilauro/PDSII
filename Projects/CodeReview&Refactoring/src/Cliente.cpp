#include <iostream>
#include <string>
#include "Cliente.hpp"
#include <assert.h>


Usuario::Cliente::Cliente(string nome, string endereco, string cidade, string estado, string cep) {
    this->setNome(nome);
    this->setEndereco(endereco);
    this->setCidade(cidade);
    this->setEstado(estado);
    this->setCep(cep);
}

void Usuario::Cliente::setNome(string param) {
    assert(param != "" && "parametro Nome não pode ser Nulo!");
    this->nome = param;
}

void Usuario::Cliente::setEndereco(string param) {
    assert(param != "" && "parametro Endereco não pode ser Nulo!");
    this->endereco = param;
}

void Usuario::Cliente::setCidade(string param) {
    assert(param != "" && "parametro Cidade não pode ser Nulo!");
    this->cidade = param;
}

void Usuario::Cliente::setEstado(string param) {
    assert(param != "" && "parametro Estado não pode ser Nulo!");
    this->estado = param;
}

void Usuario::Cliente::setCep(string param) {
    assert(param != "" && "parametro Cep não pode ser Nulo!");
    this->cep = param;
}

void Usuario::Cliente::print() {
	std::cout << "  Nome: " << this->nome << endl
		 << "  Endereço: " << this->endereco << endl
		 << "  Cidade: " << this->cidade << endl
		 << "  Estado: " << this->estado << endl
		 << "  CEP: " << this->cep << endl;
}



