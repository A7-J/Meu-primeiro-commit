#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Comodo{
	char nome[50];
	char lembranca[100];
	struct Comodo* proximo;

}Comodo;

Comodo* criarComodo(char nome[], char lembranca[]){
	Comodo* novo = (Comodo*) malloc(sizeof(Comodo));
	strcpy(novo->nome,nome);
	strcpy(novo->lembranca,lembranca);
	novo->proximo = NULL;
	return novo;
}

void adicionarComodo(Comodo** inicio){
	char nome[50], lembranca[100];
	int c;

	while ((c = getchar()) != '\n' && c != EOF);
	printf("Nome do cômodo: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome,"\n")] = 0;

	printf("Lembraça associada: ");
	fgets(lembranca, sizeof(lembranca),stdin);
	lembranca[strcspn(lembranca, "\n")] = 0;

	Comodo* novo = criarComodo(nome,lembranca);

	if(*inicio==NULL){
		*inicio=novo;
	}else{
		Comodo* atual=*inicio;
		while(atual->proximo!=NULL)
			atual=atual->proximo;
		atual->proximo=novo;
	}

	printf("\n cômodo adicionado com sucesso!");
}

void visitaPalacio(Comodo* inicio){
	if(inicio==NULL){
		printf("\n Palácio vazio!");
		return;
	}
	Comodo* atual = inicio;
	while(atual != NULL){
		printf("\n Você está em: %s\n",atual->nome);
		printf("Lembraça: %s",atual->lembranca);
		atual=atual->proximo;
	}
}

void salvarPalacio(Comodo* inicio){

	FILE* arquivo = fopen("palacio_memoria.txt","w");
	if(!arquivo){
		printf("\n Erro em salvar.");
		return;
	}

	Comodo* atual = inicio;
	while(atual != NULL){
		fprintf(arquivo,"%s|%s\n",atual->nome,atual->lembranca);
		atual=atual->proximo;
	}

	fclose(arquivo);
	printf("\n Palacio salvo em 'palacio_memoria.txt'.");
}

void carregarPalacio(Comodo** inicio){
	FILE* arquivo=fopen("palacio_memoria.txt","r");
	if(!arquivo){
		printf("\n Nenhum Palácio salvo encontrado.");
		return;
	}

	char linha[200],nome[50],lembranca[100];
	while(fgets(linha, sizeof(linha), arquivo)){
		sscanf(linha,"%[^|]|%[^\n]",nome,lembranca);
		Comodo* novo = criarComodo(nome,lembranca);

		if(*inicio==NULL)
			*inicio=novo;
		else{
			Comodo* atual = *inicio;
			while(atual->proximo!=NULL)
				atual=atual->proximo;
			atual->proximo=novo;
		}
	}

	fclose(arquivo); 
	printf("\n Palácio carregado com sucesso!");
}

void liberarPalacio(Comodo* inicio){
	while(inicio != NULL){
		Comodo* temp = inicio;
		inicio = inicio->proximo;
		free(temp);
	}
}

int main(){
	Comodo* palacio = NULL;
	int opcao;

	carregarPalacio(&palacio);

	do{
		printf("\n *** Palácio da Memória ***\n");
		printf("\n 1 - Adicionar cômodo");
		printf("\n 2 - Visitar Palácio");
		printf("\n 3 - Salvar Palácio");
		printf("\n 4 - Sair");

		printf("\n Informe a opção:");
		scanf("%d",&opcao);

		switch(opcao){
		case 1:
			adicionarComodo(&palacio);
			break;
		case 2:
			visitaPalacio(palacio);
			break;
		case 3:
			salvarPalacio(palacio);
			break;
		case 4:
			salvarPalacio(palacio);
			liberarPalacio(palacio);
			printf("\n Saindo e salvando...");
			break;
		default:
			printf("\n opção invalida");
		}
	}while(opcao != 4);

	printf("\n\n");
	return 0;
	
}