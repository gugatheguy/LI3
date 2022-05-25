#include "../includes/interface.h"


static int input();
static void lerDosFicheiros(int* exit, SGV* sgv);
static void lerDosFicheirosCustom(int* exit, SGV* sgv);
static void menuLeitura(DadosLeitura d);
static void menuLeituraValgrind(DadosLeitura d);
static void ficheiroValido(char* filename, char* type);
static void menuQueries(int* exit, SGV* sgv);
static void menuQueriesAux(int* exit, SGV* sgv);

int input(){
	int r;
	char* aux;

	fgets(aux, sizeof(char*), stdin);
	if (aux[0] >= '0' && aux[0] <= '9'){
            r = aux[0] - '0';
            if(r > 0){
                return r;
            }
        }
        else{
            
            if(aux[0] == 's' || aux[0] == 'S'){
                return -1;
            }

             if(aux[0] == 'v' || aux[0] == 'V'){
                return 0;
            }

        }
    return -2;
}

void criaInterface(){
	
	int exit = 1;
	SGV sgv = NULL;

	lerDosFicheiros(&exit, &sgv);

	system("clear");

	if(sgv) 
		destroySGV(sgv);
}

void criaInterfaceValgrind(){
	SGV sgv = NULL;
	DadosLeitura d;
	clock_t start, end;
	double time_used;
	d = criaDadosIniciais("Dados_Iniciais/Clientes.txt", "Dados_Iniciais/Produtos.txt", "Dados_Iniciais/Vendas_1M.txt");
	start = clock();
	sgv = loadSGVFromFiles(sgv, "Dados_Iniciais/Clientes.txt", "Dados_Iniciais/Produtos.txt", "Dados_Iniciais/Vendas_1M.txt");
	end = clock();
	carregaDadosIniciais(sgv, d);
	time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    setTempoExec(d, time_used);
    menuLeituraValgrind(d);
    eliminaDadosIniciais(d);
    destroySGV(sgv);

}

void lerDosFicheiros(int* exit, SGV* sgv){
	
	int resp;
	clock_t start, end;
	double time_used;

	if(*sgv)
		destroySGV(*sgv);
			
	*sgv = NULL;


	while(*exit){

		DadosLeitura d = NULL;	
		system("clear");
		printf("\t-- SGV -- \n\n");
		printf("1- Ler Ficheiros Default\n");
		printf("2- Ler Ficheiros Custom\n\n");
		printf("s- Sair\n\n");
		printf("Opção: ");
		resp = input();
		

		switch(resp){

			case 1:

				d = criaDadosIniciais("Dados_Iniciais/Clientes.txt", "Dados_Iniciais/Produtos.txt", "Dados_Iniciais/Vendas_1M.txt");
				start = clock();
				*sgv = loadSGVFromFiles(*sgv, "Dados_Iniciais/Clientes.txt", "Dados_Iniciais/Produtos.txt", "Dados_Iniciais/Vendas_1M.txt");
				end = clock();
				carregaDadosIniciais(*sgv, d);
				time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
			    setTempoExec(d, time_used);
    			menuLeitura(d);
    			eliminaDadosIniciais(d);
    			menuQueries(exit,sgv);
				break;

			case 2:

				lerDosFicheirosCustom(exit, sgv);
				break;

			case -1:
				*exit = 0;
				break;

			default:
				break;
		}
	}

}

void menuLeitura(DadosLeitura d){
	
	system("clear");
    char* fileC;
    char* fileP;
    char* fileV;

    printf("\t-- Resultados Leitura [Queries 1 e 13] --\n\n" );

    printf("Tempo de Execução: %f s\n\n", getTempoExec(d));


    fileC = getFileC(d);
    printf("Ficheiro dos Clientes:	%s\n", fileC);
    printf("Clientes Lidos:         %d\n", getClientesLidosDados(d));
    printf("Clientes Válidos:       %d\n\n", getClientesValidosDados(d));

    fileP = getFileP(d);
    printf("Ficheiro dos Produtos:	%s\n", fileP);
    printf("Produtos Lidos:         %d\n", getProdutosLidosDados(d));
    printf("Produtos Válidos:       %d\n\n", getProdutosValidosDados(d));

	fileV = getFileV(d);
    printf("Ficheiro das Vendas:	%s\n", fileV);
    printf("Vendas Lidas:           %d\n", getVendasLidasDados(d));
    printf("Vendas Válidas:         %d\n\n", getVendasValidasDados(d));

    printf("\t -- Pressione ENTER para continuar --\n");
   	getchar();

    free(fileC);
    free(fileP);
    free(fileV);
}

