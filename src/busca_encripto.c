#include <stdio.h>
#include <string.h>

void casamento_exato(char texto[],char padrao[], float * frequencia, int * contador) {
    int n = strlen(texto);
    int m = strlen(padrao);
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && texto[i + j] == padrao[j]) {
            j++;
        }
        if (j == m) {
            *contador +=1;
        }
    }
    float aux = (*contador);
    *frequencia = ((aux) / n) * 100;
}
