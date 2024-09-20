/*
============================================================================
Name : 26a.c
Author : Ashutosh Jadhav
Description : 26. Write a program to execute an executable program.
               b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	execl(argv[1],"a.out",argv[2],NULL);
}

/*
 ./a.out myout myfile

hi
i m Ashutosh
line by line
*/