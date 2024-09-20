/*
============================================================================
Name : 22.c
Author : Ashutosh Jadhav
Description : 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>



