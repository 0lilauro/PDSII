#ifndef PARTIDA
#define PARTIDA

#include <string>
#include <iostream>
#include "Jogador.hpp"
#include <vector>

using namespace std;

class Partida {
	
private:
// 	Jogador *_jogadores;
	vector<Jogador> _jogadores{};
	int _num_jogadores = 0;
	int _atualSize = 0;

public:

	Partida(int num_jogadores);
	~Partida();
	void addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe);
	
	int getNumJogadores();
	int getNumAtualJogadores();
	void setJogadores(Jogador* jogadores);
	void setNewJogador(Jogador jogador);
	Jogador* getJogadores();
	Jogador* getJogador(string nomeJogador);
	Jogador* getCampeao();
	Jogador* getJogadoresOrdenados();
	void imprimeJogadoresOrdenados();
	static bool sortByVal(pair<string, int> &a, pair<string, int> &b);
	vector<pair<string, int>> sortedPlayers();
};

#endif