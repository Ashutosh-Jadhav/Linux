/*
============================================================================
Name : 29.c
Author : Ashutosh Jadhav
Description : 29. Write a program to remove the message queue.
Date: 20th Sep, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int key,msgid ;
    key = ftok(".",'a');
    msgid = msgget(key,0);
    msgctl(msgid,IPC_RMID,NULL);
}

/*
ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x610201f0 0          root       674        0            0           

ashutosh@coolguy:~/hands_on_list/2nd$ ./a.out
ashutosh@coolguy:~/hands_on_list/2nd$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
*/