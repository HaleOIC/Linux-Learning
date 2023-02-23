/**
 *@file fork.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


int main(int argc, char* argv[]){
	
	pid_t pid = fork();

	if ( pid == -1 ){
		perror("fork error");
		exit(1);
	} else if ( pid == 0 ){					
		execlp("ls","ls", "-l", "-a", NULL);
		execlp("date", "date", NULL);
		perror("exec error");
		exit(1);
	} else if ( pid > 0 ) {
		sleep(1);
		printf("I'm parent: %d\n", pid);
	}

    return 0;
}

