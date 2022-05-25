#include "../includes/query11.h"

void adicionaCodigoQuantidadeClienteVendaFilial(VendaFilial vf, MyArrayQuantidadeCliente arr){
    ProdutosFilial pf = getProdutosFilial(vf);
    ProdutoFilial aux;
    char *str;
    int i,tam = getSizeProdutosFilial(pf);
    for (i = 0; i < tam; i++)
    {
        aux = getProdutoFilial(pf,i);
        str = getProdutoProdutoFilial(aux);
        adicionaCodigoQuantidadeCliente(arr,criaCodigoQuantidadeCliente(str,getQuantidadeProdutoFilial(aux)));
        free(str);
    }
    eliminaProdutosFilial(pf);
}

void nProdutosMaisVendidosFilial(int n,Filial f){
    MyArrayQuantidadeCliente r1=criaMyArrayQuantidadeCliente();
    VendaFilialArray va = getVendasFilial(f);
    int i,tam = getSizeVendaFilialArray(va);

    for (i = 0; i < tam; i++)
        adicionaCodigoQuantidadeClienteVendaFilial(getVendaFilialArray(va,i),r1);

    eliminaVendaFilialArray(va);

    qSortMyArrayCodigoCliente(r1);
    r1 = removeRepetidosMyArrayQuantidadeCliente(r1);
    qSortMyArrayQuantidadeCliente(r1);

    for (i = 0; i < n; i++){
        printf("\n");
        printaCodigoQuantidadeCliente(getCodigoQuantidadeCliente(r1,i));
    }
    eliminaMyArrayQuantidadeCliente(r1);
}

void nProdutosMaisVendidos(int n,Filial f1,Filial f2,Filial f3){
    printf("Filial 1: {");
    nProdutosMaisVendidosFilial(n,f1);
    printf("}\n");
    printf("Filial 2: {");
    nProdutosMaisVendidosFilial(n,f2);
    printf("}\n");
    printf("Filial 3: {");
    nProdutosMaisVendidosFilial(n,f3);
    printf("}\n");
}