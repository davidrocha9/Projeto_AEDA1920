#include <fstream>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
#include <ostream>

#include "Convocatoria.h"
#include "Utils.h"
#include "Jogadores.h"
#include "Jogo.h"

using namespace std;

//Construtores
Convocatoria::Convocatoria(unsigned int id, unsigned int nrjogos, unsigned int custo, string datai, string dataf, string competicao, vector<Jogo> jogos, vector<Futebolista> jogadoresnaconvocatoria, vector<EquipaTecnica> equipatnaconvocatoria, multimap<Futebolista, bool> condicaofisica, multimap<Futebolista, Date> dataschegada, multimap<Futebolista, Date> dataspartida): id(id), nrjogos(nrjogos), custodiario(custo), datainicial(Date(datai)), datafinal(Date(dataf)), competicao(competicao), jogos(jogos), jogadoresnaconvocatoria(jogadoresnaconvocatoria), equipatnaconvocatoria(equipatnaconvocatoria), condicaofisica(condicaofisica), dataschegada(dataschegada), dataspartida(dataspartida){}

//Metodos GET
unsigned int Convocatoria::getId() const{
	return id;
}

unsigned int Convocatoria::getNrJogos() const{
	return jogos.size();
}

unsigned int Convocatoria::getCustoDiario() const{
	return custodiario;
}

Date Convocatoria::getDataInicial() const{
	return datainicial;
}

Date Convocatoria::getDataFinal() const{
	return datafinal;
}

string Convocatoria::getCompeticao() const{
	return competicao;
}

vector<Jogo> Convocatoria::getJogos() const{
	return jogos;
}

vector<Futebolista> Convocatoria::getJogadores() const{
	return jogadoresnaconvocatoria;
}

vector<EquipaTecnica> Convocatoria::getEquipaTecnica(){
	return equipatnaconvocatoria;
}

multimap<Futebolista, bool> Convocatoria::getCondicaoFisica(){
	return condicaofisica;
}

multimap<Futebolista, Date> Convocatoria::getDatasChegada() const {
	return dataschegada;
}

multimap<Futebolista, Date> Convocatoria::getDatasPartida() const {
	return dataspartida;
}


//Metodos SET
void Convocatoria::setId(unsigned int id){
	this->id = id;
}

void Convocatoria::setNrJogos(unsigned int nrjogos){
	this->nrjogos = nrjogos;
}

void Convocatoria::setCustoDiario(unsigned int custo){
	custodiario = custo;
}

void Convocatoria::setDataInicial(string datai){
	datainicial = datai;
}

void Convocatoria::setDataFinal(string dataf){
	datafinal = dataf;
}

void Convocatoria::setCompeticao(string comp){
	competicao = comp;
}

void Convocatoria::setJogos(vector<Jogo> jogos){
	this->jogos = jogos;
}

void Convocatoria::setCondicaoFisica(multimap<Futebolista, bool> condicaofisica){
	this->condicaofisica = condicaofisica;
}

void Convocatoria::setDatasChegada(multimap<Futebolista, Date> dataschegada){
	this->dataschegada = dataschegada;
}

void Convocatoria::setDatasPartida(multimap<Futebolista, Date> dataspartida){
	this->dataspartida = dataspartida;
}


