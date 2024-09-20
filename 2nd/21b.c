/*
============================================================================
Name : 21a.c
Author : Ashutosh Jadhav
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char buf[1024];
    int fd = open("myfifo",O_WRONLY);
    int fd2 = open("myfifo2",O_RDONLY);
    printf("writing...\n");
    write(fd,"Hi there \n",10);
    int s_r = read(fd2,&buf,sizeof(buf));
    printf("reading...\n");
    write(1,&buf,s_r);

}

/*
./read
writing...
reading...
How are you?
*/