CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
BUILD = build

SRC = src/main.c \
	  src/TAD_Ocorrencias.c \
	  src/quicksort.c\
	  src/busca_encripto.c\
      src/TAD_Criptografia.c\
	  src/TAD_frequencia.c\
	  src/processador_cripto.c\
	  src/entrada.c

OBJ = $(SRC:src/%.c=$(BUILD)/%.o)

EXEC = main.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

$(BUILD)/%.o: src/%.c
	@if not exist "$(BUILD)" mkdir "$(BUILD)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(BUILD)\*.o
	del /Q $(EXEC)

run: all
	./$(EXEC)
