/**
@file auxQuery10.h
\brief Módulo Auxiliar à realização da query 10.
*/
#ifndef AUXQUERY10_H
#define AUXQUERY10_H

#include <string.h>

/**
\brief Estrutura de Dados que representa um Produto e a sua Quantidade.
*/
typedef struct codigoQuantidade* CodigoQuantidade;

/**
\brief Estrutura de Dados que guarda todos CodigoQuantidade.
*/
typedef struct myArrayQuantidade* MyArrayQuantidade;

/**
@brief Imprime no ecrã toda a informação do CodigoQuantidade.
@param aux CodigoQuantidade.
*/
void printaCodigoQuantidade(CodigoQuantidade aux);

/**
@brief Liberta o CodigoQuantidade.
@param cl CodigoQuantidade a ser destruído.
*/
void eliminaCodigoQuantidade (CodigoQuantidade cl);

/**
@brief Cria um CodigoQuantidade a partir dos seus parâmetros.
@param cod Produto.
@param quant Quantidade.
@return CodigoQuantidade resultante.
*/
CodigoQuantidade criaCodigoQuantidade(char* cod,int quant);

/**
@brief Retorna o Produto de um CodigoQuantidade.
@param cl CodigoQuantidade.
@return Produto de um CodigoQuantidade.
*/
char* getCodigoCodigoQuantidade(CodigoQuantidade cl);

/**
@brief Retorna a Quantidade de um CodigoQuantidade.
@param cl CodigoQuantidade.
@return Quantidade de um CodigoQuantidade.
*/
int getQuantidadeCodigoQuantidade(CodigoQuantidade cl);

/**
@brief Iniciliza um ArrayQuantidade (Array).
@return Struct ArrayQuantidade com memória alocada.
*/
MyArrayQuantidade criaMyArrayQuantidade();

/**
@brief Tamanho do ArrayQuantidade (Array).
@param r ArrayQuantidade.
@return Tamanho do ArrayQuantidade (Array).
*/
int getSizeMyArrayQuantidade(MyArrayQuantidade r);

/**
@brief Adiciona um CodigoQuantidade ao ArrayQuantidade (Array).
@param r ArrayQuantidade.
@param c CodigoQuantidade.
@return ArrayQuantidade (GArray) resultante.	
*/
MyArrayQuantidade adicionaCodigoQuantidade(MyArrayQuantidade r, CodigoQuantidade c);

/**
@brief Obtém um CodigoQuantidade existente no ArrayQuantidade (Array) a partir do índice onde se encontra.
@param r ArrayQuantidade.
@param idx Índice onde se encontra o CodigoQuantidade.
@return CodigoQuantidade resultante.
*/
CodigoQuantidade getCodigoQuantidade(MyArrayQuantidade r, int idx);

/**
@brief Liberta o ArrayQuantidade (Array).
@param r ArrayQuantidade a ser destruído.
*/
void eliminaMyArrayQuantidade(MyArrayQuantidade r);

/**
@brief Organiza o ArrayQuantidade (Array) por ordem Alfabética dos códigos dos produtos dos CodigoQuantidade.
@param r ArrayQuantidade a ser organizado.
*/
void qSortMyArrayCodigo(MyArrayQuantidade array);

/**
@brief Organiza o ArrayQuantidade (Array) por ordem Descrescente da quantidade dos CodigoQuantidade.
@param r ArrayQuantidade a ser organizado.
*/
void qSortMyArrayQuantidade(MyArrayQuantidade array);

/**
@brief Percorre o ArrayQuantidade (Array) sumando as quantidades dos CodigoQuantidade com códigos de produto iguais removendo o duplicado.
@param r ArrayQuantidade a ser refeito.
@return ArrayQuantidade refeito.
*/
MyArrayQuantidade removeRepetidosMyArrayQuantidade(MyArrayQuantidade array);

#endif