/*
============================================================================
Name : 20b.c
Author : Ashutosh Jadhav
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char buf[1024];
    int fd = open("myfifo",O_WRONLY);
    int r_s = write(fd,"Hi there \n",10);
}

/*
 cc 20b.c -o write
ashutosh@coolguy:~/hands_on_list/2nd$ ./write
*/