# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Diretórios
BUILD = build

# Fontes
SRC = src/main.c \
      src/TAD_Ocorrencias.c \
      src/quicksort.c \
      src/busca_encripto.c \
      src/TAD_Criptografia.c \
      src/TAD_frequencia.c \
      src/processador_cripto.c \
      src/entrada.c

OBJ = $(SRC:src/%.c=$(BUILD)/%.o)

# Detecta Windows ou Linux
ifeq ($(OS),Windows_NT)
    EXEC = main.exe
    MKDIR = if not exist "$(BUILD)" mkdir "$(BUILD)"
    RM_FILE = del /Q /F
    RM_DIR = rmdir /S /Q
    RUN_CMD = .\$(EXEC)
else
    EXEC = main
    MKDIR = mkdir -p $(BUILD)
    RM_FILE = rm -f
    RM_DIR = rm -rf
    RUN_CMD = ./$(EXEC)
endif

# Regra padrão
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compila objetos
$(BUILD)/%.o: src/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	-$(RM_FILE) $(BUILD)/* 2> NUL
	-$(RM_DIR) $(BUILD) 2> NUL
	-$(RM_FILE) $(EXEC) 2> NUL

# Executa
run: all
	$(RUN_CMD)
