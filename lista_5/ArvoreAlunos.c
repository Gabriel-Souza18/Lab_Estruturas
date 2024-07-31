#include "arvoreAlunos.h"


no * criarArvore(){
    no *inicial = NULL;
    return inicial;
}

no * Buscar(no* inicial,int matricula){
    if (inicial == NULL)
        return NULL;

    if (matricula == inicial->matricula)
        return inicial;
    else if (matricula < inicial->matricula)
        return Buscar(inicial->esqNo, matricula);
    else
        return Buscar(inicial->dirNo, matricula);
}  

void Adicionar(no** inicial,int matricula,char* nome, double nota){
    if (*inicial == NULL)
    {
        *inicial = (no*)malloc(sizeof(no));
        (*inicial)->matricula = matricula;
        (*inicial)->nome = nome;
        (*inicial)->nota = nota;
        (*inicial)->esqNo = NULL;
        (*inicial)->dirNo = NULL;
    }
    else if (nota < (*inicial)->matricula)
        Adicionar(&((*inicial)->esqNo),matricula, nome, nota);
    else
        Adicionar(&((*inicial)->dirNo),matricula, nome, nota);
}

no* MaiordirNo(no** inicial) {
    while ((*inicial)->dirNo != NULL) {
        inicial = &((*inicial)->dirNo);
    }
    return *inicial;
}

void Remover(no** inicial, int matricula){
if (*inicial == NULL) {
        printf("matricula não encontrada\n");
        return;
    }

    if (matricula < (*inicial)->matricula) {
        Remover(&((*inicial)->esqNo), matricula);
    } else if (matricula > (*inicial)->matricula) {
        Remover(&((*inicial)->dirNo), matricula);
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
            (*inicial)->matricula = substituto->matricula;
            (*inicial)->nome = substituto->nome;
            Remover(&(*inicial)->esqNo, substituto->matricula);
        }
    }
}




void imprimirOrdem(no* inicial){
    if(inicial != NULL){
        imprimirOrdem(inicial->esqNo);
        printf("matricula: %d, nome: %s, nota: %lf\n" ,inicial->matricula, inicial->nome, inicial->nota );
        imprimirOrdem(inicial->dirNo);
        return ;
    }
    
    return;
}
void imprimirPreOrdem(no* inicial){
        if(inicial != NULL){
        printf("matricula: %d, nome: %s, nota: %lf\n" ,inicial->matricula, inicial->nome, inicial->nota );
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
        printf("matricula: %d, nome: %s, nota: %lf\n" ,inicial->matricula, inicial->nome, inicial->nota );

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