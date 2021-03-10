#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using namespace std;

/**
 * \brief Esse namespace se refere ao módulo de usuários.
 */
namespace Usuario {
    /**
     * \brief Essa classe representa o papel do usuário na modelagem no sistema em questão.
     */
    class Cliente {
        public: 
            /** 
             * \brief Esse é o construtor da classe que não possui nenhum parametro,
             * por conta disso nenhuma propriedade dessa classe é inicializada.
             *
            */
            Cliente(){};
            /** 
             * \brief Esse é o construtor da classe que possibilia a instanciação da classe
             * passando todos os parametros necessários para definir o objeto por completo.
             *
             * @param string string que se refere ao nome do cliente instanciado.
             * @param string endereco que se refere ao endereco do cliente instanciado.
             * @param string cidade que se refere a cidade do cliente instanciado.
             * @param string estado que se refere ao estado do cliente instanciado.
             * @param string cep que se refere ao cep do cliente instanciado.
            */ 
            Cliente(string nome, string endereco, string cidade, string estado, string cep);

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade nome dessa classe.
             * \return string
            */
            string getNome() const {return this->nome;};

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade endereco dessa classe.
             * \return string
            */
            string getEndereco() const {return this->endereco;};

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade cidade dessa classe.
             * \return string
            */
            string getCidade() const {return this->cidade;};

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade estado dessa classe.
             * \return string
            */
            string getEstado() const {return this->estado;};

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade cep dessa classe.
             * \return string
            */
            string getCep() const {return this->cep;};

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade nome dessa classe.
             * \param @string param, valor referente ao Nome do Cliente
             * Nessa classe
             *
             * \return void (nenhum retorno)
            */
            void setNome(string param);

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade endereco dessa classe.
             * \param @string param, valor referente ao Endereco do Cliente
             * Nessa classe
             *
             * \return void (nenhum retorno)
            */
            void setEndereco(string param);

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade cidade dessa classe.
             * \param @string param, valor referente ao Cidade do Cliente
             * Nessa classe
             *
             * \return void (nenhum retorno)
            */
            void setCidade(string param);

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade estado dessa classe.
             * \param @string param, valor referente ao Estado do Cliente
             * Nessa classe
             *
             * \return void (nenhum retorno)
            */
            void setEstado(string param);

            /** 
             * \brief Esse método tem a função de retornar o valor
             * armazenado na propriedade cep dessa classe.
             * \param @string param, valor referente ao Cep do Cliente
             * Nessa classe
             *
             * \return void (nenhum retorno)
            */
            void setCep(string param);

            /**
             * A função print() tem a função de imprimir na 
             * tela o cliente cadastrado referente a esta Objeto
             * \return void (sem retorno)
             */
            void print(); 

        private:
            string nome; ///< O nome do cliente representado por essa classe
            string endereco; ///< O endereco do cliente representado por essa classe
            string cidade; ///< A cidade do cliente representado por essa classe
            string estado; ///< O estado do cliente representado por essa classe
            string cep; ///< O cep do cliente representado por essa classe
    };
}

#endif