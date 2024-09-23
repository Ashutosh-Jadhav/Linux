/*
============================================================================
Name : 23.c
Author : Ashutosh Jadhav
Description : 23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

int main()
{
    printf("max number of open files : %ld\n",sysconf(_POSIX_OPEN_MAX));
    
}