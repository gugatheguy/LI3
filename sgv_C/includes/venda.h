/**
@file venda.h
\brief Módulo de Tratamento de Venda Individual.
*/
#ifndef VENDA_H
#define VENDA_H

#include <stdio.h>
#include "produtos.h"
#include "clientes.h" 
#include "factTotal.h"
#include "filial.h"

/**
\brief Estrutura para guardar uma Venda.
*/
typedef struct venda* Venda;

/**
@brief Cria uma Venda através de uma String.
@param cod String a converter.
@return Struct Venda que representa a Venda dada.
*/
Venda criaVenda(char ** cod);

/**
@brief Destrói uma Venda.
@param v Venda a libertar.
*/ 
void eliminaVenda (Venda v);

/**
@brief Verifica se uma Venda é válida.
@param cod String com a Venda.
@param catC Catálogo de Clientes.
@param catP Catálogo de Produtos.
@return 1 caso seja Verdadeira, 0 caso contrário. 
*/
int verificaVenda(char** cod, Clientes catC, Produtos catP);

/**
@brief Retorna uma Cópia do Código do Produto de uma Venda.
@param v Venda.
@return Cópia do Código do Produto
*/
char* getProdutoVenda(Venda v);

/**
@brief Retorna o Preço de uma Venda.
@param v Venda.
@return Preço da Venda.
*/
double getPrecoVenda(Venda v);

/**
@brief Retorna a Quantidade de Produto Vendida de uma Venda.
@param v Venda.
@return Quantidade Vendida.
*/
int getQuantidadeVenda(Venda v);

/**
@brief Retorna uma cópia do Modo de Compra de uma Venda.
@param v Venda.
@return Cópia do Modo de Compra da Venda.
*/
char getPromoVenda(Venda v);

/**
@brief Retorna uma Cópia do Código do Cliente de uma Venda.
@param v Venda.
@return Cópia do Código do Cliente da Venda.
*/
char* getClienteVenda(Venda v);

/**
@brief Retorna o mês onde se realizou a Venda.
@param v Venda.
@return Mês onde se realizou a Venda.
*/
int getMesVenda(Venda v);

/**
@brief Retorna a Filial onde se realizou a Venda.
@param v Venda.
@return Filial onde se realizou a Venda.
*/
int getFilialVenda(Venda v);

/**
@brief Cria uma Factura através de uma Venda.
@param v Venda.
@return Fatura a partir da Venda dada.
*/
Fact vendaToFact(Venda v);

/**
@brief Converte uma linha de Venda em VendaFilial.
@param v Linha de Venda.
@return VendaFilial resultante.
*/
VendaFilial vendaToVendaFilial(Venda v);

/**
@brief Carrega o Catálogo da Faturação Total e as 3 Filiais.
@param cat_clientes Catálogo de Clientes.
@param cat_produtos Catálogo de Produtos.
@param filename Diretoria do Ficheiro de Vendas.
@param cat Catálogo da Faturação Total.
@param f1 Filial 1.
@param f2 FIlial 2.
@param f3 Filial 3.
*/
void carregaFactTotalEFiliais(Clientes cat_clientes, Produtos cat_produtos, char* filename, FactTotal cat, Filial f1, Filial f2, Filial f3);

#endif