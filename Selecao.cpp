    #include "Selecao.h"
#include "Jogadores.h"
#include "Convocatoria.h"

#include <fstream>

using namespace std;

////////////////////
// Membro Selecao //
////////////////////


//Construtores e Destrutores
Selecao::Selecao() {
	Futebolista f;
	EquipaTecnica et;
	Convocatoria c;
	Jogo j;
	Fornecedores f1;
	jogadores = f.ReadJogadores();
	equipatecnica = et.ReadEquipaTecnica();
	jogos = j.ReadJogo();
	convocatorias = c.ReadConvocatoria(jogos);
	fornecedores = f1.ReadFornecedores();
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
		etfile << et.at(x).getNome() << " | " << et.at(x).getDataNascimento() << " | " << et.at(x).getFuncao() << " | " << et.at(x).getSalario();
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
		if (auxconvocatoria != conv.size() - 1)
			convfile << endl;
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
			jogofile << endl;
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