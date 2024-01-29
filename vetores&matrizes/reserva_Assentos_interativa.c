#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>

#define NUM_FILEIRAS 5
#define NUM_ASSENTOS 10

// inicio funcoes para criar interaçao em c
void linhaCol(int lin, int col);
void box(int lin1, int col1, int lin2, int col2);
int menu(int lin1, int col1, int qtd, char lista[4][40]);

// COR DA LETRA
enum
{
    BLACK,        // 0
    BLUE,         // 1
    GREEN,        // 2
    CYAN,         // 3
    RED,          // 4
    MAGENTA,      // 5
    BROWN,        // 6
    LIGHTGRAY,    // 7
    DARKGRAY,     // 8
    LIGHTBLUE,    // 9
    LIGHTGREEN,   // 10
    LIGHTCYAN,    // 11
    LIGHTRED,     // 12
    LIGHTMAGENTA, // 13
    YELLOW,       // 14
    WHITE         // 15

};
// COR DO FUNDO
enum
{
    _BLACK = 0,          // 0
    _BLUE = 16,          // 1
    _GREEN = 32,         // 2
    _CYAN = 48,          // 3
    _RED = 64,           // 4
    _MAGENTA = 80,       // 5
    _BROWN = 96,         // 6
    _LIGHTGRAY = 112,    // 7
    _DARKGRAY = 128,     // 8
    _LIGHTBLUE = 144,    // 9
    _LIGHTGREEN = 160,   // 10
    _LIGHTCYAN = 176,    // 11
    _LIGHTRED = 192,     // 12
    _LIGHTMAGENTA = 208, // 13
    _YELLOW = 224,       // 14
    _WHITE = 240         // 15
};

void textColor(int letra, int fundo)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
}

void linhaCol(int lin, int col)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){col - 1, lin - 1});
}
void box(int lin1, int col1, int lin2, int col2)
{
    int i, j, tamlin, tamcol;

    // achar o tamanho do box
    tamlin = lin2 - lin1;
    tamcol = col2 - col1;

    // Monta o Box
    for (i = col1; i <= col2; i++)
    { // linhas
        linhaCol(lin1, i);
        printf("%c", 196);
        linhaCol(lin2, i);
        printf("%c", 196);
    }

    for (i = lin1; i <= lin2; i++)
    { // colunas
        linhaCol(i, col1);
        printf("%c", 179);
        linhaCol(i, col2);
        printf("%c", 179);
    }

    for (i = lin1 + 1; i < lin2; i++)
    {
        for (j = col1 + 1; j < col2; j++)
        {
            linhaCol(i, j);
            printf(" ");
        }
    }
    // Posição dos cantos
    linhaCol(lin1, col1);
    printf("%c", 218);
    linhaCol(lin1, col2);
    printf("%c", 191);
    linhaCol(lin2, col1);
    printf("%c", 192);
    linhaCol(lin2, col2);
    printf("%c", 217);
}

int menu(int lin1, int col1, int qtd, char lista[4][40])
{
    int opc = 1, lin2, col2, linha, i, tamMaxItem, tecla;

    // calcula as coordenadas
    tamMaxItem = strlen(lista[0]);
    // tamanho maximo do item
    for (i = 1; i < qtd; i++)
    {
        if (strlen(lista[i]) > tamMaxItem)
        {
            tamMaxItem = strlen(lista[i]);
        }
    }
    lin2 = lin1 + (qtd * 2 + 2);
    col2 = col1 + tamMaxItem + 4;

    // Monta Tela
    textColor(WHITE, _BLUE);
    setlocale(LC_ALL, "C");
    box(lin1, col1, lin2, col2);
    setlocale(LC_ALL, "");
    // laço das opcões
    while (1)
    {
        linha = lin1 + 2;
        for (i = 0; i < qtd; i++)
        {
            if (i + 1 == opc)
                textColor(BLACK, _LIGHTGREEN);
            else
                textColor(WHITE, _BLUE);
            linhaCol(linha, col1 + 2);
            printf("%s", lista[i]);
            linha += 2;
        }

        // Aguarda tecla
        linhaCol(1, 1);
        tecla = getch();
        linhaCol(22, 1);
        // printf(" tecla:  %d   ",tecla);
        // Opção
        if (tecla == 27)
        { // ESC
            opc = 0;
            break;
        }
        else if (tecla == 13)
        { // ENTER
            break;
        }
        // Seta para cima
        else if (tecla == 72)
        { // se possivel seleciona o item anterior - seta para cima
            if (opc > 1)
                opc--; // se opcao for maior que 1, pode voltar
        }
        else if (tecla == 80)
        { // seta para baixo
            if (opc < qtd)
                opc++; // Se opcao for menor que quantidade de itens, posso avançar
        }
    }
    return opc;
}
// fim funcoes para criar interaçao em c

