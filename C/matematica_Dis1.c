#include <stdio.h>


void desafio(){
	char resposta;

	printf("\n Desafio 1: Qual conectivo representa a conjuncao:");
	printf("\n a) v\nb)  ∧\nc) →\nd) ¬");
	printf("Informe a letra correspondente:");
	scanf("%c",&resposta);

	if(resposta == 'b' || resposta == 'B'){
		printf("\n Correto! ∧ representa a conjuncao");
	}else {
		printf("\n Errado. A resposta correta é b) ∧.");
	}
}

void tabelaverdade(){
	int P,Q;
	printf("\nTabela verdade para P ∧ Q:");
	printf("\n P | Q | P∧Q\n");
	for(P = 0;P<=1;P++){
		for(Q = 0;Q<=1;Q++){
			printf("%d | %d | %d\n",P,Q, P && Q);
		}
	} 
}

void argumentoSimples(){
	printf("\n Considere:");
	printf("\n Premissa 1: P → Q\nPremissa 2:\nConclusao: Q");
	printf("Esse argumento eh valido: (s/n):");

	char resposta;
	scanf("%c",&resposta);

	if (resposta == 's' || resposta == 'S'){
		printf("\n Correto! Isso eh Modus Poneus, um argumento válido.");
	}else{
		printf("Errado. Esse eh um argumento valido pela regra di Modus Poneus ");
	}
}

int main(){
	int opcao;

	do{
		printf("\n === Jogo de Logica Formal ===");
		printf("\n 1.Desafio 1 - Conectivos");
		printf("\n 2.Desafio 2 - Tabela Verdade");
		printf("\n 3.Desafio 3 - Validade de argumento");
		printf("\n 4.Sair");

		printf("\n Informe a opcao:");
		scanf("%d", &opcao);

		switch(opcao){
		case 1: desafio();
			break;
		case 2: tabelaverdade();
			break;
		case 3: argumentoSimples();
			break;
		case 4:printf("\n Saindo...");
			break;
		default: printf("Opcao invalida");
		}
	}while(opcao != 4);
	return 0;
}