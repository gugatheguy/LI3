/**
@file auxStructs.h
\brief Módulo Auxiliar à realização das estruturas de dados FacTotal e da Filial, assim prints de listas de códigos em diversos módulos.
*/
#ifndef AUXSTRUCTS_H
#define AUXSTRUCTS_H 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "glibWarningAvoid.h"

/**
\brief Estrutura de Dados que guarda strings.
*/
typedef GArray* StringArray;

/**
@brief Iniciliza um StringArray (GArray).
@return Struct StringArray com memória alocada.
*/
StringArray criaStringArray();

/**
@brief Adiciona uma String ao StringArray (GArray).
@param r StringArray.
@param value gpointer(String).
@return StringArray (GArray) resultante.	
*/
StringArray adicionaStringArray(StringArray r,  gpointer value);

/**
@brief Tamanho do StringArray (GArray).
@param r StringArray.
@return Tamanho do StringArray (GArray).
*/
int getSizeStringArray(StringArray r);

/**
@brief Obtém uma String existente no StringArray (GArray) a partir do índice onde se encontra.
@param r StringArray.
@param idx Índice onde se encontra a String.
@return String resultante.
*/
char* getString(StringArray r, int idx);

/**
@brief Liberta o ArrayString (GArray).
@param r StringArray a ser destruído.
*/
void eliminaStringArray(StringArray r);

#endif