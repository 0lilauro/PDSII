#ifndef EncomendaRelampago_H
#define EncomendaRelampago_H

#include "Cliente.hpp"
#include "Encomenda.hpp"
using namespace std;

/**
 * \brief Esse namespace se refere ao módulo de Correio.
 */
namespace Correio {
    /** 
     * \brief essa é a classe filha Encomenda Normal que vai herda a classe Encomenda.
     *
     */
    class EncomendaRelampago: public Correio::Encomenda {

        public:

            /** 
             * \brief Esse é o construtor da classe que não possui nenhum parametro,
             * por conta disso nenhuma propriedade é setada atraves do construtor.
             * Além da definição da entrega Normal Ou não.
             *
            */
            EncomendaRelampago(){
                this->encomendaNormal = false;
            };

             /** 
             * \brief Esse é o construtor da classe que possui os parametro para se inicializar a classe,
             * por conta disso cada parametro é definido no setPropriedade de cada atributo.
             * 
             * @param double peso que se refere ao peso da encomenda instanciado.
             * @param double custo_por_kg que se refere custo por peso da encomenda instanciado.
             * @param Cliente remet que se refere ao cliente que vai fazer o envio da encomenda instanciado.
             * @param Cliente desti que se refere ao cliente que vai receber a encomenda instanciado.
            */
            EncomendaRelampago(double peso, double custoPorKg, Usuario::Cliente *remet, Usuario::Cliente *desti): EncomendaRelampago::Encomenda(peso, custoPorKg, remet, desti) {
                this->encomendaNormal = false;
            };
    
            /** 
             * \brief Desconstrutor da classe definida como virtual para ser possivel obter o
             * tipo dinâmico da classe.
             *
            */
            virtual ~EncomendaRelampago() {};

            /**
             * A função print() tem a função de imprimir na 
             * tela o remetente e o destinatário da entrega em questão.
             * \return void (sem retorno)
             */
            void print() override;

            /**
             * \brief Essa função é responsavel por fazer o calculo do custo total da entrega e retornar o preço
             * No caso atual, faz o calculo para encomendas Relampagos, considerando a tarifa fixa.
             * 
             * \return double, retorna o valor referente ao custo total da encomenda relampago.
             */
            virtual double calcularCustoTotal() override;

            static constexpr double TARIFA_ADICIONAL_FIXA = 0.25; ///< O valor referente à tarifa fixa da entrega via Encomenda Relampago.
            
    };

}
#endif