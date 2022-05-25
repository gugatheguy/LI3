#include "../includes/interface.h"

int main (int argc, char* argv[]){

	if(argc == 2)
		criaInterfaceValgrind();
	else
		criaInterface();
	return 0;

}