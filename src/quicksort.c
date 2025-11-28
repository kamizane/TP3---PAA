#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/TAD_frequencia.h"

int ehMenor(ListaFrequencia a, ListaFrequencia b) {
    if (a.caractere == 0 && b.caractere != 0) return 0;
    if (a.caractere != 0 && b.caractere == 0) return 1;
    return a.frequencia > b.frequencia;
}

int ehMaior(ListaFrequencia a, ListaFrequencia b) {
    if (a.caractere == 0 && b.caractere != 0) return 1;
    if (a.caractere != 0 && b.caractere == 0) return 0;
    return a.frequencia < b.frequencia;
}

void Ordena(int Esq, int Dir, ListaFrequencia *item) {
    int i = Esq, j = Dir;
    ListaFrequencia pivo = item[(i + j) / 2], aux;

    do {
        while (ehMenor(item[i], pivo)) i++;
        while (ehMaior(item[j], pivo)) j--;

        if (i <= j) {
            aux = item[i];
            item[i] = item[j];
            item[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (Esq < j) Ordena(Esq, j, item);
    if (i < Dir) Ordena(i, Dir, item);
}

void QuickSort(ListaFrequencia *vetor, int n) {
    Ordena(0, n - 1, vetor);
}