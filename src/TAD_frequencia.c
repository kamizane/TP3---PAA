#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/quicksort.h"
#include "../include/entrada.h"

void criaColecaoFrequencia(ColecaoFrequencias *colecao, char *texto){
    executaFrequencia(colecao->listaTexto,texto);
    leArquivoFrequencia(colecao->listaAlfabeto);
    executaFrequencia12arquivos(colecao->lista12textos);
}

void imprimeColecaofreq(ColecaoFrequencias colecao){
    printf("Frequencia do texto original:\n");
    imprimeLetrasEfrequencia(colecao.listaTexto);
    printf("----------------------------------------\n");
    printf("Frequencia dos 12 arquivos:\n");
    imprimeLetrasEfrequencia(colecao.lista12textos);
    printf("----------------------------------------\n");
     printf("Frequencia do alfabeto:\n");
    imprimeLetrasEfrequencia(colecao.listaAlfabeto);
    printf("----------------------------------------\n");
}

void imprimeColecao(ColecaoFrequencias colecao) {

    // Cores
    const char *COR1 = "\033[34m"; // azul
    const char *COR2 = "\033[32m"; // verde
    const char *COR3 = "\033[35m"; // magenta
    const char *RESET = "\033[0m";

    // Cabeçalho
    printf("%s%-26s%s | %s%-26s%s | %s%-26s%s\n",
           COR1, "Texto Criptografado", RESET,
           COR2, "12 Arquivos", RESET,
           COR3, "Alfabeto", RESET);

    printf("%s%-26s%s | %s%-26s%s | %s%-26s%s\n",
           COR1, "Letra  Cnt   Freq", RESET,
           COR2, "Letra  Cnt   Freq", RESET,
           COR3, "Letra  Cnt   Freq", RESET);

    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < 26; i++) {

        char buf1[40], buf2[40], buf3[40];

        if (colecao.listaTexto[i].caractere == '*')
            snprintf(buf1, sizeof(buf1), "-");
        else
            snprintf(buf1, sizeof(buf1), "%-1c %5.0lf %7.2lf%%",
                     colecao.listaTexto[i].caractere,
                     colecao.listaTexto[i].qntd,
                     colecao.listaTexto[i].frequencia * 100);

        if (colecao.lista12textos[i].caractere == '*')
            snprintf(buf2, sizeof(buf2), "-");
        else
            snprintf(buf2, sizeof(buf2), "%-1c %5.0lf %7.2lf%%",
                     colecao.lista12textos[i].caractere,
                     colecao.lista12textos[i].qntd,
                     colecao.lista12textos[i].frequencia * 100);

        if (colecao.listaAlfabeto[i].caractere == '*')
            snprintf(buf3, sizeof(buf3), "-");
        else
            snprintf(buf3, sizeof(buf3), "%-1c %5.0lf %7.2lf%%",
                     colecao.listaAlfabeto[i].caractere,
                     colecao.listaAlfabeto[i].qntd,
                     colecao.listaAlfabeto[i].frequencia * 100);

        // Três colunas com cores diferentes
        printf("%s%-26s%s | %s%-26s%s | %s%-26s%s\n",
               COR1, buf1, RESET,
               COR2, buf2, RESET,
               COR3, buf3, RESET);
    }

    printf("\n");
}




void executaFrequencia(ListaFrequencia lista[], char *texto){
    criaListaFrequencia(lista);
    contabilizaLetra(lista, texto);
    calculaFrequencia(lista, texto);
    QuickSort(lista,tamVetor);
}
void executaFrequencia12arquivos(ListaFrequencia lista[]){

    char* textoCompleto = folder_to_string("input/12arquivos");
    removeAcentoseMaiusculas(textoCompleto);
    //printf("%s", textoCompleto);
    criaListaFrequencia(lista);
    contabilizaLetra(lista,textoCompleto);
    calculaFrequencia(lista,textoCompleto);
    QuickSort(lista,tamVetor);
}
void criaListaFrequencia(ListaFrequencia lista[]){
    for (int i = 0; i < 27; i++) {
        lista[i].caractere = '*';
        lista[i].qntd = 0;
        lista[i].frequencia = 0;
    }
}

void contabilizaLetra(ListaFrequencia lista[], char *str){
    int i = 0;
    
    while (str[i] != '\0'){
        // isalpha verifica(A-Z ou a-z)
        if (isalpha(str[i])){
            int indiceLetra = tolower(str[i]) - 'a'; // em ascii essa conta retorna um indice entre tam alfabeto
            //printf("(%c)", str[i]);
            if (lista[indiceLetra].caractere == '*'){
                lista[indiceLetra].caractere = str[i];
                lista[indiceLetra].qntd++;
            }
            else
            {
                lista[indiceLetra].qntd++;
            }
        }
        i++;
    }
}

void calculaFrequencia(ListaFrequencia lista[], char *str){

    double letrasTexto = contagemLetrastexto(str);
    //printf("%lf\n", letrasTexto); //retirar dps
    for(int i = 0;i < tamVetor;i++){
    if(lista[i].caractere != '*'){
        lista[i].frequencia = (lista[i].qntd / letrasTexto); //frequencia em 0.(algo) tem que multiplicar por 100
    }else{continue;}
    }
}

double contagemLetrastexto(char *str){
    int i = 0;
    double cont = 0;
    while(str[i] != '\0') {
        if (isalpha(str[i])) {
            cont++;
            i++;
        }else{i++;}
    }
    return cont;
}

