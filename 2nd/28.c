/*
============================================================================
Name : 28.c
Author : Ashutosh Jadhav
Description : 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
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
    struct msqid_ds *m = malloc(sizeof(struct msqid_ds));
    struct msqid_ds *c = malloc(sizeof(struct msqid_ds));
    key = ftok(".",'a');
    msgid = msgget(key,0);
    msgctl(msgid,IPC_STAT,m);
    printf("%hu\n",m->msg_perm.mode);

    c->msg_perm.mode = 444 ;
    msgctl(msgid,IPC_SET,c);
    printf("%hu\n",c->msg_perm.mode);

    free(c);

    free(m);
}
/*
./a.out
484
444
*/