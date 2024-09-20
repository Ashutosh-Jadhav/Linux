/*
============================================================================
Name : 12.c
Author : Ashutosh Jadhav
Description : 12. Write a program to find out the opening mode of a file. Use fcntl.
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int agrc, char *argv[])
{
	int fd1,res,res1;
	fd1 = open(argv[1],O_RDWR);
	res = fcntl(fd1,F_GETFL);
	res1 = res & 3 ;
	if(res1==0)
		printf("Read Only \n");
	else if(res1==1)
		printf("Write Only \n");
	else
		printf("Read and Write \n");
}

/*
./a.out myfile
Read and Write 
*/

