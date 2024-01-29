#include <stdio.h>

#define NUM_FILEIRAS 5
#define NUM_ASSENTOS 10


void exibirAssentos(char assentos[NUM_FILEIRAS][NUM_ASSENTOS]) {
    printf("\nLayout dos Assentos:\n\n");
    printf("   ");
    for (int i = 1; i <= NUM_ASSENTOS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < NUM_FILEIRAS; i++) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < NUM_ASSENTOS; j++) {
            printf("%c ", assentos[i][j]);
        }
        printf("\n");
    }
    
}

void reservarAssento(char assentos[NUM_FILEIRAS][NUM_ASSENTOS]) {
    char fileira;
    int assento;

    printf("\nDigite a fileira (A-E) e o numero do assento (1-10) para reservar:\n");
    scanf(" %c%d", &fileira, &assento);

    if (fileira < 'A' || fileira > 'E' || assento < 1 || assento > NUM_ASSENTOS) {
        printf("Entrada invalida. Tente novamente.\n");
        return;
    }

    int fileiraIndex = fileira - 'A';

    if (assentos[fileiraIndex][assento - 1] == 'X') {
        printf("Assento ocupado. Escolha outro assento.\n");
    } else {
        assentos[fileiraIndex][assento - 1] = 'X';
        printf("Assento reservado com sucesso!\n");
    }
}

void liberarAssento(char assentos[NUM_FILEIRAS][NUM_ASSENTOS]) {
    char fileira;
    int assento;

    printf("\nDigite a fileira (A-E) e o numero do assento (1-10) para liberar:\n");
    scanf(" %c%d", &fileira, &assento);

    if (fileira < 'A' || fileira > 'E' || assento < 1 || assento > NUM_ASSENTOS) {
        printf("Entrada invalida. Tente novamente.\n");
        return;
    }

    int fileiraIndex = fileira - 'A';

    if (assentos[fileiraIndex][assento - 1] == 'O') {
        printf("Assento já esta liberado. Escolha outro assento.\n");
    } else {
        assentos[fileiraIndex][assento - 1] = 'O';
        printf("Assento liberado com sucesso!\n");
    }
}

int main() {
    char assentos[NUM_FILEIRAS][NUM_ASSENTOS];

    for (int i = 0; i < NUM_FILEIRAS; i++) {
        for (int j = 0; j < NUM_ASSENTOS; j++) {
            assentos[i][j] = 'O';
        }
    }

    int escolha;

    do {
        printf("\nMenu:\n\n");
        printf("1. Exibir Assentos\n");
        printf("2. Reservar Assento\n");
        printf("3. Liberar Assento\n");
        printf("0. Sair\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                exibirAssentos(assentos);
                break;
            case 2:
                reservarAssento(assentos);
                break;
            case 3:
                liberarAssento(assentos);
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}
