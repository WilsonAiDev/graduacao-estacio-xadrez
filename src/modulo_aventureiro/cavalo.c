/*
 * ♟️ Implementação do Cavalo - Módulo Aventureiro
 * Movimento em "L" usando loops aninhados
 */

#include <stdio.h>
#include <stdlib.h>
#include "xadrez_novato.h"
#include "xadrez_aventureiro.h"

void inicializar_movimentos_cavalo(MovimentoCavalo movimentos[MOVIMENTOS_CAVALO]) {
    // Os 8 movimentos possíveis do Cavalo em formato L
    // Inicialização silenciosa para evitar spam de output
    
    int direcoes[4][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    int contador = 0;
    
    // Loop aninhado para gerar todos os movimentos em L
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                // Movimento longo na vertical, curto na horizontal
                movimentos[contador].delta_linha = direcoes[i][0];
                movimentos[contador].delta_coluna = direcoes[i][1];
            } else {
                // Inverter: movimento longo na horizontal, curto na vertical
                movimentos[contador].delta_linha = direcoes[i][1];
                movimentos[contador].delta_coluna = direcoes[i][0];
            }
            contador++;
        }
    }
}

void inicializar_movimentos_cavalo_verbose(MovimentoCavalo movimentos[MOVIMENTOS_CAVALO]) {
    // Versão com output detalhado para demonstrações
    printf("🔄 Inicializando movimentos do Cavalo com loops aninhados:\n");
    
    int direcoes[4][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    int contador = 0;
    
    // Loop aninhado para gerar todos os movimentos em L
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                // Movimento longo na vertical, curto na horizontal
                movimentos[contador].delta_linha = direcoes[i][0];
                movimentos[contador].delta_coluna = direcoes[i][1];
            } else {
                // Inverter: movimento longo na horizontal, curto na vertical
                movimentos[contador].delta_linha = direcoes[i][1];
                movimentos[contador].delta_coluna = direcoes[i][0];
            }
            
            printf("Movimento %d: (%+d, %+d)\n", 
                   contador + 1, 
                   movimentos[contador].delta_linha, 
                   movimentos[contador].delta_coluna);
            
            contador++;
        }
    }
    printf("✅ 8 movimentos do Cavalo inicializados!\n");
}

int validar_movimento_cavalo(Posicao *origem, Posicao *destino) {
    // Validar se as posições estão dentro do tabuleiro
    if (!validar_posicao(origem) || !validar_posicao(destino)) {
        printf("❌ Posições fora do tabuleiro!\n");
        return 0;
    }
    
    // Não pode ficar na mesma posição
    if (origem->linha == destino->linha && origem->coluna == destino->coluna) {
        printf("❌ Origem e destino são iguais!\n");
        return 0;
    }
    
    // Verificar se é um movimento em L válido
    if (!verificar_movimento_L(origem, destino)) {
        printf("❌ Cavalo deve mover-se em formato de L!\n");
        return 0;
    }
    
    printf("✅ Movimento em L válido para o Cavalo!\n");
    return 1;
}

int verificar_movimento_L(Posicao *origem, Posicao *destino) {
    int diff_linha = abs(destino->linha - origem->linha);
    int diff_coluna = abs(destino->coluna - origem->coluna);
    
    // Movimento em L: (2,1) ou (1,2)
    return (diff_linha == 2 && diff_coluna == 1) || 
           (diff_linha == 1 && diff_coluna == 2);
}

void mover_cavalo(Tabuleiro *tabuleiro, Posicao *origem, Posicao *destino) {
    printf("\n🐎 === EXECUTANDO MOVIMENTO DO CAVALO ===\n");
    
    // Limpar posição de origem
    tabuleiro->pecas[origem->linha][origem->coluna] = VAZIO;
    
    // Demonstrar o movimento usando loops aninhados
    demonstrar_movimento_cavalo(origem, destino);
    
    // Colocar Cavalo na posição destino
    tabuleiro->pecas[destino->linha][destino->coluna] = CAVALO;
    
    // Exibir informações do movimento
    exibir_caminho(origem, destino, "Movimento em L (Cavalo)");
    
    printf("🎯 Cavalo movido usando conceito de loops aninhados!\n");
}

