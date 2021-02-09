#include "No.hpp"


No::No(int dado, No* proximo) {
    this->setDado(dado);
    // this->setPrioridade(dado);
    this->setProximo(proximo);
}

No::No(int dado) {
    this->setDado(dado);
}


void No::setProximo(No* next) {
    if(next) {
        this->_proximo = next;
    }
}

No* No::getProximo() {
    return this->_proximo;
}

void No::setDado(int dado){
    this->_dado = dado;
}

int No::getDado(){
    return this->_dado;
}

// void No::setPrioridade(int prioridade) {
//     this->_prioridade = prioridade;
// }

// int No::getPrioridade() {
//     return this->_prioridade;
// }

