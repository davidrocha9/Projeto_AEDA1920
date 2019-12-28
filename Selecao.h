#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

#include "Jogadores.h"
#include "Convocatoria.h"
#include "Equipamentos.h"

using namespace std;
/**
 * @brief classe relativa a selecao
 */
class Selecao {
private:
  vector<Futebolista> jogadores; //vetor com os jogadores
  vector<EquipaTecnica> equipatecnica; //vetor com a equipa tecnica
  vector<Convocatoria> convocatorias; //vetor com as convocatorias
  vector<Jogo> jogos; //vetor com os jogos
  priority_queue<Fornecedores> fornecedores; // fila de prioridade com os fornecedores
public:
  Selecao();
  ~Selecao();
  /**
   * @brief da update ao ficheiro jogadores.txt, que contem os futebolistas
   * @param vf vector da classe Futebolista com os futebolistas
   */
  void JogadoresToFile(vector<Futebolista> vf);
  /**
   * @brief da update ao ficheiro equipatecnica.txt, que contem os membros tecnicos
   * @param et vector da classe EquipaTecnica com os membros tecnicos
   */
  void EquipaTecnicatoFile(vector<EquipaTecnica> et);
  /**
   * @brief da update ao ficheiro convocatoria.txt, que contem os membros tecnicos
   * @param conv vector da classe Convocatoria com as convocatorias
   */
  void ConvocatoriatoFile(vector<Convocatoria> conv);
  /**
   * @brief da update ao ficheiro Jogo.txt, que contem os jogos
   * @param jogos vector da classe Jogo com os jogos
   */
  void JogostoFile(vector<Jogo> jogos);

  // methods GET
  /**
   * @brief retorna um vector da classe Futebolista com os futebolistas
   * @return vector da classe Futebolista com os futebolistas
   */
  vector<Futebolista> getJogadores() const;
  /**
   * @brief retorna um vector da classe EquipaTecnica com os membros tecnicos
   * @return vector da classe EquipaTecnica com os membros tecnicos
   */
  vector<EquipaTecnica> getEquipaTecnica() const;
  /**
   * @brief retorna um vector da classe Jogo com os jogos
   * @return vector da classe Jogo com os jogos
   */
  vector<Jogo> getJogos() const;
  /**
   * @brief retorna um vector da classe Convocatoria com as convocatorias
   * @return vector da classe Convocatoria com as convocatorias
   */
  vector<Convocatoria> getConvocatorias() const;
  priority_queue<Fornecedores> getFornecedores() const;
};
