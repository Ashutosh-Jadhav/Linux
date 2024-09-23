/*
============================================================================
Name : 27a.c
Author : Ashutosh Jadhav
Description : 27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 20th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int msgid ;
    int size ;
    key_t key ;

    struct msg {
        long int mtype ;
        char message[80] ;
    }mq;

    key = ftok(".",'a');
    msgid = msgget(key,0);

    printf("Enter the message type to recieve: ");
    scanf("%ld",&mq.mtype);

    msgrcv(msgid,  &mq, sizeof(mq.message),mq.mtype,0);
    printf("message type : %ld\n",mq.mtype);
    printf("message text : %s\n",mq.message);
}

/*
./a.out
Enter the message type to recieve: 10
message type : 10
message text : hi there
*/