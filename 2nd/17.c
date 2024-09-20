#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int i ;
     	int fd[2];
	pipe(fd);
	if (!fork())
	{
		// child executes
		close(1);
		close(fd[0]);
		dup(fd[1]);
		execl("/bin/ls","ls","-l",NULL);
	}
	else {
		close(fd[1]);
		close(0);
		//sleep(2);
		dup(fd[0]);
		//read(0,&buf,sizeof(buf));
		execl("/bin/wc","wc",NULL);
	}
}
