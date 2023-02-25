/**
 *@file catch_child.c
 *@author ShineHale
 *@date 2023-02-25
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include <sys/wait.h>
#include <signal.h>


void sys_err(const char* str){
    perror(str);
    exit(1);
}

void catch_child( int signo ){
	pid_t wpid;
	int status;
	//while ( (wpid = wait(NULL) )  != -1 ) {
	while ( (wpid = waitpid(-1, &status, 0) )  != -1 ) {
		if ( wpid == -1 ) sys_err(" wait error ");
		if ( WIFEXITED(status)) 
			printf("--------catch child id = %d, ret = %d\n", wpid, WEXITSTATUS(status));
	} 
	return;
}


int main(int argc, char* argv[]){
		
	pid_t pid;

// make blocking
	

	int i;
	for ( i = 0; i < 15; ++i ) 
		if ((pid = fork()) == 0 ) 	break;
	if ( i == 15 ) {
		struct sigaction act;
		
		act.sa_handler = catch_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;

		sigaction(SIGCHLD, &act, NULL); 

//unblocking

		printf("I'm parent, pid = %d\n", getpid());

		while (1);
	} else {
		printf("I'm child, pid = %d\n", getpid());
		return i;
	}
    return 0;
}

