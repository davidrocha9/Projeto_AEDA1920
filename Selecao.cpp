#include "Selecao.h"
#include "Jogadores.h"
#include "Convocatoria.h"
#include "Utils.h"

#include <fstream>

using namespace std;

//////////////////////
/// Membro Selecao ///
//////////////////////

int BinarySearch(const vector<EquipaTecnica> &v, EquipaTecnica x) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v.at(mid) < x) left = mid + 1;
        else if (x < v.at(mid)) right = mid - 1;
        else return mid;
    }
    return -1;
}

//Construtores e Destrutores
Selecao::Selecao() : selecionadores(Selecionadores("",0)){
	Futebolista f;
	EquipaTecnica et;
	Convocatoria c;
	Jogo j;
	Fornecedores f1;
	Selecionadores s;
	jogadores = f.ReadJogadores();
	equipatecnica = et.ReadEquipaTecnica();
	jogos = j.ReadJogo();
	convocatorias = c.ReadConvocatoria(jogos);
	fornecedores = f1.ReadFornecedores();
	s.ReadSelecionadores(selecionadores);
}

Selecao::~Selecao(){}

  // metodos GET
vector<Futebolista> Selecao::getJogadores() const {
	return jogadores;
}

vector<EquipaTecnica> Selecao::getEquipaTecnica() const {
	return equipatecnica;
}

vector<Convocatoria> Selecao::getConvocatorias() const {
	return convocatorias;
}

vector<Jogo> Selecao::getJogos() const{
	return jogos;
}

priority_queue<Fornecedores> Selecao::getFornecedores() const {
    return fornecedores;
}


// metodos SET
void Selecao::JogadoresToFile(vector<Futebolista> vf){
	ofstream jogadoresfile;
    jogadoresfile.open("../jogadores.txt");

	if (jogadoresfile.fail())
		cerr << "Error Opening File" << endl;
	for (size_t x = 0; x < vf.size(); x++)
	{
		jogadoresfile << vf.at(x).getNome() << " | " << vf.at(x).getDataNascimento() << " | " << vf.at(x).getPosicao() << " | " << vf.at(x).getClube() << " | " << vf.at(x).getPeso() << " | " << vf.at(x).getAltura() << " | " << vf.at(x).getValorPasse();
		if (x != vf.size() - 1)
			jogadoresfile << endl;
		else
			continue;
	}
	jogadoresfile.close();
}

void Selecao::EquipaTecnicatoFile(vector<EquipaTecnica> et){
	ofstream etfile;
	etfile.open("../equipatecnica.txt");

	if (etfile.fail())
		cerr << "Error Opening File" << endl;
	for (size_t x = 0; x < et.size(); x++)
	{
		etfile << et.at(x).getNome() << " | " << et.at(x).getDataNascimento() << " | " << et.at(x).getFuncao() << " | " << et.at(x).getSalario() << " | ";
		if (et.at(x).getConhecido()) etfile << "1";
		else etfile << "0";
		if (x != et.size() - 1)
			etfile << endl;
		else
			continue;
	}
	etfile.close();
}

