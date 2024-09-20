/*
============================================================================
Name : 6.c
Author : Ashutosh Jadhav
Description :6. Write a simple program to create three threads.
Date: 18th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* my_func(void *)
{//printf("hi there\n");
printf("thread id is : %ld\n",pthread_self());
}

int main()
{
	pthread_t mythread ;
	//printf("%ld\n",mythread);
	pthread_create(&mythread,NULL,my_func,NULL);
	//perror("");
	//printf("%ld\n",mythread);
	pthread_create(&mythread,NULL,my_func,NULL);
	//perror("");
	//printf("%ld\n",mythread);
	pthread_create(&mythread,NULL,(void *)my_func,NULL);
	//printf("pid : %d\n",getpid());
	getchar();
}

/*
 * ./a.out
thread id is : 128153804605120
thread id is : 128153794119360
thread id is : 128153783633600
 */
