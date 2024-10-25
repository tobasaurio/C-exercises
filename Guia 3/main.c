#include <stdio.h>
#include <stdlib.h>

struct peaje{
    int cabina;
    int catego;
};
struct autos{
    int cat;
    int precio;
};


void bin();
void creatabla(struct autos listado[]);

int main()
{
    bin();
    FILE *peabin;
    peabin = fopen("peabin.bin","rb");
    struct autos listado[5];
    struct peaje lista;
    int totalcabin[7]={0};
    int autoscate[5]={0};
    int autocabin[7][5]={0};
    if (peabin == NULL){
        printf("no hay archivos");
    }else{
        creatabla(listado);
        fread(&lista,sizeof(struct peaje),1,peabin);
        while(!feof(peabin)){
            autoscate[lista.catego-1] += 1;
            totalcabin[lista.cabina-1] += listado[lista.catego-1].precio;
            autocabin[lista.cabina-1][lista.catego-1] +=1;
            fread(&lista,sizeof(struct peaje),1,peabin);
        }
        fclose(peabin);
        for(int i=0 ;i<7;i++){
            printf("\nEn la cabina %d, se recaudo %d",(i+1),totalcabin[i]);
        }
        for(int i=0 ;i<5;i++){
            printf("\nHubo %d, autos de la categoria %d",autoscate[i],(i+1));
        }

    }
    return 0;
}
void bin(){
    struct peaje pea;
    struct autos cars;
    FILE *peajes, *categoria, *peabin, *catebin;
    peajes = fopen("peaje.txt","rt");
    categoria = fopen("categoria.txt","rt");
    peabin = fopen("peabin.bin","wb");
    catebin = fopen("catebin.bin","wb");
    if (peajes == NULL || categoria == NULL || peabin == NULL || catebin == NULL){
        printf("no hay archivo jefe");
    }else{
        while(fscanf(peajes,"%d %d",&pea.cabina,&pea.catego)==2){
            fwrite(&pea,sizeof(struct peaje),1,peabin);
        }
        while(fscanf(categoria,"%d %d",&cars.cat,&cars.precio)==2){
            fwrite(&cars,sizeof(struct autos),1,catebin);
        }
        fclose(peabin);
        fclose(catebin);
        fclose(categoria);
        fclose(peajes);
    }
}
 void creatabla(struct autos listado[]){
    FILE *catebin;
    catebin = fopen("catebin.bin","rb");
    int i=0;
    if (catebin == NULL){
        printf("no hay archivo");
    }else{
        while (fread(&listado[i],sizeof(struct autos),1,catebin)){
            i++;
        }
     fclose(catebin) ;
    }
 }
