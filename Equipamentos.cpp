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

Fornecedores::Fornecedores(string n, double r, unsigned int re, vector<Equipamentos> eq) {
    nome = n;
    reputacao = r;
    reviews = re;
    equipamentos = eq;
}

string Fornecedores::getNome() const {
    return nome;
}

double Fornecedores::getReputacao() const {
    return reputacao;
}

unsigned int Fornecedores::getReviews() const{
    return reviews;
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

void Fornecedores::setReviews(unsigned int r){
    reviews = r;
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
            reviews = stoi(line);
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
            Fornecedores f1(nome, reputacao, reviews, eq);
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

void Fornecedores::VenderEquipamentos(priority_queue<Fornecedores> &fornecedores) {
    priority_queue<Fornecedores> aux = fornecedores;
    cout << " Que tipo de equipamento pretende adquirir?" << endl << endl;
    vector<string> equipamentospossiveis = {"Camisolas", "Calcoes", "Meias", "Chuteiras", "Caneleiras", "Camisolas Termicas", "Fato de treino", "Sapatilhas"};
    std::cout << " Lista de equipamentos disponiveis:" << endl << endl;
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
    unsigned int opt;
    do {
        cout << endl << " Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > equipamentospossiveis.size()) {
            cin.clear();
            cin.ignore();
            cout << " Input invalido! Introduza um numero entre 1 e " << equipamentospossiveis.size();
        }
    } while (opt < 1 || opt > equipamentospossiveis.size());
    string pedido = equipamentospossiveis.at(opt-1);

    Fornecedores f;
    bool found;
    while(!aux.empty()){
        found = false;
        vector<Equipamentos> temp = aux.top().getEquipamentos();
        for (auto x: temp){
            if (x.getTipo() == pedido){
                f = aux.top();
                found = true;
                break;
            }
        }
        if (found)
            break;
        aux.pop();
    }
    std::system("cls"); logo();
    if(found){
        cout << " Fornecedor encontrado!" << endl << endl;
        cout << f;
        cout << endl << " Pretende realizar a compra? (S/N)" << endl;
        string n;
        do {
            std::cout << " Introduza uma opcao: ";
            cin.clear();
            cin >> n;
            if (n != "S" && n != "s" && n != "N" && n != "n" || cin.fail()){
                cin.clear();
                cin.ignore();
                std::cout << " Opcao invalida! Tente Novamente." << endl;
            }
        } while (n != "S" && n != "s" && n != "N" && n != "n");
        if (n == "n" || n == "N")
            return;
        else{
            std::system("cls"); logo();
            cout << " Compra realizada!" << endl << endl << " Pretende emitir uma opiniao sobre a transacao efetuada?" << endl;
            do {
                std::cout << " Introduza uma opcao (S/N): ";
                cin.clear();
                cin >> n;
                if (n != "S" && n != "s" && n != "N" && n != "n" || cin.fail()){
                    cin.clear();
                    cin.ignore();
                    std::cout << " Opcao invalida! Tente Novamente." << endl;
                }
            } while (n != "S" && n != "s" && n != "N" && n != "n");
            if (n == "n" || n == "N")
                return;
            else{
                std::system("cls"); logo();
                cout << " Como classificaria esta compra de 0 a 5 estrelas?" << endl;
                double rating;
                do {
                    cout << endl << " Introduza uma opcao: ";
                    cin.clear();
                    std::cin >> rating;
                    if (rating < 0.0 || rating > 5.0) {
                        cin.clear();
                        cin.ignore();
                        cout << " Input invalido! Introduza um numero entre 0.0 e 5.0";
                    }
                } while (rating < 0.0 || rating> 5.0);
                double newr = f.getReputacao()*f.getReviews() + rating;
                unsigned int newre = f.getReviews() + 1;
                newr = newr/newre;
                vector<Fornecedores> temp;
                while(!fornecedores.empty()){
                    temp.push_back(fornecedores.top());
                    fornecedores.pop();
                }
                for (auto x: temp){
                    if (x == f){
                        x.setReputacao(newr);
                        x.setReviews(newre);
                    }
                    fornecedores.push(x);
                }
            }
        }
    }
}


//Operadores
bool Fornecedores::operator<(const Fornecedores &f) const {
    return reputacao < f.reputacao;
}

ostream &operator<<(ostream &out, const Fornecedores &f) {
    out << " Nome: " << f.getNome() << endl;
    out << " Reputacao: " << f.getReputacao() << "/5 estrelas" << endl;
    out << " Numero de reviews: " << f.getReviews() << endl;
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

bool Fornecedores::operator== (const Fornecedores& f) const{
    return nome == f.nome;
}