#include<stdio.h>
#include<string.h>
struct cliente{
        int numconta;
        char nome[10];
        float saldo;
};
void carrega(struct cliente vetor[100],int &tl){
	tl=0;
	char nome[10];
	int numconta;
	float saldo;
	FILE *arq = fopen("poupanca.txt", "r");
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else  {
			while( !feof(arq) ){
			     fscanf(arq,"%d %s %f\n",&numconta,nome,&saldo);
			     vetor[tl].numconta=numconta;
			     strcpy(vetor[tl].nome,nome);
			     vetor[tl].saldo = saldo;
			     tl++;
          }
	    fclose(arq);
	}
}
void exibe(struct cliente vetor[100], int tl){
    int i;
    printf("\nLista de Clientes com Poupanca no VETOR");
    for (i=0;i<tl;i++)
       printf("\nPosicao:%d  Nro:%d Nome=%s Saldo:$%5.2f",i,vetor[i].numconta,vetor[i].nome,vetor[i].saldo);   
}
void regravar(struct cliente vetor[100], int tl){
	FILE *arq = fopen("poupanca.txt","w");
	int i;
	for (i=0;i<tl;i++)
	   fprintf(arq,"%d %s %f\n",vetor[i].numconta,vetor[i].nome,vetor[i].saldo);
	fclose(arq); 
	printf("\n Regravado o arquivo texto POUPANCA.TXT");  
}

main(){
	int opcao=0;
	struct cliente vetor[100];
	// uma unica posição do vetor tem numconta, nome, saldo
	int tl=0, posicao;
	char nome[10];
	int numero;
	float valor;
	while (opcao!=9){
		printf("\n\n1 - Leitura do arquivo texto para carregar o vetor");
		printf("\n2 - Exibe o vetor na memoria principal");
		printf("\n3 - Consulta um cliente (busca) no vetor");
		printf("\n4 - Inclusao de um novo cliente no vetor - memoria principal");
		printf("\n5 - Remocao de um cliente no vetor");
		printf("\n6 - Regravar o arquivo texto- grava no HD ");
		printf("\n7 - Deposito em conta");
		printf("\n8 - retirada /saque de conta");
		printf("\n9 - Sair");
		printf("\n Opcao:"); scanf("%d",&opcao);
		switch (opcao) {
			case 1: carrega(vetor,tl);
			        printf("\nVetor carregado com tl=%d clientes", tl);
			        break;
			case 2: exibe(vetor,tl);
			        break; 
			case 3: printf("\n Entre com o numero da conta a ser procurado: ");
			        scanf("%d",&numero);
					posicao = busca(vetor, tl, numero);
					if (posicao==-1)
					   printf("\n Nao encontrou");
					   else printf("\n Encontrou na posicao:%d conta:%d nome:%s saldo:$%5.2f",posicao,numero,
					                                                      vetor[posicao].nome,vetor[posicao].saldo);
					break;
			case 4: inclusao(vetor,tl);
			        break;
			case 5: printf("\n faca voce a remocao como exercicio");
			        break;        
			case 6: regravar(vetor,tl);
			        break;
			case 7: printf("\n Entre com o numero da conta para o deposito: ");
			        scanf("%d",&numero);
					posicao = busca(vetor, tl, numero);
					if (posicao==-1)
					   printf("\n Nao encontrou");
					   else { // encontrou a conta para deposito na posicao
					   	   printf("\nQual o valor a ser depositado?");
					   	   scanf("%f",&valor);
					   	   vetor[posicao].saldo = vetor[posicao].saldo + valor;
					   	   printf("\nDeposito realizado com sucesso conta:%d cliente:%s novo saldo:$%5.2f",
							                         vetor[posicao].numconta, vetor[posicao].nome,vetor[posicao].saldo);
					   }
					break;   				   		       
		}
		
	}
}
