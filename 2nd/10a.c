/*
============================================================================
Name : 10a.c
Author : Ashutosh Jadhav
Description : 10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void my_handler()
{
	printf("Catched SIGSEGV\n");
	exit(0);
}

int main()
{
	int i,j;
    struct sigaction s;
    s.sa_handler = my_handler;
	sigaction(11,&s,NULL);

	scanf("%d",(int *)i);
}

/*
 ./a.out
9
Catched SIGSEGV
*/