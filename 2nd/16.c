/*
============================================================================
Name : 16.c
Author : Ashutosh Jadhav
Description : 16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1[2] ;
	int fd2[3] ;
	int i , double_i ;
	pipe(fd1);
	pipe(fd2);
	if (!fork())
	{
		// child will execute it..
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0],&i,sizeof(i));
		printf("received i from parent , now doubling it...\n");
		double_i = 2*i ;
		write(fd2[1],&double_i,sizeof(double_i));
		printf("sending to parent ...\n");
	}
	else 
	{
		// parent will execute 
		close(fd1[0]);
		close(fd2[1]);
		printf("Enter i to send to child : ");
		scanf("%d",&i);
		write(fd1[1],&i,sizeof(i));
		read(fd2[0],&double_i,sizeof(double_i));
		printf("child gives ans : %d \n",double_i);
	}
}


/*
./a.out
Enter i to send to child : 8
received i from parent , now doubling it...
sending to parent ...
child gives ans : 16 
*/