/**
 *@file loop_fork.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


int main(int argc, char* argv[]){
	
	int i = 0;
	pid_t pid;
	for (i = 0; i < 5; ++i ){
		if ( fork() == 0 ) break;
	}
	if ( i == 5 ) {
		sleep(5);
		printf("I'm parent\n");
	} else {
		sleep(i);
		printf("I'm %dth child\n", i + 1);	
	}

    return 0;
}

