#include <fstream>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
#include <ostream>

#include "Convocatoria.h"
#include "Utils.h"
#include "Jogadores.h"

using namespace std;

//Construtores
Jogo::Jogo() {}

Jogo::Jogo(Date data, string pais, string adversario, string cidade, string estadio, vector<Futebolista> jogadores_conv, vector<Futebolista> jogadores_part, vector<string> equipa_arbitragem, vector<string> equipa_adversaria, multimap<Futebolista, unsigned int> golos, multimap<Futebolista, unsigned int> assists, multimap<Futebolista, unsigned int> passes, multimap<Futebolista, unsigned int> passes_acertados, multimap<Futebolista, unsigned int> desarmes, multimap<Futebolista, unsigned int> faltas, multimap<Futebolista, double> km_percorridos, multimap<Futebolista, unsigned int> minutos_jogados, multimap<Futebolista, unsigned int> amarelos, multimap<Futebolista, unsigned int> vermelhos, vector<Futebolista> lesao) : data(data), pais(pais), adversario(adversario), cidade(cidade), estadio(estadio), jogadores_convocados(jogadores_conv), jogadores_participantes(jogadores_part), equipa_arbitragem(equipa_arbitragem), equipa_adversaria(equipa_adversaria), golos(golos), assists(assists), passes(passes), passes_acertados(passes_acertados), desarmes(desarmes), faltas(faltas), km_percorridos(km_percorridos), minutos_jogados(minutos_jogados), amarelos(amarelos), vermelhos(vermelhos), lesao(lesao) {}

//Metodos GET
Date Jogo::getData() const {
	return data;
}

string Jogo::getPais() const {
	return pais;
}

string Jogo::getAdversario() const {
	return adversario;
}

string Jogo::getCidade() const {
	return cidade;
}

string Jogo::getEstadio() const {
	return estadio;
}

vector<Futebolista> Jogo::getJogadoresConvocados() const {
	return jogadores_convocados;
}

vector<Futebolista> Jogo::getJogadoresParticipantes() const {
	return jogadores_participantes;
}

vector<Futebolista> Jogo::getLesao() const {
	return lesao;
}

vector<string> Jogo::getEquipaArbitragem() const {
	return equipa_arbitragem;
}

vector<string> Jogo::getEquipaAdversaria() const {
	return equipa_adversaria;
}

multimap<Futebolista, unsigned int> Jogo::getGolos() const {
	return golos;
}

multimap<Futebolista, unsigned int> Jogo::getAssists() const {
	return assists;
}

multimap<Futebolista, unsigned int> Jogo::getPasses() const {
	return passes;
}

multimap<Futebolista, unsigned int> Jogo::getPassesAcertados() const {
	return passes_acertados;
}

multimap<Futebolista, unsigned int> Jogo::getDesarmes() const {
	return desarmes;
}

multimap<Futebolista, unsigned int> Jogo::getFaltas() const {
	return faltas;
}

multimap<Futebolista, double> Jogo::getKmPercorridos() const {
	return km_percorridos;
}

multimap<Futebolista, unsigned int> Jogo::getMinutosJogados() const {
	return minutos_jogados;
}

multimap<Futebolista, unsigned int> Jogo::getAmarelos() const {
	return amarelos;
}

multimap<Futebolista, unsigned int> Jogo::getVermelhos() const {
	return vermelhos;
}


//Metodos SET
void Jogo::setData(Date data) {
	this->data = data;
}

void Jogo::setPais(string pais) {
	this->pais = pais;
}

void Jogo::setAdversario(string adversario) {
	this->adversario = adversario;
}

void Jogo::setCidade(string cidade) {
	this->cidade = cidade;
}

void Jogo::setEstadio(string estadio) {
	this->estadio = estadio;
}

void Jogo::setJogadoresConvocados(vector<Futebolista> jogadores_convocados) {
	this->jogadores_convocados = jogadores_convocados;
}

void Jogo::setJogadoresParticipantes(vector<Futebolista> jogadores_participantes) {
	this->jogadores_participantes = jogadores_participantes;
}

void Jogo::setLesao(vector<Futebolista> lesao) {
	this->lesao = lesao;
}

void Jogo::setEquipaArbitragem(vector<string> equipa_arbitragem) {
	this->equipa_arbitragem = equipa_arbitragem;
}

void Jogo::setEquipaAdversaria(vector<string> equipa_adversaria) {
	this->equipa_adversaria = equipa_adversaria;
}

void Jogo::setGolos(multimap<Futebolista, unsigned int> golos) {
	this->golos = golos;
}

void Jogo::setAssists(multimap<Futebolista, unsigned int> assists) {
	this->assists = assists;
}

void Jogo::setPasses(multimap<Futebolista, unsigned int> passes) {
	this->passes = passes;
}

void Jogo::setPassesAcertados(multimap<Futebolista, unsigned int> passes_acertados) {
	this->passes_acertados = passes_acertados;
}

