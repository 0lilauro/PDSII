# PDS 2 - Como é? 


* Programação Orientada a Objetos
* Uso e entendimento de Estruturas de Dados 
* Boas praticas, de programação 
* Ferramentas 
* **DESENVOLVER BONS PROGRAMAS**

## Mentalidade; 
1 - Entender o problema
> 1.1- Qual o problema ? 

> 1.2- Qual o resultado esperado

2 - Modelar os dados 
> 2.1- Como abstrair as partes do sistema ? 
> 2.2- Como que as diferentes partes se ligam

3 - Codificar a solução
> 3.1 - Quais as partes serão classes quais serão interfaces ? 
> ... 

<hr>

## Sistemas de computações: 
#### São desenvolvidos através de abstração.
Devemos esconder a complexidade. Abstração 

 

 # Como modlar um Banco ? 

 temos uma agência Fisica: 
 - Paredes
 - Cor 
 - Numero de Entradas 


 Vamos criar um App paro BB-Online 

 *Operações*> 
 1 clientes 
 2 Transacoes 
 3 Contas
 4 Agencia: 


poderiamos fazer o seguinte: 

```c++ 
typedef struct {
    char *nome;
    conta_t *conta;
    agencias *agencia;

} client_t;
```