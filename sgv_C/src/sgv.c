#include "../includes/sgv.h"

#define BUFFER 64

struct sgv {
	Clientes clientes; /**< Todos os clientes lidos */
	Produtos produtos; /**< Todos os produtos lidos */
	FactTotal faturas; /**< Todas as faturas lidas */
	Filial filial[3]; /**< Todas as filiais lidas */
};

struct dadosLeitura {
	char* fileC; /**< Caminho para o ficheiro de Clientes */
	int lidosC; /**< Número de linhas no ficheiro de Clientes */
	int valC; /**< Número de linhas válidas no ficheiro de Clientes */
	
	char* fileP; /**< Caminho para o ficheiro de Produtos */
	int lidosP; /**< Número de linhas no ficheiro de Produtos */
	int valP; /**< Número de linhas válidas no ficheiro de Produtos */
	
	char* fileV; /**< Caminho para o ficheiro de Vendas */
	int lidosV; /**< Número de linhas no ficheiro de Vendas */
	int valV; /**< Número de linhas válidas no ficheiro de Vendas */
	
	double tempoExec; /** Tempo de execução da Query 1*/
};


SGV initSGV(){
	int i;

	SGV r = malloc(sizeof(struct sgv));
	r->clientes = criaClientes();
	r->produtos = criaProdutos();
	r->faturas = criaFactTotal();

	for(i = 0; i < 3; i++){
		r->filial[i] = criaFilial();
	}

	return r;
}

void destroySGV(SGV sgv){
    int i;
    
    eliminaClientes(sgv->clientes);
    eliminaProdutos(sgv->produtos);
    eliminaFactTotal(sgv->faturas);
    
    for(i = 0; i < 3; i++)
        eliminaFilial(sgv->filial[i]);
    
    free(sgv);
}


SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath){

	SGV r = initSGV();
	r->clientes = carregaCatalogoClientes(r->clientes,clientsFilePath);
	r->produtos = carregaCatalogoProdutos(r->produtos, productsFilePath);

	StringArray s = getCodigosProdutos(r->produtos);
	stringArrayToFactTotal(s, r->faturas);
	eliminaStringArray(s);

	s = getCodigosClientes(r->clientes);
	stringArrayToFilial(s,r->filial[0],r->filial[1],r->filial[2]);
	eliminaStringArray(s);

	carregaFactTotalEFiliais(r->clientes, r->produtos, salesFilePath, r->faturas, r->filial[0], r->filial[1], r->filial[2]);

	return r;

}


void carregaDadosIniciais(SGV sgv, DadosLeitura d){

	d->lidosC = getClientesLidos(sgv->clientes);
	d->valC = getSizeClientes(sgv->clientes);

	d->lidosP = getProdutosLidos(sgv->produtos);
	d->valP = getSizeProdutos(sgv->produtos);

	d->lidosV = getVendasLidas(sgv->faturas);
	d->valV = getVendasValidas(sgv->faturas);
}

DadosLeitura criaDadosIniciais(char* fileC, char* fileP, char* fileV){
	DadosLeitura r = malloc(sizeof(struct dadosLeitura));
	r->fileC = strdup(fileC);
	r->lidosC = 0;
	r->valC = 0;
	
	r->fileP = strdup(fileP);
	r->lidosP = 0;
	r->valP = 0;
	
	r->fileV = strdup(fileV);
	r->lidosV = 0;
	r->valV = 0;

	r->tempoExec = 0;

	return r;
}


void eliminaDadosIniciais(DadosLeitura d){
	free(d->fileC);
	free(d->fileP);
	free(d->fileV);
	free(d);
}


void setTempoExec(DadosLeitura d, double time){
	d->tempoExec = time;
}	


double getTempoExec(DadosLeitura d){
	return d->tempoExec;
}

char* getFileC(DadosLeitura d){
	return strdup(d->fileC);
}

int getClientesLidosDados(DadosLeitura d){
	return d->lidosC;
}

int getClientesValidosDados(DadosLeitura d){
	return d->valC;
}

char* getFileP(DadosLeitura d){
	return strdup(d->fileP);
}

int getProdutosLidosDados(DadosLeitura d){
	return d->lidosP;
}

int getProdutosValidosDados(DadosLeitura d){
	return d->valP;
}

char* getFileV(DadosLeitura d){
	return strdup(d->fileV);
}

int getVendasLidasDados(DadosLeitura d){
	return d->lidosV;
}

int getVendasValidasDados(DadosLeitura d){
	return d->valV;
}

