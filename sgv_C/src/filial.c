#include "../includes/filial.h"

struct filial{
    GTree* catFilial;
};

static int comparaVendaFilial(gconstpointer c1, gconstpointer c2){
	char* codc1 = getClienteFilial((VendaFilial) c1);
	char* codc2 = getClienteFilial((VendaFilial) c2);
	int r = strcmp(codc1, codc2);
	free(codc1);
	free(codc2);
	return r;
}

Filial criaFilial(){
    Filial f = malloc (sizeof(struct filial));
    f->catFilial = g_tree_new_full(comparaVendaFilial, NULL, NULL, eliminaVendaFilial);
    return f;
}

void stringArrayToFilial(StringArray s, Filial f1, Filial f2, Filial f3){
    int i=0, tam = getSizeStringArray(s);
    VendaFilial v1,v2,v3;
    while ( i < tam){
        v1 = criaVendaFilial(getString(s,i));
        v2 = criaVendaFilial(getString(s,i));
        v3 = criaVendaFilial(getString(s,i));
        insereVendaFilial(f1, v1);
        insereVendaFilial(f2, v2);
        insereVendaFilial(f3, v3);
        ++i;
    }
}

int existeVendaFilial(Filial f, char* str){
	VendaFilial c = criaVendaFilial(str);
	char* key = g_tree_lookup(f->catFilial, c);
	eliminaVendaFilial(c);
	int r = key!=NULL;
	return r;
}

void eliminaFilial(Filial f){
    g_tree_destroy(f->catFilial);
    free (f);
}

void insereVendaFilial(Filial f,VendaFilial vf){
    g_tree_insert(f->catFilial, vf, vf);
}

void adicionaVendaFilial(Filial f, VendaFilial vf){
    appendVendaFilial(g_tree_lookup(f->catFilial, vf), vf);
}

VendaFilial getVendaFilial(Filial f, char* str){
    VendaFilial aux1 = criaVendaFilial(str);
    VendaFilial aux2 = (VendaFilial) g_tree_lookup(f->catFilial, aux1);
    eliminaVendaFilial(aux1);
    aux1 = clonaVendaFilial(aux2);
    return aux1;
}

static int treeToVendaFilialArray(gpointer key, gpointer value, gpointer data){
    VendaFilial v = (VendaFilial) value;
    VendaFilial r = clonaVendaFilial(v);
    adicionaVendaFilialArray (data, r);
    return FALSE;
}

VendaFilialArray getVendasFilial(Filial f){
    VendaFilialArray r = criaVendaFilialArray();
    g_tree_foreach(f->catFilial, treeToVendaFilialArray, r);
    return r;
}

int getSizeFilial(Filial f){
    return g_tree_nnodes(f->catFilial);
}