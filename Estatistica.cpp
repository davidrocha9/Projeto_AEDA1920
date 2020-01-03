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
#include "Date.h"

using namespace std;

void EstatisticaJogador(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatoria) {
    string line;
    Futebolista nome;
    vector<unsigned int> ids_convo;
    vector<string> ids_jogos;
    vector<Date> ids_jogosdata;
    vector<unsigned int> stats;

    vector<string> nomes;
    string nome1;
    std::cout << " Lista de jogadores disponiveis: " << endl << endl;
    int aux = 0;
    std::cout << " ";
    for (size_t x = 0; x < jogadores.size(); x++) {
        nome1 = jogadores.at(x).getNome();
        nomes = nameSplitter(nome1);
        if (nomes.size() > 2) {
            nome1 = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
            std::cout << "[" << x + 1 << "]" << setw(18) << nome1 << "   ";
        }
        else
            std::cout << "[" << x + 1 << "]" << setw(18) << jogadores.at(x).getNome() << "   ";
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    std::cout << endl;
    unsigned int opt = 0;
    do {
        cout << "Introduza uma opcao: "; cin >> opt;
    } while (opt < 1 && opt > jogadores.size());
    nome = jogadores.at(opt - 1);

    system("cls"); logo();
    cout << " Jogador Selecionado: " << nome.getNome() << endl << endl;
    int num;
    std::cout << endl;
    std::cout << " 1 - Voltar atras\n 2 - Informacao Geral\n 3 - Informacao por jogo\n" << endl;
    do {
        std::cout << "Introduza uma opcao: "; cin >> num;
        if (num < 1 || num > 3)
            std::cout << "Invalid number. Choose another number!" << endl;
    } while (num < 1 || num > 3);

    multimap<Futebolista, unsigned int> m1;
    multimap<Futebolista, double> m2;

    double pas = 0;
    double pasacert = 0;
    double percentpass;
    int golos = 0;
    int assists = 0;
    int amarelos = 0;
    int vermelhos = 0;
    int faltas = 0;
    int desarmes = 0;
    double kiloms = 0.0;
    int minutos = 0;
    int cont = 0;

    system("cls"); logo();
    cout << " Jogador Selecionado: " << nome.getNome() << endl << endl;
    switch (num) {
        case(1): EstatisticaJogador(jogadores, jogos, convocatoria);
            break;
        case(2):
            for (size_t x = 0; x < convocatoria.size(); x++) {
                for (size_t i = 0; i < convocatoria.at(x).getJogadores().size(); i++) {
                    if (nome.getNome() == convocatoria.at(x).getJogadores().at(i).getNome()) {
                        ids_convo.push_back(convocatoria.at(x).getId());
                    }
                }
            }
            if (ids_convo.size() == 0) {
                cout << "Jogador sem nenhuma convocatoria" << endl;
                break;
            }
            else {
                cout << " Convocatorias: ";
                for (int j = 0; j < ids_convo.size(); j++)
                    cout << ids_convo.at(j);
                cout << endl;
            }


            for (size_t x = 0; x < jogos.size(); x++) {
                for (size_t i = 0; i < jogos.at(x).getJogadoresParticipantes().size(); i++) {
                    if (nome.getNome() == jogos.at(x).getJogadoresParticipantes().at(i).getNome()) {
                        cont += 1;
                        m1 = jogos.at(x).getGolos();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                golos += z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getAssists();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                assists += z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getPasses();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                pas += z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getPassesAcertados();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                pasacert += z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getDesarmes();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                desarmes += z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getFaltas();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                faltas += z.second;
                                break;
                            }
                        }
                        m2 = jogos.at(x).getKmPercorridos();
                        for (auto z : m2) {
                            if (z.first == nome) {
                                kiloms += z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getMinutosJogados();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                minutos += z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getAmarelos();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                amarelos += z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getVermelhos();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                vermelhos += z.second;
                                break;
                            }
                        }
                    }
                }
            }
            if (cont == 0)
                cout << "Jogador sem jogos realizados" << endl << endl;
            else {
                cout << " Jogos realizados: " << cont << endl;
                cout << " Golos: " << golos << endl;
                cout << " Assistencias: " << assists << endl;
                cout << " Passes: " << pas << endl;
                cout << " Passes Acertados: " << pasacert << endl;
                cout << " Precisao de Passe (%): " << (double((pasacert / pas)) * 100) << endl;
                cout << " Desarmes: " << desarmes << endl;
                cout << " Faltas: " << faltas << endl;
                cout << " Kilometros: " << kiloms << endl;
                cout << " Minutos: " << minutos << endl;
                cout << " Amarelos: " << amarelos << endl;
                cout << " Vermelhos: " << vermelhos << endl;
                cout << endl;
            }

            break;
        case(3):
            for (size_t x = 0; x < convocatoria.size(); x++) {
                for (size_t i = 0; i < convocatoria.at(x).getJogadores().size(); i++) {
                    if (nome.getNome() == convocatoria.at(x).getJogadores().at(i).getNome()) {
                        ids_convo.push_back(convocatoria.at(x).getId());
                    }
                }
            }
            if (ids_convo.size() == 0)
                cout << "Jogador sem nenhuma convocatoria" << endl;
            else {
                cout << " Convocatorias: ";
                for (int j = 0; j < ids_convo.size(); j++)
                    cout << ids_convo.at(j);
                cout << endl;
            }

            multimap<Futebolista, unsigned int> m1;
            multimap<Futebolista, double> m2;

            int passes;
            int passesacert;
            vector<double> kms;

            for (size_t x = 0; x < jogos.size(); x++) {
                for (size_t i = 0; i < jogos.at(x).getJogadoresParticipantes().size(); i++) {
                    if (nome.getNome() == jogos.at(x).getJogadoresParticipantes().at(i).getNome()) {
                        ids_jogos.push_back(jogos.at(x).getAdversario());
                        ids_jogosdata.push_back(jogos.at(x).getData());
                        m1 = jogos.at(x).getGolos();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                break;
                            }
                        }
                        m1 = jogos.at(x).getAssists();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                break;
                            }
                        }
                        m1 = jogos.at(x).getPasses();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                passes = z.second;
                                break;
                            }
                        }
                        m1 = jogos.at(x).getPassesAcertados();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                passesacert = z.second;
                                break;
                            }
                        }
                        stats.push_back((passesacert / passes) * 100);
                        m1 = jogos.at(x).getDesarmes();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                break;
                            }
                        }
                        m1 = jogos.at(x).getFaltas();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                break;
                            }
                        }
                        m2 = jogos.at(x).getKmPercorridos();
                        for (auto z : m2) {
                            if (z.first == nome) {
                                kms.push_back(z.second);
                                break;
                            }
                        }
                        m1 = jogos.at(x).getMinutosJogados();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                break;
                            }
                        }
                        m1 = jogos.at(x).getAmarelos();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                break;
                            }
                        }
                        m1 = jogos.at(x).getVermelhos();
                        for (auto z : m1) {
                            if (z.first == nome) {
                                stats.push_back(z.second);
                                break;
                            }
                        }
                    }
                }
            }
            double b;
            double c;
            if (ids_jogos.size() == 0)
                std::cout << "Jogador sem jogos realizados" << endl << endl;
            else {
                std::cout << " Jogos realizados:" << endl << endl;
                for (size_t x = 0; x < ids_jogos.size(); x++) {
                    std::cout << "   [" << x + 1 << "] " << ids_jogos.at(x) << " (" << ids_jogosdata.at(x) << ")" << endl;
                }
                cout << endl;
                do {
                    std::cout << "Introduza uma opcao: "; cin >> opt;
                } while (opt < 1 && opt > jogos.size());


                int i = opt-1;
                int a = opt-1;
                system("cls"); logo();
                cout << " Jogador Selecionado: " << nome.getNome() << endl << endl;
                cout << " Golos: " << stats.at(i) << endl; i++;
                cout << " Assistencias: " << stats.at(i) << endl; i++;
                cout << " Passes: " << stats.at(i) << endl; b = double(stats.at(i)); i++;
                cout << " Passes Acertados: " << stats.at(i) << endl; c = double(stats.at(i)); i++; i++;
                cout << " Precisao de Passe: " << (c / b) * 100 << endl;
                cout << " Desarmes: " << stats.at(i) << endl; i++;
                cout << " Faltas: " << stats.at(i) << endl; i++;
                cout << " Kilometros: " << kms.at(a) << endl; a++;
                cout << " Minutos: " << stats.at(i) << endl; i++;
                cout << " Amarelos: " << stats.at(i) << endl; i++;
                cout << " Vermelhos: " << stats.at(i) << endl; i++;
                cout << endl;
            }
            break;
    }
}

