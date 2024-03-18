#include <stdio.h>

int somaRecursiva(int *vet, int N);

void main(){
    int N=4;
    int vetor[5];
    vetor[0] = 2;
    vetor[1] = 1;
    vetor[2] = 2;
    vetor[3] = 2;
    vetor[4] = 1;

    printf("%d", somaRecursiva(vetor,N));
}

int somaRecursiva(int *vet, int N){
    int soma = 0;
    if(N>=0){
        soma = vet[N];
        soma += somaRecursiva(vet, N-1);
    }

    return soma;
}