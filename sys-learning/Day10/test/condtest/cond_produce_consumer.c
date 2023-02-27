/**
 *@file cond_produce_consumer.c
 *@author ShineHale
 *@date 2023-02-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define N 128

struct msg{
	int num;
	char str[N];
	struct msg *next;
};

struct msg *head;

/*
   pthread_mutex_t mutex;
   pthread_mutex_init(&mutex, NULL);
   */

// define and initialize a mutex and conditioner.
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_data = PTHREAD_COND_INITIALIZER;



void err_thread(int ret, char *str){
	if( ret != 0 ) {
		fprintf(stderr, "%s:%s\n", str, strerror(ret));
		pthread_exit(NULL);
	}
}

void *producer( void* arg){

	while (1) {

		struct msg *mp = (struct msg*)malloc(sizeof(struct msg));

		mp->num = rand() % 1000 + 1;
		strcpy(mp->str, "hello consumer-producer model");

		printf("--produce %d\n", mp->num);

		pthread_mutex_lock(&mutex);
		mp->next = head;
		head = mp;
		pthread_mutex_unlock(&mutex);

		pthread_cond_signal(&has_data);
		sleep(rand() % 3);
	}	

	return NULL;
}

void *consumer( void* arg){

	struct msg *mp;
	while ( 1 ){

		int ret = pthread_mutex_lock(&mutex);
		if ( ret != 0 ) err_thread(ret, "pthread mutex lock failed!");


		while ( head == NULL ) {
			pthread_cond_wait(&has_data, &mutex);
		}

		mp = head;
		head = mp->next;

		pthread_mutex_unlock(&mutex);
		printf("-----------consumer %d\n", mp->num);
		free(mp);
		sleep(rand() % 3);

	}

	return NULL;
}

int main(int argc, char* argv[]){

	pthread_t pid[3], cid[3];

	srand(time(NULL));

	int ret = pthread_create(&pid[0], NULL, producer, NULL);
	if ( ret != 0 ) 
		err_thread(ret, "pthread create producer failed");

	ret = pthread_create(&pid[1], NULL, producer, NULL);
	if ( ret != 0 ) 
		err_thread(ret, "pthread create producer failed");
	
	ret = pthread_create(&pid[2], NULL, producer, NULL);
	if ( ret != 0 ) 
		err_thread(ret, "pthread create producer failed");
	
	
	
	
	ret = pthread_create(&cid[0], NULL, consumer, NULL);
	if ( ret != 0 ) 
		err_thread(ret, "pthread create consumer failed");

	ret = pthread_create(&cid[1], NULL, consumer, NULL);
	if ( ret != 0 ) 
		err_thread(ret, "pthread create consumer failed");
	ret = pthread_create(&cid[2], NULL, consumer, NULL);
	if ( ret != 0 ) 
		err_thread(ret, "pthread create consumer failed");
	
	int i = 0;
	for ( i = 0; i < 3; ++i ) pthread_join(pid[i], NULL);
	for ( i = 0; i < 3; ++i ) pthread_join(cid[i], NULL);


	return 0;
}