void imprimeLetrasEfrequencia(ListaFrequencia lista[]) {
    printf("Letra,  Contagem,   Frequencia\n");

    for (int i = 0; i < tamVetor; i++) {
        if (lista[i].caractere == '*') {
            continue;
        } else {
            // 2. e 3. Modificação do printf para formatação de tabela
            // %-7c   -> Imprime o char alinhado à esquerda (o menos faz isso) num espaço de 7 chars
            // %6.0lf -> Imprime o contador alinhado à direita num espaço de 6 chars
            // %6.2lf -> Imprime a frequência alinhada à direita num espaço de 6 chars
            // %%     -> Imprime o símbolo de porcentagem literal
            printf("%-7c %8.0lf %12.2lf%%\n", 
                   lista[i].caractere, 
                   lista[i].qntd, 
                   lista[i].frequencia * 100);
        }
    }
}

void leArquivoFrequencia(ListaFrequencia lista[]) {
    // Inicializa a lista
    const char *nomeArquivo = "input/ListaFrequencia.txt";

    for (int i = 0; i < tamVetor; i++) {
        lista[i].caractere = '*';
        lista[i].qntd = 0;
        lista[i].frequencia = 0.0;
    }
    
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s , insira uma lista de frequencia do alfabeto convencional!\n", nomeArquivo);
        return;
    }
    
    char letra;
    double frequencia;
    
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, " %c %lf", &letra, &frequencia) == 2) {
            letra = toupper(letra);
            int indice = tolower(letra) - 'a';
            lista[indice].caractere = letra;
            lista[indice].frequencia = frequencia;
            lista[indice].qntd = 0;
            //printf("Lido: %c -> frequencia: %.4lf\n", letra, frequencia);
    }
}
    QuickSort(lista,tamVetor);
    fclose(arquivo);
    printf("\nLeitura concluida com sucesso!\n");
}

void chutaCifraTexto(ColecaoFrequencias colecao, criptografia *cripto){
    for(int i = 0; i < 27; i++){
        if(colecao.listaTexto[i].caractere == '*')
            continue;

        double freq = colecao.listaTexto[i].frequencia;
        int indice = buscaBinariaAproximada(colecao.listaAlfabeto, tamVetor, freq);

        //printf("%c -> %c\n", colecao.listaTexto[i].caractere, colecao.listaAlfabeto[indice].caractere);
        //substituir funcao troca
        alterarChave(cripto, colecao.listaAlfabeto[indice].caractere, colecao.listaTexto[i].caractere);
        colecao.listaAlfabeto[indice].caractere = '*';
    }
    printf("\n");
}

void chutaCifra12Textos(ColecaoFrequencias colecao, criptografia *cripto){
    for(int i = 0; i < 27; i++){
        if(colecao.lista12textos[i].caractere == '*')
            continue;

        double freq = colecao.lista12textos[i].frequencia;
        int indice = buscaBinariaAproximada(colecao.listaAlfabeto, tamVetor, freq);

        //printf("%c -> %c\n",colecao.lista12textos[i].caractere,colecao.listaAlfabeto[indice].caractere);
        alterarChave(cripto, colecao.listaAlfabeto[indice].caractere, colecao.listaTexto[i].caractere);
        colecao.listaAlfabeto[indice].caractere = '*';
    }
    printf("\n");
}

void cravaMapeamento(ColecaoFrequencias colecao, criptografia *cripto) { //crava o mapeamento com base na letra mais frequente do texto
    // letra mais frequente do texto
    int idxMax = -1;
    double maiorFreq = -1.0;

    for (int i = 0; i < 27; i++) {
        if (colecao.listaTexto[i].caractere == '*')
            continue;

        if (colecao.listaTexto[i].frequencia > maiorFreq) {
            maiorFreq = colecao.listaTexto[i].frequencia;
            idxMax = i;
        }
    }

    if (idxMax == -1) {
        printf("Nenhuma letra válida encontrada.\n");
        return;
    }

    char letraTexto = colecao.listaTexto[idxMax].caractere;
    double freqTexto = colecao.listaTexto[idxMax].frequencia;

    // analise em freq alfabeto
    int idxAlfa = buscaBinariaAproximada(colecao.listaAlfabeto, 27, freqTexto);
    char letraAlfa = colecao.listaAlfabeto[idxAlfa].caractere;

    int deslocamento = (letraTexto - letraAlfa);
    if (deslocamento < 0){
        deslocamento += 26;
    }

    // printf("Letra freq: %c\n", letraTexto);
    // printf("Letra freq mapeada: %c\n", letraAlfa);
    // printf("Deslocamento: %d\n\n", deslocamento);

    // 4) Agora usa o deslocamento para mapear TODAS as letras do texto
    printf("Mapeamento completo usando deslocamento:\n");

    for (int i = 0; i < 27; i++) {
        if (colecao.listaTexto[i].caractere == '*')
            continue;

        char cifrada = colecao.listaTexto[i].caractere;

        if (cifrada < 'A' || cifrada > 'Z') { //so letra
            printf(" caractere invalido: %c -> ?\n", cifrada);
            continue;
        }
        char decodificada = ((cifrada - 'A' - deslocamento + 26) % 26) + 'A';

        //printf("%c -> %c\n", cifrada, decodificada); //substituir funcao troca
        alterarChave(cripto, decodificada, cifrada);
    }

    printf("\n");
}
