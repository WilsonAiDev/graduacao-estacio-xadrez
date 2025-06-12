# ♟️ Movimentação de Peças de Xadrez

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![GCC](https://img.shields.io/badge/GCC-Compiler-red?style=for-the-badge&logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)
[![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-orange?style=for-the-badge)](https://github.com)

[![Estácio](https://img.shields.io/badge/Universidade-Estácio-blue?style=flat-square)](https://estacio.br)
[![Academic](https://img.shields.io/badge/Projeto-Acadêmico-green?style=flat-square)](https://estacio.br)
[![Semester](https://img.shields.io/badge/Semestre-2º-lightgrey?style=flat-square)](https://estacio.br)

---

## 📋 Descrição do Projeto

Sistema desenvolvido em linguagem C que simula o movimento de peças específicas de xadrez utilizando estruturas de repetição (for, while, do-while), loops aninhados e recursividade. O projeto é dividido em três módulos de complexidade crescente.

## 🎯 Cenário

A **MateCheck**, desenvolvedora de jogos, criou um jogo eletrônico inovador para o ensino de programação e incentivo ao xadrez. No jogo, o jogador não move as peças manualmente, mas cria procedimentos e rotinas em código para executar as ações, respeitando as regras do xadrez e a sintaxe da linguagem C.

## 📁 Estrutura do Projeto

```
graduacao-estacio-xadrez/
├── src/
│   ├── modulo_novato/
│   ├── modulo_aventureiro/
│   └── modulo_mestre/
├── include/
├── tests/
├── docs/
├── Makefile
├── README.md
└── .gitignore
```

## ⚙️ Requisitos Funcionais

### 🏰 RF001 - Movimentação Linear da Torre
- **Descrição**: Implementar movimento linear (horizontal e vertical) da Torre
- **Critério**: Utilizar estruturas de repetição for, while ou do-while
- **Entrada**: Posição inicial e final da Torre
- **Saída**: Validação do movimento e caminho percorrido

### ⛪ RF002 - Movimentação Diagonal do Bispo
- **Descrição**: Implementar movimento diagonal do Bispo
- **Critério**: Utilizar estruturas de repetição for, while ou do-while
- **Entrada**: Posição inicial e final do Bispo
- **Saída**: Validação do movimento e caminho percorrido

### 👑 RF003 - Movimentação Combinada da Rainha
- **Descrição**: Implementar movimento combinado (linear e diagonal) da Rainha
- **Critério**: Utilizar estruturas de repetição for, while ou do-while
- **Entrada**: Posição inicial e final da Rainha
- **Saída**: Validação do movimento e caminho percorrido

### 🐎 RF004 - Movimentação em "L" do Cavalo
- **Descrição**: Implementar movimento em "L" do Cavalo
- **Critério**: Utilizar loops aninhados para simular o movimento complexo
- **Entrada**: Posição inicial e final do Cavalo
- **Saída**: Validação do movimento em "L"

### 🔄 RF005 - Otimização com Recursividade
- **Descrição**: Implementar recursividade para otimizar movimentos das peças
- **Critério**: Aplicar recursividade e loops complexos com múltiplas condições
- **Entrada**: Posição inicial, final e peça selecionada
- **Saída**: Caminho otimizado e validação do movimento

### ✅ RF006 - Validação do Tabuleiro
- **Descrição**: Validar se as posições estão dentro dos limites do tabuleiro (8x8)
- **Critério**: Verificar coordenadas entre A1-H8
- **Entrada**: Coordenadas da posição
- **Saída**: Confirmação de posição válida

### 💻 RF007 - Interface de Linha de Comando
- **Descrição**: Fornecer interface simples para entrada de comandos
- **Critério**: Menu interativo para seleção de peças e movimentos
- **Entrada**: Comandos do usuário
- **Saída**: Feedback das operações

## 🔧 Requisitos Não Funcionais

### 💻 RNF001 - Linguagem de Programação
- **Descrição**: O sistema deve ser desenvolvido exclusivamente em linguagem C
- **Critério**: Código compatível com padrão C99 ou superior

### 🔄 RNF002 - Estruturas de Repetição Obrigatórias
- **Descrição**: Uso obrigatório de estruturas for, while e do-while
- **Critério**: Cada tipo de estrutura deve ser utilizada pelo menos uma vez

### ⚡ RNF003 - Performance
- **Descrição**: O sistema deve responder em tempo real às operações
- **Critério**: Tempo de resposta inferior a 1 segundo para qualquer movimento

### 🌐 RNF004 - Portabilidade
- **Descrição**: O código deve ser compilável em diferentes sistemas operacionais
- **Critério**: Compatibilidade com GCC em Linux, macOS e Windows

### 🧩 RNF005 - Modularidade
- **Descrição**: O código deve ser organizado em módulos bem definidos
- **Critério**: Separação clara entre lógica de negócio, interface e validações

### 📚 RNF006 - Documentação
- **Descrição**: Todo o código deve ser adequadamente documentado
- **Critério**: Comentários explicativos em funções complexas e headers

### ⚠️ RNF007 - Tratamento de Erros
- **Descrição**: O sistema deve tratar adequadamente entradas inválidas
- **Critério**: Mensagens de erro claras e recuperação de estados inválidos

### 💾 RNF008 - Uso de Memória
- **Descrição**: O sistema deve usar memória de forma eficiente
- **Critério**: Liberação adequada de memória alocada dinamicamente

## 🎮 Módulos do Projeto

### 🌱 Módulo Novato
- Implementação de movimentos básicos (Torre, Bispo, Rainha)
- Uso de estruturas de repetição simples
- Validação básica de movimentos

### 🎯 Módulo Aventureiro
- Implementação do movimento do Cavalo
- Uso de loops aninhados
- Validação de movimentos complexos

### 🏆 Módulo Mestre
- Otimização com recursividade
- Loops complexos com múltiplas condições
- Refinamento e otimização de código

## 🚀 Como Compilar e Executar

### 📋 Pré-requisitos
- Compilador GCC instalado
- Sistema operacional: Linux, macOS ou Windows
- Make (opcional, para usar Makefile)

### ⚙️ Compilação
```bash
# Compilação manual
gcc -o xadrez src/*.c -I include/

# Usando Makefile
make all
```

### ▶️ Execução
```bash
./xadrez
```

## 📂 Estrutura de Arquivos

- `src/`: Código fonte do projeto
- `include/`: Arquivos de cabeçalho (.h)
- `tests/`: Testes unitários
- `docs/`: Documentação adicional
- `Makefile`: Arquivo de automação de build

## 🧪 Testes

Execute os testes unitários com:
```bash
make test
```

## 🤝 Contribuição

1. Fork o projeto
2. Crie uma branch para sua feature (`git checkout -b feature/nova-feature`)
3. Commit suas mudanças (`git commit -am 'Adiciona nova feature'`)
4. Push para a branch (`git push origin feature/nova-feature`)
5. Crie um Pull Request

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

## 👨‍💻 Autor

Desenvolvido como projeto acadêmico para a disciplina de Programação - Estácio de Sá

## 📞 Contato

Para dúvidas e sugestões, entre em contato através do repositório do projeto.

---

<div align="center">
  <img src="https://img.shields.io/badge/Made%20with-❤️-red?style=for-the-badge" alt="Made with love">
  <img src="https://img.shields.io/badge/Powered%20by-C%20Language-blue?style=for-the-badge&logo=c" alt="Powered by C">
</div>
