#include"../includes/auxStructsVendaFilial.h"


VendaFilialArray criaVendaFilialArray(){
	VendaFilialArray r = g_array_new(FALSE, FALSE, sizeof(VendaFilial));
	return r;
}

VendaFilialArray adicionaVendaFilialArray(VendaFilialArray r, gpointer value){
	g_array_append_val(r, value);
	return r;
}

int getSizeVendaFilialArray(VendaFilialArray r){
	return r->len;
}

VendaFilial getVendaFilialArray(VendaFilialArray r, int idx){
	return g_array_index(r, VendaFilial, idx);
}

void eliminaVendaFilialArray(VendaFilialArray r){
	int i = 0;
	while( i < getSizeVendaFilialArray(r)){
		eliminaVendaFilial(getVendaFilialArray(r, i));
		++i;
	}
	g_array_free(r, TRUE);
}