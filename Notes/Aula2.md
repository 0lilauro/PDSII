# Hierarquia de memória 

Memória é uma estrutura interna que armazena informações.
Todo computador possuí 2 tipos de memória: 

## 1. Memória principal 
 * DRAM ( Dynamic Random Access Memory)
 * Armazenamento Temporário
## 2. Memória secundária
* Tecnologias Magnéticas e Ópticas
* Não Voláteis


Existe uma hierarquia da memoria,
quanto mais rápido, mais custoso é e menos consegue armazenar. 

Ordem: 

1- Memória de Cache

2 - Memoria RAM

3 - Memoria Secundária  (HD)

Quando há necessidade de fazer uma busca de um endereço de memória, a busca se inicia do topo da hierarquia até sua base.


# Principio da Localidade - Temporal & Espacial

## Temporal:
Dado acessados recentemente tem mais chances de serem usados novamente do que os dados usados há mais tempo

Exemplo: 

* Comandos de repetição
* Funções

Manter os dados e instruções usados recentemente no topo da hierarquia ajuda a ter o acesso mais rápido da informação quando ela for solicitada.

## Espacial 
Probabilidade de acesso maior para dados e instruções em endereços proximos aquelas acessadas recentemente
Exemplo,
 * acesso às posições de um vetor.
 * Variaveis são armazenasdas proximas uma às outras
 * Vetores e matrizes armazenados em sequência
 * Levando em consideração seus índices

## Memoria Virtual
Hoje em dia a memória RAM é muito requisitada, e para não parar seu uso, quando está muito cheia, ela pega um pedaço da memoria secundaria como uma estenção de si. 

## Computador simplificado

Um computador não é nada mais que um barramento/bus, que conecta "modulos" como: Input Devices, CPU, Main Memory, Output Devices e etc..


# Alocação de Memória: 

A memória de um programa é geralmente dividida em 3 partes: 

* Codigo/Globais
    
    * Guarda o código compilado do programa e outras variaveis
* Stack (Pilha) 

    * Espaço que variáveis dentro de funções são alocadas
* Heap 

    * Espaço mais estável (durável) de armazenamento
    * Programa aloca/desaloca porções de memória do Heap durante a execução

## Alocação de memória: *Pilha*

* Porção contígua/sequencial de memória

    * Escopo de variavel: incrementado toda vez que um metodo é chamado, liberado quando ele é finalizado
* É uma estrutura de LIFO (First in last Out)
    
    * O último elemento a entrar é o primeiro a sair

* Não é necessário gerenciar manualmente
* Possui limites no seu crescimento , varia de Linguagem para Linguagem.
* Quando uma função é chamada, uma pilha é importada para a memoria com endereço de todas as variaveis e elementos externos que estão sendo chamados na função.

## Alocação de memória: *Heap*

* Espaço de memória de propósito Geral

* Não impõe um padrão de alocação
    
    * Fragmentação ao longo do tempo
* Gerenciamento explícito pelo programador
    * há alocação e desalocação são manuais.
* Não possui um limite de tamanho... toda vez que seu espaço está acabando, solicita ao Sistema Operacional mais espaço.


## Tipo de Alocação de Memória Estatica (Pilha): 
Acesso/ Manipulação sem alterar o endereço ( variável global )

## Tipo de Alocação de Memória Dinâmica (Heap): 
Sabe-se o espaço de memória para as variáveis em compile time ou seja durante o desenvolvimento ( e persiste até o final).


# Exemplo de alocação de memória em codigo: 
veja em Python Tutor http://pythontutor.com/

## Alocação C++ com Stack:

