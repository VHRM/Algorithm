#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
	
	char info;

	struct arvore* esquerda;
	struct arvore* direita;

} Arvore;

Arvore* Cria(char info, Arvore* esquerda, Arvore* direita){ 
	
	Arvore* nova = (Arvore*)malloc(sizeof(Arvore));

	nova->info = info;
	nova->esquerda = esquerda;
	nova->direita = direita;

	return nova;
}

int Vazia(Arvore* raiz){

	return raiz == NULL;
}

void Libera(Arvore** raiz){
	if(!Vazia(*raiz)){
		Libera(&((*raiz)->esquerda));
		Libera(&((*raiz)->direita));
		free(*raiz);
		*raiz = NULL;
	}

}

void PreOrdem(Arvore* raiz){
	if(!Vazia(raiz)){
		printf("%c \n",raiz->info);
		PreOrdem(raiz->esquerda);
		PreOrdem(raiz->direita);
	}
}

void EmOrdem(Arvore* raiz){
	if(!Vazia(raiz)){
		EmOrdem(raiz->esquerda);
		printf("%c \n",raiz->info);
		EmOrdem(raiz->direita);
	}
}

void PosOrdem(Arvore* raiz){
	if(!Vazia(raiz)){
		PosOrdem(raiz->esquerda);
		PosOrdem(raiz->direita);
		printf("%c \n",raiz->info);
	}
}


int main(int argc, char const *argv[])
{
	Arvore* a = Cria('a', NULL, NULL);
	Arvore* b = Cria('b', NULL, NULL);
	Arvore* c = Cria('c', a, b);
	Arvore* d = Cria('d', NULL, NULL);
	Arvore* e = Cria('e', NULL, NULL);
	Arvore* f = Cria('f', d, e);
	Arvore* g = Cria('g', c, f);
	Arvore* h = Cria('h', g, NULL);
	Arvore* i = Cria('i', NULL, NULL);
	Arvore* j = Cria('j', NULL, i);
	Arvore* k = Cria('k', j, h);

	system("cls");
	printf("\nPre-Ordem: \n");
	PreOrdem(k);
	printf("\nEm-Ordem: \n");
	EmOrdem(k);
	printf("Pos-Ordem: \n");
	PosOrdem(k);
	system("pause");
	Libera(&k);
	system("shutdown -r");
	return 0;
}