#include <stdio.h>
#include <string.h>

int process_command(char *command)
{
    if (strcmp(command, "run") == 0)
        return 1;

    if (strcmp(command, "exit") == 0)
        return 1;

    return 0;
}

int main()
{
    char *tests[] = {"run", "exit", "hello"};
    int expected[] = {1, 1, 0};

    int total = 3;
    int passed = 0;

    printf("Running Test Cases...\n\n");

    for (int i = 0; i < total; i++)
    {
        int result = process_command(tests[i]);

        printf("Test %d: %s -> ", i + 1, tests[i]);

        if (result == expected[i])
        {
            printf("PASS\n");
            passed++;
        }
        else
        {
            printf("FAIL\n");
        }
    }

    printf("\nTest Report:\n");
    printf("Passed: %d/%d\n", passed, total);
    printf("Failed: %d/%d\n", total - passed, total);

    return 0;
}