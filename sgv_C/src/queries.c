#include "../includes/queries.h"

/*query 2*/

void getProdutosComLetra(char l,Produtos cat){
    StringArray s = getCodigosProdutos(cat);
    StringArray r = criaStringArray();
    int i = 0, tam= getSizeStringArray(s);
    char * str;
    for (str = getString(s,i);str[0]<=l && i < tam-1; ++i, str = getString(s,i))
        if(str[0]==l)
            adicionaStringArray(r,str);
    if(l=='Z')
        adicionaStringArray(r,str);
    tam = getSizeStringArray(r);
    for (i = 0; i < tam; i++)
    {
        printf("%s\n",getString(r,i));
    }
    printf("Total de Produtos: %d\n",tam);
    eliminaStringArray(s);
}

/*query 3*/

void vendasProdutoMesGlobal(FactTotal cat, char * prod, int mes){
	Fact f = getFact(cat,prod);
	VendasFact v = getVendasFact(f);
	int vendas[2][3] = {0};
	double dinheiro[2][3] = {0};
	char c;
	FactVal fv;
	int i,tam = getSizeVendasFact(v);
	for (i = 0; i <tam; ++i){
		fv = getFactVal(v,i);
		if(getMesFactVal(fv)==mes){
			c = getPromoFactVal(fv);
			if (c=='N'){
				vendas[0][getFilialFactVal(fv)-1]++;
				dinheiro[0][getFilialFactVal(fv)-1] += getPrecoFactVal(fv) * getQuantidadeFactVal(fv);
			}
			else{
				vendas[1][getFilialFactVal(fv)-1]++;
				dinheiro[1][getFilialFactVal(fv)-1] += getPrecoFactVal(fv) * getQuantidadeFactVal(fv);
			}
		}
	}
	eliminaVendasFact(v);
	eliminaFact(f);

	printf("Vendas N: {\n");
	for (i = 0; i < 3; i++)
		printf("\tFilial %d: %d\n",i+1,vendas[0][i]);
	printf("}\n");

	printf("Vendas P: {\n");
	for (i = 0; i < 3; i++)
		printf("\tFilial %d: %d\n",i+1,vendas[1][i]);
	printf("}\n");

	printf("Dinheiro N: {\n");
	for (i = 0; i < 3; i++)
		printf("\tFilial %d: %.2f\n",i+1, dinheiro[0][i]);
	printf("}\n");

	printf("Dinheiro P: {\n");
	for (i = 0; i < 3; i++)
		printf("\tFilial %d: %.2f\n",i+1,dinheiro[1][i]);
	printf("}\n");
}

/*query 4*/

void getProdutosNaoComprados(FactTotal cat){
	FactArray fa = getFacts(cat);
	Fact f;
	StringArray r = criaStringArray();
	char * str;
	int i, tam= getSizeFactArray(fa);
	for (i = 0; i < tam; i++)
	{
		f = getFactArray(fa,i);
		if(getSizeFact(f)==0)
			r = adicionaStringArray(r,getProdutoFact(f));
	}
	tam= getSizeStringArray(r);
	for (i = 0; i < tam; i++)
	{
		str = getString(r,i);
		printf("%s\n",str);
	}
	printf("Produtos não comprados: %d\n", getSizeFactArray(r));
	eliminaFactArray(fa);
	eliminaStringArray(r);
}

void produtoCompradoFiliais(Fact f,int r[]){
	int i=0,tam;
	VendasFact vf = getVendasFact(f);
	tam=getSizeVendasFact(vf);
	FactVal aux;
	while (i<tam)
	{
		aux = getFactVal(vf,i);
		r[getFilialFactVal(aux)-1] = 1;
		i++;
	}
	eliminaVendasFact(vf);
}

