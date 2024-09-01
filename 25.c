/*
============================================================================
Name : 25.c
Author : Ashutosh Jadhav
Description : 25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int i ;
	if ((i=fork()) != 0){
		if (fork()!=0){
			if (fork()!=0){
				printf("waiting for my boy to finish...\n");
				waitpid(i,NULL,0);
			}
		}
	}
	else{
		printf("child pid is : %d \n",getpid());
		sleep(5);
	}
}

/*
 ./a.out
child pid is : 14376 
waiting for my boy to finish...
*/