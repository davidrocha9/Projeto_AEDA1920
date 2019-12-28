#include <fstream>
#include <string>
#include <cctype>
#include <ostream>
#include <iomanip>
#include <algorithm>

#include "Jogadores.h"
#include "Selecao.h"
#include "Utils.h"

using namespace std;

////////////////////
// Membro Selecao //
////////////////////

//Construtores e Destrutores
MembroSelecao::MembroSelecao(string n, string dn) : nome(n), datanascimento(Date(dn)){}

MembroSelecao::MembroSelecao(){}

//Metodos Get
string MembroSelecao::getNome() const{
	return nome;
}

Date MembroSelecao::getDataNascimento() const{
	return datanascimento;
}

//Metodos Set
void MembroSelecao::setNome(string n){
	nome = n;
}

void MembroSelecao::setDataNascimento(string dn){
	datanascimento = dn;
}

void MembroSelecao::Info() const{
}



////////////////////
/// Futebolista ////
////////////////////

Futebolista::Futebolista(){
	altura = 0;
	peso = 0;
	valorpasse = 0;
}

Futebolista::Futebolista(string n, string dn, string p, string c, unsigned int pe, unsigned int a, unsigned int vp) :MembroSelecao(n, dn), posicao(p), clube(c), peso(pe), altura(a), valorpasse(vp) {}

bool Futebolista::operator<(const Futebolista& f) const{
	if (nome < f.getNome())
		return false;
	return true;
}

bool Futebolista::operator==(const Futebolista& f) const{
	return (f.getNome() == nome && f.getDataNascimento() == datanascimento);
}

//Metodos Get
string Futebolista::getPosicao() const{
	return posicao;
}

string Futebolista::getClube() const{
	return clube;
}

unsigned int Futebolista::getPeso() const{
	return peso;
}

unsigned int Futebolista::getAltura() const{
	return altura;
}

unsigned int Futebolista::getValorPasse() const{
	return valorpasse;
}

//Metodos Set
void Futebolista::setPosicao(string p){
	posicao = p;
}

void Futebolista::setClube(string c){
	clube = c;
}

void Futebolista::setPeso(unsigned int p){
	peso = p;
}

void Futebolista::setAltura(unsigned int a){
	altura = a;
}

void Futebolista::setValorPasse(unsigned int vp){
	valorpasse = vp;
}

//Outros Metodos
vector<Futebolista> Futebolista::ReadJogadores() {
	vector<Futebolista> fv;
	ifstream jogadoresfile;
	jogadoresfile.open("../jogadores.txt");

	string dn;
	if (jogadoresfile.fail()) {									// checking if nothing went wrong
		cerr << "Error Opening File. Try again!" << endl;		// while opening the file
	}
	else {
		vector<Futebolista> jogadores;
		string line;
		vector<string> info;
		while (!jogadoresfile.eof()) {		// going through the file
			std::getline(jogadoresfile, line);
			info = divideStrings(line);
			int index = 0;
			for (size_t x = 0; x < info.size(); x++) {
				switch (index) {
				case 0:
					nome = info.at(x);
					break;
				case 1:
					dn = info.at(x);
					break;
				case 2:
					posicao = info.at(x);
					break;
				case 3:
					clube = info.at(x);
					break;
				case 4:
					peso = stoi(info.at(x));
					break;
				case 5:
					altura = stoi(info.at(x));
					break;
				case 6:
					valorpasse = stoi(info.at(x));
					break;
				default:
					break;
				}
				index++;
			}
			Futebolista f(nome, dn, posicao, clube, peso, altura, valorpasse);
			fv.push_back(f);
		}
	}
	jogadoresfile.close();
	return fv;
}

void Futebolista::AdicionarJogador(vector<Futebolista> &jogadores) const {
    string n, p, c, dn;
    int pe, a, vp;
    string input, nome1, nome2;
    std::cin.ignore();

    cout << " Nome: "; getline(cin, n);

    do {
        cout << " Data de Nascimento (DD/MM/AAAA): ";
        cin.clear();
        std::getline(std::cin, dn);
        if (dn.length() != 10) {
            cin.clear();
            cout << " Data Invalida! Tente novamente." << endl;
        }
    } while (dn.length() != 10);

    nome1 = n;
    transform(nome1.begin(), nome1.end(), nome1.begin(), ::tolower);
    vector<string> vnomes = nameSplitter(nome1);

    for (size_t x = 0; x < jogadores.size(); x++) {
        for (size_t i = 0; i < jogadores.at(x).getNome().size(); i++) {
            nome2 += jogadores.at(x).getNome().at(i);
        }
        transform(nome2.begin(), nome2.end(), nome2.begin(), ::tolower);
        bool pass = true;
        for (size_t x = 0; x < vnomes.size(); x++) {
            if (nome2.find(vnomes.at(x)) == string::npos)
                pass = false;
        }

        if (pass == true && jogadores.at(x).getDataNascimento() == dn) {
            throw JogadorJaExistente(n, dn);
        }
        else
            nome2 = "";
    }
    std::cout << " Posicao: "; std::getline(std::cin, p);
    std::cout << " Clube: "; std::getline(std::cin, c);
    std::cout << " Peso (kgs): "; std::cin >> pe;
    std::cout << " Altura (cm): "; std::cin >> a;
    std::cout << " Valor do Passe (euros): "; std::cin >> vp;
    std::cout << endl;
    Futebolista newf(n, dn, p, c, pe, a, vp);
    jogadores.push_back(newf);
}