void exibirAssentos(char assentos[NUM_FILEIRAS][NUM_ASSENTOS])
{
    printf("\nLayout dos Assentos:\n");
    printf("\n");
    printf("   ");
    for (int i = 1; i <= NUM_ASSENTOS; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < NUM_FILEIRAS; i++)
    {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < NUM_ASSENTOS; j++)
        {
            printf("%c ", assentos[i][j]);
        }
        printf("\n");
    }
}
void reservarAssento(char assentos[NUM_FILEIRAS][NUM_ASSENTOS])
{
    char fileira;
    int assento;

    printf("\nDigite a fileira (A-E) e o numero do assento (1-10) para reservar:\n");
    scanf(" %c%d\n", &fileira, &assento);

    if (fileira < 'A' || fileira > 'E' || assento < 1 || assento > NUM_ASSENTOS)
    {
        printf("Entrada invalida. Tente novamente.\n");
        return;
    }

    int fileiraIndex = fileira - 'A';

    if (assentos[fileiraIndex][assento - 1] == 'X')
    {
        printf("Assento ocupado. Escolha outro assento.\n");
    }
    else
    {
        assentos[fileiraIndex][assento - 1] = 'X';
        printf("Assento reservado com sucesso!\n");
    }
}

void liberarAssento(char assentos[NUM_FILEIRAS][NUM_ASSENTOS])
{
    char fileira;
    int assento;

    printf("\nDigite a fileira (A-E) e o numero do assento (1-10) para liberar:\n");
    scanf(" %c%d\n", &fileira, &assento);

    if (fileira < 'A' || fileira > 'E' || assento < 1 || assento > NUM_ASSENTOS)
    {
        printf("Entrada invalida. Tente novamente.\n");

        return;
    }

    int fileiraIndex = fileira - 'A';

    if (assentos[fileiraIndex][assento - 1] == 'O')
    {
        printf("Assento ja esta liberado. Escolha outro assento.\n");
    }
    else
    {
        assentos[fileiraIndex][assento - 1] = 'O';
        printf("Assento liberado com sucesso!\n");
    }
}

int main()
{
    char assentos[NUM_FILEIRAS][NUM_ASSENTOS];
    int escolha;

    for (int i = 0; i < NUM_FILEIRAS; i++)
    {
        for (int j = 0; j < NUM_ASSENTOS; j++)
        {
            assentos[i][j] = 'O';
        }
    }

    char lista[4][40] = {"Exibir Assentos", "Reservar Assento", "Liberar Assento", "Sair"};

    setlocale(LC_ALL, "");
    while (true)
    {
        escolha = menu(10, 10, 4, lista);

        if (escolha == 4)
        {
            break;
        }

        switch (escolha)
        {
        case 1:
            exibirAssentos(assentos);
            printf("\n");
            break;
        case 2:
            exibirAssentos(assentos);
            printf("\n");
            reservarAssento(assentos);
            break;
        case 3:
            exibirAssentos(assentos);
            printf("\n");
            liberarAssento(assentos);
            break;
        }
    }

    textColor(WHITE, _BLACK);
    linhaCol(24, 1);
    printf("");

    return 0;
}
