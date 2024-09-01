/*
============================================================================
Name : 23.c
Author : Ashutosh Jadhav
Description : 23. Write a program to create a Zombie state of the running program.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int i ;
	if (fork()==0){
		sleep(2);
		i = getpid();
		printf("child pid :%d  \n",i);
	}
	else
	{
		sleep(10);
	}

}

/*
./a.out
child pid :13902  


I have screenshot of zombie state
*/