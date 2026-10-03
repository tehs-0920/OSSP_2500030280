#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 5
#define MAX_LENGTH 100

int main()
{
    char history[MAX_HISTORY][MAX_LENGTH];
    int count = 0;
    char command[MAX_LENGTH];

    printf("Enter commands (type 'done' to finish):\n");

    while (count < MAX_HISTORY)
    {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "done") == 0)
            break;

        strcpy(history[count], command);
        count++;
    }

    printf("\nCommand History:\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d: %s\n", i + 1, history[i]);
    }

    printf("\nTotal commands stored: %d\n", count);

    if (count == MAX_HISTORY)
        printf("History capacity reached.\n");

    return 0;
}