void menuLeituraValgrind(DadosLeitura d){
	
	system("clear");
    char* fileC;
    char* fileP;
    char* fileV;

    printf("\t-- Resultados Leitura [Queries 1 e 13] --\n\n" );

    printf("Tempo de Execução: %f s\n\n", getTempoExec(d));


    fileC = getFileC(d);
    printf("Ficheiro dos Clientes:	%s\n", fileC);
    printf("Clientes Lidos:         %d\n", getClientesLidosDados(d));
    printf("Clientes Válidos:       %d\n\n", getClientesValidosDados(d));

    fileP = getFileP(d);
    printf("Ficheiro dos Produtos:	%s\n", fileP);
    printf("Produtos Lidos:         %d\n", getProdutosLidosDados(d));
    printf("Produtos Válidos:       %d\n\n", getProdutosValidosDados(d));

	fileV = getFileV(d);
    printf("Ficheiro das Vendas:	%s\n", fileV);
    printf("Vendas Lidas:           %d\n", getVendasLidasDados(d));
    printf("Vendas Válidas:         %d\n\n", getVendasValidasDados(d));

    free(fileC);
    free(fileP);
    free(fileV);
}


void ficheiroValido(char* filename, char* type){
	
	int cond = 1, existeFile = 1, ePasta = 1;
	struct stat statbuf;
	
	while(cond){
		
		system("clear");
		printf("\t-- Leitura de Ficheiros Custom [Query 1] --\n\n");
	
		if(!existeFile){
			system("clear");
			printf("\t-- Leitura de Ficheiros Custom [Query 1] --\n\n");
			printf("Ficheiro Inválido ou inexistente.\n\n");
		}

		if(!ePasta){
			system("clear");
			printf("\t-- Leitura de Ficheiros Custom [Query 1] --\n\n");
			printf("Ficheiro é uma pasta.\n\n");
		}

		printf("%s",type);
		fgets(filename, MAX_CHAR_FILES, stdin);
		printf("\n");
		filename = strtok(filename, "\n"); 

		if (stat(filename, &statbuf) == 0 && S_ISDIR(statbuf.st_mode))
			ePasta = 0;

		else {
		
			if(access(filename, R_OK) != -1)
				cond =  0;
		
			else existeFile = 0;
		}
			
	}
}


void lerDosFicheirosCustom(int* exit, SGV* sgv){
	
	char * fileC = malloc(sizeof(char) * MAX_CHAR_FILES);
	char * fileP = malloc(sizeof(char) * MAX_CHAR_FILES);
	char * fileV = malloc(sizeof(char) * MAX_CHAR_FILES);
	clock_t start, end;
	double time_used;

	ficheiroValido(fileC, "Ficheiro dos Clientes: ");
	ficheiroValido(fileP, "Ficheiro dos Produtos: ");
	ficheiroValido(fileV, "Ficheiro das Vendas: ");

	DadosLeitura d = criaDadosIniciais(fileC, fileP, fileV);

	start = clock();
	*sgv = loadSGVFromFiles(*sgv, fileC, fileP, fileV);
	end = clock();
	carregaDadosIniciais(*sgv, d);

	time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    setTempoExec(d, time_used);

 	menuLeitura(d);
    menuQueries(exit,sgv);


   	eliminaDadosIniciais(d);
}

