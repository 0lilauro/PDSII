#include "Partida.hpp"
#include "Jogador.hpp"
#include "Carta.hpp"
#include <vector>
#include <algorithm> 
#include <map>

using namespace std;

Partida::Partida (int num_jogadores) {
	this->_num_jogadores = num_jogadores;
}

int Partida::getNumJogadores() {
    return this->_num_jogadores;
}

Jogador *Partida::getJogador(string nomeJogador) {
    Jogador* player = nullptr;
    for (int i = 0; i < this->_jogadores.size(); i++)
    {
        if(this->_jogadores[i].getNomeJogador() == nomeJogador) {
            player = &this->_jogadores[i];
        }
    }
    return player;
}

void Partida::setNewJogador(Jogador jogador) {
    this->_jogadores.push_back(jogador);
}

void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe) {
    Jogador *player = this->getJogador(nomeJogador);
    Carta carta(numero_pontos_carta, naipe);
    if (player == nullptr) {
        player = new Jogador();
        player->setNomeJogador(nomeJogador);
        player->adicionaCarta(carta);
        this->setNewJogador(*player);
    } else {
        player->adicionaCarta(carta);
    }
}

bool Partida::sortByVal(pair<string, int> &a, pair<string, int> &b) { 
    return (a.second < b.second); 
} 

vector<pair<string, int>> Partida::sortedPlayers() {
    vector<pair<string, int>> pairVec;
    for(Jogador j: this->_jogadores) {
        pairVec.push_back(make_pair(j.getNomeJogador(), j.calcularPontuacao()));
    }
    sort(pairVec.begin(), pairVec.end(), this->sortByVal);
    return pairVec;
}

Jogador* Partida::getCampeao() {
    vector<pair<string, int>> sortedPairVector = this->sortedPlayers();
    return this->getJogador(sortedPairVector[sortedPairVector.size()-1].first);
}

void Partida::imprimeJogadoresOrdenados() {
    vector<pair<string, int>> sortedPairVector = this->sortedPlayers();
	for (int i = 0; i < sortedPairVector.size(); i++) {
		cout << sortedPairVector[i].first << " " << sortedPairVector[i].second  << endl;
	}
    // Jogador *player = this->getCampeao();
    cout << sortedPairVector[sortedPairVector.size()-1].first << endl;
}
