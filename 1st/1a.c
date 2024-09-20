/*
============================================================================
Name : 1a.c
Author : Ashutosh Jadhav
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int i ;
	i = symlink("/home/ashutosh/IIITB/Linux" ,"/home/ashutosh/Softy");
	if (i == 0)
		printf("Softlink Created Successfully... \n");
	else 
		printf("Unsuccessful due to some reason...\n");
}


/*
./a.out
Softlink Created Successfully... 
*/