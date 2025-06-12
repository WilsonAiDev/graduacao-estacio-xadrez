# Makefile para o Projeto Xadrez - Todos os Módulos
# Compilação e execução do sistema completo

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
SRCDIR_NOVATO = src/modulo_novato
SRCDIR_AVENTUREIRO = src/modulo_aventureiro
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Arquivos fonte - Módulo Novato
SOURCES_NOVATO = $(SRCDIR_NOVATO)/main.c $(SRCDIR_NOVATO)/utils.c $(SRCDIR_NOVATO)/torre.c $(SRCDIR_NOVATO)/bispo.c $(SRCDIR_NOVATO)/rainha.c
OBJECTS_NOVATO = $(OBJDIR)/novato_main.o $(OBJDIR)/novato_utils.o $(OBJDIR)/novato_torre.o $(OBJDIR)/novato_bispo.o $(OBJDIR)/novato_rainha.o
TARGET_NOVATO = $(BINDIR)/xadrez_novato

# Arquivos fonte - Módulo Aventureiro  
SOURCES_AVENTUREIRO = $(SRCDIR_AVENTUREIRO)/main.c $(SRCDIR_NOVATO)/utils.c $(SRCDIR_AVENTUREIRO)/cavalo.c $(SRCDIR_AVENTUREIRO)/utils_aventureiro.c $(SRCDIR_AVENTUREIRO)/tutorial.c
OBJECTS_AVENTUREIRO = $(OBJDIR)/aventureiro_main.o $(OBJDIR)/aventureiro_utils.o $(OBJDIR)/aventureiro_cavalo.o $(OBJDIR)/aventureiro_utils_aventureiro.o $(OBJDIR)/aventureiro_tutorial.o
TARGET_AVENTUREIRO = $(BINDIR)/xadrez_aventureiro

# Regra principal
all: directories $(TARGET_NOVATO) $(TARGET_AVENTUREIRO)

# Criar diretórios necessários
directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

# === MÓDULO NOVATO ===
novato: directories $(TARGET_NOVATO)

$(TARGET_NOVATO): $(OBJECTS_NOVATO)
	@echo "🔗 Linkando executável novato..."
	$(CC) $(CFLAGS) $(OBJECTS_NOVATO) -o $(TARGET_NOVATO)
	@echo "✅ Executável criado: $(TARGET_NOVATO)"

# Compilar arquivos objeto do novato
$(OBJDIR)/novato_%.o: $(SRCDIR_NOVATO)/%.c
	@echo "🛠️  Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# === MÓDULO AVENTUREIRO ===
aventureiro: directories $(TARGET_AVENTUREIRO)

$(TARGET_AVENTUREIRO): $(OBJECTS_AVENTUREIRO)
	@echo "🔗 Linkando executável aventureiro..."
	$(CC) $(CFLAGS) $(OBJECTS_AVENTUREIRO) -o $(TARGET_AVENTUREIRO)
	@echo "✅ Executável criado: $(TARGET_AVENTUREIRO)"

# Compilar arquivos objeto do aventureiro
$(OBJDIR)/aventureiro_main.o: $(SRCDIR_AVENTUREIRO)/main.c
	@echo "🛠️  Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/aventureiro_utils.o: $(SRCDIR_NOVATO)/utils.c
	@echo "🛠️  Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/aventureiro_%.o: $(SRCDIR_AVENTUREIRO)/%.c
	@echo "🛠️  Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Executar programas
run-novato: $(TARGET_NOVATO)
	@echo "🚀 Executando módulo novato..."
	./$(TARGET_NOVATO)

run-aventureiro: $(TARGET_AVENTUREIRO)
	@echo "🚀 Executando módulo aventureiro..."
	./$(TARGET_AVENTUREIRO)

run: run-novato

# Limpar arquivos compilados
clean:
	@echo "🧹 Limpando arquivos compilados..."
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "✅ Limpeza concluída!"

# Recompilar tudo
rebuild: clean all

# Verificar sintaxe
check:
	@echo "🔍 Verificando sintaxe dos arquivos..."
	$(CC) $(CFLAGS) -fsyntax-only $(SOURCES_NOVATO)
	$(CC) $(CFLAGS) -fsyntax-only $(SOURCES_AVENTUREIRO)
	@echo "✅ Sintaxe verificada!"

# Compilar com debug
debug: CFLAGS += -g -DDEBUG
debug: all

# Compilar apenas um módulo
novato-only: novato
aventureiro-only: aventureiro

# Ajuda
help:
	@echo "🎯 Comandos disponíveis:"
	@echo "  make all              - Compilar todos os módulos"
	@echo "  make novato           - Compilar apenas módulo novato"
	@echo "  make aventureiro      - Compilar apenas módulo aventureiro"
	@echo "  make run-novato       - Compilar e executar novato"
	@echo "  make run-aventureiro  - Compilar e executar aventureiro"
	@echo "  make run              - Executar módulo novato (padrão)"
	@echo "  make clean            - Limpar arquivos compilados"
	@echo "  make rebuild          - Recompilar tudo"
	@echo "  make check            - Verificar sintaxe"
	@echo "  make debug            - Compilar com símbolos de debug"
	@echo "  make help             - Exibir esta ajuda"

# Regras que não criam arquivos
.PHONY: all run run-novato run-aventureiro clean rebuild check debug help directories novato aventureiro novato-only aventureiro-only
