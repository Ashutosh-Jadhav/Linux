/*
============================================================================
Name : 8b.c
Author : Ashutosh Jadhav
Description : 8. Write a separate program using signal system call to catch the following signals.
b. SIGint
Date: 18th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void my_handler(int sig)
{
	printf("recieved signal %d\n",sig);
	exit(0);
}

int main()
{
	signal(2,my_handler);
	while(1);
}

/*
 * ./a.out
^Crecieved signal 2
*/
