/**
@file auxStructsFact.h
\brief Módulo Auxiliar à FactTotal para o seu encapsulamento.
*/
#ifndef AUXSTRUCTSFACT_H
#define AUXSTRUCTSFACT_H 

#include<stdio.h>
#include "fact.h"

/**
\brief Estrutura de Dados que guarda Facts.
*/
typedef GArray* FactArray;

/**
@brief Iniciliza um FactArray (GArray).
@return Struct FactArray com memória alocada.
*/
FactArray criaFactArray();

/**
@brief Adiciona uma Fact ao FactArray (GArray).
@param r FactArray.
@param value gpointer(Fact).
@return FactArray (GArray) resultante.	
*/
FactArray adicionaFactArray(FactArray r,  gpointer value );

/**
@brief Tamanho do FactArray (GArray).
@param r FactArray.
@return Tamanho do FactArray (GArray).
*/
int getSizeFactArray(FactArray r);

/**
@brief Obtém uma Fact existente no FactArray (GArray) a partir do índice onde se encontra.
@param r FactArray.
@param idx Índice onde se encontra a Fact.
@return Fact resultante.
*/
Fact getFactArray(FactArray r, int idx);

/**
@brief Liberta o ArrayFact (GArray).
@param r FactArray a ser destruído.
*/
void eliminaFactArray(FactArray r);

#endif