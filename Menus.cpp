#include "Menus.h"
#include "Jogadores.h"
#include "Convocatoria.h"
#include "Jogo.h"
#include "Utils.h"
#include "Estatistica.h"
#include "Equipamentos.h"
#include <queue>

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

void mainMenu(Selecao& selecao) {
    bool return_menu = true;
    Futebolista f1;
    EquipaTecnica et1;
    Selecionadores s1;
    Convocatoria c1;
    Jogo j1, j;
    Fornecedores for1;
    vector<Futebolista> jogadores = selecao.getJogadores();
    vector<EquipaTecnica> equipatecnica = selecao.getEquipaTecnica();
    vector<Convocatoria> convocatorias = selecao.getConvocatorias();
    vector<Jogo> jogos = selecao.getJogos();
    priority_queue<Fornecedores> fornecedores = selecao.getFornecedores();
    BST<Selecionadores> selecionadores = selecao.getSelecionadores();
    BSTItrIn<Selecionadores> it(selecionadores);
    Convocatoria c;
    do {
        logo();
        cout << " 1 - Gerir Jogadores" << endl;
        cout << " 2 - Gerir Equipa Tecnica " << endl;
        cout << " 3 - Gerir Convocatorias" << endl;
        cout << " 4 - Gerir Jogos" << endl;
        cout << " 5 - Estatisicas da Selecao" << endl;
        cout << " 6 - Venda de Equipamentos" << endl;
        unsigned int opt = 0;
        cout << endl;
        do {
            cout << "Introduza uma opcao: "; cin >> opt;
            if (opt < 1 || opt > 6 || cin.fail()) {
                cin.clear();
                cout << "Opcao invalida! Introduza um numero entre 1 e 6." << endl;
                cin.ignore(1000, '\n');
            }
        } while (opt < 1 || opt > 6 || cin.fail());
        cin.ignore(1000, '\n');

        switch (opt) {
            case 1:
                system("cls"); logo();
                cout << " 1 - Informacoes sobre os jogadores" << endl;
                cout << " 2 - Adicionar um jogador " << endl;
                cout << " 3 - Remover um jogador" << endl;
                cout << " 4 - Editar um jogador" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: "; cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                switch (opt) {
                    case(1):
                        system("cls"); logo();
                        f1.InformacoesJogador(jogadores);
                        break;
                    case(2):
                        system("cls"); logo();
                        try {
                            f1.AdicionarJogador(jogadores);
                        }
                        catch (JogadorJaExistente j) {
                            cout << endl << "Ja existe um jogador com este nome e data de nascimento!";
                        }
                        selecao.JogadoresToFile(jogadores);
                        break;
                    case(3):
                        system("cls"); logo();
                        f1.RemoverJogador(jogadores);
                        selecao.JogadoresToFile(jogadores);
                        break;
                    case(4):
                        system("cls"); logo();
                        f1.EditarJogador(jogadores);
                        selecao.JogadoresToFile(jogadores);
                        break;
                    case(5):
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 2:
                system("cls"); logo();
                cout << " 1 - Informacoes sobre os Membros Tecnicos" << endl;
                cout << " 2 - Adicionar um Membro Tecnico " << endl;
                cout << " 3 - Remover um Membro Tecnico" << endl;
                cout << " 4 - Editar um Membro Tecnico" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: "; cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                switch (opt) {
                    case(1):
                        system("cls"); logo();
                        et1.InformacoesTecnico(equipatecnica);
                        break;
                    case(2):
                        system("cls"); logo();
                        try {
                            et1.AdicionarTecnico(equipatecnica);
                        }
                        catch (MembroTecnicoJaExistente mt) {
                            cout << endl << "Ja existe um membro tecnico com este nome e data de nascimento!";
                        }
                        selecao.EquipaTecnicatoFile(equipatecnica);
                        break;
                    case(3):
                        system("cls"); logo();
                        et1.RemoverTecnico(equipatecnica);
                        selecao.EquipaTecnicatoFile(equipatecnica);
                        break;
                    case(4):
                        system("cls"); logo();
                        et1.EditarTecnico(equipatecnica);
                        selecao.EquipaTecnicatoFile(equipatecnica);
                        break;
                    case(5):
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 3:
                system("cls"); logo();
                cout << " 1 - Informacoes sobre as Convocatorias" << endl;
                cout << " 2 - Adicionar uma Convocatoria " << endl;
                cout << " 3 - Remover uma Convocatoria" << endl;
                cout << " 4 - Editar uma Convocatoria" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: "; cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                switch (opt) {
                    case(1):
                        system("cls"); logo();
                        c1.InformacoesConvocatoria(convocatorias);
                        break;
                    case(2):
                        system("cls"); logo();
                        try {
                            c = c1.AdicionarConvocatoria(convocatorias, jogadores, equipatecnica, jogos);
                        }
                        catch (ConvocatoriaJaExistente c) {
                            cout << "Ja existe uma convocatoria com este ID!";
                        }
                        selecao.updateSelecionadores(selecionadores, c);
                        selecao.ConvocatoriatoFile(convocatorias);
                        break;
                    case(3):
                        system("cls"); logo();
                        c1.RemoverConvocatoria(convocatorias);
                        selecao.ConvocatoriatoFile(convocatorias);
                        break;
                    case(4):
                        system("cls"); logo();
                        c1.EditarConvocatoria(convocatorias, jogos);
                        selecao.ConvocatoriatoFile(convocatorias);
                        break;
                    case(5):
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 4:
                system("cls"); logo();
                cout << " 1 - Informacoes sobre os Jogos" << endl;
                cout << " 2 - Adicionar um Jogo " << endl;
                cout << " 3 - Remover um Jogo" << endl;
                cout << " 4 - Editar um Jogo" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: "; cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                switch (opt) {
                    case(1):
                        system("cls"); logo();
                        j1.infoJogo(jogos);
                        break;
                    case(2):
                        system("cls"); logo();
                        try {
                            j1.addJogo(jogos, jogadores);
                        }
                        catch (JogoJaExistente j){
                            cout << "Ja existe um jogo com esta data!";
                        }
                        selecao.JogostoFile(jogos);
                        break;
                    case(3):
                        system("cls");
                        j = j1.removeJogo(jogos);
                        c1.updateJogos(convocatorias, j);
                        selecao.JogostoFile(jogos);
                        selecao.ConvocatoriatoFile(convocatorias);
                        break;
                    case(4):
                        system("cls"); logo();
                        j1.editJogo(jogos, jogadores);
                        selecao.JogostoFile(jogos);
                        break;
                    case(5):
                        system("cls");
                        mainMenu(selecao);
                        break;
                }
                break;
            case 5:
                system("cls"); logo();
                cout << " 1 - Estatisticas Individuais" << endl;
                cout << " 2 - Estatisiticas Coletivas" << endl;
                cout << " 3 - Custo Individual" << endl;
                cout << " 4 - Custo Coletivo" << endl;
                cout << " 5 - Voltar ao Menu Principal" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: "; cin >> opt;
                    if (opt < 1 || opt > 5 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 5." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 5 || cin.fail());
                system("cls"); logo();
                switch (opt) {
                    case 1:
                        system("cls"); logo();
                        EstatisticaJogador(jogadores, jogos, convocatorias);
                        break;
                    case 2:
                        system("cls"); logo();
                        EstatisticaSelecao(jogadores, jogos, convocatorias);
                        break;
                    case 3:
                        system("cls"); logo();
                        CustoIndvMes(jogadores, jogos, convocatorias);
                        break;
                    case 4:
                        system("cls"); logo();
                        CustoGeralMesEquip(jogadores, jogos, convocatorias, equipatecnica);
                        break;
                    case 5:
                        system("cls"); logo();
                        CustoGeralMesTudo(jogadores, jogos, convocatorias, equipatecnica);
                        break;
                }
                break;
            case 6:
                system("cls"); logo();
                cout << " 1 - Informacoes sobre Fornecedores" << endl;
                cout << " 2 - Compra de Equipamentos" << endl;
                cout << endl;
                opt = 0;
                do {
                    cout << "Introduza uma opcao: "; cin >> opt;
                    if (opt < 1 || opt > 2 || cin.fail()) {
                        cin.clear();
                        cout << "Opcao invalida! Introduza um numero entre 1 e 2." << endl;
                        cin.ignore(1000, '\n');
                    }
                } while (opt < 1 || opt > 2 || cin.fail());
                system("cls"); logo();
                switch (opt) {
                    case 1:
                        system("cls"); logo();
                        for1.InfoFornecedores(fornecedores);
                        break;
                    case 2:
                        system("cls"); logo();
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
        }
        changeReturn(return_menu);
        if (return_menu == true)
            system("cls");
    } while (return_menu);
}