void EstatisticaSelecao(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatoria) {
    string line;
    Futebolista nome;
    vector<unsigned int> ids_convo;
    vector<string> ids_jogos;
    vector<Date> ids_jogosdata;
    vector<unsigned int> stats;

    multimap<Futebolista, unsigned int> m1;
    multimap<Futebolista, double> m2;

    double pas = 0;
    double pasacert = 0;
    double percentpass;
    int golos = 0;
    int assists = 0;
    int amarelos = 0;
    int vermelhos = 0;
    int faltas = 0;
    int desarmes = 0;
    double kiloms = 0.0;
    int minutos = 0;
    int cont = 0;
    int conv = 0;

    for (size_t x = 0; x < convocatoria.size(); x++) {
        conv += 1;
    }
    std::cout << "Convocatorias: ";
    std::cout << conv;
    std::cout << endl << endl;

    for (size_t x = 0; x < jogos.size(); x++) {
        for (size_t i = 0; i < jogos.at(x).getJogadoresParticipantes().size(); i++) {
            cont += 1;
            m1 = jogos.at(x).getGolos();
            for (auto z : m1) {
                golos += z.second;
            }
            m1 = jogos.at(x).getAssists();
            for (auto z : m1) {
                assists += z.second;
            }
            m1 = jogos.at(x).getPasses();
            for (auto z : m1) {
                pas += z.second;
            }
            m1 = jogos.at(x).getPassesAcertados();
            for (auto z : m1) {
                pasacert += z.second;
            }
            m1 = jogos.at(x).getDesarmes();
            for (auto z : m1) {
                desarmes += z.second;
            }
            m1 = jogos.at(x).getFaltas();
            for (auto z : m1) {
                faltas += z.second;
            }
            m2 = jogos.at(x).getKmPercorridos();
            for (auto z : m2) {
                kiloms += z.second;
            }
            m1 = jogos.at(x).getMinutosJogados();
            for (auto z : m1) {
                minutos += z.second;
            }
            m1 = jogos.at(x).getAmarelos();
            for (auto z : m1) {
                amarelos += z.second;
            }
            m1 = jogos.at(x).getVermelhos();
            for (auto z : m1) {
                vermelhos += z.second;
            }
            break;
        }
    }
    std::cout << "Jogos realizados: " << cont << endl << endl;
    std::cout << "Golos: " << golos << endl;
    std::cout << "Assistencias: " << assists << endl;
    std::cout << "Passes: " << pas << endl;
    std::cout << "Passes Acertados: " << pasacert << endl;
    std::cout << "Precisao de Passe: " << (double((pasacert / pas)) * 100) << endl;
    std::cout << "Desarmes: " << desarmes << endl;
    std::cout << "Faltas: " << faltas << endl;
    std::cout << "Kilometros: " << kiloms << endl;
    std::cout << "Minutos: " << minutos << endl;
    std::cout << "Amarelos: " << amarelos << endl;
    std::cout << "Vermelhos: " << vermelhos << endl;
    std::cout << endl;

}