void Jogo::setDesarmes(multimap<Futebolista, unsigned int> desarmes) {
	this->desarmes = desarmes;
}

void Jogo::setFaltas(multimap<Futebolista, unsigned int> faltas) {
	this->faltas = faltas;
}

void Jogo::setKmPercorridos(multimap<Futebolista, double> km_percorridos) {
	this->km_percorridos = km_percorridos;
}

void Jogo::setMinutosJogados(multimap<Futebolista, unsigned int> minutos_jogados) {
	this->minutos_jogados = minutos_jogados;
}

void Jogo::setAmarelos(multimap<Futebolista, unsigned int> amarelos) {
	this->amarelos = amarelos;
}

void Jogo::setVermelhos(multimap<Futebolista, unsigned int> vermelhos) {
	this->vermelhos = vermelhos;
}

bool Jogo::operator==(Jogo& jogo) const{
	return (jogo.getAdversario() == adversario && jogo.getData() == data);
}

bool Jogo::operator!=(Jogo& jogo) const {
	return (jogo.getAdversario() != adversario && jogo.getData() != data);
}


//Outros Metodos
vector<Jogo> Jogo::ReadJogo() {
	vector<Jogo> jogos;
	ifstream jogofile;
	jogofile.open("../Jogo.txt");

	if (jogofile.fail()) {
		cerr << "Error Opening File.Try again!" << endl;
	}
	else {
		vector<string> info;
		vector<string> v1, v2;
		Futebolista f1;
		vector<Futebolista> jognaconv, jogpart, lesionados;
		multimap<Futebolista, unsigned int> gols, assists, pass, passcerto, disharms, fouls, min, yellows, reds;
		multimap<Futebolista, double> kms;
		multimap<Futebolista, string> datascheg;
		multimap<Futebolista, string> dataspart;
		int index = 0;
		string line;
		
		while (!jogofile.eof()) {
			std::getline(jogofile, line);
			switch(index){
			case 0:
				info = divideStrings(line);
				for (size_t x = 0; x < info.size(); x++) {
					switch (x) {
					case 0:
						data = Date(info.at(x));
						break;
					case 1:
						adversario = info.at(x);
						break;
					case 2:
						pais = info.at(x);
						break;
					case 3:
						cidade = info.at(x);
						break;
					case 4:
						estadio = info.at(x);
						break;
					}
				}
				break;
			case 1:
				v1 = divideStrings(line);
				break;
			case 2:
				v2 = divideStrings(line);
				for (size_t i = 0; i < v1.size(); i++) {
					for (Futebolista x : f1.ReadJogadores()) {
						if (v1.at(i) == x.getNome() && Date(v2.at(i)) == x.getDataNascimento()) {
							jognaconv.push_back(x);
							break;
						}
					}
				}
				break;
			case 3:
				v1.clear();
				v1 = divideStrings(line);
				break;
			case 4:
				v2.clear();
				v2 = divideStrings(line);
				for (size_t i = 0; i < v1.size(); i++) {
					for (Futebolista x : jognaconv) {
						if (v1.at(i) == x.getNome() && Date(v2.at(i)) == x.getDataNascimento()) {
							jogpart.push_back(x);
							break;
						}
					}
				}
				break;
			case 5:
				equipa_arbitragem = divideStrings(line);
				break;
			case 6:
				equipa_adversaria = divideStrings(line);
				break;
			case 7:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					gols.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 8:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					assists.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 9:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					pass.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 10:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					passcerto.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 11:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					disharms.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 12:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					fouls.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 13:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					kms.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 14:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					min.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 15:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					yellows.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 16:
				v2.clear();
				v2 = divideStrings(line);
				//assert(jognaconv.size() == v2.size());
				for (size_t x = 0; x < jogpart.size(); x++)
					reds.insert(pair<Futebolista, unsigned int>(jogpart.at(x), stoi(v2.at(x))));
				break;
			case 17:
				v1.clear();
				v1 = divideStrings(line);
				break;
			case 18:
				v2.clear();
				v2 = divideStrings(line);
				for (size_t i = 0; i < v1.size(); i++) {
					for (Futebolista x : f1.ReadJogadores()) {
						if (v1.at(i) == x.getNome() && Date(v2.at(i)) == x.getDataNascimento())
							lesao.push_back(x);
					}
				}
			break;
			}
			index++;
			if (index == 19) {
				jogos.push_back(Jogo(data, pais, adversario, cidade, estadio, jognaconv, jogpart, equipa_arbitragem, equipa_adversaria, gols, assists, pass, passcerto, disharms, fouls, kms, min, yellows, reds, lesao));
				index = 0;
				jognaconv.clear(); jogpart.clear(); equipa_arbitragem.clear(); equipa_adversaria.clear(); gols.clear(); assists.clear(); pass.clear(); passcerto.clear(); disharms.clear(); fouls.clear(); kms.clear(); min.clear(); yellows.clear(); reds.clear(); lesao.clear();
			}
		}
	}
	jogofile.close();
	return jogos;
}

