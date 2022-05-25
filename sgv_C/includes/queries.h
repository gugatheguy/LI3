/**
@file queries.h
\brief Módulo Auxiliar à realização das queries.
*/
#ifndef QUERIES_H
#define QUERIES_H

#include "produtos.h"
#include "factTotal.h"
#include "auxStructs.h"
#include "filial.h"
#include "glibWarningAvoid.h"

/**
 * Query 2
@brief Determinar a lista e o no total de produtos cujo código se inicia por uma dada
letra (maiúscula).
*/
void getProdutosComLetra(char l,Produtos cat);

/**
 * Query 3
@brief Dado um mês e um código de produto, ambos válidos, determinar e apresentar
o número total de vendas (no de registos de venda) e o total facturado com
esse produto em tal mês, distinguindo os totais em modo N e os totais em
modo P. O utilizador deverá decidir se pretende o resultado global ou os
resultados filial a filial para todas as 3 filiais.
*/
void vendasProdutoMesGlobal(FactTotal cat, char * prod, int mes);

/**
 * Query 4
@brief Determinar a lista ordenada dos códigos dos produtos (e o seu número total)
que ninguém comprou, podendo o utilizador decidir igualmente se pretende
valores totais ou divididos pelas filiais.
*/
void getProdutosNaoComprados(FactTotal cat);

void produtoCompradoFiliais(Fact f,int r[]);

void getProdutosNaoCompradosPorFilial(FactTotal cat);

/**
 * Query 6
@brief Determinar o número de clientes registados que não realizaram compras bem
como o número de produtos que ninguém comprou.
*/
void getClientesQueNaoCompram(Filial f1,Filial f2,Filial f3);

void getClientesEProdutosNaoComprados(FactTotal ft,Filial f1,Filial f2,Filial f3);

/**
 * Query 8
@brief Dado um intervalo fechado de meses, por exemplo [1..3], determinar o total de
vendas (no de registos de venda) registadas nesse intervalo e o total faturado.
*/
void factEntreMeses(FactTotal cat, int ini, int fim);

/**
 * Query 5
@brief Determinar a lista ordenada de códigos de clientes que realizaram compras em
todas as filiais.
*/
void clientesTodasFiliais(Filial f1,Filial f2,Filial f3);

/**
 * Query 9
@brief Dado um código de produto e uma filial, determinar os códigos (e número total)
dos clientes que o compraram, distinguindo entre compra N e compra P.
*/
int modoProdutoVendaFilial(char* prod, VendaFilial vf);

StringArray clientesQueCompraramFilialAux(char* prod, Filial f,int modo[]);

void clientesQueCompraramProdutoFilial(int i, char* prod, Filial f1, Filial f2,Filial f3);

/**
 * Query 7
@brief Dado um código de cliente, criar uma tabela com o número total de produtos
comprados (ou seja a soma das quantidades de todas as vendas do produto),
mês a mês (para meses em que não comprou a entrada deverá ficar a 0). A
tabela deverá ser apresentada em ecrã organizada por filial.
*/

void totalProdutosCompradosPorMes(char* cliente, Filial f1, Filial f2, Filial f3);

void totalProdutosCompradosPorMesAux(VendaFilial vf, int mes[]);

#endif