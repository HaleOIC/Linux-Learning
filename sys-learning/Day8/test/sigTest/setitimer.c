/**
 *@file setitimer.c
 *@author ShineHale
 *@date 2023-02-25
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>



void sys_err(const char* str){
    perror(str);
    exit(1);
}

void myfunc(int signo){
	printf("hello world\n");
}


int main(int argc, char* argv[]){
	
	struct itimerval it, oldit;

	signal(SIGALRM, myfunc);
	
	it.it_value.tv_sec = 2;
	it.it_value.tv_usec = 0;

	it.it_interval.tv_sec = 5;
	it.it_interval.tv_usec = 0;

	if ( setitimer(ITIMER_REAL, &it, &oldit) == -1 ) sys_err("setitimer error");

	while ( 1 );

    return 0;
}

