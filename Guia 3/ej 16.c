#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct solucion{
    int indice[10];
    int suma [10];
};

void cargamtriz(int mat[][10],int *dn,int *dm);
int compropar(int mat[][10], int i, int m, int n);
int compromulti(int mat[][10], int i, int m, int n);
void muestraall(int mat[][10], struct solucion sol[],int n, int m, int k);

int main(void)
{
    int n,m,i,k, kont;
    struct solucion sol [10];
    int mat[10][10] ={0};
    cargamtriz(mat,&n,&m);
    k = 0;
    for(i=0; i<n;i++){
        if ((kont =compromulti(mat,i,m,n))>0){
                sol[k].indice[k] = i;
                sol[k].suma[k] = kont;
                k++;
        }else{
                if ((kont =compropar (mat,i,m,n))>0){
                    sol[k].indice[k] = i;
                    sol[k].suma[k] = kont;
                    k++;}
                    }
    }
    muestraall(mat,sol,n,m,k);

return 0;
}


void cargamtriz(int mat[][10], int *dn, int *dm){
    int i,j;
    printf("ingrese la cantidad de filas (n)");
    scanf("%d", dn);
    printf("ingrese la cantidad de columnas (m)");
    scanf ("%d", dm);
    for (i=0; i<*dn; i++){
        for (j=0; j<*dm; j++){
            printf("ingrese el valor [%d][%d]:",i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int compromulti(int mat[][10], int i, int m , int n){
    int j, kont;
    kont = 0;
    for (j=0; j<m ; j++){
        if((mat[i][j]) % n == 0){
            kont += (mat[i][j]);
        }
    }
    if (kont == 0){
        return 0;
    } else{
        return kont;
    }
}

int compropar(int mat[][10], int i, int m, int n){
    int j, kont;
    kont = 0;
    for (j=0; j<m ; j++){
        if((mat[i][j]) % 2 == 0){
            ++kont;
        }
    }
    if (kont == 0){
        return 0;
    } else{
        return kont;
    }
}


void muestraall(int mat[][10], struct solucion sol[],int n, int m, int k){

    int i,j,p;
    for (i=0 ; i<n; i++){
        for (j=0; j<m ; j++){
            printf("el valor de la pos[%d][%d] es: %d\n", i,j, mat[i][j]);
        }
    }
    for (p=0; p<k; p++){
        printf("Indice de fila: %d\n",sol[p].indice[p]);
        printf("Valor: %d\n",sol[p].suma[p]);
    }

}



