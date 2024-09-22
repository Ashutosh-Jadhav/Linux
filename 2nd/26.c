/*
============================================================================
Name : 26.c
Author : Ashutosh Jadhav
Description : 26. Write a program to send messages to the message queue. Check $ipcs -q
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
        char message[80] ;
    }mq;

    key = ftok(".",'a');
    msgid = msgget(key,0);

    printf("Enter the message text : ");
    scanf("%[^\n]",mq.message);
    size = strlen(mq.message);

    msgsnd(msgid,  &mq, size+1,0);
}
