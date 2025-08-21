#include <stdio.h>


int main(){
	int vetor[] = {1,2,3,4,5};
	int tl = 5;
	int *p = vetor + (tl - 1);

	for(int i=0;i<tl;i++){
		printf(" %d",*p);
		p--;
	}

	printf("\n");
	return 0;
}