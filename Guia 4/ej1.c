#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct empresa
{
    char empleado [20];
    char secc [10];
    char cat [3];
};

struct sectores
{
    char secct [10];
    char descr[90];
};

struct sueldos
{
    char cate[3];
    int plata;
};

void emplearch();
void printemple();
void categoarch();
void printcate();
void suelarch();
void printsuel();
void opera();

int main()
{
    struct sueldos sul[5];
    struct sectores sec[5];
    struct empresa empe[10];
    emplearch();
    printemple();
    categoarch();
    printcate();
    suelarch();
    printsuel();
    opera(sul,sec,empe);
    return 0;
}

//-----------------------------------------------------------------------------------------------------------
void emplearch()
{
    struct empresa empe[10];
    FILE *archemp, *empleados;
    int i=0;

    archemp = fopen("archemp.bin","wb");
    empleados = fopen("empleados.txt","rt");
    if (empleados == NULL)
    {
        printf("el archivo de empleados no existe!");
        return;
    }
    else
    {
        while (!feof(empleados))
        {
            fscanf(empleados,"%s %s %s", empe[i].empleado, empe[i].secc, empe[i].cat);
            fwrite(&empe[i], sizeof(struct empresa),1,archemp);
            i++;
        }

    }
    fclose(empleados);
    fclose(archemp);

}

void printemple(){
       struct empresa empe[10];
    FILE *archemp;
    int i;
    archemp = fopen("archemp.bin", "rb");
    if (archemp == NULL) {
        printf("No hay archivo\n");
    } else {
        i = 0;
        while (fread(&empe[i], sizeof(struct empresa), 1, archemp)) {
            printf("%s \t%s \t%s \n", empe[i].empleado, empe[i].secc, empe[i].cat);
            i++;
        }
    }
    fclose(archemp);
}

//------------------------------------------------------------------------------------------------------------------------------------
void categoarch()
{
    struct sectores sec[5];
    FILE *archsec, *secciones;
    int i=0;

    archsec = fopen("archsec.bin","wb");
    secciones = fopen ("secciones.txt","rt");
    if (secciones == NULL)
    {
        printf("el archivo no existe");
        return;
    }
    else
    {
        while (!feof(secciones))
        {
            fscanf(secciones,"%s %s", sec[i].secct, sec[i].descr);
            fwrite(&sec[i], sizeof(struct sectores),1,archsec);
            i++;
        }
    }
    fclose(secciones);
    fclose(archsec);
}

void printcate(){
    struct sectores sec[5];
    FILE *archsec;
    int i;
    archsec = fopen("archsec.bin", "rb");
    if (archsec == NULL) {
        printf("No hay archivo\n");
    } else {
        i = 0;
        while (fread(&sec[i], sizeof(struct sectores), 1, archsec)) {
            printf("%s \t%s  \n",sec[i].secct, sec[i].descr);
            i++;
        }
    }
    fclose(archsec);

}
 //------------------------------------------------------------------------------------
void suelarch()
{
    struct sueldos sul[5];
    FILE *archsul, *categorias;
    int i =0;

    archsul = fopen("archsul.bin","wb");
    categorias = fopen ("categorias.txt","rt");
    if (categorias == NULL)
    {
        printf("no existe el archivo");
        return;
    }else
         {
        while (!feof(categorias))
            {
            fscanf(categorias,"%s %d", sul[i].cate, &sul[i].plata);
            fwrite(&sul[i], sizeof(struct sueldos),1,archsul);
            i++;
            }
        }
    fclose(categorias);
    fclose(archsul);
}

void printsuel(){
    struct sueldos sul[5];
    FILE *archsul;
    int i;
    archsul = fopen("archsul.bin","rb");
    if (archsul == NULL){
        printf("el arch no exite");
        return;
    }else {
         i = 0;
        while (fread(&sul[i], sizeof(struct sueldos), 1, archsul)) {
            printf("%s \t%d  \n", sul[i].cate, sul[i].plata);
            i++;
        }
    }
    fclose(archsul);
}

void opera(struct sueldos sul[],struct sectores sec[],struct empresa empe[]){
    int i,j,k, contsueldo,contemple, contsec;
    contsueldo = 0;
    i= 0;
    FILE *archsul;
    archsul = fopen("archsul.bin","rb");
    if (archsul == NULL){
        printf("el arch no exite");
        return;
    }
    FILE *archsec;
    archsec = fopen("archsec.bin", "rb");
    if (archsec == NULL) {
        printf("No hay archivo\n");
        return;
    }
    FILE *archemp;
    archemp = fopen("archemp.bin", "rb");
    if (archemp == NULL) {
        printf("No hay archivo\n");
    }
    while (fread(&sec[i], sizeof(struct sectores), 1, archsec)) {
        contemple =0;
        for (j=0;j<4;j++){
            fread(&empe[j], sizeof(struct empresa), 1, archemp);
            if (strcmp(sec[i].secct,empe[j].secc)==0){
                contemple++;
            }
        }

        printf("en el sector de %s , codigo de sector: %s , hay %d empleados\n",(sec[i].descr),(sec[i].secct),contemple);
    }
    while (fread(&sul[i], sizeof(struct sueldos), 1, archsul)){
        contsec = 0;
        for (k=0; k<4;k++){
            fread(&empe[k], sizeof(struct empresa), 1, archemp);
            if(strcmp(empe[k].cat,sul[i].cate)==0){
                contsec++;
            }
        }
       contsueldo += contsec*(sul[i].plata);
    }
    printf("la cantidad total de sueldos es: %d", contsueldo);
    fclose(archemp);
    fclose(archsec);
    fclose(archsul);



}
