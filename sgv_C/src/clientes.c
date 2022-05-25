#include "../includes/clientes.h"

struct clientes {
	GTree* catClientes; /**< Árvore Binária Balanceada para guardar os clientes */
	int clientesLidos; /**< Guarda o número total de Clientes lidos a partir do Ficheiro. */
};

static int comparaClientes(gconstpointer c1, gconstpointer c2){
	char* codc1 = getCodigoCliente((Cliente) c1);
	char* codc2 = getCodigoCliente((Cliente) c2);
	int r = strcmp(codc1, codc2);
	free(codc1);
	free(codc2);
	return r;
}

Clientes criaClientes(){
	Clientes r = malloc(sizeof(struct clientes));
	r->catClientes = g_tree_new_full(comparaClientes,NULL, NULL, eliminaCliente);
	r->clientesLidos = 0;
	return r;
}

Clientes carregaCatalogoClientes(Clientes cat, char* filename){
	char buffer[64];
	char* temp;
	Cliente cliente;

	FILE* f = fopen(filename, "r");
	if (f == NULL){
		return NULL;
	}
	while(fgets(buffer,sizeof(buffer),f)!=NULL){
		temp = strtok((buffer),"\r\n");
		cat->clientesLidos++;
		if (verificaCliente(temp)){
			cliente = criaCliente(temp);
			g_tree_insert(cat->catClientes,cliente,cliente);
		}
	}
	fclose(f);
	return cat;
}

int existeCliente(Clientes cat, char* str){
	Cliente c = criaCliente(str);
	char * existe = g_tree_lookup(cat->catClientes,c);
	eliminaCliente(c);
	int r = (existe!=NULL);
	return r;
}

void eliminaClientes(Clientes cat){
	g_tree_destroy(cat->catClientes);
	free(cat);
}


void adicionaCliente(Clientes cat, Cliente cl){
	g_tree_insert(cat->catClientes, cl,cl);
}

int getSizeClientes (Clientes cat){
	return g_tree_nnodes(cat->catClientes);
}

static int getArrayClientes(gpointer key, gpointer value, gpointer data){
	Cliente c = (Cliente) value;
	char* str = getCodigoCliente(c);
	adicionaStringArray(data, str);
	return FALSE;
}

StringArray getCodigosClientes(Clientes cat){
	StringArray r = criaStringArray();
	g_tree_foreach(cat->catClientes, getArrayClientes, r);
	return r;
}

int getClientesLidos(Clientes cat){
	return cat->clientesLidos;
}