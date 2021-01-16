# Tipos Abstratos de Dados: 

Conjunto de vaores
Conjunto de operações sobre esses valores

O que o TAD Representa e faz é mais importante do que como ele faz

* Integridade, Manutenção, Reutilização


Como guardar uma coleção de elementos  ?
> Vetores: Arrays
Mas infelizmente os vetores tem que ter uma definiçãom de espaço antes de serem inicializados

Exemplos de inicialização dos vetores: 

```c++
#include <iostream>

using namespace std;


int main() {
    int vetorA[5];
    vetorA[3] =99;
    for(int i=0; i<5; i++) {
        cout << vetorA[i] << "\t";
    }
    cout << endl;


    int vetorB[5] = {};
    for(int i=0; i<5; i++) {
        cout << vetorB[i] << "\t";
    }
    cout << endl;

    
    double vectorC[] = {1.1, 2.2, 3.3};
    cout << vectorC[1] << endl;
}
```

Vetores multi dimensionais:

```cpp
int main() {
    int stackMatrixB[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int rows = 3;
    int cols = 4;
    int** heapMatrix = new int*[rows];
    for (int i=0; i < rows; i++)
        heapMatrix[i] = new int[cols];
    
    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            heapMatrix[i][j] = (rows*i + i) + j;
    for (int i=0; i < rows; i++)
        delete[] heapMatrix[i];
    
    delete[] heapMatrix;
    return 0;
}
```
# Lista Encadeadas 
Forma alternativa de guardar coleções, cada célula/nó guarda duas informações: 

* O próprio valor 
* Referencia para o elemento seguinte na cadeia


## Diferenças: 

* Lista: Tem acesso sequencial, para pegar o valor de um elemento, tem que percorrer todos os anteriores; tem tamanho variavel

* Arrays: tem acesso direto, mas tamanho fixo;


Implementação base de uma **Lista Encadeada**: 

```cpp
    struct Node {
        int data;
        Node* next;
    }
```

Comportamento da lista BASE: 

```cpp
#include <iostream>

using namespace std;

int main() {
    Node a;
    Node b;

    a.data = 99;
    a.next = &b;

    b.data = 123;

    cout << a.data << endl;
    cout << a.next->data << endl;

    return 0;
}
```


Operações de Listas:

* Criar uma nova lista (inicializar)
* Inserir elemento
* Remover elemento
* Localizar um elemento
* recuperar o valor de um elemento
* recuperar o elemento seguinte ao elemento
* ...

Mas todas essas operações não ficam associadas ao node, e sim a um novo TAD.

O TAD, precisa de uma referencia para o primeiro Node. (Head)
e para o ultimo Node, (Tail).


List.hpp
```cpp 

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void insertNode(int data);
    void removeNode(int data);
    void display();
}
```

List.cpp
```cpp
#include "List.hpp"

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;

    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
}

```

main.cpp
```cpp 
#include "List.hpp"

int main() {
    List lista;
    lista.insertNode(111);
    lista.insertNode(222);

    return 0;
}
```

Removendo elementos da lista, casos: 
* Head 
* Tail 
* algum outra posição

```cpp

void List::removeNode(int data) {

    Node *current = head;
    Node *previous = nullptr;

    while (current != nullptr) {
        if (current->data == data) {
            head = current->next;
            
        } else if {
            previous->next = nullptr;
        } else {
            previous->next = current->next;
        }
        delete current;
        return;
    }
    previous = current;
    current = current->next;
}
```

implementação:

main.cpp 
```cpp
#include "Lista.hpp"

int main() {
    List lista;

    lista.insertNode(111);
    lista.insertNode(222);


    lista.removeNode(222);
    return 0;
}
```

Mostrar: 

lista.cpp:
```cpp
void List::display() {
    Node *aux = head;
    while ( aux!= nullptr ) {
        cout << aux->data << "\t";
        aux = aux->next;
    }
    cout << endl;
}
```



implementação:

main.cpp 
```cpp
#include "Lista.hpp"

int main() {
    List lista;

    lista.insertNode(111);
    lista.insertNode(222);
    lista.display();
    return 0;
}
```


## Variação: Listas duplamente encadeadas: 

```cpp
struct Node {
    int data;
    Node* next;
    Node* previous;
}
```

Vantagem: É possivel percorrer a lista em 2 sentidos,
inserção e  remoção diretas;

Desvantagem: Espaço extra para a nova referencia.


<hr>

# Arvores

As arvores armaazenam estuturas organizadas

São aduqadas para acesso direto e sequencial
facilidade de inserção e retirada de registros;
boa taxa de utilização de memória.
utilização de memória primaria e secundária.

Dados organizados de forma hierarquica entre nós e filhos: 


Estrutura Hierárquica
* Organização dos elementos em niveis
* Cada elemento é chamado de Nó ou vértice

Relação Pai - Filhos:

* Raiz: Pimeiro nó da hierarquia
* Folhas: nós que não possuem filhos

Filho de um nó é a raiz de uma subárvore;


### Arvores binárias.

Nelas, cada nó pode ter no máximo dois filhos

```c++

struct NodeT {
    int data;
    NodeT* esq;
    NodeT* dir;
}
```

## Arvóres Binárias de Pesquisa: 

As árvores mostradas anteriormente apenas representam os dados hierarquicamente sem nenhuma organização

As arvores binárias de busca possuem uma ordenação

* Todos os vértices filhos com chaves **menores** que o vértice pai estão dispostos na subarvore da **esquerda**

* Todos os vértices filhos com chaves **maiores** que o vértice pai estão dispostos na subarvore da **direita**

* Não aceita valores iguais

* Operações: 

    * Criar uma nova arvore
    * Inserir  elemento
    * Retirar elementos
    * Listar os elementos
    * localizar um elemento
    * Recuperar o valor de um elemento 


Código: 

bts.hpp
```c++

#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct NodeT (
    int data;
    NodeT* esq;
    NodeT* dir;
);

struct BST {
    NodeT* root = nullptr;

    void insertNodeHelper(NodeT* root, int data);
    void insertNode(int data);
    void removeNode(int data);
    void display();
};

#endif
```

bst.cpp
```c++
#include "BST.hpp"
NodeT* createNode(int data) {
    NodeT* aux = new NodeT;
    aux->data = data;
    aux->esq = nullptr;
    aux->dir = nullptr;

    return aux;
}

void BST::insertNodeHelper(NodeT* n, int data) {
    if (data< n->data) {
        if (n->esq == nullptr) {
            n->esq = createNode(data);
        } else {
            insertNodeHelper(n->esq, data);
        }
    } else if (data> n->data) {
        if (n->dir == nullptr) {
            n->dir = createNode(data);
        } else {
            insertNodeHelper(n->dir, data);
        }
    }
}

void BST::insertNode(int data) {
    if (root != nullptr) {
        insertNodeHelper(root,data);
    } else {
        root = createNode(data);
    }
}

```
implementação: 

main.cpp
``` c++

#include <iostream>

int main() {
    BST bst;

    bst.insert(5);
    bst.insert(2);
    bst.insert(7);
    bst.insert(6);

    return 0;
}
```

O usuário que for implementar o metodo, precisa conhecer a função insertNodeHelper ? Não necessáriamente.