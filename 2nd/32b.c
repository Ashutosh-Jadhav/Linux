/*
============================================================================
Name : 32b.c
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
#include <sys/shm.h>

int main()
{
    int key, shmid ,semid;
    char *p ;
    key = ftok(".",'a');
    struct sembuf buf = {0,-1,0};
    semid = semget(key,1,0);
    shmid = shmget(key,0,0);
    printf("before entering into critical section...\n");
    printf("waiting for the lock...\n");

    semop(semid,&buf,1);
    p = (char *) shmat(shmid,NULL,0);
    printf("inside the critical section...\n");
    printf("pesent val is : %s\n",p);
    printf("Enter a string : ");
    scanf("%[^\n]",p);

    printf("enter to unlock");
    getchar();
    getchar();
    buf.sem_op = 1 ;
    semop (semid,&buf,1);
    printf("unlocked...\n");


}

/*
 ./a.out
before entering into critical section...
waiting for the lock...
inside the critical section...
pesent val is : Ashutosh
Enter a string : Hayat
enter to unlock
unlocked...

./a.out
before entering into critical section...
waiting for the lock...
inside the critical section...
pesent val is : Hayat
Enter a string : 

*/