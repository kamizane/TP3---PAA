#include <stdio.h>
#include <stdlib.h>
#include "../include/TAD_Criptografia.h"

void inicializaChaves(criptografia * cripto){
    char letraEmNumero = 65;
    for (int i=0; i<26; i++){
        cripto->Chaves.normal[i] = letraEmNumero;
        cripto->Chaves.cifra[i] = ' ';
        letraEmNumero++;
    }


    for (int i=0; i<26; i++){
    printf("%c ", cripto->Chaves.normal[i]);
    }
    printf("\n");
    for (int i=0; i<26; i++){
    printf("%c ", cripto->Chaves.cifra[i]);
    }
    printf("\n");

}