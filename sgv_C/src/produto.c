#include "../includes/produto.h"

char *strdup(const char *s);

struct produto {
	char* codigo; /**< Código do Produto*/
};

int verificaProduto(char* codigo){
	int produtosVal=0;
		
	if ((strlen(codigo)== 6)&&(codigo[0]>='A' && codigo[0]<='Z')&&(codigo[1]>='A' && codigo[1]<='Z'))
			if(codigo[2] >= '1' && codigo[2] <= '9' && codigo[3] >= '0' && codigo[3] <= '9' && codigo[4] >= '0' && codigo[4] <= '9' && codigo[5] >= '0' && codigo[5] <= '9')
				produtosVal = 1;
	return produtosVal;
}

void eliminaProduto (Produto cl){
	free(cl->codigo);
	free(cl);
}

Produto criaProduto(char* codigo){
	Produto r = malloc(sizeof(struct produto));
	r->codigo = strdup(codigo);
	return r;
}

char* getCodigoProduto(Produto cl){
	return strdup(cl->codigo);
}