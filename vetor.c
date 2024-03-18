#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int N);

float *preencher(int N);
float maior(float *vet,int N);
float menor(float *vet,int N);
float media(float *vet, int N);

void main(){
    int N=5;
    float *vet = preencher(N);
    int neg = negativos(vet,N);
    float max = maior(vet,N);
    float min= menor(vet,N);
    float med = media(vet, N);
    for(int i=0; i<N; i++){
        float j = vet[i];
        printf("%.2f ", j);  
    }

    printf("\n Negativos: %d\n maior: %.2f\n menor: %.2f\n media: %.2f.\n", neg, max, min, med);
    free(vet);
}

//1.1

int negativos(float *vet, int N){
    int negativos=0;
    for(int i=0; i<N;i++){
        if(vet[i] < 0){
            negativos++;
        }
    }
    return negativos;
}

//1.2

float *preencher(int N) {
    float *vet = (float *)malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        vet[i] = (rand() % 100) - 50;
    }
    return vet;
}

float maior(float *vet, int N){
    float maior = vet[0];
    for(int i=1; i<N;i++){
        if(vet[i]>maior){
            maior = vet[i];
        }
    }
    return maior;
}

float menor(float *vet, int N){
    float menor= vet[0];
    for(int i=1; i<N; i++){
       if(vet[i]<menor){
            menor= vet[i];
       } 
    }
    return menor;
}

float media(float *vet, int N){
    float soma=0;
    for(int i=0; i<N; i++){
        soma += vet[i];
    }
    int media = soma/N;
    return media;
}