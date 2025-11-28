#include <stdio.h>
#include <string.h>
#include "entrada.c"
#include "../include/TAD_Criptografia.h"
#include "busca_encripto.c"
#include "../include/TAD_frequencia.h"

void menu();
char * lerDoTeclado();

int main(){
    menu();
}

void menu(){
    char * texto = lerEntrada();
    removeAcentoseMaiusculas(texto);
    criptografia teste;
    inicializaChaves(&teste, texto);
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

        int c;
        while ((c = getchar()) != '\n' && c != EOF);//limpando o buffer


        switch (opcao){
        case 1:{
            imprimeCriptografado(&teste);
            imprimeChaves(&teste);
            imprimeParcial(&teste);
            break;
            };
        case 2:{
            char* texto = NULL;
            texto = lerEntrada();
            removeAcentoseMaiusculas(texto);
            // ListaFrequencia lista[27];
            // executaFrequencia(lista, texto);

            ColecaoFrequencias colecao;
            criaColecaoFrequencia(&colecao, texto);
            //imprimeColecaofreq(colecao);
            imprimeColecao(colecao);
            // char* pi  = folder_to_string("input/12arquivos");
            // removeAcentoseMaiusculas(pi);
            // printf("%s", pi);
            // ListaFrequencia lista2[27];
            // criaListaFrequencia(lista2);
            // leArquivoFrequencia(lista2);
            // imprimeLetrasEfrequencia(lista2);
            // chutaCifraTexto(colecao);
            // chutaCifra12Textos(colecao);
            cravaMapeamento(colecao);
            break;
        }
        case 3:{
            printf("Qual o padrao utilizado?\n> ");
            char * padrao = lerDoTeclado();
            int contador =0; float frequencia =0;
            casamento_exato(teste.criptografado, padrao, &frequencia, &contador);
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



char * lerDoTeclado() {
    char buffer[1000];

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL; 
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    char *texto = malloc(strlen(buffer) + 1);
    if (texto == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    strcpy(texto, buffer);
    return texto;
}
