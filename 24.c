/*
============================================================================
Name : 24.c
Author : Ashutosh Jadhav
Description : 24. Write a program to create an orphan process.
Date: 31th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	if (fork()==0){
		sleep(1);
		for(;;);
	}
	else{
		printf("parent pid : %d \n",getpid());
	}
}

/*
 ./a.out
parent pid : 14145 

I have screenshot of orphan process.
*/