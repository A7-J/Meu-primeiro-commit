#include <stdio.h>
#include <stdlib.h>

struct Aluno{
	char sobrenome[10];
	int matricula;
	int ano_nasc;
};


int main(){
	struct Aluno *aluno;
	int tl;

	printf("\n Informe quantos alunos para cadastro:");
	scanf("%d",&tl);

	aluno=(struct Aluno *)malloc(tl * sizeof(struct Aluno));
	if(aluno==NULL){
		printf("\n Erro na elocação da memoria");
		return 1;
	}

	


	printf("\n");
	return 0;
}