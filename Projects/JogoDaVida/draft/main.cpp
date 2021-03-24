#include <iostream>
#include <chrono>
#include <thread>

#include "game_of_life.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono_literals;

void Print(const GameOfLife& g) {
  cout << "  "; 
  for (int i = 0; i < g.columns(); ++i) {
    cout << "- "; 
  }
  cout << endl;
  for (int i = 0; i < g.lines(); ++i) {
    cout << "| ";
    for (int j = 0; j < g.columns(); ++j) {
      if (g.alive(i, j)) {
        cout << "* "; 
      } else {
        cout << "  ";
      }
    }
    cout << "|" << endl;
  }
  cout << "  "; 
  for (int i = 0; i < g.columns(); ++i) {
    cout << "- "; 
  }
  cout << endl;
}

#include <memory>
#include <string>

using namespace std;

int main() {
  try {
    // Lê os dados.
    int iterations;
    cin >> iterations;
    int line, column;
    cin >> line >> column;
    GameOfLife g(line, column);
    while (cin >> line) {
      cin >> column;
      g.Enliven(line, column);
    }
    Print(g);
      
    // Executa o número esperado de iterações.
    while (iterations > 0) {
      g++;
      Print(g);
      std::this_thread::sleep_for(10ms);
      iterations--;
    }
    return 0;
  } catch (GameOfLife::InvalidCellException e) {
    cerr << "As coordenadas [" << e.line << ", " << e.column << "] não são de uma célula válida" << endl;
    return 1; // Return 1 when the program fails.
  } catch(...) {
    cerr << "Any Other Exception will falls here!" << endl;
    return 1;
  }
}