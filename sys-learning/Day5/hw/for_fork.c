/**
 *@file for_fork.c
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
	for ( i = 0; i < 3; ++i ){
		if ( fork() == 0 ) break;
	}
	if ( i == 3 ){
		sleep(5);
		printf("I'm parent, pid:%d, parentpid: %d\n", getpid(), getppid());
	} else {
		sleep(i);
		printf("I'm child, pid:%d, parentpid: %d\n", getpid(), getppid());
	}

	

    return 0;
}

