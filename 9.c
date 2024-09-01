/*
============================================================================
Name : 9.c
Author : Ashutosh Jadhav
Description : 9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char *argv[])
{
	struct stat *p= malloc(sizeof(struct stat));
	int i ;
	i = lstat(argv[1] , p );
	if (i < 0 ){
		perror("Error : ");
		exit(0);
	}
	printf("inode : %ld \n",p->st_ino);
	printf("number of hard links : %ld \n",p->st_nlink);
	printf("user ID : %d \n",p->st_uid);
	printf("Group ID : %d \n" , p->st_gid);
	printf("size in Bytes : %ld\n",p->st_size);
	printf("Block Size : %ld\n",p->st_blksize);
	printf("Number of blocks : %ld\n",p->st_blocks);
	printf("Last time of access : %s ",ctime(&(p->st_atim.tv_sec)));
	printf("Time of last modification : %s ",ctime(&(p->st_mtime)));
	printf("Time of last status change : %s",ctime(&(p->st_ctime)));
	free(p);
	return 0 ;
}



/*
./a.out myfile
inode : 20840692 
number of hard links : 1 
user ID : 1000 
Group ID : 1000 
size in Bytes : 3597
Block Size : 4096
Number of blocks : 8
Last time of access : Sun Sep  1 19:14:11 2024
 Time of last modification : Sun Sep  1 19:13:43 2024
 Time of last status change : Sun Sep  1 19:13:43 2024
*/








