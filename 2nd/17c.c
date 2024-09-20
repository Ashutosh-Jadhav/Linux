/*============================================================================
Name : 17c.c
Author : Ashutosh Jadhav
Description : 17. Write a program to execute ls -l | wc.
c. use fcntl
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
        fcntl(fd[1],F_DUPFD);
		execl("/bin/ls","ls","-l",NULL);
	}
	else {
		close(fd[1]);
        close(0);
        fcntl(fd[0],F_DUPFD);
		//read(0,&buf,sizeof(buf));
		execl("/bin/wc","wc",NULL);
	}
}

/*
./a.out
     38     335    2043
*/