/*
============================================================================
Name : 1b.c
Author : Ashutosh Jadhav
Description : 1. Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 8th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int i;
	i = link("/home/ashutosh/IIITB/Linux/myfile","/home/ashutosh/hard");
	if (i == 0)
		printf("Hard link Created Successfully...\n");
	else 
		printf("Unsuccessful for some reason...\n");
}

/*
./a.out
Hard link Created Successfully...

ls
 a.out                       Documents       IIITB      programs   Templates
'backup for c'               Downloads       Music      Public     texput.log
'backup for linux d drive'   hands_on_list   myfifo     snap       Videos
 Desktop                     hard            Pictures   Softy

*/