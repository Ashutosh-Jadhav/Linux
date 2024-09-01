/*
============================================================================
Name : 28.c
Author : Ashutosh Jadhav
Description : 28. Write a program to get maximum and minimum real time priority.
Date: 31th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>
int main(){
	
	printf("maximum real time priority : %d\n",sched_get_priority_max(SCHED_RR));
	printf("minimum real time priority : %d\n",sched_get_priority_min(SCHED_RR));
}

/*
 ./a.out
maximum real time priority : 99
minimum real time priority : 1
*/