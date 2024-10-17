/*
============================================================================
Name : 18b.c
Author : Ashutosh Jadhav
Description : 18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 31th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
    struct {
        int train_no ;
        int ticket_no ;
    } db ;
    int fd1,train ;
    printf("which train to read 1 ,2 or 3 : ");
    scanf("%d",&train);
    fd1 = open("db1",O_RDONLY);
    
    struct flock lock ;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET ;
    lock.l_start = (train-1)*sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();

    lseek(fd1,(train-1)*sizeof(db),SEEK_SET);
    read(fd1,&db,sizeof(db));
    printf("before entering into critical section...\n");
    fcntl(fd1,F_SETLKW,&lock);
    printf("ticket number : %d\n",db.ticket_no);
    printf("to exit press a key \n");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd1,F_SETLK,&lock);
    printf("finished...\n");
}

/*
./a.out
which train to read 1 ,2 or 3 : 1
before entering into critical section...
ticket number : 100
to exit press a key 

finished...
*/