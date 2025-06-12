/*
 * ♟️ Testes Unitários - Módulo Novato
 * Validação das funcionalidades básicas
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "xadrez_novato.h"

// Contador de testes
int testes_executados = 0;
int testes_passou = 0;

void executar_teste(const char* nome, int (*funcao_teste)()) {
    printf("🧪 Executando: %s... ", nome);
    testes_executados++;
    
    if (funcao_teste()) {
        printf("✅ PASSOU\n");
        testes_passou++;
    } else {
        printf("❌ FALHOU\n");
    }
}

// Testes de conversão de posição
int teste_conversao_posicao() {
    Posicao pos;
    
    // Teste posição válida
    if (!converter_posicao("A1\n", &pos)) return 0;
    if (pos.linha != 0 || pos.coluna != 0) return 0;
    
    if (!converter_posicao("H8\n", &pos)) return 0;
    if (pos.linha != 7 || pos.coluna != 7) return 0;
    
    // Teste posição inválida
    if (converter_posicao("I9\n", &pos)) return 0;
    if (converter_posicao("A0\n", &pos)) return 0;
    
    return 1;
}

// Testes de validação da Torre
int teste_validacao_torre() {
    Posicao origem = {0, 0}; // A1
    Posicao destino;
    
    // Movimento horizontal válido
    destino.linha = 0; destino.coluna = 7; // A1 -> H1
    if (!validar_movimento_torre(&origem, &destino)) return 0;
    
    // Movimento vertical válido
    destino.linha = 7; destino.coluna = 0; // A1 -> A8
    if (!validar_movimento_torre(&origem, &destino)) return 0;
    
    // Movimento diagonal inválido
    destino.linha = 7; destino.coluna = 7; // A1 -> H8
    if (validar_movimento_torre(&origem, &destino)) return 0;
    
    return 1;
}

// Testes de validação do Bispo
int teste_validacao_bispo() {
    Posicao origem = {0, 0}; // A1
    Posicao destino;
    
    // Movimento diagonal válido
    destino.linha = 7; destino.coluna = 7; // A1 -> H8
    if (!validar_movimento_bispo(&origem, &destino)) return 0;
    
    // Movimento horizontal inválido
    destino.linha = 0; destino.coluna = 7; // A1 -> H1
    if (validar_movimento_bispo(&origem, &destino)) return 0;
    
    // Movimento vertical inválido
    destino.linha = 7; destino.coluna = 0; // A1 -> A8
    if (validar_movimento_bispo(&origem, &destino)) return 0;
    
    return 1;
}

// Testes de validação da Rainha
int teste_validacao_rainha() {
    Posicao origem = {3, 3}; // D4
    Posicao destino;
    
    // Movimento horizontal válido
    destino.linha = 3; destino.coluna = 7; // D4 -> H4
    if (!validar_movimento_rainha(&origem, &destino)) return 0;
    
    // Movimento vertical válido
    destino.linha = 7; destino.coluna = 3; // D4 -> D8
    if (!validar_movimento_rainha(&origem, &destino)) return 0;
    
    // Movimento diagonal válido
    destino.linha = 7; destino.coluna = 7; // D4 -> H8
    if (!validar_movimento_rainha(&origem, &destino)) return 0;
    
    // Movimento em "L" inválido
    destino.linha = 5; destino.coluna = 1; // D4 -> B6
    if (validar_movimento_rainha(&origem, &destino)) return 0;
    
    return 1;
}

// Teste de inicialização do tabuleiro
int teste_inicializacao_tabuleiro() {
    Tabuleiro tabuleiro;
    inicializar_tabuleiro(&tabuleiro);
    
    // Verificar se todas as posições estão vazias
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro.pecas[i][j] != VAZIO) {
                return 0;
            }
        }
    }
    
    return 1;
}

// Teste de validação de posições
int teste_validacao_posicoes() {
    Posicao pos_valida = {3, 3};
    Posicao pos_invalida1 = {-1, 3};
    Posicao pos_invalida2 = {3, 8};
    
    if (!validar_posicao(&pos_valida)) return 0;
    if (validar_posicao(&pos_invalida1)) return 0;
    if (validar_posicao(&pos_invalida2)) return 0;
    
    return 1;
}

int main() {
    printf("\n♟️ === SUITE DE TESTES - MÓDULO NOVATO ===\n\n");
    
    // Executar todos os testes
    executar_teste("Conversão de Posição", teste_conversao_posicao);
    executar_teste("Validação Torre", teste_validacao_torre);
    executar_teste("Validação Bispo", teste_validacao_bispo);
    executar_teste("Validação Rainha", teste_validacao_rainha);
    executar_teste("Inicialização Tabuleiro", teste_inicializacao_tabuleiro);
    executar_teste("Validação Posições", teste_validacao_posicoes);
    
    // Relatório final
    printf("\n📊 === RELATÓRIO DE TESTES ===\n");
    printf("Total de testes: %d\n", testes_executados);
    printf("Testes passou: %d\n", testes_passou);
    printf("Testes falhou: %d\n", testes_executados - testes_passou);
    printf("Taxa de sucesso: %.1f%%\n", 
           (float)testes_passou / testes_executados * 100);
    
    if (testes_passou == testes_executados) {
        printf("🎉 Todos os testes passaram! Módulo Novato validado.\n");
        return 0;
    } else {
        printf("⚠️  Alguns testes falharam. Verifique a implementação.\n");
        return 1;
    }
}
