#include <stdio.h>

void VetDecrescente(char *vet, int N);

void main(){
    char* vetor = "teste";
    VetDecrescente(vetor,5);
}

void VetDecrescente(char *vet, int N){
    if(N >=0){
        printf("%c ", vet[N]);
        VetDecrescente(vet, N-1);
    }
}