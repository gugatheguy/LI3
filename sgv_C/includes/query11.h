/**
@file queries.h
\brief Módulo Auxiliar à realização das query 11.
*/
#ifndef QUERY11_H
#define QUERY11_H

#include "auxQuery11.h"
#include "queries.h"

/**
 * Query 11
@brief Criar uma lista dos N produtos mais vendidos em todo o ano, indicando o
número total de clientes e o número de unidades vendidas, filial a filial.
*/
void adicionaCodigoQuantidadeClienteVendaFilial(VendaFilial vf, MyArrayQuantidadeCliente arr);

void nProdutosMaisVendidosFilial(int n,Filial f);

void nProdutosMaisVendidos(int n,Filial f1,Filial f2,Filial f3);

#endif 