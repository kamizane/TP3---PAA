#include <stdio.h>
#include <string.h>

int casamento_exato(char texto[],char padrao[]) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int contador = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && texto[i + j] == padrao[j]) {
            j++;
        }
        if (j == m) {
            contador++;
        }
    }

    return contador;
}
