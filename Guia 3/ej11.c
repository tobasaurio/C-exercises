#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct alumnos{
    char nombre[20];
    int matricula;
    float promedio;
};

void cargastruct(struct alumnos alum[], int *dn);
int alummaxi (struct alumnos alum[], int n);
void listastruct (struct alumnos alum[], int n,int *promt);

int main()
{
    int n,prom;
    struct alumnos alum[50];
    cargastruct(alum, &n);
    printf("el alumno con mejor promedio es: %s", (alummaxi(alum, n)));
    printf("\ningrese el promedio deseado: ");
    scanf("%d",&prom);
    listastruct(alum, n,&prom);
    return 0;
}

void cargastruct(struct alumnos alum[], int *dn){
    int i;
    printf("ingrese la cantidad de alumnos: ");
    scanf("%d",dn);
    for (i=0; i <*dn; i++){
        printf("\nIngrese el nombre del alumno %d: ", i+1);
        scanf("%s",(alum[i]).nombre);
        printf("\n Ingrese el numero de matricula: ");
        scanf("%d", &(alum[i]).matricula);
        printf("\n Ingrese el promedio del alumno: ");
        scanf("%f", &(alum[i]).promedio);
        printf("--------------------------------------");
    }

}

int alummaxi (struct alumnos alum[50], int n){
    int aux=0,i, pos;
    for (i=0; i<n; i++){
        if (((alum[i]).promedio)> aux){
            aux = (alum[i].promedio);
            pos = i;
        }
    }
    return (alum[pos].nombre);
}

void listastruct(struct alumnos alum[50], int n, int *promt){
    int i;
    printf("Alumno       Promedio       Matricula\n");
    for (i =0; i<n; i++){
        if (alum[i].promedio>= *promt){
            printf("%s      %.2f        %d\n",alum[i].nombre, alum[i].promedio,alum[i].matricula);
        }
        else{
            printf("el alumno %s no supero el promedio esperado\n", alum[i].nombre);
        }
    }

}
