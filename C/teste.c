#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct funcionario{
	char nome[10];
	float salario;
	int idade;
};
int carregar(struct funcionario vetor[]){
	int i=0;

	FILE *arq = fopen("empresa.txt","r");

	if(arq==NULL){
		printf("\n Erro no arquivo");
		return 0;
	}
		while(fscanf(arq,"%s %f %d",vetor[i].nome,&vetor[i].salario,&vetor[i].idade)==3){
		i++;
	   }
	fclose(arq);
	return i;
}
int incluir(struct funcionario vetor[],int tl){
	int i;
	int num;
	printf("\n Quantos funcionario desejar incluir:");
	scanf("%d",&num);
	for(i=tl;i<tl+num;i++){
		if(tl + num > 10){
			printf("\n Ta cheio");
			break;
		}
		printf("\n Informe o nome:");
		scanf("%s",vetor[i].nome);
		printf("\n Informe o salario:");
		scanf("%f",&vetor[i].salario);
		printf("\n Informe a idade:");
		scanf("%d",&vetor[i].idade);
	}
	return tl;
}
void busca(struct funcionario vetor[],char nome[],int tl){
	int i=0;
	int encontrado=0;
	for(i=0;i<tl;i++){
		if(strcmp(vetor[i].nome,nome)==0){
			printf("\n Foi encontrado o nome:");
			printf("\n %d Nome:%s Salario:%.2f Idade:%d \n",i+1,vetor[i].nome,vetor[i].salario,vetor[i].idade);
			encontrado = 1;
			break;
		}
	}
	if(encontrado==0){
		printf("\n Não foi encontrado");
	}
}

void exibir(struct funcionario vetor[],int tl){
	int i;

	for(i=0;i<tl;i++){
		printf("\n Posição:%d Nome:%s Salario:%.2f Idade:%d",i+1,vetor[i].nome,vetor[i].salario,vetor[i].idade);
	}
}

void regravar(struct funcionario vetor[],int tl){
	int i;

	FILE *arq= fopen("empresa.txt","w");
	if(arq==NULL){
		printf("\n Erro de arquivo:");
		return;
	}else{
		for(i=0;i<tl;i++){
			fprintf(arq,"%s %.2f %d \n",vetor[i].nome,vetor[i].salario,vetor[i].idade);
		}
	}

	fclose(arq);
}

int remover(struct funcionario vetor[],char nome[],int tl){
	int i,j;
	int encontrado=0;

	for(i=0;i<tl;i++){
		if(strcmp(vetor[i].nome,nome)== 0){
			encontrado = 1;
			break;
		}
	}

	if(encontrado){
		printf("\n funcionario %s encontrado na posição %d removendo",nome,i);
		for(j=i;j<tl-1;j++){
			vetor[j]=vetor[j+1];
		}
		tl--;
		printf("\n Remoção concluida com sucesso");
	}else{
		printf("\n Funcionario com nome %s não foi encontrado ",nome);
	}
	return tl;
}
int main(){
	struct funcionario vetor[10];
	int i;
	char nome[10];
	int tl;
	int opc;

	while(opc!=7){
		printf("\n 1-Leitura do arquivo texto para carregar o vetor:");
		printf("\n 2-Exibir o vetor:");
		printf("\n 3-Consulta um funcionario(busca)");
		printf("\n 4-Inclusão de um novo funcionario");
		printf("\n 5-Remoção de um funcionario no vetor");
		printf("\n 6-Regravar e exibir o arquivo texto atualizado");
		printf("\n 7-Sair");
		printf("\n Informe a opção:");
		scanf("%d",&opc);

		switch(opc){
		case 1:tl = carregar(vetor);
			printf("\n Carregado para memoria principal com sucesso");
			break;
		case 2:exibir(vetor,tl);
		    break;
		case 3:printf("\n Infome o nome para buscar:");
	        scanf("%s",nome);
	        busca(vetor,nome,tl);
			break;
		case 4:tl=incluir(vetor,tl);
			exibir(vetor,tl);
			break;
		case 5:printf("\n Informe o nome para ser removido:");
			scanf("%s",nome);
			tl=remover(vetor,nome,tl);
			break;
		case 6:regravar(vetor,tl);
			printf("\n Salvou no arquivo com sucesso");
			break;
		case 7:printf("\n Saindo...");
			break;
		}
	}
	

	printf("\n");
	return 0;
}