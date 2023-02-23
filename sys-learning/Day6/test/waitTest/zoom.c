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
		printf("---child, my parent = %d, going to sleep 10s \n", getppid());
		sleep(10);
		printf("------------------child die------------\n");
	} else if ( pid > 0 ) {
		while ( 1 ){
			printf("I am parent, pid = %d, myson = %d\n", getpid(), pid);
			sleep(1);
		}
	} else {
		perror("fork failed");
		return 1;
	}

    return 0;
}