void Futebolista::RemoverJogador(vector<Futebolista> &jogadores) const{
    unsigned int opt;
    int i = 1;
    std::cin.ignore();
    vector<string> nomes;
    string name;

    cout << " Lista de jogadores disponiveis:" << endl << endl;
    int aux = 0;
    std::cout << " ";
    for (size_t x = 0; x < jogadores.size(); x++) {
        name = jogadores.at(x).getNome();
        nomes = nameSplitter(name);
        if (nomes.size() == 1)
            std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << jogadores.at(x).getNome() << "   ";
        else {
            name = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
            std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << name << "   ";
        }
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    cout << endl << endl << "Que jogador pretende remover?" << endl;

    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > jogadores.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e " << jogadores.size();
        }
    } while (opt < 1 || opt > jogadores.size());

    jogadores.erase(jogadores.begin() + opt - 1);
    cout << endl << "Jogador removido com sucesso!" << endl;
}

void Futebolista::InformacoesJogador(vector<Futebolista> &jogadores) const{
    unsigned int opt;
    int i = 1;
    string name;
    std::cin.ignore();
    vector<string> nomes;

    cout << " Lista de jogadores disponiveis:" << endl << endl;
    int aux = 0;
    std::cout << " ";
    for (size_t x = 0; x < jogadores.size(); x++) {
        name = jogadores.at(x).getNome();
        nomes = nameSplitter(name);
        if (nomes.size() == 1)
            std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << jogadores.at(x).getNome() << "   ";
        else {
            name = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
            std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << name << "   ";
        }
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    cout << endl << endl << " A que jogador pretende aceder?" << endl;

    do {
        cout << endl << " Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > jogadores.size()) {
            cin.clear();
            cin.ignore();
            cout << " Input invalido! Introduza um numero entre 1 e " << jogadores.size();
        }
    } while (opt < 1 || opt > jogadores.size());
    std::system("cls"); logo();
    cout << jogadores.at(opt - 1);
}

void Futebolista::EditarJogador(vector<Futebolista>& jogadores) const {
    unsigned int opt, index;
    string line;
    std::cin.ignore();
    string name;
    vector<string> nomes;

    std::cout << " Lista de jogadores disponiveis:" << endl << endl;
    int aux = 0;
    std::cout << " ";
    for (size_t x = 0; x < jogadores.size(); x++) {
        name = jogadores.at(x).getNome();
        nomes = nameSplitter(name);
        if (nomes.size() == 1)
            std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << jogadores.at(x).getNome() << "   ";
        else {
            name = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
            std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << name << "   ";
        }
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }

    cout << endl << endl << " Que jogador pretende editar?" << endl;
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > jogadores.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e " << jogadores.size();
        }
    } while (opt < 1 || opt > jogadores.size());

    index = opt - 1;
    system("cls"); logo();
    std::cout << " O que pretende alterar?" << endl;
    std::cout << " 1 - Nome" << endl;
    std::cout << " 2 - Data de Nascimento" << endl;
    std::cout << " 3 - Posicao" << endl;
    std::cout << " 4 - Clube" << endl;
    std::cout << " 5 - Peso (kgs)" << endl;
    std::cout << " 6 - Altura (cm)" << endl;
    std::cout << " 7 - Valor do Passe (euros)" << endl << endl;
    do {
        cout << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > 7) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e 7" << endl;
        }
    } while (opt < 1 || opt > jogadores.size());

    std::cin.ignore();

    system("cls"); logo();
    switch (opt) {
        case(1): std::cout << " Novo nome: "; std::getline(cin, line);
            jogadores.at(index).setNome(line);
            break;
        case(2):
            do {
                cout << " Nova data de Nascimento (DD/MM/AAAA): ";
                cin.clear();
                std::getline(std::cin, line);
                if (line.length() != 10) {
                    cin.clear();
                    cout << " Data Invalida! Tente novamente." << endl;
                }
            } while (line.length() != 10);
            jogadores.at(index).setDataNascimento(line);
            break;
        case(3): std::cout << " Nova posicao: "; getline(cin, line);
            jogadores.at(index).setPosicao(line);
            break;
        case(4): std::cout << " Novo clube: "; getline(cin, line);
            jogadores.at(index).setClube(line);
            break;
        case(5): std::cout << " Novo peso: "; getline(cin, line);
            jogadores.at(index).setPeso(stoi(line));
            break;
        case(6): std::cout << " Nova altura: "; getline(cin, line);
            jogadores.at(index).setAltura(stoi(line));
            break;
        case(7): std::cout << " Novo Valor de Passe: "; getline(cin, line);
            jogadores.at(index).setValorPasse(stoi(line));
            break;
    }
}