void CustoIndvMes(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatoria) {
    int ano;
    int mes;
    bool checkano = true;
    bool checkmes = true;
    double salario = 0.0;
    int count = 0;
    Futebolista nome;
    string line;
    vector<bool> cond;

    int ip = 1;
    unsigned int aux = 0;
    cin.ignore();
    cin.clear();
    cout << " ";
    vector<string> nomes;
    string nome1;
    std::cout << " Lista de jogadores disponiveis: " << endl << endl;
    std::cout << " ";
    for (size_t x = 0; x < jogadores.size(); x++) {
        nome1 = jogadores.at(x).getNome();
        nomes = nameSplitter(nome1);
        if (nomes.size() > 2) {
            nome1 = nomes.at(0) + " " + nomes.at(nomes.size() - 1);
            std::cout << "[" << x + 1 << "]" << setw(18) << nome1 << "   ";
        }
        else
            std::cout << "[" << x + 1 << "]" << setw(18) << jogadores.at(x).getNome() << "   ";
        if (aux == 2) {
            aux = -1;
            std::cout << endl << " ";
        }
        aux++;
    }
    std::cout << endl;
    unsigned int opt = 0;
    do {
        cout << "Introduza uma opcao: "; cin >> opt;
    } while (opt < 1 && opt > jogadores.size());
    nome = jogadores.at(opt - 1);
    cout << endl;
    nome = jogadores.at(stoi(line) - 1);

    while (checkano) {
        cout << " Ano que pretende consultar: ";
        cin >> ano;
        cout << endl << endl;
        if (ano > 2019 || ano < 0) {
            cout << "Ano invalido! " << endl << endl;
            checkano = true;
        }
        else {
            checkano = false;
        }
    }
    while (checkmes) {
        cout << " Mes que pretende consultar: ";
        cin >> mes;
        cout << endl << endl;
        if (mes > 12 || mes < 1) {
            cout << "Mes invalido! " << endl << endl;
            checkmes = true;
        }
        else {
            checkmes = false;
        }
    }

    multimap<Futebolista, bool> m1;

    for (int x = 0; x < convocatoria.size(); x++) {
        if (convocatoria.at(x).getDataInicial().getAno() == ano || convocatoria.at(x).getDataFinal().getAno() == ano) {
            if (mes >= convocatoria.at(x).getDataInicial().getMes() && mes <= convocatoria.at(x).getDataFinal().getMes()) {
                for (int j = 0; j < convocatoria.at(x).getJogadores().size(); j++) {
                    if (convocatoria.at(x).getJogadores().at(j).getNome() == nome.getNome()) {
                        for (int m = 0; m < jogadores.size(); m++) {
                            if (nome.getNome() == jogadores.at(m).getNome()) {
                                count += 1;
                                m1 = convocatoria.at(x).getCondicaoFisica();
                                for (auto z : m1) {
                                    if (z.first == nome) {
                                        if (z.second == 1) {
                                            salario += (double(jogadores.at(m).getValorPasse()) / 400.0);
                                            salario += double(convocatoria.at(x).getCustoDiario() * 30.0);
                                        }
                                        else {
                                            salario += (double(jogadores.at(m).getValorPasse()) / 1200.0);
                                            salario += double(convocatoria.at(x).getCustoDiario() * 30.0);
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else break;
        }
        else break;
    }

    if (count != 0) {
        cout << " Custos do jogador: " << salario << endl << endl;
    }
    else {
        cout << " Jogador sem participacoes nessa data!" << endl << endl;
    }
}

void CustoGeralMesEquip(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatoria, vector<EquipaTecnica>& equipatecnica) {
    int ano;
    int mes;
    bool checkano = true;
    bool checkmes = true;
    double salario = 0.0;
    int count = 0;
    string line;
    vector<bool> cond;
    multimap<Futebolista, bool> m1;

    while (checkano) {
        std::cout << "Ano que pretende consultar: ";
        cin >> ano;
        std::cout << endl << endl;
        if (ano > 2019 || ano < 0) {
            std::cout << "Ano invalido! " << endl << endl;
            checkano = true;
        }
        else {
            checkano = false;
        }
    }
    while (checkmes) {
        std::cout << "Mes que pretende consultar: ";
        cin >> mes;
        std::cout << endl << endl;
        if (mes > 12 || mes < 1) {
            std::cout << "Mes invalido! " << endl << endl;
            checkmes = true;
        }
        else {
            checkmes = false;
        }
    }

    for (int x = 0; x < convocatoria.size(); x++) {
        if (convocatoria.at(x).getDataInicial().getAno() == ano || convocatoria.at(x).getDataFinal().getAno() == ano) {
            if (mes >= convocatoria.at(x).getDataInicial().getMes() && mes <= convocatoria.at(x).getDataFinal().getMes()) {
                for (int j = 0; j < convocatoria.at(x).getJogadores().size(); j++) {
                    for (int m = 0; m < jogadores.size(); m++) {
                        if (convocatoria.at(x).getJogadores().at(j).getNome() == jogadores.at(m).getNome()) {
                            count += 1;
                            m1 = convocatoria.at(x).getCondicaoFisica();
                            for (auto z : m1) {
                                if (z.first == jogadores.at(m)) {
                                    if (z.second == 1) {
                                        salario += (double(jogadores.at(m).getValorPasse()) / 400.0);
                                        salario += double(convocatoria.at(x).getCustoDiario() * 30);
                                    }
                                    else {
                                        salario += (double(jogadores.at(m).getValorPasse()) / 1200.0);
                                        salario += double(convocatoria.at(x).getCustoDiario() * 30);
                                    }
                                    break;
                                }
                            }

                        }

                    }
                }
                for (int k = 0; k < convocatoria.at(x).getEquipaTecnica().size(); k++) {
                    salario += (double(equipatecnica.at(k).getSalario()));
                    salario += double(convocatoria.at(x).getCustoDiario() * 30);
                }
            }
            else break;
        }
        else break;
    }

    if (count != 0) {
        std::cout << "Custos da Equipa: " << salario << endl << endl;
    }
    else {
        std::cout << "Sem convocatorias nessa data !" << endl << endl;
    }
}

void CustoGeralMesTudo(vector<Futebolista>& jogadores, vector<Jogo>& jogos, vector<Convocatoria>& convocatoria, vector<EquipaTecnica>& equipatecnica) {
    int ano;
    int mes;
    bool checkano = true;
    bool checkmes = true;
    double salario = 0.0;
    int count = 0;
    string line;
    vector<bool> cond;
    multimap<Futebolista, bool> m1;

    while (checkano) {
        cout << "Ano que pretende consultar: ";
        cin >> ano;
        cout << endl << endl;
        if (ano > 2019 || ano < 0) {
            cout << "Ano invalido! " << endl << endl;
            checkano = true;
        }
        else {
            checkano = false;
        }
    }
    while (checkmes) {
        cout << "Mes que pretende consultar: ";
        cin >> mes;
        cout << endl << endl;
        if (mes > 12 || mes < 1) {
            cout << "Mes invalido! " << endl << endl;
            checkmes = true;
        }
        else {
            checkmes = false;
        }
    }

    for (int x = 0; x < convocatoria.size(); x++) {
        if (convocatoria.at(x).getDataInicial().getAno() == ano || convocatoria.at(x).getDataFinal().getAno() == ano) {
            if (mes >= convocatoria.at(x).getDataInicial().getMes() && mes <= convocatoria.at(x).getDataFinal().getMes()) {
                for (int j = 0; j < convocatoria.at(x).getJogadores().size(); j++) {
                    for (int m = 0; m < jogadores.size(); m++) {
                        if (convocatoria.at(x).getJogadores().at(j).getNome() == jogadores.at(m).getNome()) {
                            count += 1;
                            m1 = convocatoria.at(x).getCondicaoFisica();
                            for (auto z : m1) {
                                if (z.first == jogadores.at(m)) {
                                    if (z.second == 1) {
                                        salario += (double(jogadores.at(m).getValorPasse()) / 400.0);
                                        salario += double(convocatoria.at(x).getCustoDiario() * 30.0);
                                    }
                                    else {
                                        salario += (double(jogadores.at(m).getValorPasse()) / 1200.0);
                                        salario += double(convocatoria.at(x).getCustoDiario() * 30.0);
                                    }
                                    break;
                                }
                            }

                        }

                    }
                }
                for (int k = 0; k < convocatoria.at(x).getEquipaTecnica().size(); k++) {
                    for (int o = 0; o < equipatecnica.size(); o++) {
                        if (equipatecnica.at(o).getNome() == convocatoria.at(x).getEquipaTecnica().at(k).getNome()) {
                            salario += (double(equipatecnica.at(k).getSalario()));
                            salario += double(convocatoria.at(x).getCustoDiario() * 30.0);
                        }
                    }
                }
            }
            else break;
        }
        else break;
    }

    if (count != 0) {
        cout << "Custos da Equipa: " << salario << endl << endl;
    }
    else {
        cout << "Sem convocatorias nessa data !" << endl << endl;
    }
}