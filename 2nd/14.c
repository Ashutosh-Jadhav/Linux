#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd[2];
	int i,j;
	char buf[14];
	pipe(fd);
	if(!fork())
	{
		close(fd[0]);
		printf("Child writing...\n");
		write(fd[1],"Hello There",11);
	}
	else
	{
		close(fd[1]);
		read(fd[0],buf,11);
		printf("parent reading : %s\n",buf);
	}
}