////////////////////////
//// Equipa Tecnica ////
////////////////////////

//Construtores
EquipaTecnica::EquipaTecnica(string n, string dn, string f, unsigned int s): MembroSelecao(n, dn), funcao(f), salario(s) {}

//Metodos Get
string EquipaTecnica::getFuncao() const {
	return funcao;
}

unsigned int EquipaTecnica::getSalario() const {
	return salario;
}

//Metodos Set
void EquipaTecnica::setFuncao(string f) {
	funcao = f;
}

void EquipaTecnica::setSalario(unsigned int s) {
	salario = s;
}

//Outros metodos
vector<EquipaTecnica> EquipaTecnica::ReadEquipaTecnica(){
	vector<EquipaTecnica> et;
	ifstream etfile;
	etfile.open("../equipatecnica.txt");

	string dn;
	if (etfile.fail()) {									// checking if nothing went wrong
		cout << "Error Opening File. Try again!" << endl;		// while opening the file
	}
	else {
		string line;
		vector<string> info;
		while (!etfile.eof()) {		// going through the file
			std::getline(etfile, line);
			info = divideStrings(line);
			for (size_t x = 0; x < info.size(); x++) {
				switch (x) {
				case 0:
					nome = info.at(x);
					break;
				case 1:
					dn = info.at(x);
					break;
				case 2:
					funcao = info.at(x);
					break;
				case 3:
					salario = stoi(info.at(x));
					break;
				default:
					break;
				}
			}
			EquipaTecnica et1(nome, dn, funcao, salario);
			et.push_back(et1);
		}
	}
	etfile.close();
	return et;
}

void EquipaTecnica::AdicionarTecnico(vector<EquipaTecnica>& equipatecnica) const{
    string n, nome1, nome2, dn, input, f;
    unsigned int s, opt;
    std::cin.ignore();
    std::cout << " Nome: "; std::getline(cin, n);

    nome1 = n;
    transform(nome1.begin(), nome1.end(), nome1.begin(), ::tolower);
    vector<string> vnomes = nameSplitter(nome1);
    do {
        cout << " Data de Nascimento (DD/MM/AAAA): ";
        cin.clear();
        std::getline(std::cin, dn);
        if (dn.length() != 10) {
            cin.clear();
            cout << " Data Invalida! Tente novamente." << endl;
        }
    } while (dn.length() != 10);

    for (size_t x = 0; x < equipatecnica.size(); x++) {
        nome2 = equipatecnica.at(x).getNome();
        transform(nome2.begin(), nome2.end(), nome2.begin(), ::tolower);
        bool pass = true;
        for (size_t x = 0; x < vnomes.size(); x++) {
            if (nome2.find(vnomes.at(x)) == string::npos)
                pass = false;
        }

        if (pass == true && equipatecnica.at(x).getDataNascimento() == dn) {
            throw MembroTecnicoJaExistente(n, dn);
        }
        else
            nome2 = "";
    }
    system("cls"); logo();
    std::cout << " Funcoes disponiveis: " << endl << endl;
    std::cout << "   1 - Selecionador Nacional" << endl;
    std::cout << "   2 - Diretor" << endl;
    std::cout << "   3 - Treinador Nacional" << endl;
    std::cout << "   4 - Treinador Nacional de Guarda-Redes" << endl;
    std::cout << "   5 - Preparador Fisico" << endl;
    std::cout << "   6 - Medico Principal" << endl;
    std::cout << "   7 - Departamento Medico" << endl;
    std::cout << "   8 - Funcionario Tecnico" << endl << endl;
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > equipatecnica.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e 8";
        }
    } while (opt < 1 || opt > equipatecnica.size());

    switch (opt) {
        case 1:
            f = "Selecionador Nacional";
            break;
        case 2:
            f = "Diretor";
            break;
        case 3:
            f = "Treinador Nacional";
            break;
        case 4:
            f = "Treinador Nacional de Guarda-Redes";
            break;
        case 5:
            f = "Preparador Fisico";
            break;
        case 6:
            f = "Medico Principal";
            break;
        case 7:
            f = "Departamento Medico";
            break;
        case 8:
            f = "Funcionario Tecnico";
            break;
        default:
            break;
    }
    std::cout << "Salario: "; cin >> s;
    std::cout << endl;
    EquipaTecnica newet(n, dn, f, s);
    equipatecnica.push_back(newet);
}

