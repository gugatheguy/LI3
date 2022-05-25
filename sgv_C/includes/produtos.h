/**
@file produtos.h
\brief Módulo de Tratemento de Produtos.
*/
#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "produto.h"
#include "auxStructs.h"

/**
\brief Estrutura de Produtos Lidos.
*/
typedef struct produtos* Produtos;

/**
@brief Inicializar o Catálogo de Produtos.
@return Struct Produtos com memória alocada.
*/
Produtos criaProdutos();

/**
@brief Liberta todo o Catálogo de Produtos.
@param cat Catálogo a ser destruído.
*/
void eliminaProdutos(Produtos cat);

/**
@brief Carrega o Catálogo de Produtos através de um Ficheiro.
@param cat Catálogo onde se vai adicionar.
@param filename Directoria do ficheiro.
@return Catálogo Editado.
*/
Produtos carregaCatalogoProdutos(Produtos cat, char* filename);

/**
@brief Adicionar um Produtos.
@param cat Catálogo onde se vai adicionar.
@param prod Código de Produto a adicionar.
@return Catálogo Editado.
*/
void adicionaProduto(Produtos cat, Produto prod);

/**
@brief Verfica se existe um Produto no Catálogo.
@param cat Catálogo de Produtos.
@param str Código de Produto.
@return Retorna 1 no caso de existir, 0 caso contrário.
*/
int existeProduto(Produtos cat, char* str);

/**
@brief Número total de Produtos do Catálogo.
@param cat Catálogo de Produtos.
@return Número total.
*/
int getSizeProdutos (Produtos cat);

/**
@brief Coloca todos os Códigos do Produto num StringArray (GArray)
@param cat Catálogo de Produtos.
@return StringArray resultante.
*/
StringArray getCodigosProdutos(Produtos cat);

/**
@brief Número total de Produtos lidos a partir do Ficheiro.
@þaram cat Catálogo de Produtos.
@return Número Total.
*/
int getProdutosLidos(Produtos cat);

#endif