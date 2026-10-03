#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *name = "Tehseen";

    printf("Single Quotes:\n");
    printf("'Hello $name'\n");

    printf("\nDouble Quotes:\n");
    printf("\"Hello %s\"\n", name);

    printf("\nPreserving Spaces:\n");
    printf("\"Operating Systems And Systems Programming\"\n");

    printf("\nNested Tokens:\n");
    printf("\"Hello 'World'\"\n");

    return 0;
}