#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTOS 100

// cria um novo nome para um tipo 
typedef struct
{
    int codigo;
    char nome[100];
    char local[100];
    char data[15];
    int vagas;
    int inscritos;

} Evento;

Evento eventos[MAX_EVENTOS];
int totalEventos = 0;

/* Funções */

// Ariane Parolin
void removerQuebraLinha(char texto[])
{
    texto[strcspn(texto, "\n")] = '\0';
}


// Ariane Parolin
void cor(int cor)
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        cor
    );
}


// Ariane Parolin
void cadastrarEvento()
{
    system("cls");

    cor(11);

    printf("\n=============================================================\n");
    printf("                    CADASTRAR EVENTO\n");
    printf("=============================================================\n");

    cor(15);

    if(totalEventos >= MAX_EVENTOS)
    {
        cor(12);
        printf("\nLimite maximo de eventos atingido!\n");
        cor(15);
        return;
    }

    Evento novoEvento;

    /* CODIGO */
    while(1)
    {
        printf("\nCodigo do evento: ");

        if(scanf("%d", &novoEvento.codigo) == 1)
        {
            int codigoExiste = 0;

            for(int i = 0; i < totalEventos; i++)
            {
                if(eventos[i].codigo == novoEvento.codigo)
                {
                    codigoExiste = 1;
                    break;
                }
            }

            if(codigoExiste)
            {
                cor(12);
                printf("Ja existe um evento com esse codigo!\n");
                cor(15);
            }
            else
            {
                break;
            }
        }
        else
        {
            cor(12);
            printf("Codigo invalido! Digite apenas numeros.\n");
            cor(15);
        }

        while(getchar() != '\n');
    }

    while(getchar() != '\n');

    /* NOME */
    printf("Nome do evento: ");
    fgets(novoEvento.nome, sizeof(novoEvento.nome), stdin);
    removerQuebraLinha(novoEvento.nome);

    /* LOCAL */
    printf("Local do evento: ");
    fgets(novoEvento.local, sizeof(novoEvento.local), stdin);
    removerQuebraLinha(novoEvento.local);

    /* DATA */

    int dia, mes, ano;

    time_t t = time(NULL);
    struct tm hoje = *localtime(&t);

    int diaAtual = hoje.tm_mday;
    int mesAtual = hoje.tm_mon + 1;
    int anoAtual = hoje.tm_year + 1900;

    while(1)
    {
        printf("Data do evento (dd/mm/aaaa): ");
        fgets(novoEvento.data, sizeof(novoEvento.data), stdin);
        removerQuebraLinha(novoEvento.data);

        if(sscanf(novoEvento.data, "%d/%d/%d",
                  &dia, &mes, &ano) == 3)
        {
            int dataValida = 1;

            if(dia < 1 || dia > 31)
                dataValida = 0;

            if(mes < 1 || mes > 12)
                dataValida = 0;

            if(ano < anoAtual)
                dataValida = 0;

            if(dataValida)
            {
                if(ano == anoAtual)
                {
                    if(mes < mesAtual)
                        dataValida = 0;

                    if(mes == mesAtual && dia < diaAtual)
                        dataValida = 0;
                }
            }

            if(dataValida)
                break;
        }

        cor(12);
        printf("Data invalida! Informe uma data igual ou posterior a hoje.\n");
        cor(15);
    }

    /* VAGAS */

    while(1)
    {
        printf("Quantidade de vagas: ");

        if(scanf("%d", &novoEvento.vagas) == 1 &&
           novoEvento.vagas > 0)
        {
            break;
        }

        cor(12);
        printf("Quantidade de vagas invalida! Digite um numero maior que zero.\n");
        cor(15);

        while(getchar() != '\n');
    }

    novoEvento.inscritos = 0;

    system("cls");

    cor(14);

    printf("\n=============================================================\n");
    printf("                  CONFIRMACAO DE CADASTRO\n");
    printf("=============================================================\n");

    cor(15);

    printf("\nCodigo........: %d\n", novoEvento.codigo);
    printf("Nome..........: %s\n", novoEvento.nome);
    printf("Local.........: %s\n", novoEvento.local);
    printf("Data..........: %s\n", novoEvento.data);
    printf("Vagas.........: %d\n", novoEvento.vagas);
    printf("Inscritos.....: %d\n", novoEvento.inscritos);

    char confirmar;

    printf("\nDeseja confirmar o cadastro? (S/N): ");
    scanf(" %c", &confirmar);

    if(confirmar == 'S' || confirmar == 's')
    {
        eventos[totalEventos] = novoEvento;
        totalEventos++;

        cor(10);
        printf("\nEvento cadastrado com sucesso!\n");
    }
    else
    {
        cor(12);
        printf("\nCadastro cancelado!\n");
    }

    cor(15);
}


