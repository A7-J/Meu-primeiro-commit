#include <stdio.h>
#include <math.h>

long fatorial(long numero){
	long fato = 1;
	int i;
	for(i=numero;i>1;i--){
		fato=fato * i;
	}

	return fato;

}
long fatorialrecuns(long numero){
	if(numero<=1)
		return 1;
	else 
	return numero * fatorialrecuns(numero -1);
}
int main(){
	long n=5;
	printf("\n Fatorial de %ld=%ld",n,fatorial(n));
	printf("\n Fatorial recuns de %ld=%ld",n,fatorialrecuns(n));

	printf("\n\n");
	return 0;
}