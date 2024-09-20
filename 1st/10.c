/*
============================================================================
Name : 10.c
Author : Ashutosh Jadhav
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[] )
{
	int fd1,i;
	fd1 = open(argv[1],O_RDWR);
	write(fd1,"hello, there",10);
	i = lseek(fd1,10,SEEK_CUR);
	printf("%d",i);
	write(fd1,"how are you doing ",10);
}


/*
./a.out newfile2
20
cat newfile2
hello, thehow are yo
*/