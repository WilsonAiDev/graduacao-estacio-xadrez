/*
 * ♟️ Implementação do Bispo - Módulo Novato
 * Movimento diagonal usando estruturas de repetição
 */

#include <stdio.h>
#include <stdlib.h>
#include "xadrez_novato.h"

int validar_movimento_bispo(Posicao *origem, Posicao *destino) {
    // Validar se as posições estão dentro do tabuleiro
    if (!validar_posicao(origem) || !validar_posicao(destino)) {
        printf("❌ Posições fora do tabuleiro!\n");
        return 0;
    }
    
    // Bispo move-se apenas em diagonal
    int diff_linha = abs(destino->linha - origem->linha);
    int diff_coluna = abs(destino->coluna - origem->coluna);
    
    if (diff_linha != diff_coluna) {
        printf("❌ Bispo só pode mover-se em diagonal!\n");
        return 0;
    }
    
    // Não pode ficar na mesma posição
    if (diff_linha == 0 && diff_coluna == 0) {
        printf("❌ Origem e destino são iguais!\n");
        return 0;
    }
    
    printf("✅ Movimento válido para o Bispo!\n");
    return 1;
}

void mover_bispo(Tabuleiro *tabuleiro, Posicao *origem, Posicao *destino) {
    printf("\n⛪ === EXECUTANDO MOVIMENTO DO BISPO ===\n");
    
    // Limpar posição de origem
    tabuleiro->pecas[origem->linha][origem->coluna] = VAZIO;
    
    // Demonstrar o caminho usando WHILE loop
    printf("📍 Simulando movimento diagonal passo a passo:\n");
    printf("Movimento DIAGONAL usando estrutura WHILE:\n");
    
    // Determinar direção do movimento
    int dir_linha = (destino->linha > origem->linha) ? 1 : -1;
    int dir_coluna = (destino->coluna > origem->coluna) ? 1 : -1;
    
    // Usar WHILE para percorrer o caminho diagonal
    int linha_atual = origem->linha;
    int coluna_atual = origem->coluna;
    int passo = 0;
    
    while (linha_atual != destino->linha && coluna_atual != destino->coluna) {
        printf("Passo %d: %c%d", passo + 1, 'A' + coluna_atual, linha_atual + 1);
        if (passo == 0) printf(" (origem)");
        printf("\n");
        
        linha_atual += dir_linha;
        coluna_atual += dir_coluna;
        passo++;
    }
    
    // Mostrar posição final
    printf("Passo %d: %c%d (destino)\n", passo + 1, 'A' + destino->coluna, destino->linha + 1);
    
    // Colocar Bispo na posição destino
    tabuleiro->pecas[destino->linha][destino->coluna] = BISPO;
    
    // Exibir informações do movimento
    exibir_caminho(origem, destino, "Diagonal (Bispo)");
    
    printf("🎯 Bispo movido usando estrutura de repetição WHILE!\n");
}
