#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd1,fd2,size_read;
	char buf[1024];
	fd1 = open("myfile",O_RDWR);
	fd2 = open("to_copy",O_WRONLY | O_EXCL | O_CREAT , 0600);
	while((size_read=read(fd1,buf,sizeof(buf)))>0){
	write(fd2,buf,size_read);
	}
	
	

}
