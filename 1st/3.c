/*
============================================================================
Name : 3.c
Author : Ashutosh Jadhav
Description : 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 8th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
int main()
{
	printf("fd = %d \n", creat("myfile", 0744));
}

/*
./a.out
fd = 3 
*/
