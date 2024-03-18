#include <stdio.h>

void preencher(int* vet, int N){
    if(N>=0){
        vet[N] = N;
        preencher(vet, N-1);
    }
}

void imprimirCresc(int *vet, int N){
    if(N>=0){
        imprimirCresc(vet, N-1);
        printf("%d ",vet[N]);
    }

}

void imprimirDresc(int *vet, int N){
    if(N>=0){
        printf("%d ",vet[N]);
    }
    imprimirDresc(vet, N-1);
}
void main(){
    int N =5;
    int vetor[N];
    preencher(vetor, N);
    imprimirCresc(vetor, N);
    printf("\n");
    imprimirDresc(vetor, N);
    printf("\n");
}