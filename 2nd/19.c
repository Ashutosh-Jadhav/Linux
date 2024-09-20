/*
============================================================================
Name : 19c.c
Author : Ashutosh Jadhav
Description : 19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    mknod(argv[1],S_IFIFO | 0744,NULL);
}

/*
 ./a.out myfifo2
 ll myfifo2
prwxr--r-- 1 ashutosh ashutosh 0 Sep 20 23:43 myfifo2|

*/