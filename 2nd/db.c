#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd1 ;
    struct{
        int ticket_no ;
    } db ;
    db.ticket_no = 100 ;
    fd1 = open("db",O_CREAT | O_RDWR , 0744);
    write(fd1,&db,sizeof(db));
    close(fd1);
    fd1 = open("db",O_RDONLY);
    read(fd1,&db,sizeof(db));
    printf("Ticket : %d\n",db.ticket_no);
    close(fd1);
}