```cpp 
#include <iostream>
#include <string> 

int valor_global = 100; // 1º Alocada na Stack

double dobrar_valor (double input){ 
    //7º  Aloca input na Stack
    double dobro = input * 2.;
    return dobro; //8º  Aloca dobro na Stack
    //8º  Remove dobro na Stack
    //9º  Remove input na Stack
}

int main() { // 2º Alocada na Stack
    int idade = 30; // 3º Alocada na Stack
    double salario = 1323.67 // 4º Alocada na Stack
    double lista[3] = {1.2, 2.3, 3.40}; // 5º Alocada na Stack

    std::cout << std::fixed << std::setprecision(2) << 
    // 6º Aloca dobrar_valor na memoria
    dobrar_valor(salario);
     //10º  Remove dobrar valor na Stack
     //10º  Remove as variaveis de main da Stack
    return 0;
}

```

Toda vez que um return é executado, as variaveis usadas no escopo do return são limpas da pilha. 

Em funções recursivas podem ser um problema, pois cresce muito a pilha: 

```cpp 
#include <iostream>

int factiorial(int n) {

    if (n > 1) 
        return n*factorial(n-1);
    else return 1;
}

int main() { 
    int fact1 = factorial(10);
    // Adiciona factorial 10 para a stack
    // Adiciona factorial 9 para a stack
    // Adiciona factorial 8 para a stack
    // Adiciona factorial 7 para a stack
    // Adiciona factorial 6 para a stack
    // Adiciona factorial 5 para a stack
    // Adiciona factorial 4 para a stack
    // Adiciona factorial 3 para a stack
    // Adiciona factorial 2 para a stack
    // Adiciona factorial 1 para a stack
    return 0;
}
```
Por isso utilizar funções recursivas pode estourar a memoria, pois muito espaço é alocado para essa execução


## Alocação C++ com Heap:

Exige uma maior expertise e manipulação com as variáveis.

Armazenamento de grandes quantidades de dados cujo o tamanho máximo é desconhecido na implementação
* Sob demenda durante a execução
* Tamanho pode variar após o inicio da execução
*Não estão associadas a um escopo específico! 

Em C/C++,faz a utilização de ponteiros para manusear a memória de maneira explicita;

# Ponteiros: 
 - Armazena um endereço de memória
 - Variaveis alocadas dinamicamente em Heap

    #### **Referencia**: 
    * ``` &x ```
    * Endereço de memória da variavel X;

    #### **Deferencia (dereferencia)**
    * ``` *x ```
    * Conteudo do endereço apontado por X;

Exemplo do uso de ponteiros: 

```cpp 
int main() {
    int var = 100;
    int *p = &var;   // *p é um ponteiro
    
    return 0;
}
```
> Cara variavel da memoria tem um endereço na memoria.

> Um ponteiro é como qualquer outra variavel, e possui um endereço de memoria. A diferença é que o valor que ele armazena é um endereço de memória.

> Estamos *atribuindo* o endereço da variavel ***var*** ao *conteudo* da variavel ***p***


Memoria Do código acima:
|      |       |          |
|------|-------|----------|
| Nome | Valor | Endereco |
| ... |        |    0x0000      |
|    Var  | 100      | 0x0004          |
|  p    |  0x0004     |  0x0008        |
|     |       |  0x000c        |
|      |       |  0x0010        |


Exemplo de ponteiro 2: 
```cpp
int main() {
    int i = 10;
    int *ponteiro = &i;   // *ponteiro é um ponteiro
    int **ppp = &ponteiro; // **ppp é um ponteiro para um ponteiro de inteiro.

    return 0;
}
```
Memória do codigo acima 

|   |   |   |
|---|---|---|
| Nome | Valor | Endereço |
|   |   | 0x0000 |
| i | 10 | 0x0004 |
| ponteiro  | 0x0004  | 0x0008 |
| pppp |  0x0008 | 0x000c |
|   |   | 0x0010 |


## Operações com ponteiros: 

### Em **C**:
```c
    Alocação: malloc
    Liberação: free
``` 
### Em **C++**:
```c
    Alocação: new
    Liberação: delete
``` 


