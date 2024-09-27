/*
============================================================================
Name : 14.c
Author : Ashutosh Jadhav
Description : 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd[2];
	int i,j;
	char buf[14];
	pipe(fd);
	if(!fork())
	{
		close(fd[0]);
		printf("Child writing...\n");
		write(fd[1],"Hello There",11);
	}
	else
	{
		close(fd[1]);
		read(fd[0],buf,11);
		printf("parent reading : %s\n",buf);
	}
}
/*
./a.out
Child writing...
parent reading : Hello There
*/