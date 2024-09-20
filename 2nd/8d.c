/*
============================================================================
Name : 8d.c
Author : Ashutosh Jadhav
Description : 8. Write a separate program using signal system call to catch the following signals.
d.SIGALRM (use alarm system call)
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void my_handler(int sig)
{
	printf("recieved SIGALRM\n");
	exit(0);
}

int main()
{
	alarm(3);
	signal(14,my_handler);
	while(1){}
}

/*
./a.out
recieved SIGALRM
*/
