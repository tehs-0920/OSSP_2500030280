#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char *path = getenv("PATH");

    if (path == NULL)
    {
        printf("PATH variable not found\n");
        return 1;
    }

    printf("PATH = %s\n\n", path);

    char *copy = strdup(path);
    char *dir = strtok(copy, ":");

    while (dir != NULL)
    {
        printf("Directory: %s\n", dir);
        dir = strtok(NULL, ":");
    }

    free(copy);

    printf("\nChecking commands:\n");

    if (access("/bin/ls", X_OK) == 0)
        printf("ls: executable found\n");
    else
        printf("ls: executable not found\n");

    if (access("/bin/invalidcommand", X_OK) == 0)
        printf("invalidcommand: executable found\n");
    else
        printf("invalidcommand: command not found\n");

    return 0;
}