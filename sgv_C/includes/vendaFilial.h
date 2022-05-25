/**
@file vendaFilial.h
\brief Módulo de tratamento do Histórico de Compras associado a um cliente.
*/
#ifndef VENDAFILIAL_H
#define VENDAFILIAL_H

#include "auxFilial.h"

/**
\brief Struct para representar todo Histórico de Compras relacionado com um Cliente.
*/
typedef struct vendaFilial* VendaFilial;

/**
@brief Imprime no ecrã toda a informação das Compras relacionadas com um Cliente assim como o próprio.
@param vf Histórico de Compras dado.
*/
void printaVendaFilial(VendaFilial vf);

/**
@brief Cria um Histórico de Compras a partir do Código do Cliente, com o GArray inicialmente vazio.
@param prod Código do Produto.
@return Histórico de Compras do Cliente dado.
*/
VendaFilial criaVendaFilial(char* codigo);

/**
@brief Adiciona um ProdutoFilial de um Cliente.
@param vf Histórico de Compras de um Cliente
@param pf ProdutoFilial
@return Histórico de Compras resultante.
*/
VendaFilial adicionaProdutosFilial(VendaFilial vf, ProdutoFilial pf);

/**
@brief Obter Cópia do Código de Cliente a partir de um Histórico de Compras.
@param vf Histórico de Compras.
@return Cópia do Código do Cliente. 
*/
char* getClienteFilial(VendaFilial vf);

/** 
@brief Obtém uma cópia do GArray.
@param pf Histórico de Compras.
@return Cópia do GArray do Histórico de Compras dado.
*/
ProdutosFilial getProdutosFilial(VendaFilial vf);

/**
@brief Tamanho do GArray de um Histórico de Compras.
@param pf Histórico de Compras.
@return Tamanho do GArray.
*/
int getSizeVendaFilial(VendaFilial vf);

/**
@brief Destrói um Histórico de Compras.
@param pf Histórico de Compras a libertar.
*/
void eliminaVendaFilial(VendaFilial vf);

/**
@brief Obter Cópia de um Histórico de Compras.
@param pf Histórico de Compras.
@return Cópia do Histórico de Compras.
*/
VendaFilial clonaVendaFilial(VendaFilial vf);

/**
@brief Adiciona no final do ProdutosFilial da VendaFilial um ProdutoFilial.
@param vf VendaFilial.
@param pf ProdutoFilial.
*/
void appendProdutosFilial(VendaFilial vf, ProdutoFilial pf);

/**
@brief Adiciona o ProdutosFilial de um Histórico de Compras o outro.
@param vf1 VendaFilial a ser modificado. 
@param vf2 VendaFilial.
*/
void appendVendaFilial(VendaFilial vf1, VendaFilial vf2);

#endif