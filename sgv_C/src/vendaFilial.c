#include "../includes/vendaFilial.h"

char *strdup(const char *s);

struct vendaFilial{
    char* cliente;
    ProdutosFilial produtosFilial;
};

void printaVendaFilial(VendaFilial vf){
    int i=0, tam = getSizeVendaFilial(vf);
    char* prod;
    ProdutoFilial aux;
    printf("%s\n",getClienteFilial(vf));
    while(i < tam){
        aux = getProdutoFilial(vf->produtosFilial, i);
        prod = getProdutoProdutoFilial(aux);
        printf("{\n");
        printaProdutoFilial(aux);
        printf("}\n");
        free(prod);
        ++i;
    }
}

VendaFilial criaVendaFilial(char* codigo){
    VendaFilial vf = malloc(sizeof(struct vendaFilial));
    vf->cliente = strdup(codigo);
    vf->produtosFilial = criaProdutosFilial();
    return vf;
}

VendaFilial adicionaProdutosFilial(VendaFilial vf, ProdutoFilial pf){
    vf->produtosFilial = adicionaProdutoFilial(vf->produtosFilial, pf);
    return vf;
}

char* getClienteFilial(VendaFilial vf){
    return strdup(vf->cliente);
}

ProdutosFilial getProdutosFilial(VendaFilial vf){
    int i, tam = getSizeVendaFilial(vf);
    ProdutosFilial pf = criaProdutosFilial();
    for ( i = 0; i < tam; i++)
        pf = adicionaProdutoFilial(pf, copiaProdutoFilial(getProdutoFilial(vf->produtosFilial, i)));
    return pf;
}

int getSizeVendaFilial(VendaFilial vf){
    return getSizeProdutosFilial(vf->produtosFilial);
}

void eliminaVendaFilial(VendaFilial vf){
    free(vf->cliente);
    eliminaProdutosFilial(vf->produtosFilial);
	free(vf);
}

VendaFilial clonaVendaFilial(VendaFilial vf){
    char* str = getClienteFilial(vf);
    VendaFilial aux = criaVendaFilial(str);
    eliminaProdutosFilial(aux->produtosFilial);
    free(str);
    aux->produtosFilial = getProdutosFilial(vf);
    return aux;
}

void appendProdutosFilial(VendaFilial vf, ProdutoFilial pf){
    ProdutosFilial pfs= vf->produtosFilial;
    pfs = adicionaProdutoFilial(pfs, pf);
}

void appendVendaFilial(VendaFilial vf1, VendaFilial vf2){
    ProdutosFilial pfs = vf2->produtosFilial;
    ProdutoFilial aux;
    int i, tam = getSizeProdutosFilial(pfs);
    for(i = 0; i < tam; i++){
        aux = copiaProdutoFilial(getProdutoFilial(pfs, i));
        vf1 = adicionaProdutosFilial(vf1, aux);
    }
    eliminaVendaFilial(vf2);
}