#include <stdio.h>

void par_impar(int num){
	if(num%2==0){
		printf("\n %d é numero par",num);
	}else{
		printf("\n %d é numero impar",num);
	}
}
int main(){
	int num;

	printf("\n Programa que verifica que numero é impar ou par");
	printf("\n Informe um numero:");
	scanf("%d",&num);

	par_impar(num);

	printf("\n\n");
	return 0;
}