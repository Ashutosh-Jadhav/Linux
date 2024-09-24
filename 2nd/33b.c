/*
============================================================================
Name : 33.c
Author : Ashutosh Jadhav
Description : 33. Write a program to communicate between two machines using socket.
Date: 21th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    struct sockaddr_in serv, cli ;
    int sd, sz, nsd ;
    char buf[80];
    sd = socket(AF_UNIX,SOCK_STREAM,0);

    serv.sin_family = AF_UNIX ;
    serv.sin_addr.s_addr = INADDR_ANY ;
    serv.sin_port = htons(6006);

    bind(sd,(void *) &serv, sizeof(serv));

    listen(sd,5);
    sz = sizeof(cli);
    nsd = accept(sd,(void *) &cli,&sz);
    read(nsd,buf,sizeof(buf));
    printf("message from client : %s\n",buf);
    write(nsd,"ACK from server\n",17);
}

/*
./a.out
message from client : hey server

*/