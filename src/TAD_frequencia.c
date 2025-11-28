#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/quicksort.h"

void executaFrequencia(ListaFrequencia lista[], char *texto){
    criaListaFrequencia(lista);
    contabilizaLetra(lista, texto);
    calculaFrequencia(lista, texto);
    QuickSort(lista,27);
    imprimeLetrasEfrequencia(lista);
}
void criaListaFrequencia(ListaFrequencia lista[]){
    for (int i = 0; i < 27; i++) {
        lista[i].caractere = 0;
        lista[i].qntd = 0;
    }
}

void contabilizaLetra(ListaFrequencia lista[], char *str){
    int i = 0;
    
    while (str[i] != '\0'){
        // isalpha verifica(A-Z ou a-z)
        if (isalpha(str[i])){
            int indiceLetra = tolower(str[i]) - 'a'; // em ascii essa conta retorna um indice entre 0 e 1
            printf("(%c)", str[i]);
            if (lista[indiceLetra].caractere == 0){
                lista[indiceLetra].caractere = str[i];
                lista[indiceLetra].qntd++;
            }
            else
            {
                lista[indiceLetra].qntd++;
            }
        }
        i++;
    }
    printf("\n CONTABILIZACAO SUCESSO\n");
}

void calculaFrequencia(ListaFrequencia lista[], char *str){

    double letrasTexto = contagemLetrastexto(str);
    printf("%lf\n", letrasTexto); //retirar dps
    for(int i = 0;i < 27;i++){
    if(lista[i].caractere != 0){
        lista[i].frequencia = (lista[i].qntd / letrasTexto) * 100;
    }else{continue;}
    }
}

double contagemLetrastexto(char *str){
    int i = 0;
    double cont = 0;
    while(str[i] != '\0') {
        if (isalpha(str[i])) {
            cont++;
            i++;
        }else{i++;}
    }
    return cont;
}

void imprimeLetrasEfrequencia(ListaFrequencia lista[]) {
    printf("Letra,  Contagem,   Frequencia\n");

    for (int i = 0; i < 27; i++) {
        if (lista[i].caractere == 0) {
            continue;
        } else {
            // 2. e 3. Modificação do printf para formatação de tabela
            // %-7c   -> Imprime o char alinhado à esquerda (o menos faz isso) num espaço de 7 chars
            // %6.0lf -> Imprime o contador alinhado à direita num espaço de 6 chars
            // %6.2lf -> Imprime a frequência alinhada à direita num espaço de 6 chars
            // %%     -> Imprime o símbolo de porcentagem literal
            printf("%-7c %8.0lf %12.2lf%%\n", 
                   lista[i].caractere, 
                   lista[i].qntd, 
                   lista[i].frequencia);
        }
    }
}