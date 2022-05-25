/**
@file auxFilial.h
\brief Módulo Auxiliar ao tratamento das Compras associadas a um cliente.
*/
#ifndef VENDAFILIALAUX_H
#define VENDAFILIALAUX_H

#include <string.h>
#include "glibWarningAvoid.h"

/**
\brief Estrutura de Dados que representa as Compras de um determinado Cliente.
*/
typedef struct produtoFilial* ProdutoFilial;

/**
\brief Estrutura de Dados que guarda todas as Compras de um Produto.
*/
typedef GArray* ProdutosFilial;

/**
@brief Imprime no ecrã toda a informação das Compras.
@param p Compras dada.
*/
void printaProdutoFilial(ProdutosFilial p);

/**
@brief Obtém Cópia dos Valores das Compras de um Cliente.
@param pf Valores das Compras do Cliente.
@return Cópia resultante.
*/
ProdutoFilial clonaProdutoFilial(ProdutoFilial pf);

/**
@brief Cria um ProdutoFilial a partir dos seus parâmetros.
@param produto Produto.
@param preco Preço.
@param qt Quantidade.
@param pr Modo de Compra.
@param mes Mês.
@return ProdutoFilial resultante.
*/
ProdutoFilial criaProdutoFilial(char* produto, double preco, int qt, char pr, int mes);

/**
@brief Liberta o ProdutoFilial.
@param pf ProdutoFilial a ser destruído.
*/
void eliminaProdutoFilial(ProdutoFilial pf);

/**
@brief Retorna o Produto de um ProdutoFilial.
@param pf ProdutoFilial.
@return Produto de um ProdutoFilial.
*/
char* getProdutoProdutoFilial(ProdutoFilial pf);

/**
@brief Retorna o Preço de um ProdutoFilial.
@param pf ProdutoFilial.
@return Preço do ProdutoFilial.
*/
double getPrecoProdutoFilial(ProdutoFilial pf);

/**
@brief Retorna a Quantidade de um Produto de um ProdutoFilial.
@param pf ProdutoFilial.
@return Quantidade Vendida.
*/
int getQuantidadeProdutoFilial(ProdutoFilial pf);

/**
@brief Retorna o Modo de Compra de um ProdutoFilial.
@param pf ProdutoFilial.
@return Cópia do Modo de Compra de um ProdutoFilial.
*/
char getPromoProdutoFilial(ProdutoFilial pf);

/**
@brief Retorna o Mês de um ProdutoFilial.
@param pf ProdutoFilial.
@return Mês de um ProdutoFilial.
*/
int getMesProdutoFilial(ProdutoFilial pf);

/**
@brief Obtém Cópia de um ProdutoFilial.
@param pf ProdutoFilial.
@return Cópia de um ProdutoFilial resultante.
*/
ProdutoFilial copiaProdutoFilial(ProdutoFilial pf);

/**
@brief Iniciliza um ProdutosFilial (GArray).
@return Struct ProdutosFilial com memória alocada.
*/
ProdutosFilial criaProdutosFilial();

/**
@brief Adiciona um ProdutoFilial ao ProdutosFilial (GArray).
@param pfs ProdutosFilial.
@param pf ProdutoFilial.
@return VendasFact (GArray) resultante.	
*/
ProdutosFilial adicionaProdutoFilial(ProdutosFilial pfs, ProdutoFilial pf);

/**
@brief Tamanho do ProdutosFilial (GArray).
@param pfs ProdutosFilial
@return Tamanho do ProdutosFilial (GArray).
*/
int getSizeProdutosFilial(ProdutosFilial pfs);

/**
@brief Obtém um ProdutoFilial existente no ProdutosFilial (GArray) a partir do índice onde se encontra.
@param pfs ProdutosFilial.
@param index Índice onde se encontra o FactVal.
@return ProdutoFilial resultante.
*/
ProdutoFilial getProdutoFilial(ProdutosFilial pfs, int index);

/**
@brief Liberta o ProdutosFilial (GArray).
@param pfs ProdutosFilial a ser destruído.
*/
void eliminaProdutosFilial(ProdutosFilial pfs);

#endif