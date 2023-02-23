/**
 *@file exec_ps.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	
	int fd;
	pid_t pid;
	

	fd = open("ps.out", O_RDWR|O_CREAT|O_TRUNC, 0644);
	if ( fd == -1 ) {
		perror(" open ps.out file failed!");
		exit(1);
	}	
	dup2 (fd, STDOUT_FILENO);
	
	pid = fork();
	if ( pid == 0 ){
		execlp("ps","ps", "aux", NULL);
		perror("execlp failed");
	}else {
		sleep(1);
		close( fd );
	}



    return 0;
}

