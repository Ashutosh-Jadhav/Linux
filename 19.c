/*
============================================================================
Name : 19.c
Author : Ashutosh Jadhav
Description : 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 31th Aug, 2024.
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

int main(void){
    int i, nano ;
    unsigned long long int start, end ;
    start = rdtsc();
    getpid();
    end= rdtsc();
    nano = (end-start)/2.09;
    printf("The funtion takes %d nano sec\n",nano);

}

// The `funtion takes 2926 nano sec
