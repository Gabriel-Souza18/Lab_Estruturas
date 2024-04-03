#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* nome;
    double preco;
    int quantidade;
}Produto;

typedef struct{
    Produto* Produtos[100];
    int totalProdutos;
}CatalogoProdutos;


CatalogoProdutos* criarCatalogo();
//Cria um catálogo vazio, zerando o total de produtos
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade);
//Adiciona um novo produto ao catálogo
int verificarEstoque(CatalogoProdutos *c, char *nome);
//Verifica a quantidade em estoque de um produto
void imprimirCatalogo(CatalogoProdutos *c);
//Imprime todas as informações dos produtos no catálogo

void main(){
    CatalogoProdutos *c = criarCatalogo();
    adicionarProduto(c,"arroz", 10.50, 10);
    adicionarProduto(c,"feijao", 5.50, 10);
    adicionarProduto(c,"macarrao", 5.30, 40);
    adicionarProduto(c,"carne", 50.0, 19);

    printf("quantidade de arroz: %d\n",verificarEstoque(c,"arroz"));
    imprimirCatalogo(c);
    for (int i = 0; i < c->totalProdutos; i++) {
        free(c->Produtos[i]);
    }
    free(c);
}

CatalogoProdutos* criarCatalogo(){
    CatalogoProdutos* novoCatalogo = (CatalogoProdutos*)malloc(sizeof(CatalogoProdutos));
    if (novoCatalogo == NULL) {
        return NULL;
    }
    novoCatalogo->totalProdutos = 0;
    for (int i = 0; i < 100; i++) {
        novoCatalogo->Produtos[i] = NULL;
    }
    return novoCatalogo;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade){
    Produto* produtoNovo = (Produto*)malloc(sizeof(Produto));
    produtoNovo->nome = strdup(nome);
    produtoNovo->preco = preco;
    produtoNovo->quantidade = quantidade;
    c->totalProdutos++;
    c->Produtos[c->totalProdutos-1] = produtoNovo;
}

int verificarEstoque(CatalogoProdutos *c, char *nome){
    for(int i=0; i<c->totalProdutos; i++){
        if(strcmp(c->Produtos[i]->nome, nome) == 0){
            return c->Produtos[i]->quantidade;
        }
    }
    return 0;
}

void imprimirCatalogo(CatalogoProdutos *c){
    for(int i=0; i<c->totalProdutos;i++){

        printf("Nome do produto: %s, Preco: %.2lf, Quantidade: %d\n", 
        c->Produtos[i]->nome,
        c->Produtos[i]->preco,
        c->Produtos[i]->quantidade
        );
    }
}
