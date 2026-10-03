#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_JOBS 3

struct Job
{
    int job_id;
    pid_t pid;
    char state[20];
};

int main()
{
    struct Job jobs[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            sleep(5);
            return 0;
        }

        jobs[i].job_id = i + 1;
        jobs[i].pid = pid;
        snprintf(jobs[i].state, sizeof(jobs[i].state), "Running");
    }

    printf("Active Jobs:\n");

    for (int i = 0; i < MAX_JOBS; i++)
    {
        printf("[%d] PID: %d | State: %s\n",
               jobs[i].job_id,
               jobs[i].pid,
               jobs[i].state);
    }

    printf("\nJob listing completed.\n");

    for (int i = 0; i < MAX_JOBS; i++)
        waitpid(jobs[i].pid, NULL, 0);

    return 0;
}