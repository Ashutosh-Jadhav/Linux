/*
============================================================================
Name : 1c.c
Author : Ashutosh Jadhav
Description : 1. Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 8th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
	int i ;
	i = mknod("myfifo",S_IFIFO|0666,0);
	if (i == 0)
		printf("named pipe created successfully...\n");
	else
		printf("unsuccessful...\n");
}

/*
./a.out
named pipe created successfully...
*/
