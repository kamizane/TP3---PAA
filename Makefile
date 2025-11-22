# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Nome do executável
TARGET = main.exe

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = .

# Arquivos fonte
SOURCES = $(SRC_DIR)/main.c \
          $(SRC_DIR)/entrada.c \
          $(SRC_DIR)/TAD_Criptografia.c

# Arquivos objeto (serão criados no diretório build)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Arquivo de entrada
INPUT_FILE = "Dang Heng - Terravox.txt"

# Regra padrão
all: $(BUILD_DIR) $(TARGET)

# Cria o diretório build se não existir
$(BUILD_DIR):
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	@if not exist "$(BUILD_DIR)\src" mkdir "$(BUILD_DIR)\src"

# Linkagem para criar o executável na pasta externa
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN_DIR)/$(TARGET)

# Compilação dos arquivos objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra específica para TAD_Criptografia
$(BUILD_DIR)/TAD_Criptografia.o: $(SRC_DIR)/TAD_Criptografia.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	@if exist "$(TARGET)" del "$(TARGET)"
	@if exist "*.exe" del "*.exe"

# Executar o programa
run: $(TARGET)
	$(BIN_DIR)/$(TARGET) $(INPUT_FILE)

# Recompilar tudo
rebuild: clean all

# Ajuda
help:
	@echo.
	@echo "Makefile para TP3--PAA - Sistema de Criptografia"
	@echo.
	@echo "Comandos disponiveis:"
	@echo "  make all      - Compila o projeto (padrao)"
	@echo "  make clean    - Remove arquivos gerados"
	@echo "  make run      - Executa o programa"
	@echo "  make rebuild  - Recompila tudo do zero"
	@echo "  make help     - Mostra esta ajuda"

.PHONY: all clean run rebuild help