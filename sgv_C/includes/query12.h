/**
@file queries.h
\brief Módulo Auxiliar à realização das query 12.
*/
#ifndef QUERY12_H
#define QUERY12_H

#include "auxQuery12.h"
#include "queries.h"

/**
 * Query 12
@brief Dado um código de cliente determinar quais os códigos dos N produtos em que
mais gastou dinheiro durante o ano.
*/

void adicionaCodigoDinheiroCliente(VendaFilial vf, MyArrayDinheiro arr);

void nProdutosMaisCompradosCliente(char* cliente, int n, Filial f1, Filial f2, Filial f3);

#endif