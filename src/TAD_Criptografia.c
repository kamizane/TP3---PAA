#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/TAD_Criptografia.h"
#include "criptografar.c"

void inicializaChaves(criptografia * cripto, char * texto){
    char letraEmNumero = 65;
    //Inicializas as duas chaves, a normal contém o alfabeto a cifra está 'vazia'
    for (int i=0; i<26; i++){
        cripto->Chaves.normal[i] = letraEmNumero;
        cripto->Chaves.cifra[i] = ' ';
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
    strcpy(cripto->criptografado,string);
    strcpy(cripto->parcial,string);



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
        if(cripto->parcial[i] != cripto->criptografado[i]){
            printf("\033[32m%c\033[0m",cripto->parcial[i]);
        }
        else{
            printf("\033[31m%c\033[0m",cripto->parcial[i]);
        }

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


void alterarChave(criptografia *cripto, char original, char encriptada) {
    
    original = toupper(original);
    encriptada = toupper(encriptada);

    int idx = original - 'A';
    cripto->Chaves.cifra[idx] = encriptada;

    printf("Registrado: %c -> %c\n\n", original, encriptada);

    int n = strlen(cripto->criptografado);

    for (int i = 0; i < n; i++) {
        if (cripto->criptografado[i] == encriptada) {
            cripto->parcial[i] = original;
        }
    }
}

