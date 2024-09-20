/*
============================================================================
Name : 8.c
Author : Ashutosh Jadhav
Description : 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 31th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(int args,char *argv[]){

	char buff[1];
	int fd1 = open(argv[1],O_RDONLY);
	if(fd1 == -1){
		perror("Error");
	}
	while(read(fd1,buff,1)==1)
	{
	    if(buff[0]=='\n')
	    {
			getchar();

		}
		else{

			write(1,buff,1);
		}
	}
	close(fd1);
    return 0;
}

/*
./a.out myfile
hi
myname is Ashutosh
line by line
*/
