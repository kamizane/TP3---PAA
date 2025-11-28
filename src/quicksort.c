#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/quicksort.h"


int ehMenor(ListaFrequencia a, ListaFrequencia b) {
    if (a.caractere == 0 && b.caractere != 0) {
        return 0;
    }
    if (a.caractere != 0 && b.caractere == 0) {
        return 1;
    }
    return a.qntd > b.qntd;
}

int ehMaior(ListaFrequencia a, ListaFrequencia b) {
    if (a.caractere == 0 && b.caractere != 0) {
        return 1;
    }
    if (a.caractere != 0 && b.caractere == 0) {
        return 0;
    }
    return a.qntd < b.qntd;
}

void Ordena(int Esq, int Dir, ListaFrequencia *item) {
    int i, j;
    ListaFrequencia pivo, aux;

    i = Esq;
    j = Dir;
    
    pivo = item[(i + j) / 2];

    do {
        while (ehMenor(item[i], pivo)) {
            i++;
        }
        while (ehMaior(item[j], pivo)){ 
            j--;
        }
        if (i <= j) {
            aux = item[i];
            item[i] = item[j];
            item[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (Esq < j) {
        Ordena(Esq, j, item);
    }
    if (i < Dir) {
        Ordena(i, Dir, item);
    }
}

void QuickSort(ListaFrequencia *vetor, int n) {
    Ordena(0, n - 1, vetor);
}