/*
============================================================================
Name : 32a.c
Author : Ashutosh Jadhav
Description : 32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <fcntl.h>

int main()
{
    struct {
        int ticket_no ;
    } db;
    int key, semid;
    int fd1 ;
    key = ftok(".",'a');
    struct sembuf buf = {0,-1,0} ;
    semid = semget(key,1,0);
    fd1 = open("db",O_RDWR);
    read(fd1,&db,sizeof(db));

    printf("Before entering into critical section...\n");
    printf("waiting for unlock...\n");

    semop(semid,&buf,1);
    printf("current ticket number : %d \n",db.ticket_no);
    db.ticket_no++;
    lseek(fd1,0L,SEEK_SET);
    printf("Inside the critical section...\n");
    write(fd1,&db,sizeof(db));
    printf("Enter to unlock...\n");
    getchar();
    buf.sem_op = 1;
    semop(semid,&buf,1);
    printf("unlocked...\n");
    
    printf("finish\n");
}

/*
./a.out
Before entering into critical section...
waiting for unlock...
current ticket number : 104 
Inside the critical section...
Enter to unlock...

unlocked...
finish

*/