void Selecao::ConvocatoriatoFile(vector<Convocatoria> conv) {
	ofstream convfile;
	convfile.open("../convocatorias.txt");
	unsigned int auxconvocatoria = 0;
	unsigned int auxcnt = 0;

	if (convfile.fail())
		cerr << "Error Opening File" << endl;
	for (Convocatoria x : conv)
	{
		convfile << x.getId() << " | " << x.getNrJogos() << " | " << x.getCustoDiario() << " | " << x.getDataInicial() << " | " << x.getDataFinal() << " | " << x.getCompeticao() << endl;
		for (Jogo i : x.getJogos()) {
			convfile << i.getAdversario();
			if (auxcnt != x.getJogos().size() - 1)
				convfile << " | ";
			auxcnt++;
		}
		convfile << endl;
		auxcnt = 0;
		for (Jogo i : x.getJogos()) {
			convfile << i.getData();
			if (auxcnt != x.getJogos().size() - 1)
				convfile << " | ";
			auxcnt++;
		}
		convfile << endl;
		auxcnt = 0;
		for (auto it : x.getCondicaoFisica()){
			convfile << it.first.getNome();
			if (auxcnt != x.getJogadores().size()-1)
				convfile << " | ";
			auxcnt++;
		}
		convfile << endl;
		auxcnt = 0;
		for (auto it : x.getCondicaoFisica()) {
			convfile << it.first.getDataNascimento();
			if (auxcnt != x.getJogadores().size() - 1)
				convfile << " | ";
			auxcnt++;
		}
		convfile << endl;
		auxcnt = 0;
		for (auto it : x.getCondicaoFisica()) {
			if ((it).second == true)
				convfile << "0";
			else
				convfile << "1";
			if (auxcnt != x.getCondicaoFisica().size()-1)
				convfile << " | ";
			auxcnt++;
		}
		convfile << endl;
		auxcnt = 0;
		for (auto it : x.getDatasChegada()) {
			convfile << (it).second;
			if (auxcnt != x.getDatasChegada().size() - 1)
				convfile << " | ";
			auxcnt++;
		}
		convfile << endl;
		auxcnt = 0;
		for (auto it : x.getDatasPartida()) {
			convfile << (it).second;
			if (auxcnt != x.getCondicaoFisica().size() - 1)
				convfile << " | ";
			auxcnt++;
		}
		convfile << endl;
		auxcnt = 0;
		for (size_t z = 0; z < x.getEquipaTecnica().size(); z++) {
			convfile << x.getEquipaTecnica().at(z).getNome();
			if (z != x.getEquipaTecnica().size() - 1)
				convfile << " | ";
		}
		convfile << endl;
		for (size_t z = 0; z < x.getEquipaTecnica().size(); z++) {
			convfile << x.getEquipaTecnica().at(z).getDataNascimento();
			if (z != x.getEquipaTecnica().size() - 1)
				convfile << " | ";
		}
		if (auxconvocatoria != conv.size() - 1) {
            convfile << endl << "::::::::::" << endl;
        }
		auxconvocatoria++;
	}
	convfile.close();
}

