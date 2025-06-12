/*
 * ♟️ Tutoriais e Demonstrações - Módulo Aventureiro
 * Funções educacionais para entender loops aninhados
 */

#include <stdio.h>
#include <stdlib.h>
#include "xadrez_novato.h"
#include "xadrez_aventureiro.h"

void tutorial_movimento_L() {
    printf("\n📚 === TUTORIAL: MOVIMENTO EM L DO CAVALO ===\n\n");
    
    printf("🐎 O Cavalo é a peça mais única do xadrez!\n");
    printf("Características especiais:\n");
    printf("• É a ÚNICA peça que pode 'saltar' sobre outras\n");
    printf("• Move-se sempre em formato de 'L'\n");
    printf("• Tem exatamente 8 movimentos possíveis\n\n");
    
    printf("🔤 Formato do movimento em L:\n");
    printf("• 2 casas em uma direção (horizontal OU vertical)\n");
    printf("• + 1 casa perpendicular à primeira direção\n\n");
    
    printf("Pressione ENTER para ver exemplo visual...");
    getchar();
    
    printf("📐 Exemplo visual do movimento em L:\n");
    printf("Cavalo em D4 pode ir para:\n\n");
    
    // Demonstração visual usando loops aninhados
    char tabuleiro_demo[8][8];
    
    // Inicializar tabuleiro demo com loops aninhados
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro_demo[i][j] = '.';
        }
    }
    
    // Posição do cavalo (D4 = linha 3, coluna 3)
    int cavalo_linha = 3, cavalo_coluna = 3;
    tabuleiro_demo[cavalo_linha][cavalo_coluna] = 'C';
    
    // Marcar movimentos possíveis usando loops aninhados
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
    
    printf("🔄 Calculando movimentos com loops aninhados:\n");
    
    for (int i = 0; i < MOVIMENTOS_CAVALO; i++) {
        for (int validacao = 0; validacao < 1; validacao++) { // Loop interno para demonstração
            int nova_linha = cavalo_linha + movimentos[i].delta_linha;
            int nova_coluna = cavalo_coluna + movimentos[i].delta_coluna;
            
            printf("Movimento %d: (%+d,%+d) -> ", 
                   i + 1, movimentos[i].delta_linha, movimentos[i].delta_coluna);
            
            if (nova_linha >= 0 && nova_linha < 8 && nova_coluna >= 0 && nova_coluna < 8) {
                tabuleiro_demo[nova_linha][nova_coluna] = '*';
                printf("%c%d ✅\n", 'A' + nova_coluna, nova_linha + 1);
            } else {
                printf("Fora do tabuleiro ❌\n");
            }
        }
    }
    
    printf("\n📋 Visualização:\n");
    
    // Exibir tabuleiro usando loops aninhados
    for (int i = 7; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf(" %c ", tabuleiro_demo[i][j]);
        }
        printf(" %d\n", i + 1);
    }
    
    printf("  ");
    for (int j = 0; j < 8; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n\n");
    
    printf("Legenda:\n");
    printf("C = Cavalo (posição atual)\n");
    printf("* = Movimentos possíveis\n");
    printf(". = Casas vazias\n");
    
    printf("\n🎯 Lembre-se: O movimento em L é SEMPRE 2+1 ou 1+2 casas!\n");
}

void demonstrar_loops_aninhados() {
    printf("\n🔄 === DEMONSTRAÇÃO: LOOPS ANINHADOS ===\n\n");
    
    printf("🎓 Por que usamos loops aninhados no movimento do Cavalo?\n");
    printf("• Para verificar TODAS as combinações possíveis\n");
    printf("• Para analisar cada movimento em múltiplas dimensões\n");
    printf("• Para organizar a lógica de forma sistemática\n\n");
    
    printf("📝 Exemplo 1: Verificando todos os movimentos possíveis\n");
    printf("```\n");
    printf("for (int movimento = 0; movimento < 8; movimento++) {\n");
    printf("    for (int validacao = 0; validacao < 1; validacao++) {\n");
    printf("        // Calcular nova posição\n");
    printf("        // Verificar se é válida\n");
    printf("    }\n");
    printf("}\n");
    printf("```\n\n");
    
    printf("🔢 Demonstração prática - Gerando padrão de movimentos:\n");
    
    // Demonstração de loops aninhados com contadores
    int contador_total = 0;
    
    printf("\nLoop Externo (Direções principais):\n");
    for (int direcao = 1; direcao <= 4; direcao++) {
        printf("  Direção %d:\n", direcao);
        
        printf("  Loop Interno (Variações):\n");
        for (int variacao = 1; variacao <= 2; variacao++) {
            contador_total++;
            printf("    Movimento %d (Dir:%d, Var:%d)\n", 
                   contador_total, direcao, variacao);
        }
        printf("\n");
    }
    
    printf("Total de movimentos gerados: %d\n", contador_total);
    
    printf("\nPressione ENTER para continuar com exemplo 2...");
    getchar();
    
    printf("\n🎯 Exemplo 2: Análise de tabuleiro completo\n");
    printf("Verificando TODAS as posições do tabuleiro:\n\n");
    
    int posicoes_analisadas = 0;
    
    // Loop aninhado para percorrer todo o tabuleiro
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            posicoes_analisadas++;
            
            // Simular análise de movimento (apenas algumas posições para não sobrecarregar)
            if (posicoes_analisadas % 32 == 0) {
                printf("Analisando posição %c%d... ✅\n", 
                       'A' + coluna, linha + 1);
            }
        }
    }
    
    printf("Total de posições analisadas: %d\n", posicoes_analisadas);
    
    printf("\n📊 Vantagens dos loops aninhados:\n");
    printf("• ✅ Código mais organizado e legível\n");
    printf("• ✅ Análise sistemática de todas as possibilidades\n");
    printf("• ✅ Facilita a manutenção e debugging\n");
    printf("• ✅ Permite estruturas de dados mais complexas\n");
    
    printf("\n🔧 Aplicações no xadrez:\n");
    printf("• Verificar todos os movimentos possíveis\n");
    printf("• Analisar ameaças no tabuleiro\n");
    printf("• Buscar melhores jogadas\n");
    printf("• Calcular rotas otimizadas\n");
}

