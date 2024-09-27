/*
============================================================================
Name : 24.c
Author : Ashutosh Jadhav
Description : 24. Write a program to create a message queue and print the key and message queue id.
system call with FIFO.
Date: 20th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main()
{
    int msgid ;
    key_t key ;
    key = ftok(".",'a');
    msgid = msgget(key,IPC_CREAT | IPC_EXCL | 0744);
    printf("key value = %d\n",key);
    printf("key value in hex = 0x%0x \n",key);
    printf("message queue id = %d\n",msgid);
    printf("pid : %d",getpid());
}

/*
./a.out
key value = 1627521520
key value in hex = 0x610201f0 
message queue id = 0
*/
