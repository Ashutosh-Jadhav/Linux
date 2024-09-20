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
    int fd = open("myfifo",O_RDONLY);
    int fd2 = open("myfifo2",O_WRONLY);
    int r_s = read(fd,&buf,sizeof(buf));
    printf("Reading... \n ");
    write(1,&buf,r_s);
    printf("writing...\n");
    write(fd2,"How are you?\n",13);
}

/*
./write
Reading... 
Hi there 
writing...

*/