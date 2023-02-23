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
	pid_t wpid, pid, tmpid;
	int status;

	for (i = 0; i < 5; ++i ){
		pid = fork();
		if ( pid == 0 ) {
			break;
		}
		if ( i == 2 ){
			tmpid = pid;
			printf("---------pid = %d\n", tmpid);
		}
	}
	if ( i == 5 ) {
		sleep(5);
		// wpid = waitpid( -1, &status, WNOHANG ); // recycle any child process and no blocking 
		// wpid = waitpid( -1, &status, 0); // recycle any child process and in blocking
		wpid = waitpid( tmpid, &status, WNOHANG);
		if ( wpid == -1 ){
			perror("waitpid error");
			exit(1);
		}
		printf("I'm parent, wait a child finish : %d\n", wpid);
	} else {
		sleep(i);
		printf("I'm %dth child, pid = %d \n", i + 1, getpid());	
	}

    return 0;
}

