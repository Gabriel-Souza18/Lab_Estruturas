#include <stdio.h>

int multiplicacao(int M, int N) {
    if (N == 0) {
        return 0;
    }
    return M + multiplicacao(M, N - 1); 

}

 void main(){
    int M = 5;
    int N = 4;
    printf("resultado: %d\n", multiplicacao(M,N));
 }