Exemplo de codigo de alocação em memoria Heap
```cpp
int *a, b; // reserva um espaço na Stack para a e b

b = 10; // da um valor para o espaço na stack para B
a = new int; // quarda um endeço de um spaço da heap como um valor na stack

*a = 20 // Armazena 2 no endereço armazenado no ponteiro para o Heap
a = &b  // a variavel a, guarda o endereço de B.
*a = 30 // a variavel b, recebe o valor de 30
```

Como melhorar esse código ? 

```cpp
int *a = nullptr // ponteiros não iniciados, podem receber esse valor
int b = 10 // evitar declar variaveis sem atribuir valor

a = new int;
*a = 20;
delete a; // Liberar a memoria armazenada manualmente
a = &b;
*a = 30;
```

### Ponteiros para vetores
Vetores são criados em tempo de execução e quando temos um ponteiro para um vetor,
estamos indicando para o ponteiro o primeiro endereço do vetor.

Exemplo: 
```cpp
int main() {
    int *p = new int[10];

    p[0] = 99;
    
    delete[] p; //para deletar a reserva de espaço do vetor devemos usar o colchete para indicar um espaço continuo na memória.

    // O comando delete[] p não necessáriamente deleta o alocamento, só indica que o espaço pode ser usado para outra necessidade
    return 0;
}
```

Para inicializar ponteiros vazios é muito recomendado o null pointer pois ele é mais seguro e costuma indicar apenas ponteiros que não foram inicializado. 
Mas, em geral **nullptr = NULL = 0**.

Pointeiros com nullptr não podem ser inicializados


### Ponteiros para Void;

Não é uma boa pratica.
O ponteiro void, pode ser de qualquer outro tipo de ponteiro.

exemplo:
```cpp
int i = 10;
int *int_ptr;
void *void_ptr;
double *double_ptr;

int_ptr = &i;
void_ptr = int_ptr; // ok
double_ptr = int_ptr; //not ok - pode gerar imprecisão
double_ptr = void_ptr; // ok
```

### Ponteiros para estrututras 
#### Declaraçao e Inicialização: 

```cpp
struct data {int data; int mes; int ano;};
struct data d1;

d1.dia = 8;
d1.mes = 8;
d1.ano = 8;


struct data *ptr = &d1;

ptr->dia = 7;
ptr->mes = 11;
ptr->ano = 2020;

int i = 0;
```

## Passagem de Parâmetros 

## Valor 
* Parâmetro formal (recebido na função) é uma cópia do paâmetro real
* variáveis totalmente **independente**

Exemplo: 
```cpp 
#include <iostream>
using namespace std;

void addOneValue(int x) {
    x = x+1;
}

int main() {
    int a = 0;
    cout << "Antes: " << a << endl;
    addOneValue(a)
    cout << "Depois: " << a << endl;
    return 0
}
```

#### Referência (ponteira)
* Parâmetro formal é uma referência para o parâmetro real 
* Modificações no parametro refletem na variável original

Exemplo:
```cpp 
#include <iostream>
using namespace std;

void addOnePointer(int *x) {
    *x = *x+1;
}

int main() {
    int a = 0;
    cout << "Antes: " << a << endl;
    addOneValue(a)
    cout << "Depois: " << a << endl;
    return 0
}
```

### Boas Pŕaticas de Passagem de parametro
```cpp
    void function(int &i) {
        int j = 10;
        i = &j;
    } // Erro de compilação
```
```cpp
    void function(int &i) {
        int j = 10;
        i = &j;
    }// Compila, mas é i, fomnte de bugs
```

### dica:
* Use referências (&) sempre que possível (*Aceita valores nullos*)
* Use referências (*) quando for necessário 

### Sugestões: 
* Tente acessar o conteúdo de uma posição da memoria, sem ter sido alocada anteriomente

*copiar o valor do ponteiro  e não o valor da variável
endereço != Conteúdo
* Esquecer de desalocar a memória exssa b
* Escopo: desalocada ao fim do programa ou da função.
* Pode ser um problema em loops
