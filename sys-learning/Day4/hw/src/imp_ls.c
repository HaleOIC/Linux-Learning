/**
 *@file imp_ls.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char* argv[]){
	
	DIR* Buf;
	
	struct dirent* dBuf;
		
	Buf = opendir(argv[1]);
	if ( Buf == NULL ){
		perror("opendir failed!\n");
		exit(1);
	}
	
	while ( ( dBuf = readdir(Buf) ) != NULL ) {
		printf("%s\t", dBuf->d_name);
	}

	printf("\n");
	closedir(Buf);

    return 0;
}

