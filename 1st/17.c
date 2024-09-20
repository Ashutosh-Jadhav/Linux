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
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd1 ;
    struct{
        int ticket_no ;
    } db ;
    db.ticket_no = 100 ;
    fd1 = open("db",O_CREAT | O_RDWR , 0744);
    write(fd1,&db,sizeof(db));
    close(fd1);
    fd1 = open("db",O_RDONLY);
    read(fd1,&db,sizeof(db));
    printf("Ticket : %d\n",db.ticket_no);
    close(fd1);
}
