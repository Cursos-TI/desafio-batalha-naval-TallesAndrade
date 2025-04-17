#include <stdio.h>

int main() {
    // Definição do tabuleiro 10x10
    int tabuleiro[10][10] = {0};

    // Coordenadas do navio vertical
    int linhaV = 4, colunaV = 2;

    if (linhaV + 3 <= 10) {
        int podePosicionar = 1;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if (podePosicionar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro: Sobreposição no navio vertical.\n");
        }
    }

    // Coordenadas do navio horizontal
    int linhaH = 7, colunaH = 5;

    if (colunaH + 3 <= 10) {
        int podePosicionar = 1;
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[linhaH][colunaH + j] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if (podePosicionar) {
            for (int j = 0; j < 3; j++) {
                tabuleiro[linhaH][colunaH + j] = 3;
            }
        } else {
            printf("Erro: Sobreposição no navio horizontal.\n");
        }
    }

    // Coordenadas do navio diagonal principal
    int linhaD1 = 0, colunaD1 = 6;

    if (linhaD1 + 3 <= 10 && colunaD1 + 3 <= 10) {
        int podePosicionar = 1;
        for (int d = 0; d < 3; d++) {
            if (tabuleiro[linhaD1 + d][colunaD1 + d] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if (podePosicionar) {
            for (int d = 0; d < 3; d++) {
                tabuleiro[linhaD1 + d][colunaD1 + d] = 3;
            }
        } else {
            printf("Erro: Sobreposição no navio diagonal principal.\n");
        }
    }

    // Coordenadas do navio diagonal secundária 
    int linhaD2 = 6, colunaD2 = 2;

    if (linhaD2 + 3 <= 10 && colunaD2 - 2 >= 0) {
        int podePosicionar = 1;
        for (int d = 0; d < 3; d++) {
            if (tabuleiro[linhaD2 + d][colunaD2 - d] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if (podePosicionar) {
            for (int d = 0; d < 3; d++) {
                tabuleiro[linhaD2 + d][colunaD2 - d] = 3;
            }
        } else {
            printf("Erro: Sobreposição no navio diagonal secundária.\n");
        }
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
