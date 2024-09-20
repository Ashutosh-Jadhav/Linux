/*
============================================================================
Name : 22.c
Author : Ashutosh Jadhav
Description : 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int fd;
	char buf1[166] = "chiled writing...", buf2[19]= "parent writing...";
	fd = open(argv[1],O_RDWR);
	if (fork() == 0){
		write(fd,"Child Writing...",16);
	}
	else{
		write(fd,"parent is writing..",19);
	}
}

/*
./a.out newfile7
ashutosh@coolguy:~/hands_on_list$ cat newfile7
parent is writing..Child Writing...
*/