#include <iostream>
#include <typeinfo> 
#include <vector>
#include "Encomenda.hpp"
#include "EncomendaNormal.hpp"
#include "EncomendaRelampago.hpp"
#include "Cliente.hpp"

std::vector<Usuario::Cliente*> construirClientes() {
	std::vector<Usuario::Cliente*> vectCliente;
	vectCliente.push_back(new Usuario::Cliente("Thales","Rua dos Pré-Socráticos","Miletus","Ionia","548 a.C."));
	vectCliente.push_back(new Usuario::Cliente("Aristóteles","Avenida do Meio-Termo","Atenas","Ática","384 a.C."));
	vectCliente.push_back(new Usuario::Cliente("Platão","Praça das Formas","Atenas","Ática","348 a.C"));
	vectCliente.push_back(new Usuario::Cliente("Sócrates","Rua do Elenchus","Atenas","Ática","399 a.C."));
	vectCliente.push_back(new Usuario::Cliente("Pitágoras","Praça dos Quadrados dos Catetos","Samos","Egeu","571 a.C."));
	vectCliente.push_back(new Usuario::Cliente("Parmênides","Rua do Não Ser","Eleia","Magna Grécia","460 a.C."));
	vectCliente.push_back(new Usuario::Cliente("Empédocles","Rua dos Quatro Elementos","Agrigento","Sicília","495 a.C."));
	vectCliente.push_back(new Usuario::Cliente("Anaxágoras","Avenida da Mente Cósmica","Clazômenas","Jónia","499 a.C"));
	return vectCliente;
}

std::vector<Correio::Encomenda*> construirEncomendas(std::vector<Usuario::Cliente*> clientes) {
	std::vector<Correio::Encomenda*> vectEncomendas;
	vectEncomendas.push_back(new Correio::EncomendaNormal(5, 12, clientes[0], clientes[1]));
	vectEncomendas.push_back(new Correio::EncomendaNormal(10, 12, clientes[1], clientes[2]));
	vectEncomendas.push_back(new Correio::EncomendaNormal(7, 12, clientes[2], clientes[3]));
	vectEncomendas.push_back(new Correio::EncomendaNormal(2, 12, clientes[3], clientes[4]));
	vectEncomendas.push_back(new Correio::EncomendaNormal(3, 12, clientes[4], clientes[5]));
	vectEncomendas.push_back(new Correio::EncomendaRelampago(13, 18, clientes[5], clientes[6]));
	vectEncomendas.push_back(new Correio::EncomendaRelampago(6, 18, clientes[6], clientes[7]));
	vectEncomendas.push_back(new Correio::EncomendaRelampago(8, 18, clientes[7], clientes[0]));
	return vectEncomendas;
}

int main(){
	// Construindo os clientes da nossa aplicação
	std::vector<Usuario::Cliente*> vectorCliente = construirClientes();
	// Construindo as encomendas da nossa aplicação
	std::vector<Correio::Encomenda*> vectorEncomendas = construirEncomendas(vectorCliente);
	
	// Definindo as variaveis que usaremos.
	unsigned qtdEncomendasNormais = 0;
	unsigned qtdEncomendasRelampago = 0;
	double custoEncomendasNormais = 0.0;
	double custoEncomendasRelampago = 0.0;
	
	// Relatório

	std::cout << "\n>> Relatório de encomendas <<" << endl;
	for(Correio::Encomenda *encomenda:  vectorEncomendas) {
		encomenda->print();
		std::cout << endl;
		if(encomenda->GetEncomendaNormal()) {
			qtdEncomendasNormais++;
			custoEncomendasNormais+=encomenda->calcularCustoTotal();
		} else {
			qtdEncomendasRelampago++;
			custoEncomendasRelampago+=encomenda->calcularCustoTotal();
		}
	}
	std::cout << "\n>> Encomendas Normais <<" 
		<< "\nQuantidade: " << qtdEncomendasNormais
		<< "\nValor Total: " << custoEncomendasNormais
		<< endl
		<< "\n>> Encomendas Relâmpago <<" 
		<< "\nQuantidade: " << qtdEncomendasRelampago
		<< "\nValor Total: " << custoEncomendasRelampago
		<< endl;
}

