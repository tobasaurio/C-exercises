#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiacadena(char **cadina, char *cadest);
int cuentaletra (char *cadena, char letra);

int main()
{
    char cadena[99];
    char *caddin;
    char letra;
    int dina, estati;
    printf("dame cadena:\n");
    scanf("%s",cadena);

    copiacadena(&caddin, cadena);
    printf("\n tamodsdso :%s",caddin);

    printf("\n dame letra:");
    scanf(" %c",&letra);
    dina = (cuentaletra(caddin,letra));
    printf("\n %d",dina);
    estati= (cuentaletra(cadena,letra));
    printf("\n %d",estati);
    free(caddin);


}

void copiacadena( char **cadina, char *cadest){
    printf("%s\n",cadest);
    int largo = strlen(cadest);
    *cadina =(char*)malloc((largo +1) *sizeof(char));
    strcpy(*cadina, cadest);
    printf("tamoo :%s",*cadina);

}

int cuentaletra (char *cadena, char letra){
    int cont =0;
    while (*cadena){
        if(*cadena == letra){
            cont++;
        }
        cadena++;
    }
    return cont;

}


