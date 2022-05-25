/**
@file interface.h
\brief Módulo da Interface do Programa.
*/
#ifndef INTERFACE_H
#define INTERFACE_H

#include "sgv.h"
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#define MAX_CHAR_FILES 256

/**
@brief Interface do Trabalho.
*/
void criaInterface();

/**
@brief Interface para o Valgrind.
*/
void criaInterfaceValgrind();


#endif