/**
@file clientes.h
\brief Módulo de tratamento de clientes.
*/
#ifndef CLIENTES_H
#define CLIENTES_H

#include "cliente.h" 
#include "auxStructs.h"

/**
\brief Estrutura de Clientes Lidos.
*/
typedef struct clientes* Clientes;

/**
@brief Inicializar o Catálogo de Clientes.
@return Struct Clientes com memória alocada.
*/
Clientes criaClientes();

/**
@brief Liberta todo o Catálogo de Clientes.
@param cat Catálogo a ser destruído.
*/
void eliminaClientes(Clientes cat);

/**
@brief Carrega o Catálogo de Clientes através de um Ficheiro.
@param cat Catálogo onde se vai adicionar.
@param filename Directoria do ficheiro.
@return Catálogo Editado.
*/
Clientes carregaCatalogoClientes(Clientes cat, char* filename);

/**
@brief Adicionar um Cliente.
@param cat Catálogo onde se vai adicionar.
@param cl Código de Cliente a Adicionar.
@return Catálogo Editado.
*/
void adicionaCliente(Clientes cat, Cliente cl);

/**
@brief Verfica se existe um Cliente no Catálogo
@param cat Catálogo de Clientes.
@param str Código de Cliente.
@return Retorna 1 no caso de existir, 0 caso contrário.
*/
int existeCliente(Clientes cat, char* str);

/**
@brief Número total de Clientes do Catálogo.
@param cat Catálogo de Clientes.
@return Número total.
*/
int getSizeClientes (Clientes cat);


/**
@brief Coloca todos os Códigos de Cliente num StringArray (GArray)
@param cat Catálogo de Clientes.
@return StringArray resultante.
*/
StringArray getCodigosClientes(Clientes cat);


/**
@brief Número total de Clientes lidos a partir do Ficheiro.
@þaram cat Catálogo de Clientes.
@return Número Total.
*/
int getClientesLidos(Clientes cat);

#endif
