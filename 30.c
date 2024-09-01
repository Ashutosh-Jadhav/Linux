/*
============================================================================
Name : 30.c
Author : Ashutosh Jadhav
Description : 30. Write a program to run a script at a specific time using a Daemon process.
Date: 31th Aug, 2024.
============================================================================
*/

#include <time.h>      
#include <stdio.h>     
#include <stdlib.h>    
#include <sys/types.h> 
#include <unistd.h>    
#include <sys/stat.h>  

int main()
{
    int i=0 ;
    printf("after how much sec to run the script : \n");
    scanf("%d",&i);
    if(!fork()) {
        chdir("/");
        umask(0);
        while(1){
            sleep(i);
            printf("child pid : %d\n",getpid());
            printf("daemon process is running...\n");
        }
    }
    else
    {
        exit(0);
    }
}

/*
./a.out
after how much time to run the script 
5
child pid : 12076
daemon process is running...
*/
