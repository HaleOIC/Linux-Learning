/**
 *@file kill.c
 *@author ShineHale
 *@date 2023-02-25
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>


void sys_err(const char* str){
    perror(str);
    exit(1);
}


int main(int argc, char* argv[]){
    
	pid_t pid = fork();

	if ( pid > 0 ) {
		printf("parent, pid = %d\n", getpid());
		while(1);
	}
	else if ( pid == 0 ){
		printf("child, pid = %d\n", getpid());
		sleep(2);
		kill(getppid(), SIGKILL);
	}



	return 0;
}

