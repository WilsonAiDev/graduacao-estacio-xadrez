/*
 * ♟️ Implementação da Rainha - Módulo Novato
 * Movimento combinado usando estruturas de repetição
 */

#include <stdio.h>
#include <stdlib.h>
#include "xadrez_novato.h"

int validar_movimento_rainha(Posicao *origem, Posicao *destino) {
    // Validar se as posições estão dentro do tabuleiro
    if (!validar_posicao(origem) || !validar_posicao(destino)) {
        printf("❌ Posições fora do tabuleiro!\n");
        return 0;
    }
    
    // Rainha combina movimentos da Torre e do Bispo
    int mesma_linha = (origem->linha == destino->linha);
    int mesma_coluna = (origem->coluna == destino->coluna);
    int diff_linha = abs(destino->linha - origem->linha);
    int diff_coluna = abs(destino->coluna - origem->coluna);
    
    // Não pode ficar na mesma posição
    if (mesma_linha && mesma_coluna) {
        printf("❌ Origem e destino são iguais!\n");
        return 0;
    }
    
    // Movimento linear (como Torre) OU diagonal (como Bispo)
    int movimento_linear = (mesma_linha || mesma_coluna);
    int movimento_diagonal = (diff_linha == diff_coluna);
    
    if (!(movimento_linear || movimento_diagonal)) {
        printf("❌ Rainha só pode mover-se em linha reta ou diagonal!\n");
        return 0;
    }
    
    printf("✅ Movimento válido para a Rainha!\n");
    return 1;
}

void mover_rainha(Tabuleiro *tabuleiro, Posicao *origem, Posicao *destino) {
    printf("\n👑 === EXECUTANDO MOVIMENTO DA RAINHA ===\n");
    
    // Limpar posição de origem
    tabuleiro->pecas[origem->linha][origem->coluna] = VAZIO;
    
    // Determinar tipo de movimento
    int mesma_linha = (origem->linha == destino->linha);
    int mesma_coluna = (origem->coluna == destino->coluna);
    int diff_linha = abs(destino->linha - origem->linha);
    int diff_coluna = abs(destino->coluna - origem->coluna);
    
    printf("📍 Simulando movimento da Rainha passo a passo:\n");
    
    if (mesma_linha || mesma_coluna) {
        // Movimento linear - usando DO-WHILE
        printf("Movimento LINEAR usando estrutura DO-WHILE:\n");
        
        int linha_atual = origem->linha;
        int coluna_atual = origem->coluna;
        int passo = 0;
        
        do {
            printf("Passo %d: %c%d", passo + 1, 'A' + coluna_atual, linha_atual + 1);
            if (passo == 0) printf(" (origem)");
            
            // Determinar próximo passo
            if (mesma_linha) {
                // Movimento horizontal
                if (destino->coluna > origem->coluna) {
                    coluna_atual++;
                } else {
                    coluna_atual--;
                }
            } else {
                // Movimento vertical
                if (destino->linha > origem->linha) {
                    linha_atual++;
                } else {
                    linha_atual--;
                }
            }
            
            if (linha_atual == destino->linha && coluna_atual == destino->coluna) {
                printf("\nPasso %d: %c%d (destino)", passo + 2, 'A' + coluna_atual, linha_atual + 1);
            }
            printf("\n");
            passo++;
            
        } while (linha_atual != destino->linha || coluna_atual != destino->coluna);
        
    } else if (diff_linha == diff_coluna) {
        // Movimento diagonal - usando DO-WHILE
        printf("Movimento DIAGONAL usando estrutura DO-WHILE:\n");
        
        int dir_linha = (destino->linha > origem->linha) ? 1 : -1;
        int dir_coluna = (destino->coluna > origem->coluna) ? 1 : -1;
        
        int linha_atual = origem->linha;
        int coluna_atual = origem->coluna;
        int passo = 0;
        
        do {
            printf("Passo %d: %c%d", passo + 1, 'A' + coluna_atual, linha_atual + 1);
            if (passo == 0) printf(" (origem)");
            
            linha_atual += dir_linha;
            coluna_atual += dir_coluna;
            
            if (linha_atual == destino->linha && coluna_atual == destino->coluna) {
                printf("\nPasso %d: %c%d (destino)", passo + 2, 'A' + coluna_atual, linha_atual + 1);
            }
            printf("\n");
            passo++;
            
        } while (linha_atual != destino->linha || coluna_atual != destino->coluna);
    }
    
    // Colocar Rainha na posição destino
    tabuleiro->pecas[destino->linha][destino->coluna] = RAINHA;
    
    // Exibir informações do movimento
    if (mesma_linha || mesma_coluna) {
        exibir_caminho(origem, destino, "Linear (Rainha)");
    } else {
        exibir_caminho(origem, destino, "Diagonal (Rainha)");
    }
    
    printf("🎯 Rainha movida usando estrutura de repetição DO-WHILE!\n");
}
