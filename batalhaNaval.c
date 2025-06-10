#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAM 10
#define FIG 5

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[TAM][TAM] = {0};  // matriz 10x10
    int i, j;
    
    int cone[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    };

    int cruz[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0},
    };

    int octaedro[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    };

    // Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
// Posicionar um navio na vertical - nível novato
   // tabuleiro[6][2] = 3;
   // tabuleiro[7][2] = 3;
   // tabuleiro[8][2] = 3;

    // Posicionar do navio 1 na horizontal
    tabuleiro[5][6] = 3;
    tabuleiro[5][7] = 3;
    tabuleiro[5][8] = 3;

    // Posicionar do navio 2 na horizontal
    tabuleiro[9][6] = 3;
    tabuleiro[9][7] = 3;
    tabuleiro[9][8] = 3;

    // Navio na 1ª diagonal
    for (i = 0; i < 7; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio na 2ª diagonal
    for (i = 7; i < 10; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    void imprimirMatriz(int matriz[5][5], const char* nome){
    printf("\n%s:\n", nome);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
    imprimirMatriz(cone, "Cone");
    imprimirMatriz(cruz, "Cruz");
    imprimirMatriz(octaedro, "Octaedro");

     void sobrepor(int destino[TAM][TAM], int figura[5][5], int lin, int col){
        for (int i = 0; i < FIG; i++) {
            for (int j = 0; j < FIG; j++) {
                if (lin + i < TAM && col + j < TAM) {
                    if (figura[i][j] == 1)
                        destino[lin + i][col + j] = 1;
                }
            }
        }
    }

    // Sobrepor as 3 figuras em posições diferentes
    sobrepor(tabuleiro, cone, 0, 0);       // canto superior esquerdo
    sobrepor(tabuleiro, cruz, 0, 5);       // canto superior direito
    sobrepor(tabuleiro, octaedro, 5, 0);   // canto inferior esquerdo

    // Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
