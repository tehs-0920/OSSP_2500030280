#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void pwd()
{
    char path[1024];

    if (getcwd(path, sizeof(path)) != NULL)
        printf("%s\n", path);
}

void echo()
{
    printf("Hello from built-in command\n");
}

void exit_shell()
{
    printf("Exiting shell...\n");
    exit(0);
}

struct Builtin
{
    char *name;
    void (*function)();
};

int main()
{
    struct Builtin commands[] =
    {
        {"pwd", pwd},
        {"echo", echo},
        {"exit", exit_shell}
    };

    char command[50];
    int found = 0;

    printf("Enter command: ");
    scanf("%49s", command);

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(command, commands[i].name) == 0)
        {
            commands[i].function();
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Invalid command\n");

    return 0;
}