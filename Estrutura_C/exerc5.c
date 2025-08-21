#include <stdio.h>
#include <stdlib.h>



int main(){
	int *array;
	int i;

	array=(int *)malloc(5 * sizeof(int));
	if(array==NULL){
		printf("\n Erro na alocação de memoria");
		return 1;
	}


	for(i=0;i<5;i++){
		printf("\n Infome um numero %d:",i+1);
		scanf("%d",&array[i]);
	}

	for(i=0;i<5;i++){
		printf("\n O numero que foi digitado na podição %d = %d",i+1,array[i]);
	}

	free(array);

	printf("\n");	
	return 0;
}