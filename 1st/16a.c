/*
============================================================================
Name : 16a.c
Author : Ashutosh Jadhav
Description : 16. Write a program to perform mandatory locking.
a. Implement write lock
Date: 14th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc,char *argv[]){
        struct flock lck ;
        int fd ;
        fd = open(argv[1],O_RDWR);
        lck.l_start = 0;
        lck.l_len = 0 ;
        lck.l_type = F_WRLCK;
        lck.l_whence = SEEK_SET;
        lck.l_pid = getpid();
	printf("before entering into the critical section \n");
        fcntl(fd,F_SETLKW,&lck);
        printf("Inside the critical section... \n");
        printf("Enter l to unlock..\n");
        char c= getchar();
        if(c=='l'){ lck.l_type= F_UNLCK;}
        fcntl(fd,F_SETLK,&lck);
        printf("unlocked\n");
        printf("finish \n");
}

/*
./a.out
before entering into the critical section 
Inside the critical section... 
Enter l to unlock..
l
unlocked
finish 
*/

