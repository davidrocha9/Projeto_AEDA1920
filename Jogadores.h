#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Date.h"
#include "bst.h"

using namespace std;
/**
 * classe relativa aos membros da selecao
 */
class MembroSelecao{
protected:
	string nome;
	Date datanascimento;
public:
    /**
     * @brief construtor da classe MembroSelecao
     * @param n nome do membro da selecao
     * @param dn data de nascimento do membro da selecao
     */
	 MembroSelecao(string n, string dn);
	 /**
	  * @brief construtor vazio da classe MembroSelecao
	  */
	 MembroSelecao();
	 /**
	  * @brief destrutor da Classe MembroSelecao
	  */
	 virtual ~MembroSelecao() {};

	 // metodos GET
	 /**
	  * @brief retorna o nome de um membro da selecao
	  * @return retorna a string com o nome de um membro da selecao
	  */
	 string getNome() const;
	 /**
	  * @brief retorna a data de nascimento de um membro da selecao
	  * @return objeto da classe Date com a data de nascimento de um membro da selecao
	  */
	 Date getDataNascimento() const;

	 // metodos SET
	 /**
	  * @brief altera o valor do nome de um membro da selecao
	  * @param n nome de um membro da selecao
	  */
	 void setNome(string n);
	 /**
	  * @brief altera o valor da data de nascimento de um membro da selecao
	  * @param dn data de nascimento de um membro da selecao
	  */
	 void setDataNascimento(string dn);

	 //Outros metodos
	 /**
	  * @brief mostra a informacao de um membro da selecao
	  */
	 virtual void Info() const;
};
/**
 * @brief classe relativa aos futebolistas
 */
class Futebolista : public MembroSelecao {
    string posicao, clube;
	unsigned int peso, altura, valorpasse;
public:
    /**
     * @brief construtor vazio da classe Futebolista
     */
	Futebolista();
	/**
	 * @brief construtor da classe Futebolista
	 * @param n nome de um Futebolista
	 * @param dn data de nascimento de um Futebolista
	 * @param p posicao de um Futebolista
	 * @param c clube de um Futebolista
	 * @param pe peso de um Futebolista
	 * @param a altura de um Futebolista
	 * @param vp valor do passe de um Futebolista
	 */
	Futebolista(string n, string dn, string p, string c, unsigned int pe, unsigned int a, unsigned int vp);
	/**
	 * @brief compara dois objetos da classe Futebolista
	 * @param f Objeto da classe futebolista
	 * @return bool resultante da comparacao entre dois futebolistas (menor que o outro)
	 */
	bool operator < (const Futebolista &f) const;
	/**
	 * @brief compara dois objetos da classe Futebolista
	 * @param f objeto da classe futebolista
	 * @return bool resultante da comparacao entre dois futebolistas (igual ao outro)
	 */
	bool operator == (const Futebolista& f) const;
	/**
	 * @brief ostream para mostrar a informacao de um futebolista
	 * @param out ostream vazia
	 * @param f objeto da classe Futebolista
	 * @return ostream com a informacao do futebolista
	 */
	friend ostream& operator<<(ostream& out, const Futebolista& f);

	// metodos GET
	/**
	 * @brief retorna a posicao de um futebolista
	 * @return string com a posicao de um futebolista
	 */
	string getPosicao() const;
	/**
	 * @brief retorna o clube de um futebolista
	 * @return string com o clube de um futebolista
	 */
	string getClube() const;
	/**
	 * @brief retorna o peso de um futebolista
	 * @return unsigned int com o peso de um futebolista
	 */
	unsigned int getPeso() const;
	/**
	 * @brief retorna a altura de um futebolista
	 * @return unsigned int com a altura de um futebolista
	 */
	unsigned int getAltura() const;
	/**
	 * @brief retorna o valor do passe de um futebolista
	 * @return unsigned int com o valor do passe de um futebolista
	 */
	unsigned int getValorPasse() const;

	//metodos SET
	/**
	 * @brief altera a posicao de um futebolista
	 * @param p string com a posicao de um futebolista
	 */
	void setPosicao(string p);
	/**
	 * @brief altera o clube de um futebolista
	 * @param c string com o clube de um futebolista
	 */
	void setClube(string c);
	/**
	 * @brief altera o peso de um futebolista
	 * @param p unsigned int com o peso de um futebolista
	 */
	void setPeso(unsigned int p);
	/**
	 * @brief altera a altura de um futebolista
	 * @param a unsigned int com a altura de um futebolista
	 */
	void setAltura(unsigned int a);
	/**
	 * @brief altera o valor do passe de um futebolista
	 * @param vp unsigned int com o valor do passe de um futebolista
	 */
	void setValorPasse(unsigned int vp);

