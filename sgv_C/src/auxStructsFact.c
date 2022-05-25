#include"../includes/auxStructsFact.h"


FactArray criaFactArray(){
	FactArray r = g_array_new(FALSE,FALSE, sizeof(Fact));
	return r;
}

FactArray adicionaFactArray(FactArray r,  gpointer value ){
	g_array_append_val(r,value);
	return r;
}

int getSizeFactArray(FactArray r){
	return r->len;
}

Fact getFactArray(FactArray r, int idx){
	return g_array_index( r, Fact, idx );
}

void eliminaFactArray(FactArray r){
	int i;
	for (i = 0; i < getSizeFactArray(r); ++i){
		eliminaFact(getFactArray(r,i));
	}
	g_array_free (r,TRUE);
}