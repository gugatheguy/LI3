/**
@file auxQuery12.h
\brief Módulo Auxiliar à realização da query 12.
*/
#ifndef AUXQUERY12_H
#define AUXQUERY12_H

#include <string.h>

/**
\brief Estrutura de Dados que representa um Produto e o seu Custo(Dinheiro).
*/
typedef struct codigoDinheiro* CodigoDinheiro;

/**
\brief Estrutura de Dados que guarda todos CodigoDinheiro.
*/
typedef struct myArrayDinheiro* MyArrayDinheiro;

/**
@brief Imprime no ecrã toda a informação do CodigoDinheiro.
@param aux CodigoDinheiro.
*/
void printaCodigoDinheiro(CodigoDinheiro aux);

/**
@brief Liberta o CodigoDinheiro.
@param cl CodigoDinheiro a ser destruído.
*/
void eliminaCodigoDinheiro (CodigoDinheiro cl);

/**
@brief Cria um CodigoDinheiro a partir dos seus parâmetros.
@param cod Produto.
@param money Custo.
@return CodigoDinheiro resultante.
*/
CodigoDinheiro criaCodigoDinheiro(char* cod,double money);

/**
@brief Retorna o Produto de um CodigoDinheiro.
@param cl CodigoDinheiro.
@return Produto de um CodigoDinheiro.
*/
char* getCodigoCodigoDinheiro(CodigoDinheiro cl);

/**
@brief Retorna o Custo de um CodigoDinheiro.
@param cl CodigoDinheiro.
@return Custo de um CodigoDinheiro.
*/
double getDinheiroCodigoDinheiro(CodigoDinheiro cl);

/**
@brief Iniciliza um ArrayDinheiro (Array).
@return Struct ArrayDinheiro com memória alocada.
*/
MyArrayDinheiro criaMyArrayDinheiro();

/**
@brief Tamanho do ArrayDinheiro (Array).
@param r ArrayDinheiro.
@return Tamanho do ArrayDinheiro (Array).
*/
int getSizeMyArrayDinheiro(MyArrayDinheiro r);

/**
@brief Adiciona um CodigoDinheiro ao ArrayDinheiro (Array).
@param r ArrayDinheiro.
@param c CodigoDinheiro.
@return ArrayDinheiro (GArray) resultante.	
*/
MyArrayDinheiro adicionaCodigoDinheiro(MyArrayDinheiro r, CodigoDinheiro c);

/**
@brief Obtém um CodigoDinheiro existente no ArrayDinheiro (Array) a partir do índice onde se encontra.
@param r ArrayDinheiro.
@param idx Índice onde se encontra o CodigoDinheiro.
@return CodigoDinheiro resultante.
*/
CodigoDinheiro getCodigoDinheiro(MyArrayDinheiro r, int idx);

/**
@brief Liberta o ArrayDinheiro (Array).
@param r ArrayDinheiro a ser destruído.
*/
void qSortMyArrayCodigoDinheiro(MyArrayDinheiro array);

/**
@brief Organiza o ArrayDinheiro (Array) por ordem Alfabética dos códigos dos produtos dos CodigoDinheiro.
@param r ArrayDinheiro a ser organizado.
*/
void qSortMyArrayDinheiro(MyArrayDinheiro array);

/**
@brief Organiza o ArrayDinheiro (Array) por ordem Descrescente do custo dos CodigoDinheiro.
@param r ArrayDinheiro a ser organizado.
*/
void eliminaMyArrayDinheiro(MyArrayDinheiro r);

/**
@brief Percorre o ArrayDinheiro (Array) sumando os custos dos CodigoDinheiro com códigos de produto iguais removendo o duplicado.
@param r ArrayDinheiro a ser refeito.
@return ArrayDinheiro refeito.
*/
MyArrayDinheiro removeRepetidosMyArrayDinheiro(MyArrayDinheiro array);

#endif