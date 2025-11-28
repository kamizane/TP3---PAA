#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#include "../include/TAD_entrada.h"

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

void removeAcentoseMaiusculas(char *p){
    int j = 0;
    
    for(int i = 0; p[i];){

        char sub = 0;

        // Detecta caractere UTF-8 acentuado (prefixo 0xC3)
        if((unsigned char)p[i] == 0xC3){
              
            unsigned char proxC = (unsigned char)p[i+1];

            // á à ã â ä ... (e maiúsculas equivalentes)
            if(proxC == 0xA1 || proxC == 0xA0 || proxC == 0xA3 || proxC == 0xA2 
            || proxC == 0x81 || proxC == 0x80 || proxC == 0x83 || proxC == 0x82
            || proxC == 0x84 || proxC == 0xA4){
                sub = 'A';
            }

            // é ê è ë ... (e maiúsculas equivalentes)
            if(proxC == 0xA9 || proxC == 0xAA || proxC == 0x89 || proxC == 0x8A
            || proxC == 0x88 || proxC == 0x8B || proxC == 0xA8 || proxC == 0xAB){
                sub = 'E';
            }

            // í ì î ï ... (e maiúsculas equivalentes)
            if(proxC == 0xAD || proxC == 0x8D || proxC == 0xAE 
            || proxC == 0xAF || proxC == 0xAC || proxC == 0x8C 
            || proxC == 0x8E || proxC == 0x8F){
                sub = 'I';
            }

            // ó ò ô õ ö ... (e maiúsculas equivalentes)
            if(proxC == 0xB3 || proxC == 0xB2 || proxC == 0xB4 || proxC == 0xB5 
            || proxC == 0x93 || proxC == 0x92 || proxC == 0x94 || proxC == 0x95
            || proxC == 0xB6 || proxC == 0x96){
                sub = 'O';
            }

            // ú ù û ... (e maiúsculas equivalentes)
            if(proxC == 0xBA || proxC == 0xB9 || proxC == 0xBB || proxC == 0x9A 
            || proxC == 0x99 || proxC == 0x9B || proxC == 0x9C || proxC == 0xBC){
                sub = 'U';
            }

            // ç Ç
            if(proxC == 0xA7 || proxC == 0x87){
                sub = 'C';
            }

            // ñ Ñ
            if(proxC == 0xB1 || proxC == 0x91){
                sub = 'N';
            }

            // Se identificou um substituto, escreve e anda
            if(sub){
                p[j++] = sub; 
            }

            i += 2; // pula o caractere UTF-8
        } else {

            char c = p[i];

            // Se for letra normal maiúscula, converte
            if(c >= 'a' && c <= 'z'){
                c = toupper(c);
            }

            p[j++] = c;
            i++;
        }
    }

    p[j] = '\0';
}

void filtrarApenasLetras(char* str) {
    int i = 0;

    while(str[i] != '\0') {
        // isalpha verifica(A-Z ou a-z)
        if (isalpha(str[i])) {
            printf("(%c)", str[i]);
        }
        i++;
    }
}


char* folder_to_string(const char *path) {
    DIR *d = opendir(path);
    if (!d) return NULL; // Retorna NULL se não achar a pasta

    struct dirent *dir;
    char *result = malloc(1); // Começa vazia
    if (!result) { closedir(d); return NULL; }
    
    result[0] = '\0';
    size_t total_len = 0;

    while ((dir = readdir(d)) != NULL) {
        // Filtra: Pula pastas ocultas e garante que seja .txt
        if (dir->d_name[0] == '.') continue;
        if (!strstr(dir->d_name, ".txt")) continue;

        // Monta o caminho completo do arquivo
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, dir->d_name);

        FILE *f = fopen(full_path, "rb");
        if (f) {
            fseek(f, 0, SEEK_END);
            long fsize = ftell(f);
            fseek(f, 0, SEEK_SET);

            // Realoca memória: tamanho atual + tamanho novo + 1 (newline) + 1 (null terminator)
            char *temp = realloc(result, total_len + fsize + 2);
            if (temp) {
                result = temp;
                fread(result + total_len, 1, fsize, f); // Lê direto para o final da string
                total_len += fsize;
                
                // Opcional: Adiciona quebra de linha entre arquivos
                result[total_len] = '\n';
                total_len++;
                result[total_len] = '\0'; // Fecha a string
            }
            fclose(f);
        }
    }
    closedir(d);
    return result;
}