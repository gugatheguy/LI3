 #include "../includes/factTotal.h"

struct factTotal{
	GTree* catFact; /**< Árvore Binária Balanceada para guardar todas as Faturas. */
	int vendasLidas; /**< Guarda o número total de Vendas lidas a partir do Ficheiro. */
	int vendasValidas; /**< Guarda o número total de Vendas Vaĺidas a partir do Ficheiro. */
};

static int comparaFact(gconstpointer c1, gconstpointer c2){
	char* codc1 = getProdutoFact((Fact) c1);
	char* codc2 = getProdutoFact((Fact) c2);
	int r = strcmp(codc1, codc2);
	free(codc1);
	free(codc2);
	return r;
}

FactTotal criaFactTotal(){
	FactTotal r = malloc(sizeof(struct factTotal));
	r->catFact = g_tree_new_full(comparaFact ,NULL, NULL, eliminaFact);
	r->vendasLidas = 0;
	r->vendasValidas = 0;
	return r;
}

void stringArrayToFactTotal(StringArray s, FactTotal cat){
    int i, tam = getSizeStringArray(s);
    Fact f;
    for (i = 0; i < tam; ++i){
        f = criaFact(getString(s,i));
        insertFact(cat, f);
    }
}

int existeFact(FactTotal cat, char* str){
	Fact c = criaFact(str);
	char* key = g_tree_lookup(cat->catFact,c);
	eliminaFact(c);
	int r = key!=NULL;
	return r;
}

void eliminaFactTotal(FactTotal cat){
	g_tree_destroy(cat->catFact);
	free(cat);
}

void insertFact(FactTotal cat, Fact f){
	g_tree_insert(cat->catFact, f, f);
}

void adicionaFact(FactTotal cat, Fact f){
	appendFact(g_tree_lookup(cat->catFact, f),f);
}

Fact getFact(FactTotal cat, char * str){
	Fact f = criaFact(str);
	Fact r = (Fact) g_tree_lookup(cat->catFact, f);
	eliminaFact(f);
	f = clonaFact(r);
	return f;
}

static int treeToFactArray(gpointer key, gpointer value, gpointer data){
	Fact v = (Fact) value;
	Fact r = clonaFact(v);
	adicionaFactArray(data, r);
	return FALSE;
}

FactArray getFacts(FactTotal cat){
	FactArray r = criaFactArray();
	g_tree_foreach(cat->catFact, treeToFactArray, r);
	return r;
}

int getSizeFactTotal(FactTotal cat){
	return g_tree_nnodes(cat->catFact);
}

void setVendasLidas(FactTotal cat, int num){
	cat->vendasLidas = num;
}

void setVendasValidas(FactTotal cat, int num){
	cat->vendasValidas = num;
}

int getVendasLidas(FactTotal cat){
	return cat->vendasLidas;
}

int getVendasValidas(FactTotal cat){
	return cat->vendasValidas;
}