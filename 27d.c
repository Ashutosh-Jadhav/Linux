/*
============================================================================
Name : 27d.c
Author : Ashutosh Jadhav
Description : 27. Write a program to execute ls -Rl by the following system calls 
d. execv
Date: 31th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	char *c[]={"ls","-R","-l",NULL};
        execv("/bin/ls",c);
}

/*
./a.out
.:
total 244
-rw-rw-r-- 1 ashutosh ashutosh   799 Sep  1 19:27 10.c
-rw-rw-r-- 1 ashutosh ashutosh   787 Sep  1 19:29 11a.c
-rw-rw-r-- 1 ashutosh ashutosh   839 Sep  1 19:31 11b.c
-rw-rw-r-- 1 ashutosh ashutosh   877 Sep  1 19:32 11c.c
*/