#include "../includes/auxQuery11.h"

struct codigoQuantidadeCliente{
    char * codigo;
    int quantidade;
    int clientes;
};

void printaCodigoQuantidadeCliente(CodigoQuantidadeCliente aux){
    char* str = getCodigoCodigoQuantidadeCliente(aux);
    printf("Código: %s\n", str);
    printf("Quantidade: %d\n",getQuantidadeCodigoQuantidadeCliente(aux));
    printf("Clientes: %d\n",getClientesCodigoQuantidadeCliente(aux));
    free(str);
}

void eliminaCodigoQuantidadeCliente (CodigoQuantidadeCliente cl){
	free(cl->codigo);
	free(cl);
}

CodigoQuantidadeCliente criaCodigoQuantidadeCliente(char* cod,int quant){
	CodigoQuantidadeCliente r = malloc(sizeof(struct codigoQuantidadeCliente));
	r->codigo = strdup(cod);
    r->quantidade = quant;
    r->clientes = 1;
	return r;
}

CodigoQuantidadeCliente criaCodigoQuantidadeMaisDeUmCliente(char* cod,int quant,int buyers){
	CodigoQuantidadeCliente r = malloc(sizeof(struct codigoQuantidadeCliente));
	r->codigo = strdup(cod);
    r->quantidade = quant;
    r->clientes = buyers;
	return r;
}

char* getCodigoCodigoQuantidadeCliente(CodigoQuantidadeCliente cl){
	return strdup(cl->codigo);
}

int getQuantidadeCodigoQuantidadeCliente(CodigoQuantidadeCliente cl){
    return cl->quantidade;
}

int getClientesCodigoQuantidadeCliente(CodigoQuantidadeCliente cl){
    return cl->clientes;
}

struct myArrayQuantidadeCliente
{
    CodigoQuantidadeCliente* array;
    int len;
};


MyArrayQuantidadeCliente criaMyArrayQuantidadeCliente(){
    MyArrayQuantidadeCliente r = malloc(sizeof(struct myArrayQuantidadeCliente));
    r->array = malloc(sizeof(CodigoQuantidadeCliente));
    r->len = 0;
}


int getSizeMyArrayQuantidadeCliente(MyArrayQuantidadeCliente r){
	return r->len;
}

MyArrayQuantidadeCliente adicionaCodigoQuantidadeCliente (MyArrayQuantidadeCliente r, CodigoQuantidadeCliente c){
    r->array=realloc(r->array, (r->len+1)*sizeof(CodigoQuantidadeCliente));
    r->array[r->len] = c;
    r->len++;
    return r;
}

CodigoQuantidadeCliente getCodigoQuantidadeCliente(MyArrayQuantidadeCliente r, int idx){
    return r->array[idx];
}

static void swap(MyArrayQuantidadeCliente arr,int a, int b){
    CodigoQuantidadeCliente temp = arr->array[a];
    arr->array[a] = arr->array[b];
    arr->array[b] = temp;
}

static int partitionMyArrayCodigo(MyArrayQuantidadeCliente arr,int ini, int fim){
	int idx,i;
	char *str, *pivot = getCodigoCodigoQuantidadeCliente(getCodigoQuantidadeCliente(arr,fim));
	idx = ini;
	for (i=ini; i<fim; i++){
        str = getCodigoCodigoQuantidadeCliente(getCodigoQuantidadeCliente(arr,i));
		if (strcmp(str,pivot)<=0){
            swap(arr,idx,i);
			idx++;
		}
        free(str);
	}
    free(pivot);
    swap(arr,idx,fim);
	return idx;
}

void qSortMyArrayCodigoClienteAux(MyArrayQuantidadeCliente array,int ini, int fim){
   int p;
   if(ini<fim){
	   p = partitionMyArrayCodigo(array,ini,fim);
	   qSortMyArrayCodigoClienteAux(array, ini ,p-1);
	   qSortMyArrayCodigoClienteAux(array,p+1, fim-p-1);
	}
}

void qSortMyArrayCodigoCliente(MyArrayQuantidadeCliente array){
    qSortMyArrayCodigoClienteAux(array,0,getSizeMyArrayQuantidadeCliente(array)-1);
}


static int partitionMyQuantidade(MyArrayQuantidadeCliente arr,int ini, int fim){
	int idx,i;
	int aux, pivot = getQuantidadeCodigoQuantidadeCliente(getCodigoQuantidadeCliente(arr,fim));
	idx = ini;
	for (i=ini; i<fim; i++){
        aux = getQuantidadeCodigoQuantidadeCliente(getCodigoQuantidadeCliente(arr,i));
		if (pivot<=aux){
            swap(arr,idx,i);
			idx++;
		}
	}
    swap(arr,idx,fim);
	return idx;
}

void qSortMyArrayQuantidadeClienteAux(MyArrayQuantidadeCliente array,int ini, int fim){
   int p;
   if(ini<fim){
	   p = partitionMyQuantidade(array,ini,fim);
	   qSortMyArrayQuantidadeClienteAux(array, ini ,p-1);
	   qSortMyArrayQuantidadeClienteAux(array,p+1, fim-p-1);
	}
}

void qSortMyArrayQuantidadeCliente(MyArrayQuantidadeCliente array){
    qSortMyArrayQuantidadeClienteAux(array,0,getSizeMyArrayQuantidadeCliente(array)-1);
}

void eliminaMyArrayQuantidadeCliente(MyArrayQuantidadeCliente r){
    int i;
    for (i = 0; i < r->len; i++)
    {
        eliminaCodigoQuantidadeCliente(r->array[i]);
    }
    free(r->array);
    free(r);
}

MyArrayQuantidadeCliente removeRepetidosMyArrayQuantidadeCliente(MyArrayQuantidadeCliente array){
    CodigoQuantidadeCliente auxJ,aux,auxI=getCodigoQuantidadeCliente(array,0);
    int i=0,j=1,len =getSizeMyArrayQuantidadeCliente(array),quant = getQuantidadeCodigoQuantidadeCliente(auxI),buyers=1;
    MyArrayQuantidadeCliente r = criaMyArrayQuantidadeCliente();
    char * strJ,*strI = getCodigoCodigoQuantidadeCliente(auxI);
    while (i<len-1 && j<len)
    {
        auxJ = getCodigoQuantidadeCliente(array,j);
        strJ = getCodigoCodigoQuantidadeCliente(auxJ);
        if(strcmp(strJ,strI)!=0){
            aux = criaCodigoQuantidadeMaisDeUmCliente(strI,quant,buyers);
            adicionaCodigoQuantidadeCliente(r,aux);
            i=j;
            free(strI);
            auxI = getCodigoQuantidadeCliente(array,i);
            strI = getCodigoCodigoQuantidadeCliente(auxI);
            quant = getQuantidadeCodigoQuantidadeCliente(auxI);
            buyers=1;
        }
        else{
            quant += getQuantidadeCodigoQuantidadeCliente(auxJ);
            buyers++;
        }
        j++;
        free(strJ);
    }
    adicionaCodigoQuantidadeCliente(r,criaCodigoQuantidadeMaisDeUmCliente(strI,quant,buyers));
    free(strI);
    eliminaMyArrayQuantidadeCliente(array);
    return r;   
}