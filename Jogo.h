#pragma once
#include "Jogadores.h"
#include "Date.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
/**
 * @brief classe relativa ao jogo
 */
class Jogo{
    string pais, adversario, cidade, estadio;
    Date data;
    vector<Futebolista> jogadores_convocados, jogadores_participantes, lesao;
    vector<string> equipa_arbitragem, equipa_adversaria;
    multimap<Futebolista, unsigned int> golos, assists, passes, passes_acertados, desarmes, faltas, minutos_jogados, amarelos, vermelhos;
    multimap<Futebolista, double> km_percorridos;

public:
    Jogo();
    /**
     * @brief Construtor da classe jogo
     * @param data Objeto da classe Date que define a data do jogo
     * @param pais String com o pais onde se realizou o jogo
     * @param adversario String com o adversario contra quem Portugal jogou
     * @param cidade String com a cidade onde se realiza o jogo
     * @param estadio String com o estadio onde se vai jogar
     * @param jogadores_conv Vetor com os jogadores portugueses convocados do jogo
     * @param jogadores_part Vetor com os jogadores portugueses participantes do jogo
     * @param equipa_arbitragem Vetor com a equipa de arbitragem do jogo
     * @param equipa_adversaria Vetor com o 11 inicial adversario
     * @param golos Define um multimap associando os jogadores portugueses aos golos no jogo
     * @param assists Define um multimap associando os jogadores portugueses as assistencias no jogo
     * @param passes Define um multimap associando os jogadores portugueses aos passes no jogo
     * @param passes_acertados Define um multimap associando os jogadores portugueses aos passes acertados no jogo
     * @param desarmes Define um multimap associando os jogadores portugueses aos desarmes no jogo
     * @param faltas Define um multimap associando os jogadores portugueses as faltas no jogo
     * @param km_percorridos Define um multimap associando os jogadores portugueses aos quilometros percorridos no jogo
     * @param minutos_jogados Define um multimap associando os jogadores portugueses aos minutos em campo durante o jogo
     * @param amarelos Define um multimap associando os jogadores portugueses aos amarelos no jogo
     * @param vermelhos Define um multimap associando os jogadores portugueses aos vermelhos no jogo
     * @param lesao Vetor com os jogadores que se lesionaram no jogo
     */
    Jogo(Date data, string pais, string adversario, string cidade, string estadio, vector<Futebolista> jogadores_conv, vector<Futebolista> jogadores_part, vector<string> equipa_arbitragem, vector<string> equipa_adversaria, multimap<Futebolista, unsigned int> golos, multimap<Futebolista, unsigned int> assists, multimap<Futebolista, unsigned int> passes, multimap<Futebolista, unsigned int> passes_acertados, multimap<Futebolista, unsigned int> desarmes, multimap<Futebolista, unsigned int> faltas, multimap<Futebolista, double> km_percorridos, multimap<Futebolista, unsigned int> minutos_jogados, multimap<Futebolista, unsigned int> amarelos, multimap<Futebolista, unsigned int> vermelhos, vector<Futebolista> lesao);
    /**
     *@brief Destrutor da classe jogo
     */
    virtual ~Jogo() {};
    /**
     * @brief Mostra a informação de um jogo (j) sem estatisticas
     * @param out Ostream vazia
     * @param j Objeto da classe Jogo que será apresentado
     * @return Ostream com a informação do jogo (sem estatisticas)
     */
    friend ostream& operator<<(ostream& out, Jogo& j);

