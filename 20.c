/*
============================================================================
Name : 20.c
Author : Ashutosh Jadhav
Description : 20. Find out the priority of your running program. Modify the priority with nice command.
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    int new_p,old_p;
    old_p=getpriority(PRIO_PROCESS,0);
    printf("old priority : %d\n",old_p);
    new_p=nice(19);
    printf("new priority : %d\n",new_p);
    return 0;
}

/*
./a.out
old priority : 0
new priority : 19
*/
