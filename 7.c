/*
============================================================================
Name : 7.c
Author : Ashutosh Jadhav
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
Date: 22th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
	int file1 = open(argv[1],O_RDONLY);
	if(file1<0)
	{perror("Program");exit(0); }
	int file2 = open(argv[2],O_WRONLY | O_EXCL | O_CREAT,0600);
	if(file2<0)
        {perror("Program");exit(0); }
	char buffer[1024];
	int size_read;
	while((size_read = read(file1,buffer,sizeof(buffer)))>0){
	write(file2,buffer,size_read);
	}
	close(file1);
	close(file2);
	return 0;
}

/*
./a.out myfile myfile11
ashutosh@coolguy:~/hands_on_list$ cat myfile11
total 264
drwxrwxr-x  2 ashutosh ashutosh  4096 Sep  1 19:13 ./
drwxr-x--- 23 ashutosh ashutosh  4096 Sep  1 18:57 ../
*/
