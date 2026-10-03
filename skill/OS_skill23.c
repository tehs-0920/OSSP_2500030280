#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define JOBS 3

int main()
{
    int pipes[JOBS - 1][2];
    pid_t pids[JOBS];
    time_t start, end;

    start = time(NULL);

    for (int i = 0; i < JOBS - 1; i++)
        pipe(pipes[i]);

    for (int i = 0; i < JOBS; i++)
    {
        pids[i] = fork();

        if (pids[i] == 0)
        {
            if (i > 0)
                dup2(pipes[i - 1][0], STDIN_FILENO);

            if (i < JOBS - 1)
                dup2(pipes[i][1], STDOUT_FILENO);

            for (int j = 0; j < JOBS - 1; j++)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            if (i == 0)
                execlp("ls", "ls", NULL);
            else if (i == 1)
                execlp("grep", "grep", ".c", NULL);
            else
                execlp("wc", "wc", "-l", NULL);

            perror("exec");
            return 1;
        }
    }

    for (int i = 0; i < JOBS - 1; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    for (int i = 0; i < JOBS; i++)
        waitpid(pids[i], NULL, 0);

    end = time(NULL);

    printf("Pipeline completed successfully.\n");
    printf("Jobs executed: %d\n", JOBS);
    printf("Execution time: %ld seconds\n", end - start);

    return 0;
}