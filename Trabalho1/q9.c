#include <stdio.h>
#include <string.h>

#define TAM 10
#define MAX_NAVIOS 5

char tabuleiro1[TAM][TAM];
char tabuleiro2[TAM][TAM];

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro(char tabuleiro[TAM][TAM], int mostrarNavios) {
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%c |", 'A' + i);
        for (int j = 0; j < TAM; j++) {
            char c = tabuleiro[i][j];
            if (c == 'N' && !mostrarNavios) c = ' ';
            printf("%c|", c);
        }
        printf("\n");
    }
}

int posicaoValida(int x, int y) {
    return x >= 0 && x < TAM && y >= 0 && y < TAM;
}

int podeColocar(char tabuleiro[TAM][TAM], int x, int y, int tamanho, int horizontal) {
    for (int i = 0; i < tamanho; i++) {
        int nx = x + (horizontal ? 0 : i);
        int ny = y + (horizontal ? i : 0);
        if (!posicaoValida(nx, ny) || tabuleiro[nx][ny] != ' ') return 0;
    }
    return 1;
}

void colocarNavio(char tabuleiro[TAM][TAM], int x, int y, int tamanho, int horizontal) {
    for (int i = 0; i < tamanho; i++) {
        int nx = x + (horizontal ? 0 : i);
        int ny = y + (horizontal ? i : 0);
        tabuleiro[nx][ny] = 'N';
    }
}

void posicionarNavios(char tabuleiro[TAM][TAM]) {
    int navios[5] = {4, 3, 1, 1, 1};
    for (int i = 0; i < MAX_NAVIOS; i++) {
        int x, y, horizontal;
        int ok = 0;
        while (!ok) {
            imprimirTabuleiro(tabuleiro, 1);
            printf("Posicione o navio de tamanho %d (ex: 1A H): ", navios[i]);
            char linha;
            scanf(" %c%d %c", &linha, &y, &linha);
            x = linha - 'A';
            horizontal = (linha == 'H' || linha == 'h');
            if (podeColocar(tabuleiro, x, y, navios[i], horizontal)) {
                colocarNavio(tabuleiro, x, y, navios[i], horizontal);
                ok = 1;
            } else {
                printf("Posicao invalida, tente novamente.\n");
            }
        }
    }
}

int atirar(char tabuleiro[TAM][TAM], int x, int y) {
    if (!posicaoValida(x, y)) return -1;
    if (tabuleiro[x][y] == 'N') {
        tabuleiro[x][y] = '0';
        return 1;
    } else if (tabuleiro[x][y] == ' ') {
        tabuleiro[x][y] = 'X';
        return 0;
    }
    return -1;
}

int venceu(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 'N') return 0;
        }
    }
    return 1;
}

int main() {
    inicializarTabuleiro(tabuleiro1);
    inicializarTabuleiro(tabuleiro2);

    printf("Jogador 1 posicione seus navios\n");
    posicionarNavios(tabuleiro1);
    printf("Jogador 2 posicione seus navios\n");
    posicionarNavios(tabuleiro2);

    int vez = 1;
    while (1) {
        printf("Tabuleiro Jogador 1 (seu):\n");
        imprimirTabuleiro(tabuleiro1, 1);
        printf("Tabuleiro Jogador 2 (visao):\n");
        imprimirTabuleiro(tabuleiro2, 0);

        int x, y;
        char linha;
        printf("Jogador %d, informe onde quer atirar (ex: A0): ", vez);
        scanf(" %c%d", &linha, &y);
        x = linha - 'A';

        int resultado;
        if (vez == 1) {
            resultado = atirar(tabuleiro2, x, y);
        } else {
            resultado = atirar(tabuleiro1, x, y);
        }

        if (resultado == 1) {
            printf("Acertou!\n");
        } else if (resultado == 0) {
            printf("Errou!\n");
        } else {
            printf("Tiro invalido.\n");
            continue;
        }

        if (venceu(vez == 1 ? tabuleiro2 : tabuleiro1)) {
            printf("Jogador %d venceu!\n", vez);
            break;
        }

        vez = 3 - vez; 
    }

    return 0;
}
