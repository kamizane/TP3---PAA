#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/processador_cripto.h"

int gerarNmrAleatorio(int min, int max){
    if(min == max) return min;
    return (rand() % (max - min + 1)) + min;
}

//Função que realiza a criptografia por substitução
void cifraDeDeslocamento(char *texto) {
    srand(time(NULL));
    int chave = gerarNmrAleatorio(1,25);
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if(texto[i] == '.' || texto[i] == 'n' || texto[i] == '"' || texto[i] == ' '){
            continue;
        }
        if (c >= 'a' && c <= 'z') {
            texto[i] = ((c - 'a' + chave) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z'){
            texto[i] = ((c - 'A' + chave) % 26) + 'A';
        }    }
    
}


void computeLastOcc(const char *padrao, int lastOcc[]) {
    for (int i = 0; i < 128; i++) {
        lastOcc[i] = -1;
    }

    int m = strlen(padrao);
    for (int i = 0; i < m - 1; i++) {
        lastOcc[(unsigned char)padrao[i]] = i;
    }
}

//adaptação do algoritimo Boyer-Moore-Horspool Algorithm implementado em java. Mais detalhes na documentação.
void casamento_exato(char *texto, char *padrao,float * frequencia, int *contador) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int lastOcc[128];

    computeLastOcc(padrao, lastOcc);

    *contador = 0;  

    int i0 = 0;

    while (i0 <= n - m) {
        int j = m - 1;

        while (j >= 0 && padrao[j] == texto[i0 + j]) {
            j--;
        }

        if (j < 0) {
            // casamento exato
            printf("Ocorrencia encontrada na posicao %d\n", i0);
            (*contador)++;


            i0++;
        } else {
            unsigned char c = texto[i0 + m - 1];
            int shift = (m - 1) - lastOcc[c];
            if (shift <= 0) shift = 1; 
            i0 += shift;
        }
    }
    float aux = (*contador) ;
    *frequencia = ((aux) / (n/m)) * 100;
}