/*
char* inputProdutoValido(SGV sgv, char* topo){
	int cond = 0, prodInv = 0;
	char buf[BUFFER];
	char* r;

	while(!cond){
		system("clear");
		printf("\t %s \n\n", topo);

		if(prodInv)
			printf("Produto Inválido\n\n");

		printf("Produto a pesquisar:\n");
		fgets(buf, BUFFER, stdin);
		r = strtok(buf, "\n");
		if(existeProdutoSGV(sgv, r))
			cond = 1;
		else
			prodInv = 1;
	}	

	return r;
}

char* inputClienteValido(SGV sgv, char* topo){
	int cond = 0, cliInv = 0;
	char buf[BUFFER];
	char* r;

	while(!cond){
		system("clear");
		printf("\t %s \n\n", topo);

		if(cliInv)
			printf("Cliente Inválido\n\n");

		printf("Cliente a pesquisar:\n");
		fgets(buf, BUFFER, stdin);
		r = strtok(buf, "\n");
		if(existeClienteSGV(sgv, r))
			cond = 1;
		else
			cliInv = 1;
	}	

	return r;
}

int existeClienteSGV(SGV sgv, char* cliente){
	printf("Cliente no ExisteCliente%s\n", cliente);
	return existeCliente(sgv->clientes, cliente);
}

int existeProdutoSGV(SGV sgv, char* produto){
	return existeProduto(sgv->produtos, produto);
}
*/

int inputMesValido(char* topo){
	int cond = 0, mesInv = 0, r = 0;
	char* buf[BUFFER];

	while(!cond){
		system("clear");
		printf("\t %s \n\n", topo);

		if(mesInv)
			printf("Mês Inválido\n\n");

		printf("Insira o mês:\n");
		fgets(buf, BUFFER, stdin);
		strtok(buf,"\n");
		r = atoi(buf);

		if(r >= 1 && r <= 12)
			cond = 1;
		else
			mesInv = 1;
	}	

	return r;

}

void inputIntervaloValido(char* topo, int intervalo[]){

	int cond = 0, intervInv = 0;
	char* buf[BUFFER];

	while(!cond){
		system("clear");
		printf("\t %s \n\n", topo);

		if(intervInv)
			printf("Intervalo Inválido\n\n");
		
		printf("Insira o Mês Inicial:\n");
		fgets(buf, BUFFER, stdin);
		strtok(buf,"\n");
		intervalo[0] = atoi(buf);

		printf("\nInsira o Mês Final:\n");
		fgets(buf, BUFFER, stdin);
		strtok(buf,"\n");
		intervalo[1] = atoi(buf);
		printf("\n");
		if(intervalo[0] >=1 && intervalo[0] <= 12 && intervalo[1] >= 1 && intervalo[1] <= 12 && intervalo[0] <= intervalo[1])
			cond = 1;
		else
			intervInv = 1;
	}
}

/* Query 2 */

void getProductsStartedByLetter(SGV sgv, char letra){
	getProdutosComLetra(letra, sgv->produtos);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 3 */

void getProductSalesAndProfit(SGV sgv, char* productID, int month){
	vendasProdutoMesGlobal(sgv->faturas, productID, month);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 4 */

void getProductsNeverBought(SGV sgv, int branchID){
	if (branchID == 2)
		getProdutosNaoComprados(sgv->faturas);
	else
		getProdutosNaoCompradosPorFilial(sgv->faturas);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 5 */

void getClientsOfAllBranches(SGV sgv){
	clientesTodasFiliais(sgv->filial[0], sgv->filial[1], sgv->filial[2]);	
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/*Query 6 */

void getClientsAndProductsNeverBoughtCount(SGV sgv){
	getClientesEProdutosNaoComprados(sgv->faturas, sgv->filial[0], sgv->filial[1], sgv->filial[2]);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 7 */

void getProductsBoughtByClient(SGV sgv, char* clientID){
	totalProdutosCompradosPorMes(clientID, sgv->filial[0], sgv->filial[1], sgv->filial[2]);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 8 */

void getSalesAndProfit(SGV sgv, int minMonth, int maxMonth){
	factEntreMeses(sgv->faturas,minMonth, maxMonth);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 9 */

void getProductBuyers(SGV sgv, char* productID, int branch){
	clientesQueCompraramProdutoFilial(branch, productID, sgv->filial[0], sgv->filial[1], sgv->filial[2]);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 10 */

void getClientFavoriteProducts(SGV sgv, char* clientID, int month){
	produtosMaisCompradosClienteMes(clientID, month ,sgv->filial[0], sgv->filial[1], sgv->filial[2]);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 11 */
void getTopSelledProducts(SGV sgv, int limit){
	nProdutosMaisVendidos(limit, sgv->filial[0], sgv->filial[1], sgv->filial[2]);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}

/* Query 12 */
void getCLientTopProfitProducts(SGV sgv, char* clientID, int limit){
	nProdutosMaisCompradosCliente(clientID, limit, sgv->filial[0], sgv->filial[1], sgv->filial[2]);
	printf("\n\t -- Pressione ENTER para continuar --\n");
   	getchar();
}