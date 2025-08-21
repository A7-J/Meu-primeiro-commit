#include <stdio.h>


int main(){
	int num;

	printf("\n Programa que verifica que numero é par ou impar:");
	printf("\n Informe o numero:");
	scanf("%d",&num);

	if(num%2==0){
		printf("\n %d é numero PAR",num);
	}else{
		printf("\n %d é numero é impar",num);
	}

	printf("\n\n");
	return 0;
}