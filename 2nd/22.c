/*
============================================================================
Name : 22.c
Author : Ashutosh Jadhav
Description : 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main(void)
{
    char buf[3];
    int retval,fd ;
    fd_set wrfds ;
    struct timeval tv ;
    fd = open("myfifo",O_WRONLY);
    FD_ZERO(&wrfds);
    FD_SET(fd , &wrfds);

    tv.tv_sec = 10 ;
    tv.tv_usec = 0 ;

    retval = select(2,NULL,&wrfds,NULL,&tv);
    perror("");
    printf("ho gaya \n");
    // read(0,buf,sizeof(buf));
    write(fd,"hi",2);

    if (retval)
    {
        printf("data was avilable... \n");
    }
    else 
    {
        printf("no data within 10 secs...\n");
    }

}
/*
 ./a.out
Success
ho gaya 
no data within 10 secs...
*/
