/**
 *@file imp_mv.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


int main(int argc, char* argv[]){
	
	link(argv[1], argv[2]);

	int ret = unlink(argv[1]);
	if ( ret == -1 ){
		perror("can not unlink the target file");
		exit(1);
	}

    return 0;
}

