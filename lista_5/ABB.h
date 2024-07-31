#ifndef ABB_H
#define ABB_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int chave;
    int conteudo;
    struct No *esqNo, *dirNo;
}no;


no * criarArvore();
no * Buscar(no* inicial,int chave);
void Adicionar(no** inicial,int chave, int conteudo);
void Remover(no** inicial, int chave);
void imprimirOrdem(no* inicial);
void imprimirPreOrdem(no* inicial);
void imprimirPosOrdem(no* inicial);
int quantidadeNos(no* inicial);
void destruir(no* inicial);

#endif // ABB_H