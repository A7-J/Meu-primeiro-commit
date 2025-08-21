#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
	char nome[10];
	float nota1,nota2,media;
}Aluno;

float calculo_media(float n1,float n2){
	return (n1+n2)/2;
}

void salvarEmArquivo(Aluno aluno[],int qtd,const char* nomeArquivo){
	FILE *arquivo = fopen(nomeArquivo,"w");
	if(arquivo == NULL){
		printf("\n Erro de arquivo");
		return;
	}

	fprintf(arquivo,"*** Relatorio de Aluno ***\n");
	for(int i=0;i<qtd;i++){
		fprintf(arquivo,"\n Aluno: %s \n",aluno[i].nome);
		fprintf(arquivo,"\n Notas: %f %f \n",aluno[i].nota1,aluno[i].nota2);
		fprintf(arquivo,"\n Media: %f \n",aluno[i].media);
	}

	fclose(arquivo);
	printf("\n Dados salvo com sucesso %s",nomeArquivo);
}

int cadastrarAluno(Aluno aluno[]){
	int qtd;

	printf("\n Informe a quantidade de Aluno:");
	scanf("%d",&qtd);

	if(qtd>MAX){
		printf("\n Ultrapassou numero de Aluno");
		return 0;
	}

	for(int i;i<qtd;i++){
		printf("\n *** Aluno %d ***",i++);
		printf("\n Informe o nome do aluno:");
		scanf("%s",aluno[i].nome);
		printf("\n Nota 1:");
		scanf("%f",&aluno[i].nota1);
		printf("\n Nota 2:");
		scanf("%f",&aluno[i].nota2);
		calculo_media(aluno[i].nota1,aluno[i].nota2);

	}
	return qtd;
}

int main(){
	Aluno aluno[MAX];
	int quantidade;

	quantidade = cadastrarAluno(aluno);

	if(quantidade>0){
		salvarEmArquivo(aluno, quantidade, "aluno.txt");
	}

	printf("\n\n");

	return 0;
}