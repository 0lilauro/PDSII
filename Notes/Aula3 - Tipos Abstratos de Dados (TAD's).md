# Tipos Abstratos de Dados *Tads*

## Algoritmos
É uma sequencia de passos finitos que transformam uma entreada 
em uma saida

Trabalham sobre as estruturas de dados 

## Estrutura de passos
Abstração da realidade

Suportam as operações dos algoritmos

### Diferença entre Programa & Algoritmo
Um programa impleta em uma certa linguagem de programação os passos que são descritas por um algoritmo.

O algoritmo é a abstração e o programa é o concreto.

## Como representar variáveis no programa ? 
O que os tipos fazem  ?

O programa possuira apenas tipos como boll e int ?
    
    Temos os tipos primitivos 
    e os genericos que criamos.

### O que faz um programa ser bom ? 
 1. Funciona
 2. Facil de entender e modificar 
 3. Razoavel eficiente

 ### Tipos Abstratos de dados: 
 Generalização dos tips primitivos 

 **Encapsula**: Junta diversos elementos 
    em 2 grupos, conjunto de valores e operações.

Desvincular a especificação da sua implementação 
    
    * Ocultação de informação 

AS Especificaações (interface, contrato): 
* O que esse tipo de coisa Representa ? 
* Quais operaçẽs podem ser feitas com ela? 

Implementação:

* Como essa coisa deve ser implementada ? 
* E suas operações ? 

O TAD: 

> 1 Aplicação ( Usuário do TAD conhece)

> 2 Especificação ( Usuário do TAD conhece, O programador constroi)

> 3 Especificação ( O programador constroi )

## TAD Rule:
Um TAD é um tipo caracterizado não pelos valores que o compõe, mas pelas operações que se aplicam sobre ele.

**O que o TAD representa e faz é mais importante do que como ele faz!**

Vantagens: Reuntilização, Integridade, Manutençao;

O que faz parte do TAD  ?

* Filosofia Egoista
* Se algo nao é util, então nao é necessárop
* Informar ao usuário apenas o que ele precisa.
* Liberdade para alterações futuras


### Descrições de TADS 
* Precisas e sem ambiguidades
* completas (o quanto for necessário)
* Não exxcessivamente detalhadas 
* o mais abstrato o possível.

Problema Objetivo ( epecificação ) <==> TADS <==> Implementação (Structs Classes)


# Implementação de TADs

Em linguagensestruturadas como (C, Pascal), a implementação é feita com definiçõesde tipos e implementação de funções: **typedef**

Em linguagens orientadas a objetos, a implementação é feita
atraves de classes ( Começaremos usando **structs**!)

Em c++ um **struct** é similar a uma classe
A unica diferença é que as variaveis de um struct por padrão são publicas e de uma classe é private.

Exemplo de um struct : 
```cpp 

#include <iostream>
#include <cmath>

using namespace std;


struct Ponto3D {

    float x,y,z;
    float cacalcularDistancia(Ponto3D* p2) {
        float dx = p2->x - this->x;
        float dy = p2->y - this->y;
        float dz = p2->z - this->z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }
};

int main() {
    Ponto3D* p1 = new Ponto3D;
    p1->x = 0;
    p1->y = 0;
    p1->z = 0;

    Ponto3D* p2 = new Ponto3D;
    p2->x = 5;
    p2->y = 5;
    p2->z = 5;

    cout << p1->calcularDistancia(p2)<<endl;


    delete p1; // Muito importante de desalocar o que foi alocado
    delete p2; // Muito importante de desalocar o que foi alocado

    return 0;
}

```
> O **this** é um ponteiro que refere para a propria struct.



##  Como Representar um Aluno ? 

* Quais atributos/dados ? 
    
    * nome, matricula, curso,....

* Quais operações sobre esses dados ? 

    * Matricular, calcular RSG


```cpp 
#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    int matricula;

    float calcularRSG() {
        // Fazer calculo necessário
        return 0
    }
};

int main() {
    Aluno aluno; // Precisa dar delete pois foi criada na Stack
    aluno.nome = "Jose da Silva";
    aluno.matricula = 201812345;
    cout << aluno.nome << endl;
    return 0;
}

```

Agora vamos ver mais um exemplo: 
```cpp
    #include <iostream>
    
    // Declaração do TAD 
    struct MyTAD {
        int x = 0;

        void set_x(int x) {
            this->x = x;
        }

        void who_am_i() {
            std::cout << this << std::endl;
        }
    };
```
> 0 THis é um ponteiro para acessar os dados da estrutura
>
> O this é um auto ponteiro, logo sera impresso o endereço


Outro exemplo: 

```cpp 

int main() {
    MyTAD tad_stack; // Referencia Stack

    std:count << &tad_stack << std::endl // Retorno igual;
    tad_stack.who_am_i() // retorno igual;
    // Se a instancia for referencia, se usa o operador '.'

    tad_stack.set_x(55); // acessar os dados por um metodo é mais recomendado
    tad_stack.x = 99;


    MyTad  *tad_heap = new MyTAD(); // Ponteiro, Heap

    std::cout << tad_heap << std::endl;
    tad_heap->who_am_i();  // Em HEAP usa-se o operador -> 

    delete tad_heap;

    MyTAD outr_var_stack;
    outr_var_stack = tad_stack; // Ocorre uma cópia dos valores

    MyTAD *outra_var_heap;
    outra_var_heap = &tad_stack; // Simplismente aponta para o endereço.
}
```
> No código acima  há um erro: **Especificação e implementação estão Juntas**
> 
> Para resolver: 
>  Separar em modulos: 


### Faremos a separação em arquivos: 

* **A especificação:** NomeDoTAD.**hpp**

* **Implementação:** NomeDoTAD.**cpp**

Para utilizar esse TAD  em outras partes do programa é necessário acessar via #include o arquivo hpp.
<b style="color:red"> Não deve-se fazer  include de arquivo .cpp! </b>

<hr>

### Como representar uma circunferência ? 

Quais atributos/Dados ? 

    Coordenadas do centro, raio ....

Quais operações
    
    Calcular Area, perimetro

Codigo: 

Circunferencia.hpp
```cpp 

#ifndef M_PI
#define M_PI 3.141535264735354242

#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

#include <cmath> 

struct Circunferencia {
    double _x, _y;
    double _raio;

    // Construtor
    Circunferencia(double, double, double);
    double calcularArea();
};

#endif
```

circunferencia.cpp 
```cpp
#include "Circunferencia.hpp"

Circunferencia::Circunferencia(double x, double y, double raio) {
    _x = x;
    _y = y;
    _raio = raio;
}

double Circunferencia::calcularArea() {
    return M_PI * pow(_raio,2);
}
```

main.cpp
```cpp

#include <iostream>
#include "Circunferencia.hpp"

using namespace std;

int main() {
    Circunferencia* circ = new Circunferencia(0,0, 10);
    cout << circ->calcularArea() << endl;
    delete circ;
    return 0;
}
```
Para compilar tudo acima, execute: 
```sh 
g++ -std=c++11 -Wall main.cpp Circunferencia.cpp -o main
```

## Desenvolvimento

O desenvolvimento orientado a objetos 
* Construção de programas como uma coleção estruturada de implementações completas/parciais de TADs (structs/classes)

Modularização:

* Programa Orientada a Objetos
* Programa (design) por contratos.

O que é um contrato ? 

* No mundo um contrato é um acordo de diferentes partes ... e no programa.


O que é um contrato num programa: 

* Requisistos de funcionalidade, desempenho;
* Operações disponiveis de um TAD
    * Entradas e Saidas 

Como podemos garantir(forçar) que o contrato definido estará sendo 
cumprido pelo usuário do TAD ? 

-  Tipos 
-  Asserções 
-  Exceções

Requisitos <> implementação 
* Garantir a consistencia entre esses artefatos

A implementação não é p mais importante, pense no tipo como um conjunto de operações criar,setarBase, SetarAltura, CalcularArea,...

Usuário deve acessar os dados pelas operações!


### IMplementação
A implementação nao deve ser conhecida
A abstração deve definir o contrato ( prover os metodos) que será utilizado para a manipulação dos dados (internos ao TAD)

<br>

<br>

<br>


### TESTE

1) calcularArea(): que retorna o valor da área da cincunferência.

2) possuiIntersecao(Circunferencia* c): que recebe outra circunferência como parâmetro e retorna um bool (true/false) indicando se a circunferência atual possua interseção com a passada como parâmetro. 

Obs: Nesse exercício seu programa *não* deverá implementar a função main! A mesma já está implementada e simula o caso em que o usuário do TAD conhece apenas o contrato definido no arquivo .hpp. Considere PI=3.14.