	//Outros metodos
	/**
	 * @brief le os jogadores do ficheiro jogadores.txt e armazena-os num vector
	 * @return vector da classe Futebolista com todos os futebolistas que ja estiveram presentes na selecao
	 */
	vector<Futebolista> ReadJogadores();
	/**
	 * @brief adiciona um jogador ao vector da classe Futebolista
	 * @param jogadores vector da classe Futebolista com todos os futebolistas que ja estiveram presentes na selecao
	 */
	void AdicionarJogador(vector<Futebolista>& jogadores) const;
	/**
	 * @brief remove um jogador do vector da classe Futebolista
	 * @param jogadores vector da classe Futebolista com todos os futebolistas que ja estiveram presentes na selecao
	 */
	void RemoverJogador(vector<Futebolista>& jogadores) const;
	/**
	 * @brief mostra as informacoes de um jogador do vector da classe Futebolista
	 * @param jogadores vector da classe Futebolista com todos os futebolistas que ja estiveram presentes na selecao
	 */
	void InformacoesJogador(vector<Futebolista>& jogadores) const;
	/**
	 * @brief edita as informacoes de um jogador do vector da classe Futebolista
	 * @param jogadores vector da classe Futebolista com todos os futebolistas que ja estiveram presentes na selecao
	 */
	void EditarJogador(vector<Futebolista>& jogadores) const;
};
/**
 * @brief class relativa a Equipa Tecnica
 */
class EquipaTecnica : public MembroSelecao {
	string funcao;
	unsigned int salario;
public:
	/**
	 * @brief construtor vazio da classe EquipaTecnica
	 */
    EquipaTecnica() { salario = 0; };
    /**
     * @brief construtor da classe EquipaTecnica
     * @param n nome do membro da equipa tecnica
     * @param dn data de nascimento do membro da equipa tecnica
     * @param f funcao do membro da equipa tecnica
     * @param s salario do membro da equipa tecnica
     */
	EquipaTecnica(string n, string dn, string f, unsigned int s);
	/**
	 *
	 * @param out ostream com a informacao de um membro da equipa tecnica
	 * @param et membro da equipa tecnica
	 * @return ostream com a informacao de um membro da equipa tecnica
	 */
	friend ostream& operator<<(ostream& out, const EquipaTecnica& et);
	
	// metodos GET
	/**
	 * @brief retorna a funcao de um membro da equipa tecnica
	 * @return funcao de um membro da equipa tecnica
	 */
	string getFuncao() const;
	/**
	 * @brief retorna o salario de um membro da equipa tecnica
	 * @return salario de um membro da equipa tecnica
	 */
	unsigned int getSalario() const;

	// metodos SET
	/**
	 * @brief altera a funcao de um membro da equipa tecnica
	 * @param f string com a funcao de um membro da equipa tecnica
	 */
	void setFuncao(string f);
	/**
	 * @brief altera o salario de um membro da equipa tecnica
	 * @param s string com o salario de um membro da equipa tecnica
	 */
	void setSalario(unsigned int s);

	//Outros metodos
	/**
	 * @brief le os membros tecnicos do ficheiro equipatecnica.txt e armazena-os num vector
	 * @return vector da classe EquipaTecnica com todos os membros tecnicos que ja estiveram presentes na selecao
	 */
	vector<EquipaTecnica> ReadEquipaTecnica();
	/**
	 * @brief adiciona um membro tecnico ao vector da classe EquipaTecnica
	 * @param equipatecnica vector da classe EquipaTecnica com todos os membros tecnicos que ja estiveram presentes na selecao
	 */
	void AdicionarTecnico(vector<EquipaTecnica>& equipatecnica) const;
	/**
	 * @brief remove um membro tecnico do vector da classe EquipaTecnica
	 * @param equipatecnica vector da classe EquipaTecnica com todos os membros tecnicos que ja estiveram presentes na selecao
	 */
	void RemoverTecnico(vector<EquipaTecnica>& equipatecnica) const;
	/**
	 * @brief mostra as informacoes de um membro tecnico do vector da classe EquipaTecnica
	 * @param equipatecnica vector da classe EquipaTecnica com todos os membros tecnicos que ja estiveram presentes na selecao
	 */
	string InformacoesTecnico(vector<EquipaTecnica>& equipatecnica) const;
	/**
	 * @brief editar as informacoes de um membro tecnico do vector da classe EquipaTecnica
	 * @param equipatecnica vector da classe EquipaTecnica com todos os membros tecnicos que ja estiveram presentes na selecao
	 */
	void EditarTecnico(vector<EquipaTecnica>& equipatecnica) const;
};
/**
 * @brief class exception para futebolistas ja existentes
 */

class Selecionadores : public EquipaTecnica{
    unsigned int titulosganhos;
    vector<unsigned int> selecoes;
public:
    Selecionadores();
    Selecionadores(string n, unsigned int tg, vector<unsigned int> sel);
    Selecionadores(string n, unsigned int tg);
    unsigned int getTitulosGanhos() const;
    vector<unsigned int> getSelecoes() const;
    void setTitulosGanhos(unsigned int t);
    void setSelecoes(vector<unsigned int> sel);
    BST<Selecionadores> ReadSelecionadores(BST<Selecionadores> &selecionadores);
    bool operator < (const Selecionadores &s) const;
};


class JogadorJaExistente {
public:
    string nome, datanascimento;
    /**
     * @brief construtor da classe com exception
     * @param n string com nome de um futebolista
     * @param dn string com data de nascimento de um futebolista
     */
    JogadorJaExistente(string n, string dn) {
        nome = n;
        datanascimento = dn;
    }
};

/**
 * @brief class exception para membros tecnicos ja existentes
 */
class MembroTecnicoJaExistente {
public:
    string nome, datanascimento;
    /**
     * @brief construtor da classe com exception
     * @param n string com nome de um membro tecnico
     * @param dn string data de nascimento com nome de um membro tecnico
     */
    MembroTecnicoJaExistente(string n, string dn) {
        nome = n;
        datanascimento = dn;
    }
};