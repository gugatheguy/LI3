#include "../includes/venda.h"

struct venda {
    char* produto; /**< Código do Produto */
    double preco; /**< Preço do Produto */
    int quantidade; /**< Quantidade Vendida */
    char promo; /**< Tipo de compra (N/P) */
    char* cliente; /**< Código do Cliente */
    int mes; /** Mês em que foi realizada a Venda */
    int filial; /** Filial onde foi realizada a Venda */
};

Venda criaVenda(char ** cod){
    Venda venda = malloc(sizeof(struct venda));
	venda->produto = strdup(cod[0]);
	venda->preco = atof(cod[1]);
	venda->quantidade = atoi(cod[2]);
	venda->promo = cod[3][0];
	venda->cliente = strdup(cod[4]);
	venda->mes = atoi(cod[5]);
	venda->filial = atoi(cod[6]);

    return venda;
}

void eliminaVenda (Venda v){
	free(v->produto);
    free(v->cliente);
	free(v);
}

int verificaVenda(char** cod, Clientes catC, Produtos catP){
	
	return(existeProduto(catP,cod[0])&&
		   atof(cod[1])>=0.0 && atof(cod[1])<=999.99 &&
		   atoi(cod[2])>=1 && atoi(cod[2])<=200 &&
		   (strcmp(cod[3],"N")==0 || strcmp(cod[3],"P")==0) &&
		   existeCliente(catC,cod[4]) &&
		   atoi(cod[5])>=1 &&  atoi(cod[5])<=12 &&
		   atoi(cod[6])>=1 && atoi(cod[6])<=3);
}

Fact vendaToFact(Venda v){
	char * prod = getProdutoVenda(v);
	Fact f = criaFact(prod);
	FactVal r = criaFactVal(getPrecoVenda(v), getQuantidadeVenda(v), getPromoVenda(v), getMesVenda(v), getFilialVenda(v));
	f = adicionaVendaVal(f,r);
	free(prod);
	return f;
}

VendaFilial vendaToVendaFilial(Venda v){
    char* cliente = getClienteVenda(v);
    char* prod = getProdutoVenda(v);
    VendaFilial vf = criaVendaFilial(cliente);
    ProdutoFilial pf = criaProdutoFilial(prod, getPrecoVenda(v), getQuantidadeVenda(v), getPromoVenda(v), getMesVenda(v));
    vf = adicionaProdutosFilial(vf, pf);
    free(cliente);
    free(prod);
    return vf;
}

void carregaFactTotalEFiliais(Clientes cat_clientes, Produtos cat_produtos, char* filename, FactTotal cat, Filial f1, Filial f2, Filial f3){
	char buffer[64];
	char* temp, *temp2, *tokens[7];
	int r=0,fil;
	int val,i, vv = 0, vl = 0;
	Fact auxFact;
	VendaFilial auxVendaFilial;
	Venda v;
	FILE* f = fopen(filename, "r");
	if (f == NULL){
		return NULL;
	}
	while(fgets(buffer,sizeof(buffer),f)!=NULL){
		temp2 = strdup(buffer);
		for (temp =strtok(temp2, " \r\n"), i=0; temp != NULL && i<7 ;temp=strtok(NULL, " \r\n"), i++)
			tokens[i] = temp;
		vl++;
		val = verificaVenda(tokens, cat_clientes, cat_produtos);
		if (val){
			vv++;
			v = criaVenda(tokens);
			auxFact = vendaToFact(v);
			auxVendaFilial = vendaToVendaFilial(v);
			adicionaFact(cat,auxFact);
			fil = getFilialVenda(v);
			if(fil==1)
				adicionaVendaFilial(f1,auxVendaFilial);
			else{
				if(fil==2)
					adicionaVendaFilial(f2,auxVendaFilial);
				else
					adicionaVendaFilial(f3,auxVendaFilial);
			}
			eliminaVenda(v);
		}
		free(temp2);
	}
	fclose(f);
	setVendasLidas(cat, vl);
	setVendasValidas(cat, vv);
	return cat;

}

char* getProdutoVenda(Venda v){
	return strdup(v->produto);
}

double getPrecoVenda(Venda v){
	return v->preco;
}

int getQuantidadeVenda(Venda v){
	return v->quantidade;
}

char getPromoVenda(Venda v){
	return v->promo;
}

char* getClienteVenda(Venda v){
	return strdup(v->cliente);
}

int getMesVenda(Venda v){
	return v->mes;
}

int getFilialVenda(Venda v){
	return v->filial;
}