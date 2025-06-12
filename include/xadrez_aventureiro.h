/*
 * ♟️ Header do Módulo Aventureiro - Xadrez
 * Movimento do Cavalo com loops aninhados
 */

#ifndef XADREZ_AVENTUREIRO_H
#define XADREZ_AVENTUREIRO_H

// Incluir definições básicas do módulo novato
#include "xadrez_novato.h"

// Constantes específicas do Cavalo
#define MOVIMENTOS_CAVALO 8

// Estrutura para movimentos possíveis do Cavalo
typedef struct {
    int delta_linha;
    int delta_coluna;
} MovimentoCavalo;

// Estrutura para histórico de movimentos
typedef struct {
    Posicao posicoes[64]; // Máximo de posições no tabuleiro
    int num_movimentos;
} HistoricoMovimento;

// Declarações das funções do módulo aventureiro

// Inicialização e configuração
void inicializar_movimentos_cavalo(MovimentoCavalo movimentos[MOVIMENTOS_CAVALO]);
void inicializar_movimentos_cavalo_verbose(MovimentoCavalo movimentos[MOVIMENTOS_CAVALO]);
void exibir_menu_aventureiro(void);

// Validação de movimentos do Cavalo
int validar_movimento_cavalo(Posicao *origem, Posicao *destino);
int verificar_movimento_L(Posicao *origem, Posicao *destino);
void listar_movimentos_possiveis(Posicao *posicao_atual, Posicao movimentos_validos[], int *num_movimentos);

// Execução de movimentos
void mover_cavalo(Tabuleiro *tabuleiro, Posicao *origem, Posicao *destino);
void demonstrar_movimento_cavalo(Posicao *origem, Posicao *destino);

// Algoritmos avançados
void encontrar_caminho_cavalo(Posicao *origem, Posicao *destino, HistoricoMovimento *historico);
int buscar_movimento_otimo(Posicao *atual, Posicao *destino, int profundidade_max);

// Utilitários de exibição
void exibir_tabuleiro_aventureiro(Tabuleiro *tabuleiro, HistoricoMovimento *historico);
void mostrar_possibilidades_cavalo(Posicao *posicao);
void exibir_estatisticas_movimento(HistoricoMovimento *historico);

// Demonstrações educacionais
void tutorial_movimento_L(void);
void demonstrar_loops_aninhados(void);

#endif // XADREZ_AVENTUREIRO_H
