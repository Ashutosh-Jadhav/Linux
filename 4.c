/*
============================================================================
Name : 4.c
Author : Ashutosh Jadhav
Description : 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 08th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int i ;
	i = open("/home/ashutosh/hands_on_list/myfile10",O_EXCL | O_CREAT,O_RDWR);
	printf("file discriptor is : %d \n",i);
}


/*
./a.out
file discriptor is : 3 
*/