#include <stdio.h>
#include <stdlib.h>
int Tamanho;

// typedef struct lista {
// 	int data;
// 	struct lista* prox;
// } Lista;

typedef struct hash{
	int data;
	struct* proximo;
	struct* anterior;
} Hash;

int Leitura(){
	int aux;
	aux = getchar();
	while(aux == ' ' || aux == '\n'){
		aux = getchar();
	}
	return aux;
}

int hashing(int k){
	return numero % tamanho;
}


void insere(Hash* tabela[], int k){
	int p = hashing(k);
	hash* novo = (Hash*)malloc(sizeof(Hash));
	novo->proximo = tabela[p];
	novo->data = k;
	tabela[p]
}
