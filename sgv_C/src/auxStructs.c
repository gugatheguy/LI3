#include"../includes/auxStructs.h"


StringArray criaStringArray(){
	StringArray r = g_array_new(FALSE,FALSE, sizeof(char*));
	return r;
}

StringArray adicionaStringArray(StringArray r,  gpointer value ){
	g_array_append_val(r,value);
	return r;
}

int getSizeStringArray(StringArray r){
	return r->len;
}

char* getString(StringArray r, int idx){
	return g_array_index( r, char*, idx );
}

void eliminaStringArray(StringArray r){
	int i;
	for (i = 0; i < getSizeStringArray(r); ++i){
		free(g_array_index(r,char*, i));
	}
	g_array_free (r,TRUE);
}