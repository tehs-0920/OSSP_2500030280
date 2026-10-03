#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig)
{
    printf("\nSignal received: %d\n", sig);
    printf("Signal handled safely.\n");
}

int main()
{
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Signal handlers registered.\n");
    printf("Process ID: %d\n", getpid());
    printf("Press Ctrl+C to test SIGINT.\n");

    for (int i = 1; i <= 5; i++)
    {
        printf("Process running: %d\n", i);
        sleep(2);
    }

    printf("Process completed normally.\n");

    return 0;
}