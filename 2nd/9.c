/*
============================================================================
Name : 9.c
Author : Ashutosh Jadhav
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	signal(2,SIG_IGN);
    printf("ignoring SIGINT\n");
    sleep(5);
    printf("set to default\n");
    signal(2,SIG_DFL);
	while(1){}
}

/*
 ./a.out
ignoring SIGINT
^C^C^C^C^C^Cset to default
^C
*/