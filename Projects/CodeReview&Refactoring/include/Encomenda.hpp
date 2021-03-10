#ifndef Encomenda_H
#define Encomenda_H

#include "Cliente.hpp"
using namespace std;

/**
 * \brief Esse namespace se refere ao módulo de Correio.
 */
namespace Correio {
    /** 
     * \brief essa é a classe abstrata que vai ser herdade por outras.
     * Essa classe trás informações referentes a encomenda do correio.
     *
     */
    class Encomenda {

        public:
            /** 
             * \brief Esse é o construtor da classe que não possui nenhum parametro,
             * por conta disso nenhuma propriedade é setada atraves do construtor.
             *
            */
            Encomenda() {};
             /** 
             * \brief Esse é o construtor da classe que possui os parametro para se inicializar a classe,
             * por conta disso cada parametro é definido no setPropriedade de cada atributo.
             * 
             * @param double peso que se refere ao peso da encomenda instanciado.
             * @param double custo_por_kg que se refere custo por peso da encomenda instanciado.
             * @param Cliente remet que se refere ao cliente que vai fazer o envio da encomenda instanciado.
             * @param Cliente desti que se refere ao cliente que vai receber a encomenda instanciado.
            */
            Encomenda(double peso, double custoPorKg, Usuario::Cliente *remet, Usuario::Cliente *desti);

            /** 
             * \brief Desconstrutor da classe definida como possivel de ser sobreescrito.
             *
            */
            virtual ~Encomenda() {};

            /**
             * A função print() tem a função de imprimir na 
             * tela o remetente e o destinatário da entrega em questão.
             * \return void (sem retorno)
             */
            virtual void print();

            /**
             * \brief Essa função é responsavel por fazer o calculo do custo total da entrega e retornar o preço
             * 
             * \return double, retorna o valor referente ao custo total da encomenda.
             */
            virtual double calcularCustoTotal();

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade Peso dessa classe.
             * \return double
            */
            double GetPeso() const {return this->peso;};

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade Custo por kg dessa classe.
             * \return double
            */            
            double GetCustoPorKg() const {return this->custoPorKg;};

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade Remetente dessa classe.
             * \return Cliente
            */            
            Usuario::Cliente* GetRemetente() const {return this->remetente;};

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade Destinatario dessa classe.
             * \return Cliente
            */            
            Usuario::Cliente* GetDestinatario() const {return this->destinatario;};

            /** 
             * \brief Esse método tem a função de retornar 1 se a 
             * encomenda for normal e 0 se não for uma encomenda normal.
             * \return bool
            */            
            virtual bool GetEncomendaNormal() {return this->encomendaNormal;};


            /** 
             * \brief Esse método definir a função de retornar o valor
             * que será armazenado na propriedade Peso dessa classe se for válido.
             * \return double
            */
            void setPeso(double parameter);

            /** 
             * \brief Esse método tem definir função de retornar o valor
             * que será armazenado na propriedade Custo por kg dessa classe se for válido.
             * \return double
            */            
            void setCustoPorKg(double parameter);

            /** 
             * \brief Esse método tem a definir de retornar o valor
             * que será armazenado na propriedade Remetente dessa classe se for válido.
             * \return Cliente
            */            
            void setRemetente(Usuario::Cliente* parameter);

            /** 
             * \brief Esse método tem a função de definir o valor
             * que será armazenado na propriedade Destinatario dessa classe se for válido.
             * \return Cliente
            */            
            void setDestinatario(Usuario::Cliente* parameter);

        protected: 
            bool encomendaNormal = true; ///< O valor referente ao tipo da encomenda (normal:1 ou anormal:0)
            double peso = 0.0; ///< O peso referente à encomenda em Kilogramas (KG).
            double custoPorKg = 0.0; ///< O o custo por Kilogramas da encomenda.
            Usuario::Cliente *remetente; ///< O usuário Remetente da encomenda.
            Usuario::Cliente *destinatario; ///< O usuário destinatário da encomenda.
    };

}
#endif