void Selecao::JogostoFile(vector<Jogo> jogos){
	ofstream jogofile;
	jogofile.open("../Jogo.txt");
	unsigned int endofile = 0;
	unsigned int aux = 0;

	if (jogofile.fail())
		cerr << "Error Opening File" << endl;
	for (Jogo x : jogos) {
		jogofile << x.getData() << " | " << x.getAdversario() << " | " << x.getPais() << " | " << x.getCidade() << " | " << x.getEstadio() << endl;
		for (size_t i = 0; i < x.getJogadoresConvocados().size(); i++) {
			jogofile << x.getJogadoresConvocados().at(i).getNome();
			if (i != x.getJogadoresConvocados().size() - 1) {
				jogofile << " | ";
			}
		}
		jogofile << endl;
		for (size_t i = 0; i < x.getJogadoresConvocados().size(); i++) {
			jogofile << x.getJogadoresConvocados().at(i).getDataNascimento();
			if (i != x.getJogadoresConvocados().size() - 1)
				jogofile << " | ";
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getGolos()) {
			jogofile << i.first.getNome();
			if (aux != x.getGolos().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getGolos()) {
			jogofile << i.first.getDataNascimento();
			if (aux != x.getGolos().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		for (size_t i = 0; i < x.getEquipaArbitragem().size(); i++) {
			jogofile << x.getEquipaArbitragem().at(i);
			if (i != x.getEquipaArbitragem().size() - 1)
				jogofile << " | ";
		}
		jogofile << endl;
		for (size_t i = 0; i < x.getEquipaAdversaria().size(); i++) {
			jogofile << x.getEquipaAdversaria().at(i);
			if (i != x.getEquipaAdversaria().size() - 1)
				jogofile << " | ";
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getGolos()) {
			jogofile << i.second;
			if (aux != x.getGolos().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getAssists()) {
			jogofile << i.second;
			if (aux != x.getAssists().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getPasses()) {
			jogofile << i.second;
			if (aux != x.getPasses().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getPassesAcertados()) {
			jogofile << i.second;
			if (aux != x.getPassesAcertados().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getDesarmes()) {
			jogofile << i.second;
			if (aux != x.getDesarmes().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getFaltas()) {
			jogofile << i.second;
			if (aux != x.getFaltas().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getKmPercorridos()) {
			jogofile << i.second;
			if (aux != x.getKmPercorridos().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getMinutosJogados()) {
			jogofile << i.second;
			if (aux != x.getMinutosJogados().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getAmarelos()) {
			jogofile << i.second;
			if (aux != x.getAmarelos().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		jogofile << endl;
		aux = 0;
		for (auto i : x.getVermelhos()) {
			jogofile << i.second;
			if (aux != x.getVermelhos().size() - 1) {
				jogofile << " | ";
				aux++;
			}
		}
		aux = 0;
		jogofile << endl;
		for (size_t i = 0; i < x.getLesao().size(); i++){
			jogofile << x.getLesao().at(i).getNome();
			if (i != x.getLesao().size() - 1) {
				jogofile << " | ";
			}
		}
		jogofile << endl;
		for (size_t i = 0; i < x.getLesao().size(); i++) {
			jogofile << x.getLesao().at(i).getDataNascimento();
			if (i != x.getLesao().size() - 1) {
				jogofile << " | ";
			}
		}
		if (endofile != jogos.size() - 1)
			jogofile << endl << "::::::::::" << endl;
		endofile++;
	}
	jogofile.close();
}

void Selecao::FornecedorestoFile(priority_queue<Fornecedores> fornecedores){
    ofstream fornecedoresfile;
    fornecedoresfile.open("../fornecedores.txt");

    if (fornecedoresfile.fail())
        cerr << "Error Opening File" << endl;
    int x = 0;
    priority_queue<Fornecedores> aux = fornecedores;
    while(!aux.empty()){
        Fornecedores f = aux.top();
        fornecedoresfile << f.getNome() << endl << f.getReputacao() << endl << f.getReviews() << endl;
        vector<Equipamentos> eq = f.getEquipamentos();
        for (size_t x = 0; x < eq.size(); x++){
            fornecedoresfile << eq.at(x).getTipo();
            if (x != eq.size() - 1)
                fornecedoresfile << " | ";
        }
        fornecedoresfile << endl;
        for (size_t x = 0; x < eq.size(); x++){
            fornecedoresfile << eq.at(x).getPreco();
            if (x != eq.size() - 1)
                fornecedoresfile << " | ";
        }
        x++;
        if (x != fornecedores.size())
            fornecedoresfile << endl << "::::::::::" << endl;
        aux.pop();
    }
    fornecedoresfile.close();
}

void Selecao::SelecionadorestoFile(BST<Selecionadores> selecionadores){
    ofstream selecionadoresfile;
    selecionadoresfile.open("../selecionadores.txt");
    int size = 0;
    BSTItrIn<Selecionadores> it(selecionadores);
    while(!it.isAtEnd()){
        size++;
        it.advance();
    }
    if (selecionadoresfile.fail())
        cerr << "Error Opening File" << endl;
    int x = 1;
    BSTItrIn<Selecionadores> it2(selecionadores);
    while(!it2.isAtEnd()){
        selecionadoresfile << it2.retrieve().getNome() << " | " << it2.retrieve().getDataNascimento() << " | " << it2.retrieve().getSalario() << " | " << it2.retrieve().getTitulosGanhos() << endl;
        vector<unsigned int> v1 = it2.retrieve().getSelecoes();
        if (v1.empty())
            selecionadoresfile << "0";
        for (size_t y = 0; y < v1.size(); y++){
            selecionadoresfile << v1.at(y);
            if (y < v1.size()-1)
                selecionadoresfile << " | ";
        }
        if (x < size)
            selecionadoresfile << endl;
        x++;
        it2.advance();
    }
    selecionadoresfile.close();
}

BST<Selecionadores> Selecao::getSelecionadores() const {
    return selecionadores;
}

void Selecao::updateSelecionadores(BST<Selecionadores> &selecionadores, Convocatoria c) {
    BSTItrIn<Selecionadores> it(selecionadores);
    vector<Selecionadores> v;
    bool pass = false;
    while(!it.isAtEnd()){
        if(it.retrieve().getNome() == c.getSelecionador()){
            pass = true;
            vector<unsigned int> v1 = it.retrieve().getSelecoes();
            v1.push_back(c.getId());
            it.retrieve().setSelecoes(v1);
        }
        it.advance();
    }
}

HTFuncionariosRecord Selecao::getFuncionariosRecord() {
    return funcRec;
}

void Selecao::setFuncionariosRecord(HTFuncionariosRecord h) {
    funcRec = h;
}

HTFuncionariosRecord Selecao::generateRecords(vector<EquipaTecnica> et) {
    for (auto x: et){
        if (x.getConhecido())
            funcRec.insert(x);
    }
    return funcRec;
}

void Selecao::InformacoesFuncionariosConvocatoria(vector<Convocatoria> c, HTFuncionariosRecord ht){
    Convocatoria conv = c.back();
    for (size_t x = 0; x < conv.getEquipaTecnica().size(); x++){
        cout << conv.getEquipaTecnica().at(x);
        if (x < conv.getEquipaTecnica().size() - 1)
            cout << endl << endl << "----------------------" << endl << endl;
    }
}

void Selecao::InformacoesFuncionariosConhecidos(HTFuncionariosRecord ht) {
    int x = 0, size = ht.size();
    for (auto it = ht.begin(); it != ht.end(); it++){
        cout << *it;
        if (x < size -1)
            cout << endl << endl << "----------------------" << endl << endl;
        x++;
    }
}

void Selecao::ContratarFuncionario(vector<Convocatoria> &c, HTFuncionariosRecord ht, vector<EquipaTecnica> &et) {
    Convocatoria conv = c.back();
    cout << " Qual a funcao do funcionario a contratar?" << endl;
    std::cout << " Funcoes disponiveis: " << endl << endl;
    std::cout << "   1 - Selecionador Nacional" << endl;
    std::cout << "   2 - Diretor" << endl;
    std::cout << "   3 - Treinador Nacional" << endl;
    std::cout << "   4 - Treinador Nacional de Guarda-Redes" << endl;
    std::cout << "   5 - Preparador Fisico" << endl;
    std::cout << "   6 - Medico Principal" << endl;
    std::cout << "   7 - Departamento Medico" << endl;
    std::cout << "   8 - Funcionario Tecnico" << endl << endl;
    unsigned opt = 0;
    do {
        cout << endl << "Introduza uma opcao: ";
        cin.clear();
        std::cin >> opt;
        if (opt < 1 || opt > 8 || cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Input invalido! Introduza um numero entre 1 e 8";
        }
    } while (opt < 1 || opt > 8 || cin.fail());

    vector<EquipaTecnica> funcionariosacontratar;
    system("cls"); logo();
    string f;
    int aux = 0, index = 0;
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

    cout << " Lista de Funcionarios disponiveis para esta funcao: " << endl << endl;
    cout << " ";
    for (auto x: ht) {
        if (x.getFuncao() == f && BinarySearch(equipatecnica, x) != -1) {
            cout << "[" << index + 1 << "]" << setfill(' ') << setw(18) << x.getNome() << "   ";
            funcionariosacontratar.push_back(x);
            index++;
            aux++;
        }
        if (aux == 2) {
            aux = -1;
            cout << endl << " ";
        }
    }
    if (index > 0) {
        do {
            cout << endl << "Introduza uma opcao: ";
            cin.clear();
            std::cin >> opt;
            if (opt < 1 || opt > funcionariosacontratar.size()) {
                cin.clear();
                cin.ignore();
                cout << "Input invalido! Introduza um numero entre 1 e " << funcionariosacontratar.size();
            }
        } while (opt < 1 || opt > funcionariosacontratar.size() || cin.fail());
    }
    else{
        //cout << "Nao existem funcionarios conhecidos para esta funcao! A listagem corresponde a funcionarios desconhecidos." << endl << endl << " ";
        aux = 0;
        for (auto x: et) {
            if (x.getFuncao() == f && !x.getConhecido()) {
                cout << "[" << index + 1 << "]" << setfill(' ') << setw(18) << x.getNome() << "   ";
                funcionariosacontratar.push_back(x);
                index++;
                aux++;
            }
            if (aux == 2) {
                aux = -1;
                cout << endl << " ";
            }
        }
        if (index == 0) {
            throw FuncionarioNaoExistente(f);
        }
        cout << endl << endl << " Nao existem funcionarios conhecidos para esta funcao! A listagem corresponde a funcionarios desconhecidos." << endl << endl << " ";
        do {
            cout << endl << endl << "Introduza uma opcao: ";
            cin.clear();
            std::cin >> opt;
            if (opt < 1 || opt > funcionariosacontratar.size()) {
                cin.clear();
                cin.ignore();
                cout << "Input invalido! Introduza um numero entre 1 e " << funcionariosacontratar.size();
            }
        } while (opt < 1 || opt > funcionariosacontratar.size() || cin.fail());

        bool found = false;
        for (auto x: conv.getEquipaTecnica()){
            if (x == funcionariosacontratar.at(opt-1)) {
                found = true;
                break;
            }
        }
        if (!found){
            vector<EquipaTecnica> v = conv.getEquipaTecnica();
            v.push_back(funcionariosacontratar.at(opt-1));
            c.back().setEquipaTecnica(v);
            EquipaTecnica newet;
            vector<EquipaTecnica> v1;
            for (auto x: et){
                if (x == funcionariosacontratar.at(opt-1)) {
                    x.setConhecido(true);
                    newet = x;
                } else v1.push_back(x);
            }
            v1.push_back(newet);
            et = v1;
            cout << endl <<  " Funcionario contratado com sucesso!" << endl << endl;
        }
    }
}