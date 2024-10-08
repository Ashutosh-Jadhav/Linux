/*
============================================================================
Name : 8.c
Author : Ashutosh Jadhav
Description : 8. Write a separate program using signal system call to catch the following signals.
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
	signal(11,my_handler);
	scanf("%d",(int *)i);
}

/* ./a.out
9
Catched SIGSEGV
*/
