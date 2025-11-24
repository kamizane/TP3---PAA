#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/TAD_Criptografia.h"
#include "criptografar.c"

void inicializaChaves(criptografia * cripto, char * texto){
    char letraEmNumero = 65;
    //Inicializas as duas chaves, a normal contém o alfabeto a cifra está 'vazia'
    for (int i=0; i<26; i++){
        cripto->Chaves.normal[i] = letraEmNumero;
        cripto->Chaves.cifra[i] = '?';
        letraEmNumero++;
    }

    //Aloca memória para as variáveis
    int aux = strlen(texto);
    cripto->claro = malloc(aux*( sizeof(char)));
    cripto->criptografado = malloc(aux*( sizeof(char)));
    cripto->parcial = malloc(aux*( sizeof(char)));


    for (int i =0; i<aux; i++){
        cripto->claro[i] = texto[i];
    }
    char * string = texto;

    //Encriptografa o texto lido
    cifraDeDeslocamento(string);
    cripto->criptografado = string;
    cripto->parcial = string;


}

void imprimeClaro(criptografia * cripto){
    int aux = strlen(cripto->claro);
    for(int i=0; i<aux; i++){
        printf("%c",cripto->claro[i]);
    }
}


void imprimeCriptografado(criptografia * cripto){
    printf("=== Texto criptografado ===\n");
    int aux = strlen(cripto->criptografado);
    for(int i=0; i<aux; i++){
        printf("%c",cripto->criptografado[i]);
    }
    printf("\n");
    printf("\n");
}
void imprimeParcial(criptografia * cripto){
    printf("=== Texto parcialmente decifrado ===\n");
    int aux = strlen(cripto->parcial);
    for(int i=0; i<aux; i++){
        printf("%c",cripto->parcial[i]);
    }
    printf("\n");
    printf("\n");
}
void imprimeChaves(criptografia * cripto){
    printf("=== Chave ===\n");
    for(int i=0; i<26; i++){
        printf("%c",cripto->Chaves.normal[i]);
    }
    printf("\n");
    for(int i=0; i<26; i++){
        printf("%c",cripto->Chaves.cifra[i]);
    }
    printf("\n");
    printf("\n");
}
