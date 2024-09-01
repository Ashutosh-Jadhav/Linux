/*
============================================================================
Name : 18.c
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

int main()
{
    struct {
        int train_no ;
        int ticket_no ;
    } db[3];
    int fd1;
    fd1 = open("db1",O_CREAT | O_RDWR,0744);
    for (int i = 0; i < 3 ; i++)
    {
        db[i].train_no = i+1;
        db[i].ticket_no = 100 ;
        write(fd1,&db[i],sizeof(db));
    }
    close(fd1);
    fd1 = open("db1",O_RDONLY);
    for(int i=0;i<3;i++)
    {
        printf("Train no is : %d\n",db[i].train_no);
        printf("Ticket no is : %d \n",db[i].ticket_no);
    }
}


