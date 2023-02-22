/**
 *@file get_file_type.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	

	struct stat buf;

	int ret = lstat( argv[1], &buf );

	if ( ret == -1 ){
		perror("can not stat the file !\n");
		exit(1);
	}

	mode_t ans = buf.st_mode;
	if ( S_ISREG(ans) ) printf("This file is a regular file!\n");
	else if ( S_ISDIR(ans) ) printf("This file is a directory!\n");
	else if ( S_ISBLK(ans) ) printf("This is a block filen\n");
	else if ( S_ISFIFO(ans) ) printf("This is a FIFO file!\n");
	else printf("I can not figure which type the file is !\n");

    return 0;
}

