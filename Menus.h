#pragma once

#include "Selecao.h"
/**
 * @brief menus do projeto
 * @param selecao objeto da classe Selecao com a selecao
 */
void mainMenu(Selecao& selecao);

/**
 * @brief struct usada para gerar o corredor da fama
 */
struct JogadorFama{
    /**
     * @brief nome do jogador
     */
    string nome;
    /**
     * @brief numero de golos do jogador
     */
    unsigned int golos;
    /**
     * @brief numero de assistencias do jogador
     */
    unsigned int assists;
    /**
     * @brief numero de jogos do jogador
     */
    unsigned int jogos;
};