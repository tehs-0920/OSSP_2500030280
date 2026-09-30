#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, *b;

    a = (int *)malloc(5 * sizeof(int));
    printf("Memory allocated using malloc()\n");

    b = (int *)calloc(5, sizeof(int));
    printf("Memory allocated using calloc()\n");

    a = (int *)realloc(a, 10 * sizeof(int));
    printf("Memory reallocated using realloc()\n");

    free(a);
    printf("Memory released for a\n");

    free(b);
    printf("Memory released for b\n");

    return 0;
}