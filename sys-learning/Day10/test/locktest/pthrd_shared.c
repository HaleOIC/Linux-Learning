/**
 *@file pthrd_shared.c
 *@author ShineHale
 *@date 2023-02-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex;


void *tfn(void* arg){
	srand(time(NULL));

	while (1) {
	
		pthread_mutex_lock(&mutex);

		printf("hello");
		sleep(rand()%3);
		printf("world\n");
	
		pthread_mutex_unlock(&mutex);


		sleep(rand()%3);
	}
	return NULL;
}


int main(int argc, char* argv[]){
		
	pthread_t tid;
	srand(time(NULL));

	int ret = pthread_mutex_init(&mutex, NULL);		//init the mutex 


	if (ret != 0) {
		fprintf(stderr,"mutex init failed:%s\n", strerror(ret));
		exit(1);
	}


	pthread_create(&tid, NULL, tfn, NULL);
	while (1) {
		
		pthread_mutex_lock(&mutex);

		printf("HELLO");
		sleep(rand()%3);
		printf("WORLD\n");

		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}

	pthread_join(tid, NULL);
	
	ret = pthread_mutex_destroy(&mutex);
	
    return 0;
}

