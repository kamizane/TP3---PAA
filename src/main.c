#include <stdio.h>

#include "entrada.c"
#include "criptografar.c"
#include "../include/TAD_Criptografia.h"
#include "busca_encripto.c"

void menu();

int main(){
    menu();
}

void menu(){
    lerEntrada();
    char teste[] = "teste";
    cifraDeDeslocamento(teste);
    for(int i=0; i<5;i++){
        printf("%c", teste[i]);
    }
    int flag = 1;
    while(flag){
        printf("--------------------MENU--------------------\n");
        printf("1- Apresentar o estado atual da criptografia\n");
        printf("2- Fazer um chute baseado na analise de frequencia no texto encriptografado\n");
        printf("3- Realizar casamento exato de caracteres no texto encriptografado\n");
        printf("4- Realizar casamento aproximado de caracteres no texto parcialmente decifrado\n");
        printf("5 - Alterar chave de criptografia\n");
        printf("6- Exportar resultado e encerrar o programa\n");

        printf("Escolha uma opcao acima:\n");
        int opcao;
        scanf("%d", &opcao);
        switch (opcao){
        case 1:{
            criptografia teste;
            inicializaChaves(&teste);
            break;
            };
        case 2:{
            char* texto = NULL;
            texto = lerEntrada();
            printf("Texto: %s\n", texto);
            removeAcentoseMaiusculas(texto);
            printf("Texto: %s\n", texto);
            filtrarApenasLetras(texto);
            break;
        }
        case 3:{
            criptografia teste2;
            inicializaChaves(&teste2);
            int contador =0; float frequencia =0;
            casamento_exato("CASA","A",&frequencia, &contador);
            printf("Ocorrencias: %d\n", contador); 
            printf("Frequencia: %.2f%%\n", frequencia); 
            break;
        };
        case 4:
            break;
        case 5:
            break;
        case 6:
            printf("Exportanto resultados e fechando programa...\n");
            return;
        
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}