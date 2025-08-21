#include <stdio.h>
#include <stdlib.h>



int main(){
	int *vetor=NULL;
	int tl=0;
	int num;

	
	while(1){
		printf("\nInforme números inteiros (-1 para sair):");
		scanf("%d",&num);

		if(num<0){
			break;
		}

		tl++;

		vetor=(int *)realloc(vetor,tl * sizeof(int));
		if(vetor==NULL){
			printf("\n Erro na realocação de memoria");
			return 1;
		}
		vetor[tl-1]=num;
	}

	for(int i=0;i<tl;i++){
		printf("\n vetor lido %d: %d",i+1,vetor[i]);
	}

	free(vetor);

	printf("\n");
	return 0;
}