#ifndef TAD_CRIPTOGRAFIA_H
#define TAG_CRIPTOGRAFIA_H

typedef struct{
    char normal[26];
    char cifra[26];
}chave;

typedef struct{
    chave Chaves;
    char * claro;
    char * criptografado;
}criptografia;

void inicializaChaves(criptografia * cripto);
#endif