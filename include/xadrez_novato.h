/*
 * ♟️ Movimentação de Peças de Xadrez - Header do Módulo Novato
 * Definições e declarações para movimentos básicos
 */

#ifndef XADREZ_NOVATO_H
#define XADREZ_NOVATO_H

// Constantes
#define TAMANHO_TABULEIRO 8

// Tipos de peças
typedef enum {
    VAZIO = 0,
    TORRE = 1,
    BISPO = 2,
    RAINHA = 3,
    CAVALO = 4
} TipoPeca;

// Estrutura para posição no tabuleiro
typedef struct {
    int linha;    // 0-7 (corresponde a 1-8)
    int coluna;   // 0-7 (corresponde a A-H)
} Posicao;

// Estrutura do tabuleiro
typedef struct {
    TipoPeca pecas[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
} Tabuleiro;

// Declarações das funções

// Inicialização e utilitários
void inicializar_tabuleiro(Tabuleiro *tabuleiro);
int converter_posicao(const char *str, Posicao *pos);
void exibir_caminho(Posicao *origem, Posicao *destino, const char *tipo_movimento);

// Validação de movimentos
int validar_posicao(Posicao *pos);
int validar_movimento_torre(Posicao *origem, Posicao *destino);
int validar_movimento_bispo(Posicao *origem, Posicao *destino);
int validar_movimento_rainha(Posicao *origem, Posicao *destino);

// Execução de movimentos
void mover_torre(Tabuleiro *tabuleiro, Posicao *origem, Posicao *destino);
void mover_bispo(Tabuleiro *tabuleiro, Posicao *origem, Posicao *destino);
void mover_rainha(Tabuleiro *tabuleiro, Posicao *origem, Posicao *destino);

// Interface
void exibir_menu(void);
void exibir_tabuleiro(Tabuleiro *tabuleiro);

#endif // XADREZ_NOVATO_H
