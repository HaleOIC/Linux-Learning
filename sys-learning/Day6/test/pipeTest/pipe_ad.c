/**
 *@file pipi.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define N 1024


void sys_err(const char *str){
	perror(str);
	exit(1);
}


int main(int argc, char* argv[]){
    
	int ret;
	int fd[2];
	pid_t pid;

	char buf[N];
		
//	char *str = "hello pipe\n";

	ret = pipe(fd);
	if ( ret == -1 ) sys_err("pipe error");

	pid = fork();
	if ( pid == 0 ){
		close( fd[1] );
		ret = read(fd[0], buf, N );
		write(STDOUT_FILENO, buf, ret);

		close( fd[0] );
		
	} else if ( pid > 0 ){
		close(fd[0]);				// close father's process's read port
		sleep(3);
		close(fd[1]);				// close father's process's write port
	}

    return 0;
}

