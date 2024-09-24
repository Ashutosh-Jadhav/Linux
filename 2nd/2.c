/*
============================================================================
Name : 2.c
Author : Ashutosh Jadhav
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main()
{
	struct rlimit p;
	int i = getrlimit(RLIMIT_MSGQUEUE,&p);
	if (!i)
		perror("");
	if (p.rlim_cur == RLIM_INFINITY)
		printf("RLIM_INFINITY\n");
	printf("message queue limits..\n");
	printf("Soft limit : %ld\n",p.rlim_cur);
	printf("Hard limit : %ld\n",p.rlim_max);

	getrlimit(RLIMIT_AS ,&p);
	if (p.rlim_cur == RLIM_INFINITY)
		printf("No limit on maximum size of the process's virtual memory\n");
	else {
	printf("Soft limit : %ld\n",p.rlim_cur);
	printf("Hard Limit : %ld \n",p.rlim_max);}
	
	getrlimit(RLIMIT_CORE, &p);
	if (p.rlim_cur == RLIM_INFINITY)
		printf("No limit on maximum size of core file.\n");
	else {
		printf("limit on maximum size of core file...\n");
		printf("Soft limit : %ld\n",p.rlim_cur);
        	printf("Hard Limit : %ld \n",p.rlim_max);
	}

	getrlimit(RLIMIT_CPU, &p);
	if (p.rlim_cur == RLIM_INFINITY)
	{
		printf("no limit on the amount of cpu time that the process can consume\n");
	}
	else{
	printf("Softlimit : %ld\n",p.rlim_cur);
	printf("Hardlimit : %ld\n",p.rlim_cur);}
	
	getrlimit(RLIMIT_FSIZE,&p);
	if(p.rlim_cur == RLIM_INFINITY){
		printf("no limit on maximum size of files that the process may create\n");
	}

	getrlimit(RLIMIT_DATA,&p);
	if (p.rlim_cur == RLIM_INFINITY)
	{
		printf("no limit on the size of the process data segment\n");
	}
	
}


/*
./a.out
Success
message queue limits..
Soft limit : 819200
Hard limit : 819200
No limit on maximum size of the process's virtual memory
limit on maximum size of core file...
Soft limit : 0
Hard Limit : -1 
no limit on the amount of cpu time that the process can consume
no limit on maximum size of files that the process may create
no limit on the size of the process data segment
*/