void Jogo::addJogo(vector<Jogo>& jogos, vector<Futebolista>& jogadores) {
    unsigned int num_jogadores_conv;
    bool keep = true;
    string input, data, adv, adv1, pais, cid, est;
    unsigned int opt;
    double optd;
    vector<string> arbitros, eqadversaria;
    vector<Futebolista> jogconv, jogpart, lesionados;
    multimap<Futebolista, unsigned int> goals, assists, pass, passcerto, disharms, fouls, min, yellows, reds;
    multimap<Futebolista, double> kms;
    multimap<Futebolista, string> datascheg, dataspart;

    system("cls"); logo();
    std::cin.ignore(1000, '\n');

    do {
        std::cout << " Data do jogo (DD/MM/AAAA): "; std::getline(std::cin, data);
        for (Jogo x : jogos) {
            if (x.getData() == data) {
                throw JogoJaExistente(data);
            }
        }
        keep = true;
    } while (keep != true);

    std::cout << " Adversario: "; std::getline(std::cin, adv);
    for (size_t i = 0; i < adv.size(); i++) {
        if (i == 0)
            adv1 += toupper(adv[1]);
        else
            adv1 += tolower(adv[i]);
    }

    std::cout << " Pais: "; std::getline(cin, pais);
    std::cout << " Cidade: "; getline(cin, cid);
    std::cout << " Estadio: "; getline(cin, est);
    std::cout << " Quantos jogadores pretende convocar para o jogo? ";
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> num_jogadores_conv;
        if (num_jogadores_conv < 1 || num_jogadores_conv > jogadores.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e " << jogadores.size();
        }
    } while (num_jogadores_conv < 1 && num_jogadores_conv > jogos.size());
    system("cls"); logo();
    vector<string> nomes;
    string nome;
    std::cout << " Lista de jogadores disponiveis: " << endl << endl;
    int aux = 0;
    std::cout << " ";
    for (size_t x = 0; x < jogadores.size(); x++) {
        nome = jogadores.at(x).getNome();
        nomes = nameSplitter(nome);
        if (nomes.size() > 2) {
            nome = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
            std::cout << "[" << x + 1 << "]" << setw(18) << nome << "   ";
        }
        else
            std::cout << "[" << x + 1 << "]" << setw(18) << jogadores.at(x).getNome() << "   ";
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    aux = 0;
    std::cout << endl;
    do {
        std::cout << " Jogador a adicionar: "; cin >> opt;
        jogconv.push_back(jogadores.at(opt - 1));
        do {
            std::cout << " Participou no jogo? (S/N)"; cin >> input;
            if (input == "s" || input == "S")
                jogpart.push_back(jogadores.at(opt - 1));
        } while (input != "s" && input != "S" && input != "n" && input != "N");
        num_jogadores_conv--;
    } while (num_jogadores_conv != 0 || opt < 1 || opt > jogadores.size());

    system("cls"); logo();
    std::cout << endl << " Estatisticas de cada jogador" << endl << endl;
    for (Futebolista x : jogpart) {
        std::cout << " " << x.getNome() << " -> [1] Golos = "; cin >> opt;
        goals.insert(pair<Futebolista, unsigned int>(x, opt));
        std::cout << setw(x.getNome().size() + 24) << "[2] Assistencias = "; cin >> opt;
        assists.insert(pair<Futebolista, unsigned int>(x, opt));
        std::cout << setw(x.getNome().size() + 27) << "[3] Total de Passes = "; cin >> opt;
        pass.insert(pair<Futebolista, unsigned int>(x, opt));
        std::cout << setw(x.getNome().size() + 30) << "[4] Passes com sucesso = "; cin >> opt;
        passcerto.insert(pair<Futebolista, unsigned int>(x, opt));
        std::cout << setw(x.getNome().size() + 30) << "[5] Numero de Desarmes = "; cin >> opt;
        disharms.insert(pair<Futebolista, unsigned int>(x, opt));
        std::cout << setw(x.getNome().size() + 28) << "[6] Numero de Faltas = "; cin >> opt;
        fouls.insert(pair<Futebolista, unsigned int>(x, opt));
        std::cout << setw(x.getNome().size() + 27) << "[7] Kms Percorridos = "; cin >> optd;
        kms.insert(pair<Futebolista, double>(x, opt));
        std::cout << setw(x.getNome().size() + 27) << "[8] Minutos jogados = "; cin >> opt;
        min.insert(pair<Futebolista, unsigned int>(x, opt));
        std::cout << setw(x.getNome().size() + 38) << "[9] Numero de Cartoes Amarelos = "; cin >> opt;
        yellows.insert(pair<Futebolista, unsigned int>(x, opt));
        std::cout << setw(x.getNome().size() + 40) << "[10] Numero de Cartoes Vermelhos = "; cin >> opt;
        reds.insert(pair<Futebolista, unsigned int>(x, opt));
        do {
            std::cout << setw(x.getNome().size() + 40) << "[11] Lesao durante o jogo? (S/N) = "; cin >> input;
            if (input == "s" || input == "S")
                lesionados.push_back(x);
        } while (input != "s" && input != "S" && input != "n" && input != "N");
        cout << endl;
    }

    system("cls"); logo();
    std::cout << " Equipa de arbitragem (4 elementos)" << endl << endl;
    cin.ignore(1000, '\n');
    for (size_t x = 0; x < 4; x++) {
        std::cout << " Nome: "; std::getline(std::cin, input);
        arbitros.push_back(input);
    }

    system("cls"); logo();
    std::cout << " Equipa inicial da equipa adversaria (11 elementos)" << endl;
    for (size_t x = 0; x < 11; x++) {
        std::cout << " Nome: "; std::getline(std::cin, input);
        eqadversaria.push_back(input);
    }

    jogos.push_back(Jogo(data, pais, adv, cid, est, jogconv, jogpart, arbitros, eqadversaria, goals, assists, pass, passcerto, disharms, fouls, kms, min, yellows, reds, lesionados));
}

