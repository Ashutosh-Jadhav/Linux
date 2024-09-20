/*
============================================================================
Name : 13.c
Author : Ashutosh Jadhav
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int sig)
{
    printf("was able to catch\n");
    exit(0);
}

int main()
{
    struct sigaction s;
    s.sa_handler = my_handler;
    printf("pid : %d\n",getpid());
    sigaction(19,&s,NULL);
    printf("waiting for SIG_STOP signal\n");
    while(1){}
}