/*
============================================================================
Name : 12.c
Author : Ashutosh Jadhav
Description : 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    if (!fork())
    {
        // child will execute
        int i = getppid();
        printf("parent id before killing : %d\n",i);
        kill(i,9);
        sleep(1);
        i = getppid();
        printf("parent id after killing : %d\n",i);
    }
    else
    {
        while(1){}
    }
}

/*
./a.out
parent id before killing : 23500
Killed
ashutosh@coolguy:~/hands_on_list/2nd$ parent id after killing : 2591
*/