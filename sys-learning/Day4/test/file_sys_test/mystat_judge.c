/**
 *@file mystat_judge.c
 *@author ShineHale
 *@date 2023-02-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include <sys/stat.h>


int main(int argc, char* argv[]){
	struct  stat buf;
		
	int ret = stat(argv[1], &buf);
	if ( ret == -1 ){
		perror("stat error address!");
		exit(1);
	}

	if ( S_ISREG(buf.st_mode) ) printf("This is a regular file!\n");
	else if ( S_ISDIR(buf.st_mode) ) printf("This is a directory");
	else if ( S_ISBLK(buf.st_mode) ) printf("This is a block device!\n");
	else if ( S_ISFIFO(buf.st_mode) ) printf("This is a FIFO file!\n");
	else printf("I do not know which type of the file!\n");
    return 0;
}

