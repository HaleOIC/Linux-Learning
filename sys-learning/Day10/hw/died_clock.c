/**
 *@file died_clock.c
 *@author ShineHale
 *@date 2023-02-27
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutex_t lock1;
pthread_mutex_t lock2;


void *case1(void *arg){
	
	pthread_mutex_lock(&mutex);
	pthread_mutex_lock(&mutex);
	printf("hello world\n");
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex);
	
	return NULL;
}

int var = 100;

void *case2_th1(void *arg){
	
	while (1) {
		
		pthread_mutex_lock(&lock1);
		sleep(3);
		pthread_mutex_lock(&lock2);
		printf("HELLO WORLD\n");
		sleep(3);
		pthread_mutex_unlock(&lock1);
		pthread_mutex_unlock(&lock2);
		sleep(3);
	}
}

void* case2_th2(void *arg){

	while(1) {

		pthread_mutex_lock(&lock2);
		sleep(3);
		pthread_mutex_lock(&lock1);
		sleep(3);
		printf("hello world!\n");
		pthread_mutex_unlock(&lock1);
		pthread_mutex_unlock(&lock2);
		sleep(3);
	}

}


int main(int argc, char* argv[]){
	
//	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&lock1, NULL);
	pthread_mutex_init(&lock2, NULL);

	pthread_t tid1,tid2_1,tid2_2;

//	pthread_create(&tid1, NULL, case1, NULL);
	pthread_create(&tid2_1, NULL, case2_th1, NULL);
	pthread_create(&tid2_2, NULL, case2_th2, NULL);

//	pthread_join(tid1, NULL);
	pthread_join(tid2_1, NULL);
	pthread_join(tid2_2, NULL);
	pthread_mutex_destroy(&mutex);
	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);

    return 0;
}

