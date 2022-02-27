#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1,fd2;
    char buffer[60];
    fd1 = open("f2",O_RDWR);
    fd2 = open("f6",O_RDWR);
    read(fd1,buffer,sizeof(buffer));
    write(fd2,buffer,sizeof(buffer));
    close(fd1);
    close(fd2);
    return 0;
}