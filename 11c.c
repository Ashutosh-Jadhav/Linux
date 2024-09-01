/*
============================================================================
Name : 11c.c
Author : Ashutosh Jadhav
Description : 11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
c. use fcntl
Date: 25th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd1, fd2, newfd;
	fd1 = open(argv[1],O_RDWR);
	fd2 = open(argv[2],O_RDONLY);
	newfd = fcntl(fd1,F_DUPFD, 3);
	printf("%d\n",newfd);
	write(fd1,"Again Hi!",9);
	write(newfd,"Nah bro! not you again",22);
}


/*
./a.out newfile4 newfile5
5
ashutosh@coolguy:~/hands_on_list$ cat newfile5
ashutosh@coolguy:~/hands_on_list$ cat newfile4
Again Hi!Nah bro! not you again
*/