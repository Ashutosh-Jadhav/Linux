#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int i ;
	int fd[2];
	pipe(fd);
	if (!fork())      // child will execute
	{
		close(fd[1]);
		read(fd[0],&i,sizeof(int));   //sending an int from parent
		printf("data recieved successfully : %d\n",i);			
	}
	else
	{
		close(fd[0]);
		printf("enter data to send to child : ");
		scanf("%d",&i);
		write(fd[1],&i,sizeof(int));
	}
}
