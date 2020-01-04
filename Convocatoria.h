#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Jogadores.h"
#include "Jogo.h"
#include "Date.h"

using namespace std;
/**
 * @brief class relativa a convocatoria
 */
class Convocatoria {
private:
	unsigned int id, nrjogos, custodiario;
	string competicao, selecionador;
	Date datainicial, datafinal, dnselecionador;
	static const unsigned int alojamentoealimentacao = 150;
	vector<Jogo> jogos;
	vector<Futebolista> jogadoresnaconvocatoria;
	vector<EquipaTecnica> equipatnaconvocatoria;
	multimap<Futebolista, bool> condicaofisica;
	multimap<Futebolista, Date> dataschegada;
	multimap<Futebolista, Date> dataspartida;
public:
    /**
     * @brief construtor vazio da convocatoria
     */
	Convocatoria() { id = 0; nrjogos = 0; custodiario = 0; };
	/**
	 *
	 * @param id id da convocatoria
	 * @param nrjogos numero de jogos da convocatoria
	 * @param custo custo diario da convocatoria
	 * @param datai data inicial da convocatoria
	 * @param dataf data final da convocatoria
	 * @param competicao string com o nome da competicao em causa
	 * @param jogos vector da classe Jogos com os jogos
	 * @param jogadoresnaconvocatoria vector da classe Futebolista com os futebolistas
	 * @param equipatnaconvocatoria vector da classe EquipaTecnica com os membros tecnicos
	 * @param condicaofisica multimap que associa os futebolistas com a sua condicao fisica (se estao lesionados ou nao)
	 * @param dataschegada multimap que associa os futebolistas com as respetivas datas de chegada
	 * @param dataspartida multimap que associa os futebolistas com as respetivas datas de partida
	 * @param selecionador nome do selecionador
	 * @param dnselecionador data de nascimento do selecionador
	 */
	Convocatoria(unsigned int id, unsigned int nrjogos, unsigned int custo, string datai, string dataf, string competicao, vector<Jogo> jogos, vector<Futebolista> jogadoresnaconvocatoria, vector<EquipaTecnica> equipatnaconvocatoria, multimap<Futebolista, bool> condicaofisica, multimap<Futebolista, Date> dataschegada, multimap<Futebolista, Date> dataspartida, string selecionador, Date dnselecionador);
	/**
	 * @brief destrutor da classe Convocatoria
	 */
	virtual ~Convocatoria() {};
	/**
	 * @brief ostream da classe Convocatoria para mostrar a informacao de uma convocatoria
	 * @param out ostream com a informacao da convocatoria
	 * @param c objeto da classe Convocatoria com a convocatoria
	 * @return ostream com a informacao da convocatoria
	 */
	friend ostream& operator<<(ostream& out, Convocatoria& c);

	// metodos GET
	/**
	 * @brief retorna o id de uma convocatoria
	 * @return unsigned int com o id da convocatoria
	 */
	unsigned int getId() const;
	/**
	 * @brief retorna o numero de jogos de uma convocatoria
	 * @return unsigned int com o numero de jogos de uma convocatoria
	 */
	unsigned int getNrJogos() const;
	/**
	 * @brief retorna o custo diario de uma convocatoria
	 * @return unsigned int com o numero de jogos de uma convocatoria
	 */
	unsigned int getCustoDiario() const;
	/**
	 * @brief retorna um objeto da classe Date com a data inicial
	 * @return objeto da classe Date com a data inicial
	 */
	Date getDataInicial() const;
	/**
	 * @brief retorna um objeto da classe Date com a data final
	 * @return objeto da classe Date com a data final
	 */
	Date getDataFinal() const;
	/**
	 * @brief retorna a string com o nome da competicao da convocatoria
	 * @return string com a competicao da convocatoria
	 */
	string getCompeticao() const;
	/**
	 * @brief retorna o nome do selecionador
	 * @return string com o nome do selecionador
	 */
	string getSelecionador() const;
	/**
	 * @brief retorna um vector da classe Jogo com os jogos da convocatoria
	 * @return vector da classe Jogo com os jogos da convocatoria
	 */
	vector<Jogo> getJogos() const;
	/**
	 * @brief retorna um vector da classe Futebolista com os jogadores da convocatoria
	 * @return vector da classe Futebolista com os jogadores da convocatoria
	 */
	vector<Futebolista> getJogadores() const;
	/**
	 * @brief retorna um vector da classe EquipaTecnica com os membros tecnicos da convocatoria
	 * @return vector da classe EquipaTecnica com os membros tecnicos da convocatoria
	 */
	Date getDataNascimentoSelecionador() const;
	/**
	 * @brief retorna um vetor com a equipa tecnica
	 * @return vetor com a equipa tecnica
	 */
	vector<EquipaTecnica> getEquipaTecnica();
	/**
	 * @brief retorna um multimap que associa um futebolista à sua condicao fisica (lesionado ou nao)
	 * @return multimap que associa um futebolista à sua condicao fisica (lesionado ou nao)
	 */
	multimap<Futebolista, bool> getCondicaoFisica();
	/**
	 * @brief retorna um multimap que associa um futebolista à sua data de chegada
	 * @return multimap que associa um futebolista à sua data de chegada
	 */
	multimap<Futebolista, Date> getDatasChegada() const;
	/**
	 * @brief retorna um multimap que associa um futebolista à sua data de partida
	 * @return multimap que associa um futebolista à sua data de partida
	 */
	multimap<Futebolista, Date> getDatasPartida() const;

