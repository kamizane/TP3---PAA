#ifndef TAD_FREQUENCIA_H
#define TAG_FREQUENCIA_H

#define tamVetor 27

typedef struct{
    char caractere;
    double qntd;
    double frequencia;
}ListaFrequencia;

typedef struct{
    ListaFrequencia listaTexto[tamVetor];
    ListaFrequencia lista12textos[tamVetor];
    ListaFrequencia listaAlfabeto[tamVetor];
}ColecaoFrequencias;


void criaColecaoFrequencia(ColecaoFrequencias *colecao, char *texto);
void imprimeColecaofreq(ColecaoFrequencias colecao);
void imprimeColecao(ColecaoFrequencias colecao);

void criaListaFrequencia(ListaFrequencia lista[]);
void executaFrequencia(ListaFrequencia lista[], char *texto);
void executaFrequencia12arquivos(ListaFrequencia lista[]);
void contabilizaLetra(ListaFrequencia lista[], char *str);
void imprimeLetrasEfrequencia(ListaFrequencia lista[]);
double contagemLetrastexto(char *str);
void calculaFrequencia(ListaFrequencia lista[], char *str);
void leArquivoFrequencia(ListaFrequencia lista[]);

void chutaCifraTexto(ColecaoFrequencias colecao);
void chutaCifra12Textos(ColecaoFrequencias colecao);
void cravaMapeamento(ColecaoFrequencias colecao);

#endif