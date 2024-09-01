/*
============================================================================
Name : 26a.c
Author : Ashutosh Jadhav
Description : 26. Write a program to execute an executable program.
               a. use some executable program
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	execl(argv[1],"a.out",NULL);
}

/*
cc 3.c -o myout
./a.out myout
fd = 3 
*/