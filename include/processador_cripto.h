#ifndef PROCESSADOR_CRIPTO_H
#define PROCESSADOR_CRIPTO_H
int gerarNmrAleatorio(int min, int max);
void cifraDeDeslocamento(char *texto);
void computeLastOcc(const char *padrao, int lastOcc[]);
void casamento_exato(char *texto, char *padrao,float * frequencia, int *contador);

#endif