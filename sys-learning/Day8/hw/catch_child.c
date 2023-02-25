/**
 *@file catch_child.c
 *@author ShineHale
 *@date 2023-02-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include <signal.h>
#include <sys/wait.h>


void sys_err(const char* str){
    perror(str);
    exit(1);
}


void catch_child(int signo){
	
	pid_t pid;
	int status;

	while ( (pid = waitpid(-1, &status, 0) ) != -1 ) {
		if ( WIFEXITED(status) )  
			printf("the recycled pid = %d, return value is %d\n", pid, WEXITSTATUS(status));
		else if (WIFSIGNALED(status)) 
			printf("child %d cancel signal %d\n", pid, WTERMSIG(status));
	}

}


int main(int argc, char* argv[]){
    
	int i = 0;
	pid_t pid; 
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGCHLD);

	sigprocmask(SIG_BLOCK, &set, NULL);


	for ( i = 0; i < 15; ++i ){
		pid = fork();
		if ( pid == -1 ) sys_err("fork failed");
		if ( pid == 0 ) break;
	}

	if ( i == 15 ) {
		printf("I'm parent, my pid = %d\n", getpid());


		struct sigaction act, oldact;
		int ret = 0;

		act.sa_handler = catch_child;
		sigemptyset(&(act.sa_mask));
		act.sa_flags = 0;
		

		sigprocmask(SIG_UNBLOCK, &set, NULL);

		ret = sigaction(SIGCHLD, &act, &oldact );
		if ( ret == -1 ) sys_err("sigaction failed!");

		while(1);

	}
	else { 
		sleep(i);
		printf("I'm child, my pid = %d\n", getpid());
		return i;
	}


    return 0;
}

