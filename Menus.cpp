#include "Menus.h"
#include "Jogadores.h"
#include "Convocatoria.h"
#include "Jogo.h"
#include "Utils.h"
#include "Estatistica.h"
#include "Equipamentos.h"
#include <iomanip>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

bool changeReturn(bool& return_menu) {
    string n;
    //cin.ignore(1000, '\n');
    std::cout << endl << endl << "Deseja realizar mais alguma operacao? (S/N)" << endl;
    do {
        std::cout << "Introduza uma opcao: ";
        cin.clear();
        cin >> n;
        if (n != "S" && n != "s" && n != "N" && n != "n" || cin.fail()){
            cin.clear();
            cin.ignore();
            std::cout << " Opcao invalida! Tente Novamente." << endl;
        }
    } while (n != "S" && n != "s" && n != "N" && n != "n");

    if (n == "N" || n == "n")
        return_menu = false;
    return return_menu;
}

bool maisgolos(JogadorFama f1, JogadorFama f2){
    return f1.golos > f2.golos;
}

bool maisassists(JogadorFama f1, JogadorFama f2){
    return f1.assists > f2.assists;
}

bool maisjogos(JogadorFama f1, JogadorFama f2){
    return f1.jogos > f2.jogos;
}

void mainMenu(Selecao& selecao) {
    bool return_menu = true;
    Futebolista f1;
    EquipaTecnica et1, ettemp;
    Selecionadores s1, stemp;
    Convocatoria c1;
    Jogo j1, j;
    Fornecedores for1;
    vector<MembroSelecao> membros;
    vector<Futebolista> jogadores = selecao.getJogadores();
    vector<EquipaTecnica> equipatecnica = selecao.getEquipaTecnica();
    vector<Convocatoria> convocatorias = selecao.getConvocatorias();
    for (auto x: jogadores)
        membros.push_back(x);
    for (auto x: equipatecnica)
        membros.push_back(x);
    vector<Jogo> jogos = selecao.getJogos();
    priority_queue<Fornecedores> fornecedores = selecao.getFornecedores();
    BST<Selecionadores> selecionadores = selecao.getSelecionadores();
    HTFuncionariosRecord funcRec = selecao.generateRecords(equipatecnica);
    BSTItrIn<Selecionadores> it(selecionadores);
    Convocatoria c;
    string nometemp = "";
    BSTItrIn<Selecionadores> it2(selecionadores);

    BSTItrLevel<Selecionadores> itnivel(selecionadores);
    BSTItrPre<Selecionadores> itpre(selecionadores);
    BSTItrPost<Selecionadores> itpost(selecionadores);

    int size = 0, index = 0;
    do {
        logo();
        cout << " 1 - Gerir Jogadores" << endl;
        cout << " 2 - Gerir Equipa Tecnica " << endl;
        cout << " 3 - Gerir Convocatorias" << endl;
        cout << " 4 - Gerir Jogos" << endl;
        cout << " 5 - Estatisicas da Selecao" << endl;
        cout << " 6 - Venda de Equipamentos" << endl;
        cout << " 7 - Pesquisa de Selecionadores" << endl;
        cout << " 8 - Contratar Funcionarios" << endl;
        cout << " 9 - Corredor da Fama" << setfill(' ') << setw(40) << "Numero de membros atualmente: " << membros.size() << endl;
        unsigned int opt = 0;
        cout << endl;
        do {
            cout << "Introduza uma opcao: "; cin >> opt;
            if (opt < 1 || opt > 9 || cin.fail()) {
                cin.clear();
                cout << "Opcao invalida! Introduza um numero entre 1 e 9." << endl;
                cin.ignore(1000, '\n');
            }
        } while (opt < 1 || opt > 9 || cin.fail());
        cin.ignore(1000, '\n');

        switch (opt) {
            case 1:
                system("cls");
                logo();
                cout << " 1 - Informacoes sobre os jogadores" << endl;
                cout << " 2 - Adicionar um jogador " << endl;
                cout << " 3 - Remover um jogador" << endl;
                cout << " 4 - Editar um jogador" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: ";
                    cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                switch (opt) {
                    case (1):
                        system("cls");
                        logo();
                        f1.InformacoesJogador(jogadores);
                        break;
                    case (2):
                        system("cls");
                        logo();
                        try {
                            f1.AdicionarJogador(jogadores);
                        }
                        catch (JogadorJaExistente j) {
                            cout << endl << "Ja existe um jogador com este nome e data de nascimento!";
                        }
                        selecao.JogadoresToFile(jogadores);
                        break;
                    case (3):
                        system("cls");
                        logo();
                        f1.RemoverJogador(jogadores);
                        selecao.JogadoresToFile(jogadores);
                        break;
                    case (4):
                        system("cls");
                        logo();
                        f1.EditarJogador(jogadores);
                        selecao.JogadoresToFile(jogadores);
                        break;
                    case (5):
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 2:
                system("cls");
                logo();
                cout << " 1 - Informacoes sobre os Membros Tecnicos" << endl;
                cout << " 2 - Adicionar um Membro Tecnico " << endl;
                cout << " 3 - Remover um Membro Tecnico" << endl;
                cout << " 4 - Editar um Membro Tecnico" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: ";
                    cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                switch (opt) {
                    case (1):
                        system("cls");
                        logo();
                        nometemp = et1.InformacoesTecnico(equipatecnica);
                        while (!it2.isAtEnd()) {
                            if (it2.retrieve().getNome() == nometemp) {
                                cout << endl << " Numero de titulos ganhos: " << it2.retrieve().getTitulosGanhos();
                                break;
                            }
                            it2.advance();
                        }
                        break;
                    case (2):
                        system("cls");
                        logo();
                        try {
                            ettemp = et1.AdicionarTecnico(equipatecnica);
                        }
                        catch (MembroTecnicoJaExistente mt) {
                            cout << endl << "Ja existe um membro tecnico com este nome e data de nascimento!";
                        }
                        if (ettemp.getFuncao() == "Selecionador Nacional") {
                            stemp.setNome(ettemp.getNome());
                            stemp.setDataNascimento((ettemp.getDataNascimento()));
                            stemp.setFuncao(ettemp.getFuncao());
                            stemp.setSalario(ettemp.getSalario());
                            stemp.setTitulosGanhos(0);
                            selecionadores.insert(stemp);
                            selecao.SelecionadorestoFile(selecionadores);
                        }
                        selecao.EquipaTecnicatoFile(equipatecnica);
                        break;
                    case (3):
                        system("cls");
                        logo();
                        et1.RemoverTecnico(equipatecnica);
                        selecao.EquipaTecnicatoFile(equipatecnica);
                        break;
                    case (4):
                        system("cls");
                        logo();
                        et1.EditarTecnico(equipatecnica);
                        selecao.EquipaTecnicatoFile(equipatecnica);
                        break;
                    case (5):
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 3:
                system("cls");
                logo();
                cout << " 1 - Informacoes sobre as Convocatorias" << endl;
                cout << " 2 - Adicionar uma Convocatoria " << endl;
                cout << " 3 - Remover uma Convocatoria" << endl;
                cout << " 4 - Editar uma Convocatoria" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: ";
                    cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                switch (opt) {
                    case (1):
                        system("cls");
                        logo();
                        c1.InformacoesConvocatoria(convocatorias);
                        break;
                    case (2):
                        system("cls");
                        logo();
                        try {
                            c = c1.AdicionarConvocatoria(convocatorias, jogadores, equipatecnica, jogos);
                        }
                        catch (ConvocatoriaJaExistente c) {
                            cout << "Ja existe uma convocatoria com este ID!";
                        }
                        selecao.updateSelecionadores(selecionadores, c);
                        selecao.SelecionadorestoFile(selecionadores);
                        selecao.ConvocatoriatoFile(convocatorias);
                        break;
                    case (3):
                        system("cls");
                        logo();
                        c1.RemoverConvocatoria(convocatorias);
                        selecao.ConvocatoriatoFile(convocatorias);
                        break;
                    case (4):
                        system("cls");
                        logo();
                        c1.EditarConvocatoria(convocatorias, jogos);
                        selecao.ConvocatoriatoFile(convocatorias);
                        break;
                    case (5):
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 4:
                system("cls");
                logo();
                cout << " 1 - Informacoes sobre os Jogos" << endl;
                cout << " 2 - Adicionar um Jogo " << endl;
                cout << " 3 - Remover um Jogo" << endl;
                cout << " 4 - Editar um Jogo" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: ";
                    cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                switch (opt) {
                    case (1):
                        system("cls");
                        logo();
                        j1.infoJogo(jogos);
                        break;
                    case (2):
                        system("cls");
                        logo();
                        try {
                            j1.addJogo(jogos, jogadores);
                        }
                        catch (JogoJaExistente j) {
                            cout << "Ja existe um jogo com esta data!";
                        }
                        selecao.JogostoFile(jogos);
                        break;
                    case (3):
                        system("cls");
                        j = j1.removeJogo(jogos);
                        c1.updateJogos(convocatorias, j);
                        selecao.JogostoFile(jogos);
                        selecao.ConvocatoriatoFile(convocatorias);
                        break;
                    case (4):
                        system("cls");
                        logo();
                        j1.editJogo(jogos, jogadores);
                        selecao.JogostoFile(jogos);
                        break;
                    case (5):
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 5:
                system("cls");
                logo();
                cout << " 1 - Estatisticas Individuais" << endl;
                cout << " 2 - Estatisiticas Coletivas" << endl;
                cout << " 3 - Custo Individual" << endl;
                cout << " 4 - Custo Coletivo da Equipa" << endl;
                cout << " 5 - Custo Coletivo da Selecao" << endl;
                cout << " 6 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: ";
                    cin >> opt;
                    if (opt < 1 || opt > 6 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 6." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                system("cls");
                logo();
                switch (opt) {
                    case 1:
                        system("cls");
                        logo();
                        EstatisticaJogador(jogadores, jogos, convocatorias);
                        break;
                    case 2:
                        system("cls");
                        logo();
                        EstatisticaSelecao(jogadores, jogos, convocatorias);
                        break;
                    case 3:
                        system("cls");
                        logo();
                        CustoIndvMes(jogadores, jogos, convocatorias);
                        break;
                    case 4:
                        system("cls");
                        logo();
                        CustoGeralMesEquip(jogadores, jogos, convocatorias, equipatecnica);
                        break;
                    case 5:
                        system("cls");
                        logo();
                        CustoGeralMesTudo(jogadores, jogos, convocatorias, equipatecnica);
                        break;
                    case 6:
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 6:
                system("cls");
                logo();
                cout << " 1 - Informacoes sobre Fornecedores" << endl;
                cout << " 2 - Compra de Equipamentos" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: ";
                    cin >> opt;
                    if (opt < 1 || opt > 2 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 2." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 2 || cin.fail());
                system("cls");
                logo();
                switch (opt) {
                    case 1:
                        system("cls");
                        logo();
                        for1.InfoFornecedores(fornecedores);
                        break;
                    case 2:
                        system("cls");
                        logo();
                        try {
                            for1.VenderEquipamentos(fornecedores);
                        }
                        catch (SemFornecedor p) {
                            cout << endl << "Nao existe fornecedor para este tipo de equipamento!";
                        }
                        selecao.FornecedorestoFile(fornecedores);
                        break;
                }
                break;
            case 7:
                system("cls");
                logo();
                cout << " 1 - Mostrar Selecionadores em Ordem" << endl;
                cout << " 2 - Mostrar Selecionadores em Nivel" << endl;
                cout << " 3 - Mostrar Selecionadores em Pre-Ordem" << endl;
                cout << " 4 - Mostrar Selecionadores em Pos-Ordem" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: ";
                    cin >> opt;
                    if (opt < 1 || opt > 4 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 4." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 4 || cin.fail());
                system("cls");
                logo();
                switch (opt) {
                    case 1:
                        system("cls");
                        logo();
                        while (!it2.isAtEnd()) {
                            size++;
                            it2.advance();
                        }
                        while (!it.isAtEnd()) {
                            cout << it.retrieve();
                            index++;
                            if (index < size)
                                cout << endl << endl << " -----------------------" << endl << endl;
                            it.advance();
                        }
                        break;
                    case 2:
                        system("cls");
                        logo();
                        while (!it2.isAtEnd()) {
                            size++;
                            it2.advance();
                        }
                        while (!itnivel.isAtEnd()) {
                            cout << itnivel.retrieve();
                            index++;
                            if (index < size)
                                cout << endl << endl << " -----------------------" << endl << endl;
                            itnivel.advance();
                        }
                        break;
                    case 3:
                        system("cls");
                        logo();
                        while (!it2.isAtEnd()) {
                            size++;
                            it2.advance();
                        }
                        while (!itpre.isAtEnd()) {
                            cout << itpre.retrieve();
                            index++;
                            if (index < size)
                                cout << endl << endl << " -----------------------" << endl << endl;
                            itpre.advance();
                        }
                        break;
                    case 4:
                        system("cls");
                        logo();
                        while (!it2.isAtEnd()) {
                            size++;
                            it2.advance();
                        }
                        while (!itpre.isAtEnd()) {
                            cout << itpre.retrieve();
                            index++;
                            if (index < size)
                                cout << endl << endl << " -----------------------" << endl << endl;
                            itpre.advance();
                        }
                        break;
                }
                break;
            case 8:
                system("cls");
                logo();
                cout << " 1 - Informacoes dos Funcionarios da Convocatoria Atual" << endl;
                cout << " 2 - Informacoes de todos os Funcionarios conhecidos" << endl;
                cout << " 3 - Contratar um Funcionario para a Convocatoria Atual" << endl;
                cout << " 4 - Voltar Atras" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: ";
                    cin >> opt;
                    if (opt < 1 || opt > 4 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 4." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 4 || cin.fail());
                system("cls");
                logo();
                switch (opt) {
                    case 1:
                        system("cls");
                        logo();
                        selecao.InformacoesFuncionariosConvocatoria(convocatorias, funcRec);
                        break;
                    case 2:
                        system("cls");
                        logo();
                        selecao.InformacoesFuncionariosConhecidos(funcRec);
                        break;
                    case 3:
                        system("cls");
                        logo();
                        try {
                            selecao.ContratarFuncionario(convocatorias, funcRec, equipatecnica);
                        }
                        catch (FuncionarioNaoExistente s) {
                            cout << endl
                                 << " Nao existe nenhum funcionario que desempenhe esta funcao disponivel para ser contratado!";
                        }
                        selecao.ConvocatoriatoFile(convocatorias);
                        selecao.EquipaTecnicatoFile(equipatecnica);
                        break;
                }
                break;
            case 9:
                system("cls");
                logo();
                vector<JogadorFama> v1;
                JogadorFama j;
                for (auto x: jogadores){
                    j.nome = x.getNome();
                    j.golos = 0;
                    j.assists = 0;
                    j.jogos = 0;
                    for (auto y: jogos){
                        for (auto z: y.getGolos()){
                            if (x == z.first) {
                                j.golos += z.second;
                                j.jogos += 1;
                            }
                        }
                        for (auto z: y.getAssists()){
                            if (x == z.first)
                                j.assists += z.second;
                        }
                    }
                    v1.push_back(j);
                }
                if (v1.empty())
                    cout << " Ainda nao existem jogadores para existir Corredor da Fama!" << endl;
                else {
                    sort(v1.begin(), v1.end(), maisgolos);
                    cout << " CORREDOR DA FAMA" << endl << endl;
                    cout << " Melhor Marcador de Sempre: " << v1.front().nome << " (" << v1.front().golos << " golos)"
                         << endl;
                    sort(v1.begin(), v1.end(), maisassists);
                    cout << " Jogador com mais Assistencias de Sempre: " << v1.front().nome << " ("
                         << v1.front().assists << " assistencias)" << endl;
                    sort(v1.begin(), v1.end(), maisjogos);
                    cout << " Mais Internacional de Sempre: " << v1.front().nome << " (" << v1.front().jogos
                         << " internacionalizacoes)" << endl;
                    cout << endl;
                }
        }
        changeReturn(return_menu);
        if (return_menu == true)
            system("cls");
    } while (return_menu);
}