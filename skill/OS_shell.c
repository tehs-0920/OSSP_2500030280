#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 100
#define MAX_ARGS 20

int main()
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1)
    {
        printf("myshell> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
            continue;

        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting shell...\n");
            break;
        }

        int count = 0;
        char *token = strtok(input, " ");

        while (token != NULL && count < MAX_ARGS - 1)
        {
            args[count++] = token;
            token = strtok(NULL, " ");
        }

        args[count] = NULL;

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("fork");
            continue;
        }

        if (pid == 0)
        {
            execvp(args[0], args);

            perror("Command failed");
            exit(1);
        }
        else
        {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}