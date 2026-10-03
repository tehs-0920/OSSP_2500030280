#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_module(char *command)
{
    printf("Module 1: Input received\n");

    if (strlen(command) == 0)
    {
        printf("Error: Empty command\n");
        exit(1);
    }
}

void process_module(char *command)
{
    printf("Module 2: Processing command: %s\n", command);
}

void output_module()
{
    printf("Module 3: Output generated successfully\n");
}

int main()
{
    char command[100];

    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    input_module(command);
    process_module(command);
    output_module();

    printf("End-to-end execution completed.\n");

    return 0;
}
// next change od code

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void log_error(char *message)
{
    FILE *file = fopen("error.log", "a");

    if (file != NULL)
    {
        fprintf(file, "ERROR: %s\n", message);
        fclose(file);
    }

    printf("ERROR: %s\n", message);
}

int main()
{
    char command[100];

    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    if (strlen(command) == 0)
    {
        log_error("Empty command");
        printf("Recovery: Please enter a valid command.\n");
        return 1;
    }

    if (strcmp(command, "run") != 0 &&
        strcmp(command, "exit") != 0)
    {
        log_error("Invalid command syntax");
        printf("Recovery: Supported commands are run and exit.\n");
        return 1;
    }

    printf("Command accepted: %s\n", command);

    return 0;
}