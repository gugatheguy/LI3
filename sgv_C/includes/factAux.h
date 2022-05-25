/**
@file factAux.h
\brief Módulo Auxiliar ao tratamento de uma Fatura Individual.
*/
#ifndef FACTAUX_H
#define FACTAUX_H

#include "glibWarningAvoid.h"

/**
\brief Estrutura de Dados que representa os Valores de Faturação de um determinado Produto.
*/
typedef struct factVal* FactVal;

/**
\brief Estrutura de Dados que guarda todas as Vendas de um Produto.
*/
typedef GArray* VendasFact;

/**
@brief Obtém Cópia dos Valores de Faturação de um Produto.
@param f Valores de Faturação do Produto.
@return Cópia resultante.
*/
FactVal clonaFactVal(FactVal f);

/**
@brief Cria um FactVal a partir dos seus parâmetros.
@param p Preço.
@param q Quantidade.
@param c Modo de Compra.
@param m Mês.
@param f Filial.
@return FactVal resultante.
*/
FactVal criaFactVal(double p, int q, char c, int m, int f);

/**
@brief Liberta o FactVal.
@param f FactVal a ser destruído.
*/
void eliminaFactVal(FactVal f);

/**
@brief Retorna o Preço de um FactVal.
@param f FactVal.
@return Preço do FactVal.
*/
double getPrecoFactVal(FactVal f);

/**
@brief Retorna a Quantidade de um Produto de um FactVal.
@param f FactVal.
@return Quantidade Vendida.
*/
int getQuantidadeFactVal(FactVal f);

/**
@brief Retorna o Modo de Compra de um FactVal.
@param f FactVal.
@return Cópia do Modo de Compra de um FactVal.
*/
char getPromoFactVal(FactVal f);

/**
@brief Retorna o Mês de um FactVal.
@param f FactVal.
@return Mês de um FactVal.
*/
int getMesFactVal(FactVal f);

/**
@brief Retorna a Filial de um FactVal.
@param f FactVal.
@return Filial de um FactVal.
*/
int getFilialFactVal(FactVal f);

/**
@brief Obtém Cópia de um FactVal.
@param f FactVal.
@return Cópia de um FactVal resultante.
*/
FactVal copiaFactVal(FactVal f);

/**
@brief Iniciliza um VendasFact (GArray).
@return Struct VendasFact com memória alocada.
*/
VendasFact criaVendasFact();

/**
@brief Adiciona um FactVal ao VendasFact (GArray).
@param v VendasFact.
@param f FactVal.
@return VendasFact (GArray) resultante.	
*/
VendasFact adicionaFactVal(VendasFact v, FactVal f);


/**
@brief Tamanho do VendasFact (GArray).
@param v VendasFact
@return Tamanho do VendasFact (GArray).
*/
int getSizeVendasFact(VendasFact v);

/**
@brief Obtém um FactVal existente no VendasFact (GArray) a partir do índice onde se encontra.
@param v VendasFact.
@param index Índice onde se encontra o FactVal.
@return FactVal resultante.
*/
FactVal getFactVal(VendasFact v, int index);

/**
@brief Liberta o VendasFact (GArray).
@param v VendasFact a ser destruído.
*/
void eliminaVendasFact(VendasFact v);

#endif