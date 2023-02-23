/**
 *@file exec_ps.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>


int main(int argc, char* argv[]){

	pid_t pid;

	int fd1 = open("psFile", O_CREAT|O_RDWR|O_TRUNC);
	
	dup2(fd1, STDOUT_FILENO);
	pid = fork();
	if ( pid == 0 ) {
		execlp("/bin/ps", "ps", "aux", NULL);
		perror("'ps aux' command failed");
		exit(1);
	} else if ( pid > 0 ){
		sleep(1);
		close(fd1);
	} else {
		perror("fork failed");
		exit(1);
	}
	


    return 0;
}

