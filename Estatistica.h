#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Jogadores.h"
#include "Jogo.h"
#include "Convocatoria.h"
#include <map>

using namespace std;

/**
 * @brief calcula as estatisticas individuais de um futebolista
 * @param jogadores vector da classe Futebolista com todos os futebolistas existentes
 * @param jogos vector da classe Jogo com todos os jogos existentes
 * @param convocatorias vector da classe Convocatoria com todas as convocatorias existentes
 */
void EstatisticaJogador(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatorias);
/**
 * @brief calcula as estatisticas coletivas da selecao
 * @param jogadores vector da classe Futebolista com todos os futebolistas existentes
 * @param jogos vector da classe Jogo com todos os jogos existentes
 * @param convocatorias vector da classe Convocatoria com todas as convocatorias existentes
 */
void EstatisticaSelecao(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatorias);
/**
 * @brief calcula o custo individual mensal de cada jogador
 * @param jogadores vector da classe Futebolista com todos os futebolistas existentes
 * @param jogos vector da classe Jogo com todos os jogos existentes
 * @param convocatorias vector da classe Convocatoria com todas as convocatorias existentes
 */
void CustoIndvMes(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatorias);
/**
 * @brief calcula o custo coletivo mensal de toda os futebolista da selecao
 * @param jogadores vector da classe Futebolista com todos os futebolistas existentes
 * @param jogos vector da classe Jogo com todos os jogos existentes
 * @param convocatorias vector da classe Convocatoria com todas as convocatorias existentes
 * @param equipatecnica vector da classe EquipaTecnica com todos os membros tecnicos existentes
 */
void CustoGeralMesEquip(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatorias, vector<EquipaTecnica>& equipatecnica);
/**
 * @brief calcula o custo coletivo mensal de toda a selecao
 * @param jogadores vector da classe Futebolista com todos os futebolistas existentes
 * @param jogos vector da classe Jogo com todos os jogos existentes
 * @param convocatorias vector da classe Convocatoria com todas as convocatorias existentes
 */
void CustoGeralMesTudo(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatorias, vector<EquipaTecnica>& equipatecnica);