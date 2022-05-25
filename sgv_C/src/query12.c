#include "../includes/query12.h"

/*query 12*/

void adicionaCodigoDinheiroCliente(VendaFilial vf, MyArrayDinheiro arr){
    ProdutosFilial pf = getProdutosFilial(vf);
    ProdutosFilial aux;
    char* str;
    int i, tam = getSizeProdutosFilial(pf);

    for(i = 0; i < tam; i++){
        aux = getProdutoFilial(pf, i);
        str = getProdutoProdutoFilial(aux);
        adicionaCodigoDinheiro(arr, criaCodigoDinheiro(str,getPrecoProdutoFilial(aux)*getQuantidadeProdutoFilial(aux)));
        free(str);
    }
    eliminaProdutosFilial(pf);
}

void nProdutosMaisCompradosCliente(char* cliente, int n,Filial f1,Filial f2,Filial f3){
    VendaFilial vf = getVendaFilial(f1,cliente);
    MyArrayDinheiro arr = criaMyArrayDinheiro();
    int i;

    adicionaCodigoDinheiroCliente(vf, arr);
    eliminaVendaFilial(vf);

    vf = getVendaFilial(f2,cliente);
    adicionaCodigoDinheiroCliente(vf, arr);
    eliminaVendaFilial(vf);

    vf = getVendaFilial(f3,cliente);
    adicionaCodigoDinheiroCliente(vf, arr);
    eliminaVendaFilial(vf);

    qSortMyArrayCodigoDinheiro(arr);
    arr = removeRepetidosMyArrayDinheiro(arr);
    qSortMyArrayDinheiro(arr);
    for ( i = 0; i < n; i++){
        printaCodigoDinheiro(getCodigoDinheiro(arr,i));
        printf("\n");
    }
    eliminaMyArrayDinheiro(arr);    
}