void menuQueries(int* exit, SGV* sgv){

	while(*exit){

		int resp, mes = 0, qualFilial = 0;
		int intervalo[2];
		char letra = 'a';
		char* opcao[64];
		char produto[10];
		char cliente[10];
		int cond = 0;

		DadosLeitura d = NULL;	
		system("clear");
		printf("\t-- SGV -- \n\n");
		printf("1- Navegar Produtos por Letra                           [Query 2]\n");
		printf("2- Informações de Produto por mês                       [Query 3]\n");
		printf("3- Produtos não comprados                               [Query 4]\n");
		printf("4- Clientes em todas as filiais                         [Query 5]\n");
		printf("5- Clientes que não compraram e Produtos não comprados	[Query 6]\n");
		printf("6- Stats sobre Cliente num ano                          [Query 7]\n");
		printf("7- Total Faturado em intervalo de tempo                 [Query 8]\n");
		printf("8- Stats de Produto numa Filial                         [Query 9]\n");
		printf("9- Ver Queries restantes\n\n");
		printf("v- Voltar Atrás\n");
		printf("s- Sair \n\n");
		printf("Opção: ");
		resp = input();

		switch(resp){

			case 1:	
				while(!cond){
					system("clear");
					printf("\t -- SGV [Query 2] --\n\n");
					printf("Letra a procurar:\n");
					letra = getchar();
					toupper(letra);
					if(letra >= 'A' && letra <= 'Z')
						cond = 1;
				}
				system("clear");
				printf("\t -- SGV [Query 2] --\n\n");
				getProductsStartedByLetter(*sgv, letra);
				getchar();
				break;

			case 2:
				system("clear");
				printf("\t -- SGV [Query 9] --\n\n");
				printf("Produto a Pesquisar:\n");
				fgets(produto,10,stdin);
				mes = inputMesValido("-- SGV [Query 2] --");
				getProductSalesAndProfit(*sgv, strtok(produto,"\n"), mes);
				break;

			case 3:
				while(!cond){
					system("clear");
					printf("\t -- SGV [Query 4] --\n\n");
					if(qualFilial > 2)
						printf("Opção Inválida\n\n");
					printf("Produtos não comprados:\n\n");
					printf("1- Total dividido por Filial\n");
					printf("2- Total\n\n");
					printf("Opção: ");
					fgets(opcao,64,stdin);
					strtok(opcao,"\n");
					if((opcao >= "A" && opcao <= "Z" && opcao >= "a" && opcao <= "z") || atoi(opcao) > 2)
						qualFilial = 3;
					else{
						qualFilial = atoi(opcao);
						cond = 1;
					}
				}
				system("clear");
				printf("\t -- SGV [Query 4] --\n\n");
				getProductsNeverBought(*sgv, qualFilial);
				break;

			case 4:
				system("clear");
				printf("\t -- SGV [Query 5] --\n\n");
				getClientsOfAllBranches(*sgv);
				break;

			case 5:
				system("clear");
				printf("\t -- SGV [Query 6] --\n\n");
				getClientsAndProductsNeverBoughtCount(*sgv);
				break;

			case 6:
				system("clear");
				printf("\t -- SGV [Query 7] -- \n\n");
				printf("Cliente a Pesquisar:\n");
				fgets(cliente,10,stdin);
				system("clear");
				printf("\t -- SGV [Query 7] -- \n\n");
				getProductsBoughtByClient(*sgv, strtok(cliente,"\n"));
				break;
				
			case 7:
				system("clear");
				inputIntervaloValido("-- SGV [Query 8] --", intervalo);
				getSalesAndProfit(*sgv, intervalo[0], intervalo[1]);
				break;
				
			case 8:
				system("clear");
				printf("\t -- SGV [Query 9] --\n\n");
				printf("Produto a Pesquisar:\n");
				fgets(produto,10,stdin);
				while(!cond){

					if(qualFilial > 4){
						system("clear");
						printf("\t --SGV [Query 9] --\n\n");
						printf("Opção Inválida");
					}
					printf("\nFilial a pesquisar:\n");	
					printf("1- Filial 1\n");
					printf("2- Filial 2\n");
					printf("3- Filial 3\n\n");
					printf("Opção: ");
					fgets(opcao,64,stdin);
					strtok(opcao,"\n");
					if((opcao >= "A" && opcao <= "Z" && opcao >= "a" && opcao <= "z") || atoi(opcao) > 3)
						qualFilial = 4;
					else{
						qualFilial = atoi(opcao);
						cond = 1;
					}
				}
				system("clear");
				printf("\t -- SGV [Query 9] --\n\n");
				getProductBuyers(*sgv, strtok(produto,"\n"), qualFilial);
				break;
				
			case 9:

				menuQueriesAux(exit, sgv);
				break;		

			case 0:

				lerDosFicheiros(exit, sgv);
				break;

			case -1:
				*exit = 0;
				break;

			default:
				break;
		}
	}
}


