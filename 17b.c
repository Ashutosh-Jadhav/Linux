/*
============================================================================
Name : 17.c
Author : Ashutosh Jadhav
Description : 17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    struct {
        int ticket_no ;
    } db;
    struct flock lock ;
    int fd1 ;
    fd1 = open("db",O_RDWR);
    read(fd1,&db,sizeof(db));
    lock.l_type = F_WRLCK ;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0 ;
    lock.l_pid = getpid();
    printf("Before entering into critical section...\n");
    fcntl(fd1,F_SETLKW,&lock);
    printf("current ticket number : %d \n",db.ticket_no);
    db.ticket_no++;
    lseek(fd1,0L,SEEK_SET);
    printf("Inside the critical section...\n");
    write(fd1,&db,sizeof(db));
    printf("Enter to unlock...\n");
    getchar();
    lock.l_type = F_UNLCK;
    printf("unlocked...\n");
    fcntl(fd1,F_SETLK,&lock);
    printf("finish\n");
}

/*
./a.out
Before entering into critical section...
current ticket number : 102 
Inside the critical section...
Enter to unlock...

unlocked...
finish
*/
