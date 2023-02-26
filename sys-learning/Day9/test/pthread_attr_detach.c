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

	pthread_attr_t attr;
	
	int ret = pthread_attr_init(&attr);
	if ( ret != 0 ){
		fprintf(stderr, "attr init failed: %s\n", strerror(ret));
		exit(1);
	}

	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	if ( ret != 0 ){
		fprintf(stderr, "attr setdetachstate failed: %s\n", strerror(ret));
		exit(1);
	}

	ret = pthread_create(&tid, &attr, tfn, NULL);
	if ( ret != 0 ) {
		fprintf(stderr,"pthread_create error: %s\n",strerror(ret));
		exit(0);
	}

	ret = pthread_attr_destroy(&attr);	
	if ( ret != 0 ) {
		fprintf(stderr,"pthread_destroy error: %s\n",strerror(ret));
		exit(0);
	}

	ret = pthread_join(tid, NULL);
	if ( ret != 0 ) {
		fprintf(stderr,"pthread_join error: %s\n",strerror(ret));
		exit(0);
	}

	printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
	


	pthread_exit(NULL);
    return 0;
}

