#include <stdio.h>
#define MAX 100

typedef struct {
    int itens[MAX];
    int tamanho;
} ListaSequencial;

void inicializarLista(ListaSequencial* lista) {
    lista->tamanho = 0;
}

int procurar(ListaSequencial* lista, int x) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->itens[i] == x) {
            return i;
        }
    }
    return -1; // Elemento não encontrado
}

int inserirOrdenado(ListaSequencial* lista, int item) {
    if (lista->tamanho == MAX) {
        return -1; // Lista cheia
    }

    int i;
    for (i = lista->tamanho; i > 0 && lista->itens[i - 1] > item; i--) {
        lista->itens[i] = lista->itens[i - 1];
    }
    lista->itens[i] = item;
    lista->tamanho++;
    return 0;
}

void imprimirLista(ListaSequencial* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->itens[i]);
    }
    printf("\n");
}

int main() {
    ListaSequencial lista;
    inicializarLista(&lista);
    inserirOrdenado(&lista, 1);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 4);
    inserirOrdenado(&lista, 5);
    imprimirLista(&lista);
    inserirOrdenado(&lista, 3);
    imprimirLista(&lista);
    return 0;
}
