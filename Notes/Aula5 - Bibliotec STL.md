# Bibliotec STL  


#### Recaptulando: 
Vimos exemplos de TADS: 
- Listas encadeadas, Avores de pesquisar
- Ponto 3D, aluno, Circunferencia

Existem infinitos tads e nem sempre que precisarmos vamos ter que implementar<br>
então passamos a utilizar bibliotecas 

## Bibliotcas
Elas servem para nao escrever tudo do zero: 

- um conjunto de implementações escritas em uma especifilinguagem,
geralememte possuem interface e comportamento muito bem definidos (na documentação)
- reutilizacção de codigo em partes diferentes.

Utilizar -> Entender -> implementar

Nossos programas podem ser compostos por partes que nao somos nos que construimos. 

## Bibliotecas padrões
Componentes na linguagem:
    - Strings
    - Ponteiros inteligentes 
    - Entrada/saida (streams)
    - Funcionalidades Numericas
    - Containers

Funcionalidades atraves da inclusão de headers.

Importando bibliotecas:
```c++
# include <string>
# include <iostream>
```

Importando bibliotecas de *C*:
```c++
# include <stdlib.h>
# include <cstdlib>
```

Utilizamos o *std* como forma de indicar o namespace. 
Para utilizar uma lib padrão, fazemos: 

1. importamos a biblioteca
2. através do namespace acessamos o metodo da biblioteca que importamos

exemplo: 
```c++
#include <iostream>

int main() {
    std::count << "Hello World" << std::endl
    return 0
}
```

Podemos importar todas as bibliotecas de uma vez:

exemplo: 
```c++
#include <iostream>

using namespace std; 
int main() {
    count << "Hello World" << std
    return 0
}
```

## STL

Parte da ISO C++ Standard Library
- Soluções que envolvem estruturas de dados
- Componentes bem escritos e bem testados


### Componentes basicos: 

<img href="./img/image_01.PNG" width=100>

* Containers: Representa como os dados são armazenados na memória.
* Iterador: auxilia no acesso e manipulação de ponteiros
* Algoritmos: procedimentos que pode ser aplicados aos dados

* Temos a implementação da Programação generica, atua sobre diferentes tipos: 
    * Prove maior liberdade e flexibilidade para implementalos
    * Polimorfismo universal (Parametrico): **os tipos passados em parametro**

* Linguagem: 
    * Templates: C++,
    * Generics: Java,


Imagine que vamos escrever uma classe para uma lista encadeada de inteiros: 
``` c++ 
    struct NodeI {
        int data;
        NodeT* next;
    }
```
Agora, vamos mudar para uma lista de Alunos ( tipo aluno):
``` c++ 
    struct NodeA {
        Aluno data;
        NodeT* next;
    }
```

Mas teriamos que reconstruir...  Para isso existem os templates: 
``` c++ 
    template <typename T> Class NodeG {
        T data;
        NodeT* next;
    }
```


Todos os containers: 
São estruturas de dados que armazenam coleções
Todos os elementos são do mesmo tipo

E praticamente todos os TADS são contairners
- Tipos especificos (Estruturas Rígidas)
- Tipos Genéricos (Podem ser reutilizadas)


O acesso uniforme aos dados (contrato)
- Independente do tipo do elemento
- Independente de como está armazenado

Recuperação dos dados 
- Indece (N-ésimo elemento)
- Valor ( Elemento com valor "**João**")
- Propriedades (Elemento com "**idade > 18**")


Com isso ganhamos:
* Organização de dados 
* Operações
* Implementação.


### Tipos de Containers: 

* Sequenciais:
    São arrays personalizados, formas de relacionar elementos sequênciais
    - Vector 
    - Deque 
    - List
    
* Associativos: Mantem organizações internas.
    - Set 
    - Map 
    - Multiset
    - Multimap

* Adaptadores
    - Queue
    - ...


## Containers Sequenciais: 
Os elementos estão em uma **ordem Linear** 
Precedido por um elemento específico e seguido por outro 

Gerenciamento automático de memoria, cresce dinamicamente.
Possui onjunto de funções.

Vector: 
Array Genérico e dinamicamente redimensionável 

* Vantagens: 
    * Acesso individual aos elementos (índice)
    * Adição/remoção de elementos no final
    * percorrer em order especifica.

exemplo: 