Jogo Jogo::removeJogo(vector<Jogo>& jogos){
    string line, d, data2;
    unsigned int opt;
    int x = 0;
    std::cin.ignore(1000, '\n');
    Jogo j;

    system("cls"); logo();
    do {
        cout << " Qual o jogo que pretende remover?" << endl << endl;
        for (size_t x = 0; x < jogos.size(); x++) {
            cout << " [" << x + 1 << "]" << " Portugal - " << jogos.at(x).getAdversario() << " (" << jogos.at(x).getData() << ")" << endl;
        }
        do {
            cout << endl << "Introduza uma opcao: ";
            cin.clear();
            std::cin >> opt;
            if (opt < 1 || opt > jogos.size()) {
                cin.clear();
                cin.ignore();
                cout << "Input invalido! Introduza um numero entre 1 e " << jogos.size();
            }
        } while (opt < 1 || opt > jogos.size());

        for (vector<Jogo>::const_iterator it = jogos.begin(); it != jogos.end(); it++) {
            if ((*it) == jogos.at(opt - 1)) {
                j = *it;
                jogos.erase(it);
                cout << endl << "Jogo removido com sucesso!";
                break;
            }
        }
    } while (opt < 0 && jogos.size() + 2 > opt);
    return j;
}

void Jogo::infoJogo(vector<Jogo>& jogos) {
    unsigned int opt;
    string option;
    int index;
    bool pass = false;
    int x = 1;
    cin.ignore(1000, '\n');
    std::cout << " Lista de Jogos disponiveis: " << endl << endl << " ";
    do {
        int aux = 0;
        for (size_t x = 0; x < jogos.size(); x++) {
            std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(10) << jogos.at(x).getAdversario() << " (" << jogos.at(x).getData() << ")" << "   ";
            if (aux == 1) {
                aux = -1;
                std::cout << endl << " ";
            }
            aux++;
        }
        std::cout << endl << endl;
        do {
            cout << endl << "Introduza uma opcao: ";
            cin.clear();
            std::cin >> opt;
            if (opt < 1 || opt > jogos.size()) {
                cin.clear();
                cin.ignore();
                cout << "Input invalido! Introduza um numero entre 1 e " << jogos.size();
            }
        } while (opt < 1 || opt > jogos.size());

        system("cls"); logo();
        cout << jogos.at(opt - 1);

        pass = true;
        cin.ignore(1000, '\n');
        do{
            std::cout << "Deseja ver as estatisticas da selecao nacional neste jogo? (S/N): " << endl << "Introduza uma opcao: "; getline(cin, option);
            if (option == "n" || option == "N") {
                std::cout << endl;
                return;
            }
            else if (option == "s" || option == "S") {
                system("cls"); logo();
                vector<string> nomes; string name;
                std::cout << endl << "     Jogadores      |  Golos  |  Assistencias  |  Passes  |  Precisao Passe" << endl;
                std::cout << " -------------------|---------|----------------|----------|--------------------" << endl;
                multimap<Futebolista, unsigned int> assistencias1 = jogos.at(opt - 1).getAssists();
                multimap<Futebolista, unsigned int> passes1 = jogos.at(opt - 1).getPasses();
                multimap<Futebolista, unsigned int> passesacertados1 = jogos.at(opt - 1).getPassesAcertados();
                auto it = assistencias1.begin();
                auto it2 = passes1.begin();
                auto it3 = passesacertados1.begin();
                double percent;
                for (auto z : jogos.at(opt-1).getGolos()) {
                    name = z.first.getNome();
                    nomes = nameSplitter(name);
                    if (nomes.size() > 2) {
                        name = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
                        cout << setfill(' ') << setw(19) << name << " |";
                    }
                    else
                        cout << setfill(' ') << setw(19) << z.first.getNome() << " |";
                    cout << setfill(' ') << setw(4) << ' ' << z.second << setfill(' ') << setw(4) << ' ' << '|' << setfill(' ') << setw(7) << ' ' << (*it).second << setfill(' ') << setw(8) << ' ' << '|';
                    if ((*it2).second >= 100)
                        cout << setfill(' ') << setw(3) << ' ' << (*it2).second << setfill(' ') << setw(4) << ' ' << '|';
                    else if ((*it2).second >= 10)
                        cout << setfill(' ') << setw(4) << ' ' << (*it2).second << setfill(' ') << setw(4) << ' ' << '|';
                    else
                        cout << setfill(' ') << setw(5) << ' ' << (*it2).second << setfill(' ') << setw(4) << ' ' << '|';
                    cout << fixed << setprecision(2);
                    percent = double((*it3).second) / double((*it2).second);
                    cout << setfill(' ') << setw(7) << ' ' << percent*100.0 << endl;
                    it++; it2++; it3++;
                }
                unsigned int cont;
                cout << endl << endl << "Prima 1 para continuar (0 para sair)" << endl;

                do {
                    cout << endl << "Introduza uma opcao: ";
                    cin.clear();
                    std::cin >> cont;
                    if (opt < 0 || opt > 1 || cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Input invalido! Introduza um numero entre 0 e 1";
                    }
                } while (opt < 0 && opt > 1 || cin.fail());

                if (cont == 0)
                    break;
                system("cls"); logo();
                std::cout << endl << "     Jogadores      | Desarmes | Faltas | Minutos | Amarelos | Vermelhos " << endl;
                std::cout << " -------------------|----------|--------|---------|----------|-----------" << endl;
                multimap<Futebolista, unsigned int> desarmes1 = jogos.at(opt - 1).getDesarmes();
                multimap<Futebolista, unsigned int> faltas1 = jogos.at(opt - 1).getFaltas();
                multimap<Futebolista, unsigned int> min1 = jogos.at(opt - 1).getMinutosJogados();
                multimap<Futebolista, unsigned int> amarelos1 = jogos.at(opt - 1).getAmarelos();
                multimap<Futebolista, unsigned int> vermelhos1 = jogos.at(opt - 1).getVermelhos();
                auto it4 = desarmes1.begin();
                auto it5 = faltas1.begin();
                auto it6 = min1.begin();
                auto it7 = amarelos1.begin();
                auto it8 = vermelhos1.begin();
                for (auto z : jogos.at(opt - 1).getGolos()) {
                    name = z.first.getNome();
                    nomes = nameSplitter(name);
                    if (nomes.size() > 2) {
                        name = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
                        cout << setfill(' ') << setw(19) << name << " |";
                    }
                    else
                        cout << setfill(' ') << setw(19) << name << " |";
                    cout << setfill(' ') << setw(4) << " " << setw(2) << (*it4).second << setfill(' ') << setw(5) << " |";
                    cout << setfill(' ') << setw(3) << " " << setw(2) << (*it5).second << setfill(' ') << setw(4) << " |";
                    cout << setfill(' ') << setw(4) << " " << setw(2) << (*it6).second << setfill(' ') << setw(4) << " |";
                    cout << setfill(' ') << setw(4) << " " << setw(2) << (*it7).second << setfill(' ') << setw(5) << " |";
                    cout << setfill(' ') << setw(4) << " " << setw(2) << (*it7).second << setfill(' ') << setw(6) << "  " << endl;

                    it4++; it5++; it6++; it7++;
                }
            }
            else {
                cout << "Input invalido! Tente novamente" << endl;
            }
        } while (option != "S" && option != "s" && option != "N" && option != "n");
    } while (pass != true);
    std::cout << endl << endl;
}

