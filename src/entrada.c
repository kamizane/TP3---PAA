#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/TAD_Entrada.h"

char* lerEntrada() {
    FILE *file;
    char nome[256];
    char *conteudo = NULL;
    long tamanhoArquivo;

    while(1) {
        printf("Digite o caminho para o arquivo (0 para sair):\n");
       
        scanf("%255s", nome);

        if(strcmp(nome, "0") == 0) {
            printf("Saindo...\n");
            return NULL;
        }

        file = fopen(nome, "r");

        if(file == NULL) {
            printf("Arquivo invalido, tente novamente...\n");
            continue;
        } else {
            
            fseek(file, 0, SEEK_END); 
            tamanhoArquivo = ftell(file);
            rewind(file);

            conteudo = (char*) malloc(sizeof(char) * (tamanhoArquivo + 1));

            if (conteudo == NULL) {
                printf("Erro ao alocar memoria!\n");
                fclose(file);
                return NULL;
            }

            size_t lidos = fread(conteudo, 1, tamanhoArquivo, file);
            
            conteudo[lidos] = '\0';
            fclose(file);
            return conteudo; 
        }
    }
}

void removeAcentos(char *p){
    int j = 0;
    
    for(int i = 0; p[i];){

        char sub = 0;

        //UTF-8 pra acentos e tal no alfabeto latino (basic latin)
        //com 0xC3 sendo prefixo para elementos fora dos ascii normais 
        //(C3 + A1 -> 'á', por exemplo, com 0x na frente para indicar hex)
        if((unsigned char)p[i] == 0xC3){
              
            unsigned char proxC = (unsigned char)p[i+1];

            //á à ã â ä , o mesmo pro maiusculo com acentos
            if(proxC == 0xA1 || proxC == 0xA0 || proxC == 0xA3 || proxC == 0xA2 
                || proxC == 0x81 || proxC == 0x80 || proxC == 0x83 || proxC == 0x82
                || proxC == 0x84 || proxC == 0xA4){
                sub = 'a';
            }

            //é ê è ë, o mesmo pros maiusculos
            if(proxC == 0xA9 || proxC == 0xAA || proxC == 0x89 || proxC == 0x8A
                || proxC == 0x88 || proxC == 0x8B || proxC == 0xA8 || proxC == 0xAB){
                sub = 'e';
            }

            //í Í ì î ï...
            if(proxC == 0xAD || proxC == 0x8D || proxC == 0xAE 
                || proxC == 0xAF || proxC == 0xAC || proxC == 0x8C 
                || proxC == 0x8E || proxC == 0x8F){
                sub = 'i';
            }

            //ó ò ô õ Ö...
            if(proxC == 0xB3 || proxC == 0xB2 || proxC == 0xB4 || proxC == 0xB5 
                || proxC == 0x93 || proxC == 0x92 || proxC == 0x94 || proxC == 0x95
                || proxC == 0xB6 || proxC == 0x96){
                sub = 'o';
            }

            //ú ù û...
            if(proxC == 0xBA || proxC == 0xB9 || proxC == 0xBB || proxC == 0x9A 
                || proxC == 0x99 || proxC == 0x9B || proxC == 0x9C || proxC == 0xBC){
                sub = 'u';
            }

            //ç Ç
            if(proxC == 0xA7 || proxC == 0x87){
                sub = 'c';
            }

            if(proxC == 0x91 || proxC == 0xB1){
                sub = 'n';
            }

            if(sub){
                //alterando o caractere
                p[j] = sub;
                j++;
            }
            
            
            //pular os 2 bytes do trem ai, o atual e o verificado acima
            i += 2;
        }else{
            
            p[j] = p[i];
            
            i++;
            j++;
            
        }
    }
    //acabou a palavra com o fim do for
    p[j] = '\0';
}