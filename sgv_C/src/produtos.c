#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../includes/produtos.h"


struct produtos {
	GTree* catProdutos; /**< Árvore Binária Balanceada para guardar os produtos */
	int produtosLidos /**< Guarda o número total de Produtos lidos a partir do Ficheiro. */
};

static int comparaProdutos(gconstpointer c1, gconstpointer c2){
	char* codc1 = getCodigoProduto((Produto) c1);
	char* codc2 = getCodigoProduto((Produto) c2);
	int r = strcmp(codc1, codc2);
	free(codc1);
	free(codc2);
	return r;
}

Produtos criaProdutos(){
	Produtos r = malloc(sizeof(struct produtos));
	r->catProdutos = g_tree_new_full(comparaProdutos,NULL, NULL, eliminaProduto);
	r->produtosLidos = 0;
	return r;
}

Produtos carregaCatalogoProdutos(Produtos cat, char* filename){
	char buffer[64];
	char* temp;
	Produto produto;

	FILE* f = fopen(filename, "r");
	if (f == NULL){
		return NULL;
	}
	while(fgets(buffer,sizeof(buffer),f)!=NULL){
		temp = strtok((buffer),"\r\n");
		cat->produtosLidos++;
		if (verificaProduto(temp)){
			produto = criaProduto(temp);
			g_tree_insert(cat->catProdutos,produto,produto);
		}
	}
	fclose(f);
	return cat;
}

int existeProduto(Produtos cat, char* str){
	Produto c = criaProduto(str);
	char * existe = g_tree_lookup(cat->catProdutos,c);
	eliminaProduto(c);
	int r = (existe!=NULL);
	return r;
}

static int getArrayProdutos(gpointer key, gpointer value, gpointer data){
	Produto p = (Produto) value;
	char* str = getCodigoProduto(p);
	adicionaStringArray(data, str);
	return FALSE;
}

StringArray getCodigosProdutos(Produtos cat){
	StringArray r = criaStringArray();
	g_tree_foreach(cat->catProdutos, getArrayProdutos , r );
	return r;
}

void eliminaProdutos(Produtos cat){
	g_tree_destroy(cat->catProdutos);
	free(cat);
}

void adicionaProduto(Produtos cat, Produto cl){
	g_tree_insert(cat->catProdutos, cl,cl);
}

int getSizeProdutos (Produtos cat){
	return g_tree_nnodes(cat->catProdutos);
}

int getProdutosLidos(Produtos cat){
	return cat->produtosLidos;
}