void menuQueriesAux(int* exit, SGV* sgv){

	while(*exit){

		int resp, mes = 0, limite = 0;
		int intervalo[2];
		char letra = 'a';
		char* opcao[64];
		char produto[10];
		char cliente[10];
		int cond = 0;


		DadosLeitura d = NULL;	
		system("clear");
		printf("\t-- SGV -- \n\n");
		printf("1- Stats sobre Cliente num Mês                          [Query 10]\n");
		printf("2- N Produtos mais vendidos no Ano                      [Query 11]\n");
		printf("3- N Produtos que um Cliente mais gastou                [Query 12]\n\n");
		printf("v- Voltar Atrás\n");
		printf("s- Sair \n\n");
		printf("Opção: ");
		resp = input();

		switch(resp){

			case 1:
				system("clear");
				printf("\t -- SGV [Query 10] --\n\n");
				printf("Cliente a Pesquisar:\n");
				fgets(cliente,10,stdin);
				mes = inputMesValido("-- SGV [Query 10] --");
				system("clear");
				printf("\t -- SGV [Query 10] --\n\n");
				getClientFavoriteProducts(*sgv, strtok(cliente,"\n"), mes);
				menuQueries(exit, sgv);
				break;

			case 2:
				system("clear");
				printf("\t -- SGV [Query 11] --\n\n");
				while(!cond){

					if(limite < 0){
						system("clear");
						printf("\t --SGV [Query11] --\n\n");
						printf("Limite Inválido\n");
					}
					printf("\nNúmero de Produtos:\n");	
					fgets(opcao,64,stdin);
					strtok(opcao,"\n");
					if((opcao >= "A" && opcao <= "Z" && opcao >= "a" && opcao <= "z") || atoi(opcao)<= 0)
						limite = -1;
					else{
						limite = atoi(opcao);
						cond = 1;
					}
				}
				system("clear");
				printf("\t -- SGV [Query 11] --\n\n");
				getTopSelledProducts(*sgv, limite);
				menuQueries(exit, sgv);
				break;

			case 3:
				system("clear");
				printf("\t -- SGV [Query 12] --\n\n");
				printf("Cliente a Pesquisar:\n");
				fgets(cliente,10,stdin);
				while(!cond){

					if(limite < 0){
						system("clear");
						printf("\t --SGV [Query11] --\n\n");
						printf("Limite Inválido\n");
					}
					printf("\nNúmero de Produtos:\n");	
					fgets(opcao,64,stdin);
					strtok(opcao,"\n");
					if((opcao >= "A" && opcao <= "Z" && opcao >= "a" && opcao <= "z") || atoi(opcao) <= 0)
						limite = -1;
					else{
						limite = atoi(opcao);
						cond = 1;
					}
				}
				system("clear");
				printf("\t -- SGV [Query 12] --\n\n");
				getCLientTopProfitProducts(*sgv, strtok(cliente,"\n"), limite);
				menuQueries(exit,sgv);
				break;	

			case 0:

				
				menuQueries(exit, sgv);
				break;

			case -1:
				*exit = 0;
				break;

			default:
				break;
		}
	}
}