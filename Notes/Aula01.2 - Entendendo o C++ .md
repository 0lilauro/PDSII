# Entendendo o C++ 

#### *veja o seguinte codigo:*

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World" << std::endl;
    return 0;
}
```

o **iostream** é a biblioteca que importa as as funções de input e output.

Quando programamos em **C**, usamos o comando **printf** da lib ***stdio.h***.

O operador **<<** é um comando de "*pegue o que está à direita e jogue na esquerda*".


O operador **<<** é um comando de "*pgue o que está à direita e jogue na esquerda*".

Se **std::count** é a saida, então "*std::count << "Texto*", seria pegue o texto e jogue na saida. 

Para adicionar uma quebra de linha, podemos utilizar o comando "**std::endl**.

<hr>

# Como compilar ? 

linux: 
```sh
g++ hello.cpp -o hello
./hello
```

Comando completo: 
```sh
g++ -std=c++14 -Wall hello.cpp -o hello
```
* **g++**: selecionar o compilador
* **-std=c++14**: paramentro para utilizar a versão 14 do compilador de c++
* **-Wall**: Exibir erros durante a compilação.
<hr>

# Operadores de fluxo

seja: 
```cpp 
#include <iostream>

int main() {
    int numero;
    std::cout >> "Digite um número: ";
    std::cin >> numero;       // parecido com scanf
    std::cout << std::endl << "Echo: ";
    std::cout << numero << std::endl // parecido com printf
}
```

Em c++ existe o tipo Fluxo (Streams) "<< e >>", os operadores de fluxos, controlam entrada e saida. Exemplos de uso: 

* Rede
* Arquivo
* Teclado 
* Tela 
* stdin
* stdout

Temos: 
> * **Stream de saida**: >> 
>
> * **Stream de entrada**: << 

<hr> 

# Strings

Considere: 
```cpp
#include <iostream>
#include <string>

int main() {
    std::string ola = std::string("Olá\n");
    std::string pds2("Vamos Iniciar PDS2\n");
    std::cout << ola;
    std::cout << std::endl;
    std::cout << pds2;

    std::string maisuma = "Mais Uma!";
    std::cout << maisuma.size();
    std::cout << std.endl;
    return 0;
}
```

No exemplo acima, mostramos 3 formas de se declarar uma string. Assim como o objetivo da aula, a ideia aqui é ocultar o desnecessário. Vamos ver uma comparação em codigo de **C++** e **C**. 

## Strings Em C & C++
Código em **C**:
```c
#include <stdio.h>

int main()  {
    char s0[4] = {'d', 'c', 'c', '\0'};
    char s1[] = "dcc";
    printf("%s\n", s0);
    printf("%s\n", s1)
}
```
Código em **C++**:
```c++
#include <iostream>
#include <string>

int main()  {
    std::string string = "dcc";
    std::cout << string.size()
    std::cout << std.endl;
    return 0;
}
```
Veja que em **C**, somos obrigados a especificar o tamanho da string, ou
dizer quando ela termina com **\0**. Em c++  isso também ocorre, a string é um vetor, mas tudo é feito por trás dos panos dentro da biblioteca do **IOSTREAM**


Exemplo de como ler uma estrada em string: 
```cpp
#include <iostream>
#include <string>

int main() {
    std::string entrada_usuario;
    std::cin >> entrada_usuario;
    std::cout << "O Tamanho é: "<< entrada_usuario.size() << std::endl;
    return 0;
}

```