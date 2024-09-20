
/*
============================================================================
Name : 1c.c
Author : Ashutosh Jadhav
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
c. ITIMER_PROF
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
	printf("recieved %d : SIGPROF \n",sig);
}

int main()
{
    int ret;
	//struct itimerval val;
	struct itimerval val2;
	signal(27,my_handler);
	val2.it_interval.tv_sec = 10;
	val2.it_interval.tv_usec = 10;
	val2.it_value.tv_sec = 10;
	val2.it_value.tv_usec = 10 ;
	ret = setitimer(ITIMER_PROF,&val2,NULL);
	while(1)
	{
	}
}

/*
./a.out
recieved 27 : SIGPROF 
recieved 27 : SIGPROF 
*/