void EquipaTecnica::RemoverTecnico(vector<EquipaTecnica>& equipatecnica) const{
    string line;
    unsigned int opt;
    cin.ignore();
    cout << " Lista de membros tecnicos disponiveis: " << endl << endl;
    int aux = 0;
    cout << " ";
    for (size_t x = 0; x < equipatecnica.size(); x++) {
        cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << equipatecnica.at(x).getNome() << "   ";
        if (aux == 2) {
            aux = -1;
            cout << endl << " ";
        }
        aux++;
    }
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > equipatecnica.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e " << equipatecnica.size();
        }
    } while (opt < 1 || opt > equipatecnica.size());

    equipatecnica.erase(equipatecnica.begin() + (opt - 1));
    std::cout << endl << "Membro tecnico removido com sucesso!" << endl << endl;
}

void EquipaTecnica::InformacoesTecnico(vector<EquipaTecnica>& equipatecnica) const {
    string line;
    unsigned int opt;
    int i = 1;
    std::cin.ignore();
    std::cin.clear();
    cout << " Lista de membros tecnicos disponiveis: " << endl << endl;
    int aux = 0;

    for (size_t x = 0; x < equipatecnica.size(); x++) {
        cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << equipatecnica.at(x).getNome() << "   ";
        if (aux == 2) {
            aux = -1;
            cout << endl;
        }
        aux++;
    }
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > equipatecnica.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e " << equipatecnica.size();
        }
    } while (opt < 1 || opt > equipatecnica.size());
    system("cls"); logo();
    cout << equipatecnica.at(opt - 1) << endl;
}

void EquipaTecnica::EditarTecnico(vector<EquipaTecnica>& equipatecnica) const{
    unsigned int opt, index;
    string line;
    std::cin.ignore();

    int aux = 0;
    cout << " Lista de membros tecnicos disponiveis:" << endl << endl << " ";
    for (size_t x = 0; x < equipatecnica.size(); x++) {
        std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << equipatecnica.at(x).getNome() << "   ";
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    cout << endl;
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > equipatecnica.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e " << equipatecnica.size();
        }
    } while (opt < 1 || opt > equipatecnica.size());

    index = opt - 1;

    system("cls"); logo();
    std::cout << " O que pretende alterar?" << endl << endl;
    std::cout << "   1 - Nome" << endl;
    std::cout << "   2 - Data de Nascimento" << endl;
    std::cout << "   3 - Funcao" << endl;
    std::cout << "   4 - Salario" << endl << endl;
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > 4) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e 4";
        }
    } while (opt < 1 || opt > equipatecnica.size());

    system("cls"); logo();
    std::cin.ignore();
    std::cin.clear();
    switch (opt) {
        case(1): std::cout << " Novo nome: "; getline(std::cin, line);
            equipatecnica.at(index).setNome(line);
            break;
        case(2):
            do {
                cout << " Nova data de Nascimento (DD/MM/AAAA): ";
                cin.clear();
                std::getline(std::cin, line);
                if (line.length() != 10) {
                    cin.clear();
                    cout << " Data Invalida! Tente novamente." << endl;
                }
            } while (line.length() != 10);
            equipatecnica.at(index).setDataNascimento(line);
            break;
        case(3):
            system("cls"); logo();
            std::cout << " Funcoes disponiveis: " << endl << endl;
            std::cout << "   1 - Selecionador Nacional" << endl;
            std::cout << "   2 - Diretor" << endl;
            std::cout << "   3 - Treinador Nacional" << endl;
            std::cout << "   4 - Treinador Nacional de Guarda-Redes" << endl;
            std::cout << "   5 - Preparador Fisico" << endl;
            std::cout << "   6 - Medico Principal" << endl;
            std::cout << "   7 - Departamento Medico" << endl;
            std::cout << "   8 - Funcionario Tecnico" << endl << endl;
            do {
                cout << endl << "Introduza uma opcao: ";
                cin.clear();
                std::cin >> opt;
                if (opt < 1 || opt > equipatecnica.size()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Input invalido! Introduza um numero entre 1 e 8";
                }
            } while (opt < 1 || opt > equipatecnica.size());
            switch (opt) {
                case 1:
                    equipatecnica.at(index).setFuncao("Selecionador Nacional");
                    break;
                case 2:
                    equipatecnica.at(index).setFuncao("Diretor");
                    break;
                case 3:
                    equipatecnica.at(index).setFuncao("Treinador Nacional");
                    break;
                case 4:
                    equipatecnica.at(index).setFuncao("Treinador Nacional de Guarda-Redes");
                    break;
                case 5:
                    equipatecnica.at(index).setFuncao("Preparador Fisico");
                    break;
                case 6:
                    equipatecnica.at(index).setFuncao("Medico Principal");
                    break;
                case 7:
                    equipatecnica.at(index).setFuncao("Departamento Medico");
                    break;
                case 8:
                    equipatecnica.at(index).setFuncao("Funcionario Tecnico");
                    break;
            }
            break;
        case(4): std::cout << " Novo salario: "; getline(std::cin, line);
            equipatecnica.at(index).setSalario(stoi(line));
            break;
    }
}

