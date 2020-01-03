#pragma once

#include <string>
#include <vector>
#include <queue>
using namespace std;

class Equipamentos{
    string tipo;
    double preco;
public:
    /**
     * @brief Construtor vazio da classe Equipamentos
     */
    Equipamentos();
    /**
     * @brief Construtor da classe Equipamentos
     * @param t tipo
     * @param p preco
     */
    Equipamentos(string t, double p);
    /**
     * @brief funcao get para retornar o tipo do equipamento
     * @return tipo do equipamento
     */
    string getTipo();
    /**
     * @brief funcao get para retornar o preço do equipamento
     */
    double getPreco();
    /**
     * @brief funcao set para mudar o tipo do equipamento
     * @param t tipo
     */
    void setTipo(string t);
    /**
     * @brief funcao set para mudar o preço do equipamento
     * @param p preço
     */
    void setPreco(double p);

};

class Fornecedores{
    string nome;
    double reputacao;
    unsigned int reviews;
    vector<Equipamentos> equipamentos;
public:
    /**
     * @brief construtor vazio da classe Fornecedores
     */
    Fornecedores();
    /**
     * @brief construtor da classe Fornecedores
     * @param n nome do fornecedor
     * @param r reputação do fornecedor
     * @param re numero de reviews do fornecedor
     * @param eq vetor de equipamentos do fornecedor
     */
    Fornecedores(string n, double r, unsigned int re, vector<Equipamentos> eq);
    /**
     * @brief funcao get para retornar o nome
     * @return nome do fornecedor
     */
    string getNome() const;
    /**
     * @brief funcao get para retornar a reputacao
     * @return reputacao do fornecedor
     */
    double getReputacao() const;
    /**
     * @brief funcao get para retornar as reviews
     * @return reviews do fornecedor
     */
    unsigned int getReviews() const;
    /**
     * @brief funcao get para retornar equipamentos
     * @return equipamentos do fornecedor
     */
    vector<Equipamentos> getEquipamentos() const;
    /**
     * @brief funcao set para mudar o nome de um fornecedor
     * @param n nome
     */
    void setNome(string n);
    /**
     * @brief funcao set para mudar a reputacao de um fornecedor
     * @param r reputacao
     */
    void setReputacao(double r);
    /**
     * @brief funcao set para mudar o numero de reviews de um fornecedor
     * @param r numero de reviews
     */
    void setReviews(unsigned int r);
    /**
     * @brief funcao set para mudar o vetor de equipamentos de um fornecedor
     * @param eq vetor de equipamentos
     */
    void setEquipamentos(vector<Equipamentos> eq);
    /**
     * @brief funcao para ler os fornecedores do ficheiro
     * @return priority queue com todos os fornecedores
     */
    priority_queue<Fornecedores> ReadFornecedores();
    /**
     * @brief funcao para mostrar a informacao de um fornecedor
     * @param fornecedores priority queue com todos os fornecedores
     */
    void InfoFornecedores(priority_queue<Fornecedores> fornecedores);
    /**
     * @brief funcao para vender um equipamento de um fornecedor à seleção
     * @param fornecedores priority queue com todos os fornecedores
     */
    void VenderEquipamentos(priority_queue<Fornecedores> &fornecedores);
    /**
     * @brief operador < para um objeto da classe Fornecedores
     * @param f fornecedor
     * @return true caso seja menor, senão falso
     */
    bool operator< (const Fornecedores& f) const;
    /**
     * @brief operador == para um objeto da classe Fornecedores
     * @param f fornecedor
     * @return true caso seja igual, senão falso
     */
    bool operator== (const Fornecedores& f) const;
    /**
     * @brief ostream para um objeto da classe Fornecedores
     * @param f fornecedor
     * @param out ostream
     * @return ostream com informações do operador
     */
    friend ostream& operator<<(ostream& out, const Fornecedores& f);
};


class SemFornecedor {
public:
    /**
     * @brief tipo do equipamento
     */
    string tipo;
    /**
     * @brief construtor da clsse SemFornecedor (exceção)
     * @param t tipo do equipamento
     */
    SemFornecedor(string t) {
        tipo = t;
    }
};