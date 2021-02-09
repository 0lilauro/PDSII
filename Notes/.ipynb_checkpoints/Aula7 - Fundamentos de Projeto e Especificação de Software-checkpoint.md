# Fundamentos de Projeto & Especificação de Software

Introdução à Orientação a Objetos Tentamos responder perguntas como:
* O que é um objeto ?
* como criar esses objetos
    
Em Fundamentos de Software fazemos:
* Requisitos/análises/Modelagem/Design

Vamos destacar 2 dessas tarefas aqui: 

**Análise** que é levantar as necessidades do cliente e transformar isso em requisitos

**Modelagem** que é pegar os requisitos criados e transformar eles em códigos (software)

*Quanto mais complexo é mais necessário é fazer um planejamento*


    Imagine um prédio, ninguem começa a construir um prédio sem saber a planta,
    em software não é diferente. Tem que haver um planejamento antes de tudo ser construido. 
    
Boa parte dos problemas de construção de software é a comunicação.
Aqui vamos entender como modelar as especificações de sistemas.

O planejamento inicial de um sistema ORIENTADO A OBJETOS é basicamente levantar
os Objetos (dados e metodos) e suas interações entre si. 

<img src="./img/image_02.png" width="500px">

Todo software é construido a partir de requisitos.

**Requisitos** são: 
* Objetivos/restrições estabelecidas por clientes e usuários
* Definem as propriedades/caracteristicas desejadas.

Os *requisitos geralmente tem 2 categorias*: 
* **Funcionais**: que o software deve oferecer
* **Não funcionais**: Qualidades globais de um software.

A especificação de requisitos visa: 
* Identificar e formalizar as (reais) necessidades
* Falhas $\rightarrow$ Alto custo mais tarde para arrumar.

A abordagem mais aprofundade dessa identificação de requisitos de softwares é vista melhor em **Engenharia de Software**


## Histórias de Usuário (User Stories)

### User Story
descrição informal em linguagem natural de um ou mias recursos desejados/necessários para um sistema de software. 
*  Funcionalidades importantes para os usuários/clientes do sistema.

Conta uma história acerca de como alguém irá utilizar o produto (sistema) para alcançar um determinado objetivo..

<center> User Stories ≠ Requistos </center>
<center> User Stories $\rightarrow$ Requistos (Ajuda a criar requisitos) </center>
<br>
Todas as historias de usuparios terão criterios de aceitação:
<center><img src="./img/image_03.png" width="500px"></center>
    

A criação de historias de usuários envolvem 3 etapas: 
* **Cartão**: Descrição por escrito da historia
* **Conversação**: Discussão para explicar detalhes
* **Confirmação**: Critérios que confirmam a conclusão 
    
### Cartão: 

* **Who**: Representa os papéis dos usuários do software (ex: visitante, cliente, admin)
* **What**: Qual o objetivo ? Qual a funcionalidade? (sempre pelo ponto de vista do usuário)
* **Why**: Porque tem valor para o usuário ? Qual o contexto? Podem haver diferentes formas de alcançar um objetivo. 

**Exemplo**: **Como** um *cliente* de operadora de saúde **eu quero** *proucurar um médico pelo nome* **para** *obter o endereço* de seu consultório.

### Conversação: 

Visa garantir que todas possuem a mesma visão do probnlema por isso escrever efetivamente as 
historias num cartão é tão importante pois fica explicita e fica possivel compreender tudo até que todos 
estejam de acordo com o alinhado.


### Critérios de aceitação: 

Surgem de perguntas que a equipe faz quando a história está sendo escrito.
Critérios precisam ser alcançados para que a User Story atenda os requisitos do usuário e seja aceita (concluida).
- Devem apresentar a intenção, não a solução.
- Confirmar o mínimo necessário para ser útil ao usuário
- Evitar a adição de características desnecessárias.

recomendado criar de 3 à 5 critérios de aceitação para a criação da história.

Deve-se deixar bem claro o que o time vai fazer antes de iniciar. Permite ao time saber exatamente quando ela está completa. Auxiliar no desenvolvimento de testes automatizados.

* Características funcionais e não funcionais.
* Questões relativas à desempenho e usabilidade
* Tratamento de erros (cenários negativos)
* Impacto para outras funcionalidades:

Exemplo: Como um operador de marcação de consulta eu gostaria de visualizar a agenda de consultas dos médicos para saber quais horários estão disponíveis para novas marcações. 

* Criterios de aceitação: 
- Visualização da agenda por dia, semana, e mês
- Visualizar a agenda de consultas do mês atual e do mês posterior
- Cada consulta agendada deve mostrar o nome e o convênio do paciente

