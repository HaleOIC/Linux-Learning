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

#include <sys/time.h>
#include <signal.h>


void sys_err(const char* str){
    perror(str);
    exit(1);
}

void foo(int signo) {
	printf("the catch signal nember = %d\n", signo);
}


int main(int argc, char* argv[]){
			

	signal(SIGALRM, foo);

	struct itimerval it, oldit;

	it.it_value.tv_sec = 3;
	it.it_value.tv_usec = 0;
	it.it_interval.tv_sec = 1;
	it.it_interval.tv_usec = 0;

	int ret =  setitimer(ITIMER_REAL, &it, &oldit);	
	if ( ret == -1 )  sys_err("setitimer failed");
	
	while(1);

    return 0;
}

