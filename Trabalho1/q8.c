#include <stdio.h>
#include <string.h>

void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n   1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n  ---+---+---\n");
    }
    printf("\n");
}

int verificarGanhador(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return tabuleiro[i][0] == 'X' ? 1 : 2;
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return tabuleiro[0][i] == 'X' ? 1 : 2;
    }

    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return tabuleiro[0][0] == 'X' ? 1 : 2;
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return tabuleiro[0][2] == 'X' ? 1 : 2;

    return 0;
}

int main() {
    char tabuleiro[3][3];
    memset(tabuleiro, ' ', sizeof(tabuleiro));

    int jogador = 1;
    int jogadas = 0;

    while (1) {
        imprimirTabuleiro(tabuleiro);
        printf("Jogador %d (%c), informe sua jogada (ex: B2): ", jogador, jogador == 1 ? 'X' : 'O');

        char jogada[3];
        scanf("%s", jogada);

        if (strlen(jogada) != 2 ||
            jogada[0] < 'A' || jogada[0] > 'C' ||
            jogada[1] < '1' || jogada[1] > '3') {
            printf("Jogada invalida! Tente novamente.\n");
            continue;
        }

        int linha = jogada[0] - 'A';
        int coluna = jogada[1] - '1';

        if (tabuleiro[linha][coluna] != ' ') {
            printf("Celula ocupada! Escolha outra.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador == 1 ? 'X' : 'O';
        jogadas++;

        int vencedor = verificarGanhador(tabuleiro);
        if (vencedor != 0) {
            imprimirTabuleiro(tabuleiro);
            printf("Jogador %d venceu!\n", vencedor);
            break;
        }

        if (jogadas == 9) {
            imprimirTabuleiro(tabuleiro);
            printf("Deu velha! Ninguem venceu.\n");
            break;
        }

        jogador = jogador == 1 ? 2 : 1;
    }

    return 0;
}
