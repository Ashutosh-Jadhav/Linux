/*
============================================================================
Name : 8b.c
Author : Ashutosh Jadhav
Description : 8. Write a separate program using signal system call to catch the following signals.
c.SIGFPE
Date: 18th Sep, 2024.
============================================================================
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_handler(void)
{
	printf("signal SIGFPE recieved\n");
	exit(0);
}

int main()
{
	signal(8,my_handler);
	int i = 1/0;
}

/*
 * ./a.out
signal SIGFPE recieved
*/
