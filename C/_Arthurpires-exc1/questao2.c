#include <stdio.h>
#include <string.h>
#include <ctype.h>


int eh_fbf(char express[]){
	int i,tam = strlen(express);
	if(!isalpha(express[0]) || !isalpha(express[tam-1])) 
		return 0;
	for(i=0;i<tam;i++){
		if(!(isalpha(express[i]) || express[i] == 'e' || express[i] == 'o' || express[i] == 'n'))
			return 0;
		if(isalpha(express[i]) && i<tam-1 && isalpha(express[i+1]))
			return 0;
	}
	return 1;
}

int main(){
	char express[100];
	printf("\n Informe uma expressão lógica usando letra e conectivos (e=AND, o=OR, n=NOT):");
	scanf("%s",express);

	if(eh_fbf(express))
		printf("\n Expressão valida (FBF)");
	else
		printf("\n Expressão invalida");


	printf("\n\n");
	return 0;
}