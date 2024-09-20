/*
============================================================================
Name : 15.c
Author : Ashutosh Jadhav
Description : 15. Write a program to display the environmental variable of the user (use environ).
Date: 26th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
 	extern char ** environ;
	for(int i=0;environ[i]!=NULL;i++)
	{
		printf("%s: %d\n",environ[i],i);
	}
}

/*
 ./a.out
SHELL=/bin/bash: 0
SESSION_MANAGER=local/coolguy:@/tmp/.ICE-unix/2679,unix/coolguy:/tmp/.ICE-unix/2679: 1
QT_ACCESSIBILITY=1: 2
COLORTERM=truecolor: 3
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg: 4
XDG_MENU_PREFIX=gnome-: 5
TERM_PROGRAM_VERSION=1.92.2: 6
*/