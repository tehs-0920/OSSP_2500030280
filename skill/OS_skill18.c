#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig)
{
    printf("\nSignal received: %d\n", sig);
    printf("Process handled the signal.\n");
}

int main()
{
    signal(SIGINT, handle_signal);

    printf("Process ID: %d\n", getpid());
    printf("Press Ctrl+C to send SIGINT.\n");
    printf("Process is running...\n");

    for (int i = 1; i <= 5; i++)
    {
        printf("Running: %d\n", i);
        sleep(2);
    }

    printf("Process completed.\n");

    return 0;
}