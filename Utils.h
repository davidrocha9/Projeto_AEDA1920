#pragma once
#include "Date.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @brief separa os nomes de um membro da selecao e armazena-os num vector da classe string
 * @param str string com o nome de um membro da selecao
 * @return vector da classe string com as palavras do nome de um membro da selecao
 */
vector<string> nameSplitter(string& str);

/**
 * @brief separa uma string com informacoes separadas por '|'
 * @param s string com informacoes das convocatorias/futebolistas/jogos/equipa tecnica
 * @return vector da classe string com informacoes das convocatorias/futebolistas/jogos/equipa tecnica
 */
vector<string> divideStrings(string& s);
/**
 * @brief mostra na consola a mensagem de boas vindas
 */
void logo();
string dateToString(Date date);