//Outros Metodos
vector<Convocatoria> Convocatoria::ReadConvocatoria(vector<Jogo> jogo){
	vector<Convocatoria> convocatoria;
	ifstream convocatoriafile;
	convocatoriafile.open("../convocatorias.txt");
	Futebolista f1;
	EquipaTecnica et1;
	Jogo j1;
	vector<Futebolista> jognaconv;
	vector<EquipaTecnica> etnaconv;
	vector<Jogo> jogos;
	multimap<Futebolista, bool> condfis;
	multimap<Futebolista, Date> datascheg;
	multimap<Futebolista, Date> dataspart;
	string datai, dataf;

	if (convocatoriafile.fail()) {									// checking if nothing went wrong
		cerr << "Error Opening File. Try again!" << endl;		// while opening the file
	}
	else {
		int index = 0;
		string line;
		vector<string> v1, v2;
		while (!convocatoriafile.eof()) {// going through the file
			std::getline(convocatoriafile, line);
			switch (index) {
			case 0:
				v1 = divideStrings(line);
				for (size_t x = 0; x < v1.size(); x++) {
					switch (x) {
					case 0:
						id = stoi(v1.at(x));
						break;
					case 1:
						nrjogos = stoi(v1.at(x));
						break;
					case 2:
						custodiario = stoi(v1.at(x));
						break;
					case 3:
						datai = v1.at(x);
						break;
					case 4:
						dataf = v1.at(x);
						break;
					case 5:
						competicao = v1.at(x);
						break;
					default:
						break;
					}
				}
				break;
			case 1:
				v1 = divideStrings(line);
				break;
			case 2:
				v2 = divideStrings(line);
				for (size_t x = 0; x < v1.size(); x++) {
					for (Jogo i : jogo) {
						if (v1.at(x) == i.getAdversario() && Date(v2.at(x)) == i.getData())
							jogos.push_back(i);
					}
				}
				break;
			case 3:
				v1.clear();
				v1 = divideStrings(line);
				break;
			case 4:
				v2 = divideStrings(line);
				for (size_t i = 0; i < v1.size(); i++) {
					for (Futebolista x : f1.ReadJogadores()) {
						if (v1.at(i) == x.getNome() && Date(v2.at(i)) == x.getDataNascimento())
							jognaconv.push_back(x);
					}
				}
				break;
			case 5:
				v1 = divideStrings(line);
				for (size_t x = 0; x < jognaconv.size(); x++) {
					if (v1.at(x) == "1")
						condfis.insert(pair<Futebolista, bool>(jognaconv.at(x), false));
					else
						condfis.insert(pair<Futebolista, bool>(jognaconv.at(x), true));
				}
				break;
			case 6:
				v1.clear();
				v1 = divideStrings(line);
				for (size_t x = 0; x < jognaconv.size(); x++) {
					datascheg.insert(pair<Futebolista, string>(jognaconv.at(x), v1.at(x)));
				}
				break;
			case 7:
				v1.clear();
				v1 = divideStrings(line);
				for (size_t x = 0; x < jognaconv.size(); x++) {
					dataspart.insert(pair<Futebolista, string>(jognaconv.at(x), v1.at(x)));
				}
				break;
			case 8:
				v1.clear();
				v1 = divideStrings(line);
				break;
			case 9:
				v2.clear();
				v2 = divideStrings(line);
				for (size_t i = 0; i < v1.size(); i++) {
					for (EquipaTecnica x : et1.ReadEquipaTecnica()) {
						if (v1.at(i) == x.getNome() && Date(v2.at(i)) == x.getDataNascimento())
							etnaconv.push_back(x);
					}
				}
				break;
			}
			index++;
			if (index == 10) {
			    Convocatoria c(id, nrjogos, custodiario, datai, dataf, competicao, jogos, jognaconv, etnaconv, condfis, datascheg, dataspart);
				convocatoria.push_back(c);
				index = 0;
				jognaconv.clear(); etnaconv.clear(); condfis.clear(); datascheg.clear(); dataspart.clear();
			}
		}
	}
	convocatoriafile.close();
	return convocatoria;
}

void Convocatoria::InformacoesConvocatoria(vector<Convocatoria>& convocatoria) const{
    unsigned int opt, aux = 0;
    cout << " Lista de convcatorias disponiveis:" << endl << endl;
    for (size_t x = 0; x < convocatoria.size(); x++) {
        cout << " [" << x + 1 << "]" << setfill(' ') << setw(18) << convocatoria.at(x).getCompeticao() << "   ";
        if (aux == 2) {
            aux = -1;
            cout << endl << " ";
        }
        aux++;
    }
    cout << endl;
    do {
        cout << endl << " Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > convocatoria.size()) {
            cin.clear();
            cin.ignore();
            cout << " Input invalido! Introduza um numero entre 1 e " << convocatoria.size();
        }
    } while (opt < 1 || opt > convocatoria.size());
    system("cls"); logo();
    cout << convocatoria.at(opt - 1);
}