    //métodos GET
    /**
     * @brief Funcao get que retorna a data
     * @return Retorna um objeto da classe Date
     */
    Date getData() const;
    /**
     * @brief Funcao get que retorna o adversario
     * @return Retorna uma string referente ao adversario que Portugal defrontou
     */
    string getAdversario() const;
    /**
     * @brief Funcao get que retorna o pais
     * @return Retorna uma string referente ao pais onde se realizou o jogo
     */
    string getPais() const;
    /**
     * @brief Funcao que retorna a cidade
     * @return Retorna uma string referente a cidade onde se realizou o jogo
     */
    string getCidade() const;
    /**
     * @brief Funcao que retorna o estadio
     * @return Retorna uma string referente ao estadio onde se realizou o jogo
     */
    string getEstadio() const;
    /**
     * @brief Funcao que retorna os jogadores portugueses convocados
     * @return Retorna um vetor da classe Futebolista com os jogadores portugueses convocados para o jogo
     */
    vector<Futebolista> getJogadoresConvocados() const;
    /**
     * @brief Funcao que retorna os jogadores portugueses participantes
     * @return Retorna um vetor da classe Futebolista com os jogadores portugueses participantes no jogo
     */
    vector<Futebolista> getJogadoresParticipantes() const;
    /**
     * @brief Funcao que retorna a equipa de arbitragem
     * @return Retorna um vetor de strings com a equipa de arbitragem do jogo
     */
    vector<string> getEquipaArbitragem() const;
    /**
     * @brief Funcao que retorna o 11 inicial da selecao adversaria
     * @return Retorna um vetor de strings com o 11 inicial adversario do jogo
     */
    vector<string> getEquipaAdversaria() const;
    /**
     * @brief Funcao que retorna os jogadores portugues lesionados
     * @return Retorna um vetor da classe Futebolista com os jogadores portugueses lesionados durante o jogo
     */
    vector<Futebolista> getLesao() const;
    /**
     * @brief Funcao que retorna os golos marcados pelos jogadores portugueses individualmente
     * @return Retorna um multimap que associa os jogadores portugueses aos golos que cada um marcou no jogo
     */
    multimap<Futebolista, unsigned int> getGolos() const;
    /**
     * @brief Funcao que retorna as assistencias feitas pelos jogadores portugueses individualmente
     * @return Retorna um multimap que associa os jogadores portugueses as assistencias que cada um fez no jogo
     */
    multimap<Futebolista, unsigned int> getAssists() const;
    /**
     * @brief Funcao que retorna os passes feitos pelos jogadores portugueses individualmente
     * @return Retorna um multimap que associa os jogadores portugueses aos passes que cada um fez no jogo
     */
    multimap<Futebolista, unsigned int> getPasses() const;
    /**
     * @brief Funcao que retorna os passes acertados pelos jogadores portugueses individualmente
     * @return Retorna um multimap que associa os jogadores portugueses aos passes acertados que cada um fez no jogo
     */
    multimap<Futebolista, unsigned int> getPassesAcertados() const;
    /**
     * @brief Funcao que retorna os desarmes feitos pelos jogadores portugueses individualmente
     * @return Retorna um multimap que associa os jogadores portugueses aos desarmes que cada um fez no jogo
     */
    multimap<Futebolista, unsigned int> getDesarmes() const;
    /**
     * @brief Funcao que retorna as faltas feitas pelos jogadores portugueses individualmente
     * @return Retorna um multimap que associa os jogadores portugueses as faltas que cada um fez no jogo
     */
    multimap<Futebolista, unsigned int> getFaltas() const;
    /**
     * @brief Funcao que retorna os quilometros feitos pelos jogadores portugueses individualmente
     * @return Retorna um multimap que associa os jogadores portugueses aos quilometros que cada um fez no jogo
     */
    multimap<Futebolista, double> getKmPercorridos() const;
    /**
     * @brief Funcao que retorna os minutos em campo que cada jogador jogou
     * @return Retorna um multimap que associa os jogadores portugueses aos minutos que cada um esteve no jogo
     */
    multimap<Futebolista, unsigned int> getMinutosJogados() const;
    /**
     * @brief Funcao que retorna os amarelos que os jogadores portugueses levaram individualmente
     * @return Retorna um multimap que associa os jogadores portugueses aos amarelos que cada um levou no jogo
     */
    multimap<Futebolista, unsigned int> getAmarelos() const;
    /**
     * @brief Funcao que retorna os vermelhos que os jogadores portugueses levaram individualmente
     * @return Retorna um multimap que associa os jogadores portugueses aos vermelhos que cada um levou no jogo
     */
    multimap<Futebolista, unsigned int> getVermelhos() const;

