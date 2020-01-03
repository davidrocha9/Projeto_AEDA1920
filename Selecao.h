#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>

#include "Jogadores.h"
#include "Convocatoria.h"
#include "Equipamentos.h"
#include "bst.h"

using namespace std;

/**
 * @brief struct da hash table com os funcionarios conhecidos
 */
struct FuncionariosRecordHash
{
    int operator() (const EquipaTecnica& cr) const
    {
        return 0    ;
    }

    bool operator() (const EquipaTecnica& cr1, const EquipaTecnica& cr2) const
    {
        return (cr1.getNome() == cr2.getNome() && cr1.getDataNascimento() == cr2.getDataNascimento());
    }
};

typedef unordered_set<EquipaTecnica, FuncionariosRecordHash , FuncionariosRecordHash > HTFuncionariosRecord;


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
  BST<Selecionadores> selecionadores; //arvore binaria com os selecionadores
  HTFuncionariosRecord funcRec;
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
  /**
   * @brief da update ao ficheiro fornecedores.txt, que contem os fornecedores
   * @param fornecedores vetor da classe Fornecedores com os fornecedores
   */
  void FornecedorestoFile(priority_queue<Fornecedores> fornecedores);
  /**
   * @brief da update ao ficheiro selecionadores.txt, que contem os selecionadores
   * @param selecionadores vetor da classe Selecionadores com os selecionadores
   */
  void SelecionadorestoFile(BST<Selecionadores> selecionadores);
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
  /**
   * @brief retorna os fornecedores
   * @return priority queue com os fornecedores
   */
  priority_queue<Fornecedores> getFornecedores() const;
  /**
   * @brief retorna os selecionadores
   * @return arvore binaria com os selecionadores
   */
  BST<Selecionadores> getSelecionadores() const;
  /**
   * @brief da update à arvore binaria dos selecionadores
   * @param selecionadores arvore binaria com os selecionadores
   * @param c convocatoria
   */
  void updateSelecionadores(BST<Selecionadores> &selecionadores, Convocatoria c);
  /**
   * @brief retorna a hash table com os funcionarios conhecidos
   * @return hash table com os funcionarios conhecidos
   */
  HTFuncionariosRecord getFuncionariosRecord();
  /**
   * @brief funcao set para mudar os funcionarios conhecidos
   * @param h hash table com os funcionarios conhecidos
   */
  void setFuncionariosRecord(HTFuncionariosRecord h);
  /**
   * @brief gera a hash table com os funcionarios conhecidos
   * @param et vetor com todos os funcionarios
   * @return hash table com os funcionarios conhecidos
   */
  HTFuncionariosRecord generateRecords(vector<EquipaTecnica> et);
  /**
   * @brief mostra as informaçoes dos funcionarios presentes na convocatoria mais recente
   * @param c convocatoria
   * @param ht hash table com os funcionarios conhecidos
   */
  void InformacoesFuncionariosConvocatoria(vector<Convocatoria> c, HTFuncionariosRecord ht);
  /**
   * mostra as informaçoes de todos os funcionarios conhecidos
   * @param ht hash table com os funcionarios conhecidos
   */
  void InformacoesFuncionariosConhecidos(HTFuncionariosRecord ht);
  /**
   * @brief permite contratar um funcionario, que é adicionado à equipa tecnica da convocatoria mais recente
   * @param c vetor com todas as convocatorias
   * @param ht hash table com os funcionarios conhecidos
   * @param et vetor da equipa tecnica
   */
  void ContratarFuncionario(vector<Convocatoria> &c, HTFuncionariosRecord ht, vector<EquipaTecnica> &et);
};

/**
 * @brief classe exceçao para quando nao existe um funcionario que possa ser contratado
 */
class FuncionarioNaoExistente {
public:
    string f;
    /**
     * @brief construtor da exception
     * @param f funcao do funcionario
     */
    FuncionarioNaoExistente(string f) {
        this->f = f;
    }
};