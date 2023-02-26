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


void *tfn(void *arg){

	printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());

	return NULL;
}



int main(int argc, char* argv[]){

	pthread_t tid;

	printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());

	int ret = pthread_create(&tid, NULL, tfn, NULL);
	if ( ret != 0 ) {
		fprintf(stderr, "pthread create error:%s\n", strerror(ret));	
		exit(1);
	}

	ret = pthread_detach(tid); // detach the thread, it will make the thread that 
							   // when the thread is over, it will be recycled automatically.
							   // no need for specific recycle
	if ( ret != 0 ) {
		fprintf(stderr, "pthread detach error:%s\n", strerror(ret));	
		exit(1);
	}

	sleep(1);

	ret = pthread_join(tid, NULL);
	if ( ret != 0 ) {
		fprintf(stderr, "pthread join error:%s\n", strerror(ret));	
		exit(1);
	}
	pthread_exit(NULL);
    return 0;
}

