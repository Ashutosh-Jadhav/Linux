/*
============================================================================
Name : 3.c
Author : Ashutosh Jadhav
Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main()
{
	struct rlimit r ;
	getrlimit(RLIMIT_MSGQUEUE,&r);
	printf("soft limit : %ld\n",r.rlim_cur);
	printf("Hard limit : %ld\n",r.rlim_max);
	r.rlim_cur = 819000;
	setrlimit(RLIMIT_MSGQUEUE,&r);
	getrlimit(RLIMIT_MSGQUEUE,&r);
	printf("soft limit : %ld\n",r.rlim_cur);
}


/*
 ./a.out
soft limit : 819200
Hard limit : 819200
soft limit : 819000
*/