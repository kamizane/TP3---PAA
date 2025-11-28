#ifndef OCORRENCIAS_H
#define OCORRENCIAS_H

typedef struct Celula
{

    int posicao;
    struct Celula * prox;

}Celula;

typedef struct Ocorrencias
{
    Celula * primeiro;
    Celula * ultimo;
    int tamanho;

}Ocorrencias;

void inicializaListaVazia(Ocorrencias * ocorrencias);

void insereOcorrencia(Ocorrencias * ocorrencias, int posicao);

void removeOcorrencia(Ocorrencias * ocorrencias, int posicao);

int zeroOcorrencias(Ocorrencias * ocorrencias);


#endif