#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necessário para o random funcionar bem
#include "../include/TAD_Criptografia.h"

int gerarNmrAleatorio(int min, int max){
    if(min == max) return min;
    return (rand() % (max - min + 1)) + min;
}

void cifraDeDeslocamento(char *texto) {
    // É bom inicializar o seed do rand uma vez no main, mas aqui funciona para teste
    int chave = gerarNmrAleatorio(0, 25); 
    
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];

        if (c >= 'a' && c <= 'z') {
            texto[i] = ((c - 'a' + chave) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z'){
            texto[i] = ((c - 'A' + chave) % 26) + 'A';
        }
    }
}

void inicializaChaves(criptografia *cripto){
    char letraEmNumero = 'a'; // 97
    
    for (int i = 0; i < 26; i++){
        // Corrigido: Antes estava atribuindo sempre 97. Agora usa a variável incrementada.
        cripto->Chaves.normal[i] = letraEmNumero; 
        cripto->Chaves.cifra[i] = ' '; // Inicializa vazio
        letraEmNumero++;
    }

    printf("\nAlfabeto Normal: ");
    for (int i = 0; i < 26; i++){
        printf("%c ", cripto->Chaves.normal[i]);
    }

    printf("\nChave Cifra (vazia): ");
    for (int i = 0; i < 26; i++){
        printf("%c ", cripto->Chaves.cifra[i]);
    }
    printf("\n");
}