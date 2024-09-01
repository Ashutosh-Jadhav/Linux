/*
============================================================================
Name : 14.c
Author : Ashutosh Jadhav
Description : 14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(int c,char *argv[]){
	struct stat *p=malloc(sizeof(struct stat));
	lstat(argv[1],p);
	unsigned int res = p->st_mode;
	if((res & S_IFMT) == S_IFSOCK)
       		printf("Socket\n");
	else if((res & S_IFMT) == S_IFLNK)
       		printf("Symbolic link\n");
	else if((res & S_IFMT) == S_IFREG)
       		printf("Regular file\n");
	else if((res & S_IFMT) == S_IFBLK)
       		printf("Block device\n");
	else if((res & S_IFMT) == S_IFCHR)
       		printf("Character device\n");
	else if((res & S_IFMT) == S_IFDIR)
       		printf("Directory\n");
	else if((res & S_IFMT) == S_IFIFO)
       		printf("Named pipe\n");
	else
       		printf("No Idea");
	free(p);
}


/*
./a.out myfile
Regular file
*/