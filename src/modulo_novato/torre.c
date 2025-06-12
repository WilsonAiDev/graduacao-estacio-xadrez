/*
 * ♟️ Implementação da Torre - Módulo Novato
 * Movimento linear usando estruturas de repetição
 */

#include <stdio.h>
#include <stdlib.h>
#include "xadrez_novato.h"

int validar_movimento_torre(Posicao *origem, Posicao *destino) {
    // Validar se as posições estão dentro do tabuleiro
    if (!validar_posicao(origem) || !validar_posicao(destino)) {
        printf("❌ Posições fora do tabuleiro!\n");
        return 0;
    }
    
    // Torre move-se apenas em linha reta (horizontal ou vertical)
    // Deve estar na mesma linha OU na mesma coluna, mas não ambos
    int mesma_linha = (origem->linha == destino->linha);
    int mesma_coluna = (origem->coluna == destino->coluna);
    
    if (!(mesma_linha || mesma_coluna)) {
        printf("❌ Torre só pode mover-se em linha reta!\n");
        return 0;
    }
    
    // Não pode ficar na mesma posição
    if (mesma_linha && mesma_coluna) {
        printf("❌ Origem e destino são iguais!\n");
        return 0;
    }
    
    printf("✅ Movimento válido para a Torre!\n");
    return 1;
}

void mover_torre(Tabuleiro *tabuleiro, Posicao *origem, Posicao *destino) {
    printf("\n🏰 === EXECUTANDO MOVIMENTO DA TORRE ===\n");
    
    // Limpar posição de origem
    tabuleiro->pecas[origem->linha][origem->coluna] = VAZIO;
    
    // Demonstrar o caminho usando FOR loop
    printf("📍 Simulando movimento passo a passo:\n");
    
    if (origem->linha == destino->linha) {
        // Movimento horizontal - usando FOR
        printf("Movimento HORIZONTAL usando estrutura FOR:\n");
        int inicio = (origem->coluna < destino->coluna) ? origem->coluna : destino->coluna;
        int fim = (origem->coluna > destino->coluna) ? origem->coluna : destino->coluna;
        
        for (int col = inicio; col <= fim; col++) {
            printf("Posição: %c%d", 'A' + col, origem->linha + 1);
            if (col == origem->coluna) printf(" (origem)");
            if (col == destino->coluna) printf(" (destino)");
            printf("\n");
        }
    } else {
        // Movimento vertical - usando FOR
        printf("Movimento VERTICAL usando estrutura FOR:\n");
        int inicio = (origem->linha < destino->linha) ? origem->linha : destino->linha;
        int fim = (origem->linha > destino->linha) ? origem->linha : destino->linha;
        
        for (int linha = inicio; linha <= fim; linha++) {
            printf("Posição: %c%d", 'A' + origem->coluna, linha + 1);
            if (linha == origem->linha) printf(" (origem)");
            if (linha == destino->linha) printf(" (destino)");
            printf("\n");
        }
    }
    
    // Colocar Torre na posição destino
    tabuleiro->pecas[destino->linha][destino->coluna] = TORRE;
    
    // Exibir informações do movimento
    exibir_caminho(origem, destino, "Linear (Torre)");
    
    printf("🎯 Torre movida usando estrutura de repetição FOR!\n");
}
