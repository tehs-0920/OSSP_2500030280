//pipes
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    if (mkfifo("myfifo", 0666) == -1)
    {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO created\n");

    return 0;
}
//fifo read 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];

    fd = open("myfifo", O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Received: %s\n", buffer);

    close(fd);

    return 0;
}
//fifo write
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char message[] = "Hello from Writer";

    fd = open("myfifo", O_WRONLY);

    write(fd, message, strlen(message) + 1);

    close(fd);

    printf("Message sent\n");

    return 0;
}