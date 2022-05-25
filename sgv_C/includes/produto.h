/**
@file produto.h
\brief Módulo de tratamento de Produto individual.
*/
#ifndef PRODUTO_H
#define PRODUTO_H

#include <string.h>
#include <stdlib.h>

/**
@brief Struct para representar a informação de um Produto.
*/
typedef struct produto* Produto;

/**
@brief Verifica se uma string representa um Produto valido.
@param codigo String a verificar.
@return int se é válido ou não.
*/
int verificaProduto(char* codigo);

/**
@brief Destroi um Produto.
@param prod Produto a libertar.
*/
void eliminaProduto (Produto prod);

/**
@brief Cria uma Struct de Produto com base numa String.
@param codigo String a converter.
@return Produto struct que representa o Produto dado.
*/
Produto criaProduto(char* codigo);

/**
@brief Obter Cópia do Código de Produto.
@param prod Produto a procurar.
@return Cópia do Código do Produto. 
*/
char* getCodigoProduto(Produto prod);


#endif