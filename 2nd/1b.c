
/*
============================================================================
Name : 1b.c
Author : Ashutosh Jadhav
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
b. ITIMER_VIRTUAL
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
}

int main()
{
	//struct itimerval val;
	struct itimerval val2;
	signal(26,my_handler);
	int ret ;
	val2.it_interval.tv_sec = 10;
	val2.it_interval.tv_usec = 10;
	val2.it_value.tv_sec = 10;
	val2.it_value.tv_usec = 10 ;
	ret = setitimer(ITIMER_VIRTUAL,&val2,NULL);
	while(1)
	{
	}
}

/*
./a.out
recieved 26 : SIGVTALRM 
recieved 26 : SIGVTALRM 
*/