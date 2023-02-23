/**
 *@file ls-wc-l.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/wait.h>

void sys_err(const char *str) {
	perror(str);
	exit(1);
}



int main(int argc, char* argv[]){
	
	int fd[2];
	int ret;
	pid_t pid;
	int i = 0;

	ret = pipe(fd);
	if ( ret == -1 ) {
		sys_err("pipe error");
	}

	for ( i = 0; i < 2; ++i ) {
		pid = fork();
		if ( pid == 0 ) break;
		else if ( pid == -1 ){
			sys_err("fork failed");
		}
	}
	if ( i == 0 ) {			// the first child process
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execlp("ls", "ls", "-l", NULL);
		sys_err("execlp error");
	}
	if ( i == 1 ){			// the second child process
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execlp("wc", "wc", "-l", NULL);
		sys_err("execlp error");
	}
	if ( i == 2 ) {		// the father process	
						//
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}

    return 0;
}

