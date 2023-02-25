/**
 *@file sigpending.c
 *@author ShineHale
 *@date 2023-02-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include <signal.h>

void sys_err(const char* str){
    perror(str);
    exit(1);
}


void sig_print(sigset_t *set){
	
	int i = 0;
	for ( i = 1; i < 30; ++i ) {
		if ( sigismember(set, i) ) {
			putchar('1');
		} else {
			putchar('0');
		}
	}
	printf("\n");
	
}


int main(int argc, char* argv[]){
		
	sigset_t set, oldset, sigpend;
	int ret = 0;

	// set the set's mask
	sigemptyset( &set );
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	sigaddset(&set, SIGFPE);
	sigaddset(&set, SIGALRM);
	sigaddset(&set, SIGTERM);
	
	ret = sigprocmask(SIG_BLOCK, &set, &oldset);
	if ( ret == -1 ) sys_err("sigprocmask failed");


	while( 1 ){
		ret = sigpending(&sigpend);
		if ( ret == -1 ) sys_err("sigpending failed");
		sig_print(&sigpend);
		sleep(1);
	} 
	return 0;
}

