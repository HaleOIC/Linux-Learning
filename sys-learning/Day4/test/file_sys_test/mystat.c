/**
  *@file mystat.c
  *@author ShineHale
  *@date 2023-02-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <pthread.h>


int main(int argc, char* argv[]){
    
	struct stat sbuf;

	int ret = stat(argv[1], &sbuf);
	if ( ret == -1 ){
		perror("star error");
		exit(1);
	}

	printf("file size:%ld\n", sbuf.st_size);
    return 0;
}

