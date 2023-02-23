/**
 *@file orphan.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


int main(int argc, char* argv[]){

	pid_t pid;
	pid = fork();

	if ( pid == 0 ){
		while ( 1 ){
			printf("I am child, my parent pid = %d\n", getppid() );
			sleep(1);
		}
	} else if ( pid > 0 ) {
		printf(" I am parent, my pid is = %d\n", getpid() );
		sleep(9);
		printf("-------------parent going to die------------\n");
	} else {
		perror("fork failed");
		return 1;
	}

    return 0;
}

