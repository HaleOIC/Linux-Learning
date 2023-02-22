/**
 *@file imp_cd.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#define N 1024

int main(int argc, char* argv[]){
	

	char address[N] = "                           ";	
	getcwd(address, N);

	if ( strcmp( address, "\0") == 0 ) {

		perror("can not fetch right now working path!");
		exit(1);
	}

	printf("pwd : %s\n", address);

	int ret = chdir(argv[1]);	
	if ( ret == -1 ){
		perror(" can not change the working path!");
		exit(1);
	}

	getcwd(address, N);
	printf("after changing the working directory is : %s\n", address);	

    return 0;
}