Poderiamos visar cenários negativos e adicionar criterios como: 
- Exibir mensagem de erro caso o serviço não esteja respondendo

Caso um critério seja muito trabalhoso, podemos transforma-lo em uma nova história.

Referências: 
<center><img src="./img/image_04.png" width="250px"></center>



## Modelagem CRC 

É uma das primeiras propostas de modelagem de software baseado em orientação à objetos, o novo paradigma.
Pode ser considerada como uma Ferramenta/Metodologia/Processo para fazer analise, modelagem e projeto de sistemas orientados à objetos.

A modelagem CRC é um pouco mais simples que a modelagem UML.

Lembrese: _"Nenhum processo sozinho garante bons resultados, utilizar POO não é garantia de qualidade!"._


<br><br>
É recomendado a utilização de Cartões CRC ( Class-Responsability-Collaboration)
<center><img src="./img/image_05.png" width="250px"></center>
de forma fisica de 10cm x 15cm. Utilizar de maneira fisica, ajuda à  ser claro, simples, objetivo, e comum para todos os envolvidos nos projeto. 

- **Classe**: Nome da classe definida
- **Responsabilidades**: ... da classe 
- **Colaborações**: Colaborações que essa classe vai fazer.


É um processo iterativo e interativo, conta com a colaboração e a atualização continua dos processos.
A modelagem CRC não depende de nenhuma linguagem de programação.

### Componentes de um cartão CRC

Conjunto de elementos (membros) que compartilham uma mesma estrutura e um comportamento  (objetivo) comum
#### Classe
Classe é uma estrutura que agrupa varios membros, e eles são: 
- **Atributos**: "De que isso é feito"
- **Comportamentos**: "O que isso pode fazer ?"

Com isso conseguimos determinar a responsabilidade da classe: 
* **Comportamento demandado de um objeto**
* **Contrato/Obrigação para com o sistema**

e também podemos dividir as responsabilidades em 2 categorias: 
* **(Conhecimento)**: Fornecer informações
* **(Realização)**: Fazer alguma coisa]


Por exemplo: um objeto cliente, conhece seu nome, seu endereço e seu telefone. 
<br>Por exemplo: um objeto pedido, conhece suas taxas, seu pedidor, e tem a função calcular total. 

#### Colaborador: 
* Processo através do qual vários objetos interagem para fornecer um comportamento (alcançar um objetivo)
* Possui a responsabilidade, mas não a informação.
Relação cliente/servidor (serviço)

<center><img src="./img/image_06.png" width="500px"></center>


## Sessão CRC (Reunião): 

Extração e modelagem dos requisitos 
- Simulação do sistema e execução de cenários.

Aproximadamente seis pessoas
- Especialistas, projetistas, analistas e moderador 

Príncipios para uma sessão de sucesso
- Todas as ideias são potencialmente boas ideias 
- Flexibilidade (diferentes visões é algo bom de se ter)


Em geral a reunião CRC tem esses 4 etapas em seu processo: 

1. Brainstorming.
2. Preenchimento dos cartões.
3. Determinar possíveis cenários.
4. Executar cenários para refinar os cartões.


### A Sessão brainstorming: 

* Escolher o time que irá participar 
 
* explicar comom a modelagem CRC funciona 

* Conversa geral sobre o sistema/requisitos 
    * É realmente necessário ? Por que? Qual ganho ?  
    * O que deve fazer ? Quem vai utilizar ? Como?
   
### Sessão Preenchimento dos cartoes: 

* Classes: 
    * Proucurar pelos substantivos nas descrições
    * Dado o contexto decidir os mais importantes
* Responsabilidades: 
    * **Verbos** $\rightarrow$ Comportamento
    * O que essa classe conhece e faz ?
* Colaboradores 
    * A classe consegue realizar isso sozinha ?
    * Quais informações/serviçoes ela precsa ?
    
  
### Sessão Cénarios 

Determinação de possiveis casos de uso:
* Verificar a aplicação e viabilidade
* Associar um cartão ao cenário descrito.
* Descrever a lógica de execução 
    - "Algoritmo" descrito pelos especialistas
* realizar um teste/execução do cenário.

Exemplo de E-commerce: 

<center><img src="./img/image_07.png" width="500px"></center>

Referencias: 

- [User Stories - Descrição de Requisitos que humanos entender](https://www.luiztools.com.br/post/user-stories-descricao-de-requisitos-que-humanos-entendem/)
- [Como escrever boas Stories](https://conteudo.produto.io/como-escrever-boas-user-stories-258eebb29182)
- [Users Stories - Critérios de aceitação](https://medium.com/@karladiasn/user-stories-e-crit%C3%A9rios-de-aceita%C3%A7%C3%A3o-317c48403fcd)