#include <stdio.h>
#define MAX 50

typedef struct{
	int chave;
}tipo_elem;


typedef struct{
	tipo_elem A[MAX];
	int nelem;
}lista;

int criar(lista *l);
int cheia(lista *l);
int vazia(lista *l);
int inserir_ordenado(lista *l,tipo_elem v);
int inserir_inicio(lista *l,tipo_elem v);
int inserir_final(lista *l,tipo_elem v);
int remover_inicio(lista *l);
int remover_final(lista *l);
int remover(lista *l, int chave);
int busca(lista *l,int chave);
int destruir(lista *l);
void exibir(lista *l);
int tamanho(lista *l);
int busca_binaria(lista *l, int chave);
