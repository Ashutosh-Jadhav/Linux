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
	char buf[1024];
	struct sockaddr_in serv ;
	int sd = socket(AF_UNIX, SOCK_STREAM, 0);

	serv.sin_family = AF_UNIX ;
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons(6030);

	connect(sd,(void *)&serv,sizeof(serv));
	write(sd,"hey server\n",11);
	read(sd,&buf,sizeof(buf));
	printf("msg from server : %s\n",buf);
	getchar();
	close(sd);
}

/*
./a.out
msg from server : ACK from server
*/