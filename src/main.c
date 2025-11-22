#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para inicializar o random

// IMPORTANTE: Inclua os .h, NUNCA os .c
#include "../include/TAD_Entrada.h"
#include "../include/TAD_Criptografia.h"

void menu();

int main(){
    // Inicializa o gerador de números aleatórios uma única vez
    srand(time(NULL)); 
    menu();
    return 0;
}

void menu(){
    lerEntrada();
    
    // É necessário alocar espaço para string se for alterar ela (não usar "teste" literal direto se for modificar)
    char teste[] = "teste de criptografia"; 
    
    cifraDeDeslocamento(teste);
    
    printf("Texto cifrado inicial: %s\n", teste);

    int flag = 1;
    while(flag){
        printf("\n--------------------MENU--------------------\n");
        printf("1- Apresentar o estado atual da criptografia\n");
        printf("2- Fazer um chute baseado na analise de frequencia\n");
        printf("3- Realizar casamento exato\n");
        printf("4- Alterar chave de criptografia\n");
        printf("0- Exportar e sair\n");
        printf("Escolha uma opcao: ");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            criptografia cripVar; // Nome da variável mudado para não confundir com o tipo
            inicializaChaves(&cripVar);
            break;
        }
        case 2:{
            char* texto = NULL;
            texto = lerEntrada();
            printf("Texto: %s\n", texto);
            removeAcentos(texto);
            printf("Texto: %s\n", texto);
            break;
        }
        case 3:
            printf("Funcionalidade ainda nao implementada.\n");
            break;
        case 4:
            printf("Funcionalidade ainda nao implementada.\n");
            break;
        case 0:
            printf("Exportando resultados e fechando programa...\n");
            flag = 0; // Encerra o loop
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}