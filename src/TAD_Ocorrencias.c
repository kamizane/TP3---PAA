#include <stdio.h>
#include <stdlib.h>
#include "../include/TAD_Ocorrencias.h"

void inicializaListaVazia(Ocorrencias * ocorrencias){
    ocorrencias->primeiro = (Celula*)malloc(sizeof(Celula));
    ocorrencias->primeiro->prox = NULL;
    ocorrencias->ultimo = ocorrencias->primeiro;
    ocorrencias->tamanho = 0;
}

void insereOcorrencia(Ocorrencias * ocorrencias, int posicao){
    ocorrencias->ultimo->prox = (Celula*)malloc(sizeof(Celula));
    ocorrencias->ultimo->prox->prox = NULL;
    ocorrencias->ultimo->prox->posicao = posicao;
    ocorrencias->ultimo = ocorrencias->ultimo->prox;
    ocorrencias->tamanho++;
}

void removeOcorrencia(Ocorrencias * ocorrencias, int posicao){
    Celula* anterior = ocorrencias->primeiro;
    Celula* celula = ocorrencias->primeiro->prox;

    while (celula != NULL) {

        if(celula->posicao == posicao){ //procura pela rocha da categoria certa e faz a remoção
            
            anterior->prox = celula->prox;

            if (celula->prox == NULL) ocorrencias->ultimo = anterior;
            ocorrencias->tamanho--;

            free(celula);
            return; 
        }
        
        anterior = celula;
        celula = celula->prox;
    }
}

int zeroOcorrencias(Ocorrencias * ocorrencias){
    return ocorrencias->tamanho == 0;
}
