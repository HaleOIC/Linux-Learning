/**
 *@file pthread_endof3.c
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

void *tfn1(void *arg) {
	
	printf("thread 1 returning\n");

	return (void*)111;
}

void *tfn2(void* arg){
	printf("thread 2 exiting\n");
	pthread_exit((void*)222);
}

void *tfn3(void *arg){
	while (1) {
		
		//printf("thread 3: I am going to die in 3 secondes ...\n");
		//sleep(1);
		//
		pthread_testcancel();
		
	}

	return (void*)666;
}



int main(int argc, char* argv[]){
	
	pthread_t tid;
	void* tret = NULL;

	pthread_create(&tid, NULL, tfn1, NULL);
	pthread_join(tid, &tret);
	printf("thread 1 exit code = %d\n\n", (int*)tret);

	pthread_create(&tid, NULL, tfn2, NULL);
	pthread_join(tid, &tret);
	printf("thread 2 exit code = %d\n\n", (int*)tret);


	pthread_create(&tid, NULL, tfn3, NULL);
	sleep(3);
	pthread_cancel(tid);
	pthread_join(tid, &tret);
	printf("thread 3 exit code = %d\n\n", (int*)tret);



    return 0;	
}