```c++

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {7, 5, 16, 8}; //inicializa o vetor

    v.push_back(25); // adiciona elementos no fim da sequencia
    v.push_back(13);

    for(int n: v) { // foreach
        std::count << n << std::endl;
    }
    return 0;
}
```

Como guardar uma coleção de pessoas ? assim: 

```c++
struct Pessoa { 
    string nome;
    int idade;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    Pessoa p1;
    p1.nome = "Ana";
    p1.idade = 25;

    Pessoa p2;
    p2.nome = "Pedro";
    p2.idade = 18;
    
    Pessoa p3;
    p3.nome = "Douglas";
    p3.idade = 30;

    veector<Pessoa> pessoas; 
    pessoas.push_back(p1);
    pessoas.push_back(p2);
    pessoas.push_back(p3);

    cout << pessoas[0].name << endl;
    cout << pessoas[1].name << endl;
    
    // Segunda forma
    cout << pessoas.at[2].name << endl;

    return 0;
}

```

Lista duplamente encadeada: 

Funciona Normalmente assim como a lista anterior. a unica diferença é que está relacionada dos dois lados. 

É mais facil remover ou adicionar um novo elemento

* Não pssui acesso via Índice: Iterador
* Não é necessário Mover outros elementos

exemplo: 
```c++
#include <iostream>
#include <list>

int main() {
    std::list<int> l = {7, 5, 16, 8};

    // Adicionar um numero inteiro no inicio da lista
    l.push_front(25);
    // Adicionar um numero inteiro no fim da lista
    l.push_front(13);

    for (std::list <int>::iteradtor it=l.begin(); it != l.end(); ++it) {
        std::cout << *it  << std::endl;
    }
}
```

O iterador funciona como um ponteiro.

Exemplo2: 
```C++
struct TAD {
    int x;
};

#include <iostream>
#include <list>

int main() {
    std::list<TAD> lista_ref;
    std::list<TAD*> lista_ptr;

    TAD t1;
    t1.x=10;
    lista_ref.push_back(t1);

    TAD* t2 = new TAD();
    t2->x=10;
    lista_ptr.push_back(t2);

    t1.x = 99;
    t2->x = 99;

    std::cout << lista_ref.front().x << std::endl; // nao teve seu valor auterado
    std::cout << lista_ptr.front()->x << std::endl; // teve seu valor auterado

    for(TAD *t: lista_ptr){ //correta desalocação
        delete t;
    }


    return 0;
}
```


O vector é o mais recomendado como escolha padrão. 

## Containers - Associativos

Elementos não possueem uma ordem especificas (inserção)

Projetados para suportar o acesso direto aos elementos usando chaves pré determinados (informados )
- Dados armazenados Ordenados em uma BST( binary search tree)


### Set
Guarda uma coleção de elementos distintos assim como na matemática. 

Eles tem que ser comparaveis de alguma forma.


Set Exemplo1: 
```c++
#include <iostream>
#include <set>

int main() {
    
    std::set<int> s;

    for(int i = 10; i >= 1; i--) {
        s.insert(i); // Insere inteiros de 10 a 1
    }

    s.insert(7); // Nada acontece pois 7, já existe no conjunto
    

    for(int i = 2; 10 <= i; i += 2) {
        s.insert(i); // remove os numeros pares
    }


    std::cout << "(" << s.size() << ")" << std::endl;

    for(int e: s){
        std::cout << e << std::endl;
    }


    return 0;
}
```

Set Exemplo2:
```c++
#include <iostream>
#include <set>

int main() {
    
    std::set<int> s = {1, 3, 5, 7, 9};


    if(s.find(6) != s.endl()) {
         
    } else {
        s.insert(6)
    }

    if(s.insert(6).second) {

    } else {

    }

    for(int e: s) {
        std::cout << e << std::endl;
    }

    return 0;
}
```

E se quisermos criar um conjunto de pessoas: 

```c++
struct Pessoa {
    string nome;
    int idade;
};

#include <iostream>
#include <set>

using namespace std;

// Criamos uma função para comparar nossos elementos
// essa função é um tipo especial chamado Functor.
struct compara_pessoa_f {
    bool operator() (const Pessoa& p1, const Pessoa& p2) {
        return p1.idade < p2.idade;
    }
};

int main() {
    
    // A função de compara_pessoa_f é quem define o criterio de unicidade.
    std::set<Pessoa, compara_pessoa_f> pessoas;

    pessoas.insert({"Douglas", 30});
    pessoas.insert({"Pedro", 18});
    pessoas.insert({"Ana", 25});
    
    for(Pessoa p: pessoas) {
        std::cout << p.nome << std::endl;
    }

    return 0;
}
```


