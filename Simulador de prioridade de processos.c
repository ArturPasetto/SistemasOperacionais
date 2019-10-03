#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAMANHO 5
#define TAM 100

/*
	0 - Kernel
	1 - Diretor
	2 - Chefe
	3 - Gerente
*/

typedef struct sProcesso{
	char nome[100];
	int prioridade;
	int cont;
} Processo;

int sortearPrioridade(){
	return rand()%4;
}

Processo* criarProcesso(int numero){
	Processo *processo = (Processo*) malloc(sizeof(Processo));
	processo->prioridade=sortearPrioridade();
	
	strcpy(processo->nome,"processo ");
	char x[TAM];
	strcpy(x,itoa(numero,x,10));
	strcat(processo->nome,x);	
	
	processo->cont= 1;
	return processo;
}

Processo* maiorPrioridade(Processo *vetor[TAMANHO]){
	
	Processo *maior = vetor[0];
	int i=0;
	int max=0;
	
	for(i=1;i<TAMANHO;i++){
		if(vetor[i]->prioridade < maior->prioridade){
			maior = vetor[i];
			max=i;
		}
	}
	return maior;
}

int posicaoPrioridade(Processo* lista[TAMANHO], Processo *maior){
	
	int max=0;
	int i=0;
	
	for(i=0;i<TAMANHO;i++){
		if(lista[i]==maior){
			max=i;
		}
	}
	
	return max;
}

void reenfileirarProcesso(Processo *vetor[TAMANHO], int pos){

	int i=0;
	Processo *temp=vetor[pos];
	
	for(i=pos;i<TAMANHO-1;i++){
		vetor[i]=vetor[i+1];
	}
	vetor[4]=temp;
	temp->prioridade++;
	if(temp->prioridade==4){
		temp->prioridade=sortearPrioridade();
	}
}

void processar(Processo* lista[TAMANHO], Processo* proc){
	
	int i=0;
		
	printf("Processamentos\n");
	
	for(i=0;i<TAMANHO;i++){
		printf("%i ",lista[i]->prioridade);
	}
	
	printf("\n\n");
	
	printf("Nome do processo: %s\n",proc->nome);
	printf("Prioridade do processo: %i\n",proc->prioridade);
	printf("Inciando processamento\n\n");
	
	sleep(1);
	
	while(clock()%3000!=0){}
	
	printf("processado\n\n");
	
	printf("\n\n");
}


int main(){
	
	srand(time(NULL));
	
	Processo *lista[TAMANHO];
	Processo *auxiliar;
	Processo *temp;
	
	int i=0;
	int maior=0;
	
	
	for(i=0;i<TAMANHO;i++){
		Processo *temp = criarProcesso(i+1);
		lista[i]=temp;
	}
	
	for(;;){
		
		temp = maiorPrioridade(lista);
		maior = posicaoPrioridade(lista,temp);
		processar(lista,temp);
		
		sleep(1);
		
		reenfileirarProcesso(lista,maior);
	}	
	
	free(lista);
	return 0;
}
