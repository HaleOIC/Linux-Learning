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
#include <sys/wait.h>

int main(int argc, char* argv[]){

	pid_t pid, wpid;
	int status;
	pid = fork();


	if ( pid == 0 ){
		printf("---child, my parent = %d, going to sleep 10s \n", getppid());
		sleep(10);
		printf("------------------child die------------\n");
	} else if ( pid > 0 ) {
		wpid = wait(&status);
		if ( wpid == -1 ){
			perror("wait error");
			exit(1);
		}
		printf("----------------parent wait finish, child pid = %d\n", wpid);
	} else {
		perror("fork failed");
		return 1;
	}

    return 0;
}