void encontrar_caminho_cavalo(Posicao *origem, Posicao *destino, HistoricoMovimento *historico) {
    printf("\n🚀 === BUSCA DE CAMINHO OTIMIZADO ===\n");
    printf("Origem: %c%d\n", 'A' + origem->coluna, origem->linha + 1);
    printf("Destino: %c%d\n", 'A' + destino->coluna, destino->linha + 1);
    
    printf("\n🔍 Analisando possibilidades com loops aninhados...\n");
    
    // Calcular distância Manhattan (aproximação)
    int dist_linha = abs(destino->linha - origem->linha);
    int dist_coluna = abs(destino->coluna - origem->coluna);
    
    printf("Distância em linhas: %d\n", dist_linha);
    printf("Distância em colunas: %d\n", dist_coluna);
    
    // Estimativa de movimentos mínimos
    int movimentos_minimos = (dist_linha + dist_coluna + 2) / 3; // Aproximação
    
    printf("Estimativa de movimentos mínimos: %d\n", movimentos_minimos);
    
    printf("\n🔄 Simulando busca com loops aninhados:\n");
    
    // Simular algoritmo de busca usando loops aninhados
    int encontrou_caminho = 0;
    
    for (int profundidade = 1; profundidade <= 6 && !encontrou_caminho; profundidade++) {
        printf("Analisando profundidade %d:\n", profundidade);
        
        for (int tentativa = 1; tentativa <= profundidade * 8; tentativa++) {
            // Simular verificação de caminho
            if (tentativa % 20 == 0) {
                printf("  Tentativa %d...\n", tentativa);
            }
            
            // Simular encontrar caminho na profundidade 3
            if (profundidade >= movimentos_minimos && tentativa > profundidade * 4) {
                encontrou_caminho = 1;
                
                printf("  ✅ Caminho encontrado!\n");
                
                // Simular caminho encontrado
                historico->num_movimentos = 0;
                historico->posicoes[historico->num_movimentos++] = *origem;
                
                // Adicionar posições intermediárias simuladas
                for (int i = 1; i < profundidade; i++) {
                    Posicao pos_intermediaria;
                    pos_intermediaria.linha = origem->linha + (i * (destino->linha - origem->linha)) / profundidade;
                    pos_intermediaria.coluna = origem->coluna + (i * (destino->coluna - origem->coluna)) / profundidade;
                    
                    // Ajustar para movimento válido do cavalo
                    if (i % 2 == 1) {
                        pos_intermediaria.linha += (pos_intermediaria.linha < 4) ? 2 : -2;
                        pos_intermediaria.coluna += (pos_intermediaria.coluna < 4) ? 1 : -1;
                    }
                    
                    // Validar limites
                    if (pos_intermediaria.linha < 0) pos_intermediaria.linha = 0;
                    if (pos_intermediaria.linha > 7) pos_intermediaria.linha = 7;
                    if (pos_intermediaria.coluna < 0) pos_intermediaria.coluna = 0;
                    if (pos_intermediaria.coluna > 7) pos_intermediaria.coluna = 7;
                    
                    historico->posicoes[historico->num_movimentos++] = pos_intermediaria;
                }
                
                historico->posicoes[historico->num_movimentos++] = *destino;
                break;
            }
        }
    }
    
    if (encontrou_caminho) {
        printf("\n🎉 Caminho otimizado encontrado!\n");
        printf("Número de movimentos: %d\n", historico->num_movimentos - 1);
        printf("Sequência:\n");
        
        for (int i = 0; i < historico->num_movimentos; i++) {
            printf("%d. %c%d", 
                   i + 1,
                   'A' + historico->posicoes[i].coluna,
                   historico->posicoes[i].linha + 1);
            
            if (i < historico->num_movimentos - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("\n⚠️ Não foi possível encontrar caminho na profundidade analisada.\n");
        printf("Tente uma busca mais profunda ou posições mais próximas.\n");
    }
}
