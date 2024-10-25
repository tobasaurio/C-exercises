#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tdacola.h"

int main()
{
    TCOLA cola;
    TELEMENTOC elem;
    iniciac(&cola);
    printf("Dame cadena: ");
    while(scanf(" %c",&elem)==1 && elem != '*'){
        ponec(&cola,elem);
    }
    while(!vaciac(cola)){
        sacac(&cola,&elem);
        printf(" %c",elem);
    }
    return 0;
}

