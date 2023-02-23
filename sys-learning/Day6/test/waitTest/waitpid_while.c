/**
 *@file loop_fork.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	
	int i = 0;
	pid_t wpid, pid;
	int status;

	for (i = 0; i < 5; ++i ){
		pid = fork();
		if ( pid == 0 ) {
			break;
		}
	}

	if ( i == 5 ) {
		/*
		while ( (wpid = waitpid(-1, &status, 0) ) ){
			printf("wait child %d\n", wpid);
		}
		*/

		while ( (wpid = waitpid(-1, &status, WNOHANG)) != -1 ){
			if ( wpid > 0 ) {
				printf("wait child %d\n", wpid);
			} else if ( pid == 0 ) {
				sleep(1);
				continue;
			}
		}	
	} else {
		sleep(i);
		printf("I'm %dth child, pid = %d \n", i + 1, getpid());	
	}

    return 0;
}

