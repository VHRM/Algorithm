#include <stdio.h>
#include <stdlib.h>
int tamanho;

// typedef struct lista {
// 	int data;
// 	struct lista* prox;
// } Lista;

typedef struct hash{
	int data;
	struct hash* proximo;
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
	return k % tamanho;
}


void insere(Hash* tabela[], int k){
	int p = hashing(k);
	Hash* aux = tabela[p];
	Hash* anterior=aux;
	Hash* novo = (Hash*)malloc(sizeof(Hash));
	if(tabela[p] == NULL){
		tabela[p]=novo;
		novo->proximo = NULL;
	}
	else{
		while(aux->data < k && aux->proximo != NULL){
			anterior = aux;
			aux = aux->proximo;
		}
		if(aux = anterior){
			novo->proximo = tabela[p];
			tabela[p] = novo;
		}
		else{
			if(aux->proximo == NULL){
				aux->proximo = novo;
				novo->proximo = NULL;
			}
			else{
				novo->proximo = aux;
				anterior->proximo = novo;
			}
		}
	}

	novo->data = k;
}

int remover(Hash* tabela[], int k){
	int p = hashing(k);
	Hash* aux = tabela[p];
	Hash* anterior = aux;
	while(aux->data != k && aux->proximo != NULL){
		anterior = aux;
		aux = aux->proximo;
	}

	if(aux->data == k)
	{
		if(anterior == aux){
			tabela[p] = aux->proximo;
		}
		else{
		anterior->proximo = aux->proximo;
		free(aux);
		}
		return 1;
	}
	return 0;
}

void procurar(Hash* tabela[], int k, int qtd){
	int counter = 0;
	int p = hashing(k);
	Hash* aux = tabela[p];
	Hash* anterior;
	printf("BUSCA POR %d\n", k);
	printf("numero de elementos da tabela hash: %d\n", qtd);
	if(aux == NULL){
		printf("elemento nao encontrado!\n");
		return;
	}
	while(aux->data != k && aux->proximo != NULL){
		anterior = aux;
		aux = aux->proximo;
		counter++;
	}
	if(aux->data == k)
		printf("elemento %d encontrado!\n", k);
	else
		printf("elemento nao encontrado!\n");
	
	printf("numero de elementos acessados na tabela hash: %d\n", counter);
	counter = 0;
}

void imprimir(Hash* tabela[]){
	printf("imprimindo tabela hash:\n");
	Hash* aux;
	for(int i = 0; i < tamanho; i++){
		aux = tabela[i];
		printf("[%d]:", i);
		if(tabela[i] == NULL){
			printf("Lista vazia!\n");
		}
		else{
			while(aux->proximo != NULL){
				printf("%d=>", aux->data);
				aux=aux->proximo;
			}
			printf("%d=>\n", aux->data);
		}
	}
}

void inicia(Hash* tabela[]){
	for(int i = 0; i < tamanho; i++){
		tabela[i] = NULL;
	}
}

int main(){
	scanf("%d", &tamanho);
	int Entrada, k, counter = 0;
	Hash* tabela[tamanho];
	inicia(tabela);
	while((Entrada = Leitura()) != 'f'){
		switch(Entrada){
			case 'a':
				scanf("%d", &k);
				insere(tabela, k);
				counter++;
			break;
			case 'r':
				scanf("%d", &k);
				if(remover(tabela, k) == 1)
				counter--;
			break;
			case 'i':
				imprimir(tabela);
			break;
			case 'p':
				scanf("%d", &k);
				procurar(tabela, k, counter);

			break;
		}
	}

	return 0;
}
