#include "../includes/auxQuery10.h"

struct codigoQuantidade{
    char * codigo;
    int quantidade;
};

void printaCodigoQuantidade(CodigoQuantidade aux){
    char* str = getCodigoCodigoQuantidade(aux);
    printf("Cliente: %s\n", str);
    printf("Quantidade:%d\n",getQuantidadeCodigoQuantidade(aux));
    free(str);
}

void eliminaCodigoQuantidade (CodigoQuantidade cl){
	free(cl->codigo);
	free(cl);
}

CodigoQuantidade criaCodigoQuantidade(char* cod,int quant){
	CodigoQuantidade r = malloc(sizeof(struct codigoQuantidade));
	r->codigo = strdup(cod);
    r->quantidade = quant;
	return r;
}

char* getCodigoCodigoQuantidade(CodigoQuantidade cl){
	return strdup(cl->codigo);
}

int getQuantidadeCodigoQuantidade(CodigoQuantidade cl){
    return cl->quantidade;
}

struct myArrayQuantidade{
    CodigoQuantidade* array;
    int len;
};


MyArrayQuantidade criaMyArrayQuantidade(){
    MyArrayQuantidade r = malloc(sizeof(struct myArrayQuantidade));
    r->array = malloc(sizeof(CodigoQuantidade));
    r->len = 0;
}

int getSizeMyArrayQuantidade(MyArrayQuantidade r){
	return r->len;
}

MyArrayQuantidade adicionaCodigoQuantidade(MyArrayQuantidade r, CodigoQuantidade c){
    r->array=realloc(r->array, (r->len+1)*sizeof(CodigoQuantidade));
    r->array[r->len] = c;
    r->len++;
    return r;
}

CodigoQuantidade getCodigoQuantidade(MyArrayQuantidade r, int idx){
    return r->array[idx];
}

static void swap(MyArrayQuantidade arr,int a, int b){
    CodigoQuantidade temp = arr->array[a];
    arr->array[a] = arr->array[b];
    arr->array[b] = temp;
}

static int partitionMyArrayCodigo(MyArrayQuantidade arr,int ini, int fim){
	int idx,i;
	char *str, *pivot = getCodigoCodigoQuantidade(getCodigoQuantidade(arr,fim));
	idx = ini;
	for (i=ini; i<fim; i++){
        str = getCodigoCodigoQuantidade(getCodigoQuantidade(arr,i));
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

void qSortMyArrayCodigoAux(MyArrayQuantidade array,int ini, int fim){
   int p;
   if(ini<fim){
	   p = partitionMyArrayCodigo(array,ini,fim);
	   qSortMyArrayCodigoAux(array, ini ,p-1);
	   qSortMyArrayCodigoAux(array,p+1, fim-p-1);
	}
}

void qSortMyArrayCodigo(MyArrayQuantidade array){
    qSortMyArrayCodigoAux(array,0,getSizeMyArrayQuantidade(array)-1);
}

static int partitionMyQuantidade(MyArrayQuantidade arr,int ini, int fim){
	int idx,i;
	int aux, pivot = getQuantidadeCodigoQuantidade(getCodigoQuantidade(arr,fim));
	idx = ini;
	for (i=ini; i<fim; i++){
        aux = getQuantidadeCodigoQuantidade(getCodigoQuantidade(arr,i));
		if (pivot<=aux){
            swap(arr,idx,i);
			idx++;
		}
	}
    swap(arr,idx,fim);
	return idx;
}

void qSortMyArrayQuantidadeAux(MyArrayQuantidade array,int ini, int fim){
   int p;
   if(ini<fim){
	   p = partitionMyQuantidade(array,ini,fim);
	   qSortMyArrayQuantidadeAux(array, ini ,p-1);
	   qSortMyArrayQuantidadeAux(array,p+1, fim-p-1);
	}
}

void qSortMyArrayQuantidade(MyArrayQuantidade array){
    qSortMyArrayQuantidadeAux(array,0,getSizeMyArrayQuantidade(array)-1);
}

void eliminaMyArrayQuantidade(MyArrayQuantidade r){
    int i;
    for (i = 0; i < r->len; i++)
    {
        eliminaCodigoQuantidade(r->array[i]);
    }
    free(r->array);
    free(r);
}

MyArrayQuantidade removeRepetidosMyArrayQuantidade(MyArrayQuantidade array){
    CodigoQuantidade auxJ,aux,auxI=getCodigoQuantidade(array,0);
    int i=0,j=1,len =getSizeMyArrayQuantidade(array),quant = getQuantidadeCodigoQuantidade(auxI);
    MyArrayQuantidade r = criaMyArrayQuantidade();
    char * strJ,*strI = getCodigoCodigoQuantidade(auxI);
    while (i<len-1 && j<len)
    {
        auxJ = getCodigoQuantidade(array,j);
        strJ = getCodigoCodigoQuantidade(auxJ);
        if(strcmp(strJ,strI)!=0){
            aux = criaCodigoQuantidade(strI,quant);
            adicionaCodigoQuantidade(r,aux);
            i=j;
            free(strI);
            auxI = getCodigoQuantidade(array,i);
            strI = getCodigoCodigoQuantidade(auxI);
            quant = getQuantidadeCodigoQuantidade(auxI);
        }
        else{
            quant += getQuantidadeCodigoQuantidade(auxJ);
        }
        j++;
        free(strJ);
    }
    adicionaCodigoQuantidade(r,criaCodigoQuantidade(strI,quant));
    free(strI);
    eliminaMyArrayQuantidade(array);
    return r;   
}