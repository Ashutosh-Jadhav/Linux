/*
============================================================================
Name : 17b.c
Author : Ashutosh Jadhav
Description : 17. Write a program to execute ls -l | wc.
b. use dup2
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
		close(fd[0]);
		dup2(fd[1],1);
		execl("/bin/ls","ls","-l",NULL);
	}
	else {
		close(fd[1]);
        dup2(fd[0],0);
		//read(0,&buf,sizeof(buf));
		execl("/bin/wc","wc",NULL);
	}
}

/*
./a.out
     36     317    1931
*/