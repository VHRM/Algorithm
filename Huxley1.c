#include <stdio.h>
#include <stdlib.h>

struct lista {
	int data;
	struct lista* next;
};

typedef struct lista Lista;

Lista* NovaLista(){
	return NULL;
}

Lista* Insere(int Data, Lista* Ref){
	Lista* NovoBloco = (Lista*)malloc(sizeof(Lista));
	NovoBloco->data = Data;
	NovoBloco->next = Ref;
	Ref = NovoBloco;
	return Ref;
}

Lista* Soma(Lista* Ref1, Lista* Ref2, Lista* Resultado){
	Lista* Aux1 = Ref1;
	Lista* Aux2 = Ref2;
	int carry = 0;
	int soma = 0;
	while(Aux1 != NULL || Aux2 != NULL){
		if(Aux1 == NULL)
			soma = Aux2->data + carry;
	
		else if(Aux2 == NULL)
			soma = Aux1->data + carry;

		else
			soma = Aux1->data + Aux2->data + carry;
		

		if(soma > 9){
			carry = 1;
			soma = soma - 10;
		}
		else
			carry = 0;
		Resultado = Insere(soma, Resultado);
		Aux1 = Aux1->next;
		Aux2 = Aux2->next;
	}

	return Resultado;
}

Lista* ZeroEsquerda(Lista* Ref){
	Lista* Aux;
	if(Ref->data == 0){
		for(Aux = Ref; Aux->data != 0 || Aux != NULL; Aux = Aux->next);
	}
	return Aux;
}

void Imprime(Lista* Ref){
	Lista* Aux;
	
	if(Ref->data == 0)
		for(Aux = Ref; Aux->data != 0 && Aux != NULL; Aux = Aux->next);
	
	for(Aux; Aux != NULL; Aux = Aux->next){
	printf("%d ", Aux->data);
	}
}

int Leitura(){
	int aux;
	aux = getchar();
	while(aux == ' ' || aux == '\n'){
		aux = getchar();
	}
	return aux;
}

int main(int argc, char const *argv[])
{
	Lista* A = NovaLista();
	Lista* B = NovaLista();
	Lista* C = NovaLista();
	int c;
	while((c = Leitura()) != '+'){
		A = Insere((c - '0'), A);
	}
	//Imprime(A);
	while((c = Leitura()) != '='){
		B = Insere((c - '0'), B);
	}
	//Imprime(B);
	C = Soma(A, B, C);
	Imprime(C);
	getchar();
	return 0;
}