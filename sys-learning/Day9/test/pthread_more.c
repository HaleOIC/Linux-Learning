/**
 *@file pthread_more.c
 *@author ShineHale
 *@date 2023-02-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void sys_err(const char* str){
    perror(str);
    exit(1);
}

void *tfn(void *arg) {

	int i = (int*) arg;
	sleep(i);
	printf("----I'm %dth thread: pid = %d, tid = %lu\n", i +1 , getpid(), pthread_self());
	return NULL;
}



int main(int argc, char* argv[]){
    
	int i;
	int ret;
	pthread_t tid;


	for ( i = 0; i < 5; ++i ) {
		ret = pthread_create(&tid, NULL, tfn, (void *)i );
		if ( ret != 0 ) sys_err("pthread create failed!");
	}

	sleep(i);
	printf("main: I'm main, pid = %d, tid = %lu\n", getpid(), pthread_self());


    return 0;

}

