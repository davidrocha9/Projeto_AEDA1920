#pragma once

#include <string>
#include <vector>
#include <queue>
using namespace std;

class Equipamentos{
    string tipo;
    double preco;
public:
    Equipamentos();
    Equipamentos(string t, double p);
    string getTipo();
    double getPreco();
    void setTipo(string t);
    void setPreco(double p);

};

class Fornecedores{
    string nome;
    double reputacao;
    vector<Equipamentos> equipamentos;
public:
    Fornecedores();
    Fornecedores(string n, double r, vector<Equipamentos> eq);
    string getNome() const;
    double getReputacao() const;
    vector<Equipamentos> getEquipamentos() const;
    void setNome(string n);
    void setReputacao(double r);
    void setEquipamentos(vector<Equipamentos> eq);
    priority_queue<Fornecedores> ReadFornecedores();
    void InfoFornecedores(priority_queue<Fornecedores> fornecedores);
    void VenderEquipamentos(priority_queue<Fornecedores> fornecedores);
    bool operator< (const Fornecedores& f) const;
    friend ostream& operator<<(ostream& out, const Fornecedores& f);
};