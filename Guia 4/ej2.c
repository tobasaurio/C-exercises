#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct infodep{
    char nombre[30];
    int edad;
    int cod;
};

struct deporte{
    int codi;
    char desc[20];
};

void cargainfo(int *dn);
void muestrainfo(int n);
void cargadepo(int *dm);
void muestradepo(int m);
void opera();


int main()
{
    struct infodep inf[99];
    struct deporte dep[99];
    int n,m;
    cargainfo(&n);
    muestrainfo(n);
    cargadepo(&m);
    muestradepo(m);
    opera(inf,dep,n,m);

    return 0;
}

void cargainfo(int *dn)
{
    struct infodep inf[99];
    FILE *deporti, *Deportistas;
    int i=0;
    Deportistas = fopen("Deportistas.txt","rt");
    if (Deportistas == NULL){
        printf("el archivo no existe");
        return ;
    }
    deporti = fopen ("deporti.dat","wb");
    if (deporti == NULL){
        printf("no se creo el archivo");
        return ;
    }
    while(!feof(Deportistas)){
            fscanf(Deportistas,"%s %d %d",inf[i].nombre, &inf[i].edad, &inf[i].cod);
            fwrite(&inf[i],sizeof(struct infodep),1,deporti);
            i++;
    }
    *dn = i;
    fclose(Deportistas);
    fclose(deporti);
}

void muestrainfo(int n){
    struct infodep inf[99];
    int i=0;
    FILE *deporti;
    deporti = fopen ("deporti.dat","rb");
    if (deporti == NULL){
        printf("no se creo el archivo");
        return ;
    }
    while(fread(&inf[i],sizeof(struct infodep),1,deporti)){
        printf("%s %d %d\n",inf[i].nombre,inf[i].edad,inf[i].cod);
    }
    fclose(deporti);

}

void cargadepo(int *dm){
    struct deporte dep [10];
    int i = 0;
    FILE *Deportes, *coddep;
    Deportes = fopen("Deportes.txt","rt");
    if (Deportes == NULL){
        printf("no hay archivo");
        return;
    }
    coddep = fopen("coddep.dat","wb");
    if (coddep == NULL){
        printf("no se creo el archivo");
        return;
    }
    while(!feof(Deportes)){
        fscanf(Deportes,"%d %s",&dep[i].codi,dep[i].desc);
        fwrite(&dep[i],sizeof(struct deporte),1,coddep);
        i++;
    }
    *dm=i;
    fclose(Deportes);
    fclose(coddep);
}

void muestradepo(int m){
    struct deporte dep[10];
    int i=0;
    FILE *coddep;
    coddep = fopen("coddep.dat","rb");
    if (coddep == NULL){
        printf("no se creo el archivo");
        return;
    }
    while(fread(&dep[i],sizeof(struct deporte),1,coddep)){
            printf("%d %s\n",dep[i].codi,dep[i].desc);

    }
    fclose(coddep);
}

void opera(struct infodep inf [], struct deporte dep[],int n, int m){
    int i=0,contedad,contdepor,contxdep,j=0,aux;
    float promedad;
    FILE *coddep;
    coddep = fopen("coddep.dat","rb");
    if (coddep == NULL){
        printf("no se creo el archivo");
        return;
    }
    FILE *deporti;
    deporti = fopen ("deporti.dat","rb");
    if (deporti == NULL){
        printf("no se creo el archivo");
        return ;
    }
    contedad = 0;
    contdepor=0;
    printf("\nDEPORTE \tCant deportistas\n");
     while(fread(&dep[i],sizeof(struct deporte),1,coddep)){
        contxdep=0;
        aux=dep[i].codi;
        for(j=0; j<n; j++){
            fread(&inf[j],sizeof(struct infodep),1,deporti);
            if(inf[j].cod==aux){
                    contxdep++;
                }
             }

        printf("%s\t%d\n",dep[i].desc,contxdep);
        contdepor += contxdep;
     }
     for(j=0; j<n; j++){
            fread(&inf[j],sizeof(struct infodep),1,deporti);
            contedad += inf[j].edad;}


    promedad = (float)contedad/n;
    printf("\nTotal \t%d",contdepor);
    printf("\nla edad pormedio de los deportistas es %.2f",promedad);

    fclose(deporti);
    fclose(coddep);


}