void getProdutosNaoCompradosPorFilial(FactTotal cat){
	FactArray fa = getFacts(cat);
	Fact f;
	StringArray r1 = criaStringArray();
	StringArray r2 = criaStringArray();
	StringArray r3 = criaStringArray();
	char * str;
	int comp[3];
	int j,i, tam= getSizeFactArray(fa);
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < 3; j++)
		{
			comp[j]=0;
		}
		
		f = getFactArray(fa,i);
		produtoCompradoFiliais(f,comp);
		if(comp[0]==0)
			r1 = adicionaStringArray(r1,getProdutoFact(f));
		if(comp[1]==0)
			r2 = adicionaStringArray(r2,getProdutoFact(f));
		if(comp[2]==0)
			r3 = adicionaStringArray(r3,getProdutoFact(f));
	}
	tam= getSizeStringArray(r1);
	
	printf("Produtos não comprados Filial 1: %d\n", getSizeFactArray(r1));
	printf("Produtos não comprados Filial 2: %d\n", getSizeFactArray(r2));
	printf("Produtos não comprados Filial 3: %d\n", getSizeFactArray(r3));
	eliminaFactArray(fa);
	eliminaStringArray(r1);
	eliminaStringArray(r2);
	eliminaStringArray(r3);
}

/*query 6*/	

void getClientesQueNaoCompram (Filial f1,Filial f2,Filial f3){
	VendaFilialArray va1 =getVendasFilial(f1);
	VendaFilialArray va2 =getVendasFilial(f2);
	VendaFilialArray va3 =getVendasFilial(f3);
	VendaFilial aux;
	StringArray sa = criaStringArray();
	char* str;
	int i,j,tam= getSizeVendaFilialArray(va1),r[3];
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < 3; j++)
			r[j] = 0;
		aux = getVendaFilialArray(va1,i);
		r[0] = getSizeVendaFilial(aux);
		aux = getVendaFilialArray(va2,i);
		r[1] = getSizeVendaFilial(aux);
		aux = getVendaFilialArray(va3,i);
		r[2] = getSizeVendaFilial(aux);
		if(r[0]==0 && r[1]==0 && r[2]==0)
			adicionaStringArray(sa,getClienteFilial(aux));
	}
	tam = getSizeStringArray(sa);
	
	for(i = 0; i < tam; i++){
    	str = getString(r,i);
       	printf("%s\n",str);
	}
	
	printf("Clientes que não compraram em nenhuma Filial: %d\n",tam);
	eliminaStringArray(sa);
	eliminaVendaFilialArray(va1);
	eliminaVendaFilialArray(va2);
	eliminaVendaFilialArray(va3);
}

void getClientesEProdutosNaoComprados(FactTotal ft,Filial f1,Filial f2,Filial f3){
	getProdutosNaoComprados(ft);
	getClientesQueNaoCompram(f1,f2,f3);
}

/*query 8*/

void factEntreMeses(FactTotal cat, int ini, int fim){
	int vendas=0,i,j,tam;
	double dinheiro=0;
	FactArray fa = getFacts(cat);
	Fact f;
	FactVal fv;
	VendasFact v;
	tam = getSizeFactArray(fa);
	for (i = 0; i <tam; ++i){
		f = getFactArray(fa,i);
		v = getVendasFact(f);
		for (j = 0; j < getSizeVendasFact(v); j++)
		{
			fv = getFactVal(v,j);
			if(getMesFactVal(fv)>= ini && getMesFactVal(fv)<= fim){
				vendas++;
				dinheiro += getQuantidadeFactVal(fv) * getPrecoFactVal(fv);
			}
		}
		eliminaVendasFact(v);
	}
	eliminaFactArray(fa);
	printf("Número de Vendas: %d\n", vendas);
	printf("Faturação Total: %.2f\n", dinheiro);
}

/*query 5*/

void clientesTodasFiliais(Filial f1,Filial f2,Filial f3){
	VendaFilialArray va1 =getVendasFilial(f1);
	VendaFilialArray va2 =getVendasFilial(f2);
	VendaFilialArray va3 =getVendasFilial(f3);
	VendaFilial aux;
	char* str;
	StringArray sa = criaStringArray();
	int i,j,tam= getSizeVendaFilialArray(va1),r[3];
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < 3; j++)
			r[j] = 0;
		aux = getVendaFilialArray(va1,i);
		r[0] = getSizeVendaFilial(aux);
		aux = getVendaFilialArray(va2,i);
		r[1] = getSizeVendaFilial(aux);
		aux = getVendaFilialArray(va3,i);
		r[2] = getSizeVendaFilial(aux);
		if(r[0]>0 && r[1]>0 && r[2]>0)
			adicionaStringArray(sa,getClienteFilial(aux));
	}
	tam = getSizeStringArray(sa);
	
	for(i = 0;i < tam; i++){
    	str = getString(sa,i);
        printf("%s\n",str);
	}
	
	printf("clientes que compraram nas 3 filiais: %d\n",tam);
	eliminaStringArray(sa);
	eliminaVendaFilialArray(va1);
	eliminaVendaFilialArray(va2);
	eliminaVendaFilialArray(va3);
}

