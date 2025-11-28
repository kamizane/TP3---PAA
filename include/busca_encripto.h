#ifndef BUSCAENCRIPTO_H
#define BUSCAENCRIPTO_H


void casamento_exato(char texto[],char padrao[], float * frequencia, int * contador);

void casamentoAproximado(int maxOperacoes, char texto[], char padrao[]);

void shift(int vetor[], int tamanho);

#endif