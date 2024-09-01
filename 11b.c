/*
============================================================================
Name : 11b.c
Author : Ashutosh Jadhav
Description : 11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
b. use dup2
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int fd1, newfd,fd2 ;
	fd1 = open(argv[1],O_RDWR);
	fd2 = open(argv[2],O_RDWR);
	printf("%d\n",fd1);
	printf("%d\n",fd2);
	newfd = dup2(fd1, fd2);
	printf("%d\n",newfd);
	write(fd1,"Hi There!",9);
	write(fd2,"How are you doing",17);
}

/*
 ./a.out newfile3 newfile4
3
4
4
ashutosh@coolguy:~/hands_on_list$ cat newfile4
Hi There!
*/
