#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char path[1024];

    if (getcwd(path, sizeof(path)) != NULL)
        printf("Current Directory: %s\n", path);

    printf("Program is running...\n");

    printf("Exiting program and cleaning up resources.\n");

    return 0;
}