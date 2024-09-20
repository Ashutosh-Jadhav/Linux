/*
============================================================================
Name : 11.c
Author : Ashutosh Jadhav
Description : 11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    struct sigaction s;
    s.sa_handler = SIG_IGN;
    sigaction(2,&s,NULL);
    printf("ignoring SIGINT\n");
    sleep(5);
    s.sa_handler = SIG_DFL;
    printf("set to default\n");
    sigaction(2,&s,NULL);
	while(1){}
}

/*
./a.out
ignoring SIGINT
^C^Cset to default
^C
*/