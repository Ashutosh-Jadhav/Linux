/*
============================================================================
Name : 10c.c
Author : Ashutosh Jadhav
Description : 10. Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void my_handler()
{
	printf("Catched SIGFPE\n");
	exit(0);
}

int main()
{
	int i,j;
    struct sigaction s;
    s.sa_handler = my_handler;
	sigaction(8,&s,NULL);
    i = 1/0;

    while(1){}
}

/*
./a.out
Catched SIGFPE
*/