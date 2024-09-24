/*
============================================================================
Name : 1a.c
Author : Ashutosh Jadhav
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void my_handler()
{
	printf("signal milra hai 10sec 10 micro sec ke baad, nice one \n");
}

int main()
{
	//struct itimerval val;
	struct itimerval val2;
	signal(14,my_handler);
	int ret ;
	val2.it_interval.tv_sec = 10;
	val2.it_interval.tv_usec = 10;
	val2.it_value.tv_sec = 10;
	val2.it_value.tv_usec = 10 ;
	//printf("%ld \n",val.it_interval.tv_sec);
	//printf("%ld \n",val.it_interval.tv_usec);
	ret = setitimer(ITIMER_REAL,&val2,NULL);
	perror("");
	//alarm(3);
	printf("%d\n",ret);
	//signal(14,my_handler);
	while(1)
	{
		//signal(14,my_handler);
	}
}

/*
 ./a.out
Success
0
signal milra hai 10sec 10 micro sec ke baad, nice one 
signal milra hai 10sec 10 micro sec ke baad, nice one 
*/