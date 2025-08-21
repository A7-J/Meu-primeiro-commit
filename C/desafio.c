#include <stdio.h>
#include <stdlib.h>



int main(){
	int x=4,y=7;
	int *px,*py;

	printf("&x = %p\t x = %d",&x,x);
	printf("&y = %p\t y = %d",&y,y);

	px = &x;
	py = &y;

	printf("px = %p\t*px = %d\n",px,*px);
	printf("py = %p\t*py = %d\n",py,*py);
	
	printf("\n");
	return 0;
}

