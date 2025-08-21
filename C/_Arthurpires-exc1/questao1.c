#include <stdio.h>


int main(){
	int A,B,C, resultado;

	printf("\n A B C Resultado");

	for(A=0;A<=1;A++){
		for(B=0;B<=1;B++){
			for(C=0;C<=1;C++){
				resultado = !(A&&B) || C;
				printf("\n %d %d %d %d",A,B,C,resultado);
			}
		}
	}

	printf("\n\n");
	return 0;
}