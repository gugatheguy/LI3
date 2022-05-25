/**
@file fact.h
\brief Módulo de tratamento de Fatura individual.
*/
#ifndef FACT_H
#define FACT_H

#include <string.h>
#include <stdlib.h>
#include "factAux.h"

/**
\brief Struct para representar todas as Faturas relacionadas com um Produto.
*/
typedef struct fact* Fact;

/**
@brief Imprime no ecrã toda a informação de uma Fatura.
@param f Fatura dada.
*/
void printaFact(Fact f);

/**
@brief Cria uma Fatura a partir do Código do Produto, com o GArray inicialmente vazio.
@param prod Código do Produto.
@return Fatura do Produto dado.
*/
Fact criaFact(char* prod);

/**
@brief Adiciona um FactVal de um Produto.
@param cat Fatura de um Produto
@param f FactVal
@return Fatura resultante.
*/
Fact adicionaVendaVal(Fact cat, FactVal f);

/** 
@brief Obtém uma cópia do GArray.
@param f Fatura.
@return Cópia do GArray da Fatura dada.
*/
VendasFact getVendasFact(Fact f);

/**
@brief Tamanho do GArray de uma Fatura.
@param f Fatura.
@return Tamanho do GArray.
*/
int getSizeFact(Fact f);

/**
@brief Destrói uma Fatura.
@param f Fatura a libertar.
*/
void eliminaFact(Fact f);

/**
@brief Obter Cópia do Código de Produto a partir de uma Fatura.
@param f Fatura.
@return Cópia do Código do Produto. 
*/
char * getProdutoFact(Fact f);

/**
@brief Obter Cópia de uma Fatura.
@param f Fatura.
@return Cópia da Fatura.
*/
Fact clonaFact(Fact f);

/**
@brief Adiciona no final do VendasFact do Fact um FactVal.
@param r Fact.
@param f FactVal.
*/
void appendFactVal(Fact r, FactVal f);

/**
@brief Adiciona o VendasFact de uma Fatura a outra.
@param r Fact a ser modificado. 
@param f Fact.
*/
void appendFact(Fact r, Fact f);

#endif