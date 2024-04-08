#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elementos;
    int tamanho;
    int capacidade;
} Conjunto;

Conjunto* criarConjunto() {
    Conjunto* c = (Conjunto*) malloc(sizeof(Conjunto));
    c->elementos = (int*) malloc(10 * sizeof(int));
    c->tamanho = 0;
    c->capacidade = 10;
    return c;
}

void inserirElemento(Conjunto* c, int elemento) {
    if(c->tamanho == c->capacidade) {
        c->capacidade *= 2;
        c->elementos = (int*) realloc(c->elementos, c->capacidade * sizeof(int));
    }
    c->elementos[c->tamanho++] = elemento;
}

void removerElemento(Conjunto* c, int elemento) {
    for(int i = 0; i < c->tamanho; i++) {
        if(c->elementos[i] == elemento) {
            for(int j = i; j < c->tamanho - 1; j++) {
                c->elementos[j] = c->elementos[j + 1];
            }
            c->tamanho--;
            return;
        }
    }
}

int pertenceAoConjunto(Conjunto* c, int elemento) {
    for(int i = 0; i < c->tamanho; i++) {
        if(c->elementos[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

int menorValor(Conjunto* c) {
    int menor = c->elementos[0];
    for(int i = 1; i < c->tamanho; i++) {
        if(c->elementos[i] < menor) {
            menor = c->elementos[i];
        }
    }
    return menor;
}

int maiorValor(Conjunto* c) {
    int maior = c->elementos[0];
    for(int i = 1; i < c->tamanho; i++) {
        if(c->elementos[i] > maior) {
            maior = c->elementos[i];
        }
    }
    return maior;
}

int conjuntosSaoIguais(Conjunto* c1, Conjunto* c2) {
    if(c1->tamanho != c2->tamanho) {
        return 0;
    }
    for(int i = 0; i < c1->tamanho; i++) {
        if(!pertenceAoConjunto(c2, c1->elementos[i])) {
            return 0;
        }
    }
    return 1;
}

int tamanhoDoConjunto(Conjunto* c) {
    return c->tamanho;
}

int conjuntoEhVazio(Conjunto* c) {
    return c->tamanho == 0;
}

Conjunto* diferencaDosConjuntos(Conjunto* c, Conjunto* b){
    Conjunto * diferenca = criarConjunto();
    for(int i=0; i<c->tamanho;i++){
        if(!pertenceAoConjunto(b, c->elementos[i])){
            inserirElemento(diferenca, c->elementos[i]);
        }
    }
    for(int i=0; i<b->tamanho;i++){
        if(!pertenceAoConjunto(c, b->elementos[i])){
            inserirElemento(diferenca, b->elementos[i]);
        }
    }
    return diferenca;
}
Conjunto * interesecçao(Conjunto* c, Conjunto* b){
    Conjunto * interesecçao = criarConjunto();
    for(int i=0; i<c->tamanho;i++){
        if(pertenceAoConjunto(b, c->elementos[i])){
            inserirElemento(interesecçao, c->elementos[i]);
        }
    }
    return interesecçao;
}
Conjunto* uniaoDosConjuntos(Conjunto* c, Conjunto* b){
    Conjunto * uniao = criarConjunto();
    for(int i=0; i<c->tamanho;i++){
            inserirElemento(uniao, c->elementos[i]);
    }
    for(int i=0; i<b->tamanho;i++){
        if(!pertenceAoConjunto(uniao, b->elementos[i])){
            inserirElemento(uniao, b->elementos[i]);
        }
    }
    return uniao;
}
''
