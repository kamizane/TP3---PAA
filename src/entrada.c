#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerEntrada(){
    FILE *file;
    while(1){
        char nome[256];

        printf("Digite o caminho para o arquivo (0 para sair):\n");
        scanf("%s", nome);
        
        if(strcmp(nome,"0")==0){
            printf("Saindo...\n");
            return;
        }
        
        file = fopen(nome, "r");

        if(file == NULL){
            printf("Arquivo invalido, tente novamente...\n");
            continue;
        }else{
            break;
        }
    }
}