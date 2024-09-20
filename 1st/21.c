/*
============================================================================
Name : 21.c
Author : Ashutosh Jadhav
Description : 21. Write a program, call fork and print the parent and child process id.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int ppid,cid;
	if (fork()==0){
		cid = getpid();
		printf("child pid is : %d\n ",cid);
	}
	else {
		ppid = getpid();
		printf("parent pid is : %d\n",ppid);
	}
}

/*
./a.out
parent pid is : 13307
child pid is : 13308
*/