// Luiza Oliveira
void listarEventos()
{
    printf("\n[LISTAR EVENTOS]\n");
    int i;

    system("cls");

    cor(11);

    printf("\n=============================================================\n");
    printf("                      LISTA DE EVENTOS\n");
    printf("=============================================================\n");

    cor(15);

    if(totalEventos == 0)
    {
        printf("\nNenhum evento cadastrado.\n");
        return;
    }

    for(i = 0; i < totalEventos; i++)
    {
        printf("\nEvento %d\n", i + 1);
        printf("Codigo: %d\n", eventos[i].codigo);
        printf("Nome..: %s\n", eventos[i].nome);
        printf("Local.: %s\n", eventos[i].local);
        printf("Data..: %s\n", eventos[i].data);
        printf("Vagas.: %d\n", eventos[i].vagas);
        printf("Inscritos: %d\n", eventos[i].inscritos);
        printf("------------------------------------\n");
    }

    cor(15);
}


// Otavio Sanchez
void buscarEvento()
{
    system("cls");

    int codigo, encontrado = -1; /*-1 perdido*/

    cor(11);
    printf("\n=============================================================\n");
    printf("                       BUSCAR EVENTO\n");
    printf("=============================================================\n");
    cor(15);

    if(totalEventos == 0){

        cor(12);
        printf("\nNenhum evento cadastrado.\n");
        cor(15);
        return;
    }

    printf("Digite o Codigo do Evento:");
    scanf("%d",&codigo);

        for(int i=0;i<totalEventos;i++){
            
            if(eventos[i].codigo == codigo){

                encontrado = i;
                break;
            }

        }   

        if(encontrado == -1){

            cor(12);
            printf("\nEvento nao encontrado!\n");
            cor(15);
            return;
        } 

        cor(10);
        printf("\nEvento encontrado!\n");
        cor(15);

        printf("\nCodigo........: %d\n", eventos[encontrado].codigo);
        printf("Nome..........: %s\n", eventos[encontrado].nome);
        printf("Local.........: %s\n", eventos[encontrado].local);
        printf("Data..........: %s\n", eventos[encontrado].data);
        printf("Vagas.........: %d\n", eventos[encontrado].vagas);
        printf("Inscritos.....: %d\n", eventos[encontrado].inscritos);
        
}


