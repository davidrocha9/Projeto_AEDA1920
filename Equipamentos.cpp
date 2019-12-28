#include "Utils.h"
#include "Equipamentos.h"
#include "fstream"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

////////////////////
/// Equipamentos ///
////////////////////

Equipamentos::Equipamentos() {
    tipo = "";
    preco = 0;
}

Equipamentos::Equipamentos(string t, double p) {
    tipo = t;
    preco = p;
}

string Equipamentos::getTipo() {
    return tipo;
}

double Equipamentos::getPreco() {
    return preco;
}

void Equipamentos::setTipo(string t) {
    tipo = t;
}

void Equipamentos::setPreco(double p) {
    preco = p;
}



////////////////////
/// Fornecedores ///
////////////////////

Fornecedores::Fornecedores() {
    nome = "";
    reputacao = 0;
}

Fornecedores::Fornecedores(string n, double r, vector<Equipamentos> eq) {
    nome = n;
    reputacao = r;
    equipamentos = eq;
}

string Fornecedores::getNome() const {
    return nome;
}

double Fornecedores::getReputacao() const {
    return reputacao;
}

vector<Equipamentos> Fornecedores::getEquipamentos() const {
    return equipamentos;
}

void Fornecedores::setNome(string n) {
    nome = n;
}

void Fornecedores::setReputacao(double r) {
    reputacao = r;
}

void Fornecedores::setEquipamentos(vector<Equipamentos> eq) {
    equipamentos = eq;
}

priority_queue<Fornecedores> Fornecedores::ReadFornecedores() {
    priority_queue<Fornecedores> f;
    ifstream fornecedoresfile;
    fornecedoresfile.open("../fornecedores.txt");

    if (fornecedoresfile.fail()) {									// checking if nothing went wrong
        cerr << "Error Opening File. Try again!" << endl;		// while opening the file
    }
    else {
        vector<Equipamentos> eq;
        vector<string> temp, temp1;
        string line;
        Equipamentos e;
        while (!fornecedoresfile.eof()) {		// going through the file
            std::getline(fornecedoresfile, line);
            nome = line;
            std::getline(fornecedoresfile, line);
            reputacao = stod(line);
            std::getline(fornecedoresfile, line);
            temp = divideStrings(line);
            std::getline(fornecedoresfile, line);
            temp1 = divideStrings(line);
            eq.clear();
            for (size_t x = 0; x < temp.size(); x++){
                e.setTipo(temp.at(x));
                e.setPreco(stod(temp1.at(x)));
                eq.push_back(e);
            }
            Fornecedores f1(nome, reputacao, eq);
            f.push(f1);
            std::getline(fornecedoresfile, line);
        }
    }
    fornecedoresfile.close();
    return f;
}

void Fornecedores::InfoFornecedores(priority_queue<Fornecedores> fornecedores) {
    priority_queue<Fornecedores> aux = fornecedores;
    unsigned int x = 1;
    while(!aux.empty()){
        if (x % 3 == 0)
            std::cout << endl << " ";
        std::cout << "[" << x << "]" << setfill(' ') << setw(18) << aux.top().getNome() << "   ";
        x++;
        aux.pop();
    }
    cout << endl << endl << " A que fornecedor pretende aceder?" << endl;
    unsigned int opt;
    do {
        cout << endl << " Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > fornecedores.size()) {
            cin.clear();
            cin.ignore();
            cout << " Input invalido! Introduza um numero entre 1 e " << fornecedores.size();
        }
    } while (opt < 1 || opt > fornecedores.size());
    std::system("cls"); logo();
    aux = fornecedores; x = 1;
    while(!aux.empty()){
        if (opt == x)
            cout << aux.top();
        aux.pop();
        x++;
    }
}

void Fornecedores::VenderEquipamentos(priority_queue<Fornecedores> fornecedores) {
    priority_queue<Fornecedores> aux = fornecedores;
    cout << " Que tipo de equipamento pretende adquirir?" << endl << endl;
    vector<string> equipamentospossiveis = {"Camisolas", "Calcoes", "Meias", "Chuteiras", "Caneleiras", "Camisolas Termicas", "Fato de treino", "Sapatilhas"};
    std::cout << " Lista de jogadores disponiveis:" << endl << endl;
    int y = 0;
    std::cout << " ";
    for (size_t x = 0; x < equipamentospossiveis.size(); x++) {
        if (y == 3) {
            std::cout << endl << " ";
            y++;
            y = 0;
        }
        std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(26) << equipamentospossiveis.at(x) << "   ";
        y++;
    }

    cout << endl << endl << " Que tipo equipamento pretende comprar?" << endl;
}


//Operadores
bool Fornecedores::operator<(const Fornecedores &f) const {
    return reputacao < f.reputacao;
}

ostream &operator<<(ostream &out, const Fornecedores &f) {
    out << " Nome: " << f.getNome() << endl;
    out << " Reputacao: " << f.getReputacao() << "/5 estrelas" << endl;
    out << " Artigos Disponiveis: ";
    int y = 0;
    for (auto x : f.getEquipamentos()){
        switch(y){
            case 0:
                out << x.getTipo() << " (" << x.getPreco() << " euros)" << endl;
                y++;
                break;
            default:
                out << setfill(' ') << setw(22) << " " << x.getTipo() << " (" << x.getPreco() << " euros)" << endl;
                break;
        }
    }
    return out;
}
