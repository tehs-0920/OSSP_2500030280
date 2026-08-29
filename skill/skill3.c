#include <stdio.h>
#include <string.h>

char history[5][50], buffer[50];
int count = 0, pos = 0;

int main() {
    char cmd[50];

    while (1) {
        printf("\n$ ");
        fgets(cmd, 50, stdin);
        cmd[strcspn(cmd, "\n")] = 0;

        if (strcmp(cmd, "exit") == 0) break;

        if (strcmp(cmd, "up") == 0 && count > 0) {
            pos = count - 1;
            strcpy(buffer, history[pos]);
            printf("%s", buffer);
        }
        else if (strcmp(cmd, "down") == 0 && count > 0) {
            pos = (pos + 1) % count;
            strcpy(buffer, history[pos]);
            printf("%s", buffer);
        }
        else {
            strcpy(buffer, cmd);
            strcpy(history[count++], buffer);
            pos = count;
        }
    }

    return 0;
}