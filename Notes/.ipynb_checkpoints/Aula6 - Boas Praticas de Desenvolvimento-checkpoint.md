# Boas praticas de desenvolvimento:
 
Durante o desenvolvimentod e um sistema, passamos mais tempo lendo do que escrevemos.
Vamos entender algumas diretrizes para se ter codigos limpos e organizados.

Temos que ter: 

**Codigo afeta diversar etapas**:
- Implementação, teste, manutenção, evolução

**Fácil de entender, não de escrever**:
- Várias pessoas vão usar o código (até você!)

**Boas práticas** 
- Tecnicas que deixam melhor um codigo. Nem sempre o codigo que funciona é um bom codigo

Um bom codigo apresenta: **compreensivel, confiavel, eficiente e extensivel**

Se o codigo não possui essas caracteristicas, vai demandar mais tempo para ser evoluido no futuro.

Lembre-se:
     
    Sempre deixe o acampamento mais limpo do que como o encontrou
Não basta apenas escrever bem o código inicial. Mas ele deve ser mantido Certo (limpo) ao longo do tempo.

Para alcançar um código de qualidade, vamos seguir algumas convensões


## regras gerais:

1. Evitar o aninhamento de varios 'ifs'
> - complexidade ciclomática
> - Dificil de entender, testar, modificar.

2. Definir tipos específicos para o problema.
> - Tornam os programas mais legíveis

3. Tratar as situações excepcionais.
> - Robustez
> - Tolerância à falhas


### Exemplos: 

complexidade ciclomática: 
```c++
bool exemplo(ifstream& arq, string arq_cam) {
    string linha;
    if (valido(arq_cam)) {
        if (arq.is_open()) {
            if(getline(arq, linha)) {
                if(linha.find("importante")) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
```

Exemplo melhor: 
```c++ 
bool exemplo(ifstream& arq, string arq_cam) {
    string linha;
    if(!valid(arq_cam))
        return false
    if(!arq.is_open())
        return false;
    
    bool encontrou = false;
    if (getline(arq, linha)) {
        if(linha.find("important")) {
            encontrou = true;
        }
    }
    return encontrou;
}
```

## Recomendações de códigos:

### Nomes:
* Underline:
    - int num_clientes;
    - struct list *list_alunos;
* camelCase:
    - int numClientes;
    - struct list *listAlunos;

### Structs/Classes:
* Substantivos no singular: 
    
> Cliente, Esporte, Aluno

### Atributos:
* Substantivos no singular
* Plural se for coleção 
> nome, numJogadores, curso, alunos,

### Métodos:
* ação
* verbo no infinitivo
> enviarPagamento, fazerJogada, cancelarRSG.


**Escolha nomes significativos, fáceis de pronunciar!**

Utilize <u>Constantes</u> quando necessário
* evitar "numeros mágicos" e Strings repetidas
* Devem ter nomes representativos e não seu valor.
* Nomes em letras minúsculas/ precedidos por k.

Exemplo: 
> Utilizar COR_DA_FONTE e não AMARELO
> kDiasDaSemana


## Formatação
|   |   |
|---|---|
| **Vertical** | **Horizontal** | 
|Leitura Top=Down| 80/100/120 caracteres ( nunca fazer scroll horizontal)|
|Separação de conceitos diferentes, proximidade implica em associação| Espaço em braco para associar as coisas|
| Váriaveis declaradas proximas ao uso, instancias declaradas no topo| identação, hierarquia|


### DICAS: 
* Seguir GuideLines
* Configurar o editor
* Identação com 2 a 4 espaços.

### Metodos: 

Faça metodos pequenos com 20 linhas no máximo.
Facilita a leitura e a alterações futuras.

Devem ser utilizados poucos argumentos.

Cada metodo possui *uma* funcionalidade. muitos níves, Muitas responsabilidades.
Extraia trechos em métodos  privados.


Metodos proximos e dependentes devem estar sequenciais ou proximos.

Métodos devem ser lidos de cima para baixo. 
 

**LEGIBILIDADE != COMPLEXIDADE**


### Metodos e Passagem de Parametros

Referências sempre que possível (&)
* não podem ser NULL, logo, mais seguras
* Não podem ser re-assigned (inicialização)

Use ponteiros quando necessário (*)

const:
* Variável referênciada não pode ser alterada pela referência
    - Sempre utilize se esse é o comportamento esperado
* Ajuda o compilador e o programador a debugar.
 
### Comentários: 

Sempre que possível e necessário
* Devem:
    * Ser informativos sobre o funcionamento
    * Alertar sobre posseis consequências
* Não devem:
    * Ser redundantes
    * Dizer algo que devia estar claro pelo código

No inicio de cada módulo traz informações legais, visão geral
Descrever constantes e variáveis globais.

"To Do" -> Coisas a serem resolvidas no futuro. 

Funções: 
    * Descrever os parâmetros e retorno
    * Explicar o que a função faz, não como ela faz.

Exemplo: 
```c++
// Check to see if the employee is eligible for full benefits
if((employee.flags && HOURLY_FLAG) && (employee.age > 65))
```
Better option: 
```c++
if(employee.isEligibleForFullBenefits())
``` 

### Classes
* Metodos -> Linhas,
* Classes -> Responsabilidades 

Seguir o Single Responsability Principle
* Classe dever ter APENAS UMA responsabilidade
* Apenas um **motivo** para mudar

Organização: Fazer uso de private, public, 


## Sistemas de controles de versões. 

Matem um registro de modificação: 

* Desenvolvimento colaborativo.
* Saber quem faz as mudanças e quando 
* Fazer versionamento de codigo. 