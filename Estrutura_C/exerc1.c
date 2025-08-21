#include <stdio.h>



int main(){
	int x=10, y=20;
	int *px,*py;

	px=&x;
	py=&y;
	printf("\nO endereço do Px = %p",px);
	printf("\nO endereço do Py = %p",py);

	if(px>py){
		printf("\n Px é maior do que Py");
	}else{
		printf("\n Py é maior do que Px");
	}

	printf("\n");
	return 0;
}