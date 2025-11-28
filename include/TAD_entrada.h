#ifndef ENTRADA_H
#define ENTRADA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

char* lerEntrada();
void removeAcentoseMaiusculas(char *p);
void filtrarApenasLetras(char* str);
char* folder_to_string(const char *path);

#endif