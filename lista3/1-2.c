#include <stdlib.h>

typedef struct{
    int arestas
}Face;

typedef struct 
{
    Face faces
}Cubo;

Cubo* alocaCubo() {
    Cubo* cubo = (Cubo*)malloc(sizeof(Cubo));
    if(cubo == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    return cubo;
}

int areaFace(Cubo* cubo){
    return cubo->faces.arestas * cubo->faces.arestas;
}

int ladosCubo(Cubo* cubo){
    return areaFace(cubo) * 6;
}
int volumeCubo(Cubo* cubo){
    return areaFace(cubo)*areaFace(cubo)*areaFace(cubo);
}