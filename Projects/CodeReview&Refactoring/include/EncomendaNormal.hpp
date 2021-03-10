#ifndef EncomendaNormal_H
#define EncomendaNormal_H

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
    class EncomendaNormal: public Correio::Encomenda {

        public:

            /** 
             * \brief Esse é o construtor da classe que não possui nenhum parametro,
             * por conta disso nenhuma propriedade é setada atraves do construtor.
             *
            */
            EncomendaNormal();

            /** 
             * \brief Desconstrutor da classe definida como virtual para ser possivel obter o
             * tipo dinâmico da classe.
             *
            */
            virtual ~EncomendaNormal() {};

             /** 
             * \brief Esse é o construtor da classe que possui os parametro para se inicializar a classe,
             * por conta disso cada parametro é definido no setPropriedade de cada atributo.
             * 
             * @param double peso que se refere ao peso da encomenda instanciado.
             * @param double custo_por_kg que se refere custo por peso da encomenda instanciado.
             * @param Cliente remet que se refere ao cliente que vai fazer o envio da encomenda instanciado.
             * @param Cliente desti que se refere ao cliente que vai receber a encomenda instanciado.
            */
            EncomendaNormal(double peso, double custoPorKg, Usuario::Cliente *remet, Usuario::Cliente *desti) : Encomenda(peso, custoPorKg, remet, desti) {};

            /**
             * A função print() tem a função de imprimir na 
             * tela o remetente e o destinatário da entrega em questão.
             * \return void (sem retorno)
             */
            void print() override;
    };

}
#endif