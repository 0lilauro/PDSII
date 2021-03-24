# Depuração de Software 

## Verificação e validação
Estabelecimento da existência de falhas (erros) em um programa

## Deoyração (Debbugging)
Relacionado à localização e reparação de falhas


### Quando acontecem os erros ? 
* Tempo de **Compilação**:
    * Quando o compilador converte c++ em código de máquina
* Tempo de **Ligação**
    * Quando cada modulo está individualmente compilado e o computador faz a conexão entre os módulos individuais. (por exemplo: Funções não declaradas)
* Tempo de **Execução**:
    * Quando o programa já compilou, está rodando, mas há algum erro.

### Tipos de erro:

* Erros de **sintaxe**: 
    * Associados ao fato de que a sintaxe da linguagem não está sendo respeitada, como por exemplo: 
    ```c++
    int main() {
        int a = 5.
        return 0;
    }
    ```
    Acima, estava faltando o `;` no final.

    Ou: 
    ```c++
    int main() {
        int x = (3 +5;
        return 0;
    }
    ```
    Acima está faltando um parentese. 

    Geralmente os erros de sintaxe são encontrados em tempo de compilação.
* Erros de **Semântica**:
    * Associado ao uso indevido de alguma declaração do programa, como por exemplo: 

    ```c++
    int main() {
        int i;
        i++;
        return 0;
    }
    ```
    > Acima, há uma variável não inicializada. Acontece um warning pois o programa não tem certeza absoluta de que é um erro.

    
    ```c++
    int main() {
        int i;
        i++;
        return 0;
    }
    ```

    > Acima, há uma variável recebendo um valor de um tipo diferente do que foi declarado. Atribuição incorreta de tipo e erro de compilação.


    Também são erros identificados em tempo de compilação.

* Erros de **Lógica**:
    * Manifestam-se em tempo de execução
    * Loops infinitos
    * Sementation Fault
    * Retorno de um resultado incorreto.

    Exemplos: 
    ```c++ 
    int fatorial (int n) {
        int fat = 0;
        for (int i = 2; i <= n; i++) {
            fat = fat* i;
        }
        return fat;
    }
    ```

Os erros de lógicas de programção

*  Geralmente são imprevisíveis.
* Só ocorrem com entradas específicas
* Dependentes de plataforma ou do hardware



#### Depuração

Para isso que temos a depuração: É a técnica de programação que possibilita manipular a execução do programa de diversas formas e verificar o estado atual do sistema.
* Debugamos quando: 
    * Debugamos quando o programa para inesperadamanete
    * Resultados diferentes dos esperados.
    * O desempenho está abaixo do esperado (tudo correto, mas demora muito  ou usa mais memoria do que era necessário)
    * Para entender profundamente o programa.



### Passo a passo de como depurar o Código: 

#### 1. Repdroduzir o Problema:
* Aqui devemos determinar as condições que fazem o problema acontecer
* E devemos instabilizar o programa, para que o erro ocorra todas as vezes que determinada ação for tomada, (capacidade de reproduzir o erro);

#### 2. Identificar o local e a provável causa: 
* Observar o comportamente
* Conceber uma hipotese
* Executar um experimento
* *Aqui seria mais observar, teorizar e testar*

#### 3. Corrigir o erro
* Considerar a real razão do problema, bolar uma forma de solucionar o erro para que ele não volte a acontecer mais tarde por motivo algum 

#### 4. Validar Solução
* Cuidado com possiveis efeitos colaterais.  ( A solução que eu fiz é a melhor? Quais efeitos colaterais vem com essa minha correção ?) ( Cuidado para não criar novos erros, seu **vacilão**)



<hr>

## Dicas gerais 

* Proucure por problemas comuns, facilmente corrigidos.
* Concentre-se em mudanças recentes. Faça código -> Teste -> Continue codando -> Faça mais teste. ( Versionamento de código ajuda muito nisso)
* Observe os valores das variáveis passo a passo, assim observar quando o valor da variavel não é aquele que você espera.
* **Utilize ferramentas de depuração**: `printf / cout`
    * Simples e intuitiva, mas prejudica a legibilidade e altera o código. 
    *

## Ferramentas de depurações: 

* GNU Debugger (GDB) ( ja vem integrado no compilador c/c++)
* Utilizar a flag de compilação `-g`
* A GNU Debugger pode ser utilizada pela linha de comando ou pela IDE. 

### GNU Debugger: 
#### Cursor de execução: 
* Run to Cursor, para o código onde tem um ponto de depuração.
    * **Step Over**: Executa a função e para na próxima linha
    * **Step Into**: Entra dentro da operação e executa passo a passo e retorna.
    * **Step Out**: Termina a função corrente e vai para a próxima linha fora da função. 
    * **Continue**: Continua o código para a próxima linha

* Breakpoint: 
    * Uma linha que podemos marcar para quando iniciarmos a depuração, parar no breakpoint e esperar a operação do autor.

* Watches:
    * Observa as variaveis do escopo , onde o cursor do sistema está
    * Atraves do Watches é possivel alterar os valores das variáveis. 

* **Valgrind** ajuda para Alocação e Desalocação de memória!! 


O Objetivo é descobrir a origem do ero e não eliminar o sintoma.
