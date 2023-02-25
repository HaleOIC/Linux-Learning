/**
 *@file sigsfunc.c
 *@author ShineHale
 *@date 2023-02-25
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

void print_set( sigset_t *set ){
	
	int i;
	for ( i = 1; i < 32; ++i ) {
		if ( sigismember(set, i) ) 
			putchar('1');
		else 
			putchar('0');
	}
	printf("\n");
} 

int main(int argc, char* argv[]){
	
	sigset_t set, oldset, pendset;
	int ret = 0;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGKILL);
	sigaddset(&set, SIGBUS);
	sigaddset(&set, SIGQUIT);	
	sigaddset(&set, SIGALRM);
	sigaddset(&set, SIGTERM);

	ret = sigprocmask(SIG_BLOCK, &set, &oldset);
	if ( ret == -1 ){
		sys_err("sigprocmask failed");
	}
	while( 1 ) {
		ret = sigpending(&pendset);
		if ( ret == -1 ){
			sys_err("sigpending error");
		}	
		print_set(&pendset);
		sleep(1);
	}
	





    return 0;
}

