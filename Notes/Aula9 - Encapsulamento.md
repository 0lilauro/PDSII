# Encapsulamento 

Mecanismo que coloca juntos os dados e suas funções associados , mantendo-os controlados em relação ao seu nível de acesso.

Proporciona Abstração: 
* Separa a visão externa da visão interna
* Protege a integridade dos dadso do Objeto

Escopo de uma variável: 
* Região de um programa que uma variavel pode ser referenciada pelo seu nome.

Relação com a memória?
* O escopo define quando o sistema aloca e libera memória para armazenar uma variável
* Variáveis alocadas no heap continuam lá mesmo fora do escopo (se não forem desalocadas)

exemplo: 
```c++
class ClasseTeste {
    public:
        int var1;
        std::string var2;

        void metodo(int param) {
            int x = 1;
            int y = 9;

            if (param % 2 == 2) {
                int result = 12;
            }
        }
};
```

Acima, existem 3 escopos: **Classe**, **Método**, **if**.

Temos hoje em uma classe:
* métodos públicos
* métodos privados
* dados privados
* dados públicos (São não recomendaveis...)

Em uma classe: 
* *Estado* são os **atributos** 
* *Comportamento* são os **métodos**

Em modificadores temos: 
* Public >= 
* Private >=
* Protected

### Modificador de acesso **Publico**
Permite que os membros publicos sejam acessados de qualquer
outra parte do código.

Mais liberal dos modificadores
* Não recomendado, pois deve ser usado com responsabilidade.


### Modificador de acesso **Protected**
Permite que os outros membros possam ser acessados apenas por outras classes que:
* Fazem parte da hierarquia (derivadas)
* Classes "Amigas" ( Algo especifico do C++)

Exemplo: 
```c++

class Base {
    protected:
        int i = 99;
};

class Derived : public Base {
    public:
        int f() {
            i++;
            return i;
        }
};

```

usando no main:

```c++
int main() {
    Base b;
    cout << b.i << endl; // Isso gera erro.

    Derived d;
    cout << d.f() << endl;

    return 0;
}

```

### Modificador de acesso **Private**

Permite que os membros privados sejam acessados por métodos da <u>mesma classe</u>

O mais restritivo dos modificadores: 
* Deve ser empregado sempre que possível
* Utilizar métodos auxiliares de acesso

Quando não há declaração explícita 
* Padrão de classes é privado.

``` c++
class Ponto {
    private: 
        int _x;
        int _y;

    public: 
        Ponto(int x, int y): _x(x), _y(y) {}
}
```

# Encapsulamento Prático.

Evitar a manipulação direta de atributos
* Acesso deve ser o mais <u>restrito</u> possível
* De preferência <u>todos</u> devem ser <u>private</u>

Sempre utilizar métodos auxiliares
* Melhor controle das alterações 
* Acesso centralizado.


Métodos auxiliares: 

Convenção de nomenclatura dos métodos
* Get: Os métodos que permitem apenas o acesso de consulta (obter)
    devem possuir o prefixo get
* Set: Os métodos que possibilitam a alterção (definir)
    devem possuir o prefixo set.

```c++
class Ponto {
    private:
        double _x;
        double _y;

    public:
        Ponto(double x, double y) : _x(x), _y(y) {}

        void setX(double x) { this->_x = x; }
        void setY(double y) { this->_y = y; }

        double getX() { return this->_x; }
        double getY() { return this->_y; }

}
```

Todos os atributos devem possuir get e set

Nomenclatura alternativa
* Atributos booleanas devem utilizar o prefixo "is" ao invés
do prefixo get
* Melhora a legibilidade e entendimento

E uma coleção possui "*setColecao*"

mais exemplo: 

```c++
class Cliente {
    private: 
        string _nome;
        bool _ativo;
    public: 
        Cliente(string nome, bool ativo) : _nome(nome), _ativo(ativo) {}

        void setNome(string nome) { this->_nome = nome; }
        void setAtivo(bool ativo) { this->_ativo = ativo; }

        string getNome() { return this->_nome; }
        bool isAtivo() { return this->_ativo; }
};    
```

Exemplo prático: **Conta Bancária**:

```c++
class Conta {
    public: 
        int agencia;
        int numero;
        double saldo;

        Conta(int agencia, int numero) : agencia(agencia), numero(numero) {}
};
```

melhorando ....

Exemplo prático: **Conta Bancária**:
```c++
class Conta {
    private: 
        int _agencia;
        int _numero;
        double _saldo = 0;
        // double const _TARIFA = 0.25;
        static double constexpr _TARIFA = 0.25; // Resolve em tempo de compilação
        
        void _descontarTarifa() {
            this->_saldo -= TARIFA;
        }

    public:
        Conta(int agencia, int numero) : _agencia(agencia), _numero(numero) {}

        void setAgencia(int ag) {this->_agencia = ag; }
        void setNumero(int num) {this->_numero = num; }
        // void setSaldo(double saldo) {this->_saldo = saldo; }

        void depositar(double valor) {
            this->_saldo += valor;
            descontarTarifa();
        }

        void sacar(double valor) {
            this->_saldo -= valor;
            descontarTarifa();
        }

        void descontarTarifa() {
            this->_saldo -= .25;
        }

        int getAgencia() { return this->_agencia; }
        int getNumero() { return this->_numero; }
        double getSaldo() { return this->_saldo; }

};
```