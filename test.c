#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    
    fd = open("file_that_doesnt_exist.txt", O_RDONLY);
    printf("fd = %d\n", fd);
    printf("errno = %d\n", errno);
    printf("errno = %s\n", errno);
    return 0;
}