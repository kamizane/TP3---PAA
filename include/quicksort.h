#ifndef QUICKSORT_h
#define QUICKSORT_h

#include "../include/TAD_frequencia.h"


int ehMenor(ListaFrequencia a, ListaFrequencia b);
int ehMaior(ListaFrequencia a, ListaFrequencia b);
void Ordena(int Esq, int Dir, ListaFrequencia *item);
void QuickSort(ListaFrequencia *vetor, int n);
int buscaBinariaAproximada(ListaFrequencia lista[], int n, double alvo);


#endif
