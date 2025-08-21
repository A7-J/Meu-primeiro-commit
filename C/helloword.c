#include <stdio.h>
#include <stdlib.h>

 	 

int main(){
	int *v, i=0,n=0;
	v = (int *)malloc(sizeof(int));

	while(1){
		printf("Digite(-1 para sair):");
		n++;
		v = (int *)realloc(v,n*sizeof(int));
		scanf("%d",&v[n-1]);
		if(v[n-1]<0)
		break;
	}
	v = (int *)realloc(v,(n-1)*sizeof(int));
	for(i=0;i<n-1;i++)
		printf("%d",v[i]);
	free(v);

	printf("\n\n");
	return 0;
}