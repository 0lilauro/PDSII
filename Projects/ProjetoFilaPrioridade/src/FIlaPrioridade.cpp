#include "FilaPrioridade.hpp"
#include "No.hpp"

#include <iostream>
#include <vector>

FilaPrioridade::FilaPrioridade() {}

void FilaPrioridade::inserir(int prioridade, int dado) {
    No* node = new No(dado);
    Triplet* vector_el = this->getPrioridade(prioridade);
    if(vector_el == nullptr) {
        Triplet new_triplet;
        new_triplet._priority = prioridade;
        new_triplet._start_node = node;
        new_triplet._end_node = node;
        this->_no_prioridade.push_back(new_triplet);
        vector_el = &this->_no_prioridade.back();
    } else {
        No* tmp_node = vector_el->_start_node;
        while (tmp_node->getProximo() != nullptr) 
        {
            tmp_node = tmp_node->getProximo();
        }
        tmp_node->setProximo(node);
        vector_el->_end_node = node;
    }
    vector_el->_number_elemtents++;
    this->_numero_elementos++;
    this->sortTriplet();
}

int FilaPrioridade::remover() {
    this->sortTriplet();

    Triplet* vector_el = &this->_no_prioridade[0];
    int dado = vector_el->_start_node->getDado();
    if(vector_el->_number_elemtents > 1) {
        vector_el->_start_node = vector_el->_start_node->getProximo();
        vector_el->_number_elemtents--;
    } else {
        this->_no_prioridade.erase(this->_no_prioridade.begin());
    }
    this->_numero_elementos--;
    return dado;
}


Triplet* FilaPrioridade::getPrioridade(int prioridade) {
    Triplet* vector_el = nullptr;
    for (int i = 0; i < this->_no_prioridade.size(); i++) {
        if(this->_no_prioridade[i]._priority == prioridade) {
            vector_el = &this->_no_prioridade[i];
        }
    }
    return vector_el;
}

int FilaPrioridade::estaVazio() {
    int response = 0;
    if(this->_numero_elementos > 0) {
        response = 1;
    }
    return response;
}

unsigned FilaPrioridade::getTamanho() {
    return this->_numero_elementos;
}

int FilaPrioridade::getMeio() {
    int max = this->_numero_elementos;
    int middle = (max%2==0) ? (max/2): ((max-1)/2); 
    int idx_priority=0, idx_no = 0;
    No* no = this->_no_prioridade[idx_priority]._start_node;

    while (idx_no != middle && idx_no <= max) {
        if(no->getProximo() == nullptr) {
            idx_priority++;
            no = this->_no_prioridade[idx_priority]._start_node;
        } else {
            no = no->getProximo();
        }
        idx_no++;
    }
    return no->getDado();
}

void FilaPrioridade::furaFila(int dado) {
    this->sortTriplet();
    int last_priority = this->_no_prioridade[0]._priority;
    if(last_priority == 1) {
        for (int i = 0; i < this->_no_prioridade.size(); i++) {
            last_priority++;
            this->_no_prioridade[i]._priority = last_priority;
        }
    } 
    inserir(1, dado);
}

int FilaPrioridade::getUltimo() {
    return this->_no_prioridade[this->_no_prioridade.size()-1]._end_node->getDado();
}

bool FilaPrioridade::sortByVal(Triplet &a, Triplet &b) { 
    return (a._priority < b._priority); 
}

void FilaPrioridade::sortTriplet() { 
    sort(this->_no_prioridade.begin(), this->_no_prioridade.end(), FilaPrioridade::sortByVal);
} 

void FilaPrioridade::print() {
    for (int i = 0; i < this->_no_prioridade.size(); i++) {
        No* no = this->_no_prioridade[i]._start_node;
        do {
            std::cout  << no->getDado() << " ";
            no = no->getProximo();
        } while (no);
    }
}