/**
 *@file cond_cosumer_producer.c
 *@author ShineHale
 *@date 2023-02-27
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define N 5
#define M 3

pthread_cond_t has_data = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

struct msg{
	int num;
	struct msg* next;
};
struct msg* head;

void thr_error(int ret, char* str){
	fprintf(stderr, "%s:%s\n", str, strerror(ret));
	pthread_exit(NULL);
}

void* producer(void* arg){
	int no = (int*)arg;
	while (1){
		struct msg* mp = malloc(sizeof(struct msg));
		mp->num = rand() % 1000 + 1;
		
		pthread_mutex_lock(&lock);
		printf("--producer %dth:---%d\n", no, mp->num);
		mp->next = head;
		head = mp;
		pthread_mutex_unlock(&lock);

		pthread_cond_signal(&has_data);
		sleep(rand()%3);

	}
}

void* consumer(void* arg){
	struct msg* mp;
	int no = (int*)arg;
	while ( 1 ){
		pthread_mutex_lock(&lock);
		while ( head == NULL){
			pthread_cond_wait(&has_data, &lock);
		}
		mp = head;
		head = mp->next;
		printf("-----conmsumer %dth: --- %d\n", no, mp->num);
		pthread_mutex_unlock(&lock);
		free(mp);
		sleep(rand()%3);
	}
	
}




int main(int argc, char* argv[]){
    
	srand(time(NULL));

	pthread_t ptid[N], ctid[M];
	int i = 0, j = 0;

	for ( i = 0; i < N; ++i )
		pthread_create(&ptid[i], NULL, producer, (void*)i);
	for ( j = 0; j < M; ++j ) 
		pthread_create(&ctid[j], NULL, consumer, (void*)j);


	for ( i = 0; i < N; ++i )
		pthread_join(ptid[i], NULL);
	for ( j = 0; j < M; ++j )
		pthread_join(ctid[j], NULL);


    return 0;
}

