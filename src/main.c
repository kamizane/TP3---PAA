#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/TAD_entrada.h"
#include "../include/TAD_Criptografia.h"
#include "../include/busca_encripto.h"
#include "../include/TAD_frequencia.h"
#include "../include/processador_cripto.h"

void menu();
char * lerDoTeclado();

int main(){
    menu();
}

void menu(){
    //faz a leitura e utiliza o arquivo especificado ao grupo
    char * texto = lerEntrada(1);
    char original, encriptada;
    removeAcentoseMaiusculas(texto);
    criptografia teste;
    inicializaChaves(&teste, texto);

    int flag = 1;
    while(flag){
        printf("\033[33m--------------------MENU--------------------\033[0m\n");
        printf("\033[33m1\033[0m - Apresentar o estado atual da criptografia\n");
        printf("\033[33m2\033[0m - Fazer um chute baseado na analise de frequencia no texto encriptografado\n");
        printf("\033[33m3\033[0m - Realizar casamento exato de caracteres no texto encriptografado\n");
        printf("\033[33m4\033[0m - Realizar casamento aproximado de caracteres no texto parcialmente decifrado\n");
        printf("\033[33m5\033[0m - Alterar chave de criptografia\n");
        printf("\033[33m6\033[0m - Exportar resultado e encerrar o programa\n");

        printf("Escolha uma opcao acima: ");
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
            texto = lerEntrada(0);
            printf("Texto: %s\n", texto);
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
            printf("Ocorrencia total: %d\n", contador); 
            printf("Frequencia (quantidade de letras): %.2f%%\n", frequencia); 
            break;
        };
        case 4:{

            int maxOperacoes = 0;
            printf("Qual o padrao utilizado?\n> ");
            char * padrao = lerDoTeclado();
            printf("Qual o limite de operacoes?\n>");
            scanf("%d", &maxOperacoes);

            casamentoAproximado(maxOperacoes,teste.parcial, padrao);
            teste.parcial[0] = ';';
            break;
        };
        case 5:
            printf("Informe a letra original e a letra para a qual foi mapeada (ex: A S):\n> ");
            scanf(" %c %c", &original, &encriptada);
            alterarChave(&teste, original, encriptada);
            break;
        case 6:
            exportarResultado(&teste);
            flag =0;
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
