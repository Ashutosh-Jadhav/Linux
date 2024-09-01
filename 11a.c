/*
============================================================================
Name : 11a.c
Author : Ashutosh Jadhav
Description : 11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{
	int fd1, newfd ;
	fd1 = open(argv[1],O_RDWR);
	newfd = dup(fd1);
	write(fd1,"Hello There!",12);
	write(newfd,"How are you ?",13);
	printf("%d \n",fd1);
	printf("%d \n",newfd);
}


/*
./a.out newfile3
3 
4 
ashutosh@coolguy:~/hands_on_list$ cat newfile3
Hello There!How are you ?
*/