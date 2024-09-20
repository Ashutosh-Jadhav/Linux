/*
============================================================================
Name : 8f.c
Author : Ashutosh Jadhav
Description : 8. Write a separate program using signal system call to catch the following signals.
f.SIGVTALRM (use setitimer system call)
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>

void my_handler(int sig)
{
	printf("recieved %d : SIGVTALRM \n",sig);
	exit(0);
}

int main()
{
	//struct itimerval val;
	struct itimerval val2;
	signal(26,my_handler);
	int ret ;
	val2.it_interval.tv_sec = 1;
	val2.it_interval.tv_usec = 0;
	val2.it_value.tv_sec = 1;
	val2.it_value.tv_usec = 0 ;
	ret = setitimer(ITIMER_VIRTUAL,&val2,NULL);
	while(1)
	{
	}
}

/*
./a.out
recieved 26 : SIGVTALRM 
*/