/*
============================================================================
Name : 32c.c
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
    int key1, key2, semid1, semid2 ;
    key1 = ftok(".",'a');
    key2 = ftok(".",'b');
    semid1 = semget(key1,1,0);
    semid2 = semget(key2,1,0);
    semctl(semid1,0,IPC_RMID);
    semctl(semid2,0,IPC_RMID);
}

/*
ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610201f0 0          ashutosh   744        1         
0x620201f0 1          ashutosh   744        1         

ashutosh@coolguy:~/hands_on_list/2nd$ ./a.out
ashutosh@coolguy:~/hands_on_list/2nd$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     

ashutosh@coolguy:~/hands_on_list/2nd$ 

*/