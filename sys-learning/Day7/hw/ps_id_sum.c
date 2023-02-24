/**
 *@file ps_id_sum.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>
#include <fcntl.h>

void sys_err(const char* str){
    perror(str);
    exit(1);
}

#define N 77

int main(int argc, char* argv[]){
		
	pid_t pid;
	int fd[2];

	int ret = pipe(fd);
	if ( ret == -1 ) sys_err("pipe failed");
		
	int i = 0;
	for ( i = 0; i < 2; ++i ) {
		pid = fork();
		if ( pid == -1 ) sys_err("fork failed");
		if ( pid == 0 ) break;
	}	
	
	if ( i == 0 ) {
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execlp("ps", "ps", "aux", NULL);
		sys_err("execlp failed");
	}
	if ( i == 1 ) {
		close(fd[1]);
		sleep(1);
		//int cnt = 0;
		char buf[N];
		while ( read( fd[0], buf, sizeof(buf) ) != 0 ) {
			char newbuf[N];
			strncpy(newbuf, buf+4, 10);
			printf("%s", buf+4);
		}
	}
	if ( i == 2 ) {
		close( fd[0] );
		close( fd[1] );
		pid = wait(NULL);
		printf("parent: the recycled process pid = %d\n", pid);
		pid = wait(NULL);
		printf("parent: the recycled process pid = %d\n", pid);
	}
		
		
    return 0;
}

