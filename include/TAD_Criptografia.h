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
    char * parcial;
}criptografia;

void inicializaChaves(criptografia * cripto, char * texto);
void imprimeClaro(criptografia * cripto);
void imprimeParcial(criptografia * cripto);
void imprimeCriptografado(criptografia * cripto);
void imprimeChaves(criptografia * cripto);
void alterarChave(criptografia *cripto);
#endif