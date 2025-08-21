#include <stdio.h>


int main(){
	float vetor[10];
	int i;

	for(i=0;i<10;i++){
		printf("\n O endereço do %d = %p",i,&vetor[i]);
	}

	printf("\n");
	return 0;
}