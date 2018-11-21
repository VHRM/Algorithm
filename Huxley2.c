#include <stdio.h>
#include <stdlib.h>

struct lista{
	int id;
	int idade;
	struct lista* prox;
};

typedef struct lista Fila;

Fila* CriaFila(){
	return NULL;
}

Fila* Insere(int ID, int Idade, Fila* Ref){
	Fila* NovaPessoa = (Fila*)malloc(sizeof(Fila));
	Fila* Aux;
	NovaPessoa->id = ID;
	NovaPessoa->idade = Idade;
	if(Ref == NULL){
		NovaPessoa->prox = NovaPessoa;
	}
	else{
		NovaPessoa->prox = Ref->prox;
		Ref->prox = NovaPessoa;
	}

	Ref = NovaPessoa;
	return Ref;
}


Fila* Remove(Fila* Ref){	
	if(Ref == NULL)
		return Ref;

	Fila* Aux = Ref->prox;
	if(Aux == Ref){
		Ref = NULL;
	}
	else{
		Ref->prox = Aux->prox;
	}

	free(Aux);
	return Ref;
}

void Imprime(Fila* Ref){
	Fila* Aux;
	if(Ref == NULL)
		printf("fila vazia!\n");
	else{
		for(Aux = Ref->prox; Aux != Ref; Aux = Aux->prox){
			printf("ID: %d IDADE: %d\n", Aux->id, Aux->idade);
		}
		printf("ID: %d IDADE: %d\n", Ref->id, Ref->idade);
		
	}	
}

int Leitura(){
	int aux;
	aux = getchar();
	while(aux == ' ' || aux == '\n')
		aux = getchar();
	return aux;
}

void Finaliza(Fila* Ref){
	Fila* Aux;
	if(Ref != NULL){
		for(Aux = Ref->prox; Aux != Ref; Aux = Aux->prox){
			free(Aux);
		}
	}
}

int main(int argc, char const *argv[])
{
	int Entrada, n, ID, Idade;
	scanf("%d", &n);
	int contador = n;
	Fila* Idosos = CriaFila();
	Fila* NaoIdosos = CriaFila();
	while((Entrada = Leitura()) != 'f'){
		switch (Entrada){
			case 'a':

				ID = Leitura() - '0';
				scanf("%d", &Idade);
				if(Idade > 60)
					Idosos = Insere(ID, Idade, Idosos);
				else
					NaoIdosos = Insere(ID, Idade, NaoIdosos);

			break;

			case 'r':

				if(contador > 0 && Idosos != NULL){
					Idosos = Remove(Idosos);
					contador--;
				}
				else{													//IDOSO VAZIO OU FIM DA PRIORIRADE
					if(NaoIdosos != NULL)								//JOVEM NAO VAZIO
						NaoIdosos = Remove(NaoIdosos);					//REMOVE JOVEM
					else{												//JOVEM VAZIO
						if(Idosos != NULL)								//IDOSO NAO VAZIO
							Idosos = Remove(Idosos);					//REMOVE IDOSO
					} 													//
					contador = n;										//RESETA CONTADOR
				}

			break;

			case 'i':

				printf("fila de idosos:\n");
				Imprime(Idosos);
				printf("fila de nao-idosos:\n");
				Imprime(NaoIdosos);
				printf("----------\n\n");
		}
	}

	Finaliza(Idosos);
	Finaliza(NaoIdosos);
	return 0;
}






