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

int main(){
    int fd = open("myfifo1",O_RDWR);
    int offset=0;
    char buf[1024];
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(0,&rfds);
    struct timeval t;
    t.tv_sec = 10;
    t.tv_usec=0;
    printf("Enter within  10 secs \n");
    int ret = select(fd,&rfds,0,0,&t);
    if(ret &&  FD_ISSET(0,&rfds)){
        offset= read(0,buf,sizeof(buf));
    }
    else{
        printf("Sorry timeout\n");
        exit(0);
    }
    printf("%s\n",buf);
}
