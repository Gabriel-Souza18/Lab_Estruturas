#include "ABB.h"
#include <stdio.h>

void main(){
no *no_inicial;
int chave, conteudo;


int opcao = 0;
do{
       printf("Selecione alguma opcaon:\n");
       printf("1- Criar Arvore\n"
                "2-Inserir um elemento\n"
                "3-Buscar Elemento\n"
                "4-Remover Elemento\n"
                "5-Imprimir em Ordem\n"
                "6-Imprimir em pre-ordem\n"
                "7-Imprimir em pos-ordem\n"
                "8-Quantidade de nos\n"
                "9-Detruir Arvore\n"
                "10-Sair\n"
                );

       scanf("%d", &opcao);
       switch (opcao)
       {
       case 1:
              no_inicial = criarArvore();
              printf("Arvore criada!\n");
              break;

       case 2:

              printf("Digite a chave do item: ");
              scanf("%d", &chave);
              printf("Digite o conteudo do item: ");
              scanf("%d", &conteudo);
              Adicionar(&no_inicial,chave, conteudo);
              printf("Elemento inserido!\n");
              break;

       case 3:
              printf("Digite a chave do item: ");
              scanf("%d", &chave);
              
              printf("Elemento encontrado! %d\n",Buscar(no_inicial, chave)->conteudo);
              break;

       case 4:
              printf("Digite a chave do item: ");
              scanf("%d", &chave);
              Remover(&no_inicial, chave);
              printf("Elemento removido!\n");
              break;

       case 5:
              imprimirOrdem(no_inicial);
              printf("Arvore impressa em ordem!\n");
              break;

       case 6:
              imprimirPreOrdem(no_inicial);
              printf("Arvore impressa em pre-ordem!\n");
              break;

       case 7:
              imprimirPosOrdem(no_inicial);
              printf("Arvore impressa em pos-ordem!\n");
              break;

       case 8:

              printf("Quantidade de nos: %d\n", quantidadeNos(no_inicial));
              break;

       case 9:
              destruir(no_inicial);
              printf("Arvore destruida!\n");
              break;

       case 10:
              printf("Saindo...\n");
              break;

       default:
              printf("Opcao invalida!\n");
              break;
       }
} 
while (opcao != 10);
    
}