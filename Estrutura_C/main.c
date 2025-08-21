#include "lista.h"
#include <stdio.h>
#include <stdlib.h>




int main(){
	int op;
	lista l;
	tipo_elem v;
	int chave;
	int achou;

	criar(&l);

	do{
		printf("\n 1 - Inserir-Final");
		printf("\n 2 - exibir");
		printf("\n 3 - Destruir");
		printf("\n 4 - Vazia");
		printf("\n 5 - cheia");
		printf("\n 6 - ordenar");
		printf("\n 7 - Remover final");
		printf("\n 8 - Remover inicio");
		printf("\n 9 - buscar");
		printf("\n 10 - Busca binaria");
		printf("\n 0 - Sair");

		printf("\n Digite a opção:");
		scanf("%d",&op);

		switch(op){
		case 1://Inserir-final
			printf("Digite o valor:");
			scanf("%d",&v.chave);
			if(inserir_final(&l,v))
				printf("\n Elemento inserido com sucesso!");
			else 
			printf("Não foi possivel inserir \n");
			break;
		case 2:// exibir
			exibir(&l);
			break;
		case 3://destruir
			destruir(&l);
			break;
		case 4://vazia
			if(vazia(&l))
				printf("Vazia\n");
			else
				printf("Não esta vazia \n");
			break;
		case 5://cheia
			if(cheia(&l))
				printf("Lista cheia\n");
			else
				printf("Não esta cheia\n");
			break;
		case 6:
			inserir_ordenado(&l,v);
			break;
		case 7:
			remover_final(&l);
			break;
		case 8:
			remover_inicio(&l);
			break;
		case 9:
			printf("\n Digite o numero para busca:");
			scanf("%d",&chave);
			if(busca(&l,chave)){
				printf("\n O numero %d foi encontrado com sucesso",chave);
			}else{
				printf("\n Não foi encontrado");
			}
			break;
		case 10:
			printf("\n Digite o numero para nusca binaria:");
			scanf("%d",&chave);
			if(busca_binaria(&l,chave)){
				printf("\n O numero %d foi encontrado com sucesso",chave);
			}else{
				printf("\n Não foi encontrado");
			}
			break;
		}//end switch
	}while(op!=0);
	destruir(&l);
	return 0;
}