void Jogo::editJogo(vector<Jogo>& jogos, vector<Futebolista>& jogadores) {
    string line, op, input;
    unsigned int option, opt1, opt2, num, n, nrjogadores;
    double optd;
    vector<Futebolista> temp;
    multimap<Futebolista, unsigned int> goals, assists, pass, passcerto, disharms, fouls, min, yellows, reds;
    multimap<Futebolista, double> kms;
    multimap<Futebolista, string> datascheg, dataspart;

    cin.ignore(1000, '\n');
    cin.clear();
    std::cout << " Lista de jogos disponiveis: " << endl << endl;
    bool valid = true;
    for (size_t i = 0; i < jogos.size(); i++) {
        std::cout << " [" << i + 1 << "] " << jogos.at(i).getAdversario() << " (" << jogos.at(i).getData() << ")" << endl;
    }
    std::cout << endl << "Que jogo pretende editar?" << endl;
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> option;
        if (option < 1 || option > jogos.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e " << jogos.size();
        }
    } while (option < 1 || option > jogos.size());
    system("cls"); logo();
    std::cout << " Escolha o que pretende editar:" << endl << endl;
    std::cout << "   1 - Data" << endl;
    std::cout << "   2 - Adversario" << endl;
    std::cout << "   3 - Pais" << endl;
    std::cout << "   4 - Cidade" << endl;
    std::cout << "   5 - Estadio" << endl;
    std::cout << "   6 - Jogadores convocados" << endl;
    std::cout << "   7 - Jogadores participantes" << endl;
    std::cout << "   8 - Equipa de arbitragem" << endl;
    std::cout << "   9 - 11 inicial adversario" << endl;
    std::cout << "   10 - Estatisticas" << endl;
    std::cout << endl << "Que jogo pretende editar?" << endl;
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> num;
        if (num < 1 || num > 10) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e 10";
        }
    } while (option < 1 || option > jogos.size());

    system("cls"); logo();
    std::cout << " Jogo selecionado: " << jogos.at(option - 1).getAdversario() << " (" << jogos.at(option - 1).getData() << ")" << endl << endl;
    cin.ignore(1000, '\n');
    vector<string> nomes, arbitros, eqadversaria; string name; unsigned int aux, opt;
    vector<Futebolista> jogpart, jogconv, lesionados;
    switch (num) {
        case 1:
            std::cout << " Nova data (DD/MM/AAAA): "; getline(cin, line);
            jogos.at(option - 1).setData(line);
            break;
        case 2:
            std::cout << " Novo adversario : "; getline(cin, line);
            jogos.at(option - 1).setAdversario(line);
            break;
        case 3:
            std::cout << " Novo pais : "; getline(cin, line);
            jogos.at(option - 1).setPais(line);
            break;
        case 4:
            std::cout << " Nova cidade : "; getline(cin, line);
            jogos.at(option - 1).setCidade(line);
            break;
        case 5:
            std::cout << " Novo estadio : "; getline(cin, line);
            jogos.at(option - 1).setEstadio(line);
            break;
        case 6:
            std::cout << " Quantos jogadores pretende adicionar? "; cin >> nrjogadores; cout << endl;
            std::cout << " Lista de jogadores disponiveis:" << endl << endl;
            aux = 0;
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
            std::cout << endl << endl;
            do {
                std::cout << " Jogador a adicionar: "; cin >> opt;
                if (opt <= jogadores.size() && opt >= 1) {
                    cin.ignore(1000, '\n');
                    jogconv.push_back(jogadores.at(opt - 1));
                    std::cout << " Participou no jogo? (S/N): "; std::getline(std::cin, line);
                    do {
                        if (line == "s" || line == "S") {
                            jogpart.push_back(jogadores.at(opt - 1));
                        }
                    } while (line != "S" && line != "s" && line != "N" && line != "n");
                }
                nrjogadores--;
            } while (opt < 1 && opt > jogadores.size() || nrjogadores != 0);

            system("cls"); logo();
            std::cout << endl << " Estatisticas de cada jogador" << endl << endl;
            for (Futebolista x : jogpart) {
                std::cout << " " << x.getNome() << " -> [1] Golos = "; cin >> opt;
                goals.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 24) << "[2] Assistencias = "; cin >> opt;
                assists.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 27) << "[3] Total de Passes = "; cin >> opt;
                pass.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 30) << "[4] Passes com sucesso = "; cin >> opt;
                passcerto.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 30) << "[5] Numero de Desarmes = "; cin >> opt;
                disharms.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 28) << "[6] Numero de Faltas = "; cin >> opt;
                fouls.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 27) << "[7] Kms Percorridos = "; cin >> optd;
                kms.insert(pair<Futebolista, double>(x, opt));
                std::cout << setw(x.getNome().size() + 27) << "[8] Minutos jogados = "; cin >> opt;
                min.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 38) << "[9] Numero de Cartoes Amarelos = "; cin >> opt;
                yellows.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 40) << "[10] Numero de Cartoes Vermelhos = "; cin >> opt;
                reds.insert(pair<Futebolista, unsigned int>(x, opt));
                do {
                    std::cout << setw(x.getNome().size() + 40) << "[11] Lesao durante o jogo? (S/N) = "; cin >> input;
                    if (input == "s" || input == "S")
                        lesionados.push_back(x);
                } while (input != "s" && input != "S" && input != "n" && input != "N");
                cout << endl;
            }

            jogos.at(option - 1).setJogadoresConvocados(jogconv);
            jogos.at(option - 1).setJogadoresParticipantes(jogpart);
            jogos.at(option - 1).setGolos(goals);
            jogos.at(option - 1).setAssists(assists);
            jogos.at(option - 1).setPasses(pass);
            jogos.at(option - 1).setPassesAcertados(passcerto);
            jogos.at(option - 1).setDesarmes(disharms);
            jogos.at(option - 1).setFaltas(fouls);
            jogos.at(option - 1).setKmPercorridos(kms);
            jogos.at(option - 1).setMinutosJogados(min);
            jogos.at(option - 1).setAmarelos(yellows);
            jogos.at(option - 1).setVermelhos(reds);
            jogos.at(option - 1).setLesao(lesionados);
            break;
        case 7:
            aux = 0;
            std::cout << " Quantos jogadores pretende adicionar? "; cin >> nrjogadores; cout << endl;
            std::cout << " Lista de jogadores disponiveis: " << endl << endl;
            aux = 0;
            std::cout << " ";
            for (size_t x = 0; x < jogos.at(option - 1).getJogadoresConvocados().size(); x++) {
                name = jogos.at(option - 1).getJogadoresConvocados().at(x).getNome();
                nomes = nameSplitter(name);
                if (nomes.size() == 1)
                    std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << jogos.at(option - 1).getJogadoresConvocados().at(x).getNome() << "   ";
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
            std::cout << endl << endl;
            do {
                std::cout << " Jogador a adicionar: "; cin >> opt;
                if (opt <= jogos.at(option - 1).getJogadoresConvocados().size() && opt >= 1) {
                    jogpart.push_back(jogos.at(option - 1).getJogadoresConvocados().at(opt - 1));
                }
                nrjogadores--;
            } while (opt < 1 && opt > jogadores.size() || nrjogadores != 0);

            system("cls"); logo();
            std::cout << endl << " Estatisticas de cada jogador" << endl << endl;
            for (Futebolista x : jogpart) {
                std::cout << " " << x.getNome() << " -> [1] Golos = "; cin >> opt;
                goals.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 24) << "[2] Assistencias = "; cin >> opt;
                assists.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 27) << "[3] Total de Passes = "; cin >> opt;
                pass.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 30) << "[4] Passes com sucesso = "; cin >> opt;
                passcerto.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 30) << "[5] Numero de Desarmes = "; cin >> opt;
                disharms.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 28) << "[6] Numero de Faltas = "; cin >> opt;
                fouls.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 27) << "[7] Kms Percorridos = "; cin >> optd;
                kms.insert(pair<Futebolista, double>(x, opt));
                std::cout << setw(x.getNome().size() + 27) << "[8] Minutos jogados = "; cin >> opt;
                min.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 38) << "[9] Numero de Cartoes Amarelos = "; cin >> opt;
                yellows.insert(pair<Futebolista, unsigned int>(x, opt));
                std::cout << setw(x.getNome().size() + 40) << "[10] Numero de Cartoes Vermelhos = "; cin >> opt;
                reds.insert(pair<Futebolista, unsigned int>(x, opt));
                do {
                    std::cout << setw(x.getNome().size() + 40) << "[11] Lesao durante o jogo? (S/N) = "; cin >> input;
                    if (input == "s" || input == "S")
                        lesionados.push_back(x);
                } while (input != "s" && input != "S" && input != "n" && input != "N");
                cout << endl;
            }

            jogos.at(option - 1).setJogadoresParticipantes(jogpart);
            jogos.at(option - 1).setGolos(goals);
            jogos.at(option - 1).setAssists(assists);
            jogos.at(option - 1).setPasses(pass);
            jogos.at(option - 1).setPassesAcertados(passcerto);
            jogos.at(option - 1).setDesarmes(disharms);
            jogos.at(option - 1).setFaltas(fouls);
            jogos.at(option - 1).setKmPercorridos(kms);
            jogos.at(option - 1).setMinutosJogados(min);
            jogos.at(option - 1).setAmarelos(yellows);
            jogos.at(option - 1).setVermelhos(reds);
            jogos.at(option - 1).setLesao(lesionados);
            break;
        case 8:
            std::cout << " Equipa de arbitragem (4 elementos)" << endl << endl;
            for (size_t x = 0; x < 4; x++) {
                std::cout << " Nome: "; std::getline(std::cin, input);
                arbitros.push_back(input);
            }
            jogos.at(option - 1).setEquipaArbitragem(arbitros);
            break;
        case 9:
            system("cls"); logo();
            std::cout << " Equipa adversaria (11 elementos)" << endl << endl;
            cin.ignore(1000, '\n');
            for (size_t x = 0; x < 11; x++) {
                std::cout << " Nome: "; std::getline(std::cin, input);
                eqadversaria.push_back(input);
                jogos.at(option - 1).setEquipaAdversaria(eqadversaria);
            }
            break;
        case 10:
            aux = 0;
            for (size_t x = 0; x < jogos.at(option - 1).getJogadoresParticipantes().size(); x++) {
                name = jogos.at(option - 1).getJogadoresParticipantes().at(x).getNome();
                nomes = nameSplitter(name);
                if (nomes.size() == 1)
                    std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << jogos.at(option - 1).getJogadoresParticipantes().at(x).getNome() << "   ";
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
            std::cout << endl << endl;
            do {
                std::cout << " Selecione o jogador que pretende editar: "; cin >> opt;
                if (opt <= jogos.at(option - 1).getJogadoresParticipantes().size() && opt >= 1) {
                    system("cls"); logo();
                    cout << "Jogador selecionado: " << jogos.at(option - 1).getJogadoresParticipantes().at(opt - 1).getNome() << endl << endl;
                    cout << " O que pretende editar?" << endl << endl;
                    cout << "   1 - Golos" << endl;
                    cout << "   2 - Assistencias" << endl;
                    cout << "   3 - Passes" << endl;
                    cout << "   4 - Passes Acertados" << endl;
                    cout << "   5 - Desarmes" << endl;
                    cout << "   6 - Faltas" << endl;
                    cout << "   7 - Kms Percorridos" << endl;
                    cout << "   8 - Minutos Jogados" << endl;
                    cout << "   9 - Amarelos" << endl;
                    cout << "   10 - Vermelhos" << endl << endl;

                    goals = jogos.at(option - 1).getGolos();
                    assists = jogos.at(option - 1).getAssists();
                    pass = jogos.at(option - 1).getPasses();
                    passcerto = jogos.at(option - 1).getPassesAcertados();
                    disharms = jogos.at(option - 1).getDesarmes();
                    fouls = jogos.at(option - 1).getFaltas();
                    kms = jogos.at(option - 1).getKmPercorridos();
                    min = jogos.at(option - 1).getMinutosJogados();
                    yellows = jogos.at(option - 1).getAmarelos();
                    reds = jogos.at(option - 1).getVermelhos();
                    auto it1 = goals.begin();
                    auto it2 = kms.begin();

                    do{
                        cout << "Introduza uma opcao: "; cin >> opt1;
                    } while (opt1 < 1 && opt > 10);
                    system("cls"); logo();
                    switch (opt1) {
                        case 1:
                            cout << " Numero de golos: "; cin >> opt2;
                            for (size_t x = 1; x < opt; x++)
                                it1++;
                            (*it1).second = opt2;
                            jogos.at(option - 1).setGolos(goals);
                            break;
                        case 2:
                            it1 = assists.begin();
                            cout << " Numero de assistencias: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it1++;
                            (*it1).second = opt2;
                            jogos.at(option - 1).setAssists(assists);
                            break;
                        case 3:
                            it1 = pass.begin();
                            cout << " Numero de passes: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it1++;
                            (*it1).second = opt2;
                            jogos.at(option - 1).setPasses(pass);
                            break;
                        case 4:
                            it1 = passcerto.begin();
                            cout << " Numero de passes acertados: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it1++;
                            (*it1).second = opt2;
                            jogos.at(option - 1).setPassesAcertados(passcerto);
                            break;
                        case 5:
                            it1 = disharms.begin();
                            cout << " Numero de desarmes: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it1++;
                            (*it1).second = opt2;
                            jogos.at(option - 1).setDesarmes(disharms);
                            break;
                        case 6:
                            it1 = fouls.begin();
                            cout << " Numero de faltas: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it1++;
                            (*it1).second = opt2;
                            jogos.at(option - 1).setFaltas(fouls);
                            break;
                        case 7:
                            it2 = kms.begin();
                            cout << " Numero de kms percorridos: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it2++;
                            (*it2).second = opt2;
                            jogos.at(option - 1).setKmPercorridos(kms);
                            break;
                        case 8:
                            it1 = min.begin();
                            cout << " Numero de minutos jogados: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it1++;
                            jogos.at(option - 1).setMinutosJogados(min);
                            (*it1).second = opt2;
                            break;
                        case 9:
                            it1 = yellows.begin();
                            cout << " Numero de amarelos: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it1++;
                            (*it1).second = opt2;
                            jogos.at(option - 1).setAmarelos(yellows);
                            break;
                        case 10:
                            it1 = reds.begin();
                            cout << " Numero de vermelhos: "; cin >> opt2;
                            for (size_t x = 1; x < opt1; x++)
                                it1++;
                            (*it1).second = opt2;
                            jogos.at(option - 1).setVermelhos(reds);
                            break;
                    }
                }
            } while (opt < 1 && opt > jogos.at(option - 1).getJogadoresParticipantes().size());
            break;
    }
}

