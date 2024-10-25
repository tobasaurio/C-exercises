#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,cont=0;
    printf("ingrese 3 numeros");
    scanf("%d%d%d",&a,&b,&c);
    if (a-b==1 || a-b==-1){
            printf("a y b son consecutivos");
            ++cont;
    }
     if (b-c==1 || b-c==-1){
            printf("b y c son consecutivos");
            ++cont;
    }
     if (a-c==1 || a-c==-1){
            printf("a y c son consecutivos");
            ++cont;
    }
    if (cont==0)
        printf("no hay numeros consecutivos");

    return 0;
}
