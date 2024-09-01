/*
============================================================================
Name : 6.c
Author : Ashutosh Jadhav
Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 9th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
	char buf[1024];
	read(0,buf,10);
	write(1,buf,10);
}

/*
./a.out
ashutosh
ashutosh
*/
