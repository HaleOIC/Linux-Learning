/**
 *@file pipe.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define N 128

void sys_err( const char* msg ){
	perror(msg);
	exit(1);
}



int main(int argc, char* argv[]){
	
	int fd[2];
	char buf[N];
	char *str = "this is a message!";
	pid_t pid;
	int ret;

	ret = pipe(fd);
	if ( ret == -1 ) sys_err("pipe error");

	pid = fork();
	if ( pid == 0 ) {
		close(fd[1]);
		ret = read(fd[0], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, ret);
		close(fd[0]);
	} else if ( pid > 0 ) {
		close(fd[0]);
		write(fd[1], str, strlen(str));
		close(fd[1]);
	
	} else sys_err("fork failed");

    return 0;
}

