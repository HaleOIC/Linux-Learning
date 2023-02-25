/**
 *@file signal.c
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

void sig_cath(int signo){
	printf("catch you! %d\n\n", signo);
}



int main(int argc, char* argv[]){
	
	signal(SIGINT,sig_cath);

	while(1);

    return 0;
}

