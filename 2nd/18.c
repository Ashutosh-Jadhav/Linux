/*
============================================================================
Name : 18.c
Author : Ashutosh Jadhav
Description :18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int fd[2];
	pipe(fd);
	if (!fork())
	{
		// child will execute 
		int fd1[2];
		pipe(fd1);
		if (!fork())
		{
			close(fd[1]);
			close(fd[0]);
			// child of child will execute this
			close(fd1[0]);
			dup2(fd1[1],1);
			sleep(1);
			execl("/bin/ls","ls","-l",NULL);
		}
		else 
		{
			char buf[1024];
			close(fd[0]);
			dup2(fd[1],1);
			close(fd1[1]);
			dup2(fd1[0],0);
			read(fd1[0],&buf,sizeof(buf));

			sleep(2);
			//wait(0);
			execl("/bin/grep","grep","^d",NULL);
		}
	}
	else 
	{
		char buf[1024];
		close(fd[1]);
		dup2(fd[0],0);
		sleep(3);
		//read(0,&buf,sizeof(buf));
		//wait(0);
		execl("/bin/wc","wc",NULL);
	}
}


/*
./a.out
      2      18     106
*/