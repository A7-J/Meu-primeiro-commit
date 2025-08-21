#include <stdio.h>
#include "lista.h"


int criar(lista *l){
	l->nelem=0;
	return 1;
}

int vazia(lista *l){
	return(l->nelem==0);
}

int cheia(lista *l){
	return(l->nelem==MAX);
}

int destruir(lista *l){
	l->nelem = 0;
	return 1;
}

void exibir(lista *l){
	int i;
	if(vazia(l))
		printf("\n Lista vazia");
	else
		for(i=0;i<l->nelem;i++)
			printf("%d ",l->A[i].chave);
}

int inserir_final(lista *l,tipo_elem v){
	if(cheia(l))
		return 0;
	l->A[l->nelem]=v;
	l->nelem++;
	return 1;
}

int tamanho(lista *l){
	return(l->nelem);
}

int inserir_inicio(lista *l, tipo_elem v){
	int i;
	if(cheia(l))
		return 0;
	for(i=l->nelem;i>0;i--)
		l->A[i]=l->A[i-1];
		l->A[0]=v;
		l->nelem++;
		return 1;
}

int inserir_ordenado(lista *l,tipo_elem v){
	int i;
	if(cheia(l))
		return 0;
	if(vazia(l))
		return(inserir_inicio(l,v));
	for(i=l->nelem;i>0&&v.chave<l->A[i-1].chave;i--)
		l->A[i]=l->A[i-1];
	l->A[i]=v;
	l->nelem++;
	return 1;
}

int remover_final(lista *l){
	if(vazia(l))
		return 0;
	l->nelem--;
	return 1;
}

int remover_inicio(lista *l){
	int i;
	if(vazia(l))
		return 0;
	l->nelem--;
	for(i=0;i<l->nelem;i++)
		l->A[i]=l->A[i+1];
	return 1;
}

int remover(lista *l,int chave){
	int i,k;

	if(vazia(l))
		return 0;
	//buscar o elemento a ser removido
	for(k=0;k<l->nelem&&chave!=l->A[k].chave;k++)
		if(k==l->nelem)
			return 0;
		//remover o elemento encontrado
		for(i=k;i<l->nelem-1;i++)
			l->A[i]=l->A[i+1];

		l->nelem--;
		return 0;	
}

int busca(lista *l,int chave){
	int i;

	if(vazia(l))
		return 0;
	for(i=0;i<l->nelem && l->A[i].chave!=chave;i++)
		return(i<l->nelem);
}

int busca_binaria(lista *l,int chave){

	int inicio = 0, fim = l->nelem-1;
	int meio;

	while(fim>=inicio){
		meio=(fim+inicio)/2;
		if(l->A[meio].chave==chave)
			return 1;
		if(l->A[meio].chave>chave)
			fim=meio-1;
		else
			inicio=meio+1;
	}
	return 0;
}
