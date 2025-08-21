#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool buscafelicidadeMundana(bool riqueza, bool prazer, bool status){
	if(riqueza || prazer || status){
		return false;//sempre insuficiente
	}

	return false;//nunca satisfazer
}


int main(){

	printf("\n ***Programa sobre o padrão do mundo***\n");

	bool temRiqueza = true;
	bool temPrazer = true;
	bool temStatus = true;

	bool encontrouSentido = buscafelicidadeMundana(temRiqueza, temPrazer, temStatus);

	if(!encontrouSentido){
		printf("\n Vazio existencial. O mundo não satisfaz.\n");
	}

	printf("\n É ilusão, é ilusão, diz Sábio. Tudo é ilusão. Ec 1:2");
	printf("\n\n");
	return 0;
}