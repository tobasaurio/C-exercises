#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1, *ptr2;
    int a, b;
    {
        ptr1 = &a;
        ptr2 = &b;
        *ptr1 = 8;
        *ptr2 = 61;
        ptr1 = ptr2;
        *ptr1 += 2;
        (*ptr1)++;
        printf("%d , %d\n", a, b);
        printf("%d , %d\n", *ptr1, *ptr2);
        printf("%p , %p\n", ptr1, ptr2);
        printf("%p , %p\n", &a, &b);
    }
    return 0;
}
