/*
 * ♟️ Utilitários do Módulo Aventureiro
 * Funções de apoio para visualização e análise
 */

#include <stdio.h>
#include <stdlib.h>
#include "xadrez_novato.h"
#include "xadrez_aventureiro.h"

void listar_movimentos_possiveis(Posicao *posicao_atual, Posicao movimentos_validos[], int *num_movimentos) {
    MovimentoCavalo movimentos[MOVIMENTOS_CAVALO];
    
    // Inicializar movimentos silenciosamente
    int direcoes[4][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    int contador = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                movimentos[contador].delta_linha = direcoes[i][0];
                movimentos[contador].delta_coluna = direcoes[i][1];
            } else {
                movimentos[contador].delta_linha = direcoes[i][1];
                movimentos[contador].delta_coluna = direcoes[i][0];
            }
            contador++;
        }
    }
    
    *num_movimentos = 0;
    
    printf("\n🔍 Analisando movimentos possíveis:\n");
    
    // Loop para verificar todos os movimentos possíveis
    for (int i = 0; i < MOVIMENTOS_CAVALO; i++) {
        Posicao nova_posicao;
        nova_posicao.linha = posicao_atual->linha + movimentos[i].delta_linha;
        nova_posicao.coluna = posicao_atual->coluna + movimentos[i].delta_coluna;
        
        if (validar_posicao(&nova_posicao)) {
            printf("✅ %c%d ", 'A' + nova_posicao.coluna, nova_posicao.linha + 1);
            movimentos_validos[*num_movimentos] = nova_posicao;
            (*num_movimentos)++;
        }
    }
    
    printf("\nTotal de movimentos válidos: %d\n", *num_movimentos);
}

void mostrar_possibilidades_cavalo(Posicao *posicao) {
    Posicao movimentos_validos[MOVIMENTOS_CAVALO];
    int num_movimentos;
    
    printf("🐎 Posição atual do Cavalo: %c%d\n", 'A' + posicao->coluna, posicao->linha + 1);
    
    listar_movimentos_possiveis(posicao, movimentos_validos, &num_movimentos);
    
    if (num_movimentos > 0) {
        printf("\n🎯 Destinos possíveis:\n");
        
        // Usar loops aninhados para exibir de forma organizada
        for (int linha = 7; linha >= 0; linha--) {
            for (int coluna = 0; coluna < 8; coluna++) {
                int eh_posicao_atual = (linha == posicao->linha && coluna == posicao->coluna);
                int eh_movimento_valido = 0;
                
                // Loop interno para verificar se é movimento válido
                for (int i = 0; i < num_movimentos; i++) {
                    if (movimentos_validos[i].linha == linha && movimentos_validos[i].coluna == coluna) {
                        eh_movimento_valido = 1;
                        break;
                    }
                }
                
                if (eh_posicao_atual) {
                    printf(" 🐎");
                } else if (eh_movimento_valido) {
                    printf(" ⭐");
                } else {
                    printf(" . ");
                }
            }
            printf(" %d\n", linha + 1);
        }
        
        printf("  A  B  C  D  E  F  G  H\n");
        printf("🐎 = Cavalo atual | ⭐ = Movimentos possíveis\n");
    }
}

void exibir_tabuleiro_aventureiro(Tabuleiro *tabuleiro, HistoricoMovimento *historico) {
    printf("\n📋 Tabuleiro do Módulo Aventureiro:\n");
    printf("  ");
    for (int j = 0; j < 8; j++) {
        printf("  %c ", 'A' + j);
    }
    printf("\n");
    
    // Usar loops aninhados para exibir o tabuleiro
    for (int i = 7; i >= 0; i--) {
        printf("%d ", i + 1);
        
        for (int j = 0; j < 8; j++) {
            int eh_historico = 0;
            
            // Loop interno para verificar histórico
            for (int h = 0; h < historico->num_movimentos; h++) {
                if (historico->posicoes[h].linha == i && historico->posicoes[h].coluna == j) {
                    eh_historico = 1;
                    break;
                }
            }
            
            if (tabuleiro->pecas[i][j] == VAZIO) {
                if (eh_historico) {
                    printf(" * "); // Marca posições visitadas
                } else {
                    printf(" . ");
                }
            } else {
                switch (tabuleiro->pecas[i][j]) {
                    case TORRE: printf(" T "); break;
                    case BISPO: printf(" B "); break;
                    case RAINHA: printf(" Q "); break;
                    case CAVALO: printf(" 🐎"); break;
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
    
    if (historico->num_movimentos > 0) {
        printf("* = Posições visitadas pelo Cavalo\n");
    }
}

void exibir_estatisticas_movimento(HistoricoMovimento *historico) {
    if (historico->num_movimentos == 0) {
        printf("Nenhum movimento registrado.\n");
        return;
    }
    
    printf("Total de movimentos: %d\n", historico->num_movimentos);
    printf("Posições visitadas:\n");
    
    // Usar loops aninhados para organizar as estatísticas
    for (int i = 0; i < historico->num_movimentos; i++) {
        for (int formato = 0; formato < 1; formato++) { // Loop interno para demonstração
            printf("%d. %c%d", 
                   i + 1, 
                   'A' + historico->posicoes[i].coluna, 
                   historico->posicoes[i].linha + 1);
            
            if ((i + 1) % 4 == 0) {
                printf("\n");
            } else if (i < historico->num_movimentos - 1) {
                printf(" -> ");
            }
        }
    }
    
    if (historico->num_movimentos % 4 != 0) {
        printf("\n");
    }
    
    // Calcular cobertura do tabuleiro
    int casas_visitadas = 0;
    int tabuleiro_visitado[8][8] = {0};
    
    for (int i = 0; i < historico->num_movimentos; i++) {
        int linha = historico->posicoes[i].linha;
        int coluna = historico->posicoes[i].coluna;
        
        if (!tabuleiro_visitado[linha][coluna]) {
            tabuleiro_visitado[linha][coluna] = 1;
            casas_visitadas++;
        }
    }
    
    printf("Casas únicas visitadas: %d/64 (%.1f%%)\n", 
           casas_visitadas, (casas_visitadas * 100.0) / 64);
}
