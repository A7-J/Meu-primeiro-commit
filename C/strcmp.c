#include <stdio.h>
#include <string.h>


int main(){

    char str1[]= "Arthur";
    char str2[]= "Pires";

    int result = strcmp(str1,str2);

    printf("\n strcmp %s %s = %d ",str1,str2,result);

    printf("\n");
    return 0;
}