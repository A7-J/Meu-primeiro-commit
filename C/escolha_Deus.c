#include <stdio.h>
#include <stdbool.h>

bool buscaSentidoEmDeus(bool cristoNoCentro){
	if(cristoNoCentro){
		return true;
	}
	return false;
}

int main(){

	bool entregouVidaADeus = true;

	if(buscaSentidoEmDeus(entregouVidaADeus)){
		printf("\n Paz, propósito e plenitude encontrados em Deus.");
	}else{
		printf("\n Ainda perdido. Busque a Verdade.");
	}

	printf("\n\n");

	return 0;
}