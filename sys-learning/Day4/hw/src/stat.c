/**
 *@file stat.c
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
	
	struct stat buf;

	int ret = stat( argv[1], &buf );
	
	if ( ret == -1 ){
		perror("can not stat the target file ");
		exit(1);
	}	
	
	mode_t retBuf =  buf.st_mode ;
	printf("the st_mode of the target file is %d\n", retBuf);
	
    return 0;
}

