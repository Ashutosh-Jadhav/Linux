/*
============================================================================
Name : 5.c
Author : Ashutosh Jadhav
Description :5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

int main()
{
    printf("maximum length of the arguments to exec family : %ld\n",sysconf(_SC_ARG_MAX));
    printf("maximum number of simulaneous processes per user ID : %ld\n",sysconf(_SC_CHILD_MAX));
    printf("number of clock ticks per sec : %ld\n",sysconf(_SC_CLK_TCK));
    printf("max number of open files : %ld\n",sysconf(_POSIX_OPEN_MAX));
    printf("size of page %ld\n",sysconf(_SC_PAGESIZE));
    printf("total number of pages in the physical memory : %ld\n",sysconf(_SC_PHYS_PAGES));
    printf("number of currently avilable pages of physical memory : %ld\n",sysconf(_SC_PHYS_PAGES));
}

/*
./a.out
maximum length of the arguments to exec family : 2097152
maximum number of simulaneous processes per user ID : 30241
number of clock ticks per sec : 100
max number of open files : 200809
size of page 4096
total number of pages in the physical memory : 1953262
number of currently avilable pages of physical memory : 1953262

*/