	// metodos SET
	/**
	 * @brief altera o valor do id da convocatoria
	 * @param id unsigned int com id da convocatoria
	 */
	void setId(unsigned int id);
	/**
	 * @brief altera o valor do numero de jogos
	 * @param nrjogos unsigned int com o numero de jogos
	 */
	void setNrJogos(unsigned int nrjogos);
	/**
	 * @brief altera o valor do custo diario
	 * @param custo unsigned int com o custo diario
	 */
	void setCustoDiario(unsigned int custo);
	/**
	 * @brief altera o valor da data inicial
	 * @param datai string com o valor da data inicial
	 */
	void setDataInicial(string datai);
	/**
	 * @brief altera o valor da data final
	 * @param dataf string como o valor data final
	 */
	void setDataFinal(string dataf);
	/**
	 * @brief altera o nome da competicao
	 * @param comp string como o nome da competicao da convocatoria
	 */
	void setCompeticao(string comp);
	/**
	 * @brief altera o nome do selecionador da convocatoria
	 * @param s nome do selecionador
	 */
	void setSelecionador(string s);
	/**
	 * @brief altera a equipa tecnica
	 * @param et vetor com a equipa tecnica
	 */
	void setEquipaTecnica(vector<EquipaTecnica> et);
	/**
	 * @brief altera os jogos da convocatoria
	 * @param jogos vector da classe Jogo com os jogos da convocatoria
	 */
	void setJogos(vector<Jogo> jogos);
	/**
	 * @brief altera a condicao fisica de um jogador (lesionado ou nao)
	 * @param condicaofisica multimap que associa um futebolista à sua condicao fisica (lesionado ou nao)
	 */
	void setCondicaoFisica(multimap<Futebolista, bool> condicaofisica);
	/**
	 * @brief altera a data de chegada de um futebolista
	 * @param dataschegada multimap que associa um futebolista à sua data de chegada
	 */
	void setDatasChegada(multimap<Futebolista, Date> dataschegada);
	/**
	 * @brief altera a data de partida de um futebolista
	 * @param dataspartida multimap que associa um futebolista à sua data de partida
	 */
	void setDatasPartida(multimap<Futebolista, Date> dataspartida);

	//Outros metodos
	/**
	 * @brief le as convocatorias do ficheiros convocatorias.txt e armazena-os num vector
	 * @param jogo vector da classe Jogo com todos os jogos ja realizados
	 * @return vector da classe Convocatoria com todas as convocatorias da selecao
	 */
	vector<Convocatoria> ReadConvocatoria(vector<Jogo> jogo);
	/**
	 * @brief mostra as informacoes de uma convocatoria
	 * @param convocatoria  vector da classe Convocatoria com todas as convocatorias da selecao
	 */
	void InformacoesConvocatoria(vector<Convocatoria>& convocatoria) const;
	/**
	 * @brief cria uma nova convocatoria
	 * @param convocatoria vector da classe Convocatoria com todas as convocatorias existentes
	 * @param jogadores vector da classe Futebolista com todos os jogadores existentes
	 * @param equipatecnica vector da classe EquipaTecnica com todos os membros tecnicos existentes
	 * @param jogo vector da classe Jogo com todos os jogos existentes
	 */
	Convocatoria AdicionarConvocatoria(vector<Convocatoria>& convocatoria, vector<Futebolista> jogadores, vector<EquipaTecnica> equipatecnica, vector<Jogo> jogo) const;
	/**
	 * @brief remove uma convocatoria do vector das convocatorias
	 * @param convocatoria vector da classe Convocatoria com todas as convocatorias existentes
	 */
	void RemoverConvocatoria(vector<Convocatoria>& convocatoria) const;
	/**
	 * @brief edita uma convocatoria
	 * @param convocatoria vector da classe Convocatoria com todas as convocatorias existentes
	 * @param jogo vector da classe Jogo com todos os jogos existentes
	 */
	void EditarConvocatoria(vector<Convocatoria>& convocatoria, vector<Jogo>& jogo) const;
	/**
	 * @brief aquando da remocao de um jogo do vector com todos os jogos, remove esse mesmo jogo automaticamente da convocatoria
	 * @param convocatoria vector da classe Convocatoria com todas as convocatorias existentes
	 * @param j objeto da classe Jogo com o jogo removido em causa
	 */
	void updateJogos(vector<Convocatoria>& convocatoria, Jogo& j);
};
/**
 * @brief class exception para convocatorias ja existentes
 */
class ConvocatoriaJaExistente {
public:
    /**
     * @brief id da convocatoria
     */
    unsigned int id;
    /**
     * @brief construtor da exception
     * @param i string com id da convocatoria
     */
    ConvocatoriaJaExistente(unsigned int i) {
        id = i;
    }
};