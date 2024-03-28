#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct conta{
    int numeroDaconta;
    double saldo;
    char *nomeDoTitular;
}ContaBancaria;

ContaBancaria* criarConta(int numero, char *titular);
//Cria uma nova conta bancária com o número e titular especificados.
//Inicializa o saldo como zero.
void depositar(ContaBancaria *c, double valor);
//Deposita o valor especificado na conta.
void sacar(ContaBancaria *c, double valor);
//Realiza um saque da conta, desde que haja saldo suficiente.
double consultarSaldo(ContaBancaria *c);
//Retorna o saldo atual da conta.
void imprimirInfo(ContaBancaria *c);
//Imprime as informações da conta, incluindo número, titular e saldo

void main(){
    int numero;
    char nome[100];
    
    printf("Digite o Nome: ");
    fgets(nome,100,stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("Digite o numero da conta: ");
    scanf("%d",&numero);
    ContaBancaria *c = criarConta(numero,nome);
    depositar(c, 2000);
    sacar(c, 250);
    imprimirInfo(c);
    sacar(c, 2000);
    sacar(c, 500);
    imprimirInfo(c);
    free(c->nomeDoTitular);
    free(c);
}

ContaBancaria* criarConta(int numero, char *titular){
    ContaBancaria* novaConta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (novaConta != NULL) {
        novaConta->numeroDaconta = numero;
        novaConta->nomeDoTitular = strdup(titular);
        novaConta->saldo = 0.0; 
    }
    return novaConta;
}

void depositar(ContaBancaria *c, double valor){
    c->saldo += valor;
}

void sacar(ContaBancaria* c, double valor){
    if(valor <= c->saldo){
        c->saldo -= valor; 
    }else{
        printf("Saldo abaixo do valor de saque\n");
    }
}

double consultarSaldo(ContaBancaria *c){
    return c->saldo;
}
void imprimirInfo(ContaBancaria *c){
    printf("Nome: %s\nNumero da conta: %d \nSaldo: %.2lf\n", 
    c->nomeDoTitular,
    c->numeroDaconta,
    c->saldo);
}

