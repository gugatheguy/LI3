/**
@file factTotal.h
\brief Módulo de tratamento de Faturas.
*/
#ifndef FACTTOTAL_H
#define FACTTOTAL_H


#include "auxStructs.h"
#include "auxStructsFact.h"

/**
\brief Estrutura que contém todas as Faturas.
*/
typedef struct factTotal* FactTotal;

/**
@brief Inicializar o Catálogo de Faturas.
@return Struct FactTotal com memória alocada.
*/
FactTotal criaFactTotal();

/**
@brief Transforma um StringArray (GArray) num Catálogo de Faturas.
@param s StringArray.
@param cat Catálogo de Faturas.
*/
void stringArrayToFactTotal(StringArray s, FactTotal cat);

/**
@brief Verifica se existe uma Fatura no Catálogo através do seu Código do Produto.
@param cat Cátalogo das Faturas.
@param str Código do Produto.
@return Retorna 1 no caso de existir, 0 caso contrário.
*/
int existeFact(FactTotal cat, char* str);

/**
@brief Liberta todo o Catálogo de Faturas.
@param cat Catálogo a ser destruído.
*/
void eliminaFactTotal(FactTotal cat);

/**
@brief Adicionar uma Fatura.
@param cat Catálogo onde se vai adicionar.
@param prod Fatura a adicionar.
*/
void adicionaFact(FactTotal cat, Fact cl);

/**
@brief Número total de Faturas do Catálogo.
@param cat Catálogo de Faturas.
@return Número total.
*/
int getSizeFactTotal(FactTotal cat);

/**
@brief Retorna uma Cópia da Fatura do Código de Produto dado.
@param cat Catálogo de Faturas.
@param str Código do Produto.
@return Cópia da Fatura.
*/
Fact getFact(FactTotal cat, char * str);

/**
@brief Insere uma Fatura no Catálogo.
@param cat Catálogo de Faturas.
@param f Fatura.
*/
void insertFact(FactTotal cat, Fact f);

/**
@brief Coloca todo o Catálogo de Faturas num FactArray (GArray).
@param cat Catálogo de Faturas dado.
@return FactArray (GArray) resultante.
*/
FactArray getFacts(FactTotal cat);

/**
@brief Insirir o número total de Vendas lidas do ficheiro de vendas.
@param cat Catálogo de Faturas dado.
@param num número total lido das Vendas.
*/
void setVendasLidas(FactTotal cat, int num);

/**
@brief Insirir o número total de Vendas válidas do ficheiro de vendas.
@param cat Catálogo de Faturas dado.
@param num número total lido das Vendas.
*/
void setVendasValidas(FactTotal cat, int num);

/**
@brief Cálcula o número total de Vendas lidas do ficheiro de vendas.
@param cat Catálogo de Faturas dado.
@return o número total de Vendas lidas.
*/
int getVendasLidas(FactTotal cat);

/**
@brief Cálcula o número total de Vendas válidas do ficheiro de vendas.
@param cat Catálogo de Faturas dado.
@return o número total de Vendas válidas.
*/
int getVendasValidas(FactTotal cat);

#endif