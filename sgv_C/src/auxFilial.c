#include "../includes/auxFilial.h"

char *strdup(const char *s);

struct produtoFilial{
    char* produto;
    double preco;
    int quantidade;
    char promo;
    int mes;
};

void printaProdutoFilial(ProdutosFilial aux){
    char * prod = getProdutoProdutoFilial(aux);
    printf("Produto: %s\n",prod);
    printf("Preço: %f\n", getPrecoProdutoFilial(aux));
    printf("Quantidade: %d\n", getQuantidadeProdutoFilial(aux));
    printf("Promoção %c\n", getPromoProdutoFilial(aux));
    printf("Mês: %d\n", getMesProdutoFilial(aux));
    free(prod);
}

ProdutoFilial clonaProdutoFilial(ProdutoFilial pf){
    ProdutoFilial p = criaProdutoFilial(getProdutoProdutoFilial(pf), getPrecoProdutoFilial(pf), getQuantidadeProdutoFilial(pf), getPromoProdutoFilial(pf), getMesProdutoFilial(pf));
    return p;
}

ProdutoFilial criaProdutoFilial(char* produto, double preco, int qt, char pr, int mes){
    ProdutoFilial pf = malloc(sizeof(struct produtoFilial));
    pf->produto = strdup(produto);
    pf->preco = preco;
    pf->quantidade = qt;
    pf->promo = pr;
    pf->mes = mes;
    return pf;
}

void eliminaProdutoFilial(ProdutoFilial pf){
    free(pf->produto);
    free(pf);
}

char* getProdutoProdutoFilial(ProdutoFilial pf){
    return strdup(pf->produto);
}

double getPrecoProdutoFilial(ProdutoFilial pf){
    return pf->preco;
}

int getQuantidadeProdutoFilial(ProdutoFilial pf){
    return pf->quantidade;
}

char getPromoProdutoFilial(ProdutoFilial pf){
    return pf->promo;
}

int getMesProdutoFilial(ProdutoFilial pf){
    return pf->mes;
}

ProdutoFilial copiaProdutoFilial(ProdutoFilial pf){
    char* prod = getProdutoProdutoFilial(pf);
    ProdutoFilial r = criaProdutoFilial(prod, getPrecoProdutoFilial(pf), getQuantidadeProdutoFilial(pf), getPromoProdutoFilial(pf), getMesProdutoFilial(pf));
    free(prod);
    return r;
}

ProdutosFilial criaProdutosFilial(){
    ProdutosFilial pf = g_array_new(FALSE,FALSE, sizeof(ProdutoFilial));
    return pf;
}

ProdutosFilial adicionaProdutoFilial(ProdutosFilial pfs, ProdutoFilial pf){
    pfs = g_array_append_val(pfs,pf);
    return pfs;
}

int getSizeProdutosFilial(ProdutosFilial pfs){
    return pfs->len;
}

ProdutoFilial getProdutoFilial(ProdutosFilial pfs, int index){
    return g_array_index(pfs, ProdutoFilial, index);
}

void eliminaProdutosFilial(ProdutosFilial pfs){
    int tam = getSizeProdutosFilial(pfs);
    int i;
    for ( i = 0; i < tam; i++){
        eliminaProdutoFilial(getProdutoFilial(pfs,i));
    }
    g_array_free (pfs,TRUE);
}