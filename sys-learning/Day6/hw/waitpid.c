/**
 *@file waitpid.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>


void sys_error(const char * str) {
	perror(str);
	exit(1);
}


int main(int argc, char* argv[]){
	

	int status;
	pid_t pid1, pid2, pid3;

	pid1 = fork();			// the first time to fork
	if ( pid1 == 0 ) {
		execlp("ps", "ps", "ajx", NULL);
		sys_error( "ps process failed" );
	} else if ( pid1 > 0 ) {
		printf("---------the parent process finish the first fork and into the next stage!\n");
	}	
	sleep(2);


	pid2 = fork();
	if ( pid2 == 0 ) {
		printf("-------------child pid = %d, parent pid = %d\n", getpid(), getppid());
		char *argv[] = {"./out1", NULL};
		execvp("./out1", argv);		
		sys_error("'out1' failed");
	} else if ( pid2 > 0 ) {
		int ret = waitpid(pid2, &status, 0);
		printf("the second stage the parent has recycled %d process \n\n", ret);
	}
	
	sleep(2);
	pid3 = fork();
	if ( pid3 == 0 ) {
		printf("--------------child pid = %d, parent pid = %d\n", getpid(), getppid());
		char *argv[] = {"./out2", NULL};
		execvp("./out2", argv);
		sys_error("'out2' failed");
	} else if ( pid2 > 0 ){
		waitpid(pid3, &status, 0);
		if ( WIFSIGNALED(status) ) printf("child exit with signal %d\n", WTERMSIG(status));
		} 
    return 0;
}

