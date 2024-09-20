/*
============================================================================
Name : 17a.c
Author : Ashutosh Jadhav
Description : 7. Write a simple program to print the created thread ids.
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
        getchar();
}

/*
./a.out
thread id is : 135517526034112
 */
