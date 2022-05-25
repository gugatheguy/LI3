#include "../includes/query10.h"

/*query 10*/

void adicionaCodigoQuantidadeClienteMes(int mes,VendaFilial vf, MyArrayQuantidade arr){
    ProdutosFilial pf = getProdutosFilial(vf);
    ProdutoFilial aux;
    char *str;
    int i,tam = getSizeProdutosFilial(pf);
    for (i = 0; i < tam; i++)
    {
        aux = getProdutoFilial(pf,i);
        if(getMesProdutoFilial(aux)==mes){
            str = getProdutoProdutoFilial(aux);
            adicionaCodigoQuantidade(arr,criaCodigoQuantidade(str,getQuantidadeProdutoFilial(aux)));
            free(str);
        }
    }
    eliminaProdutosFilial(pf);
}

void produtosMaisCompradosClienteMes(char* cliente,int mes,Filial f1,Filial f2,Filial f3){
    VendaFilial vf = getVendaFilial(f1,cliente);
    MyArrayQuantidade arr = criaMyArrayQuantidade();
    int i,tam;

    adicionaCodigoQuantidadeClienteMes(mes,vf,arr);
    eliminaVendaFilial(vf);
    
    vf = getVendaFilial(f2,cliente);
    adicionaCodigoQuantidadeClienteMes(mes,vf,arr);
    eliminaVendaFilial(vf);

    vf = getVendaFilial(f3,cliente);
    adicionaCodigoQuantidadeClienteMes(mes,vf,arr);
    eliminaVendaFilial(vf);

    qSortMyArrayCodigo(arr);
    arr = removeRepetidosMyArrayQuantidade(arr);
    qSortMyArrayQuantidade(arr);
    tam = getSizeMyArrayQuantidade(arr);
    for (i = 0; i < tam; i++)
    {
        printaCodigoQuantidade(getCodigoQuantidade(arr,i));
        printf("\n");
    }
    eliminaMyArrayQuantidade(arr);
}