/**
 *@file sigaction1.c
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



void sig_catch(int signo){
	if ( signo == SIGINT ) {
		printf("catch you! SIGINT signal\n");
	} else if ( signo == SIGQUIT ) {
		printf("catch you SIGQUIT signal!\n");
	}
	sleep(10);
}



int main(int argc, char* argv[]){
	
	struct sigaction act, oldact;	
	act.sa_handler = sig_catch;					// set callback function name
	sigemptyset(&(act.sa_mask));				// set mask when sig_catch working.
	act.sa_flags = 0;							// usually use.


	int ret = sigaction(SIGINT,&act, &oldact);
	if ( ret == -1 ) sys_err("sigaction failed");
	ret = sigaction(SIGQUIT,&act, &oldact);
	if ( ret == -1 ) sys_err("sigaction failed");
	
	while(1);
    return 0;
}

