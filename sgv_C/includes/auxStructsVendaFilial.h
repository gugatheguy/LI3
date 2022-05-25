/**
@file auxStructsVendaFilial.h
\brief Módulo Auxiliar à Filial para o seu encapsulamento.
*/
#ifndef AUXSTRUCTSVENDAFILIAL_H
#define AUXSTRUCTSVENDAFILIAL_H 

#include<stdio.h>
#include<stdlib.h>
#include "vendaFilial.h"

/**
\brief Estrutura de Dados que guarda VendaFilials.
*/
typedef GArray* VendaFilialArray;

/**
@brief Iniciliza um VendaFilialArray (GArray).
@return Struct VendaFilialArray com memória alocada.
*/
VendaFilialArray criaVendaFilialArray();

/**
@brief Adiciona uma VendaFilial ao VendaFilialArray (GArray).
@param r VendaFilialArray.
@param value gpointer(VendaFilial).
@return VendaFilialArray (GArray) resultante.	
*/
VendaFilialArray adicionaVendaFilialArray(VendaFilialArray r, gpointer value);

/**
@brief Tamanho do VendaFilialArray (GArray).
@param r VendaFilialArray.
@return Tamanho do VendaFilialArray (GArray).
*/
int getSizeVendaFilialArray(VendaFilialArray r);

/**
@brief Obtém uma VendaFilial existente no VendaFilialArray (GArray) a partir do índice onde se encontra.
@param r VendaFilialArray.
@param idx Índice onde se encontra a VendaFilial.
@return VendaFilial resultante.
*/
VendaFilial getVendaFilialArray(VendaFilialArray r, int idx);

/**
@brief Liberta o ArrayVendaFilial (GArray).
@param r VendaFilialArray a ser destruído.
*/
void eliminaVendaFilialArray(VendaFilialArray r);

#endif