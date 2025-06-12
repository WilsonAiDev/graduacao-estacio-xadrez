/*
 * ♟️ Movimentação de Peças de Xadrez - Módulo Novato
 * Implementação dos movimentos básicos: Torre, Bispo e Rainha
 * Uso de estruturas de repetição: for, while, do-while
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "xadrez_novato.h"

void exibir_menu() {
    printf("\n♟️ === XADREZ - MÓDULO NOVATO ===\n");
    printf("1. Mover Torre 🏰\n");
    printf("2. Mover Bispo ⛪\n");
    printf("3. Mover Rainha 👑\n");
    printf("4. Exibir Tabuleiro\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

void exibir_tabuleiro(Tabuleiro *tabuleiro) {
    printf("\n📋 Tabuleiro Atual:\n");
    printf("  ");
    for (int j = 0; j < 8; j++) {
        printf("  %c ", 'A' + j);
    }
    printf("\n");
    
    for (int i = 7; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            if (tabuleiro->pecas[i][j] == VAZIO) {
                printf(" . ");
            } else {
                switch (tabuleiro->pecas[i][j]) {
                    case TORRE: printf(" T "); break;
                    case BISPO: printf(" B "); break;
                    case RAINHA: printf(" Q "); break;
                    default: printf(" ? "); break;
                }
            }
        }
        printf(" %d\n", i + 1);
    }
    
    printf("  ");
    for (int j = 0; j < 8; j++) {
        printf("  %c ", 'A' + j);
    }
    printf("\n");
}

int main() {
    Tabuleiro tabuleiro;
    Posicao origem, destino;
    int opcao;
    char entrada[10];
    
    // Inicializar tabuleiro
    inicializar_tabuleiro(&tabuleiro);
    
    printf("🎮 Bem-vindo ao Simulador de Xadrez - Módulo Novato!\n");
    printf("Neste módulo você aprenderá os movimentos básicos usando estruturas de repetição.\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        getchar(); // Limpar buffer
        
        switch (opcao) {
            case 1: // Torre
                printf("\n🏰 === MOVIMENTO DA TORRE ===\n");
                printf("A Torre move-se em linha reta (horizontal ou vertical)\n");
                
                printf("Posição atual da Torre (ex: A1): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &origem)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                printf("Destino da Torre (ex: A8): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &destino)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                // Colocar Torre na posição origem
                tabuleiro.pecas[origem.linha][origem.coluna] = TORRE;
                
                if (validar_movimento_torre(&origem, &destino)) {
                    mover_torre(&tabuleiro, &origem, &destino);
                    printf("✅ Torre movida com sucesso!\n");
                } else {
                    printf("❌ Movimento inválido para a Torre!\n");
                }
                break;
                
            case 2: // Bispo
                printf("\n⛪ === MOVIMENTO DO BISPO ===\n");
                printf("O Bispo move-se apenas em diagonal\n");
                
                printf("Posição atual do Bispo (ex: C1): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &origem)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                printf("Destino do Bispo (ex: H6): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &destino)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                // Colocar Bispo na posição origem
                tabuleiro.pecas[origem.linha][origem.coluna] = BISPO;
                
                if (validar_movimento_bispo(&origem, &destino)) {
                    mover_bispo(&tabuleiro, &origem, &destino);
                    printf("✅ Bispo movido com sucesso!\n");
                } else {
                    printf("❌ Movimento inválido para o Bispo!\n");
                }
                break;
                
            case 3: // Rainha
                printf("\n👑 === MOVIMENTO DA RAINHA ===\n");
                printf("A Rainha combina movimentos da Torre e do Bispo\n");
                
                printf("Posição atual da Rainha (ex: D1): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &origem)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                printf("Destino da Rainha (ex: D8): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &destino)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                // Colocar Rainha na posição origem
                tabuleiro.pecas[origem.linha][origem.coluna] = RAINHA;
                
                if (validar_movimento_rainha(&origem, &destino)) {
                    mover_rainha(&tabuleiro, &origem, &destino);
                    printf("✅ Rainha movida com sucesso!\n");
                } else {
                    printf("❌ Movimento inválido para a Rainha!\n");
                }
                break;
                
            case 4: // Exibir tabuleiro
                exibir_tabuleiro(&tabuleiro);
                break;
                
            case 5: // Sair
                printf("👋 Obrigado por usar o simulador! Até a próxima!\n");
                break;
                
            default:
                printf("❌ Opção inválida! Tente novamente.\n");
                break;
        }
        
        if (opcao != 5) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
        
    } while (opcao != 5);
    
    return 0;
}
