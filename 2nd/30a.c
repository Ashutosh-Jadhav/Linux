/*
============================================================================
Name : 30a.c
Author : Ashutosh Jadhav
Description : 30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main()
{
    int key, shm ;
    char *p ;
    key = ftok(".",'a');
    shm = shmget(key,102,IPC_CREAT | 0744);
    perror("");
    p = (char *) shmat(shm,NULL,0);
    perror("");
    printf("%d\n",shm);
    printf("Enter a string : ");
    // p = (char *)p;
    scanf("%[^\n]",p);
    getchar();
    getchar();
    shmdt(p);
    perror("");
    shmctl(shm,IPC_RMID,NULL);
    perror("");

}
/*
./a.out
Success
Success
950283
Enter a string : Ashu

Success
Success
*/
