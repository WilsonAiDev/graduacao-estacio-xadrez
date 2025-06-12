/*
 * ♟️ Módulo Aventureiro - Main
 * Sistema principal para movimento do Cavalo com loops aninhados
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "xadrez_novato.h"
#include "xadrez_aventureiro.h"

void exibir_menu_aventureiro() {
    printf("\n🐎 === XADREZ - MÓDULO AVENTUREIRO ===\n");
    printf("Domine o movimento em 'L' do Cavalo com loops aninhados!\n\n");
    printf("1. Mover Cavalo 🐎\n");
    printf("2. Mostrar Movimentos Possíveis 🎯\n");
    printf("3. Tutorial Movimento em L 📚\n");
    printf("4. Demonstrar Loops Aninhados 🔄\n");
    printf("5. Buscar Caminho Otimizado 🚀\n");
    printf("6. Exibir Tabuleiro 📋\n");
    printf("7. Voltar ao Menu Principal ⬅️\n");
    printf("8. Sair 🚪\n");
    printf("Escolha uma opção: ");
}

int main() {
    Tabuleiro tabuleiro;
    HistoricoMovimento historico = {0};
    Posicao origem, destino;
    int opcao;
    char entrada[10];
    
    // Inicializar tabuleiro
    inicializar_tabuleiro(&tabuleiro);
    
    printf("🎮 Bem-vindo ao Módulo Aventureiro do Xadrez!\n");
    printf("Aqui você dominará o movimento complexo do Cavalo usando loops aninhados.\n");
    printf("O Cavalo é a única peça que pode 'saltar' sobre outras peças!\n\n");
    
    do {
        exibir_menu_aventureiro();
        scanf("%d", &opcao);
        getchar(); // Limpar buffer
        
        switch (opcao) {
            case 1: // Mover Cavalo
                printf("\n🐎 === MOVIMENTO DO CAVALO ===\n");
                printf("O Cavalo move-se em formato de 'L': 2 casas em uma direção + 1 casa perpendicular\n");
                
                printf("Posição atual do Cavalo (ex: B1): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &origem)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                printf("Destino do Cavalo (ex: C3): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &destino)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                // Colocar Cavalo na posição origem
                tabuleiro.pecas[origem.linha][origem.coluna] = CAVALO;
                
                if (validar_movimento_cavalo(&origem, &destino)) {
                    mover_cavalo(&tabuleiro, &origem, &destino);
                    
                    // Adicionar ao histórico
                    if (historico.num_movimentos < 64) {
                        historico.posicoes[historico.num_movimentos] = destino;
                        historico.num_movimentos++;
                    }
                    
                    printf("✅ Cavalo movido com sucesso!\n");
                    
                    printf("\nPressione ENTER para ver o tabuleiro atualizado...");
                    getchar();
                    exibir_tabuleiro_aventureiro(&tabuleiro, &historico);
                } else {
                    printf("❌ Movimento inválido para o Cavalo!\n");
                }
                break;
                
            case 2: // Mostrar movimentos possíveis
                printf("\n🎯 === MOVIMENTOS POSSÍVEIS ===\n");
                printf("Posição do Cavalo (ex: D4): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &origem)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                mostrar_possibilidades_cavalo(&origem);
                break;
                
            case 3: // Tutorial
                printf("\n📚 Iniciando tutorial do movimento em L...\n");
                printf("Pressione ENTER para continuar...");
                getchar();
                tutorial_movimento_L();
                break;
                
            case 4: // Demonstrar loops aninhados
                printf("\n🔄 Iniciando demonstração de loops aninhados...\n");
                printf("Pressione ENTER para continuar...");
                getchar();
                demonstrar_loops_aninhados();
                break;
                
            case 5: // Buscar caminho otimizado
                printf("\n🚀 === BUSCA DE CAMINHO OTIMIZADO ===\n");
                printf("Posição inicial (ex: A1): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &origem)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                printf("Posição destino (ex: H8): ");
                fgets(entrada, sizeof(entrada), stdin);
                if (!converter_posicao(entrada, &destino)) {
                    printf("❌ Posição inválida!\n");
                    break;
                }
                
                encontrar_caminho_cavalo(&origem, &destino, &historico);
                break;
                
            case 6: // Exibir tabuleiro
                exibir_tabuleiro_aventureiro(&tabuleiro, &historico);
                break;
                
            case 7: // Voltar ao menu principal
                printf("🔄 Funcionalidade ainda não implementada.\n");
                printf("Use a opção 8 para sair.\n");
                break;
                
            case 8: // Sair
                printf("👋 Obrigado por usar o Módulo Aventureiro! Você dominou os loops aninhados!\n");
                break;
                
            default:
                printf("❌ Opção inválida! Tente novamente.\n");
                break;
        }
        
        if (opcao != 8) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
        
    } while (opcao != 8);
    
    // Exibir estatísticas finais
    if (historico.num_movimentos > 0) {
        printf("\n📊 === ESTATÍSTICAS DA SESSÃO ===\n");
        exibir_estatisticas_movimento(&historico);
    }
    
    return 0;
}
