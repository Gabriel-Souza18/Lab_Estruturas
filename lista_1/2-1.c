#include <stdio.h>

void crescente(int N);
void decrescente(int N);

void main(){
    int N= 5;
    crescente(N);
    printf("\n");
    decrescente(N);
}
void crescente(int N){
    if(N>=1){
        crescente(N-1);
        printf("%d", N);
    }
    
    
}
void decrescente(int N){
    if(N>=1){
        printf("%d",N);
        decrescente(N-1);
    }
    
}