/*query 9*/

int modoProdutoVendaFilial(char* prod, VendaFilial vf){
	int r=-1,tam,i;
	ProdutosFilial pf = getProdutosFilial(vf);
	tam = getSizeProdutosFilial(pf);
	ProdutoFilial aux;
	char* str;
	for (i = 0;r==-1 && i < tam; i++)
	{
		aux = getProdutoFilial(pf,i);
		str = getProdutoProdutoFilial(aux);
		if(strcmp(str,prod)==0)
			r = ('P'==getPromoProdutoFilial(aux));
		free(str);
	}
	eliminaProdutosFilial(pf);
	return r;
}

StringArray clientesQueCompraramFilialAux(char* prod, Filial f,int modo[]){
	VendaFilialArray va = getVendasFilial(f);
	VendaFilial vf;
	int promo;
	StringArray r = criaStringArray();
	int i, tam = getSizeVendaFilialArray(va);
	for (i = 0; i < tam; i++)
	{
		vf = getVendaFilialArray(va,i);
		promo = modoProdutoVendaFilial(prod,vf);
		if(promo!=-1){
			adicionaStringArray(r,getClienteFilial(vf));
			modo[promo]++;
		}
	}
	eliminaVendaFilialArray(va);
	return r;
}

void clientesQueCompraramProdutoFilial(int i, char* prod, Filial f1, Filial f2,Filial f3){
	StringArray r;
	int modo[2]={0};
	int j,tam;
	if(i==1)
		r = clientesQueCompraramFilialAux(prod,f1,modo);
	else{
		if(i==2)
			r = clientesQueCompraramFilialAux(prod,f2,modo);
			else
			{
				if(i==3)
					r = clientesQueCompraramFilialAux(prod,f3,modo);
			}
	}
	if(i<=3 && i>=1){
		tam = getSizeStringArray(r);
		printf("{\n");
		for (j = 0; j < tam; j++)
			printf("%s\n",getString(r,j));
		printf("}\n\n");
		printf("Clientes que compraram %s na filial %d[N]: %d\n", prod,i, modo[0]);
		printf("Clientes que compraram %s na filial %d[P]: %d\n", prod,i, modo[1]);
		eliminaStringArray(r);
	}
}

/*query 7*/

void totalProdutosCompradosPorMes(char* cliente, Filial f1, Filial f2, Filial f3){
    int i = 0, mes1[12]={0}, mes2[12]={0}, mes3[12]={0};
    VendaFilial aux1 = getVendaFilial(f1, cliente);
    VendaFilial aux2 = getVendaFilial(f2, cliente);
    VendaFilial aux3 = getVendaFilial(f3, cliente);


    totalProdutosCompradosPorMesAux(aux1, mes1);
    totalProdutosCompradosPorMesAux(aux2, mes2);
    totalProdutosCompradosPorMesAux(aux3, mes3);

    printf("Mês:	 ");
    for ( i = 1; i < 13; ++i){
		printf("	| %d", i);
	}
    printf("\nFilial 1 : ");
    for ( i = 0; i < 12; ++i){
		printf("	| %d", mes1[i]);
	}
	printf("\nFilial 2 : ");
	for ( i = 0; i < 12; ++i){
		printf("	| %d", mes2[i]);
	}
	printf("\nFilial 3 : ");
	for ( i = 0; i < 12; ++i){
		printf("	| %d", mes3[i]);
	}
	printf("\n");
    eliminaVendaFilial(aux1);
    eliminaVendaFilial(aux2);
    eliminaVendaFilial(aux3);
}

void totalProdutosCompradosPorMesAux(VendaFilial vf, int mes[]){
    ProdutosFilial aux = getProdutosFilial(vf);
    ProdutoFilial pf;
    int i, tam = getSizeProdutosFilial(aux), maux = 0, sum = 0;

    for(i = 0; i < tam; ++i){
        pf = getProdutoFilial(aux, i);        
        maux = getMesProdutoFilial(pf);
        sum = getQuantidadeProdutoFilial(pf);
        mes[maux-1] += sum;
    }
	eliminaProdutosFilial(aux);
}