/**
@file filial.h
\brief Módulo de tratamento de Históricos de Compras.
*/
#ifndef FILIAL_H
#define FILIAL_H

#include "auxStructs.h"
#include "auxStructsVendaFilial.h"

/**
\brief Estrutura que contém todos os Históricos de Compras.
*/
typedef struct filial* Filial;

/**
@brief Inicializar o Catálogo de Históricos de Compras.
@return Struct Filial com memória alocada.
*/
Filial criaFilial();

/**
@brief Transforma um StringArray (GArray) num Catálogo de Históricos de Compras.
@param s StringArray.
@param cat Catálogo de Históricos de Compras.
*/
void stringArrayToFilial(StringArray s,Filial f1, Filial f2, Filial f3);

/**
@brief Verifica se existe um Histórico de Compras no Catálogo através do seu Código do Cliente.
@param f Cátalogo dos Históricos de Compras.
@param str Código do Cliente.
@return Retorna 1 no caso de existir, 0 caso contrário.
*/
int existeVendaFilial(Filial f, char* str);

/**
@brief Liberta todo o Catálogo de Históricos de Compras.
@param f Catálogo a ser destruído.
*/
void eliminaFilial(Filial f);

/**
@brief Adicionar um Histórico de Compras.
@param f Catálogo onde se vai adicionar.
@param vf Histórico de Compras a adicionar.
*/
void adicionaVendaFilial(Filial f, VendaFilial vf);

/**
@brief Retorna uma Cópia do Histórico de Compras do Código de Cliente dado.
@param f Catálogo de Histórico de Compras.
@param str Código do Cliente.
@return Cópia do Histórico de Compras.
*/
VendaFilial getVendaFilial(Filial f, char* str);

/**
@brief Coloca todo o Catálogo do Histórico de Compras num VendaFilialArray (GArray).
@param f Catálogo do Histórico de Compras.
@return VendaFilialArray (GArray) resultante.
*/
VendaFilialArray getVendasFilial(Filial f);

/**
@brief Insere um Histórico de Compras no Catálogo.
@param f Catálogo de Faturas.
@param vf Histórico de Compras.
*/
void insereVendaFilial(Filial f,VendaFilial vf);

/**
@brief Número total de Histórico de Compras do Catálogo.
@param f Catálogo de Faturas.
@return Número total.
*/
int getSizeFilial(Filial f);

#endif