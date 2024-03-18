#include <stdio.h>

typedef struct aluno{
    char* nome;
    int matricula;
    float nota;   
}Aluno;

void maiorEMenor(Aluno *alunos,int N);

int main(){
    Aluno alunos[3] = {
        {"Alice", 12345, 8.5},
        {"Bob", 67890, 7.2},
        {"Carol", 54321, 9.0}
    };

    maiorEMenor(alunos, 3);

    return 0;
}

void maiorEMenor(Aluno *alunos, int N){
    Aluno maiorNota = alunos[0];
    Aluno menorNota = alunos[0];
    for(int i=1; i<N; i++){
        if(alunos[i].nota > maiorNota.nota){
            maiorNota = alunos[i];
        }
        if(alunos[i].nota < menorNota.nota){
            menorNota = alunos[i];
        }
    }
    printf("Melhor Nota:\n nome: %s,matricula: %d, nota: %.2f\n", maiorNota.nome, maiorNota.matricula, maiorNota.nota);
    printf("Menor Nota:\n nome: %s,matricula: %d, nota: %.2f\n", menorNota.nome, menorNota.matricula, menorNota.nota);
}