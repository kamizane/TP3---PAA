#ifndef TAD_FREQUENCIA_H
#define TAG_FREQUENCIA_H


typedef struct{
    char caractere;
    double qntd;
    double frequencia;
}ListaFrequencia;

typedef struct{
    ListaFrequencia listaTexto[27];
    ListaFrequencia lista12textos[27];
    ListaFrequencia listaAlfabeto[27];
}ColecaoFrequencias;


void criaColecaoFrequencia(ColecaoFrequencias *colecao, char *texto);
void imprimeColecaofreq(ColecaoFrequencias colecao);

void criaListaFrequencia(ListaFrequencia lista[]);
void executaFrequencia(ListaFrequencia lista[], char *texto);
void executaFrequencia12arquivos(ListaFrequencia lista[]);
void contabilizaLetra(ListaFrequencia lista[], char *str);
void imprimeLetrasEfrequencia(ListaFrequencia lista[]);
double contagemLetrastexto(char *str);
void calculaFrequencia(ListaFrequencia lista[], char *str);
void leArquivoFrequencia(ListaFrequencia lista[]);


#endif