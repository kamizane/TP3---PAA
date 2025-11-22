#include <stdio.h>
#include <stdlib.h>
#include "../include/TAD_Criptografia.h"

void inicializaChaves(criptografia * cripto){
    char letraEmNumero = 97;
    for (int i=0; i<26; i++){
        cripto->Chaves.normal[i] = 97;
        cripto->Chaves.cifra[i] = ' ';
        letraEmNumero++;
    }


    for (int i=0; i<26; i++){
    printf("%c ", cripto->Chaves.normal[i]);
    }

    for (int i=0; i<26; i++){
    printf("%c ", cripto->Chaves.cifra[i]);
    }
}