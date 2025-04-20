#include <stdio.h>

// Função para aplicar uma habilidade (matriz 3x5) no tabuleiro
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[3][5], int linhaInicial, int colunaInicial) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = linhaInicial + i;
            int coluna = colunaInicial + j;
            // Verifica se está dentro dos limites do tabuleiro
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha][coluna] = 1; // Marca área da habilidade com 1
                }
            }
        }
    }
}

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

    // Definição das matrizes de habilidades (3x5)
    int cone[3][5] = {0};
    int cruz[3][5] = {0};
    int octaedro[3][5] = {0};

    // Padrão Cone
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            cone[i][j] = 1;
        }
    }

    // Padrão Cruz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 1 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Padrão Octaedro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 1 && j >= 1 && j <= 3) || (j == 2 && (i == 0 || i == 2))) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Aplicação das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 0, 0);        // Aplica Cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 3, 4);        // Aplica Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 6, 5);    // Aplica Octaedro na parte inferior direita

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
