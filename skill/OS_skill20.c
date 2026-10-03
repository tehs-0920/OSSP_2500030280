#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t job_pid;

void handle_sigtstp(int sig)
{
    printf("\nSIGTSTP received. Suspending job...\n");
    kill(job_pid, SIGSTOP);
}

int main()
{
    int status;

    job_pid = fork();

    if (job_pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (job_pid == 0)
    {
        printf("Job started. PID: %d\n", getpid());

        for (int i = 1; i <= 10; i++)
        {
            printf("Job running: %d\n", i);
            sleep(1);
        }

        return 0;
    }

    signal(SIGTSTP, handle_sigtstp);

    printf("Job started in foreground.\n");
    printf("Press Ctrl+Z to suspend the job.\n");

    sleep(2);

    printf("Job is running...\n");

    waitpid(job_pid, &status, WUNTRACED);

    if (WIFSTOPPED(status))
    {
        printf("Job state: Stopped\n");
        printf("Job can be resumed later using SIGCONT.\n");

        kill(job_pid, SIGCONT);

        printf("SIGCONT sent. Job resumed.\n");

        waitpid(job_pid, &status, 0);

        printf("Job state: Completed\n");
    }

    return 0;
}