#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{
    char nombre[10];
    int matricula;
    float promedio;
};
void lee (struct alumno *alum); // se pasa para la referencia de escritura y modificacion
void escribe (struct alumno alum);

int main(void){
    struct alumno alum;
    lee(&alum); // se para con & para que se modifique
    escribe(alum); // no se pone & xq solo lo lee
    //printf("dame nombre: ");
    //gets(alum.nombre);
    //printf("matricula: ");
    //scanf("%d",&alum.matricula);
    //printf("promedio: ");
    //scanf("%f",&alum.promedio);
    //printf("----------------");
    //printf("nombre del alumno: ");
    //printf("%s",alum.nombre);
    //printf("matricula: ");
    //printf("%d", alum.matricula);
    //printf("promedio");
    //printf("%f",alum.promedio);
    return 0;
}
void lee (struct alumno *alum){ // * para el parametro
    printf("dame nombre: ");
    scanf("%s",(*alum).nombre); // el char no lleva & pero se pone (*alum). nombre, para acceder a nombre y modificar el valor (es lo mimso que poner alum->nombre)
    printf("matricula: ");
    scanf("%d",&(*alum).matricula); // se pone el & xq es int y float
    printf("promedio: ");
    scanf("%f",&(*alum).promedio);
    printf("----------------\n");
}

void escribe(struct alumno alum){
    printf("el nombre del alumno es: %s", alum.nombre);
    printf("\n la matricula es: %d", alum.matricula);
    printf("\n el promedio es: %f", alum.promedio);

}
