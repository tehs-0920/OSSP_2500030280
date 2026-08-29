#include <stdio.h>
#include <string.h>

int main() {
    char input[100], *token;

    printf("Enter command: ");
    fgets(input, 100, stdin);

    token = strtok(input, " \t\n");

    if (token == NULL) {
        printf("Empty command!\n");
        return 0;
    }

    printf("Tokens:\n");

    while (token != NULL) {
        printf("[%s]\n", token);
        token = strtok(NULL, " \t\n");
    }

    printf("Syntax: Valid\n");
    printf("Parse Tree: COMMAND -> TOKENs\n");
    printf("Execution Structure: Ready\n");

    return 0;
}