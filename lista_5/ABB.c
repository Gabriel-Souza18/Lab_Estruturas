#include "ABB.h"


no * criarArvore(){
    no *inicial = NULL;
    return inicial;
}

no * Buscar(no* inicial,int chave){
    if (inicial == NULL)
        return NULL;

    if (chave == inicial->chave)
        return inicial;
    else if (chave < inicial->chave)
        return Buscar(inicial->esqNo, chave);
    else
        return Buscar(inicial->dirNo, chave);
}  

void Adicionar(no** inicial,int chave,int conteudo){
    if (*inicial == NULL)
    {
        *inicial = (no*)malloc(sizeof(no));
        (*inicial)->chave = chave;
        (*inicial)->conteudo = conteudo;
        (*inicial)->esqNo = NULL;
        (*inicial)->dirNo = NULL;
    }
    else if (conteudo < (*inicial)->chave)
        Adicionar(&((*inicial)->esqNo),chave, conteudo);
    else
        Adicionar(&((*inicial)->dirNo),chave, conteudo);
}

no* MaiordirNo(no** inicial) {
    while ((*inicial)->dirNo != NULL) {
        inicial = &((*inicial)->dirNo);
    }
    return *inicial;
}

void Remover(no** inicial, int chave){
if (*inicial == NULL) {
        printf("Chave não encontrada\n");
        return;
    }

    if (chave < (*inicial)->chave) {
        Remover(&((*inicial)->esqNo), chave);
    } else if (chave > (*inicial)->chave) {
        Remover(&((*inicial)->dirNo), chave);
    } else {
        no* ArvoreAux = *inicial;
        if ((*inicial)->esqNo == NULL && (*inicial)->dirNo == NULL) { // sem filhos
            free(ArvoreAux);
            *inicial = NULL;
        } else if ((*inicial)->esqNo == NULL) { // um filho à direita
            *inicial = (*inicial)->dirNo;
            free(ArvoreAux);
        } else if ((*inicial)->dirNo == NULL) { // um filho à esquerda
            *inicial = (*inicial)->esqNo;
            free(ArvoreAux);
        } else { // dois filhos
            no* substituto = MaiordirNo(&(*inicial)->esqNo);
            (*inicial)->chave = substituto->chave;
            (*inicial)->conteudo = substituto->conteudo;
            Remover(&(*inicial)->esqNo, substituto->chave);
        }
    }
}




void imprimirOrdem(no* inicial){
    if(inicial != NULL){
        imprimirOrdem(inicial->esqNo);
        printf("Chave: %d, conteudo: %d\n",inicial->chave, inicial->conteudo );
        imprimirOrdem(inicial->dirNo);
        return ;
    }
    
    return;
}
void imprimirPreOrdem(no* inicial){
        if(inicial != NULL){
        printf("Chave: %d, conteudo: %d\n",inicial->chave, inicial->conteudo );
        imprimirOrdem(inicial->esqNo);
        imprimirOrdem(inicial->dirNo);
        return ;
    }
    
    return ;
}
void imprimirPosOrdem(no* inicial){
    if(inicial != NULL){
        imprimirOrdem(inicial->esqNo);
        imprimirOrdem(inicial->dirNo);
        printf("Chave: %d, conteudo: %d\n",inicial->chave, inicial->conteudo );
        return ;
    }
    
    return ;
}
int quantidadeNos(no* inicial){
    if(inicial!=NULL){
        return 1 + quantidadeNos(inicial->esqNo) + quantidadeNos(inicial->dirNo);

    }
    return 0;
}
    
void destruir(no* inicial){
    if(inicial != NULL){
        destruir(inicial->esqNo);
        destruir(inicial->dirNo);
        free(inicial);
    }

}