void Convocatoria::AdicionarConvocatoria(vector<Convocatoria>& convocatoria, vector<Futebolista> jogadores, vector<EquipaTecnica> equipatecnica, vector<Jogo> jogo) const{
    unsigned int id, nrjogos, custo, nrjogadores, aux = 0, nret, opt;
    bool pass;
    string datai, dataf, nome, dn, datac, datap, input, comp;
    vector<Futebolista> jog;
    vector<EquipaTecnica> et;
    multimap<Futebolista, bool> condicaof;
    multimap<Futebolista, Date> datasch;
    multimap<Futebolista, Date> dataspa;
    vector<Jogo> jogos;

    do {
        pass = true;
        std::cout << " ID da convocatoria: "; std::cin >> id;
        for (auto x : convocatoria) {
            if (x.getId() == id) {
                pass = false;
                throw ConvocatoriaJaExistente(id);
            }
        }
    } while (pass != true);

    std::cout << " Custo diario: "; std::cin >> custo;
    std::cin.ignore(1000, '\n');
    Date d1, d2;
    do {
        do {
            cout << " Data de Inicio (DD/MM/AAAA): ";
            cin.clear();
            std::getline(std::cin, datai);
            if (datai.length() != 10) {
                cin.clear();
                cout << " Data Invalida! Tente novamente." << endl;
            }
        } while (datai.length() != 10);
        do {
            cout << " Data de Fim (DD/MM/AAAA): ";
            cin.clear();
            std::getline(std::cin, dataf);
            if (dataf.length() != 10) {
                cin.clear();
                cout << " Data Invalida! Tente novamente." << endl;
            }
        } while (dataf.length() != 10);
        d1 = Date(datai); d2 = Date(dataf);
        if (d1 > d2)
            cout << " Data inicial nao pode ser superior a data final! Tente novamente." << endl;
    } while (d1 > d2);
    std::cout << " Nome da competicao em causa: ";  std::getline(std::cin, comp);
    do {
        std::cout << " Numero de jogos a adicionar: "; std::cin >> nrjogos;
        if (nrjogos > jogo.size()) {
            cout << " Apenas existe(m) " << jogo.size() << " jogo(s) na base de dados! Tente novamente." << endl;
        }
    } while (nrjogos > jogo.size());
    do {
        std::cout << " Numero de jogadores a adicionar: "; std::cin >> nrjogadores;
        if (nrjogadores > jogadores.size()) {
            cout << " Apenas existe(m) " << jogadores.size() << " jogador(es) na base de dados! Tente novamente." << endl;
        }
    } while (nrjogadores > jogadores.size());
    do {
        std::cout << " Numero de membro tecnicos: "; std::cin >> nret;
        if (nret > equipatecnica.size()) {
            cout << " Apenas existe(m) " << equipatecnica.size() << " membro(s) na base de dados! Tente novamente." << endl;
        }
    } while (nret > equipatecnica.size());


    system("cls"); logo();
    std::cout  << " Lista de jogos disponiveis: " << endl << endl;
    aux = 0;
    cout << " ";
    for (size_t x = 0; x < jogo.size(); x++) {
        std::cout << "[" << x + 1 << "]" << setfill (' ') << setw(8) << jogo.at(x).getAdversario() << " (" << jogo.at(x).getData() << ")" << "   ";
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    cout << endl << endl;
    do {
        cout << "Jogo a adicionar: "; cin >> opt;
        if (opt < 1 || opt > jogo.size() || cin.fail()) {
            cin.clear();
            cout << " Input invalido! Introduza um numero entre 1 e " << jogo.size() << endl;
            cin.ignore(1000, '\n');
        }
        else {
            jogos.push_back(jogo.at(opt - 1));
            nrjogos--;
        }

    } while (nrjogos != 0 || cin.fail());


    system("cls"); logo();
    vector<string> nomes; string name;
    cout << " Lista de jogadores disponiveis:" << endl << endl;
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
    cout << endl << endl;
    do {
        cout << " Jogador a adicionar: "; cin >> opt;
        if (opt <= jogadores.size() && opt >= 1) {
            jog.push_back(jogadores.at(opt - 1));
            nrjogadores--;
            cin.ignore(1000, '\n');
            do {
                std::cout << " Data de chegada (DD/MM/AAAA): "; getline(cin, datac);
                if (Date(datac) < Date(datai) || Date(dataf) < Date(datac))
                    cout << " Data de chegada invalida! Tente novamente" << endl;
            } while (Date(datac) < Date(datai) || Date(dataf) < Date(datac));
            datasch.insert(pair<Futebolista, Date>(jogadores.at(opt - 1), Date(datac)));
            do {
                std::cout << " Data de partida (DD/MM/AAAA): "; getline(cin, datap);
                if (Date(datac) > Date(datap) || Date(datap) > Date(dataf) || Date(datac) > Date(datap))
                    cout << " Data de chegada invalida! Tente novamente" << endl;
            } while (Date(datac) > Date(datap) || Date(datap) > Date(dataf) || Date(datac) > Date(datap));
            dataspa.insert(pair<Futebolista, Date>(jogadores.at(opt - 1), Date(datac)));
            do {
                std::cout << " O jogador encontra-se lesionado? (S/N) "; getline(cin, input);
                if (input == "s" || input == "S")
                    condicaof.insert(pair<Futebolista, bool>(jogadores.at(opt - 1), false));
                else if (input == "n" || input == "N")
                    condicaof.insert(pair<Futebolista, bool>(jogadores.at(opt - 1), true));
                else {
                    cout << " Input invalido! Tente novamente";
                    cin.ignore(1000, '\n');
                }
            } while (input != "s" && input != "S" && input != "n" && input != "N");
        }
        else {
            cin.clear();
            cout << " Opcao invalida! Tente novamente." << endl;
            cin.ignore(1000, '\n');
        }
    } while (nrjogadores != 0 || cin.fail());

    system("cls"); logo();
    nomes.clear();
    cout << " Lista de membros tecnicos disponiveis:" << endl << endl;
    aux = 0;
    std::cout << " ";
    for (size_t x = 0; x < equipatecnica.size(); x++) {
        name = equipatecnica.at(x).getNome();
        nomes = nameSplitter(name);
        if (nomes.size() == 1)
            std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << equipatecnica.at(x).getNome() << "   ";
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
    cout << endl << endl;
    do {
        cout << "Membro Tecnico a adicionar: "; cin >> opt;
        if (opt >= 1 && opt <= equipatecnica.size()) {
            et.push_back(equipatecnica.at(opt - 1));
            nret--;
            cin.ignore(1000, '\n');
        }
        else {
            cin.clear();
            cout << " Opcao invalida! Tente novamente." << endl;
            cin.ignore(1000, '\n');
        }
    } while (nret != 0 || cin.fail());

    convocatoria.push_back(Convocatoria(id, nrjogos, custo, datai, dataf, comp, jogos, jog, et, condicaof, datasch, dataspa));
}

void Convocatoria::RemoverConvocatoria(vector<Convocatoria>& convocatoria) const {
    unsigned int opt;
    int i = 1;
    std::cin.ignore();

    std::cout << " Lista de convocatorias disponiveis:" << endl << endl;
    int aux = 0;
    std::cout << " ";
    for (size_t x = 0; x < convocatoria.size(); x++) {
        std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << convocatoria.at(x).getCompeticao() << "   ";
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    std::cout << endl << endl << endl << " Que convocatoria pretende remover?" << endl << endl;

    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > convocatoria.size()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e " << convocatoria.size();
        }
    } while (opt < 1 || opt > convocatoria.size());
    convocatoria.erase(convocatoria.begin() + opt - 1);

    cout << endl << endl << "Convocatoria removida com sucesso!" << endl;
}

void Convocatoria::EditarConvocatoria(vector<Convocatoria>& convocatoria, vector<Jogo>& jogo) const {
    unsigned int id , input, change, opt;
    string changestr;
    bool pass = false;
    vector<Convocatoria>::iterator it2;

    std::cout << " Lista de convocatorias disponiveis:" << endl << endl;
    int aux = 0, i = 1;
    std::cout << " ";
    for (size_t x = 0; x < convocatoria.size(); x++) {
        std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(18) << convocatoria.at(x).getCompeticao() << "   ";
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    std::cout << endl << endl << endl << " Que convocatoria pretende editar?" << endl << endl;
    do {
        cout << endl << " Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > convocatoria.size()) {
            cin.clear();
            cin.ignore();
            cout << " Input invalido! Introduza um numero entre 1 e " << convocatoria.size();
        }
    } while (opt < 1 || opt > convocatoria.size());

    system("cls"); logo();

    std::cout << " O que pretende editar? " << endl << endl;
    std::cout << "   1 - ID" << endl;
    std::cout << "   2 - Jogos" << endl;
    std::cout << "   3 - Custo Diario" << endl;
    std::cout << "   4 - Data Inicial" << endl;
    std::cout << "   5 - Data Final" << endl;
    std::cout << endl << endl;

    do {
        cout << endl << " Introduza uma opcao: ";
        cin.clear();
        std::cin >> input;
        if (input < 1 || input > 5) {
            cin.clear();
            cin.ignore();
            cout << " Input invalido! Introduza um numero entre 1 e 5" << endl;
        }
    } while (input < 1 || input > 5);

    system("cls"); logo();
    vector<Jogo> newjogos;
    unsigned int nrjogos;
    switch (input) {
        case 1:
            std::cout << " Insira o novo ID: "; cin >> change;
            convocatoria.at(opt-1).setId(change);
            break;
        case 2:
            std::cout << " Quantos jogos pretende adicionar?" << endl;
            do{
                cout << " Introduza uma opcao: "; cin >> nrjogos;
                if (nrjogos < 0 || nrjogos > jogo.size())
                    cout << " Input invalido! Tente novamente." << endl;
            } while (nrjogos < 0 || nrjogos > jogo.size());
            system("cls"); logo();
            std::cout << " Lista de jogos disponiveis: " << endl << endl;
            aux = 0;
            cout << " ";
            for (size_t x = 0; x < jogo.size(); x++) {
                std::cout << "[" << x + 1 << "]" << setfill(' ') << setw(8) << jogo.at(x).getAdversario() << " (" << jogo.at(x).getData() << ")" << "   ";
                if (aux == 2) {
                    aux = -1;
                    std::cout << endl << " ";
                }
                aux++;
            }

            cout << endl << endl;
            do {
                cout << "Jogo a adicionar: "; cin >> opt;
                if (opt < 1 || opt > jogo.size() || cin.fail()) {
                    cin.clear();
                    cout << " Input invalido! Introduza um numero entre 1 e " << jogo.size();
                    cin.ignore(1000, '\n');
                }
                else {
                    newjogos.push_back(jogo.at(opt - 1));
                    nrjogos--;
                }

            } while (opt < 1 || opt > jogo.size() || cin.fail());
            convocatoria.at(opt - 1).setJogos(newjogos);
            break;
        case 3:
            std::cout << " Insira o novo Custo Diario: "; cin >> change;
            convocatoria.at(opt - 1).setCustoDiario(change);
            break;
        case 4:
            std::cout << " Insira a nova Data Incial: "; getline(cin, changestr);
            convocatoria.at(opt - 1).setDataInicial(changestr);
            break;
        case 5:
            std::cout << " Insira a nova Data Final: "; getline(cin, changestr);
            convocatoria.at(opt - 1).setDataFinal(changestr);
            break;
        default:
            break;
    }
}

void Convocatoria::updateJogos(vector<Convocatoria>& convocatoria, Jogo& j) {
    vector<Jogo> newjogos;
    for (size_t x = 0; x < convocatoria.size(); x++) {
        newjogos.clear();
        for (size_t i = 0; i < convocatoria.at(x).getJogos().size(); i++) {
            if ((convocatoria.at(x).getJogos().at(i).getAdversario() != j.getAdversario()) && (j.getData() != convocatoria.at(x).getJogos().at(i).getData()))
                newjogos.push_back(convocatoria.at(x).getJogos().at(i));
        }
        convocatoria.at(x).setJogos(newjogos);
    }
}


//Ostreams
ostream& operator<<(ostream& out, Convocatoria& c) {
	out << " ID: " << c.getId() << endl;
	out << " Numero de Jogos: " << c.getNrJogos() << endl;
	out << " Data de inicio: " << c.getDataInicial() << endl;
	out << " Data de fim: " << c.getDataFinal() << endl;
	out << " Jogos: ";
	for (size_t x = 0; x < c.getJogos().size(); x++) {
		switch (x) {
		case 0:
			cout << "Portugal - " << c.getJogos().at(x).getAdversario() << " (" << c.getJogos().at(x).getData() << ")" << endl;
			break;
		default:
			cout << " " << setfill(' ') << setw(7) << " " << "Portugal - " << c.getJogos().at(x).getAdversario() << " (" << c.getJogos().at(x).getData() << ")" << endl;
		}
	}
	out << " Jogadores: ";
	unsigned int aux = 0;
	for (auto it : c.getCondicaoFisica()) {
		out << (it).first.getNome();
		if ((it).second == false)
			out << " (Lesionado)";
		if (aux != c.getCondicaoFisica().size())
			out << endl << " " << setfill(' ') << setw(11) << " ";
	}
	out << endl << " Equipa Tecnica: ";
	for (size_t x = 0; x < c.getEquipaTecnica().size(); x++) {
		out << c.getEquipaTecnica().at(x).getNome();
		if (x != c.getEquipaTecnica().size() - 1)
			out << endl << " " << setfill(' ') << setw(16) << " ";
	}
	out << endl;
	return out;
}