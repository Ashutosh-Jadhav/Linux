/*
============================================================================
Name : 2.c
Author : Ashutosh Jadhav
Description : 2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 8th Aug, 2024.
============================================================================
*/

#include <stdio.h>

int main()
{
	for(;;);
}

/*
 ./a.out &
[1] 6925

cat /proc/6925/status | head
Name:	a.out
Umask:	0002
State:	R (running)
Tgid:	6925
Ngid:	0
Pid:	6925
PPid:	5356
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000

*/