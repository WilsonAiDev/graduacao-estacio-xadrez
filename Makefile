# Makefile para o Projeto Xadrez - Módulo Novato
# Compilação e execução do sistema

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
SRCDIR = src/modulo_novato
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Arquivos fonte
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/utils.c $(SRCDIR)/torre.c $(SRCDIR)/bispo.c $(SRCDIR)/rainha.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/utils.o $(OBJDIR)/torre.o $(OBJDIR)/bispo.o $(OBJDIR)/rainha.o
TARGET = $(BINDIR)/xadrez_novato

# Regra principal
all: directories $(TARGET)

# Criar diretórios necessários
directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Compilar executável
$(TARGET): $(OBJECTS)
	@echo "🔗 Linkando executável..."
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)
	@echo "✅ Executável criado: $(TARGET)"

# Compilar arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "🛠️  Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Executar programa
run: $(TARGET)
	@echo "🚀 Executando módulo novato..."
	./$(TARGET)

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
	$(CC) $(CFLAGS) -fsyntax-only $(SOURCES)
	@echo "✅ Sintaxe verificada!"

# Compilar com debug
debug: CFLAGS += -g -DDEBUG
debug: all

# Instalar (copiar para /usr/local/bin)
install: $(TARGET)
	@echo "📦 Instalando xadrez_novato..."
	sudo cp $(TARGET) /usr/local/bin/
	@echo "✅ Instalação concluída!"

# Desinstalar
uninstall:
	@echo "🗑️  Desinstalando xadrez_novato..."
	sudo rm -f /usr/local/bin/xadrez_novato
	@echo "✅ Desinstalação concluída!"

# Ajuda
help:
	@echo "🎯 Comandos disponíveis:"
	@echo "  make all      - Compilar projeto"
	@echo "  make run      - Compilar e executar"
	@echo "  make clean    - Limpar arquivos compilados"
	@echo "  make rebuild  - Recompilar tudo"
	@echo "  make check    - Verificar sintaxe"
	@echo "  make debug    - Compilar com símbolos de debug"
	@echo "  make install  - Instalar no sistema"
	@echo "  make uninstall- Desinstalar do sistema"
	@echo "  make help     - Exibir esta ajuda"

# Regras que não criam arquivos
.PHONY: all run clean rebuild check debug install uninstall help directories
