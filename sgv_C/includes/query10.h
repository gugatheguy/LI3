/**
@file queries.h
\brief Módulo Auxiliar à realização das query 10.
*/
#ifndef QUERY10_H
#define QUERY10_H

#include "auxQuery10.h"
#include "queries.h"

/**
 * Query 10
@brief Dado um código de cliente e um mês, determinar a lista de códigos de
produtos que mais comprou por quantidade e não por faturação), por ordem
descendente.
*/
void adicionaCodigoQuantidadeClienteMes(int mes,VendaFilial vf, MyArrayQuantidade arr);

void produtosMaisCompradosClienteMes(char* cliente,int mes,Filial f1,Filial f2,Filial f3);

#endif 