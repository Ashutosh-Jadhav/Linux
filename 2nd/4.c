/*
============================================================================
Name : 4.c
Author : Ashutosh Jadhav
Description :4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc()
{
	unsigned long long dst ;
	__asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main(){
	int i ;
	float nano ; 
	unsigned long long start, end ;
	start = rdtsc();
	for (int j=0; j <= 100; j++ ){
		getppid();
	}
	end = rdtsc();
	nano = (end - start)/2.09 ;
	printf("time taken : %2f nano sec\n",nano);
}

/*
./a.out
time taken : 17340.669922 nano sec
*/