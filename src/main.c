#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/entrada.h"
#include "../include/busca_encripto.h"
#include "../include/TAD_frequencia.h"
#include "../include/processador_cripto.h"

void menu();
char * lerDoTeclado();

int main(){
    menu();
}

void menu(){
    printf("Deseja ler o texto do grupo (1) ou inserir manualmente outro texto?(2): ");
    int m;
    scanf("%d", &m);
    char * texto=NULL;
    if (m == 1){
        texto = lerEntrada(1);
    }
    else{
        texto = lerEntrada(2);
    }

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
            ColecaoFrequencias colecao;
            criaColecaoFrequencia(&colecao, texto);
            imprimeColecao(colecao);

            int opcaoFreq = 0;
            printf("----Selecione como sera o chute----\n");
            printf("1 - Chutar com base apenas em 1 texto\n");
            printf("2 - Chutar com base nos 12 textos\n");
            printf("3 - Chute feito com base na letra que tem maior frequencia, e apos isso deslocamento das outras\n");
            printf("4 - Imprimir tabelas de frequencia\n");
            printf("Digite a opcao: ");
            scanf("%d", &opcaoFreq);

            switch (opcaoFreq)
            {
            case 1:
                chutaCifraTexto(colecao, &teste);
                break;
            case 2:
                chutaCifra12Textos(colecao, &teste);
                break;
            case 3:
                cravaMapeamento(colecao, &teste);
                break;
            case 4:
                imprimeColecao(colecao);
            default:
                break;
            }
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
            flag = 0;
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
