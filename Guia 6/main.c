#include <stdio.h>
#include <stdlib.h>
#include "tdapila.h"


int main()
{
    TPILA pilaa, pilab, auxa, auxb;
    TELEMENTOP elem, aux;

    iniciap(&pilaa);
    iniciap(&pilab);
    iniciap(&auxa);
    iniciap(&auxb);

    printf("dame caracteres para a\n");
    while(scanf(" %c",&elem)==1 && elem!='*'){
        ponep(&pilaa,elem);
    }

    printf("dame caracteres para b\n");
    while(scanf(" %c",&elem)==1 && elem!='*'){
        ponep(&pilab,elem);
    }


    while(!vaciap(pilaa) && !vaciap(pilab)){
        consultap(pilaa,&elem);
        consultap(pilab,&aux);
        if(elem<aux){
            sacap(&pilaa,&elem);
            ponep(&auxa,elem);
        }else if (elem>aux){
            sacap(&pilab,&aux);
            ponep(&auxa,aux);

        }else if (elem==aux){
            sacap(&pilaa,&elem);
            sacap(&pilab,&aux);
            ponep(&auxa,aux);

        }
    }

    if(!vaciap(pilaa)){
        while(!vaciap(pilaa)){
            sacap(&pilaa,&elem);
            ponep(&auxa,elem);
        }
    }
    if(!vaciap(pilab)){
        while(!vaciap(pilab)){
            sacap(&pilab,&elem);
            ponep(&auxa,elem);
        }
    }

    while(!vaciap(auxa)){
        sacap(&auxa,&elem);
        ponep(&auxb,elem);
    }

    printf("listas intercaladas");
    while(!vaciap(auxb)){
        sacap(&auxb,&elem);
        printf(" %c",elem);
    }


    return 0;
}
