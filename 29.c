/*
============================================================================
Name : 29.c
Author : Ashutosh Jadhav
Description : 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 31th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>
int main(){
    int new_p, old_p,x;
    struct sched_param* s = malloc(sizeof(struct sched_param));
    sched_setscheduler(getpid(),SCHED_RR,s);
    s->sched_priority = 8;
    //sched_setscheduler(0,SCHED_FIFO,s);
    old_p= sched_getscheduler(0);
    if (old_p == 0)
    {
        printf("Current scheduling policy is Round Robin\n");
        x = sched_setscheduler(0,SCHED_FIFO,s);
        new_p = sched_getscheduler(getpid());
        if (new_p == 1)
        {
            printf("new policy is  : FIFO\n");
        }
    }
    else 
    {
        printf("Current scheduling policy is FIFO\n");
        sched_setscheduler(getpid(),SCHED_RR,s);
    }
    free(s);
}

/*
sudo ./a.out
Current scheduling policy is Round Robin
new policy is  : FIFO
*/
