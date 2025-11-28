#ifndef TAD_FREQUENCIA_H
#define TAG_FREQUENCIA_H


typedef struct{
    char caractere;
    double qntd;
    double frequencia;
}ListaFrequencia;

void executaFrequencia(ListaFrequencia lista[], char *texto);
void criaListaFrequencia(ListaFrequencia lista[]);
void contabilizaLetra(ListaFrequencia lista[], char *str);
void imprimeLetrasEfrequencia(ListaFrequencia lista[]);
double contagemLetrastexto(char *str);
void calculaFrequencia(ListaFrequencia lista[], char *str);


#endif