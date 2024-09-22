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
	int sd = socket(AF_INET, SOCK_STREAM, 0);
	serv.sin_family = AF_INET ;
	serv.sin_addr.s_addr = inet_addr("");
	serv.sin_port = htons(6006);
	connect(sd,(void *)&serv,sizeof(serv));
	write(sd,"hey server\n",11);
	read(sd,&buf,sizeof(buf));
	printf("msg from server : %s\n",buf);
	close(sd);
}
