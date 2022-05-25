/**
@file cliente.h
\brief Módulo de tratamento de Cliente individual.
*/
#ifndef CLIENTE_H
#define CLIENTE_H

#include <string.h>
#include <stdlib.h>

/**
@brief Struct para representar a informação de um Cliente.
*/
typedef struct cliente* Cliente;

/**
@brief Verifica se uma string representa um Ciente valido.
@param codigo String a verificar.
@return int se é válido ou não.
*/
int verificaCliente(char* codigo);

/**
@brief Destroi um Cliente.
@param cl Cliente a libertar.
*/
void eliminaCliente (Cliente cl);

/**
@brief Criar uma Struct de Cliente com base numa String.
@param codigo String a converter.
@return Cliente struct que representa o cliente dado.
*/
Cliente criaCliente(char* codigo);

/**
@brief Obter Cópia do Código de cliente.
@param cl Cliente a procurar.
@return Cópia do Código do Cliente. 
*/
char* getCodigoCliente(Cliente cl);

#endif