void demonstrar_movimento_cavalo(Posicao *origem, Posicao *destino) {
    printf("📍 Demonstrando movimento em L com loops aninhados:\n\n");
    
    // Determinar as componentes do movimento
    int diff_linha = destino->linha - origem->linha;
    int diff_coluna = destino->coluna - origem->coluna;
    
    printf("Análise do movimento:\n");
    printf("- Diferença em linhas: %+d\n", diff_linha);
    printf("- Diferença em colunas: %+d\n", diff_coluna);
    
    // Usar loops aninhados para simular o movimento em duas etapas
    printf("\n🔄 Simulação com loops aninhados:\n");
    
    if (abs(diff_linha) == 2) {
        // Primeiro movimento: 2 casas na vertical
        printf("Fase 1 - Movimento vertical (2 casas):\n");
        int direcao_linha = (diff_linha > 0) ? 1 : -1;
        
        for (int passo = 0; passo <= 2; passo++) {
            for (int sub_passo = 0; sub_passo < 1; sub_passo++) { // Loop interno para demonstração
                if (passo == 0) {
                    printf("  Posição inicial: %c%d\n", 
                           'A' + origem->coluna, origem->linha + 1);
                } else if (passo == 1) {
                    printf("  Após 1ª casa vertical: %c%d\n", 
                           'A' + origem->coluna, origem->linha + direcao_linha + 1);
                } else {
                    printf("  Após 2ª casa vertical: %c%d\n", 
                           'A' + origem->coluna, origem->linha + (2 * direcao_linha) + 1);
                }
            }
        }
        
        // Segundo movimento: 1 casa na horizontal
        printf("\nFase 2 - Movimento horizontal (1 casa):\n");
        int direcao_coluna = (diff_coluna > 0) ? 1 : -1;
        
        for (int passo = 0; passo <= 1; passo++) {
            for (int sub_passo = 0; sub_passo < 1; sub_passo++) { // Loop interno para demonstração
                if (passo == 0) {
                    printf("  Antes do movimento horizontal: %c%d\n", 
                           'A' + origem->coluna, destino->linha + 1);
                } else {
                    printf("  DESTINO FINAL: %c%d ✨\n", 
                           'A' + destino->coluna, destino->linha + 1);
                }
            }
        }
        
    } else {
        // Primeiro movimento: 2 casas na horizontal
        printf("Fase 1 - Movimento horizontal (2 casas):\n");
        int direcao_coluna = (diff_coluna > 0) ? 1 : -1;
        
        for (int passo = 0; passo <= 2; passo++) {
            for (int sub_passo = 0; sub_passo < 1; sub_passo++) { // Loop interno para demonstração
                if (passo == 0) {
                    printf("  Posição inicial: %c%d\n", 
                           'A' + origem->coluna, origem->linha + 1);
                } else if (passo == 1) {
                    printf("  Após 1ª casa horizontal: %c%d\n", 
                           'A' + origem->coluna + direcao_coluna, origem->linha + 1);
                } else {
                    printf("  Após 2ª casa horizontal: %c%d\n", 
                           'A' + origem->coluna + (2 * direcao_coluna), origem->linha + 1);
                }
            }
        }
        
        // Segundo movimento: 1 casa na vertical
        printf("\nFase 2 - Movimento vertical (1 casa):\n");
        int direcao_linha = (diff_linha > 0) ? 1 : -1;
        
        for (int passo = 0; passo <= 1; passo++) {
            for (int sub_passo = 0; sub_passo < 1; sub_passo++) { // Loop interno para demonstração
                if (passo == 0) {
                    printf("  Antes do movimento vertical: %c%d\n", 
                           'A' + destino->coluna, origem->linha + 1);
                } else {
                    printf("  DESTINO FINAL: %c%d ✨\n", 
                           'A' + destino->coluna, destino->linha + 1);
                }
            }
        }
    }
    
    printf("\n🎯 Movimento em L concluído usando estruturas de loops aninhados!\n");
}
