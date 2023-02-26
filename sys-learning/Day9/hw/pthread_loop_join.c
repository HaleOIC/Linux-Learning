/**
 *@file pthread_loop_join.c
 *@author ShineHale
 *@date 2023-02-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define N 5


void *tfn(void* arg){
	
	int no = (int*)arg;
	pthread_testcancel();
	sleep(no);
	printf("=====I'm %dth child thread,my pid = %d, thread id = %lu\n", no, getpid(), pthread_self());
	return (void*)no;
	
}


int main(int argc, char* argv[]){


	pthread_attr_t attr;
	int i = 0;
	int ret = 0;
	pthread_t vtid[N], tid;
	

	ret = pthread_attr_init(&attr);
	if ( ret != 0 ) {
		fprintf(stderr, "pthread attr init failed:%s\n", strerror(ret));
		exit(1);
	}

	ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	if ( ret != 0 ) {
		fprintf(stderr, "pthread attr setdetachstate failed:%s\n", strerror(ret));
		exit(1);
	}

	for ( i = 0; i < N; ++i ) {
		ret = pthread_create(&tid, &attr, tfn, (void*)i);
		vtid[i] = tid;
		if ( ret != 0 ) {
			fprintf(stderr, "pthread create faile:%s\n", strerror(ret));
			exit(1);
		}
	}
	
	pthread_attr_destroy(&attr);

	printf("I'm parent, my pid = %d, thread id = %lu\n", getpid(), pthread_self());

	ret = pthread_cancel(tid);
	if ( ret != 0 ) {
		fprintf(stderr, "pthread cancel failed!:%s\n", strerror(ret));
		exit(1);
	}	
	
	sleep(6);

	int val, k = 0;
	for ( k = 0; k < N; k++ ) {
		ret = pthread_join(vtid[k], (void*)&val);
		if ( ret != 0 ) {
			fprintf(stderr, "pthread join faile:%s\n", strerror(ret));
			exit(1);
		}
		if ( val != -1 ) printf("this %dth child thread is joined\n", val);
		else printf("the canceled thread is joined\n ");
		sleep(1);
	}
    return 0;
}

