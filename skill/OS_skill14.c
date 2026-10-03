#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
    {
        perror("output.txt");
        return 1;
    }

    dup2(fd, STDOUT_FILENO);
    close(fd);

    printf("New line added using append redirection\n");

    return 0;
}