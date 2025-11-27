#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int gerarNmrAleatorio(int min, int max){
    if(min == max) return min;
    return (rand() % (max - min + 1)) + min;
}

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
