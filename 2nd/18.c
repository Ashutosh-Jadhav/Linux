#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int fd[2];
	pipe(fd);
	if (!fork())
	{
		// child will execute 
		int fd1[2];
		pipe(fd1);
		if (!fork())
		{
			close(fd[1]);
			close(fd[0]);
			// child of child will execute this
			close(fd1[0]);
			dup2(1,fd1[1]);
			sleep(1);
			execl("/bin/ls","ls","-l",NULL);
		}
		else 
		{
			char buf[1024];
			close(fd[0]);
			dup2(1,fd[1]);
			close(fd1[1]);
			dup2(0,fd1[0]);
			read(fd1[0],&buf,sizeof(buf));

			sleep(2);
			//wait(0);
			execl("/bin/grep","grep","^d",&buf,NULL);
		}
	}
	else 
	{
		char buf[1024];
		close(fd[1]);
		dup2(0,fd[0]);
		sleep(3);
		//read(0,&buf,sizeof(buf));
		//wait(0);
		execl("/bin/wc","wc",NULL);
	}
}
