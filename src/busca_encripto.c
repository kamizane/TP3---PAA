#include <stdio.h>
#include <string.h>
#include "../include/TAD_Ocorrencias.h"

void shift(int vetor[], int tamanho){
    for(int i = tamanho;  i>0; i--){
        vetor[i] = vetor[i-1];
    }
    vetor[0] = 0;
}


void casamentoAproximado(int maxOperacoes, char texto[], char padrao[]){
    //declarações
    int tamanhoPadrao = strlen(padrao);
    int tamanhoTexto = strlen(texto);
    int tamanhoM = 0;
    int infos = -1;
    char M[tamanhoPadrao][tamanhoPadrao+1];
    Ocorrencias ocorrencias[maxOperacoes+1];

    for(int i = 0; i<=maxOperacoes;i++){
        inicializaListaVazia(&ocorrencias[i]);
    }
    
    printf("Gostaria de visualizar, alem das ocorrencias, as tabelas do shift-and? entradas aceitas:(s/n) \n");
    while(infos<0){
        char entrada;
        scanf("%c", &entrada);
        if(entrada == 's'){
            infos = 1;
        }else if(entrada == 'n'){
            infos = 0;
        }else{
            printf("Entrada inválida, tente novamente!\n");
        }
        printf("\n");
    }





    //inicializando a tabela M zerada
    for(int i = 0; i<tamanhoPadrao; i++){
        for(int j = 0; j<=tamanhoPadrao;j++){
            M[i][j]= 0;
        }
    }

    //criando a tabela M
    for(int i = 0; i<tamanhoPadrao; i++){
        int estaListado = 0;
        for(int j = 0; j<tamanhoM;j++){
            if(M[j][0] == padrao[i]){
                M[j][i+1] = 1;
                estaListado = 1;
                break;
            }
        }
        if(estaListado == 0){
            M[tamanhoM][0] = padrao[i];
            M[tamanhoM][i+1] = 1;
            tamanhoM++;
        }
    }


    //gerando R
    
    int R[maxOperacoes+1][tamanhoPadrao];
    int Rlinha[maxOperacoes+1][tamanhoPadrao];

    for(int i = 0; i<=maxOperacoes; i++){
        for(int j = 0; j<tamanhoPadrao; j++){
            R[i][j] = 0;
            Rlinha[i][j] = 0;
        }

    }

    //lendo cada letra
    
    for(int i = 0;i<tamanhoTexto ;i++){


        //faz o shift do R linha e coloca no r
        for(int j = 0; j<=maxOperacoes; j++){
            shift(Rlinha[j],tamanhoPadrao);
            for(int k=0; k<tamanhoPadrao;k++){
                R[j][k] = Rlinha[j][k];
            }
        }
        for(int j = 0; j<=maxOperacoes; j++){
            R[j][0] = 1;
        }

        for(int j=1; j<=maxOperacoes;j++){
            if(i>=j){
                for(int k = tamanhoPadrao-1; k>0; k--){
                    if(R[j-1][k] == 1){
                        R[j][k] = 1;
                    }
                }
            }
        }


        int linhaM = 0;
        //verifica se a letra em questão esta no padrao
        for(int j = 0; j<tamanhoM; j++){
            if(texto[i] == M[j][0]){
                linhaM = j;
                break;
            }
        }
        
        //faz o r linha

        
        for(int k=0; k<tamanhoPadrao; k++){
            if((R[0][k]==1)&&(M[linhaM][k+1]== 1) && (texto[i] == M[linhaM][0])){
                Rlinha[0][k] = 1; 
            }else{
                Rlinha[0][k] = 0;
            }
        }   

        for(int j=1; j<=maxOperacoes;j++){
            for(int k=0; k<tamanhoPadrao; k++){
                if((R[j][k]==1)&&(((M[linhaM][k+1]== 1) && (texto[i] == M[linhaM][0])) || R[j-1][k]==1)){
                    Rlinha[j][k] = 1; 
                }else{
                    Rlinha[j][k] = 0;
                }
            }                
        }

        

        if(infos == 1){
            printf("\033[34m%c       |\033[0m", texto[i]);
            for(int j = 0; j<=maxOperacoes;j++){
                printf(" k = %d :", j);
                for(int k = 0;k<tamanhoPadrao;k++){
                    printf("%d",R[j][k]);
                }
                printf(" ");
                for(int k = 0;k<tamanhoPadrao;k++){
                    printf("%d",Rlinha[j][k]);
                }
                printf(" \033[34m||\033[0m");
            }
            if(i == tamanhoTexto-1){
                printf("\n\n\n");
            }else{
                printf("\n");
            }
            
        }


        for(int j = 0; j<=maxOperacoes;j++){
            if(Rlinha[j][tamanhoPadrao-1] == 1){
                insereOcorrencia(&ocorrencias[j],i);
            }

        }
        

    }

    if(infos == 1){
        for(int i = 0; i<tamanhoM; i++){
            printf("\033[34m%c\033[0m " ,M[i][0]);
            for(int j = 1; j<=tamanhoPadrao;j++){
                printf("%d " ,M[i][j]);
            }
            printf("\n");
        }   
        printf("\n\n");
    }

    for(int i = 0; i<=maxOperacoes; i++){
        printf("\033[34mOcorrencias com %d operacoes:  %d\033[0m\n",i,ocorrencias[i].tamanho);
    }
    printf("\n\n");


    for(int i = 0; i<=maxOperacoes; i++){

        printf("\033[34mOcorrencias para %d operacoes:\033[0m\n",i);

        Celula * celulaOcorrencia;
        celulaOcorrencia = ocorrencias[i].primeiro->prox;

        
        for(int k = 0; k<ocorrencias[i].tamanho;k++){
            printf("\033[34mOcorrencia %d:\033[0m \n", k+1);
            int pos = 0;
            for(int j = 0 ; j< tamanhoTexto; j++){
                
                if((celulaOcorrencia->posicao - j < tamanhoPadrao)&&(celulaOcorrencia->posicao - j >=0)){
                    if(texto[j]!= padrao[pos]){
                        printf("\033[31m""%c""\033[0m", texto[j]);
                    }else{
                        printf("\033[32m""%c""\033[0m", texto[j]);
                    }
                    
                    pos++;
                }else{
                    printf("%c", texto[j]); 
                }


            }
            printf("\n");

            if(celulaOcorrencia->prox != NULL){
                celulaOcorrencia = celulaOcorrencia->prox;
            }
            
        }
        printf("\n\n");
    }


}