//Ostreams
ostream& operator<<(ostream& out, const Futebolista& f){
    out << " Nome completo: " << f.getNome() << endl;
    out << " Data de Nascimento: " << f.getDataNascimento() << endl;
    out << " Posicao: " << f.getPosicao() << endl;
    out << " Clube: " << f.getClube() << endl;
    out << " Peso: " << f.getPeso() << " kgs" << endl;
    out << " Altura: " << f.getAltura() << " cm" << endl;
    if (f.getValorPasse() / 1000000.00 > 1)
        out << " Valor do Passe: " << f.getValorPasse() / 1000000.00 << " milhoes de euros";
    else if (f.getValorPasse() / 1000000.00 == 1)
        out << " Valor do Passe: " << f.getValorPasse() / 1000000.00 << " milhao de euros";
    else
        out << " Valor do Passe: " << f.getValorPasse() / 1000.00 << " mil euros";
    out << endl;
    return out;
}

ostream& operator<<(ostream& out, const EquipaTecnica& et) {
    out << " Nome completo: " << et.getNome() << endl;
    out << " Data de Nascimento: " << et.getDataNascimento() << endl;
    out << " Funcao: " << et.getFuncao() << endl;
    out << " Salario: " << et.getSalario() << " euros";
    return out;
}

////////////////////////
//// Selecionadores ////
////////////////////////

Selecionadores::Selecionadores() {
}

Selecionadores::Selecionadores(string n, unsigned int tg, vector<unsigned int> sel){
    nome = n;
    titulosganhos = tg;
    selecoes = sel;
}

unsigned int Selecionadores::getTitulosGanhos() const{
    return titulosganhos;
}

vector<unsigned int> Selecionadores::getSelecoes() const {
    return selecoes;
}

void Selecionadores::setTitulosGanhos(unsigned int t) {
    titulosganhos = t;
}

void Selecionadores::setSelecoes(vector<unsigned int> sel) {
    selecoes = sel;
}

bool Selecionadores::operator<(const Selecionadores &s) const {
    if(titulosganhos == s.titulosganhos)
        return nome < s.nome;
    return titulosganhos > s.titulosganhos;
}

BST<Selecionadores> Selecionadores::ReadSelecionadores(BST<Selecionadores> &selecionadores) {
    BST<Selecionadores> sel(Selecionadores("",0));
    selecionadores = sel;
    ifstream selfile;
    selfile.open("../selecionadores.txt");

    if (selfile.fail()) {									// checking if nothing went wrong
        cout << "Error Opening File. Try again!" << endl;		// while opening the file
    }
    else {
        string line;
        vector<string> info;
        while (!selfile.eof()) {		// going through the file
            std::getline(selfile, line);
            info = divideStrings(line);
            for (size_t x = 0; x < info.size(); x++) {
                switch (x) {
                    case 0:
                        nome = info.at(x);
                        break;
                    case 1:
                        titulosganhos = stoi(info.at(x));
                        break;
                    default:
                        break;
                }
            }
            std::getline(selfile, line);
            info = divideStrings(line);
            selecoes.clear();
            for (auto x: info)
                selecoes.push_back(stoi(x));
            Selecionadores s(nome, titulosganhos, selecoes);
            selecionadores.insert(s);
        }
    }
    selfile.close();
    return selecionadores;
}

Selecionadores::Selecionadores(string n, unsigned int tg) {
    nome = n;
    titulosganhos = tg;
};
