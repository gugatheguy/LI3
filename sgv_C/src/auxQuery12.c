#include "../includes/auxQuery12.h"

struct codigoDinheiro{
    char* codigo;
    double dinheiro;
};

void printaCodigoDinheiro(CodigoDinheiro aux){
    char* str = getCodigoCodigoDinheiro(aux);
    printf("Produto: %s\n", str);
    printf("Faturação Total: %0.2f\n",getDinheiroCodigoDinheiro(aux));
    free(str);
}

void eliminaCodigoDinheiro (CodigoDinheiro cl){
	free(cl->codigo);
	free(cl);
}

CodigoDinheiro criaCodigoDinheiro(char* cod,double money){
	CodigoDinheiro r = malloc(sizeof(struct codigoDinheiro));
	r->codigo = strdup(cod);
    r->dinheiro = money;
	return r;
}

char* getCodigoCodigoDinheiro(CodigoDinheiro cl){
	return strdup(cl->codigo);
}

double getDinheiroCodigoDinheiro(CodigoDinheiro cl){
    return cl->dinheiro;
}

struct myArrayDinheiro{
    CodigoDinheiro* array;
    int len;
};

MyArrayDinheiro criaMyArrayDinheiro(){
    MyArrayDinheiro r = malloc(sizeof(struct myArrayDinheiro));
    r->array = malloc(sizeof(CodigoDinheiro));
    r->len = 0;
}

int getSizeMyArrayDinheiro(MyArrayDinheiro r){
	return r->len;
}

MyArrayDinheiro adicionaCodigoDinheiro(MyArrayDinheiro r, CodigoDinheiro c){
    r->array=realloc(r->array, (r->len+1)*sizeof(CodigoDinheiro));
    r->array[r->len] = c;
    r->len++;
    return r;
}

CodigoDinheiro getCodigoDinheiro(MyArrayDinheiro r, int idx){
    return r->array[idx];
}

static void swap(MyArrayDinheiro arr,int a, int b){
    CodigoDinheiro temp = arr->array[a];
    arr->array[a] = arr->array[b];
    arr->array[b] = temp;
}

static int partitionMyArrayCodigo(MyArrayDinheiro arr,int ini, int fim){
	int idx,i;
	char *str, *pivot = getCodigoCodigoDinheiro(getCodigoDinheiro(arr,fim));
	idx = ini;
	for (i=ini; i<fim; i++){
        str = getCodigoCodigoDinheiro(getCodigoDinheiro(arr,i));
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

void qSortMyArrayCodigoDinheiroAux(MyArrayDinheiro array,int ini, int fim){
   int p;
   if(ini<fim){
	   p = partitionMyArrayCodigo(array,ini,fim);
	   qSortMyArrayCodigoAux(array, ini ,p-1);
	   qSortMyArrayCodigoAux(array,p+1, fim-p-1);
	}
}

void qSortMyArrayCodigoDinheiro(MyArrayDinheiro array){
    qSortMyArrayCodigoAux(array,0,getSizeMyArrayDinheiro(array)-1);
}

static int partitionMyDinheiro(MyArrayDinheiro arr,int ini, int fim){
	int idx,i;
	double aux, pivot = getDinheiroCodigoDinheiro(getCodigoDinheiro(arr,fim));
	idx = ini;
	for (i=ini; i<fim; i++){
        aux = getDinheiroCodigoDinheiro(getCodigoDinheiro(arr,i));
		if (pivot<=aux){
            swap(arr,idx,i);
			idx++;
		}
	}
    swap(arr,idx,fim);
	return idx;
}

void qSortMyArrayDinheiroAux(MyArrayDinheiro array,int ini, int fim){
   int p;
   if(ini<fim){
	   p = partitionMyDinheiro(array,ini,fim);
	   qSortMyArrayDinheiroAux(array, ini ,p-1);
	   qSortMyArrayDinheiroAux(array,p+1, fim-p-1);
	}
}

void qSortMyArrayDinheiro(MyArrayDinheiro array){
    qSortMyArrayDinheiroAux(array,0,getSizeMyArrayDinheiro(array)-1);
}

void eliminaMyArrayDinheiro(MyArrayDinheiro r){
    int i;
    for (i = 0; i < r->len; i++){
        eliminaCodigoDinheiro(r->array[i]);
    }
    free(r->array);
    free(r);
}

MyArrayDinheiro removeRepetidosMyArrayDinheiro(MyArrayDinheiro array){
    CodigoDinheiro auxJ,aux,auxI=getCodigoDinheiro(array,0);
    int i=0,j=1,len =getSizeMyArrayDinheiro(array);
    double quant = getDinheiroCodigoDinheiro(auxI);
    MyArrayDinheiro r = criaMyArrayDinheiro();
    char * strJ,*strI = getCodigoCodigoDinheiro(auxI);
    while (i<len-1 && j<len){
        auxJ = getCodigoDinheiro(array,j);
        strJ = getCodigoCodigoDinheiro(auxJ);
        if(strcmp(strJ,strI)!=0){
            aux = criaCodigoDinheiro(strI,quant);
            adicionaCodigoDinheiro(r,aux);
            i=j;
            free(strI);
            auxI = getCodigoDinheiro(array,i);
            strI = getCodigoCodigoDinheiro(auxI);
            quant = getDinheiroCodigoDinheiro(auxI);
        }
        else{
            quant += getDinheiroCodigoDinheiro(auxJ);
        }
        j++;
        free(strJ);
    }
    adicionaCodigoDinheiro(r,criaCodigoDinheiro(strI,quant));
    free(strI);
    eliminaMyArrayDinheiro(array);
    return r;   
}