## Map

Nos maps, temos uma estrutura similar ao Set, mas aqui utilizamos chave e valor para relacionar elementos de um mesmo "*Nó*": 

exemplo:
```c++


#include <iostream>
#include <string>
#include <map>

int main() {
    
    // usamos o Int, como chave e a String como valor.
    std::set<int, std::string> m;

    m.insert(std::pair<int, std::string>(1243123123,"João"));

    m[1231241231] = "Maria";
    m[6425836834] = "Carlos";
    m[4563452344] = "Jose";
    m[8358386574] = "Joana";

    std::map<int, std::string>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << ": " <<  it->second << std::endl;
    }

    std::cout << m[6425836834] << std::endl;
    m[6425836834] = "Matheus";
    std::cout << m[6425836834] << std::endl;
    return 0;
}
```

## Iteradores:

Os iteradores são como ponteiros dentro de conteiners.
Cada classe de containers tem seu iterador.

Operações: 
- it++;
- *it;

exemplo:
```c++
#include <iostream>
#include <string>
#include <map>

int main() {
    
    // usamos o Int, como chave e a String como valor.
    std::set<int, std::string> m;

    m.insert(std::pair<int, std::string>(1243123123,"João"));

    m[1231241231] = "Maria";
    m[6425836834] = "Carlos";
    m[4563452344] = "Jose";
    m[8358386574] = "Joana";

    std::map<int, std::string>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << ": " <<  it->second << std::endl;
    }
    return 0;
}
```

A partir de C++11 O compilador é capaz de inferir o tipos na inicialização. Isso pode
nos ajudar, mas deve ser usado com cuidado.

Util quando tempos tipos complicados e com baixa legibilidade. Usamos a keyword **auto**

exemplo: 
exemplo:
```c++
#include <iostream>
#include <string>
#include <map>

int main() {
    
    // usamos o Int, como chave e a String como valor.
    std::set<int, std::string> m;

    m.insert(std::pair<int, std::string>(1243123123,"João"));

    m[1231241231] = "Maria";
    m[6425836834] = "Carlos";
    m[4563452344] = "Jose";
    m[8358386574] = "Joana";
    
    for(auto it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << ": " <<  it->second << std::endl;
    }
    return 0;
}
```

Temos o For each, mas o for each faz uma cópia do elemento o que pode ser um problema. 
então subsituimos o for each para um laço por referência:

exemplo:
```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    // usamos o Int, como chave e a String como valor.
    std::vector<int> v;

    v.push_back(5);
    v.push_back(2);
    v.push_back(9);
    
    for(int i: v) {
        std::cout << i << std::endl;
    }
    return 0;
}
```

exemplo mais eficiênte:
```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    // usamos o Int, como chave e a String como valor.
    std::vector<int> v;

    v.push_back(5);
    v.push_back(2);
    v.push_back(9);
    
    for(int &i: v) {
        std::cout << i << std::endl;
    }
    return 0;
}
```

## Algoritmos: Os algoritmos são usados em intervalos de elementos: 
* Range: qualquer sequência pode ser acessada por meio de iteradores ou ponteiros, como matrizes ou alguns containers: 

```c++ 
algorithm(begin, end, ...);
```

Exemplo: 
```
find(), count(), max_element()
sort(), swap(), reverse()
```

O Range considera o intervalo semi-abert: ([first, last) - Inclui o first e excluio o last)
O last é o elemento exatamente depois do range desejado

**Atenção:** em containers, o begin() aponta para o primeiro elemento e o end para a posição após o último elemento;

Exemplo: 
```c++

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = { 23, 7, 5, 16, 8, 1, 12, 20, 10};

    for(int &n: v)
        std::cout << n << std::endl;

    int max = *std::max_element(v.begin(), v.end());
    std::cout << "Max: " << max << std::endl; 

    std::cout << "Sort: " << std::endl; 
    std::sort(v.begin(), v.end());
    for(int &n: v)
        std::cout << n << std::endl;
    
    std::sort(v.begin(), v.end()-5 );
    for(int &n: v)
        std::cout << n << std::endl; //ordena { 23, 7, 5, 16}
    


    return 0;