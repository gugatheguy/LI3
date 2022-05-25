#include "../includes/fact.h"

char *strdup(const char *s);

struct fact{	
    char* produto; /**< Código do Produto. */
    VendasFact vendasFact; /** < GArray com todas as vendas relacionadas com o Código. */
};

void printaFact(Fact f){
	int i=0, tam = getSizeFact(f);
	FactVal aux;
    printf("%s\n",f->produto);
    while(i < tam){
        aux = getFactVal(f->vendasFact, i);
		printf("\t{\n");
        printf("\tPreço: %f\n", getPrecoFactVal(aux));
        printf("\tQuantidade: %d\n", getQuantidadeFactVal(aux));
        printf("\tPromoção: %c\n", getPromoFactVal(aux));
        printf("\tMês: %d\n", getMesFactVal(aux));
        printf("\tFilial: %d\n", getFilialFactVal(aux));
		printf("\t}\n");
		++i;
    }
}

Fact criaFact(char* prod){
	Fact f = malloc(sizeof(struct fact));
	f->produto = strdup(prod);
	f->vendasFact = criaVendasFact();
	return f;
}

Fact adicionaVendaVal(Fact cat, FactVal f){
	cat->vendasFact = adicionaFactVal(cat->vendasFact,f);
	return cat;
}

char * getProdutoFact(Fact f){
	return strdup(f->produto);
}

VendasFact getVendasFact(Fact f){
	int i, tam = getSizeFact(f);
	VendasFact r = criaVendasFact();
	for (i = 0; i < tam; ++i)
		r = adicionaFactVal(r,copiaFactVal(getFactVal(f->vendasFact,i)));
	return r;
}

int getSizeFact(Fact f){
	return getSizeVendasFact(f->vendasFact);
}

void eliminaFact(Fact f){
	free(f->produto);
	eliminaVendasFact(f->vendasFact);
	free(f);
}

Fact clonaFact(Fact f){
	char * str = getProdutoFact(f);
	Fact r = criaFact(str);
	eliminaVendasFact(r->vendasFact);
	free(str);
	r->vendasFact = getVendasFact(f);
	return r;
}

void appendFactVal(Fact r, FactVal f){
	VendasFact v = r->vendasFact;
	v = adicionaFactVal(v,f);
}

void appendFact(Fact r, Fact f){
	VendasFact v = f->vendasFact;
	FactVal aux;
	int i,tam = getSizeVendasFact(v);
	for (i = 0; i < tam; i++){
		aux = copiaFactVal(getFactVal(v,i));
		r = adicionaVendaVal(r, aux);
	}
	eliminaFact(f);
}