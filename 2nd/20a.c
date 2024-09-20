/*
============================================================================
Name : 20a.c
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
    int fd = open("myfifo",O_RDONLY);
    int r_s = read(fd,&buf,sizeof(buf));
    write(1,&buf,r_s);
}

/*
cc 20a.c -o read
ashutosh@coolguy:~/hands_on_list/2nd$ ./read
Hi there 
*/