//Ostreams

ostream& operator<<(ostream& out, Jogo& j){
    out << " Data do jogo: " << j.getData() << endl;
    out << " Selecao adversaria: " << j.getAdversario() << endl;
    out << " Pais: " << j.getPais() << endl;
    out << " Cidade: " << j.getCidade() << endl;
    out << " Estadio: " << j.getEstadio() << endl;
    out << " Selecoes:" << endl;
    out << " " << "      Portugal      " << "        " << j.getAdversario() << "      " << endl << endl;
    out << fixed << setprecision(2);
    string name; vector<string> nomes;
    for (size_t x = 0; x < j.getJogadoresConvocados().size(); x++) {
        name = j.getJogadoresConvocados().at(x).getNome();
        nomes = nameSplitter(name);
        if (nomes.size() < 2)
            out << " " << setfill(' ') << setw(20) << j.getJogadoresConvocados().at(x).getNome() << "  " << setfill(' ') << setw(20) << j.getEquipaAdversaria().at(x) << endl;
        else {
            name = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
            out << " " << setfill(' ') << setw(20) << name << "  " << setfill(' ') << setw(20) << j.getEquipaAdversaria().at(x) << endl;
        }
        if (x == j.getJogadoresConvocados().size() - 1)
            out << endl << " ";
    }
    return out;
}