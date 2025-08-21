#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TF 100

struct cliente{

	char nome[10];
	int numconta;
	float saldo;
};

void carregar(struct cliente vetor[TF],int &tl){
	tl=0;
	char nome[10];
	int numconta;
	float saldo;
	FILE *arq = fopen("poupanca.txt","r");
	if(arq==NULL)
		printf("\n Não foi encontrado,erro");
	else{
		while(!feof(arq)){
			fscanf(arq,"%d %s %f \n",&numconta,nome,&saldo);
			vetor[tl].numconta=numconta;
			strcpy(vetor[tl].nome,nome);
			vetor[tl].saldo=saldo;
			tl++;
		}
	}
	fclose(arq);
}

int main(){
	struct cliente vetor[TF];
	int opcao=0,posicao;
	int tl=0;
	char nome[10];
	int num;
	float valor;

	while(opcao!=2){
		printf("\n *** Informação do Funcionario ***");
		printf("\n 1 - Leitura do arquivo");
		printf("\n 2 - Sair");

		printf("\n Informe a opção:");
		scanf("%d",&opcao);

		switch(opcao){
		case 1: carregar(vetor,tl);
			printf("\n Vetor carregado com tl=%d clientes",tl);
			break;
		}


	}

	printf("\n");
	return 0;
}