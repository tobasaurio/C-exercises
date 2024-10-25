#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tdapila.h"

typedef struct {
    char codDeporte[7];
    float tiempoProm;
    int cantDepor;
}TELEMENTOL;

typedef struct {
    char nombre[30];
    float tiempo;
}TELEMENTOSL;

typedef struct nodosl{
    TELEMENTOSL deportista;
    struct nodosl *sigs;
}NODOSL;

typedef NODOSL *TSUBLISTA;

typedef struct nodo{
    TELEMENTOL deporte;
    TSUBLISTA deportistas;
    struct nodo *sig;
}NODO;

typedef NODO *TLISTA;

void cargaLista(TLISTA *pl);
void muestraLista(TLISTA li);
void cargaPila(TPILA *pila);
void combinaPilaLista(TLISTA *pl, TPILA *pila);
void buscaEnLaLista(TLISTA *act, TLISTA *ant, char codDeporte[]);
void insertaDeporte(TLISTA *act,TLISTA *ant, TELEMENTOP elemP); //en caso de que el deporte de la pila no se encuentre ya en la lista
void insertaDeportista(TSUBLISTA *aux, TELEMENTOP elemP);

int main()
{
    TLISTA lista = NULL;
    TPILA pila;
    //TELEMENTOP elemP;

    iniciap(&pila);
    cargaLista(&lista);
    printf("\nLista\n");
    muestraLista(lista);
    cargaPila(&pila);
    /*printf("PILA\n");
    while(!vaciap(pila)){
        sacap(&pila,&elemP);
        printf(">%s %s %.2f\n",elemP.nombre,elemP.codDeportep,elemP.tiempo);
    }*/
    combinaPilaLista(&lista,&pila);
    printf("\nNueva Lista\n");
    muestraLista(lista);
    return 0;
}

void cargaLista(TLISTA *pl){
    FILE *arch = fopen("DEPORTE.txt","rt");
    TELEMENTOL regDep;
    TELEMENTOSL regSL;
    TLISTA ult = NULL;
    TSUBLISTA ultSL = NULL;
    int n;

    if(arch != NULL){
        while(fscanf(arch,"%s %f %d",regDep.codDeporte,&regDep.tiempoProm,&regDep.cantDepor) == 3){
            if((*pl) == NULL){
                (*pl) = malloc(sizeof(NODO));
                (*pl)->deporte = regDep;
                (*pl)->deportistas = NULL;
                (*pl)->sig = ult;
                ult = (*pl);
            }
            else{
                ult->sig = malloc(sizeof(NODO));
                ult = ult->sig;
                ult->deporte = regDep;
                ult->deportistas = NULL;
            }
            n = regDep.cantDepor;
            while(n > 0){
                fscanf(arch,"%s %f",regSL.nombre,&regSL.tiempo);
                if(ult->deportistas == NULL){
                    ult->deportistas = malloc(sizeof(NODOSL));
                    ult->deportistas->deportista = regSL;
                    ult->deportistas->sigs = ultSL;
                    ultSL = ult->deportistas;
                }
                else{
                    ultSL->sigs = malloc(sizeof(NODOSL));
                    ultSL = ultSL->sigs;
                    ultSL->deportista = regSL;
                }
                n--;
            }
            ultSL->sigs = NULL;
        }
        ult->sig = NULL;
        fclose(arch);
    }
    else
        printf("DEPORTE.txt no existe\n");
}

void muestraLista(TLISTA li){
    TSUBLISTA slaux;

    while(li != NULL){
        slaux = li->deportistas;
        printf("\n%s %.2f %d\n",li->deporte.codDeporte,li->deporte.tiempoProm,li->deporte.cantDepor);
        while(slaux != NULL){
            printf(">%s %.2f\n",slaux->deportista.nombre,slaux->deportista.tiempo);
            slaux = slaux->sigs;
        }
        li = li->sig;
    }
}

void cargaPila(TPILA *pila){
    FILE *arch = fopen("PILA.txt","rt");
    TELEMENTOP elemP;

    if(arch != NULL){
        while(fscanf(arch,"%s %s %f",elemP.nombre,elemP.codDeportep,&elemP.tiempo) == 3)
            ponep(&(*pila),elemP);
        fclose(arch);
    }
    else
        printf("PILA.txt no existe\n");
}

void combinaPilaLista(TLISTA *pl, TPILA *pila){
    TLISTA aux,ant;
    TSUBLISTA auxSL,nuevoSL;
    TELEMENTOP elemP;
    float sumaTiempo;

    while(!vaciap(*pila)){
        sacap(&(*pila),&elemP);
        aux = (*pl);
        ant = NULL;
        buscaEnLaLista(&aux,&ant,elemP.codDeportep);
        if(aux == NULL){
            insertaDeporte(&aux,&ant,elemP);
        }
        else{
            if(aux->deporte.tiempoProm > elemP.tiempo || aux->deporte.cantDepor == 0){
                aux->deporte.cantDepor++;
                sumaTiempo = 0;
                auxSL = aux->deportistas;
                insertaDeportista(&nuevoSL,elemP);
                if(auxSL != NULL){
                    while(auxSL->sigs != NULL){
                        sumaTiempo += auxSL->deportista.tiempo;
                        auxSL = auxSL->sigs;
                    }
                    if(auxSL->sigs == NULL)
                        sumaTiempo += auxSL->deportista.tiempo;
                    auxSL->sigs = nuevoSL;
                    nuevoSL->sigs = NULL;
                    sumaTiempo += nuevoSL->deportista.tiempo;
                    aux->deporte.tiempoProm = sumaTiempo / aux->deporte.cantDepor;
                }
                else{
                    aux->deporte.tiempoProm = elemP.tiempo;
                    aux->deportistas = nuevoSL;
                }
            }
        }
    }
}

void buscaEnLaLista(TLISTA *act, TLISTA *ant, char codDeporte[]){
    while((*act) != NULL && strcmp((*act)->deporte.codDeporte,codDeporte)){
        (*ant) = (*act);
        (*act) = (*act)->sig;
    }
    //si act != NULL entonces el deporte esta en la lista, sino hay que insertarlo
}

void insertaDeporte(TLISTA *act,TLISTA *ant,TELEMENTOP elemP){
    TLISTA nuevo;
    TSUBLISTA nuevoSL;
    nuevo = malloc(sizeof(NODO));
    nuevo->deporte.cantDepor = 1;
    nuevo->deporte.tiempoProm = elemP.tiempo;
    strcpy(nuevo->deporte.codDeporte,elemP.codDeportep);
    nuevo->deportistas = NULL;
    (*ant)->sig = nuevo;
    nuevo->sig = (*act);
    insertaDeportista(&nuevoSL,elemP);
    nuevo->deportistas = nuevoSL;
}

void insertaDeportista(TSUBLISTA *aux, TELEMENTOP elemP){
    (*aux) = malloc(sizeof(NODOSL));
    (*aux)->deportista.tiempo = elemP.tiempo;
    strcpy((*aux)->deportista.nombre,elemP.nombre);
    (*aux)->sigs = NULL;
}
