/**
@file sgv.h
@brief Módulo do SGV.
*/
#ifndef SGV_H
#define SGV_H

#include "filial.h"
#include "factTotal.h"
#include "venda.h"
#include "queries.h"
#include "query10.h"
#include "query11.h"
#include "query12.h"

/**
@brief Guardar a base de dados 
*/
typedef struct sgv* SGV;

/**
@brief Estrutura de Dados que contém todas as informações sobre os Ficheiros e leitura da Base de Dados (Query 1)
*/
typedef struct dadosLeitura* DadosLeitura;

/**
@brief Inicializar a base de dados
@return SGV Base de Dados inicializada
*/
SGV initSGV();

/**
@brief Libertar um SGV
@param sgv SGV a libertar
*/
void destroySGV(SGV sgv);

/**
@brief Carrega o SGV com toda a informação dos Ficheiros que é válida
@param sgv SGV.
@param clientsFilePath Caminho para o Ficheiro de Clientes.
@param productsFilePath Caminho para o Ficheiro de Produtos.
@param salesFilePath Caminho para o Ficheiro de Vendas.
@return SGV carregado.
*/
SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath);

/**
@brief Carrega o DadosLeitura com toda a informação necessária para a Query 13
@param sgv SGV.
@param d DadosLeitura a ser carregado.
*/
void carregaDadosIniciais(SGV sgv, DadosLeitura d);

/**
@brief Cria um DadosLeitura a partir dos caminhos de Ficheiros
@param fileC Caminho para o Ficheiro de Clientes.
@param fileP Caminho para o Ficheiro de Produtos.
@param fileV Caminho para o Ficheiro de Vendas.
@return DadosLeitura inicializado.
*/
DadosLeitura criaDadosIniciais(char* fileC, char* fileP, char* fileV);;

/**
@brief Libertar um DadoLeitura.
@param sgv DadoLeitura a libertar.
*/
void eliminaDadosIniciais(DadosLeitura d);

/**
@brief Insere o Tempo de Execução da Query 1 no DadosLeitura-
@param time Tempo de Execução-
@param d DadosLeitura.
*/
void setTempoExec(DadosLeitura d, double time);

/**
@brief Retorna o Tempo de Execução.
@param d DadosLeitura.
@return Tempo de Execução da Query 1.
*/
double getTempoExec(DadosLeitura d);

/**
@brief Retorna o Caminho do Ficheiro de Clientes.
@param d DadosLeitura.
@return Cópia do Caminho do Ficheiro de Clientes.
*/
char* getFileC(DadosLeitura d);

/**
@brief Retorna o número de linhas lidas do Ficheiro de Clientes.
@param d DadosLeitura.
@return Número de linhas lidas.
*/
int getClientesLidosDados(DadosLeitura d);
/**
@brief Retorna o número de linhas válidas do Ficheiro de Clientes.
@param d DadosLeitura.
@return Número de linhas válidas.
*/
int getClientesValidosDados(DadosLeitura d);

/**
@brief Retorna o Caminho do Ficheiro de Produtos.
@param d DadosLeitura.
@return Cópia do Caminho do Ficheiro de Produtos.
*/
char* getFileP(DadosLeitura d);

/**
@brief Retorna o número de linhas lidas do Ficheiro de Produtos.
@param d DadosLeitura.
@return Número de linhas lidas.
*/
int getProdutosLidosDados(DadosLeitura d);

/**
@brief Retorna o número de linhas válidas do Ficheiro de Produtos.
@param d DadosLeitura.
@return Número de linhas válidas.
*/
int getProdutosValidosDados(DadosLeitura d);

/**
@brief Retorna o Caminho do Ficheiro de Clientes.
@param d DadosLeitura.
@return Cópia do Caminho do Ficheiro de Clientes.
*/
char* getFileV(DadosLeitura d);

/**
@brief Retorna o número de linhas lidas do Ficheiro de Vendas.
@param d DadosLeitura.
@return Número de linhas lidas.
*/
int getVendasLidasDados(DadosLeitura d);

/**
@brief Retorna o número de linhas válidas do Ficheiro de Vendas.
@param d DadosLeitura.
@return Número de linhas válidas.
*/
int getVendasValidasDados(DadosLeitura d);

/**
@brief Função para ler e verificar se o mês inserido pelo Utilizador é válido.
@param topo Header para dar informação ao Utilizador sobre qual Query está a ser executada.
@return Mês resultante.
*/
int inputMesValido(char* topo);

/**
@brief Função para ler e verificar se o intervalo de meses inserido pelo Utilizador é válido.
@param topo Header para dar informação ao Utilizador sobre qual Query está a ser executada.
@param intervalo Intervalo de Tempo.
*/
void inputIntervaloValido(char* topo, int intervalo[]);

/*
char* inputClienteValido(SGV sgv, char* topo);

int existeClienteSGV(SGV sgv, char* cliente);

char * inputProdutoValido(SGV sgv, char* topo);

int existeProdutoSGV(SGV sgv, char* produto);
*/
/**
@brief Função para a Query 2.
*/
void getProductsStartedByLetter(SGV sgv, char letra);

/**
@brief Função para a Query 3.
*/
void getProductSalesAndProfit(SGV sgv, char* productID, int month);

/**
@brief Função para a Query 4.
*/
void getProductsNeverBought(SGV sgv, int branchID);

/**
@brief Função para a Query 5.
*/
void getClientsOfAllBranches(SGV sgv);

/**
@brief Função para a Query 6.
*/
void getClientsAndProductsNeverBoughtCount(SGV sgv);

/**
@brief Função para a Query 7.
*/
void getProductsBoughtByClient(SGV sgv, char* clientID);

/**
@brief Função para a Query 8.
*/
void getSalesAndProfit(SGV sgv, int minMonth, int maxMonth);

/**
@brief Função para a Query 9.
*/
void getProductBuyers(SGV sgv, char* productID, int branch);
/**
@brief Função para a Query 10.
*/
void getClientFavoriteProducts(SGV sgv, char* clientID, int month);

/**
@brief Função para a Query 11.
*/
void getTopSelledProducts(SGV sgv, int limit);

/**
@brief Função para a Query 12.
*/
void getCLientTopProfitProducts(SGV sgv, char* clientID, int limit);


#endif