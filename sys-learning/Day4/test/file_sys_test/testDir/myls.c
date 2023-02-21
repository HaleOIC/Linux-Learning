/**
 *@file myls.c
 *@author ShineHale
 *@date 2023-02-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char* argv[]){

	DIR * dp;

	struct dirent *sdp;

	dp = opendir(argv[1]);
	if ( dp == NULL ){
		perror("opendir error");
		exit(1);
	}

	while ( (sdp = readdir(dp) ) != NULL ){
		if ( strcmp(sdp->d_name, ".") == 0 )
		   continue;	
		if ( strcmp(sdp->d_name, "..") == 0 )
		   continue;	
		printf("%s\t", sdp->d_name);
	}
	printf("\n");

	closedir(dp);

    return 0;
}

