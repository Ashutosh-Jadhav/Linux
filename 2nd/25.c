/*
============================================================================
Name : 25.c
Author : Ashutosh Jadhav
Description : 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
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
    printf("acess permission : %hu\n",m->msg_perm.mode);
    printf("uid : %d\n",m->msg_perm.uid);
    printf("gid : %d\n",m->msg_perm.gid);
    printf("Time of last msg sent : %ld\n",m->msg_stime);
    printf("Time of last msg recieved : %ld\n",m->msg_rtime);
    printf("last change in the message queue: %ld\n",m->msg_ctime);
    printf("size of the queue : %lu\n",m->msg_cbytes);
    printf("number of messages in message queue: %ld\n",m->msg_qnum);
    printf("maximum number of bytes allowed : %ld\n",m->msg_qbytes);
    printf("pid of msgsnd : %d\n",m->msg_lspid);
    printf("pid of msgrcv : %d\n",m->msg_lrpid);

    free(c);
    free(m);
}


/*
./a.out
acess permission : 444
uid : 0
gid : 0
Time of last msg sent : 1727104902
Time of last msg recieved : 1727104912
last change in the message queue: 1727108056
size of the queue : 0
number of messages in message queue: 0
maximum number of bytes allowed : 0
pid of msgsnd : 6901
pid of msgrcv : 6909

*/
