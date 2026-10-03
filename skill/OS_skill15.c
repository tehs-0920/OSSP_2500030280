#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;

    fd = open("combined.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("combined.txt");
        return 1;
    }

    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);

    close(fd);

    printf("This is normal output\n");
    fprintf(stderr, "This is error output\n");

    return 0;
}