    //métodos SET
    /**
     * @brief Funcao que altera a data do jogo
     * @param data Objeto da classe Date que representa a nova data
     */
    void setData(Date data);
    /**
     * @brief Funcao que altera o adversario do jogo
     * @param adversario String que representa o novo adversario do jogo
     */
    void setAdversario(string adversario);
    /**
     * @brief Funcao que altera o pais onde se realiza o jogo
     * @param pais String que representa o novo pais do jogo
     */
    void setPais(string pais);
    /**
     * @brief Funcao que altera a cidade onde se realiza o jogo
     * @param cidade String que representa a nova cidade do jogo
     */
    void setCidade(string cidade);
    /**
     * @brief Funcao que altera o estadio onde se realiza o jogo
     * @param estadio String que representa o novo estadio do jogo
     */
    void setEstadio(string estadio);
    /**
     * @brief Funcao que altera o vetor dos jogadores convocados do jogo
     * @param jogadores_convocados Vetor que representa os jogadores convocados atualizados
     */
    void setJogadoresConvocados(vector<Futebolista> jogadores_convocados);
    /**
     * @brief Funcao que altera o vetor dos jogadores participantes do jogo
     * @param jogadores_participantes Vetor que representa os jogadores participantes atualizados
     */
    void setJogadoresParticipantes(vector<Futebolista> jogadores_participantes);
    /**
     * @brief Funcao que altera o vetor da equipa de arbitragem
     * @param equipa_arbitragem Vetor que representa a equipa de arbitragem atualizada
     */
    void setEquipaArbitragem(vector<string> equipa_arbitragem);
    /**
     * @brief Funcao que altera o vetor do 11 inicial adversario
     * @param equipa_adversaria Vetor que representa o 11 inicial adversario atualizado
     */
    void setEquipaAdversaria(vector<string> equipa_adversaria);
    /**
     * @brief Funcao que altera o vetor dos jogadores que se lesionaram durante o jogo
     * @param lesao Vetor que representa os jogadores lesionados durante o jogo atualizado
     */
    void setLesao(vector<Futebolista> lesao);
    /**
     * @brief Funcao que altera os golos marcados no jogo
     * @param golos Multimap atualizado que associa os jogadores aos golos que cada um marcou
     */
    void setGolos(multimap<Futebolista, unsigned int> golos);
    /**
     * @brief Funcao que altera as assistencias feitas no jogo
     * @param assists Multimap atualizado que associa os jogadores as assistencias feitas por cada um
     */
    void setAssists(multimap<Futebolista, unsigned int> assists);
    /**
     * @brief Funcao que altera os passes feitos no jogo
     * @param passes Multimap atualizado que associa os jogadores aos passes feitos por cada um
     */
    void setPasses(multimap<Futebolista, unsigned int> passes);
    /**
     * @brief Funcao que altera os passes acertados no jogo
     * @param passes_acertados Multimap atualizado que associa os jogadores aos passes acertados por cada um
     */
    void setPassesAcertados(multimap<Futebolista, unsigned int> passes_acertados);
    /**
     * @brief Funcao que altera os desarmes feitos no jogo
     * @param desarmes Multimap atualizado que associa os jogadores aos desarmes feitos por cada um
     */
    void setDesarmes(multimap<Futebolista, unsigned int> desarmes);
    /**
     * @brief Funcao que altera as faltas feitas no jogo
     * @param faltas Multimap atualizado que associa os jogadores as faltas feitas por cada um
     */
    void setFaltas(multimap<Futebolista, unsigned int> faltas);
    /**
     * @brief Funcao que altera os quilometros percorridos no jogo
     * @param km_percorridos Multimap atualizado que associa os jogadores aos quilometros percorridos por cada um
     */
    void setKmPercorridos(multimap<Futebolista, double> km_percorridos);
    /**
     * @brief Funcao que altera os minutos em campo durante o jogo
     * @param minutos_jogados Multimap atualizado que associa os jogadores aos minutos em campo de cada um
     */
    void setMinutosJogados(multimap<Futebolista, unsigned int> minutos_jogados);
    /**
     * @brief Funcao que altera os cartoes amarelos no jogo
     * @param amarelos Multimap atualizado que associa os jogadores aos cartoes amarelos que cada um levou
     */
    void setAmarelos(multimap<Futebolista, unsigned int> amarelos);
    /**
     * @brief Funcao que altera os cartoes vermelhos no jogo
     * @param vermelhos Multimap atualizado que associa os jogadores aos cartoes vermelhos que cada um levou
     */
    void setVermelhos(multimap<Futebolista, unsigned int> vermelhos);
    /**
     *@brief Compara dois objetos da classe Jogo
     * @param jogo Objeto da classe Jogo
     * @return Returna true ou false dependendo se os dois jogos são iguais ou não
     */
    bool operator==(Jogo& jogo) const;
    /**
     * @brief Compara dois objetos da classe Jogo
     * @param jogo Objeto da classe Jogo
     * @return Returna true ou false dependendo se os dois jogos são diferentes ou não
     */
    bool operator!=(Jogo& jogo) const;

    //Outros métodos
    /**
     * @brief Funcao que permite ler o ficheiro do jogo (Jogo.txt)
     * @return Retorna um vetor da classe Jogo (jogos), sendo que dá push back a um construtor
     */
    vector<Jogo> ReadJogo();
    /**
     * @brief Funcao que adiciona um jogo ao ficheiro do jogo (Jogo.txt)
     * @param jogos Vetor da classe Jogo (jogos) ao qual vai ser adicionado o novo jogo criado
     * @param jogadores Vetor da classe Futebolista que contem os jogadores disponíveis (jogadores.txt)
     */
    void addJogo(vector<Jogo>& jogos, vector<Futebolista>& jogadores);
    /**
     * @brief Funcao que remove um jogo do ficheiro do jogo (Jogo.txt)
     * @param jogos Vetor da classe Jogo ao qual será removido um jogo
     * @return Retorna um objeto da classe Jogo que foi removido do ficheiro do jogo (Jogo.txt)
     */
    Jogo removeJogo(vector<Jogo>& jogos);
    /**
     * @brief Funcao que mostra a informação total (com estatisticas) ou parcial (sem estatisticas) sobre um jogo
     * @param jogos Vetor da classe Jogo que contém os jogos do ficheiro do jogo (Jogo.txt)
     */
    void infoJogo(vector<Jogo>& jogos);
    /**
     * @brief Funcao que permite editar a informacao de um jogo
     * @param jogos Vetor da classe Jogo que contem o jogo a ser editado
     * @param jogadores Vetor da classe Futebolista que contém os jogadores disponiveis (jogadores.txt)
     */
    void editJogo(vector<Jogo>& jogos, vector<Futebolista>& jogadores);

};
/**
 * class exception para jogos ja existentes
 */
class JogoJaExistente {
public:
    string data;
    /**
     * @brief construtor da exception
     * @param d string com a data do jogo
     */
    JogoJaExistente(string d) {
        data = d;
    }
};