#include "../includes/factAux.h"

struct factVal{
	double preco; /**< Preço do Produto. */
    int quantidade; /**< Quantidade de Produto vendida. */
    char promo; /**< Modo de Compra. */
    int mes; /**< Mês em que foi realizada a Compra.*/
    int filial; /**<  Filial onde foi realizada a Compra. */
};

FactVal clonaFactVal(FactVal f){
	FactVal r = criaFactVal(getPrecoFactVal(f),getQuantidadeFactVal(f),getPromoFactVal(f), getMesFactVal(f), getFilialFactVal(f));
	return r;
}

FactVal criaFactVal(double p, int q, char c, int m, int f){
	FactVal r = malloc(sizeof(struct factVal));
	r->preco = p;
	r->quantidade = q;
	r->promo = c;
	r->mes = m;
	r->filial = f;
	return r;
}

void eliminaFactVal(FactVal f){
	free(f);
}

double getPrecoFactVal(FactVal f){
	return f->preco;
}

int getQuantidadeFactVal(FactVal f){
	return f->quantidade;
}

char getPromoFactVal(FactVal f){
	return f->promo;
}

int getMesFactVal(FactVal f){
	return f->mes;
}

int getFilialFactVal(FactVal f){
	return f->filial;
}

FactVal copiaFactVal(FactVal f){
	return criaFactVal(getPrecoFactVal(f), getQuantidadeFactVal(f), getPromoFactVal(f), getMesFactVal(f), getFilialFactVal(f));
}

VendasFact criaVendasFact(){
	VendasFact r = g_array_new(FALSE,FALSE, sizeof(FactVal));
	return r;
}

VendasFact adicionaFactVal(VendasFact v, FactVal f){
	v = g_array_append_val(v,f);
	return v;
}

int getSizeVendasFact(VendasFact v){
	return v->len;
}

FactVal getFactVal(VendasFact v, int index){
	return g_array_index( v, FactVal, index );
}

void eliminaVendasFact(VendasFact v){
	int tam = getSizeVendasFact(v);
	int i;
	for(i=0; i<tam; i++)
		eliminaFactVal(getFactVal(v, i));
	g_array_free (v,TRUE);
}