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
	int cnt = 0;	
	while ( ( dBuf = readdir(Buf) ) != NULL ) {
		if ( strcmp(dBuf->d_name, ".") == 0 ) continue;
		if ( strcmp(dBuf->d_name, "..") == 0 ) continue;
		printf("%s\t", dBuf->d_name);
		cnt++;
		if ( cnt == 5 ) {
			cnt = 0;
			printf("\n");
		}
		
	}
	printf("\n");
	closedir(Buf);

    return 0;
}

