#include "../includes/cliente.h"

char *strdup(const char *s);

struct cliente {
	char* codigo; /**< Código do Cliente*/
};

int verificaCliente(char* codigo){
	int clientesVal=0;
	if ((strlen(codigo)== 5)&&(codigo[0]>='A' && codigo[0]<='Z')){
				if(codigo[1] == '5' && codigo[2] == '0' && codigo[3] == '0' && codigo[2] == '0')
					clientesVal = 1;
				else if(codigo[1] >= '1' && codigo[1] < '5' && codigo[2] >= '0' && codigo[2] <= '9' && codigo[3] >= '0' && codigo[3] <= '9' && codigo[4] >= '0' && codigo[4] <= '9')
					clientesVal = 1;
			}
	return clientesVal;
}

void eliminaCliente (Cliente cl){
	free(cl->codigo);
	free(cl);
}

Cliente criaCliente(char* codigo){
	Cliente r = malloc(sizeof(struct cliente));
	r->codigo = strdup(codigo);
	return r;
}


char* getCodigoCliente(Cliente cl){
	return strdup(cl->codigo);
}