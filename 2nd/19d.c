/*
============================================================================
Name : 19c.c
Author : Ashutosh Jadhav
Description : 19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char * argv[])
{
    mkfifo(argv[1], 0744);
}

/*
 ./a.out myfifo3

 prwxr--r-- 1 ashutosh ashutosh     0 Sep 20 23:48 myfifo3|
*/