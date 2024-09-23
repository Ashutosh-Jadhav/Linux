/*
============================================================================
Name : 31a.c
Author : Ashutosh Jadhav
Description : 31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

union semun {
    int val ;
    struct semid_ds *buf ;
    unsigned short int *array ;
};

int main(void)
{
    int key, semid ;
    union semun arg ;
    key = ftok(".",'a');
    semid = semget(key,1,IPC_CREAT | 0744);
    arg.val = 1 ;
    semctl(semid,0,SETVAL,arg);
}

