#ifndef ABB_H
#define ABB_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int matricula;
    char* nome;
    double nota;
    struct No *esqNo, *dirNo;
}no;


no * criarArvore();
no * Buscar(no* inicial,int matricula);
void Adicionar(no** inicial,int matricula, char* nome, double nota);
void Remover(no** inicial, int matricula);
void imprimirOrdem(no* inicial);
void imprimirPreOrdem(no* inicial);
void imprimirPosOrdem(no* inicial);
int quantidadeNos(no* inicial);
void destruir(no* inicial);

#endif // ABB_H