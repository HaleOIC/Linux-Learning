/**
 *@file glb_var_pthrd.c
 *@author ShineHale
 *@date 2023-02-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int var = 1000;
void err_print(const char *str, const int errno){
	fprintf(stderr, str, strerror(errno));
}

void* pfn(void* arg){
	printf("after changed\n");
	var = 2000;
	return NULL;
}


int main(int argc, char* argv[]){
	
	pthread_t pid;
	
	printf("Main: pthread id = %lu, var = %d\n", pthread_self(), var);

	pthread_create(&pid, NULL, pfn, NULL);

	sleep(2);	

	printf("Main: pthread id = %lu, var = %d\n", pthread_self(), var);

	pthread_exit(NULL);

    return 0;
}
