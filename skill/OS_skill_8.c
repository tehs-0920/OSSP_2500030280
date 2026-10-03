#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expand(char *token)
{
    if (token[0] == '$')
    {
        char *value = getenv(token + 1);

        if (value != NULL)
            printf("%s = %s\n", token, value);
        else
            printf("%s = undefined\n", token);
    }
    else
    {
        printf("%s = not a variable\n", token);
    }
}

int main()
{
    setenv("NAME", "Tehseen", 1);
    setenv("COURSE", "OS", 1);

    printf("Variable Expansion:\n");

    expand("$NAME");
    expand("$COURSE");
    expand("$UNKNOWN");

    return 0;
}