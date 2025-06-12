/*
 * ♟️ Implementação dos Utilitários - Módulo Novato
 * Funções de apoio e inicialização
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "xadrez_novato.h"

void inicializar_tabuleiro(Tabuleiro *tabuleiro) {
    // Usando loop FOR para inicializar o tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro->pecas[i][j] = VAZIO;
        }
    }
    printf("🎯 Tabuleiro inicializado com estrutura FOR!\n");
}

int converter_posicao(const char *str, Posicao *pos) {
    // Remove quebra de linha se existir
    char entrada[10];
    strcpy(entrada, str);
    
    int len = strlen(entrada);
    if (len > 0 && entrada[len-1] == '\n') {
        entrada[len-1] = '\0';
        len--;
    }
    
    // Verifica se tem pelo menos 2 caracteres
    if (len < 2) {
        return 0;
    }
    
    // Converte coluna (A-H para 0-7)
    char coluna_char = toupper(entrada[0]);
    if (coluna_char < 'A' || coluna_char > 'H') {
        return 0;
    }
    pos->coluna = coluna_char - 'A';
    
    // Converte linha (1-8 para 0-7)
    char linha_char = entrada[1];
    if (linha_char < '1' || linha_char > '8') {
        return 0;
    }
    pos->linha = linha_char - '1';
    
    return 1;
}

int validar_posicao(Posicao *pos) {
    return (pos->linha >= 0 && pos->linha < TAMANHO_TABULEIRO &&
            pos->coluna >= 0 && pos->coluna < TAMANHO_TABULEIRO);
}

void exibir_caminho(Posicao *origem, Posicao *destino, const char *tipo_movimento) {
    printf("\n📍 Caminho da peça:\n");
    printf("Origem: %c%d\n", 'A' + origem->coluna, origem->linha + 1);
    printf("Destino: %c%d\n", 'A' + destino->coluna, destino->linha + 1);
    printf("Tipo de movimento: %s\n", tipo_movimento);
    
    // Calcular distância
    int dist_linha = abs(destino->linha - origem->linha);
    int dist_coluna = abs(destino->coluna - origem->coluna);
    int distancia_total = (dist_linha > dist_coluna) ? dist_linha : dist_coluna;
    
    printf("Distância: %d casa(s)\n", distancia_total);
}
