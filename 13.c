/*
============================================================================
Name : 13.c
Author : Ashutosh Jadhav
Description : 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>
int main(){
    int offset=0;
    char buf[1024];
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(0,&rfds);
    struct timeval t;
    t.tv_sec = 10; 
    t.tv_usec=0;
    printf("Enter within  10 secs \n");
    int ret = select(1,&rfds,0,0,&t);
    if(ret &&  FD_ISSET(0,&rfds)){
        offset= read(0,buf,sizeof(buf));
    }
    else{
        printf("Sorry timeout\n");
        exit(0);
    }
    for(int i=0;i<offset;i++) 
    {
        printf("%c",buf[i]);
    }
}

/* 
./a.out
Enter within  10 secs 
ashutos
ashutos
*/