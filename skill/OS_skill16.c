#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        printf("Background job started. PID: %d\n", getpid());
        sleep(5);
        printf("Background job completed.\n");
        return 0;
    }

    printf("Background job launched. PID: %d\n", pid);
    printf("Parent continues immediately.\n");

    sleep(1);

    printf("Parent is monitoring the background job...\n");

    waitpid(pid, NULL, 0);

    printf("Background job finished.\n");

    return 0;
}