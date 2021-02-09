#include <iostream>
#include "FilaPrioridade.hpp"

using namespace std;


int main(int argc, char** argv) {
  int prioridade;
  int dado;
 
  FilaPrioridade *fila = new FilaPrioridade();
//   fila->inserir(prioridade, dado);

  fila->inserir(1, 3);
  fila->inserir(4, 9);
  fila->inserir(6, 7);
  fila->inserir(1, 2);
  fila->inserir(3, 1);
  fila->inserir(5, 1);
  
  std::cout << "final" << std::endl;
  fila->print();
  std::cout << std::endl;
  std::cout << "s:" << fila->getTamanho() << ", ";
  std::cout << "m:" << fila->getMeio() << ", ";
  std::cout << "u:" << fila->getUltimo() << ", ";
  std::cout << "r:" << fila->remover() << ", ";
  std::cout << "m:" << fila->getMeio() << ", ";
  std::cout << "u:" << fila->getUltimo() << ", ";
  fila->furaFila(7);
  std::cout << "m:" << fila->getMeio() << ", ";
  std::cout << "u:" << fila->getUltimo() << std::endl;
  fila->print();
  std::cout << std::endl;
  delete(fila);
  return 0;
}