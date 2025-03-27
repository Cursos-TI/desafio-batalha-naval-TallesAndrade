#include <stdio.h>

int main() {
    // Definição do tabuleiro 10x10
    int tabuleiro[10][10] = {0};

    // Coordenadas do navio vertical
    int linhaV = 4, colunaV = 2;

    // Verifica se o navio vertical cabe no tabuleiro antes de posicioná-lo
    if (linhaV + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = 3;
        }
    }

    // Coordenadas do navio horizontal
    int linhaH = 7, colunaH = 5;

    // Verifica se o navio horizontal cabe no tabuleiro antes de posicioná-lo
    if (colunaH + 3 <= 10) {
        // Verificação de não haver sobreposição
        int podePosicionar = 1;
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[linhaH][colunaH + j] != 0) {
                podePosicionar = 0; 
                break;
            }
        }
        
        // Se não houver sobreposição posiciona o navio horizontal
        if (podePosicionar) {
            for (int j = 0; j < 3; j++) {
                tabuleiro[linhaH][colunaH + j] = 3;
            }
        } else {
            printf("Erro: Tentativa de sobreposição de navios! Escolha outra posição.\n");
        }
    }

    // Exibe o tabuleiro 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
