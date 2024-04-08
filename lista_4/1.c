#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 100;

typedef struct Pilha {
    int topo;
    int capacidade;
    int* array;
} Pilha;

Pilha* criarPilha(int capacidade);
int estaCheia(Pilha* pilha);
int estaVazia(Pilha* pilha);
void empilhar(Pilha* pilha, int item);
int desempilhar(Pilha* pilha);
void imprimirPilha(Pilha* pilha);


void main(){
    char valor[MAX];
    Pilha *pilha = criarPilha(MAX);
    int primeiroInt=0, segundoInt=0;
    int resultado =0;


    while (1){
        printf("Digite um Inteiro ou a operacao: (F-fecha, P- imprime a pilha)");
      scanf("%s", valor);

        if(strcmp(valor, "F") == 0) break;
        if(strcmp(valor, "P") == 0) imprimirPilha(pilha);


        char *end;
        int numero = strtol(valor,&end, 10);


        if (!*end) {
            empilhar(pilha, numero);
        } else {
            if(strcmp(valor, "+")==0){
                segundoInt = desempilhar(pilha);
                primeiroInt = desempilhar(pilha);
                if(!estaVazia(pilha)){
                    printf("Expressão incorreta\n");
                }else{
                    resultado = primeiroInt + segundoInt;
                    printf("resutado de %d + %d = %d \n", primeiroInt, segundoInt,resultado);
                    }
            }
            else if (strcmp(valor, "-")==0){
                segundoInt = desempilhar(pilha);
                primeiroInt = desempilhar(pilha);
                if(!estaVazia(pilha)){
                    printf("Expressão incorreta\n");
                }else{
                    resultado = primeiroInt - segundoInt;
                    printf("resutado de %d - %d = %d \n", primeiroInt, segundoInt,resultado);
                    }
            }
            else if (strcmp(valor, "/")==0){
                segundoInt = desempilhar(pilha);
                primeiroInt = desempilhar(pilha);
                if(!estaVazia(pilha)){
                    printf("Expressão incorreta\n");
                }else{
                    resultado = primeiroInt / segundoInt;
                    printf("resutado de %d / %d = %d \n", primeiroInt, segundoInt,resultado);
                    }
            }
            else if (strcmp(valor, "*")==0){
                segundoInt = desempilhar(pilha);
                primeiroInt = desempilhar(pilha);
                if(!estaVazia(pilha)){
                    printf("Expressão incorreta\n");
                }else{
                    resultado = primeiroInt * segundoInt;
                    printf("resutado de %d * %d = %d \n", primeiroInt, segundoInt,resultado);
                    }
            }
    }
    
}
}
Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->array = (int*) malloc(pilha->capacidade * sizeof(int));
    return pilha;
}

int estaCheia(Pilha* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

int estaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha* pilha, int item) {
    if (estaCheia(pilha))
        return;
    pilha->array[++pilha->topo] = item;
}

int desempilhar(Pilha* pilha) {
    if (estaVazia(pilha))
        return 0;
    return pilha->array[pilha->topo--];
}
void imprimirPilha(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha está vazia.\n");
        return;
    }

    printf("Pilha: ");
    for (int i = 0; i <= pilha->topo; i++) {
        printf("%d ", pilha->array[i]);
    }
    printf("\n");
}
