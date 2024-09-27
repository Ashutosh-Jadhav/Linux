/*
============================================================================
Name : 17a.c
Author : Ashutosh Jadhav
Description : 17. Write a program to execute ls -l | wc.
a. use dup
Date: 18th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int i ;
     	int fd[2];
	pipe(fd);
	if (!fork())
	{
		// child executes
		close(1);
		close(fd[0]);
		dup(fd[1]);
		execl("/bin/ls","ls","-l",NULL);
	}
	else {
		close(fd[1]);
		close(0);
		//sleep(2);
		dup(fd[0]);
		//read(0,&buf,sizeof(buf));
		execl("/bin/wc","wc",NULL);
	}
}

/*
./a.out
     36     317    1931
*/