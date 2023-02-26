/**
 *@file pthread_create.c
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

void *tfn(void *arg){
	while (1) {
		printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());
		sleep(1);
	
	}
	return NULL;
}



int main(int argc, char* argv[]){

	pthread_t tid;

	int ret = pthread_create(&tid, NULL, tfn, NULL);
	if ( ret != 0 ) {
		fprintf(stderr, "pthread create error:%s\n", strerror(ret));
		exit(1);
	}

	printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
	
	sleep(5);

	ret = pthread_cancel(tid);
	if ( ret != 0 ) {
		fprintf(stderr, "pthread cancel error:%s\n", strerror(ret));
		exit(1);
	}
	while (1);
	pthread_exit(NULL);
    return 0;
}

