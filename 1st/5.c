/*
============================================================================
Name : 5.c
Author : Ashutosh Jadhav
Description : 5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 8th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int i ; 
	printf("%d",creat("myfile1",0744));
	printf("%d",creat("myfile2",0744));
	printf("%d",creat("myfile3",0744));
	printf("%d",creat("myfile4",0744));
	printf("%d",creat("myfile5",0744));
	for(;;);
}

/*
 ls
0  1  2  3  4  5  6  7
*/
