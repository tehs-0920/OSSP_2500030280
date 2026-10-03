#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buffer[100];

    fd = open("input.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("input.txt");
        return 1;
    }

    dup2(fd, STDIN_FILENO);
    close(fd);

    printf("Reading from input.txt:\n");

    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
        printf("%s", buffer);

    return 0;
}