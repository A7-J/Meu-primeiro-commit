#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define TF 10
#define MAX 999


void criar(int vetor[TF]){
	for(int i=0;i<TF;i++){
		vetor[i]=rand() % MAX;
	}
}

void exibir(int vetor[TF]){
	for(int i=0;i<TF;i++){
		printf("[%d]",vetor[i]);
	}
}
void ordena(int vetor[TF]){
	int fim,i,j,aux;
	for(fim=TF-1;fim > 0;i--){
		for(j=0;j<TF;j++){
			if(vetor[j]>vetor[j+1]){
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
			}
		}
	}
}
int buscaBinanria(int vetor[TF],int numprocurado){
	int inicio=0;int fim = TF-1;
	int meio=(inicio+fim)/2;
	while(inicio<fim)&&(numprocurado!=vetor[meio]){
		if(numprocurado>vetor[meio])
			inicio-meio+1;
		else fim=meio;
		meio=(inicio+fim)/2;
	}

	return meio;
}

int main(){
	int vetor[TF];
	int opcao=0,posicao=-1,numprocurado;
	bool ordenado=false;

	while(opcao!=7){
		printf("\n 1- Criar:");
		printf("\n 2- Exibir:");
		printf("\n 3- Ordena o vetor:");
		printf("\n 4- Busca exautiva-vetor des:");
		printf("\n 5- Busca sequecial- Vetor ordenado:");
		printf("\n 6- Busca binaria- Vetor ordenado:");
		printf("\n 7- Sair:");

		switch(opcao){
		case 1:printf("\n Criado com sucesso");
			criar(vetor);
			break;
		case 2:printf("\n Exibir os vetores:");
			exibir(vetor);
			break;
		}
		case 3:
			ordena(vetor);
			break;
		case 4:
			break;
		case 5:
			printf("\n Ente com vetor:");
			scanf("%d",&numprocurado);
			if(ordenado){
				posicao=buscaSequencial(vetor,numprocurado);
				if(vetor[posicao]==numprocurado)&&(posicao<TF)
					printf("\n Encontrou na posicao %d",posicao);
				else printf("\n Posição ideal para inserir %d",posicao);
			}else printf("\n Vetor não ordenado");
			break;
		case 6: printf("\n Informe o numero:");
			scanf("%d",&numprocurado);
			if(ordenado){
				posicao=buscaBinanria(vetor,numprocurado);
				if(vetor[posicao]==numprocurado)&&(posicao<TF)
					printf("\n Encontrou na posicao %d",posicao);
				else printf("\n Posiçãoideal para inserir %d",posicao);
			}else printf("\n Vetor não ordenado");
			break;
	}
	printf("\n\n");
	return 0;
}