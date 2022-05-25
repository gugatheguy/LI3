/**
@file auxQuery11.h
\brief Módulo Auxiliar à realização da query 11.
*/
#ifndef AUXQUERY11_H
#define AUXQUERY11_H

#include <string.h>

/**
\brief Estrutura de Dados que representa um Produto, a sua Quantidade e o número de clientes que compraram o produto.
*/
typedef struct codigoQuantidadeCliente* CodigoQuantidadeCliente;

/**
\brief Estrutura de Dados que guarda todos CodigoQuantidadeCliente.
*/
typedef struct myArrayQuantidadeCliente* MyArrayQuantidadeCliente;

/**
@brief Imprime no ecrã toda a informação do CodigoQuantidadeCliente.
@param aux CodigoQuantidadeCliente.
*/
void printaCodigoQuantidadeCliente(CodigoQuantidadeCliente aux);

/**
@brief Liberta o CodigoQuantidadeCliente.
@param cl CodigoQuantidadeCliente a ser destruído.
*/
void eliminaCodigoQuantidadeCliente (CodigoQuantidadeCliente cl);

/**
@brief Cria um CodigoQuantidadeCliente a partir dos seus parâmetros.
@param cod Produto.
@param quant Quantidade.
@return CodigoQuantidadeCliente resultante.
*/
CodigoQuantidadeCliente criaCodigoQuantidadeCliente(char* cod,int quant);

/**
@brief Cria um CodigoQuantidadeCliente a partir dos seus parâmetros.
@param cod Produto.
@param quant Quantidade.
@param buyers Número de Clientes que compraram o produto.
@return CodigoQuantidadeCliente resultante.
*/
CodigoQuantidadeCliente criaCodigoQuantidadeMaisDeUmCliente(char* cod,int quant,int buyers);

/**
@brief Retorna o Produto de um CodigoQuantidadeCliente.
@param cl CodigoQuantidade.
@return Produto de um CodigoQuantidadeCliente.
*/
char* getCodigoCodigoQuantidadeCliente(CodigoQuantidadeCliente cl);

/**
@brief Retorna a Quantidade de um CodigoQuantidadeCliente.
@param cl CodigoQuantidadeCliente.
@return Quantidade de um CodigoQuantidadeCliente.
*/
int getQuantidadeCodigoQuantidadeCliente(CodigoQuantidadeCliente cl);

/**
@brief Iniciliza um ArrayQuantidadeCliente (Array).
@return Struct ArrayQuantidadeCliente com memória alocada.
*/
MyArrayQuantidadeCliente criaMyArrayQuantidadeCliente();

/**
@brief Tamanho do ArrayQuantidadeCliente (Array).
@param r ArrayQuantidadeCliente.
@return Tamanho do ArrayQuantidadeCliente (Array).
*/
int getSizeMyArrayQuantidadeCliente(MyArrayQuantidadeCliente r);

/**
@brief Adiciona um CodigoQuantidadeCliente ao ArrayQuantidadeCliente (Array).
@param r ArrayQuantidadeCliente.
@param c CodigoQuantidadeCliente.
@return ArrayQuantidadeCliente (GArray) resultante.	
*/
MyArrayQuantidadeCliente adicionaCodigoQuantidadeCliente(MyArrayQuantidadeCliente r, CodigoQuantidadeCliente c);

/**
@brief Obtém um CodigoQuantidadeCliente existente no ArrayQuantidadeCliente (Array) a partir do índice onde se encontra.
@param r ArrayQuantidadeCliente.
@param idx Índice onde se encontra o CodigoQuantidadeCliente.
@return CodigoQuantidadeCliente resultante.
*/
CodigoQuantidadeCliente getCodigoQuantidadeCliente(MyArrayQuantidadeCliente r, int idx);

/**
@brief Liberta o ArrayQuantidadeCliente (Array).
@param r ArrayQuantidadeCliente a ser destruído.
*/
void eliminaMyArrayQuantidadeCliente(MyArrayQuantidadeCliente r);

/**
@brief Organiza o ArrayQuantidadeCliente (Array) por ordem Alfabética dos códigos dos produtos dos CodigoQuantidadeCliente.
@param r ArrayQuantidadeCliente a ser organizado.
*/
void qSortMyArrayCodigoCliente(MyArrayQuantidadeCliente array);

/**
@brief Organiza o ArrayQuantidadeCliente (Array) por ordem Descrescente da quantidade dos CodigoQuantidadeCliente.
@param r ArrayQuantidadeCliente a ser organizado.
*/
void qSortMyArrayQuantidadeCliente(MyArrayQuantidadeCliente array);

/**
@brief Percorre o ArrayQuantidadeCliente (Array) sumando as quantidades e o número de clientes dos CodigoQuantidadeCliente com códigos de produto iguais removendo o duplicado.
@param r ArrayQuantidadeCliente a ser refeito.
@return ArrayQuantidadeCliente refeito.
*/
MyArrayQuantidadeCliente removeRepetidosMyArrayQuantidadeCliente(MyArrayQuantidadeCliente array);

#endif 