#include "arvoreAlunos.h"
#include <stdio.h>
#include <string.h>

void main(){
no *no_inicial;
int matricula;
double nota;
char nome[50];


int opcao = 0;
do{
       printf("Selecione alguma opcaon:\n");
       printf("1- Criar Arvore\n"
                "2-Inserir um Aluno\n"
                "3-Buscar Aluno\n"
                "4-Remover Aluno\n"
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
              printf("Digite o nome do aluno: ");
              getchar();
              
              fgets(nome, 50, stdin);
              fflush(stdin);
              // Remover o '\n' do final da string
              size_t len = strlen(nome);
              if (len > 0 && nome[len - 1] == '\n') {
                     nome[len - 1] = '\0';
              }

              printf("Digite a matricula do aluno: ");
              scanf("%d", &matricula);

              printf("Digite a nota do Aluno: ");
              scanf("%lf", &nota);

              Adicionar(&no_inicial, matricula, nome, nota);
       
              printf("Aluno inserido!\n");
              break;

       case 3:
              printf("Digite a matricula do item: ");
              scanf("%d", &matricula);
              no *alunoBuscado = Buscar(no_inicial, matricula);
              printf("Aluno encontrado! %s -Nota: %lf\n",alunoBuscado->nome, alunoBuscado->nota);
              
              break;

       case 4:
              printf("Digite a matricula do item: ");
              scanf("%d", &matricula);
              Remover(&no_inicial, matricula);
              printf("Aluno removido!\n");
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