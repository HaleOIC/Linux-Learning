/**
 *@file mem_time_hello.c
 *@author ShineHale
 *@date 2023-02-27
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define N 128

sem_t lock1, lock2, timelock, lock;
int flag = 1;

void thr_error(int ret, char* str){
	fprintf(stderr, "%s:%s\n", str, strerror(ret));
	pthread_exit(NULL);
}



void* thread_func1(void* arg){
		
	while(1){

		struct timespec t;
		memset(&t, 0, sizeof(t));
		clock_gettime(CLOCK_REALTIME, &t);
		t.tv_sec += 5;
		t.tv_nsec = t.tv_nsec + 100;
		sem_timedwait(&timelock, &t);
		printf("hello world!\n");
		sem_post(&lock);
	}

	
}


void* thread_func2(void* arg){

	while(1){
		
		int ret = sem_wait(&lock);
		if ( ret != 0 ) {
			printf("%d\n", ret);
			sem_post(&timelock);
		}
		char buf[N];
		ret = read(STDIN_FILENO, buf, sizeof(buf));
		if ( ret > 0 ) sem_post(&timelock);
		
	}
}



int main(int argc, char* argv[]){
    
	srand(time(NULL));
	pthread_t tid1, tid2;
	int ret = sem_init(&lock, 0, 1);
	if (ret != 0) thr_error(ret, "sem init failed!");
	ret = sem_init(&timelock, 0, 0);
	if (ret != 0) thr_error(ret, "sem init failed!");
	
	
	pthread_create(&tid1, NULL, thread_func1, NULL);
	pthread_create(&tid2, NULL, thread_func2, NULL);


	sem_destroy(&lock);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);


    return 0;
}