// Otavio Sanchez
void alterarEvento()
{
    system("cls");

    int codigo, encontrado = -1;

    cor(11);
    printf("\n=============================================================\n");
    printf("                       ALTERAR EVENTO\n");
    printf("=============================================================\n");
    cor(15);

    if(totalEventos == 0)
    {
        cor(12);
        printf("\nNenhum evento cadastrado.\n");
        cor(15);
        return;
    }

    printf("\nDigite o codigo do evento que deseja alterar: ");
    scanf("%d", &codigo);

    for(int i = 0; i < totalEventos; i++)
    {
        if(eventos[i].codigo == codigo)
        {
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1)
    {
        cor(12);
        printf("\nEvento nao encontrado!\n");
        cor(15);
        return;
    }

    printf("\nNovo nome: ");
    scanf(" %[^\n]", eventos[encontrado].nome);

    printf("Novo local: ");
    scanf(" %[^\n]", eventos[encontrado].local);

    printf("Nova data: ");
    scanf(" %[^\n]", eventos[encontrado].data);

    printf("Nova quantidade de vagas: ");
    scanf("%d", &eventos[encontrado].vagas);

    cor(10);
    printf("\nEvento alterado com sucesso!\n");
    cor(15);
}


//Lucas Siqueira
void excluirEvento()
{
    system("cls");
    cor(11);
    printf("\n=============================================================\n");
    printf("                      EXCLUIR EVENTO\n");
    printf("=============================================================\n");
    cor(15);

    if(totalEventos == 0)
    {
        cor(12);
        printf("\nNenhum evento cadastrado para excluir.\n");
        cor(15);
        return;
    }

    int codigoProcurado;
    printf("\nDigite o codigo do evento que deseja excluir: ");
    
    if(scanf("%d", &codigoProcurado) != 1)
    {
        cor(12);
        printf("Codigo invalido!\n");
        cor(15);
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');

    int indiceEncontrado = -1;
    for(int i = 0; i < totalEventos; i++)
    {
        if(eventos[i].codigo == codigoProcurado)
        {
            indiceEncontrado = i;
            break;
        }
    }

    if(indiceEncontrado == -1)
    {
        cor(12);
        printf("\nEvento com o codigo %d nao encontrado.\n", codigoProcurado);
        cor(15);
        return;
    }

    printf("\nEvento encontrado:\n");
    printf("Nome: %s\n", eventos[indiceEncontrado].nome);
    printf("Data: %s\n", eventos[indiceEncontrado].data);

    char confirmar;
    cor(14);
    printf("\nTens a certeza que desejas excluir este evento? (S/N): ");
    cor(15);
    scanf(" %c", &confirmar);
    while(getchar() != '\n');

    if(confirmar == 'S' || confirmar == 's')
    {
        for(int i = indiceEncontrado; i < totalEventos - 1; i++)
        {
            eventos[i] = eventos[i + 1];
        }
        
        totalEventos--; 

        cor(10);
        printf("\nEvento excluido com sucesso!\n");
    }
    else
    {
        cor(12);
        printf("\nExclusao cancelada.\n");
    }
    cor(15);
}


// Lucas Siqueira
void inscreverParticipante()
{
    system("cls");
    cor(11);
    printf("\n=============================================================\n");
    printf("                  INSCREVER PARTICIPANTE\n");
    printf("=============================================================\n");
    cor(15);

    if(totalEventos == 0)
    {
        cor(12);
        printf("\nNenhum evento cadastrado disponivel para inscricao.\n");
        cor(15);
        return;
    }

    int codigoProcurado;
    printf("\nDigite o codigo do evento para a inscricao: ");
    
    if(scanf("%d", &codigoProcurado) != 1)
    {
        cor(12);
        printf("Codigo invalido!\n");
        cor(15);
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');

    int indiceEncontrado = -1;
    for(int i = 0; i < totalEventos; i++)
    {
        if(eventos[i].codigo == codigoProcurado)
        {
            indiceEncontrado = i;
            break;
        }
    }

    if(indiceEncontrado == -1)
    {
        cor(12);
        printf("\nEvento nao encontrado.\n");
        cor(15);
        return;
    }

    if(eventos[indiceEncontrado].inscritos >= eventos[indiceEncontrado].vagas)
    {
        cor(12);
        printf("\nDesculpe, este evento ja esta lotado (%d/%d vagas).\n", 
               eventos[indiceEncontrado].inscritos, eventos[indiceEncontrado].vagas);
        cor(15);
        return;
    }

    int vagasRestantes = eventos[indiceEncontrado].vagas - eventos[indiceEncontrado].inscritos;
    printf("\nEvento...........: %s\n", eventos[indiceEncontrado].nome);
    printf("Vagas disponiveis: %d\n", vagasRestantes);

    char confirmar;
    printf("\nConfirmar inscricao neste evento? (S/N): ");
    scanf(" %c", &confirmar);
    while(getchar() != '\n');

    if(confirmar == 'S' || confirmar == 's')
    {
        eventos[indiceEncontrado].inscritos++; 

        cor(10);
        printf("\nInscricao realizada com sucesso!\n");
    }
    else
    {
        cor(12);
        printf("\nInscricao cancelada.\n");
    }
    cor(15);
}


// Ariane Parolin
void relatorioParticipantes()
{
    system("cls");

    cor(11);

    printf("\n=============================================================\n");
    printf("                RELATORIO DE PARTICIPANTES\n");
    printf("=============================================================\n");

    if(totalEventos == 0)
    {
        cor(12);

        printf("\nNenhum evento cadastrado.\n");

        cor(15);
        return;
    }

    cor(15);

    printf("\n%-8s %-30s %-10s %-12s %-12s\n",
           "CODIGO",
           "EVENTO",
           "VAGAS",
           "INSCRITOS",
           "OCUPACAO");

    printf("=============================================================\n");

    int totalInscritos = 0;
    int totalVagas = 0;

    for(int i = 0; i < totalEventos; i++)
    {
        float ocupacao = 0;

        if(eventos[i].vagas > 0)
        {
            ocupacao =
                ((float)eventos[i].inscritos /
                 eventos[i].vagas) * 100;
        }

        printf("%-8d %-30s %-10d %-12d %.0f%%\n",
               eventos[i].codigo,
               eventos[i].nome,
               eventos[i].vagas,
               eventos[i].inscritos,
               ocupacao);

        totalInscritos += eventos[i].inscritos;
        totalVagas += eventos[i].vagas;
    }

    cor(11);

    printf("\n=============================================================\n");

    cor(10);

    printf("Total de eventos........: %d\n", totalEventos);
    printf("Total de vagas..........: %d\n", totalVagas);
    printf("Total de participantes..: %d\n", totalInscritos);

    cor(11);

    printf("=============================================================\n");

    cor(15);
}


// Ariane Parolin
void exibirMenu()
{
    system("cls");

    cor(11); 

    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                    SISTEMA DE CONTROLE DE EVENTOS                ║\n");
    printf("╚══════════════════════════════════════════════════════════════════╝\n");

    cor(11);

    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                           MENU PRINCIPAL                         ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");

    cor(11);
    printf("║  [1] ");

    cor(15);
    printf("Cadastrar Evento");

    cor(11);
    printf("                                            ║\n");

    cor(11);
    printf("║  [2] ");

    cor(15);
    printf("Listar Eventos");

    cor(11);
    printf("                                              ║\n");

    cor(11);
    printf("║  [3] ");

    cor(15);
    printf("Buscar Evento");

    cor(11);
    printf("                                               ║\n");

    cor(11);
    printf("║  [4] ");

    cor(15);
    printf("Alterar Evento");

    cor(11);
    printf("                                              ║\n");

    cor(11);
    printf("║  [5] ");

    cor(15);
    printf("Excluir Evento");

    cor(11);
    printf("                                              ║\n");

    cor(11);
    printf("║  [6] ");

    cor(15);
    printf("Inscrever Participante");

    cor(11);
    printf("                                      ║\n");

    cor(11);
    printf("║  [7] ");

    cor(15);
    printf("Relatorio de Participantes");

    cor(11);
    printf("                                  ║\n");

    cor(11);
    printf("║                                                                  ║\n");

    cor(12);
    printf("║  [8] ");

    cor(15);
    printf("Sair");

    cor(11);
    printf("                                                        ║\n");

    cor(11);
    printf("╠══════════════════════════════════════════════════════════════════╣\n");

    cor(10); 

    printf("║  Eventos cadastrados: %-42d ║\n", totalEventos);

    cor(11);

    printf("╚══════════════════════════════════════════════════════════════════╝\n");

    cor(15);

    printf("\nDigite uma opcao: ");
}


int main()
{
    system("chcp 65001 > nul");
    int opcao;

    do
    {
        exibirMenu();
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                cadastrarEvento();
                break;

            case 2:
                listarEventos();
                break;

            case 3:
                buscarEvento();
                break;

            case 4:
                alterarEvento();
                break;

            case 5:
                excluirEvento();
                break;

            case 6:
                inscreverParticipante();
                break;

            case 7:
                relatorioParticipantes();
                break;

            case 8:
                printf("\nObrigado por utilizar o sistema!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

        system("pause");
    }
    while(opcao != 8);

    return 0;
}